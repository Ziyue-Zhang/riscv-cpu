package njucore

import chisel3._
import collection.mutable.LinkedHashMap
import chisel3.util._
import chisel3.util.experimental.BoringUtils

import common.Cause._
import common.instructions._
import common.constant._
import scala.math._

//reference to https://github.com/happy-lx/simplecore

class MIP extends Bundle{
    val zero0 = UInt(4.W)
    val meip  = Bool()
    val heip  = Bool()
    val seip  = Bool()
    val ueip  = Bool()
    val mtip  = Bool()
    val htip  = Bool()
    val stip  = Bool()
    val utip  = Bool()
    val msip  = Bool()
    val hsip  = Bool()
    val ssip  = Bool()
    val usip  = Bool()
}

class Mstatus extends Bundle{
    val sd    = Bool()
    val zero1 = UInt(40.W)
    val tsr   = Bool()
    val tw    = Bool()
    val tvm   = Bool()
    val mxr   = Bool()
    val sum   = Bool()
    val mprv  = Bool()
    val xs    = UInt(2.W) 
    val fs    = UInt(2.W) 
    val mpp   = UInt(2.W) 
    val hpp   = UInt(2.W) 
    val spp   = Bool()
    val mpie  = Bool()
    val hpie  = Bool()
    val spie  = Bool()
    val upie  = Bool()
    val mie   = Bool()
    val hie   = Bool()
    val sie   = Bool()
    val uie   = Bool()
}

class CSRIO extends Bundle{
    val inst          = Input(UInt(32.W))
    val csr_op        = Input(UInt(csr_op_size))
    val data_in       = Input(UInt(64.W))
    val has_exception = Input(Bool())
    val has_stall     = Input(Bool())
    val in_mem_pc     = Input(UInt(64.W))
    val in_exe_pc     = Input(UInt(64.W))
    val in_dec_pc     = Input(UInt(64.W))
    val in_if_pc      = Input(UInt(64.W))
    val is_retire     = Input(Bool())
    

    val redir_target = Output(UInt(64.W))
    val csr_info     = Output(UInt(64.W))
    val is_redir     = Output(Bool())
    val csr_illegal_ins_exception = Output(Bool())
}

class CSRfile extends Module
{
    val io = IO(new CSRIO)

    io := DontCare

    //csr reg
    val reg_mtvec     = RegInit(UInt(64.W),MTVEC_ADDR.U)
    val reg_mepc      = RegInit(UInt(64.W),0.U)
    val reg_mcause    = RegInit(UInt(64.W),0.U)
    val reg_mie       = RegInit(0.U.asTypeOf(new MIP()))
    val reg_mip       = RegInit(0.U.asTypeOf(new MIP()))
    val reg_mtval     = RegInit(0.U(64.W))
    val reg_mscratch  = RegInit(0.U(64.W))
    val reg_mstatus   = RegInit(0.U.asTypeOf(new Mstatus()))
    val reg_mcounteren = RegInit(0.U(64.W))

    val reg_pmpcfg0  = RegInit(0.U(64.W))
    val reg_pmpcfg1  = RegInit(0.U(64.W))
    val regs_pmpaddr = RegInit(VecInit.tabulate(16){i => 0.U(64.W)})//pmpaddr0 - pmpaddr15

    val reg_mcycle          = RegInit(0.U(64.W))
    val reg_minstret        = RegInit(0.U(64.W))
    val regs_mhpmcounter    = RegInit(VecInit.tabulate(mhpmcounter_number){i => (0.U(64.W))})
    val reg_mcounterinhibit = RegInit(0.U(64.W))
    val regs_mhpmevet       = RegInit(VecInit.tabulate(mhpmevent_number){i => (0.U(64.W))})


    val prv_now = WireInit(PRV_M)

    val wire_csr_op    = Wire(UInt(csr_op_size))//reset csr operation if op is read only
    val wire_csr_index = WireInit(io.inst(csr_MSB,csr_LSB))

    wire_csr_op := io.csr_op
    when((io.csr_op === csr_c || io.csr_op === csr_s) && io.inst(rs1_MSB,rs1_LSB) === 0.U)
    {
        wire_csr_op := csr_r
    }

    val str_isa = "im"//impliment rv64im

    def gen_isa(str : String) = str_isa.map{case x:Char => 1 << (x - 'a')}.reduce(_ | _)
    val wire_isa = WireInit(gen_isa(str_isa).U(64.W))
    val csr_wire_isa = wire_isa | (BigInt(2) << 62).U(64.W)

    //check whether csr register can be written when op is set clear write
    val csr_read_only = wire_csr_index(11,10).andR
    val write_illegal = ((wire_csr_op === csr_w || wire_csr_op === csr_c || wire_csr_op === csr_s) && csr_read_only)

    //check whether csr register number is illegal when op is not csr.N
    val csr_read_map = collection.mutable.LinkedHashMap[Int,Bits](
        mvendorid -> 0.U(64.W),
        marchid   -> 0.U(64.W),
        mimpid    -> 0.U(64.W),
        mhartid   -> 0.U(64.W),

        mstatus   -> reg_mstatus.asTypeOf(UInt(64.W)),
        misa      -> csr_wire_isa,
        medelege  -> 0.U(64.W),
        midelege  -> 0.U(64.W),
        mie       -> reg_mie.asTypeOf(UInt(64.W)),
        mip       -> reg_mip.asTypeOf(UInt(64.W)),
        mtvec     -> reg_mtvec,
        mcounteren-> reg_mcounteren,

        mscratch  -> reg_mscratch,
        mepc      -> reg_mepc,
        mcause    -> reg_mcause,
        mtval     -> reg_mtval,
        
        pmpcfg0   -> reg_pmpcfg0,
        pmpcfg1   -> reg_pmpcfg1,

        mcycle    -> reg_mcycle,
        minstret  -> reg_minstret,

        mcounterinhibit -> reg_mcounterinhibit
    )

    for( i <- (0 until 16)){
        csr_read_map += ((pmpaddr0 + i) -> regs_pmpaddr(i))
    }

    for(i <- (0 until mhpmcounter_number)){
        csr_read_map += ((mhpmcounter_start + i) -> regs_mhpmcounter(i))
    }

    for(i <- (0 until mhpmevent_number)){
        csr_read_map += ((mhpmevent_start + i) -> regs_mhpmevet(i))
    }

    val csr_legal : Bool = csr_read_map.map{case(k : Int , v : Bits) => (wire_csr_index === k.U)}.reduce(_ || _)
    val read_illegal = (io.csr_op =/= csr_n && io.csr_op =/= csr_prv) && !csr_legal

    val exception_in_csr = read_illegal || write_illegal // illegal inst detected in csr file
    
    val csr_read_enable = (io.csr_op =/= csr_n && io.csr_op =/= csr_prv) && !read_illegal
    
    //according to csr map to set data to be readed 
    val csr_read_data = WireInit(0.U(64.W))

    def is_csr_of(index : Int) = {
        val temp = csr_read_map.map{case (k,v) => k -> (k.U === wire_csr_index)}
        temp(index)
    }

    when(csr_read_enable)
    {
        csr_read_data := Mux1H(for((k,v) <- csr_read_map) yield (is_csr_of(k) -> v))
    }

    io.csr_info := csr_read_data

    //according to the readed data to generate write(set or clear) or write(write) data
    //some csr can only be changed in some bits 
    val csr_write_data = MuxCase(csr_read_data,Array(
        (io.csr_op === csr_w) -> io.data_in,
        (io.csr_op === csr_s) -> (csr_read_data | io.data_in),
        (io.csr_op === csr_c) -> (csr_read_data & (~io.data_in))
    ))

    val csr_wen = !write_illegal && csr_legal && !io.has_exception && !io.has_stall && (wire_csr_op =/= csr_n && wire_csr_op =/= csr_prv && wire_csr_op =/= csr_r)

    
    when(csr_wen){
        when(is_csr_of(mstatus)){
            val temp_mstatmstatusus = csr_write_data.asTypeOf(new Mstatus)
            reg_mstatus.mie := temp_mstatmstatusus.mie
            reg_mstatus.mpie := temp_mstatmstatusus.mpie
        }

        when(is_csr_of(mie)){
            val temp_mie = csr_write_data.asTypeOf(new MIP)
            reg_mie.mtip := temp_mie.mtip
            reg_mie.msip := temp_mie.msip
        }
        when(is_csr_of(mip)){
            val temp_mip = csr_write_data.asTypeOf(new MIP)
            reg_mip.mtip := temp_mip.mtip
            reg_mip.msip := temp_mip.msip
        }
        when(is_csr_of(mtvec)) {reg_mtvec := csr_write_data}
        when(is_csr_of(mscratch)) {reg_mscratch := csr_write_data}
        when(is_csr_of(mepc)) {reg_mepc := ((csr_write_data >> 2)<<2).asUInt()}
        when(is_csr_of(mcause)) {reg_mcause := csr_write_data}
        when(is_csr_of(pmpcfg0)) {reg_pmpcfg0 := csr_write_data}
        when(is_csr_of(pmpcfg1)) {reg_pmpcfg1 := csr_write_data}
        when(is_csr_of(mcycle)) {reg_mcycle := csr_write_data}
        when(is_csr_of(minstret)) {reg_minstret := csr_write_data}
        when(is_csr_of(mcounterinhibit)) {reg_mcounterinhibit := csr_write_data}
        
        for(i <- 0 until 16)
        {
            when(is_csr_of(pmpaddr0 + i)){
                regs_pmpaddr(i) := csr_write_data
            }
        }
        for(i <- 0 until mhpmcounter_number)
        {
            when(is_csr_of(mhpmcounter_start + i))
            {
                regs_mhpmcounter(i) := csr_write_data
            }
        }
        for(i <- 0 until mhpmevent_number)
        {
            when(is_csr_of(mhpmevent_start + i))
            {
                regs_mhpmevet(i) := csr_write_data
            }
        }
        
    }

    //check exception
    val csr_illegal_ins_exception = exception_in_csr || io.has_exception

    val csr_isecall  = (io.csr_op === csr_prv) && (wire_csr_index === 0.U)
    val csr_isebreak = (io.csr_op === csr_prv) && (wire_csr_index === 1.U)
    val csr_ismret   = (io.csr_op === csr_prv) && (wire_csr_index === 0x302.U)

    val csr_has_exception = csr_illegal_ins_exception || csr_isecall || csr_isebreak
    //check if there is a time interrupt

    io.csr_illegal_ins_exception := csr_illegal_ins_exception


    //BoringUtils.addSink(reg_mip.mtip,"time_interrupt")
    
    reg_mcycle := reg_mcycle + 1.U
    
    when(io.is_retire)
    {
        reg_minstret := reg_minstret + 1.U
    }

    val csr_has_interrupt = Wire(Bool())

    when(reg_mip.mtip && reg_mie.mtip && reg_mstatus.mie && !io.has_stall && io.in_mem_pc =/= 0.U)
    {
        //can process timer interrupt
        //when no stall happens , the redirect infomation can be set into registers 

        //also if there is a NOP in MEM stage and we have a time interrupt
        //the mepc will be wrong , so we should make sure the inst
        //in MEM stage is not NOP , Maybe there will be some legal NOP 
        //insts generated by compiler,we will emit this 
        csr_has_interrupt := true.B
    }.otherwise
    {
        csr_has_interrupt := false.B
    }

    //set cause , trapaddr and return addr 
    val wire_trap_addr = WireInit(reg_mtvec)
    val wire_ret_addr  = WireInit(reg_mepc)


    when(!io.has_stall)
    {
        when(csr_has_interrupt)
        {
            val wire_mstatus_new = WireInit(reg_mstatus)
            val wire_mstatus_old = WireInit(reg_mstatus)
            // reg_mepc := io.in_mem_pc
            when(csr_ismret || csr_has_exception)
            {
                reg_mepc := io.in_mem_pc
            }.elsewhen(io.in_exe_pc =/= 0.U)
            {
                reg_mepc := io.in_exe_pc
            }.elsewhen(io.in_dec_pc =/= 0.U)
            {
                reg_mepc := io.in_dec_pc
            }.elsewhen(io.in_if_pc =/= 0.U)
            {
                reg_mepc := io.in_if_pc
            }
            reg_mtval := io.in_mem_pc

            reg_mcause := (BigInt(1)<<63).U(64.W) | m_timer_interrupt
                
            wire_mstatus_new.mie  := false.B
            wire_mstatus_new.mpie := wire_mstatus_old.mie
            wire_mstatus_new.mpp  := prv_now

            reg_mstatus := wire_mstatus_new
        }.elsewhen(csr_ismret)
        {
            val wire_mstatus_new = WireInit(reg_mstatus)
            val wire_mstatus_old = WireInit(reg_mstatus)

            io.redir_target       := wire_ret_addr
            wire_mstatus_new.mie  := wire_mstatus_old.mpie
            wire_mstatus_new.mpie := true.B
            prv_now               := wire_mstatus_old.mpp

            reg_mstatus := wire_mstatus_new
        }.elsewhen(csr_has_exception)
        {
            val wire_mstatus_new = WireInit(reg_mstatus)
            val wire_mstatus_old = WireInit(reg_mstatus)
            when(csr_illegal_ins_exception)
            {
                reg_mepc  := io.in_mem_pc
                reg_mtval := io.inst

                reg_mcause := illegal_inst
                
                wire_mstatus_new.mie  := false.B
                wire_mstatus_new.mpie := wire_mstatus_old.mie
                wire_mstatus_new.mpp  := prv_now

                reg_mstatus := wire_mstatus_new
                
            }.elsewhen(csr_isecall)
            {
                reg_mepc  := io.in_mem_pc
                reg_mtval := io.in_mem_pc

                reg_mcause := ecall_m
                
                wire_mstatus_new.mie  := false.B
                wire_mstatus_new.mpie := wire_mstatus_old.mie
                wire_mstatus_new.mpp  := prv_now

                reg_mstatus := wire_mstatus_new
            }.elsewhen(csr_isebreak)
            {
                reg_mepc  := io.in_mem_pc
                reg_mtval := io.in_mem_pc

                reg_mcause := breakpoint
                
                wire_mstatus_new.mie  := false.B
                wire_mstatus_new.mpie := wire_mstatus_old.mie
                wire_mstatus_new.mpp  := prv_now

                reg_mstatus := wire_mstatus_new
            }
        }


    }


    when(csr_has_exception || csr_has_interrupt || csr_ismret)
    {
        io.is_redir := true.B
    }.otherwise
    {
        io.is_redir := false.B
    }

    when(csr_has_exception || csr_has_interrupt)
    {
        io.redir_target := wire_trap_addr
    }

    //for difftest
    //BoringUtils.addSource(reg_mstatus.asUInt(),"mstatus")
    //BoringUtils.addSource(io.is_redir,"is_redir")
}