`define RANDOMIZE_DELAY 0

           module zzy_AXI_Bridge
           (
               input         clock,
               input         reset,
           
               //inst sram-like
               input         inst_req     ,
               input         inst_wr      ,
               input  [1 :0] inst_size    ,
               input  [63:0] inst_addr    ,
               input  [63:0] inst_wdata   ,
               output [63:0] inst_rdata   ,
               output        inst_addr_ok ,
               output        inst_data_ok ,
           
               //data sram-like
               input         data_req     ,
               input         data_wr      ,
               input  [1 :0] data_size    ,
               input  [63:0] data_addr    ,
               input  [63:0] data_wdata   ,
               output [63:0] data_rdata   ,
               output        data_addr_ok ,
               output        data_data_ok ,
           
               //axi
               //ar
               output [3 :0] arid         ,
               output [63:0] araddr       ,
               output [7 :0] arlen        ,
               output [2 :0] arsize       ,
               output [1 :0] arburst      ,
               output [1 :0] arlock       ,
               output [3 :0] arcache      ,
               output [2 :0] arprot       ,
               output        arvalid      ,
               input         arready      ,
               input  [3 :0] arqos        ,
               input         aruser       ,
               //r
               input  [3 :0] rid          ,
               input  [63:0] rdata        ,
               input  [1 :0] rresp        ,
               input         rlast        ,
               input         rvalid       ,
               output        rready       ,
               //input         ruser        ,
               //aw
               output [3 :0] awid         ,
               output [63:0] awaddr       ,
               output [7 :0] awlen        ,
               output [2 :0] awsize       ,
               output [1 :0] awburst      ,
               output [1 :0] awlock       ,
               output [3 :0] awcache      ,
               output [2 :0] awprot       ,
               output        awvalid      ,
               input         awready      ,
               input  [3 :0] awqos        ,
               input         awuser       ,

               //w
               output [3 :0] wid          ,
               output [63:0] wdata        ,
               output [7 :0] wstrb        ,
               output        wlast        ,
               output        wvalid       ,
               input         wready       ,
               //b
               input  [3 :0] bid          ,
               input  [1 :0] bresp        ,
               input         bvalid       ,
               output        bready       
               //input         buser
           );
wire resetn = !reset;
//addr
reg do_req;
reg do_req_or; //req is inst or data;1:data,0:inst
reg        do_wr_r;
reg [1 :0] do_size_r;
reg [63:0] do_addr_r;
reg [63:0] do_wdata_r;
wire data_back;

assign inst_addr_ok = !do_req&&!data_req;
assign data_addr_ok = !do_req;
always @(posedge clock)
begin
    do_req     <= !resetn                       ? 1'b0 :
                  (inst_req||data_req)&&!do_req ? 1'b1 :
                  data_back                     ? 1'b0 : do_req;
    do_req_or  <= !resetn ? 1'b0 :
                  !do_req ? data_req : do_req_or;

    do_wr_r    <= data_req&&data_addr_ok ? data_wr :
                  inst_req&&inst_addr_ok ? inst_wr : do_wr_r;
    do_size_r  <= data_req&&data_addr_ok ? data_size :
                  inst_req&&inst_addr_ok ? inst_size : do_size_r;
    do_addr_r  <= data_req&&data_addr_ok ? data_addr :
                  inst_req&&inst_addr_ok ? inst_addr : do_addr_r;
    do_wdata_r <= data_req&&data_addr_ok ? data_wdata :
                  inst_req&&inst_addr_ok ? inst_wdata :do_wdata_r;
end

//inst sram-like
assign inst_data_ok = do_req&&!do_req_or&&data_back;
assign data_data_ok = do_req&& do_req_or&&data_back;
assign inst_rdata   = rdata;
assign data_rdata   = rdata;

//---axi
reg addr_rcv;
reg wdata_rcv;

assign data_back = addr_rcv && (rvalid&&rready||bvalid&&bready);
always @(posedge clock)
begin
    addr_rcv  <= !resetn          ? 1'b0 :
                 arvalid&&arready ? 1'b1 :
                 awvalid&&awready ? 1'b1 :
                 data_back        ? 1'b0 : addr_rcv;
    wdata_rcv <= !resetn        ? 1'b0 :
                 wvalid&&wready ? 1'b1 :
                 data_back      ? 1'b0 : wdata_rcv;
end
//ar
assign arid    = 4'd0;
assign araddr  = do_addr_r;
assign arlen   = 8'd0;
assign arsize  = do_size_r;
assign arburst = 2'd0;
assign arlock  = 2'd0;
assign arcache = 4'd0;
assign arprot  = 3'd0;
assign arvalid = do_req&&!do_wr_r&&!addr_rcv;
//r
assign rready  = 1'b1;

//aw
assign awid    = 4'd0;
assign awaddr  = do_addr_r;
assign awlen   = 8'd0;
assign awsize  = do_size_r;
assign awburst = 2'd0;
assign awlock  = 2'd0;
assign awcache = 4'd0;
assign awprot  = 3'd0;
assign awvalid = do_req&&do_wr_r&&!addr_rcv;
//w
assign wid    = 4'd0;
assign wdata  = do_wdata_r;
assign wstrb  = do_size_r==2'd0 ? 8'b00000001<<do_addr_r[2:0] :
                do_size_r==2'd1 ? 8'b00000011<<do_addr_r[2:0] :
                do_size_r==2'd2 ? 8'b00001111<<do_addr_r[2:0] : 8'b11111111;
assign wlast  = 1'd1;
assign wvalid = do_req&&do_wr_r&&!wdata_rcv;
//b
assign bready  = 1'b1;

endmodule


           
    
module zzy_Cpath(
  input         clock,
  input         reset,
  input  [63:0] io_dat_dec_inst,
  input         io_dat_exe_br_eq,
  input         io_dat_exe_br_lt,
  input         io_dat_exe_br_ltu,
  input  [3:0]  io_dat_exe_br_type,
  input         io_dat_exe_ctrl_dmem_val,
  input         io_dat_inst_valid,
  input         io_dat_data_valid,
  output        io_ctl_dec_stall,
  output        io_ctl_full_stall,
  output [1:0]  io_ctl_exe_pc_sel,
  output [3:0]  io_ctl_br_type,
  output        io_ctl_if_kill,
  output        io_ctl_dec_kill,
  output [1:0]  io_ctl_op1_sel,
  output [2:0]  io_ctl_op2_sel,
  output [4:0]  io_ctl_alu_fun,
  output [2:0]  io_ctl_wb_sel,
  output        io_ctl_rf_wen,
  output        io_ctl_mem_val,
  output [1:0]  io_ctl_mem_fcn,
  output [7:0]  io_ctl_mem_typ,
  output [2:0]  io_ctl_mem_wid
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
`endif // RANDOMIZE_REG_INIT
  wire [63:0] _T = io_dat_dec_inst & 64'h707f; // @[Lookup.scala 31:38]
  wire  _T_1 = 64'h3003 == _T; // @[Lookup.scala 31:38]
  wire  _T_3 = 64'h2003 == _T; // @[Lookup.scala 31:38]
  wire  _T_5 = 64'h6003 == _T; // @[Lookup.scala 31:38]
  wire  _T_7 = 64'h3 == _T; // @[Lookup.scala 31:38]
  wire  _T_9 = 64'h4003 == _T; // @[Lookup.scala 31:38]
  wire  _T_11 = 64'h1003 == _T; // @[Lookup.scala 31:38]
  wire  _T_13 = 64'h5003 == _T; // @[Lookup.scala 31:38]
  wire  _T_15 = 64'h3023 == _T; // @[Lookup.scala 31:38]
  wire  _T_17 = 64'h2023 == _T; // @[Lookup.scala 31:38]
  wire  _T_19 = 64'h23 == _T; // @[Lookup.scala 31:38]
  wire  _T_21 = 64'h1023 == _T; // @[Lookup.scala 31:38]
  wire [63:0] _T_22 = io_dat_dec_inst & 64'h7f; // @[Lookup.scala 31:38]
  wire  _T_23 = 64'h17 == _T_22; // @[Lookup.scala 31:38]
  wire  _T_25 = 64'h37 == _T_22; // @[Lookup.scala 31:38]
  wire  _T_27 = 64'h13 == _T; // @[Lookup.scala 31:38]
  wire  _T_29 = 64'h7013 == _T; // @[Lookup.scala 31:38]
  wire  _T_31 = 64'h6013 == _T; // @[Lookup.scala 31:38]
  wire  _T_33 = 64'h4013 == _T; // @[Lookup.scala 31:38]
  wire  _T_35 = 64'h2013 == _T; // @[Lookup.scala 31:38]
  wire  _T_37 = 64'h3013 == _T; // @[Lookup.scala 31:38]
  wire [63:0] _T_38 = io_dat_dec_inst & 64'hfc00707f; // @[Lookup.scala 31:38]
  wire  _T_39 = 64'h1013 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_41 = 64'h40005013 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_43 = 64'h5013 == _T_38; // @[Lookup.scala 31:38]
  wire [63:0] _T_44 = io_dat_dec_inst & 64'hfe00707f; // @[Lookup.scala 31:38]
  wire  _T_45 = 64'h1033 == _T_44; // @[Lookup.scala 31:38]
  wire  _T_47 = 64'h33 == _T_44; // @[Lookup.scala 31:38]
  wire  _T_49 = 64'h40000033 == _T_44; // @[Lookup.scala 31:38]
  wire  _T_51 = 64'h2033 == _T_44; // @[Lookup.scala 31:38]
  wire  _T_53 = 64'h3033 == _T_44; // @[Lookup.scala 31:38]
  wire  _T_55 = 64'h7033 == _T_44; // @[Lookup.scala 31:38]
  wire  _T_57 = 64'h6033 == _T_44; // @[Lookup.scala 31:38]
  wire  _T_59 = 64'h4033 == _T_44; // @[Lookup.scala 31:38]
  wire  _T_61 = 64'h40005033 == _T_44; // @[Lookup.scala 31:38]
  wire  _T_63 = 64'h5033 == _T_44; // @[Lookup.scala 31:38]
  wire  _T_65 = 64'h1b == _T; // @[Lookup.scala 31:38]
  wire  _T_67 = 64'h101b == _T_44; // @[Lookup.scala 31:38]
  wire  _T_69 = 64'h501b == _T_44; // @[Lookup.scala 31:38]
  wire  _T_71 = 64'h4000501b == _T_44; // @[Lookup.scala 31:38]
  wire  _T_73 = 64'h3b == _T_44; // @[Lookup.scala 31:38]
  wire  _T_75 = 64'h4000003b == _T_44; // @[Lookup.scala 31:38]
  wire  _T_77 = 64'h103b == _T_44; // @[Lookup.scala 31:38]
  wire  _T_79 = 64'h4000503b == _T_44; // @[Lookup.scala 31:38]
  wire  _T_81 = 64'h503b == _T_44; // @[Lookup.scala 31:38]
  wire  _T_83 = 64'h6f == _T_22; // @[Lookup.scala 31:38]
  wire  _T_85 = 64'h67 == _T; // @[Lookup.scala 31:38]
  wire  _T_87 = 64'h63 == _T; // @[Lookup.scala 31:38]
  wire  _T_89 = 64'h1063 == _T; // @[Lookup.scala 31:38]
  wire  _T_91 = 64'h5063 == _T; // @[Lookup.scala 31:38]
  wire  _T_93 = 64'h7063 == _T; // @[Lookup.scala 31:38]
  wire  _T_95 = 64'h4063 == _T; // @[Lookup.scala 31:38]
  wire  _T_97 = 64'h6063 == _T; // @[Lookup.scala 31:38]
  wire  _T_99 = 64'h2000033 == _T_44; // @[Lookup.scala 31:38]
  wire  _T_101 = 64'h200003b == _T_44; // @[Lookup.scala 31:38]
  wire  _T_103 = 64'h2001033 == _T_44; // @[Lookup.scala 31:38]
  wire  _T_105 = 64'h2002033 == _T_44; // @[Lookup.scala 31:38]
  wire  _T_107 = 64'h2003033 == _T_44; // @[Lookup.scala 31:38]
  wire  _T_109 = 64'h2004033 == _T_44; // @[Lookup.scala 31:38]
  wire  _T_111 = 64'h200503b == _T_44; // @[Lookup.scala 31:38]
  wire  _T_113 = 64'h2005033 == _T_44; // @[Lookup.scala 31:38]
  wire  _T_115 = 64'h200403b == _T_44; // @[Lookup.scala 31:38]
  wire  _T_117 = 64'h200603b == _T_44; // @[Lookup.scala 31:38]
  wire  _T_119 = 64'h200703b == _T_44; // @[Lookup.scala 31:38]
  wire  _T_121 = 64'h2006033 == _T_44; // @[Lookup.scala 31:38]
  wire  _T_123 = 64'h2007033 == _T_44; // @[Lookup.scala 31:38]
  wire  _T_125 = 64'h5073 == _T; // @[Lookup.scala 31:38]
  wire  _T_127 = 64'h6073 == _T; // @[Lookup.scala 31:38]
  wire  _T_129 = 64'h1073 == _T; // @[Lookup.scala 31:38]
  wire  _T_131 = 64'h2073 == _T; // @[Lookup.scala 31:38]
  wire  _T_133 = 64'h3073 == _T; // @[Lookup.scala 31:38]
  wire  _T_135 = 64'h7073 == _T; // @[Lookup.scala 31:38]
  wire [63:0] _T_136 = io_dat_dec_inst & 64'hffffffff; // @[Lookup.scala 31:38]
  wire  _T_137 = 64'h73 == _T_136; // @[Lookup.scala 31:38]
  wire  _T_139 = 64'h30200073 == _T_136; // @[Lookup.scala 31:38]
  wire  _T_141 = 64'h10200073 == _T_136; // @[Lookup.scala 31:38]
  wire  _T_143 = 64'h100073 == _T_136; // @[Lookup.scala 31:38]
  wire  _T_145 = 64'h10500073 == _T_136; // @[Lookup.scala 31:38]
  wire  _T_147 = 64'h100f == _T; // @[Lookup.scala 31:38]
  wire  _T_149 = 64'hf == _T; // @[Lookup.scala 31:38]
  wire [3:0] _T_250 = _T_97 ? 4'h6 : 4'h0; // @[Lookup.scala 33:37]
  wire [3:0] _T_251 = _T_95 ? 4'h5 : _T_250; // @[Lookup.scala 33:37]
  wire [3:0] _T_252 = _T_93 ? 4'h4 : _T_251; // @[Lookup.scala 33:37]
  wire [3:0] _T_253 = _T_91 ? 4'h3 : _T_252; // @[Lookup.scala 33:37]
  wire [3:0] _T_254 = _T_89 ? 4'h1 : _T_253; // @[Lookup.scala 33:37]
  wire [3:0] _T_255 = _T_87 ? 4'h2 : _T_254; // @[Lookup.scala 33:37]
  wire [3:0] _T_256 = _T_85 ? 4'h8 : _T_255; // @[Lookup.scala 33:37]
  wire [3:0] _T_257 = _T_83 ? 4'h7 : _T_256; // @[Lookup.scala 33:37]
  wire [3:0] _T_258 = _T_81 ? 4'h0 : _T_257; // @[Lookup.scala 33:37]
  wire [3:0] _T_259 = _T_79 ? 4'h0 : _T_258; // @[Lookup.scala 33:37]
  wire [3:0] _T_260 = _T_77 ? 4'h0 : _T_259; // @[Lookup.scala 33:37]
  wire [3:0] _T_261 = _T_75 ? 4'h0 : _T_260; // @[Lookup.scala 33:37]
  wire [3:0] _T_262 = _T_73 ? 4'h0 : _T_261; // @[Lookup.scala 33:37]
  wire [3:0] _T_263 = _T_71 ? 4'h0 : _T_262; // @[Lookup.scala 33:37]
  wire [3:0] _T_264 = _T_69 ? 4'h0 : _T_263; // @[Lookup.scala 33:37]
  wire [3:0] _T_265 = _T_67 ? 4'h0 : _T_264; // @[Lookup.scala 33:37]
  wire [3:0] _T_266 = _T_65 ? 4'h0 : _T_265; // @[Lookup.scala 33:37]
  wire [3:0] _T_267 = _T_63 ? 4'h0 : _T_266; // @[Lookup.scala 33:37]
  wire [3:0] _T_268 = _T_61 ? 4'h0 : _T_267; // @[Lookup.scala 33:37]
  wire [3:0] _T_269 = _T_59 ? 4'h0 : _T_268; // @[Lookup.scala 33:37]
  wire [3:0] _T_270 = _T_57 ? 4'h0 : _T_269; // @[Lookup.scala 33:37]
  wire [3:0] _T_271 = _T_55 ? 4'h0 : _T_270; // @[Lookup.scala 33:37]
  wire [3:0] _T_272 = _T_53 ? 4'h0 : _T_271; // @[Lookup.scala 33:37]
  wire [3:0] _T_273 = _T_51 ? 4'h0 : _T_272; // @[Lookup.scala 33:37]
  wire [3:0] _T_274 = _T_49 ? 4'h0 : _T_273; // @[Lookup.scala 33:37]
  wire [3:0] _T_275 = _T_47 ? 4'h0 : _T_274; // @[Lookup.scala 33:37]
  wire [3:0] _T_276 = _T_45 ? 4'h0 : _T_275; // @[Lookup.scala 33:37]
  wire [3:0] _T_277 = _T_43 ? 4'h0 : _T_276; // @[Lookup.scala 33:37]
  wire [3:0] _T_278 = _T_41 ? 4'h0 : _T_277; // @[Lookup.scala 33:37]
  wire [3:0] _T_279 = _T_39 ? 4'h0 : _T_278; // @[Lookup.scala 33:37]
  wire [3:0] _T_280 = _T_37 ? 4'h0 : _T_279; // @[Lookup.scala 33:37]
  wire [3:0] _T_281 = _T_35 ? 4'h0 : _T_280; // @[Lookup.scala 33:37]
  wire [3:0] _T_282 = _T_33 ? 4'h0 : _T_281; // @[Lookup.scala 33:37]
  wire [3:0] _T_283 = _T_31 ? 4'h0 : _T_282; // @[Lookup.scala 33:37]
  wire [3:0] _T_284 = _T_29 ? 4'h0 : _T_283; // @[Lookup.scala 33:37]
  wire [3:0] _T_285 = _T_27 ? 4'h0 : _T_284; // @[Lookup.scala 33:37]
  wire [3:0] _T_286 = _T_25 ? 4'h0 : _T_285; // @[Lookup.scala 33:37]
  wire [3:0] _T_287 = _T_23 ? 4'h0 : _T_286; // @[Lookup.scala 33:37]
  wire [3:0] _T_288 = _T_21 ? 4'h0 : _T_287; // @[Lookup.scala 33:37]
  wire [3:0] _T_289 = _T_19 ? 4'h0 : _T_288; // @[Lookup.scala 33:37]
  wire [3:0] _T_290 = _T_17 ? 4'h0 : _T_289; // @[Lookup.scala 33:37]
  wire [3:0] _T_291 = _T_15 ? 4'h0 : _T_290; // @[Lookup.scala 33:37]
  wire [3:0] _T_292 = _T_13 ? 4'h0 : _T_291; // @[Lookup.scala 33:37]
  wire [3:0] _T_293 = _T_11 ? 4'h0 : _T_292; // @[Lookup.scala 33:37]
  wire [3:0] _T_294 = _T_9 ? 4'h0 : _T_293; // @[Lookup.scala 33:37]
  wire [3:0] _T_295 = _T_7 ? 4'h0 : _T_294; // @[Lookup.scala 33:37]
  wire [3:0] _T_296 = _T_5 ? 4'h0 : _T_295; // @[Lookup.scala 33:37]
  wire [3:0] _T_297 = _T_3 ? 4'h0 : _T_296; // @[Lookup.scala 33:37]
  wire [1:0] _T_305 = _T_135 ? 2'h2 : 2'h0; // @[Lookup.scala 33:37]
  wire [1:0] _T_306 = _T_133 ? 2'h0 : _T_305; // @[Lookup.scala 33:37]
  wire [1:0] _T_307 = _T_131 ? 2'h0 : _T_306; // @[Lookup.scala 33:37]
  wire [1:0] _T_308 = _T_129 ? 2'h0 : _T_307; // @[Lookup.scala 33:37]
  wire [1:0] _T_309 = _T_127 ? 2'h2 : _T_308; // @[Lookup.scala 33:37]
  wire [1:0] _T_310 = _T_125 ? 2'h2 : _T_309; // @[Lookup.scala 33:37]
  wire [1:0] _T_311 = _T_123 ? 2'h0 : _T_310; // @[Lookup.scala 33:37]
  wire [1:0] _T_312 = _T_121 ? 2'h0 : _T_311; // @[Lookup.scala 33:37]
  wire [1:0] _T_313 = _T_119 ? 2'h0 : _T_312; // @[Lookup.scala 33:37]
  wire [1:0] _T_314 = _T_117 ? 2'h0 : _T_313; // @[Lookup.scala 33:37]
  wire [1:0] _T_315 = _T_115 ? 2'h0 : _T_314; // @[Lookup.scala 33:37]
  wire [1:0] _T_316 = _T_113 ? 2'h0 : _T_315; // @[Lookup.scala 33:37]
  wire [1:0] _T_317 = _T_111 ? 2'h0 : _T_316; // @[Lookup.scala 33:37]
  wire [1:0] _T_318 = _T_109 ? 2'h0 : _T_317; // @[Lookup.scala 33:37]
  wire [1:0] _T_319 = _T_107 ? 2'h0 : _T_318; // @[Lookup.scala 33:37]
  wire [1:0] _T_320 = _T_105 ? 2'h0 : _T_319; // @[Lookup.scala 33:37]
  wire [1:0] _T_321 = _T_103 ? 2'h0 : _T_320; // @[Lookup.scala 33:37]
  wire [1:0] _T_322 = _T_101 ? 2'h0 : _T_321; // @[Lookup.scala 33:37]
  wire [1:0] _T_323 = _T_99 ? 2'h0 : _T_322; // @[Lookup.scala 33:37]
  wire [1:0] _T_324 = _T_97 ? 2'h0 : _T_323; // @[Lookup.scala 33:37]
  wire [1:0] _T_325 = _T_95 ? 2'h0 : _T_324; // @[Lookup.scala 33:37]
  wire [1:0] _T_326 = _T_93 ? 2'h0 : _T_325; // @[Lookup.scala 33:37]
  wire [1:0] _T_327 = _T_91 ? 2'h0 : _T_326; // @[Lookup.scala 33:37]
  wire [1:0] _T_328 = _T_89 ? 2'h0 : _T_327; // @[Lookup.scala 33:37]
  wire [1:0] _T_329 = _T_87 ? 2'h0 : _T_328; // @[Lookup.scala 33:37]
  wire [1:0] _T_330 = _T_85 ? 2'h0 : _T_329; // @[Lookup.scala 33:37]
  wire [1:0] _T_331 = _T_83 ? 2'h0 : _T_330; // @[Lookup.scala 33:37]
  wire [1:0] _T_332 = _T_81 ? 2'h3 : _T_331; // @[Lookup.scala 33:37]
  wire [1:0] _T_333 = _T_79 ? 2'h3 : _T_332; // @[Lookup.scala 33:37]
  wire [1:0] _T_334 = _T_77 ? 2'h3 : _T_333; // @[Lookup.scala 33:37]
  wire [1:0] _T_335 = _T_75 ? 2'h0 : _T_334; // @[Lookup.scala 33:37]
  wire [1:0] _T_336 = _T_73 ? 2'h0 : _T_335; // @[Lookup.scala 33:37]
  wire [1:0] _T_337 = _T_71 ? 2'h3 : _T_336; // @[Lookup.scala 33:37]
  wire [1:0] _T_338 = _T_69 ? 2'h3 : _T_337; // @[Lookup.scala 33:37]
  wire [1:0] _T_339 = _T_67 ? 2'h3 : _T_338; // @[Lookup.scala 33:37]
  wire [1:0] _T_340 = _T_65 ? 2'h0 : _T_339; // @[Lookup.scala 33:37]
  wire [1:0] _T_341 = _T_63 ? 2'h0 : _T_340; // @[Lookup.scala 33:37]
  wire [1:0] _T_342 = _T_61 ? 2'h0 : _T_341; // @[Lookup.scala 33:37]
  wire [1:0] _T_343 = _T_59 ? 2'h0 : _T_342; // @[Lookup.scala 33:37]
  wire [1:0] _T_344 = _T_57 ? 2'h0 : _T_343; // @[Lookup.scala 33:37]
  wire [1:0] _T_345 = _T_55 ? 2'h0 : _T_344; // @[Lookup.scala 33:37]
  wire [1:0] _T_346 = _T_53 ? 2'h0 : _T_345; // @[Lookup.scala 33:37]
  wire [1:0] _T_347 = _T_51 ? 2'h0 : _T_346; // @[Lookup.scala 33:37]
  wire [1:0] _T_348 = _T_49 ? 2'h0 : _T_347; // @[Lookup.scala 33:37]
  wire [1:0] _T_349 = _T_47 ? 2'h0 : _T_348; // @[Lookup.scala 33:37]
  wire [1:0] _T_350 = _T_45 ? 2'h0 : _T_349; // @[Lookup.scala 33:37]
  wire [1:0] _T_351 = _T_43 ? 2'h0 : _T_350; // @[Lookup.scala 33:37]
  wire [1:0] _T_352 = _T_41 ? 2'h0 : _T_351; // @[Lookup.scala 33:37]
  wire [1:0] _T_353 = _T_39 ? 2'h0 : _T_352; // @[Lookup.scala 33:37]
  wire [1:0] _T_354 = _T_37 ? 2'h0 : _T_353; // @[Lookup.scala 33:37]
  wire [1:0] _T_355 = _T_35 ? 2'h0 : _T_354; // @[Lookup.scala 33:37]
  wire [1:0] _T_356 = _T_33 ? 2'h0 : _T_355; // @[Lookup.scala 33:37]
  wire [1:0] _T_357 = _T_31 ? 2'h0 : _T_356; // @[Lookup.scala 33:37]
  wire [1:0] _T_358 = _T_29 ? 2'h0 : _T_357; // @[Lookup.scala 33:37]
  wire [1:0] _T_359 = _T_27 ? 2'h0 : _T_358; // @[Lookup.scala 33:37]
  wire [1:0] _T_360 = _T_25 ? 2'h0 : _T_359; // @[Lookup.scala 33:37]
  wire [1:0] _T_361 = _T_23 ? 2'h1 : _T_360; // @[Lookup.scala 33:37]
  wire [1:0] _T_362 = _T_21 ? 2'h0 : _T_361; // @[Lookup.scala 33:37]
  wire [1:0] _T_363 = _T_19 ? 2'h0 : _T_362; // @[Lookup.scala 33:37]
  wire [1:0] _T_364 = _T_17 ? 2'h0 : _T_363; // @[Lookup.scala 33:37]
  wire [1:0] _T_365 = _T_15 ? 2'h0 : _T_364; // @[Lookup.scala 33:37]
  wire [1:0] _T_366 = _T_13 ? 2'h0 : _T_365; // @[Lookup.scala 33:37]
  wire [1:0] _T_367 = _T_11 ? 2'h0 : _T_366; // @[Lookup.scala 33:37]
  wire [1:0] _T_368 = _T_9 ? 2'h0 : _T_367; // @[Lookup.scala 33:37]
  wire [1:0] _T_369 = _T_7 ? 2'h0 : _T_368; // @[Lookup.scala 33:37]
  wire [1:0] _T_370 = _T_5 ? 2'h0 : _T_369; // @[Lookup.scala 33:37]
  wire [1:0] _T_371 = _T_3 ? 2'h0 : _T_370; // @[Lookup.scala 33:37]
  wire [2:0] _T_398 = _T_97 ? 3'h3 : 3'h0; // @[Lookup.scala 33:37]
  wire [2:0] _T_399 = _T_95 ? 3'h3 : _T_398; // @[Lookup.scala 33:37]
  wire [2:0] _T_400 = _T_93 ? 3'h3 : _T_399; // @[Lookup.scala 33:37]
  wire [2:0] _T_401 = _T_91 ? 3'h3 : _T_400; // @[Lookup.scala 33:37]
  wire [2:0] _T_402 = _T_89 ? 3'h3 : _T_401; // @[Lookup.scala 33:37]
  wire [2:0] _T_403 = _T_87 ? 3'h3 : _T_402; // @[Lookup.scala 33:37]
  wire [2:0] _T_404 = _T_85 ? 3'h1 : _T_403; // @[Lookup.scala 33:37]
  wire [2:0] _T_405 = _T_83 ? 3'h5 : _T_404; // @[Lookup.scala 33:37]
  wire [2:0] _T_406 = _T_81 ? 3'h0 : _T_405; // @[Lookup.scala 33:37]
  wire [2:0] _T_407 = _T_79 ? 3'h0 : _T_406; // @[Lookup.scala 33:37]
  wire [2:0] _T_408 = _T_77 ? 3'h0 : _T_407; // @[Lookup.scala 33:37]
  wire [2:0] _T_409 = _T_75 ? 3'h0 : _T_408; // @[Lookup.scala 33:37]
  wire [2:0] _T_410 = _T_73 ? 3'h0 : _T_409; // @[Lookup.scala 33:37]
  wire [2:0] _T_411 = _T_71 ? 3'h1 : _T_410; // @[Lookup.scala 33:37]
  wire [2:0] _T_412 = _T_69 ? 3'h1 : _T_411; // @[Lookup.scala 33:37]
  wire [2:0] _T_413 = _T_67 ? 3'h1 : _T_412; // @[Lookup.scala 33:37]
  wire [2:0] _T_414 = _T_65 ? 3'h1 : _T_413; // @[Lookup.scala 33:37]
  wire [2:0] _T_415 = _T_63 ? 3'h0 : _T_414; // @[Lookup.scala 33:37]
  wire [2:0] _T_416 = _T_61 ? 3'h0 : _T_415; // @[Lookup.scala 33:37]
  wire [2:0] _T_417 = _T_59 ? 3'h0 : _T_416; // @[Lookup.scala 33:37]
  wire [2:0] _T_418 = _T_57 ? 3'h0 : _T_417; // @[Lookup.scala 33:37]
  wire [2:0] _T_419 = _T_55 ? 3'h0 : _T_418; // @[Lookup.scala 33:37]
  wire [2:0] _T_420 = _T_53 ? 3'h0 : _T_419; // @[Lookup.scala 33:37]
  wire [2:0] _T_421 = _T_51 ? 3'h0 : _T_420; // @[Lookup.scala 33:37]
  wire [2:0] _T_422 = _T_49 ? 3'h0 : _T_421; // @[Lookup.scala 33:37]
  wire [2:0] _T_423 = _T_47 ? 3'h0 : _T_422; // @[Lookup.scala 33:37]
  wire [2:0] _T_424 = _T_45 ? 3'h0 : _T_423; // @[Lookup.scala 33:37]
  wire [2:0] _T_425 = _T_43 ? 3'h1 : _T_424; // @[Lookup.scala 33:37]
  wire [2:0] _T_426 = _T_41 ? 3'h1 : _T_425; // @[Lookup.scala 33:37]
  wire [2:0] _T_427 = _T_39 ? 3'h1 : _T_426; // @[Lookup.scala 33:37]
  wire [2:0] _T_428 = _T_37 ? 3'h1 : _T_427; // @[Lookup.scala 33:37]
  wire [2:0] _T_429 = _T_35 ? 3'h1 : _T_428; // @[Lookup.scala 33:37]
  wire [2:0] _T_430 = _T_33 ? 3'h1 : _T_429; // @[Lookup.scala 33:37]
  wire [2:0] _T_431 = _T_31 ? 3'h1 : _T_430; // @[Lookup.scala 33:37]
  wire [2:0] _T_432 = _T_29 ? 3'h1 : _T_431; // @[Lookup.scala 33:37]
  wire [2:0] _T_433 = _T_27 ? 3'h1 : _T_432; // @[Lookup.scala 33:37]
  wire [2:0] _T_434 = _T_25 ? 3'h4 : _T_433; // @[Lookup.scala 33:37]
  wire [2:0] _T_435 = _T_23 ? 3'h4 : _T_434; // @[Lookup.scala 33:37]
  wire [2:0] _T_436 = _T_21 ? 3'h2 : _T_435; // @[Lookup.scala 33:37]
  wire [2:0] _T_437 = _T_19 ? 3'h2 : _T_436; // @[Lookup.scala 33:37]
  wire [2:0] _T_438 = _T_17 ? 3'h2 : _T_437; // @[Lookup.scala 33:37]
  wire [2:0] _T_439 = _T_15 ? 3'h2 : _T_438; // @[Lookup.scala 33:37]
  wire [2:0] _T_440 = _T_13 ? 3'h1 : _T_439; // @[Lookup.scala 33:37]
  wire [2:0] _T_441 = _T_11 ? 3'h1 : _T_440; // @[Lookup.scala 33:37]
  wire [2:0] _T_442 = _T_9 ? 3'h1 : _T_441; // @[Lookup.scala 33:37]
  wire [2:0] _T_443 = _T_7 ? 3'h1 : _T_442; // @[Lookup.scala 33:37]
  wire [2:0] _T_444 = _T_5 ? 3'h1 : _T_443; // @[Lookup.scala 33:37]
  wire [2:0] _T_445 = _T_3 ? 3'h1 : _T_444; // @[Lookup.scala 33:37]
  wire  _T_454 = _T_133 | _T_135; // @[Lookup.scala 33:37]
  wire  _T_455 = _T_131 | _T_454; // @[Lookup.scala 33:37]
  wire  _T_456 = _T_129 | _T_455; // @[Lookup.scala 33:37]
  wire  _T_457 = _T_127 | _T_456; // @[Lookup.scala 33:37]
  wire  _T_458 = _T_125 | _T_457; // @[Lookup.scala 33:37]
  wire  _T_459 = _T_123 | _T_458; // @[Lookup.scala 33:37]
  wire  _T_460 = _T_121 | _T_459; // @[Lookup.scala 33:37]
  wire  _T_461 = _T_119 | _T_460; // @[Lookup.scala 33:37]
  wire  _T_462 = _T_117 | _T_461; // @[Lookup.scala 33:37]
  wire  _T_463 = _T_115 | _T_462; // @[Lookup.scala 33:37]
  wire  _T_464 = _T_113 | _T_463; // @[Lookup.scala 33:37]
  wire  _T_465 = _T_111 | _T_464; // @[Lookup.scala 33:37]
  wire  _T_466 = _T_109 | _T_465; // @[Lookup.scala 33:37]
  wire  _T_467 = _T_107 | _T_466; // @[Lookup.scala 33:37]
  wire  _T_468 = _T_105 | _T_467; // @[Lookup.scala 33:37]
  wire  _T_469 = _T_103 | _T_468; // @[Lookup.scala 33:37]
  wire  _T_470 = _T_101 | _T_469; // @[Lookup.scala 33:37]
  wire  _T_471 = _T_99 | _T_470; // @[Lookup.scala 33:37]
  wire  _T_472 = _T_97 | _T_471; // @[Lookup.scala 33:37]
  wire  _T_473 = _T_95 | _T_472; // @[Lookup.scala 33:37]
  wire  _T_474 = _T_93 | _T_473; // @[Lookup.scala 33:37]
  wire  _T_475 = _T_91 | _T_474; // @[Lookup.scala 33:37]
  wire  _T_476 = _T_89 | _T_475; // @[Lookup.scala 33:37]
  wire  _T_477 = _T_87 | _T_476; // @[Lookup.scala 33:37]
  wire  _T_478 = _T_85 | _T_477; // @[Lookup.scala 33:37]
  wire  _T_479 = _T_83 ? 1'h0 : _T_478; // @[Lookup.scala 33:37]
  wire  _T_480 = _T_81 | _T_479; // @[Lookup.scala 33:37]
  wire  _T_481 = _T_79 | _T_480; // @[Lookup.scala 33:37]
  wire  _T_482 = _T_77 | _T_481; // @[Lookup.scala 33:37]
  wire  _T_483 = _T_75 | _T_482; // @[Lookup.scala 33:37]
  wire  _T_484 = _T_73 | _T_483; // @[Lookup.scala 33:37]
  wire  _T_485 = _T_71 | _T_484; // @[Lookup.scala 33:37]
  wire  _T_486 = _T_69 | _T_485; // @[Lookup.scala 33:37]
  wire  _T_487 = _T_67 | _T_486; // @[Lookup.scala 33:37]
  wire  _T_488 = _T_65 | _T_487; // @[Lookup.scala 33:37]
  wire  _T_489 = _T_63 | _T_488; // @[Lookup.scala 33:37]
  wire  _T_490 = _T_61 | _T_489; // @[Lookup.scala 33:37]
  wire  _T_491 = _T_59 | _T_490; // @[Lookup.scala 33:37]
  wire  _T_492 = _T_57 | _T_491; // @[Lookup.scala 33:37]
  wire  _T_493 = _T_55 | _T_492; // @[Lookup.scala 33:37]
  wire  _T_494 = _T_53 | _T_493; // @[Lookup.scala 33:37]
  wire  _T_495 = _T_51 | _T_494; // @[Lookup.scala 33:37]
  wire  _T_496 = _T_49 | _T_495; // @[Lookup.scala 33:37]
  wire  _T_497 = _T_47 | _T_496; // @[Lookup.scala 33:37]
  wire  _T_498 = _T_45 | _T_497; // @[Lookup.scala 33:37]
  wire  _T_499 = _T_43 | _T_498; // @[Lookup.scala 33:37]
  wire  _T_500 = _T_41 | _T_499; // @[Lookup.scala 33:37]
  wire  _T_501 = _T_39 | _T_500; // @[Lookup.scala 33:37]
  wire  _T_502 = _T_37 | _T_501; // @[Lookup.scala 33:37]
  wire  _T_503 = _T_35 | _T_502; // @[Lookup.scala 33:37]
  wire  _T_504 = _T_33 | _T_503; // @[Lookup.scala 33:37]
  wire  _T_505 = _T_31 | _T_504; // @[Lookup.scala 33:37]
  wire  _T_506 = _T_29 | _T_505; // @[Lookup.scala 33:37]
  wire  _T_507 = _T_27 | _T_506; // @[Lookup.scala 33:37]
  wire  _T_508 = _T_25 ? 1'h0 : _T_507; // @[Lookup.scala 33:37]
  wire  _T_509 = _T_23 ? 1'h0 : _T_508; // @[Lookup.scala 33:37]
  wire  _T_510 = _T_21 | _T_509; // @[Lookup.scala 33:37]
  wire  _T_511 = _T_19 | _T_510; // @[Lookup.scala 33:37]
  wire  _T_512 = _T_17 | _T_511; // @[Lookup.scala 33:37]
  wire  _T_513 = _T_15 | _T_512; // @[Lookup.scala 33:37]
  wire  _T_514 = _T_13 | _T_513; // @[Lookup.scala 33:37]
  wire  _T_515 = _T_11 | _T_514; // @[Lookup.scala 33:37]
  wire  _T_516 = _T_9 | _T_515; // @[Lookup.scala 33:37]
  wire  _T_517 = _T_7 | _T_516; // @[Lookup.scala 33:37]
  wire  _T_518 = _T_5 | _T_517; // @[Lookup.scala 33:37]
  wire  _T_519 = _T_3 | _T_518; // @[Lookup.scala 33:37]
  wire  cs_rs1_oen = _T_1 | _T_519; // @[Lookup.scala 33:37]
  wire  _T_552 = _T_85 ? 1'h0 : _T_477; // @[Lookup.scala 33:37]
  wire  _T_553 = _T_83 ? 1'h0 : _T_552; // @[Lookup.scala 33:37]
  wire  _T_554 = _T_81 | _T_553; // @[Lookup.scala 33:37]
  wire  _T_555 = _T_79 | _T_554; // @[Lookup.scala 33:37]
  wire  _T_556 = _T_77 | _T_555; // @[Lookup.scala 33:37]
  wire  _T_557 = _T_75 | _T_556; // @[Lookup.scala 33:37]
  wire  _T_558 = _T_73 | _T_557; // @[Lookup.scala 33:37]
  wire  _T_559 = _T_71 ? 1'h0 : _T_558; // @[Lookup.scala 33:37]
  wire  _T_560 = _T_69 ? 1'h0 : _T_559; // @[Lookup.scala 33:37]
  wire  _T_561 = _T_67 ? 1'h0 : _T_560; // @[Lookup.scala 33:37]
  wire  _T_562 = _T_65 ? 1'h0 : _T_561; // @[Lookup.scala 33:37]
  wire  _T_563 = _T_63 | _T_562; // @[Lookup.scala 33:37]
  wire  _T_564 = _T_61 | _T_563; // @[Lookup.scala 33:37]
  wire  _T_565 = _T_59 | _T_564; // @[Lookup.scala 33:37]
  wire  _T_566 = _T_57 | _T_565; // @[Lookup.scala 33:37]
  wire  _T_567 = _T_55 | _T_566; // @[Lookup.scala 33:37]
  wire  _T_568 = _T_53 | _T_567; // @[Lookup.scala 33:37]
  wire  _T_569 = _T_51 | _T_568; // @[Lookup.scala 33:37]
  wire  _T_570 = _T_49 | _T_569; // @[Lookup.scala 33:37]
  wire  _T_571 = _T_47 | _T_570; // @[Lookup.scala 33:37]
  wire  _T_572 = _T_45 | _T_571; // @[Lookup.scala 33:37]
  wire  _T_573 = _T_43 ? 1'h0 : _T_572; // @[Lookup.scala 33:37]
  wire  _T_574 = _T_41 ? 1'h0 : _T_573; // @[Lookup.scala 33:37]
  wire  _T_575 = _T_39 ? 1'h0 : _T_574; // @[Lookup.scala 33:37]
  wire  _T_576 = _T_37 ? 1'h0 : _T_575; // @[Lookup.scala 33:37]
  wire  _T_577 = _T_35 ? 1'h0 : _T_576; // @[Lookup.scala 33:37]
  wire  _T_578 = _T_33 ? 1'h0 : _T_577; // @[Lookup.scala 33:37]
  wire  _T_579 = _T_31 ? 1'h0 : _T_578; // @[Lookup.scala 33:37]
  wire  _T_580 = _T_29 ? 1'h0 : _T_579; // @[Lookup.scala 33:37]
  wire  _T_581 = _T_27 ? 1'h0 : _T_580; // @[Lookup.scala 33:37]
  wire  _T_582 = _T_25 ? 1'h0 : _T_581; // @[Lookup.scala 33:37]
  wire  _T_583 = _T_23 ? 1'h0 : _T_582; // @[Lookup.scala 33:37]
  wire  _T_584 = _T_21 | _T_583; // @[Lookup.scala 33:37]
  wire  _T_585 = _T_19 | _T_584; // @[Lookup.scala 33:37]
  wire  _T_586 = _T_17 | _T_585; // @[Lookup.scala 33:37]
  wire  _T_587 = _T_15 | _T_586; // @[Lookup.scala 33:37]
  wire  _T_588 = _T_13 ? 1'h0 : _T_587; // @[Lookup.scala 33:37]
  wire  _T_589 = _T_11 ? 1'h0 : _T_588; // @[Lookup.scala 33:37]
  wire  _T_590 = _T_9 ? 1'h0 : _T_589; // @[Lookup.scala 33:37]
  wire  _T_591 = _T_7 ? 1'h0 : _T_590; // @[Lookup.scala 33:37]
  wire  _T_592 = _T_5 ? 1'h0 : _T_591; // @[Lookup.scala 33:37]
  wire  _T_593 = _T_3 ? 1'h0 : _T_592; // @[Lookup.scala 33:37]
  wire  cs_rs2_oen = _T_1 ? 1'h0 : _T_593; // @[Lookup.scala 33:37]
  wire [4:0] _T_601 = _T_135 ? 5'ha : 5'h0; // @[Lookup.scala 33:37]
  wire [4:0] _T_602 = _T_133 ? 5'ha : _T_601; // @[Lookup.scala 33:37]
  wire [4:0] _T_603 = _T_131 ? 5'ha : _T_602; // @[Lookup.scala 33:37]
  wire [4:0] _T_604 = _T_129 ? 5'ha : _T_603; // @[Lookup.scala 33:37]
  wire [4:0] _T_605 = _T_127 ? 5'ha : _T_604; // @[Lookup.scala 33:37]
  wire [4:0] _T_606 = _T_125 ? 5'ha : _T_605; // @[Lookup.scala 33:37]
  wire [4:0] _T_607 = _T_123 ? 5'h18 : _T_606; // @[Lookup.scala 33:37]
  wire [4:0] _T_608 = _T_121 ? 5'h17 : _T_607; // @[Lookup.scala 33:37]
  wire [4:0] _T_609 = _T_119 ? 5'h10 : _T_608; // @[Lookup.scala 33:37]
  wire [4:0] _T_610 = _T_117 ? 5'hf : _T_609; // @[Lookup.scala 33:37]
  wire [4:0] _T_611 = _T_115 ? 5'h16 : _T_610; // @[Lookup.scala 33:37]
  wire [4:0] _T_612 = _T_113 ? 5'h15 : _T_611; // @[Lookup.scala 33:37]
  wire [4:0] _T_613 = _T_111 ? 5'h11 : _T_612; // @[Lookup.scala 33:37]
  wire [4:0] _T_614 = _T_109 ? 5'he : _T_613; // @[Lookup.scala 33:37]
  wire [4:0] _T_615 = _T_107 ? 5'h14 : _T_614; // @[Lookup.scala 33:37]
  wire [4:0] _T_616 = _T_105 ? 5'h13 : _T_615; // @[Lookup.scala 33:37]
  wire [4:0] _T_617 = _T_103 ? 5'h12 : _T_616; // @[Lookup.scala 33:37]
  wire [4:0] _T_618 = _T_101 ? 5'hd : _T_617; // @[Lookup.scala 33:37]
  wire [4:0] _T_619 = _T_99 ? 5'hd : _T_618; // @[Lookup.scala 33:37]
  wire [4:0] _T_620 = _T_97 ? 5'h0 : _T_619; // @[Lookup.scala 33:37]
  wire [4:0] _T_621 = _T_95 ? 5'h0 : _T_620; // @[Lookup.scala 33:37]
  wire [4:0] _T_622 = _T_93 ? 5'h0 : _T_621; // @[Lookup.scala 33:37]
  wire [4:0] _T_623 = _T_91 ? 5'h0 : _T_622; // @[Lookup.scala 33:37]
  wire [4:0] _T_624 = _T_89 ? 5'h0 : _T_623; // @[Lookup.scala 33:37]
  wire [4:0] _T_625 = _T_87 ? 5'h0 : _T_624; // @[Lookup.scala 33:37]
  wire [4:0] _T_626 = _T_85 ? 5'h0 : _T_625; // @[Lookup.scala 33:37]
  wire [4:0] _T_627 = _T_83 ? 5'h0 : _T_626; // @[Lookup.scala 33:37]
  wire [4:0] _T_628 = _T_81 ? 5'h1a : _T_627; // @[Lookup.scala 33:37]
  wire [4:0] _T_629 = _T_79 ? 5'hc : _T_628; // @[Lookup.scala 33:37]
  wire [4:0] _T_630 = _T_77 ? 5'h2 : _T_629; // @[Lookup.scala 33:37]
  wire [4:0] _T_631 = _T_75 ? 5'h1 : _T_630; // @[Lookup.scala 33:37]
  wire [4:0] _T_632 = _T_73 ? 5'h0 : _T_631; // @[Lookup.scala 33:37]
  wire [4:0] _T_633 = _T_71 ? 5'hc : _T_632; // @[Lookup.scala 33:37]
  wire [4:0] _T_634 = _T_69 ? 5'h3 : _T_633; // @[Lookup.scala 33:37]
  wire [4:0] _T_635 = _T_67 ? 5'h2 : _T_634; // @[Lookup.scala 33:37]
  wire [4:0] _T_636 = _T_65 ? 5'h0 : _T_635; // @[Lookup.scala 33:37]
  wire [4:0] _T_637 = _T_63 ? 5'h3 : _T_636; // @[Lookup.scala 33:37]
  wire [4:0] _T_638 = _T_61 ? 5'h4 : _T_637; // @[Lookup.scala 33:37]
  wire [4:0] _T_639 = _T_59 ? 5'h7 : _T_638; // @[Lookup.scala 33:37]
  wire [4:0] _T_640 = _T_57 ? 5'h6 : _T_639; // @[Lookup.scala 33:37]
  wire [4:0] _T_641 = _T_55 ? 5'h5 : _T_640; // @[Lookup.scala 33:37]
  wire [4:0] _T_642 = _T_53 ? 5'h9 : _T_641; // @[Lookup.scala 33:37]
  wire [4:0] _T_643 = _T_51 ? 5'h8 : _T_642; // @[Lookup.scala 33:37]
  wire [4:0] _T_644 = _T_49 ? 5'h1 : _T_643; // @[Lookup.scala 33:37]
  wire [4:0] _T_645 = _T_47 ? 5'h0 : _T_644; // @[Lookup.scala 33:37]
  wire [4:0] _T_646 = _T_45 ? 5'h2 : _T_645; // @[Lookup.scala 33:37]
  wire [4:0] _T_647 = _T_43 ? 5'h3 : _T_646; // @[Lookup.scala 33:37]
  wire [4:0] _T_648 = _T_41 ? 5'h4 : _T_647; // @[Lookup.scala 33:37]
  wire [4:0] _T_649 = _T_39 ? 5'h2 : _T_648; // @[Lookup.scala 33:37]
  wire [4:0] _T_650 = _T_37 ? 5'h9 : _T_649; // @[Lookup.scala 33:37]
  wire [4:0] _T_651 = _T_35 ? 5'h8 : _T_650; // @[Lookup.scala 33:37]
  wire [4:0] _T_652 = _T_33 ? 5'h7 : _T_651; // @[Lookup.scala 33:37]
  wire [4:0] _T_653 = _T_31 ? 5'h6 : _T_652; // @[Lookup.scala 33:37]
  wire [4:0] _T_654 = _T_29 ? 5'h5 : _T_653; // @[Lookup.scala 33:37]
  wire [4:0] _T_655 = _T_27 ? 5'h0 : _T_654; // @[Lookup.scala 33:37]
  wire [4:0] _T_656 = _T_25 ? 5'hb : _T_655; // @[Lookup.scala 33:37]
  wire [4:0] _T_657 = _T_23 ? 5'h0 : _T_656; // @[Lookup.scala 33:37]
  wire [4:0] _T_658 = _T_21 ? 5'h0 : _T_657; // @[Lookup.scala 33:37]
  wire [4:0] _T_659 = _T_19 ? 5'h0 : _T_658; // @[Lookup.scala 33:37]
  wire [4:0] _T_660 = _T_17 ? 5'h0 : _T_659; // @[Lookup.scala 33:37]
  wire [4:0] _T_661 = _T_15 ? 5'h0 : _T_660; // @[Lookup.scala 33:37]
  wire [4:0] _T_662 = _T_13 ? 5'h0 : _T_661; // @[Lookup.scala 33:37]
  wire [4:0] _T_663 = _T_11 ? 5'h0 : _T_662; // @[Lookup.scala 33:37]
  wire [4:0] _T_664 = _T_9 ? 5'h0 : _T_663; // @[Lookup.scala 33:37]
  wire [4:0] _T_665 = _T_7 ? 5'h0 : _T_664; // @[Lookup.scala 33:37]
  wire [4:0] _T_666 = _T_5 ? 5'h0 : _T_665; // @[Lookup.scala 33:37]
  wire [4:0] _T_667 = _T_3 ? 5'h0 : _T_666; // @[Lookup.scala 33:37]
  wire [2:0] _T_675 = _T_135 ? 3'h3 : 3'h0; // @[Lookup.scala 33:37]
  wire [2:0] _T_676 = _T_133 ? 3'h3 : _T_675; // @[Lookup.scala 33:37]
  wire [2:0] _T_677 = _T_131 ? 3'h3 : _T_676; // @[Lookup.scala 33:37]
  wire [2:0] _T_678 = _T_129 ? 3'h3 : _T_677; // @[Lookup.scala 33:37]
  wire [2:0] _T_679 = _T_127 ? 3'h3 : _T_678; // @[Lookup.scala 33:37]
  wire [2:0] _T_680 = _T_125 ? 3'h3 : _T_679; // @[Lookup.scala 33:37]
  wire [2:0] _T_681 = _T_123 ? 3'h0 : _T_680; // @[Lookup.scala 33:37]
  wire [2:0] _T_682 = _T_121 ? 3'h0 : _T_681; // @[Lookup.scala 33:37]
  wire [2:0] _T_683 = _T_119 ? 3'h0 : _T_682; // @[Lookup.scala 33:37]
  wire [2:0] _T_684 = _T_117 ? 3'h0 : _T_683; // @[Lookup.scala 33:37]
  wire [2:0] _T_685 = _T_115 ? 3'h0 : _T_684; // @[Lookup.scala 33:37]
  wire [2:0] _T_686 = _T_113 ? 3'h0 : _T_685; // @[Lookup.scala 33:37]
  wire [2:0] _T_687 = _T_111 ? 3'h0 : _T_686; // @[Lookup.scala 33:37]
  wire [2:0] _T_688 = _T_109 ? 3'h0 : _T_687; // @[Lookup.scala 33:37]
  wire [2:0] _T_689 = _T_107 ? 3'h0 : _T_688; // @[Lookup.scala 33:37]
  wire [2:0] _T_690 = _T_105 ? 3'h0 : _T_689; // @[Lookup.scala 33:37]
  wire [2:0] _T_691 = _T_103 ? 3'h0 : _T_690; // @[Lookup.scala 33:37]
  wire [2:0] _T_692 = _T_101 ? 3'h4 : _T_691; // @[Lookup.scala 33:37]
  wire [2:0] _T_693 = _T_99 ? 3'h0 : _T_692; // @[Lookup.scala 33:37]
  wire [2:0] _T_694 = _T_97 ? 3'h0 : _T_693; // @[Lookup.scala 33:37]
  wire [2:0] _T_695 = _T_95 ? 3'h0 : _T_694; // @[Lookup.scala 33:37]
  wire [2:0] _T_696 = _T_93 ? 3'h0 : _T_695; // @[Lookup.scala 33:37]
  wire [2:0] _T_697 = _T_91 ? 3'h0 : _T_696; // @[Lookup.scala 33:37]
  wire [2:0] _T_698 = _T_89 ? 3'h0 : _T_697; // @[Lookup.scala 33:37]
  wire [2:0] _T_699 = _T_87 ? 3'h0 : _T_698; // @[Lookup.scala 33:37]
  wire [2:0] _T_700 = _T_85 ? 3'h2 : _T_699; // @[Lookup.scala 33:37]
  wire [2:0] _T_701 = _T_83 ? 3'h2 : _T_700; // @[Lookup.scala 33:37]
  wire [2:0] _T_702 = _T_81 ? 3'h4 : _T_701; // @[Lookup.scala 33:37]
  wire [2:0] _T_703 = _T_79 ? 3'h4 : _T_702; // @[Lookup.scala 33:37]
  wire [2:0] _T_704 = _T_77 ? 3'h4 : _T_703; // @[Lookup.scala 33:37]
  wire [2:0] _T_705 = _T_75 ? 3'h4 : _T_704; // @[Lookup.scala 33:37]
  wire [2:0] _T_706 = _T_73 ? 3'h4 : _T_705; // @[Lookup.scala 33:37]
  wire [2:0] _T_707 = _T_71 ? 3'h4 : _T_706; // @[Lookup.scala 33:37]
  wire [2:0] _T_708 = _T_69 ? 3'h4 : _T_707; // @[Lookup.scala 33:37]
  wire [2:0] _T_709 = _T_67 ? 3'h4 : _T_708; // @[Lookup.scala 33:37]
  wire [2:0] _T_710 = _T_65 ? 3'h4 : _T_709; // @[Lookup.scala 33:37]
  wire [2:0] _T_711 = _T_63 ? 3'h0 : _T_710; // @[Lookup.scala 33:37]
  wire [2:0] _T_712 = _T_61 ? 3'h0 : _T_711; // @[Lookup.scala 33:37]
  wire [2:0] _T_713 = _T_59 ? 3'h0 : _T_712; // @[Lookup.scala 33:37]
  wire [2:0] _T_714 = _T_57 ? 3'h0 : _T_713; // @[Lookup.scala 33:37]
  wire [2:0] _T_715 = _T_55 ? 3'h0 : _T_714; // @[Lookup.scala 33:37]
  wire [2:0] _T_716 = _T_53 ? 3'h0 : _T_715; // @[Lookup.scala 33:37]
  wire [2:0] _T_717 = _T_51 ? 3'h0 : _T_716; // @[Lookup.scala 33:37]
  wire [2:0] _T_718 = _T_49 ? 3'h0 : _T_717; // @[Lookup.scala 33:37]
  wire [2:0] _T_719 = _T_47 ? 3'h0 : _T_718; // @[Lookup.scala 33:37]
  wire [2:0] _T_720 = _T_45 ? 3'h0 : _T_719; // @[Lookup.scala 33:37]
  wire [2:0] _T_721 = _T_43 ? 3'h0 : _T_720; // @[Lookup.scala 33:37]
  wire [2:0] _T_722 = _T_41 ? 3'h0 : _T_721; // @[Lookup.scala 33:37]
  wire [2:0] _T_723 = _T_39 ? 3'h0 : _T_722; // @[Lookup.scala 33:37]
  wire [2:0] _T_724 = _T_37 ? 3'h0 : _T_723; // @[Lookup.scala 33:37]
  wire [2:0] _T_725 = _T_35 ? 3'h0 : _T_724; // @[Lookup.scala 33:37]
  wire [2:0] _T_726 = _T_33 ? 3'h0 : _T_725; // @[Lookup.scala 33:37]
  wire [2:0] _T_727 = _T_31 ? 3'h0 : _T_726; // @[Lookup.scala 33:37]
  wire [2:0] _T_728 = _T_29 ? 3'h0 : _T_727; // @[Lookup.scala 33:37]
  wire [2:0] _T_729 = _T_27 ? 3'h0 : _T_728; // @[Lookup.scala 33:37]
  wire [2:0] _T_730 = _T_25 ? 3'h0 : _T_729; // @[Lookup.scala 33:37]
  wire [2:0] _T_731 = _T_23 ? 3'h0 : _T_730; // @[Lookup.scala 33:37]
  wire [2:0] _T_732 = _T_21 ? 3'h0 : _T_731; // @[Lookup.scala 33:37]
  wire [2:0] _T_733 = _T_19 ? 3'h0 : _T_732; // @[Lookup.scala 33:37]
  wire [2:0] _T_734 = _T_17 ? 3'h0 : _T_733; // @[Lookup.scala 33:37]
  wire [2:0] _T_735 = _T_15 ? 3'h0 : _T_734; // @[Lookup.scala 33:37]
  wire [2:0] _T_736 = _T_13 ? 3'h1 : _T_735; // @[Lookup.scala 33:37]
  wire [2:0] _T_737 = _T_11 ? 3'h1 : _T_736; // @[Lookup.scala 33:37]
  wire [2:0] _T_738 = _T_9 ? 3'h1 : _T_737; // @[Lookup.scala 33:37]
  wire [2:0] _T_739 = _T_7 ? 3'h1 : _T_738; // @[Lookup.scala 33:37]
  wire [2:0] _T_740 = _T_5 ? 3'h1 : _T_739; // @[Lookup.scala 33:37]
  wire [2:0] _T_741 = _T_3 ? 3'h1 : _T_740; // @[Lookup.scala 33:37]
  wire  _T_768 = _T_97 ? 1'h0 : _T_471; // @[Lookup.scala 33:37]
  wire  _T_769 = _T_95 ? 1'h0 : _T_768; // @[Lookup.scala 33:37]
  wire  _T_770 = _T_93 ? 1'h0 : _T_769; // @[Lookup.scala 33:37]
  wire  _T_771 = _T_91 ? 1'h0 : _T_770; // @[Lookup.scala 33:37]
  wire  _T_772 = _T_89 ? 1'h0 : _T_771; // @[Lookup.scala 33:37]
  wire  _T_773 = _T_87 ? 1'h0 : _T_772; // @[Lookup.scala 33:37]
  wire  _T_774 = _T_85 | _T_773; // @[Lookup.scala 33:37]
  wire  _T_775 = _T_83 | _T_774; // @[Lookup.scala 33:37]
  wire  _T_776 = _T_81 | _T_775; // @[Lookup.scala 33:37]
  wire  _T_777 = _T_79 | _T_776; // @[Lookup.scala 33:37]
  wire  _T_778 = _T_77 | _T_777; // @[Lookup.scala 33:37]
  wire  _T_779 = _T_75 | _T_778; // @[Lookup.scala 33:37]
  wire  _T_780 = _T_73 | _T_779; // @[Lookup.scala 33:37]
  wire  _T_781 = _T_71 | _T_780; // @[Lookup.scala 33:37]
  wire  _T_782 = _T_69 | _T_781; // @[Lookup.scala 33:37]
  wire  _T_783 = _T_67 | _T_782; // @[Lookup.scala 33:37]
  wire  _T_784 = _T_65 | _T_783; // @[Lookup.scala 33:37]
  wire  _T_785 = _T_63 | _T_784; // @[Lookup.scala 33:37]
  wire  _T_786 = _T_61 | _T_785; // @[Lookup.scala 33:37]
  wire  _T_787 = _T_59 | _T_786; // @[Lookup.scala 33:37]
  wire  _T_788 = _T_57 | _T_787; // @[Lookup.scala 33:37]
  wire  _T_789 = _T_55 | _T_788; // @[Lookup.scala 33:37]
  wire  _T_790 = _T_53 | _T_789; // @[Lookup.scala 33:37]
  wire  _T_791 = _T_51 | _T_790; // @[Lookup.scala 33:37]
  wire  _T_792 = _T_49 | _T_791; // @[Lookup.scala 33:37]
  wire  _T_793 = _T_47 | _T_792; // @[Lookup.scala 33:37]
  wire  _T_794 = _T_45 | _T_793; // @[Lookup.scala 33:37]
  wire  _T_795 = _T_43 | _T_794; // @[Lookup.scala 33:37]
  wire  _T_796 = _T_41 | _T_795; // @[Lookup.scala 33:37]
  wire  _T_797 = _T_39 | _T_796; // @[Lookup.scala 33:37]
  wire  _T_798 = _T_37 | _T_797; // @[Lookup.scala 33:37]
  wire  _T_799 = _T_35 | _T_798; // @[Lookup.scala 33:37]
  wire  _T_800 = _T_33 | _T_799; // @[Lookup.scala 33:37]
  wire  _T_801 = _T_31 | _T_800; // @[Lookup.scala 33:37]
  wire  _T_802 = _T_29 | _T_801; // @[Lookup.scala 33:37]
  wire  _T_803 = _T_27 | _T_802; // @[Lookup.scala 33:37]
  wire  _T_804 = _T_25 | _T_803; // @[Lookup.scala 33:37]
  wire  _T_805 = _T_23 | _T_804; // @[Lookup.scala 33:37]
  wire  _T_806 = _T_21 ? 1'h0 : _T_805; // @[Lookup.scala 33:37]
  wire  _T_807 = _T_19 ? 1'h0 : _T_806; // @[Lookup.scala 33:37]
  wire  _T_808 = _T_17 ? 1'h0 : _T_807; // @[Lookup.scala 33:37]
  wire  _T_809 = _T_15 ? 1'h0 : _T_808; // @[Lookup.scala 33:37]
  wire  _T_810 = _T_13 | _T_809; // @[Lookup.scala 33:37]
  wire  _T_811 = _T_11 | _T_810; // @[Lookup.scala 33:37]
  wire  _T_812 = _T_9 | _T_811; // @[Lookup.scala 33:37]
  wire  _T_813 = _T_7 | _T_812; // @[Lookup.scala 33:37]
  wire  _T_814 = _T_5 | _T_813; // @[Lookup.scala 33:37]
  wire  _T_815 = _T_3 | _T_814; // @[Lookup.scala 33:37]
  wire  _T_817 = _T_147 ? 1'h0 : _T_149; // @[Lookup.scala 33:37]
  wire  _T_818 = _T_145 ? 1'h0 : _T_817; // @[Lookup.scala 33:37]
  wire  _T_819 = _T_143 ? 1'h0 : _T_818; // @[Lookup.scala 33:37]
  wire  _T_820 = _T_141 ? 1'h0 : _T_819; // @[Lookup.scala 33:37]
  wire  _T_821 = _T_139 ? 1'h0 : _T_820; // @[Lookup.scala 33:37]
  wire  _T_822 = _T_137 ? 1'h0 : _T_821; // @[Lookup.scala 33:37]
  wire  _T_823 = _T_135 ? 1'h0 : _T_822; // @[Lookup.scala 33:37]
  wire  _T_824 = _T_133 ? 1'h0 : _T_823; // @[Lookup.scala 33:37]
  wire  _T_825 = _T_131 ? 1'h0 : _T_824; // @[Lookup.scala 33:37]
  wire  _T_826 = _T_129 ? 1'h0 : _T_825; // @[Lookup.scala 33:37]
  wire  _T_827 = _T_127 ? 1'h0 : _T_826; // @[Lookup.scala 33:37]
  wire  _T_828 = _T_125 ? 1'h0 : _T_827; // @[Lookup.scala 33:37]
  wire  _T_829 = _T_123 ? 1'h0 : _T_828; // @[Lookup.scala 33:37]
  wire  _T_830 = _T_121 ? 1'h0 : _T_829; // @[Lookup.scala 33:37]
  wire  _T_831 = _T_119 ? 1'h0 : _T_830; // @[Lookup.scala 33:37]
  wire  _T_832 = _T_117 ? 1'h0 : _T_831; // @[Lookup.scala 33:37]
  wire  _T_833 = _T_115 ? 1'h0 : _T_832; // @[Lookup.scala 33:37]
  wire  _T_834 = _T_113 ? 1'h0 : _T_833; // @[Lookup.scala 33:37]
  wire  _T_835 = _T_111 ? 1'h0 : _T_834; // @[Lookup.scala 33:37]
  wire  _T_836 = _T_109 ? 1'h0 : _T_835; // @[Lookup.scala 33:37]
  wire  _T_837 = _T_107 ? 1'h0 : _T_836; // @[Lookup.scala 33:37]
  wire  _T_838 = _T_105 ? 1'h0 : _T_837; // @[Lookup.scala 33:37]
  wire  _T_839 = _T_103 ? 1'h0 : _T_838; // @[Lookup.scala 33:37]
  wire  _T_840 = _T_101 ? 1'h0 : _T_839; // @[Lookup.scala 33:37]
  wire  _T_841 = _T_99 ? 1'h0 : _T_840; // @[Lookup.scala 33:37]
  wire  _T_842 = _T_97 ? 1'h0 : _T_841; // @[Lookup.scala 33:37]
  wire  _T_843 = _T_95 ? 1'h0 : _T_842; // @[Lookup.scala 33:37]
  wire  _T_844 = _T_93 ? 1'h0 : _T_843; // @[Lookup.scala 33:37]
  wire  _T_845 = _T_91 ? 1'h0 : _T_844; // @[Lookup.scala 33:37]
  wire  _T_846 = _T_89 ? 1'h0 : _T_845; // @[Lookup.scala 33:37]
  wire  _T_847 = _T_87 ? 1'h0 : _T_846; // @[Lookup.scala 33:37]
  wire  _T_848 = _T_85 ? 1'h0 : _T_847; // @[Lookup.scala 33:37]
  wire  _T_849 = _T_83 ? 1'h0 : _T_848; // @[Lookup.scala 33:37]
  wire  _T_850 = _T_81 ? 1'h0 : _T_849; // @[Lookup.scala 33:37]
  wire  _T_851 = _T_79 ? 1'h0 : _T_850; // @[Lookup.scala 33:37]
  wire  _T_852 = _T_77 ? 1'h0 : _T_851; // @[Lookup.scala 33:37]
  wire  _T_853 = _T_75 ? 1'h0 : _T_852; // @[Lookup.scala 33:37]
  wire  _T_854 = _T_73 ? 1'h0 : _T_853; // @[Lookup.scala 33:37]
  wire  _T_855 = _T_71 ? 1'h0 : _T_854; // @[Lookup.scala 33:37]
  wire  _T_856 = _T_69 ? 1'h0 : _T_855; // @[Lookup.scala 33:37]
  wire  _T_857 = _T_67 ? 1'h0 : _T_856; // @[Lookup.scala 33:37]
  wire  _T_858 = _T_65 ? 1'h0 : _T_857; // @[Lookup.scala 33:37]
  wire  _T_859 = _T_63 ? 1'h0 : _T_858; // @[Lookup.scala 33:37]
  wire  _T_860 = _T_61 ? 1'h0 : _T_859; // @[Lookup.scala 33:37]
  wire  _T_861 = _T_59 ? 1'h0 : _T_860; // @[Lookup.scala 33:37]
  wire  _T_862 = _T_57 ? 1'h0 : _T_861; // @[Lookup.scala 33:37]
  wire  _T_863 = _T_55 ? 1'h0 : _T_862; // @[Lookup.scala 33:37]
  wire  _T_864 = _T_53 ? 1'h0 : _T_863; // @[Lookup.scala 33:37]
  wire  _T_865 = _T_51 ? 1'h0 : _T_864; // @[Lookup.scala 33:37]
  wire  _T_866 = _T_49 ? 1'h0 : _T_865; // @[Lookup.scala 33:37]
  wire  _T_867 = _T_47 ? 1'h0 : _T_866; // @[Lookup.scala 33:37]
  wire  _T_868 = _T_45 ? 1'h0 : _T_867; // @[Lookup.scala 33:37]
  wire  _T_869 = _T_43 ? 1'h0 : _T_868; // @[Lookup.scala 33:37]
  wire  _T_870 = _T_41 ? 1'h0 : _T_869; // @[Lookup.scala 33:37]
  wire  _T_871 = _T_39 ? 1'h0 : _T_870; // @[Lookup.scala 33:37]
  wire  _T_872 = _T_37 ? 1'h0 : _T_871; // @[Lookup.scala 33:37]
  wire  _T_873 = _T_35 ? 1'h0 : _T_872; // @[Lookup.scala 33:37]
  wire  _T_874 = _T_33 ? 1'h0 : _T_873; // @[Lookup.scala 33:37]
  wire  _T_875 = _T_31 ? 1'h0 : _T_874; // @[Lookup.scala 33:37]
  wire  _T_876 = _T_29 ? 1'h0 : _T_875; // @[Lookup.scala 33:37]
  wire  _T_877 = _T_27 ? 1'h0 : _T_876; // @[Lookup.scala 33:37]
  wire  _T_878 = _T_25 ? 1'h0 : _T_877; // @[Lookup.scala 33:37]
  wire  _T_879 = _T_23 ? 1'h0 : _T_878; // @[Lookup.scala 33:37]
  wire  _T_880 = _T_21 | _T_879; // @[Lookup.scala 33:37]
  wire  _T_881 = _T_19 | _T_880; // @[Lookup.scala 33:37]
  wire  _T_882 = _T_17 | _T_881; // @[Lookup.scala 33:37]
  wire  _T_883 = _T_15 | _T_882; // @[Lookup.scala 33:37]
  wire  _T_884 = _T_13 | _T_883; // @[Lookup.scala 33:37]
  wire  _T_885 = _T_11 | _T_884; // @[Lookup.scala 33:37]
  wire  _T_886 = _T_9 | _T_885; // @[Lookup.scala 33:37]
  wire  _T_887 = _T_7 | _T_886; // @[Lookup.scala 33:37]
  wire  _T_888 = _T_5 | _T_887; // @[Lookup.scala 33:37]
  wire  _T_889 = _T_3 | _T_888; // @[Lookup.scala 33:37]
  wire  cs0_3 = _T_1 | _T_889; // @[Lookup.scala 33:37]
  wire [1:0] _T_954 = _T_21 ? 2'h2 : 2'h0; // @[Lookup.scala 33:37]
  wire [1:0] _T_955 = _T_19 ? 2'h2 : _T_954; // @[Lookup.scala 33:37]
  wire [1:0] _T_956 = _T_17 ? 2'h2 : _T_955; // @[Lookup.scala 33:37]
  wire [1:0] _T_957 = _T_15 ? 2'h2 : _T_956; // @[Lookup.scala 33:37]
  wire [1:0] _T_958 = _T_13 ? 2'h1 : _T_957; // @[Lookup.scala 33:37]
  wire [1:0] _T_959 = _T_11 ? 2'h1 : _T_958; // @[Lookup.scala 33:37]
  wire [1:0] _T_960 = _T_9 ? 2'h1 : _T_959; // @[Lookup.scala 33:37]
  wire [1:0] _T_961 = _T_7 ? 2'h1 : _T_960; // @[Lookup.scala 33:37]
  wire [1:0] _T_962 = _T_5 ? 2'h1 : _T_961; // @[Lookup.scala 33:37]
  wire [1:0] _T_963 = _T_3 ? 2'h1 : _T_962; // @[Lookup.scala 33:37]
  wire [1:0] cs0_4 = _T_1 ? 2'h1 : _T_963; // @[Lookup.scala 33:37]
  wire [7:0] _T_1028 = _T_21 ? 8'h3 : 8'hff; // @[Lookup.scala 33:37]
  wire [7:0] _T_1029 = _T_19 ? 8'h1 : _T_1028; // @[Lookup.scala 33:37]
  wire [7:0] _T_1030 = _T_17 ? 8'hf : _T_1029; // @[Lookup.scala 33:37]
  wire [7:0] _T_1031 = _T_15 ? 8'hff : _T_1030; // @[Lookup.scala 33:37]
  wire [7:0] _T_1032 = _T_13 ? 8'hff : _T_1031; // @[Lookup.scala 33:37]
  wire [7:0] _T_1033 = _T_11 ? 8'hff : _T_1032; // @[Lookup.scala 33:37]
  wire [7:0] _T_1034 = _T_9 ? 8'hff : _T_1033; // @[Lookup.scala 33:37]
  wire [7:0] _T_1035 = _T_7 ? 8'hff : _T_1034; // @[Lookup.scala 33:37]
  wire [7:0] _T_1036 = _T_5 ? 8'hff : _T_1035; // @[Lookup.scala 33:37]
  wire [7:0] _T_1037 = _T_3 ? 8'hff : _T_1036; // @[Lookup.scala 33:37]
  wire [2:0] _T_1106 = _T_13 ? 3'h3 : 3'h0; // @[Lookup.scala 33:37]
  wire [2:0] _T_1107 = _T_11 ? 3'h2 : _T_1106; // @[Lookup.scala 33:37]
  wire [2:0] _T_1108 = _T_9 ? 3'h1 : _T_1107; // @[Lookup.scala 33:37]
  wire [2:0] _T_1109 = _T_7 ? 3'h0 : _T_1108; // @[Lookup.scala 33:37]
  wire [2:0] _T_1110 = _T_5 ? 3'h5 : _T_1109; // @[Lookup.scala 33:37]
  wire [2:0] _T_1111 = _T_3 ? 3'h4 : _T_1110; // @[Lookup.scala 33:37]
  wire [2:0] _T_1115 = _T_143 ? 3'h5 : 3'h0; // @[Lookup.scala 33:37]
  wire [2:0] _T_1116 = _T_141 ? 3'h5 : _T_1115; // @[Lookup.scala 33:37]
  wire [2:0] _T_1117 = _T_139 ? 3'h5 : _T_1116; // @[Lookup.scala 33:37]
  wire [2:0] _T_1118 = _T_137 ? 3'h5 : _T_1117; // @[Lookup.scala 33:37]
  wire [2:0] _T_1119 = _T_135 ? 3'h3 : _T_1118; // @[Lookup.scala 33:37]
  wire [2:0] _T_1120 = _T_133 ? 3'h3 : _T_1119; // @[Lookup.scala 33:37]
  wire [2:0] _T_1121 = _T_131 ? 3'h4 : _T_1120; // @[Lookup.scala 33:37]
  wire [2:0] _T_1122 = _T_129 ? 3'h2 : _T_1121; // @[Lookup.scala 33:37]
  wire [2:0] _T_1123 = _T_127 ? 3'h4 : _T_1122; // @[Lookup.scala 33:37]
  wire [2:0] _T_1124 = _T_125 ? 3'h2 : _T_1123; // @[Lookup.scala 33:37]
  wire [2:0] _T_1125 = _T_123 ? 3'h0 : _T_1124; // @[Lookup.scala 33:37]
  wire [2:0] _T_1126 = _T_121 ? 3'h0 : _T_1125; // @[Lookup.scala 33:37]
  wire [2:0] _T_1127 = _T_119 ? 3'h0 : _T_1126; // @[Lookup.scala 33:37]
  wire [2:0] _T_1128 = _T_117 ? 3'h0 : _T_1127; // @[Lookup.scala 33:37]
  wire [2:0] _T_1129 = _T_115 ? 3'h0 : _T_1128; // @[Lookup.scala 33:37]
  wire [2:0] _T_1130 = _T_113 ? 3'h0 : _T_1129; // @[Lookup.scala 33:37]
  wire [2:0] _T_1131 = _T_111 ? 3'h0 : _T_1130; // @[Lookup.scala 33:37]
  wire [2:0] _T_1132 = _T_109 ? 3'h0 : _T_1131; // @[Lookup.scala 33:37]
  wire [2:0] _T_1133 = _T_107 ? 3'h0 : _T_1132; // @[Lookup.scala 33:37]
  wire [2:0] _T_1134 = _T_105 ? 3'h0 : _T_1133; // @[Lookup.scala 33:37]
  wire [2:0] _T_1135 = _T_103 ? 3'h0 : _T_1134; // @[Lookup.scala 33:37]
  wire [2:0] _T_1136 = _T_101 ? 3'h0 : _T_1135; // @[Lookup.scala 33:37]
  wire [2:0] _T_1137 = _T_99 ? 3'h0 : _T_1136; // @[Lookup.scala 33:37]
  wire [2:0] _T_1138 = _T_97 ? 3'h0 : _T_1137; // @[Lookup.scala 33:37]
  wire [2:0] _T_1139 = _T_95 ? 3'h0 : _T_1138; // @[Lookup.scala 33:37]
  wire [2:0] _T_1140 = _T_93 ? 3'h0 : _T_1139; // @[Lookup.scala 33:37]
  wire [2:0] _T_1141 = _T_91 ? 3'h0 : _T_1140; // @[Lookup.scala 33:37]
  wire [2:0] _T_1142 = _T_89 ? 3'h0 : _T_1141; // @[Lookup.scala 33:37]
  wire [2:0] _T_1143 = _T_87 ? 3'h0 : _T_1142; // @[Lookup.scala 33:37]
  wire [2:0] _T_1144 = _T_85 ? 3'h0 : _T_1143; // @[Lookup.scala 33:37]
  wire [2:0] _T_1145 = _T_83 ? 3'h0 : _T_1144; // @[Lookup.scala 33:37]
  wire [2:0] _T_1146 = _T_81 ? 3'h0 : _T_1145; // @[Lookup.scala 33:37]
  wire [2:0] _T_1147 = _T_79 ? 3'h0 : _T_1146; // @[Lookup.scala 33:37]
  wire [2:0] _T_1148 = _T_77 ? 3'h0 : _T_1147; // @[Lookup.scala 33:37]
  wire [2:0] _T_1149 = _T_75 ? 3'h0 : _T_1148; // @[Lookup.scala 33:37]
  wire [2:0] _T_1150 = _T_73 ? 3'h0 : _T_1149; // @[Lookup.scala 33:37]
  wire [2:0] _T_1151 = _T_71 ? 3'h0 : _T_1150; // @[Lookup.scala 33:37]
  wire [2:0] _T_1152 = _T_69 ? 3'h0 : _T_1151; // @[Lookup.scala 33:37]
  wire [2:0] _T_1153 = _T_67 ? 3'h0 : _T_1152; // @[Lookup.scala 33:37]
  wire [2:0] _T_1154 = _T_65 ? 3'h0 : _T_1153; // @[Lookup.scala 33:37]
  wire [2:0] _T_1155 = _T_63 ? 3'h0 : _T_1154; // @[Lookup.scala 33:37]
  wire [2:0] _T_1156 = _T_61 ? 3'h0 : _T_1155; // @[Lookup.scala 33:37]
  wire [2:0] _T_1157 = _T_59 ? 3'h0 : _T_1156; // @[Lookup.scala 33:37]
  wire [2:0] _T_1158 = _T_57 ? 3'h0 : _T_1157; // @[Lookup.scala 33:37]
  wire [2:0] _T_1159 = _T_55 ? 3'h0 : _T_1158; // @[Lookup.scala 33:37]
  wire [2:0] _T_1160 = _T_53 ? 3'h0 : _T_1159; // @[Lookup.scala 33:37]
  wire [2:0] _T_1161 = _T_51 ? 3'h0 : _T_1160; // @[Lookup.scala 33:37]
  wire [2:0] _T_1162 = _T_49 ? 3'h0 : _T_1161; // @[Lookup.scala 33:37]
  wire [2:0] _T_1163 = _T_47 ? 3'h0 : _T_1162; // @[Lookup.scala 33:37]
  wire [2:0] _T_1164 = _T_45 ? 3'h0 : _T_1163; // @[Lookup.scala 33:37]
  wire [2:0] _T_1165 = _T_43 ? 3'h0 : _T_1164; // @[Lookup.scala 33:37]
  wire [2:0] _T_1166 = _T_41 ? 3'h0 : _T_1165; // @[Lookup.scala 33:37]
  wire [2:0] _T_1167 = _T_39 ? 3'h0 : _T_1166; // @[Lookup.scala 33:37]
  wire [2:0] _T_1168 = _T_37 ? 3'h0 : _T_1167; // @[Lookup.scala 33:37]
  wire [2:0] _T_1169 = _T_35 ? 3'h0 : _T_1168; // @[Lookup.scala 33:37]
  wire [2:0] _T_1170 = _T_33 ? 3'h0 : _T_1169; // @[Lookup.scala 33:37]
  wire [2:0] _T_1171 = _T_31 ? 3'h0 : _T_1170; // @[Lookup.scala 33:37]
  wire [2:0] _T_1172 = _T_29 ? 3'h0 : _T_1171; // @[Lookup.scala 33:37]
  wire [2:0] _T_1173 = _T_27 ? 3'h0 : _T_1172; // @[Lookup.scala 33:37]
  wire [2:0] _T_1174 = _T_25 ? 3'h0 : _T_1173; // @[Lookup.scala 33:37]
  wire [2:0] _T_1175 = _T_23 ? 3'h0 : _T_1174; // @[Lookup.scala 33:37]
  wire [2:0] _T_1176 = _T_21 ? 3'h0 : _T_1175; // @[Lookup.scala 33:37]
  wire [2:0] _T_1177 = _T_19 ? 3'h0 : _T_1176; // @[Lookup.scala 33:37]
  wire [2:0] _T_1178 = _T_17 ? 3'h0 : _T_1177; // @[Lookup.scala 33:37]
  wire [2:0] _T_1179 = _T_15 ? 3'h0 : _T_1178; // @[Lookup.scala 33:37]
  wire [2:0] _T_1180 = _T_13 ? 3'h0 : _T_1179; // @[Lookup.scala 33:37]
  wire [2:0] _T_1181 = _T_11 ? 3'h0 : _T_1180; // @[Lookup.scala 33:37]
  wire [2:0] _T_1182 = _T_9 ? 3'h0 : _T_1181; // @[Lookup.scala 33:37]
  wire [2:0] _T_1183 = _T_7 ? 3'h0 : _T_1182; // @[Lookup.scala 33:37]
  wire [2:0] _T_1184 = _T_5 ? 3'h0 : _T_1183; // @[Lookup.scala 33:37]
  wire [2:0] _T_1185 = _T_3 ? 3'h0 : _T_1184; // @[Lookup.scala 33:37]
  wire [2:0] cs0_7 = _T_1 ? 3'h0 : _T_1185; // @[Lookup.scala 33:37]
  wire  _T_1188 = _T_145 ? 1'h0 : _T_147; // @[Lookup.scala 33:37]
  wire  _T_1189 = _T_143 ? 1'h0 : _T_1188; // @[Lookup.scala 33:37]
  wire  _T_1190 = _T_141 ? 1'h0 : _T_1189; // @[Lookup.scala 33:37]
  wire  _T_1191 = _T_139 ? 1'h0 : _T_1190; // @[Lookup.scala 33:37]
  wire  _T_1192 = _T_137 ? 1'h0 : _T_1191; // @[Lookup.scala 33:37]
  wire  _T_1193 = _T_135 ? 1'h0 : _T_1192; // @[Lookup.scala 33:37]
  wire  _T_1194 = _T_133 ? 1'h0 : _T_1193; // @[Lookup.scala 33:37]
  wire  _T_1195 = _T_131 ? 1'h0 : _T_1194; // @[Lookup.scala 33:37]
  wire  _T_1196 = _T_129 ? 1'h0 : _T_1195; // @[Lookup.scala 33:37]
  wire  _T_1197 = _T_127 ? 1'h0 : _T_1196; // @[Lookup.scala 33:37]
  wire  _T_1198 = _T_125 ? 1'h0 : _T_1197; // @[Lookup.scala 33:37]
  wire  _T_1199 = _T_123 ? 1'h0 : _T_1198; // @[Lookup.scala 33:37]
  wire  _T_1200 = _T_121 ? 1'h0 : _T_1199; // @[Lookup.scala 33:37]
  wire  _T_1201 = _T_119 ? 1'h0 : _T_1200; // @[Lookup.scala 33:37]
  wire  _T_1202 = _T_117 ? 1'h0 : _T_1201; // @[Lookup.scala 33:37]
  wire  _T_1203 = _T_115 ? 1'h0 : _T_1202; // @[Lookup.scala 33:37]
  wire  _T_1204 = _T_113 ? 1'h0 : _T_1203; // @[Lookup.scala 33:37]
  wire  _T_1205 = _T_111 ? 1'h0 : _T_1204; // @[Lookup.scala 33:37]
  wire  _T_1206 = _T_109 ? 1'h0 : _T_1205; // @[Lookup.scala 33:37]
  wire  _T_1207 = _T_107 ? 1'h0 : _T_1206; // @[Lookup.scala 33:37]
  wire  _T_1208 = _T_105 ? 1'h0 : _T_1207; // @[Lookup.scala 33:37]
  wire  _T_1209 = _T_103 ? 1'h0 : _T_1208; // @[Lookup.scala 33:37]
  wire  _T_1210 = _T_101 ? 1'h0 : _T_1209; // @[Lookup.scala 33:37]
  wire  _T_1211 = _T_99 ? 1'h0 : _T_1210; // @[Lookup.scala 33:37]
  wire  _T_1212 = _T_97 ? 1'h0 : _T_1211; // @[Lookup.scala 33:37]
  wire  _T_1213 = _T_95 ? 1'h0 : _T_1212; // @[Lookup.scala 33:37]
  wire  _T_1214 = _T_93 ? 1'h0 : _T_1213; // @[Lookup.scala 33:37]
  wire  _T_1215 = _T_91 ? 1'h0 : _T_1214; // @[Lookup.scala 33:37]
  wire  _T_1216 = _T_89 ? 1'h0 : _T_1215; // @[Lookup.scala 33:37]
  wire  _T_1217 = _T_87 ? 1'h0 : _T_1216; // @[Lookup.scala 33:37]
  wire  _T_1218 = _T_85 ? 1'h0 : _T_1217; // @[Lookup.scala 33:37]
  wire  _T_1219 = _T_83 ? 1'h0 : _T_1218; // @[Lookup.scala 33:37]
  wire  _T_1220 = _T_81 ? 1'h0 : _T_1219; // @[Lookup.scala 33:37]
  wire  _T_1221 = _T_79 ? 1'h0 : _T_1220; // @[Lookup.scala 33:37]
  wire  _T_1222 = _T_77 ? 1'h0 : _T_1221; // @[Lookup.scala 33:37]
  wire  _T_1223 = _T_75 ? 1'h0 : _T_1222; // @[Lookup.scala 33:37]
  wire  _T_1224 = _T_73 ? 1'h0 : _T_1223; // @[Lookup.scala 33:37]
  wire  _T_1225 = _T_71 ? 1'h0 : _T_1224; // @[Lookup.scala 33:37]
  wire  _T_1226 = _T_69 ? 1'h0 : _T_1225; // @[Lookup.scala 33:37]
  wire  _T_1227 = _T_67 ? 1'h0 : _T_1226; // @[Lookup.scala 33:37]
  wire  _T_1228 = _T_65 ? 1'h0 : _T_1227; // @[Lookup.scala 33:37]
  wire  _T_1229 = _T_63 ? 1'h0 : _T_1228; // @[Lookup.scala 33:37]
  wire  _T_1230 = _T_61 ? 1'h0 : _T_1229; // @[Lookup.scala 33:37]
  wire  _T_1231 = _T_59 ? 1'h0 : _T_1230; // @[Lookup.scala 33:37]
  wire  _T_1232 = _T_57 ? 1'h0 : _T_1231; // @[Lookup.scala 33:37]
  wire  _T_1233 = _T_55 ? 1'h0 : _T_1232; // @[Lookup.scala 33:37]
  wire  _T_1234 = _T_53 ? 1'h0 : _T_1233; // @[Lookup.scala 33:37]
  wire  _T_1235 = _T_51 ? 1'h0 : _T_1234; // @[Lookup.scala 33:37]
  wire  _T_1236 = _T_49 ? 1'h0 : _T_1235; // @[Lookup.scala 33:37]
  wire  _T_1237 = _T_47 ? 1'h0 : _T_1236; // @[Lookup.scala 33:37]
  wire  _T_1238 = _T_45 ? 1'h0 : _T_1237; // @[Lookup.scala 33:37]
  wire  _T_1239 = _T_43 ? 1'h0 : _T_1238; // @[Lookup.scala 33:37]
  wire  _T_1240 = _T_41 ? 1'h0 : _T_1239; // @[Lookup.scala 33:37]
  wire  _T_1241 = _T_39 ? 1'h0 : _T_1240; // @[Lookup.scala 33:37]
  wire  _T_1242 = _T_37 ? 1'h0 : _T_1241; // @[Lookup.scala 33:37]
  wire  _T_1243 = _T_35 ? 1'h0 : _T_1242; // @[Lookup.scala 33:37]
  wire  _T_1244 = _T_33 ? 1'h0 : _T_1243; // @[Lookup.scala 33:37]
  wire  _T_1245 = _T_31 ? 1'h0 : _T_1244; // @[Lookup.scala 33:37]
  wire  _T_1246 = _T_29 ? 1'h0 : _T_1245; // @[Lookup.scala 33:37]
  wire  _T_1247 = _T_27 ? 1'h0 : _T_1246; // @[Lookup.scala 33:37]
  wire  _T_1248 = _T_25 ? 1'h0 : _T_1247; // @[Lookup.scala 33:37]
  wire  _T_1249 = _T_23 ? 1'h0 : _T_1248; // @[Lookup.scala 33:37]
  wire  _T_1250 = _T_21 ? 1'h0 : _T_1249; // @[Lookup.scala 33:37]
  wire  _T_1251 = _T_19 ? 1'h0 : _T_1250; // @[Lookup.scala 33:37]
  wire  _T_1252 = _T_17 ? 1'h0 : _T_1251; // @[Lookup.scala 33:37]
  wire  _T_1253 = _T_15 ? 1'h0 : _T_1252; // @[Lookup.scala 33:37]
  wire  _T_1254 = _T_13 ? 1'h0 : _T_1253; // @[Lookup.scala 33:37]
  wire  _T_1255 = _T_11 ? 1'h0 : _T_1254; // @[Lookup.scala 33:37]
  wire  _T_1256 = _T_9 ? 1'h0 : _T_1255; // @[Lookup.scala 33:37]
  wire  _T_1257 = _T_7 ? 1'h0 : _T_1256; // @[Lookup.scala 33:37]
  wire  _T_1258 = _T_5 ? 1'h0 : _T_1257; // @[Lookup.scala 33:37]
  wire  _T_1259 = _T_3 ? 1'h0 : _T_1258; // @[Lookup.scala 33:37]
  wire  cs0_8 = _T_1 ? 1'h0 : _T_1259; // @[Lookup.scala 33:37]
  wire  _T_1260 = io_dat_exe_br_type == 4'h0; // @[cpath.scala 142:48]
  wire  _T_1261 = io_dat_exe_br_type == 4'h1; // @[cpath.scala 143:48]
  wire  _T_1262 = ~io_dat_exe_br_eq; // @[cpath.scala 143:64]
  wire [1:0] _T_1263 = _T_1262 ? 2'h1 : 2'h0; // @[cpath.scala 143:63]
  wire  _T_1264 = io_dat_exe_br_type == 4'h2; // @[cpath.scala 144:48]
  wire [1:0] _T_1265 = io_dat_exe_br_eq ? 2'h1 : 2'h0; // @[cpath.scala 144:63]
  wire  _T_1266 = io_dat_exe_br_type == 4'h3; // @[cpath.scala 145:48]
  wire  _T_1267 = ~io_dat_exe_br_lt; // @[cpath.scala 145:64]
  wire [1:0] _T_1268 = _T_1267 ? 2'h1 : 2'h0; // @[cpath.scala 145:63]
  wire  _T_1269 = io_dat_exe_br_type == 4'h4; // @[cpath.scala 146:48]
  wire  _T_1270 = ~io_dat_exe_br_ltu; // @[cpath.scala 146:64]
  wire [1:0] _T_1271 = _T_1270 ? 2'h1 : 2'h0; // @[cpath.scala 146:63]
  wire  _T_1272 = io_dat_exe_br_type == 4'h5; // @[cpath.scala 147:48]
  wire [1:0] _T_1273 = io_dat_exe_br_lt ? 2'h1 : 2'h0; // @[cpath.scala 147:63]
  wire  _T_1274 = io_dat_exe_br_type == 4'h6; // @[cpath.scala 148:48]
  wire [1:0] _T_1275 = io_dat_exe_br_ltu ? 2'h1 : 2'h0; // @[cpath.scala 148:63]
  wire  _T_1276 = io_dat_exe_br_type == 4'h7; // @[cpath.scala 149:48]
  wire  _T_1277 = io_dat_exe_br_type == 4'h8; // @[cpath.scala 150:48]
  wire [1:0] _T_1278 = _T_1277 ? 2'h2 : 2'h0; // @[cpath.scala 150:28]
  wire [1:0] _T_1279 = _T_1276 ? 2'h1 : _T_1278; // @[cpath.scala 149:28]
  wire [1:0] _T_1280 = _T_1274 ? _T_1275 : _T_1279; // @[cpath.scala 148:28]
  wire [1:0] _T_1281 = _T_1272 ? _T_1273 : _T_1280; // @[cpath.scala 147:28]
  wire [1:0] _T_1282 = _T_1269 ? _T_1271 : _T_1281; // @[cpath.scala 146:28]
  wire [1:0] _T_1283 = _T_1266 ? _T_1268 : _T_1282; // @[cpath.scala 145:28]
  wire [1:0] _T_1284 = _T_1264 ? _T_1265 : _T_1283; // @[cpath.scala 144:28]
  wire [1:0] _T_1285 = _T_1261 ? _T_1263 : _T_1284; // @[cpath.scala 143:28]
  wire [1:0] ctrl_exe_pc_sel = _T_1260 ? 2'h0 : _T_1285; // @[cpath.scala 142:28]
  wire  _T_1287 = ctrl_exe_pc_sel != 2'h0; // @[cpath.scala 154:34]
  wire  _T_1288 = _T_1287 | cs0_8; // @[cpath.scala 154:44]
  reg  _T_1289; // @[cpath.scala 154:67]
  wire [4:0] dec_rs1_addr = io_dat_dec_inst[19:15]; // @[cpath.scala 163:37]
  wire [4:0] dec_rs2_addr = io_dat_dec_inst[24:20]; // @[cpath.scala 164:37]
  wire [4:0] dec_wbaddr = io_dat_dec_inst[11:7]; // @[cpath.scala 165:37]
  wire  dec_rs1_oen = _T_1287 ? 1'h0 : cs_rs1_oen; // @[cpath.scala 166:25]
  wire  dec_rs2_oen = _T_1287 ? 1'h0 : cs_rs2_oen; // @[cpath.scala 167:25]
  reg [4:0] exe_reg_wbaddr; // @[cpath.scala 169:32]
  reg  exe_reg_is_csr; // @[cpath.scala 177:31]
  reg  exe_inst_is_load; // @[cpath.scala 212:33]
  wire  _T_1301 = exe_reg_wbaddr == dec_rs1_addr; // @[cpath.scala 223:51]
  wire  _T_1302 = exe_inst_is_load & _T_1301; // @[cpath.scala 223:32]
  wire  _T_1303 = exe_reg_wbaddr != 5'h0; // @[cpath.scala 223:88]
  wire  _T_1304 = _T_1302 & _T_1303; // @[cpath.scala 223:69]
  wire  _T_1305 = _T_1304 & dec_rs1_oen; // @[cpath.scala 223:97]
  wire  _T_1306 = exe_reg_wbaddr == dec_rs2_addr; // @[cpath.scala 224:51]
  wire  _T_1307 = exe_inst_is_load & _T_1306; // @[cpath.scala 224:32]
  wire  _T_1309 = _T_1307 & _T_1303; // @[cpath.scala 224:69]
  wire  _T_1310 = _T_1309 & dec_rs2_oen; // @[cpath.scala 224:97]
  wire  _T_1311 = _T_1305 | _T_1310; // @[cpath.scala 223:113]
  wire  stall = _T_1311 | exe_reg_is_csr; // @[cpath.scala 224:113]
  wire  _T_1290 = ~stall; // @[cpath.scala 181:9]
  wire  inst_stall = ~io_dat_inst_valid; // @[cpath.scala 229:21]
  wire  _T_1313 = io_dat_exe_ctrl_dmem_val & io_dat_data_valid; // @[cpath.scala 230:33]
  wire  _T_1314 = ~io_dat_exe_ctrl_dmem_val; // @[cpath.scala 230:58]
  wire  _T_1315 = _T_1313 | _T_1314; // @[cpath.scala 230:55]
  wire  data_stall = ~_T_1315; // @[cpath.scala 230:21]
  wire  full_stall = inst_stall | data_stall; // @[cpath.scala 232:28]
  wire  _T_1291 = ~full_stall; // @[cpath.scala 181:19]
  wire  _T_1292 = _T_1290 & _T_1291; // @[cpath.scala 181:16]
  wire  _T_1293 = cs0_7 != 3'h0; // @[cpath.scala 194:47]
  wire  _T_1294 = cs0_7 != 3'h5; // @[cpath.scala 194:73]
  wire  _T_1295 = _T_1293 & _T_1294; // @[cpath.scala 194:58]
  wire  _T_1297 = stall & _T_1291; // @[cpath.scala 198:20]
  wire  _T_1299 = cs0_4 == 2'h1; // @[cpath.scala 216:50]
  wire  _T_1300 = cs0_3 & _T_1299; // @[cpath.scala 216:35]
  assign io_ctl_dec_stall = _T_1311 | exe_reg_is_csr; // @[cpath.scala 235:21]
  assign io_ctl_full_stall = inst_stall | data_stall; // @[cpath.scala 236:21]
  assign io_ctl_exe_pc_sel = _T_1260 ? 2'h0 : _T_1285; // @[cpath.scala 237:21]
  assign io_ctl_br_type = _T_1 ? 4'h0 : _T_297; // @[cpath.scala 238:21]
  assign io_ctl_if_kill = _T_1288 | _T_1289; // @[cpath.scala 239:21]
  assign io_ctl_dec_kill = ctrl_exe_pc_sel != 2'h0; // @[cpath.scala 240:21]
  assign io_ctl_op1_sel = _T_1 ? 2'h0 : _T_371; // @[cpath.scala 241:21]
  assign io_ctl_op2_sel = _T_1 ? 3'h1 : _T_445; // @[cpath.scala 242:21]
  assign io_ctl_alu_fun = _T_1 ? 5'h0 : _T_667; // @[cpath.scala 243:21]
  assign io_ctl_wb_sel = _T_1 ? 3'h1 : _T_741; // @[cpath.scala 244:21]
  assign io_ctl_rf_wen = _T_1 | _T_815; // @[cpath.scala 245:21]
  assign io_ctl_mem_val = _T_1 | _T_889; // @[cpath.scala 247:21]
  assign io_ctl_mem_fcn = _T_1 ? 2'h1 : _T_963; // @[cpath.scala 248:21]
  assign io_ctl_mem_typ = _T_1 ? 8'hff : _T_1037; // @[cpath.scala 249:21]
  assign io_ctl_mem_wid = _T_1 ? 3'h6 : _T_1111; // @[cpath.scala 250:21]
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {1{`RANDOM}};
  _T_1289 = _RAND_0[0:0];
  _RAND_1 = {1{`RANDOM}};
  exe_reg_wbaddr = _RAND_1[4:0];
  _RAND_2 = {1{`RANDOM}};
  exe_reg_is_csr = _RAND_2[0:0];
  _RAND_3 = {1{`RANDOM}};
  exe_inst_is_load = _RAND_3[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
  always @(posedge clock) begin
    if (_T_1) begin
      _T_1289 <= 1'h0;
    end else if (_T_3) begin
      _T_1289 <= 1'h0;
    end else if (_T_5) begin
      _T_1289 <= 1'h0;
    end else if (_T_7) begin
      _T_1289 <= 1'h0;
    end else if (_T_9) begin
      _T_1289 <= 1'h0;
    end else if (_T_11) begin
      _T_1289 <= 1'h0;
    end else if (_T_13) begin
      _T_1289 <= 1'h0;
    end else if (_T_15) begin
      _T_1289 <= 1'h0;
    end else if (_T_17) begin
      _T_1289 <= 1'h0;
    end else if (_T_19) begin
      _T_1289 <= 1'h0;
    end else if (_T_21) begin
      _T_1289 <= 1'h0;
    end else if (_T_23) begin
      _T_1289 <= 1'h0;
    end else if (_T_25) begin
      _T_1289 <= 1'h0;
    end else if (_T_27) begin
      _T_1289 <= 1'h0;
    end else if (_T_29) begin
      _T_1289 <= 1'h0;
    end else if (_T_31) begin
      _T_1289 <= 1'h0;
    end else if (_T_33) begin
      _T_1289 <= 1'h0;
    end else if (_T_35) begin
      _T_1289 <= 1'h0;
    end else if (_T_37) begin
      _T_1289 <= 1'h0;
    end else if (_T_39) begin
      _T_1289 <= 1'h0;
    end else if (_T_41) begin
      _T_1289 <= 1'h0;
    end else if (_T_43) begin
      _T_1289 <= 1'h0;
    end else if (_T_45) begin
      _T_1289 <= 1'h0;
    end else if (_T_47) begin
      _T_1289 <= 1'h0;
    end else if (_T_49) begin
      _T_1289 <= 1'h0;
    end else if (_T_51) begin
      _T_1289 <= 1'h0;
    end else if (_T_53) begin
      _T_1289 <= 1'h0;
    end else if (_T_55) begin
      _T_1289 <= 1'h0;
    end else if (_T_57) begin
      _T_1289 <= 1'h0;
    end else if (_T_59) begin
      _T_1289 <= 1'h0;
    end else if (_T_61) begin
      _T_1289 <= 1'h0;
    end else if (_T_63) begin
      _T_1289 <= 1'h0;
    end else if (_T_65) begin
      _T_1289 <= 1'h0;
    end else if (_T_67) begin
      _T_1289 <= 1'h0;
    end else if (_T_69) begin
      _T_1289 <= 1'h0;
    end else if (_T_71) begin
      _T_1289 <= 1'h0;
    end else if (_T_73) begin
      _T_1289 <= 1'h0;
    end else if (_T_75) begin
      _T_1289 <= 1'h0;
    end else if (_T_77) begin
      _T_1289 <= 1'h0;
    end else if (_T_79) begin
      _T_1289 <= 1'h0;
    end else if (_T_81) begin
      _T_1289 <= 1'h0;
    end else if (_T_83) begin
      _T_1289 <= 1'h0;
    end else if (_T_85) begin
      _T_1289 <= 1'h0;
    end else if (_T_87) begin
      _T_1289 <= 1'h0;
    end else if (_T_89) begin
      _T_1289 <= 1'h0;
    end else if (_T_91) begin
      _T_1289 <= 1'h0;
    end else if (_T_93) begin
      _T_1289 <= 1'h0;
    end else if (_T_95) begin
      _T_1289 <= 1'h0;
    end else if (_T_97) begin
      _T_1289 <= 1'h0;
    end else if (_T_99) begin
      _T_1289 <= 1'h0;
    end else if (_T_101) begin
      _T_1289 <= 1'h0;
    end else if (_T_103) begin
      _T_1289 <= 1'h0;
    end else if (_T_105) begin
      _T_1289 <= 1'h0;
    end else if (_T_107) begin
      _T_1289 <= 1'h0;
    end else if (_T_109) begin
      _T_1289 <= 1'h0;
    end else if (_T_111) begin
      _T_1289 <= 1'h0;
    end else if (_T_113) begin
      _T_1289 <= 1'h0;
    end else if (_T_115) begin
      _T_1289 <= 1'h0;
    end else if (_T_117) begin
      _T_1289 <= 1'h0;
    end else if (_T_119) begin
      _T_1289 <= 1'h0;
    end else if (_T_121) begin
      _T_1289 <= 1'h0;
    end else if (_T_123) begin
      _T_1289 <= 1'h0;
    end else if (_T_125) begin
      _T_1289 <= 1'h0;
    end else if (_T_127) begin
      _T_1289 <= 1'h0;
    end else if (_T_129) begin
      _T_1289 <= 1'h0;
    end else if (_T_131) begin
      _T_1289 <= 1'h0;
    end else if (_T_133) begin
      _T_1289 <= 1'h0;
    end else if (_T_135) begin
      _T_1289 <= 1'h0;
    end else if (_T_137) begin
      _T_1289 <= 1'h0;
    end else if (_T_139) begin
      _T_1289 <= 1'h0;
    end else if (_T_141) begin
      _T_1289 <= 1'h0;
    end else if (_T_143) begin
      _T_1289 <= 1'h0;
    end else if (_T_145) begin
      _T_1289 <= 1'h0;
    end else begin
      _T_1289 <= _T_147;
    end
    if (_T_1292) begin
      if (_T_1287) begin
        exe_reg_wbaddr <= 5'h0;
      end else begin
        exe_reg_wbaddr <= dec_wbaddr;
      end
    end else if (_T_1297) begin
      exe_reg_wbaddr <= 5'h0;
    end
    if (reset) begin
      exe_reg_is_csr <= 1'h0;
    end else if (_T_1292) begin
      if (_T_1287) begin
        exe_reg_is_csr <= 1'h0;
      end else begin
        exe_reg_is_csr <= _T_1295;
      end
    end else if (_T_1297) begin
      exe_reg_is_csr <= 1'h0;
    end
    if (reset) begin
      exe_inst_is_load <= 1'h0;
    end else if (_T_1291) begin
      exe_inst_is_load <= _T_1300;
    end
  end
endmodule
module zzy_regfile(
  input         clock,
  input  [4:0]  io_rs1_addr,
  output [63:0] io_rs1_data,
  input  [4:0]  io_rs2_addr,
  output [63:0] io_rs2_data,
  input  [4:0]  io_waddr,
  input  [63:0] io_wdata,
  input         io_wen
);
`ifdef RANDOMIZE_MEM_INIT
  reg [63:0] _RAND_0;
`endif // RANDOMIZE_MEM_INIT
  reg [63:0] regfile [0:31]; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_1_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_1_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_4_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_4_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_10_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_10_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_11_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_11_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_12_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_12_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_13_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_13_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_14_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_14_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_15_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_15_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_16_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_16_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_17_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_17_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_18_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_18_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_19_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_19_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_20_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_20_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_21_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_21_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_22_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_22_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_23_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_23_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_24_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_24_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_25_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_25_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_26_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_26_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_27_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_27_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_28_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_28_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_29_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_29_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_30_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_30_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_31_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_31_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_32_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_32_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_33_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_33_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_34_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_34_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_35_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_35_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_36_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_36_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_37_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_37_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_38_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_38_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_39_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_39_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_40_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_40_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_41_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_41_addr; // @[regfile.scala 22:20]
  wire [63:0] regfile__T_9_data; // @[regfile.scala 22:20]
  wire [4:0] regfile__T_9_addr; // @[regfile.scala 22:20]
  wire  regfile__T_9_mask; // @[regfile.scala 22:20]
  wire  regfile__T_9_en; // @[regfile.scala 22:20]
  wire  _T = io_rs1_addr != 5'h0; // @[regfile.scala 24:35]
  wire  _T_3 = io_rs2_addr != 5'h0; // @[regfile.scala 25:35]
  wire  _T_7 = io_waddr != 5'h0; // @[regfile.scala 27:38]
  wire [63:0] _T_42_0 = regfile__T_10_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_1 = regfile__T_11_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_2 = regfile__T_12_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_3 = regfile__T_13_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_4 = regfile__T_14_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_5 = regfile__T_15_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_6 = regfile__T_16_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_7 = regfile__T_17_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_8 = regfile__T_18_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_9 = regfile__T_19_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_10 = regfile__T_20_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_11 = regfile__T_21_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_12 = regfile__T_22_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_13 = regfile__T_23_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_14 = regfile__T_24_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_15 = regfile__T_25_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_16 = regfile__T_26_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_17 = regfile__T_27_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_18 = regfile__T_28_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_19 = regfile__T_29_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_20 = regfile__T_30_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_21 = regfile__T_31_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_22 = regfile__T_32_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_23 = regfile__T_33_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_24 = regfile__T_34_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_25 = regfile__T_35_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_26 = regfile__T_36_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_27 = regfile__T_37_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_28 = regfile__T_38_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_29 = regfile__T_39_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_30 = regfile__T_40_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  wire [63:0] _T_42_31 = regfile__T_41_data; // @[regfile.scala 31:32 regfile.scala 31:32]
  assign regfile__T_1_addr = io_rs1_addr;
  assign regfile__T_1_data = regfile[regfile__T_1_addr]; // @[regfile.scala 22:20]
  assign regfile__T_4_addr = io_rs2_addr;
  assign regfile__T_4_data = regfile[regfile__T_4_addr]; // @[regfile.scala 22:20]
  assign regfile__T_10_addr = 5'h0;
  assign regfile__T_10_data = regfile[regfile__T_10_addr]; // @[regfile.scala 22:20]
  assign regfile__T_11_addr = 5'h1;
  assign regfile__T_11_data = regfile[regfile__T_11_addr]; // @[regfile.scala 22:20]
  assign regfile__T_12_addr = 5'h2;
  assign regfile__T_12_data = regfile[regfile__T_12_addr]; // @[regfile.scala 22:20]
  assign regfile__T_13_addr = 5'h3;
  assign regfile__T_13_data = regfile[regfile__T_13_addr]; // @[regfile.scala 22:20]
  assign regfile__T_14_addr = 5'h4;
  assign regfile__T_14_data = regfile[regfile__T_14_addr]; // @[regfile.scala 22:20]
  assign regfile__T_15_addr = 5'h5;
  assign regfile__T_15_data = regfile[regfile__T_15_addr]; // @[regfile.scala 22:20]
  assign regfile__T_16_addr = 5'h6;
  assign regfile__T_16_data = regfile[regfile__T_16_addr]; // @[regfile.scala 22:20]
  assign regfile__T_17_addr = 5'h7;
  assign regfile__T_17_data = regfile[regfile__T_17_addr]; // @[regfile.scala 22:20]
  assign regfile__T_18_addr = 5'h8;
  assign regfile__T_18_data = regfile[regfile__T_18_addr]; // @[regfile.scala 22:20]
  assign regfile__T_19_addr = 5'h9;
  assign regfile__T_19_data = regfile[regfile__T_19_addr]; // @[regfile.scala 22:20]
  assign regfile__T_20_addr = 5'ha;
  assign regfile__T_20_data = regfile[regfile__T_20_addr]; // @[regfile.scala 22:20]
  assign regfile__T_21_addr = 5'hb;
  assign regfile__T_21_data = regfile[regfile__T_21_addr]; // @[regfile.scala 22:20]
  assign regfile__T_22_addr = 5'hc;
  assign regfile__T_22_data = regfile[regfile__T_22_addr]; // @[regfile.scala 22:20]
  assign regfile__T_23_addr = 5'hd;
  assign regfile__T_23_data = regfile[regfile__T_23_addr]; // @[regfile.scala 22:20]
  assign regfile__T_24_addr = 5'he;
  assign regfile__T_24_data = regfile[regfile__T_24_addr]; // @[regfile.scala 22:20]
  assign regfile__T_25_addr = 5'hf;
  assign regfile__T_25_data = regfile[regfile__T_25_addr]; // @[regfile.scala 22:20]
  assign regfile__T_26_addr = 5'h10;
  assign regfile__T_26_data = regfile[regfile__T_26_addr]; // @[regfile.scala 22:20]
  assign regfile__T_27_addr = 5'h11;
  assign regfile__T_27_data = regfile[regfile__T_27_addr]; // @[regfile.scala 22:20]
  assign regfile__T_28_addr = 5'h12;
  assign regfile__T_28_data = regfile[regfile__T_28_addr]; // @[regfile.scala 22:20]
  assign regfile__T_29_addr = 5'h13;
  assign regfile__T_29_data = regfile[regfile__T_29_addr]; // @[regfile.scala 22:20]
  assign regfile__T_30_addr = 5'h14;
  assign regfile__T_30_data = regfile[regfile__T_30_addr]; // @[regfile.scala 22:20]
  assign regfile__T_31_addr = 5'h15;
  assign regfile__T_31_data = regfile[regfile__T_31_addr]; // @[regfile.scala 22:20]
  assign regfile__T_32_addr = 5'h16;
  assign regfile__T_32_data = regfile[regfile__T_32_addr]; // @[regfile.scala 22:20]
  assign regfile__T_33_addr = 5'h17;
  assign regfile__T_33_data = regfile[regfile__T_33_addr]; // @[regfile.scala 22:20]
  assign regfile__T_34_addr = 5'h18;
  assign regfile__T_34_data = regfile[regfile__T_34_addr]; // @[regfile.scala 22:20]
  assign regfile__T_35_addr = 5'h19;
  assign regfile__T_35_data = regfile[regfile__T_35_addr]; // @[regfile.scala 22:20]
  assign regfile__T_36_addr = 5'h1a;
  assign regfile__T_36_data = regfile[regfile__T_36_addr]; // @[regfile.scala 22:20]
  assign regfile__T_37_addr = 5'h1b;
  assign regfile__T_37_data = regfile[regfile__T_37_addr]; // @[regfile.scala 22:20]
  assign regfile__T_38_addr = 5'h1c;
  assign regfile__T_38_data = regfile[regfile__T_38_addr]; // @[regfile.scala 22:20]
  assign regfile__T_39_addr = 5'h1d;
  assign regfile__T_39_data = regfile[regfile__T_39_addr]; // @[regfile.scala 22:20]
  assign regfile__T_40_addr = 5'h1e;
  assign regfile__T_40_data = regfile[regfile__T_40_addr]; // @[regfile.scala 22:20]
  assign regfile__T_41_addr = 5'h1f;
  assign regfile__T_41_data = regfile[regfile__T_41_addr]; // @[regfile.scala 22:20]
  assign regfile__T_9_data = io_wdata;
  assign regfile__T_9_addr = io_waddr;
  assign regfile__T_9_mask = 1'h1;
  assign regfile__T_9_en = io_wen & _T_7;
  assign io_rs1_data = _T ? regfile__T_1_data : 64'h0; // @[regfile.scala 24:15]
  assign io_rs2_data = _T_3 ? regfile__T_4_data : 64'h0; // @[regfile.scala 25:15]
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_MEM_INIT
  _RAND_0 = {2{`RANDOM}};
  for (initvar = 0; initvar < 32; initvar = initvar+1)
    regfile[initvar] = _RAND_0[63:0];
`endif // RANDOMIZE_MEM_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
  always @(posedge clock) begin
    if(regfile__T_9_en & regfile__T_9_mask) begin
      regfile[regfile__T_9_addr] <= regfile__T_9_data; // @[regfile.scala 22:20]
    end
  end
endmodule
module zzy_Multiplier(
  input         clock,
  input         reset,
  input         io_start,
  input  [63:0] io_a,
  input  [63:0] io_b,
  input  [4:0]  io_op,
  output        io_stall_req,
  output [63:0] io_mult_out
);
`ifdef RANDOMIZE_REG_INIT
  reg [63:0] _RAND_0;
  reg [63:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [127:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
`endif // RANDOMIZE_REG_INIT
  reg [63:0] last_a; // @[mdu.scala 55:23]
  reg [63:0] last_b; // @[mdu.scala 56:23]
  reg [4:0] last_op; // @[mdu.scala 57:24]
  wire  _T = io_op == 5'hd; // @[mdu.scala 65:23]
  wire  _T_1 = io_op == 5'h12; // @[mdu.scala 65:44]
  wire  _T_2 = _T | _T_1; // @[mdu.scala 65:35]
  wire  _T_3 = io_op == 5'h13; // @[mdu.scala 65:66]
  wire  _T_4 = _T_2 | _T_3; // @[mdu.scala 65:57]
  wire  _T_5 = io_op == 5'h14; // @[mdu.scala 65:90]
  wire  _T_6 = _T_4 | _T_5; // @[mdu.scala 65:81]
  wire  _T_7 = io_op == 5'h19; // @[mdu.scala 65:113]
  wire  is_mult = _T_6 | _T_7; // @[mdu.scala 65:104]
  reg [127:0] res; // @[mdu.scala 66:20]
  reg [6:0] mult_cnt; // @[mdu.scala 67:25]
  reg [6:0] div_cnt; // @[mdu.scala 68:24]
  wire  sign_a = io_a[63]; // @[mdu.scala 69:20]
  wire  sign_wa = io_a[31]; // @[mdu.scala 70:21]
  wire [63:0] _T_10 = {32'h0,io_a[31:0]}; // @[Cat.scala 29:58]
  wire [63:0] _T_12 = ~io_a; // @[mdu.scala 74:41]
  wire [63:0] _T_14 = _T_12 + 64'h1; // @[mdu.scala 74:48]
  wire [63:0] _T_15 = sign_a ? _T_14 : io_a; // @[mdu.scala 74:22]
  wire [31:0] _T_36 = sign_wa ? _T_14[31:0] : io_a[31:0]; // @[mdu.scala 80:41]
  wire [63:0] _T_37 = {32'h0,_T_36}; // @[Cat.scala 29:58]
  wire  _T_58 = 5'hd == io_op; // @[Mux.scala 80:60]
  wire [63:0] _T_59 = _T_58 ? io_a : _T_10; // @[Mux.scala 80:57]
  wire  _T_60 = 5'h12 == io_op; // @[Mux.scala 80:60]
  wire [63:0] _T_61 = _T_60 ? _T_15 : _T_59; // @[Mux.scala 80:57]
  wire  _T_62 = 5'h13 == io_op; // @[Mux.scala 80:60]
  wire [63:0] _T_63 = _T_62 ? _T_15 : _T_61; // @[Mux.scala 80:57]
  wire  _T_64 = 5'h14 == io_op; // @[Mux.scala 80:60]
  wire [63:0] _T_65 = _T_64 ? io_a : _T_63; // @[Mux.scala 80:57]
  wire  _T_66 = 5'h19 == io_op; // @[Mux.scala 80:60]
  wire [63:0] _T_67 = _T_66 ? _T_10 : _T_65; // @[Mux.scala 80:57]
  wire  _T_68 = 5'he == io_op; // @[Mux.scala 80:60]
  wire [63:0] _T_69 = _T_68 ? _T_15 : _T_67; // @[Mux.scala 80:57]
  wire  _T_70 = 5'h15 == io_op; // @[Mux.scala 80:60]
  wire [63:0] _T_71 = _T_70 ? io_a : _T_69; // @[Mux.scala 80:57]
  wire  _T_72 = 5'h16 == io_op; // @[Mux.scala 80:60]
  wire [63:0] _T_73 = _T_72 ? _T_37 : _T_71; // @[Mux.scala 80:57]
  wire  _T_74 = 5'h11 == io_op; // @[Mux.scala 80:60]
  wire [63:0] _T_75 = _T_74 ? _T_10 : _T_73; // @[Mux.scala 80:57]
  wire  _T_76 = 5'h17 == io_op; // @[Mux.scala 80:60]
  wire [63:0] _T_77 = _T_76 ? _T_15 : _T_75; // @[Mux.scala 80:57]
  wire  _T_78 = 5'h18 == io_op; // @[Mux.scala 80:60]
  wire [63:0] _T_79 = _T_78 ? io_a : _T_77; // @[Mux.scala 80:57]
  wire  _T_80 = 5'hf == io_op; // @[Mux.scala 80:60]
  wire [63:0] _T_81 = _T_80 ? _T_37 : _T_79; // @[Mux.scala 80:57]
  wire  _T_82 = 5'h10 == io_op; // @[Mux.scala 80:60]
  wire [63:0] abs_a = _T_82 ? _T_10 : _T_81; // @[Mux.scala 80:57]
  wire  sign_b = io_b[63]; // @[mdu.scala 89:20]
  wire  sign_wb = io_b[31]; // @[mdu.scala 90:21]
  wire [63:0] _T_85 = {32'h0,io_b[31:0]}; // @[Cat.scala 29:58]
  wire [63:0] _T_87 = ~io_b; // @[mdu.scala 94:41]
  wire [63:0] _T_89 = _T_87 + 64'h1; // @[mdu.scala 94:48]
  wire [63:0] _T_90 = sign_b ? _T_89 : io_b; // @[mdu.scala 94:22]
  wire [31:0] _T_106 = sign_wb ? _T_89[31:0] : io_b[31:0]; // @[mdu.scala 100:41]
  wire [63:0] _T_107 = {32'h0,_T_106}; // @[Cat.scala 29:58]
  wire [63:0] _T_129 = _T_58 ? io_b : _T_85; // @[Mux.scala 80:57]
  wire [63:0] _T_131 = _T_60 ? _T_90 : _T_129; // @[Mux.scala 80:57]
  wire [63:0] _T_133 = _T_62 ? io_b : _T_131; // @[Mux.scala 80:57]
  wire [63:0] _T_135 = _T_64 ? io_b : _T_133; // @[Mux.scala 80:57]
  wire [63:0] _T_137 = _T_66 ? _T_85 : _T_135; // @[Mux.scala 80:57]
  wire [63:0] _T_139 = _T_68 ? _T_90 : _T_137; // @[Mux.scala 80:57]
  wire [63:0] _T_141 = _T_70 ? io_b : _T_139; // @[Mux.scala 80:57]
  wire [63:0] _T_143 = _T_72 ? _T_107 : _T_141; // @[Mux.scala 80:57]
  wire [63:0] _T_145 = _T_74 ? _T_85 : _T_143; // @[Mux.scala 80:57]
  wire [63:0] _T_147 = _T_76 ? _T_90 : _T_145; // @[Mux.scala 80:57]
  wire [63:0] _T_149 = _T_78 ? io_b : _T_147; // @[Mux.scala 80:57]
  wire [63:0] _T_151 = _T_80 ? _T_107 : _T_149; // @[Mux.scala 80:57]
  wire [63:0] abs_b = _T_82 ? _T_85 : _T_151; // @[Mux.scala 80:57]
  wire  _T_153 = sign_a == sign_b; // @[mdu.scala 108:27]
  wire [127:0] _T_154 = ~res; // @[mdu.scala 108:46]
  wire [127:0] _T_156 = _T_154 + 128'h1; // @[mdu.scala 108:52]
  wire [127:0] res_ss = _T_153 ? res : _T_156; // @[mdu.scala 108:19]
  wire  _T_157 = ~sign_a; // @[mdu.scala 109:27]
  wire [127:0] res_su = _T_157 ? res : _T_156; // @[mdu.scala 109:19]
  wire [63:0] _T_164 = ~res[63:0]; // @[mdu.scala 110:61]
  wire [63:0] _T_166 = _T_164 + 64'h1; // @[mdu.scala 110:80]
  wire [63:0] res_divs = _T_153 ? res[63:0] : _T_166; // @[mdu.scala 110:21]
  wire [63:0] _T_170 = ~res[127:64]; // @[mdu.scala 111:65]
  wire [63:0] _T_172 = _T_170 + 64'h1; // @[mdu.scala 111:91]
  wire [63:0] res_rems = _T_157 ? res[127:64] : _T_172; // @[mdu.scala 111:21]
  wire  _T_173 = sign_wa == sign_wb; // @[mdu.scala 112:31]
  wire [31:0] _T_176 = ~res[31:0]; // @[mdu.scala 112:58]
  wire [31:0] _T_178 = _T_176 + 32'h1; // @[mdu.scala 112:71]
  wire [31:0] res_divsw = _T_173 ? res[31:0] : _T_178; // @[mdu.scala 112:22]
  wire [31:0] _T_182 = ~res[95:64]; // @[mdu.scala 113:63]
  wire [31:0] _T_184 = _T_182 + 32'h1; // @[mdu.scala 113:86]
  wire [31:0] res_remsw = _T_157 ? res[95:64] : _T_184; // @[mdu.scala 113:22]
  reg  last_stall_req; // @[mdu.scala 114:31]
  wire [6:0] _T_186 = mult_cnt + 7'h1; // @[mdu.scala 123:30]
  wire  _T_187 = ~last_stall_req; // @[mdu.scala 128:14]
  wire [127:0] _T_189 = {64'h0,abs_b}; // @[Cat.scala 29:58]
  wire [63:0] _T_206 = res[0] ? abs_a : 64'h0; // @[mdu.scala 155:39]
  wire [64:0] _T_207 = {1'h0,_T_206}; // @[Cat.scala 29:58]
  wire [64:0] _T_209 = {1'h0,res[127:64]}; // @[Cat.scala 29:58]
  wire [64:0] _T_211 = _T_207 + _T_209; // @[mdu.scala 155:69]
  wire  _T_289 = res[127:64] >= abs_b; // @[mdu.scala 168:46]
  wire [63:0] _T_292 = res[127:64] - abs_b; // @[mdu.scala 168:80]
  wire [63:0] _T_294 = _T_289 ? _T_292 : res[127:64]; // @[mdu.scala 168:21]
  wire [64:0] front_val = is_mult ? _T_211 : {{1'd0}, _T_294}; // @[mdu.scala 154:17]
  wire [127:0] _T_214 = {front_val[63:0],res[63:0]}; // @[Cat.scala 29:58]
  wire [127:0] _T_300 = {front_val[62:0],res[63:0],_T_289}; // @[Cat.scala 29:58]
  wire [127:0] step_result = is_mult ? _T_214 : _T_300; // @[mdu.scala 154:17]
  wire [127:0] _T_192 = {front_val[64],step_result[127:1]}; // @[Cat.scala 29:58]
  wire [6:0] _T_194 = div_cnt + 7'h1; // @[mdu.scala 136:28]
  wire [127:0] _T_198 = {63'h0,abs_a,1'h0}; // @[Cat.scala 29:58]
  wire  _T_199 = div_cnt == 7'h40; // @[mdu.scala 143:28]
  wire [127:0] _T_204 = {front_val[63],step_result[127:65],step_result[63:0]}; // @[Cat.scala 29:58]
  wire  _T_215 = mult_cnt != 7'h41; // @[mdu.scala 157:43]
  wire  _T_217 = io_a == last_a; // @[mdu.scala 52:7]
  wire  _T_218 = io_b == last_b; // @[mdu.scala 52:19]
  wire  _T_219 = _T_217 & _T_218; // @[mdu.scala 52:14]
  wire  _T_220 = last_op == 5'h14; // @[mdu.scala 40:19]
  wire  _T_221 = last_op == 5'h12; // @[mdu.scala 40:47]
  wire  _T_222 = _T_220 | _T_221; // @[mdu.scala 40:33]
  wire  _T_223 = last_op == 5'h13; // @[mdu.scala 40:74]
  wire  _T_224 = _T_222 | _T_223; // @[mdu.scala 40:60]
  wire  _T_226 = _T_224 & _T; // @[mdu.scala 40:90]
  wire  _T_227 = last_op == 5'he; // @[mdu.scala 41:19]
  wire  _T_228 = io_op == 5'h17; // @[mdu.scala 41:37]
  wire  _T_229 = _T_227 & _T_228; // @[mdu.scala 41:31]
  wire  _T_230 = _T_226 | _T_229; // @[mdu.scala 40:109]
  wire  _T_231 = last_op == 5'h15; // @[mdu.scala 42:19]
  wire  _T_232 = io_op == 5'h18; // @[mdu.scala 42:38]
  wire  _T_233 = _T_231 & _T_232; // @[mdu.scala 42:32]
  wire  _T_234 = _T_230 | _T_233; // @[mdu.scala 41:50]
  wire  _T_235 = last_op == 5'h11; // @[mdu.scala 43:19]
  wire  _T_236 = io_op == 5'h10; // @[mdu.scala 43:39]
  wire  _T_237 = _T_235 & _T_236; // @[mdu.scala 43:33]
  wire  _T_238 = _T_234 | _T_237; // @[mdu.scala 42:52]
  wire  _T_239 = last_op == 5'h16; // @[mdu.scala 44:19]
  wire  _T_240 = io_op == 5'hf; // @[mdu.scala 44:38]
  wire  _T_241 = _T_239 & _T_240; // @[mdu.scala 44:32]
  wire  _T_242 = _T_238 | _T_241; // @[mdu.scala 43:54]
  wire  _T_243 = io_op == 5'he; // @[mdu.scala 45:11]
  wire  _T_244 = last_op == 5'h17; // @[mdu.scala 45:37]
  wire  _T_245 = _T_243 & _T_244; // @[mdu.scala 45:23]
  wire  _T_246 = _T_242 | _T_245; // @[mdu.scala 44:52]
  wire  _T_247 = io_op == 5'h15; // @[mdu.scala 46:11]
  wire  _T_248 = last_op == 5'h18; // @[mdu.scala 46:38]
  wire  _T_249 = _T_247 & _T_248; // @[mdu.scala 46:24]
  wire  _T_250 = _T_246 | _T_249; // @[mdu.scala 45:50]
  wire  _T_251 = io_op == 5'h11; // @[mdu.scala 47:11]
  wire  _T_252 = last_op == 5'h10; // @[mdu.scala 47:39]
  wire  _T_253 = _T_251 & _T_252; // @[mdu.scala 47:25]
  wire  _T_254 = _T_250 | _T_253; // @[mdu.scala 46:52]
  wire  _T_255 = io_op == 5'h16; // @[mdu.scala 48:11]
  wire  _T_256 = last_op == 5'hf; // @[mdu.scala 48:38]
  wire  _T_257 = _T_255 & _T_256; // @[mdu.scala 48:24]
  wire  _T_258 = _T_254 | _T_257; // @[mdu.scala 47:54]
  wire  _T_259 = _T_219 & _T_258; // @[mdu.scala 52:26]
  wire  _T_260 = ~_T_259; // @[mdu.scala 157:83]
  wire  _T_261 = _T_187 & _T_260; // @[mdu.scala 157:80]
  wire  _T_262 = _T_215 | _T_261; // @[mdu.scala 157:60]
  wire  _T_263 = io_start & _T_262; // @[mdu.scala 157:30]
  wire [31:0] _T_266 = res[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _T_268 = {_T_266,res[31:0]}; // @[Cat.scala 29:58]
  wire [63:0] _T_279 = _T_58 ? res[63:0] : _T_268; // @[Mux.scala 80:57]
  wire [63:0] _T_281 = _T_60 ? res_ss[127:64] : _T_279; // @[Mux.scala 80:57]
  wire [63:0] _T_283 = _T_62 ? res_su[127:64] : _T_281; // @[Mux.scala 80:57]
  wire [63:0] _T_285 = _T_64 ? res[127:64] : _T_283; // @[Mux.scala 80:57]
  wire [63:0] _T_287 = _T_66 ? _T_268 : _T_285; // @[Mux.scala 80:57]
  wire  _T_301 = div_cnt != 7'h41; // @[mdu.scala 170:42]
  wire  _T_348 = _T_301 | _T_261; // @[mdu.scala 170:59]
  wire  _T_349 = io_start & _T_348; // @[mdu.scala 170:30]
  wire  _T_350 = |io_b; // @[mdu.scala 173:29]
  wire [63:0] _T_352 = _T_350 ? res_divs : 64'hffffffffffffffff; // @[mdu.scala 173:23]
  wire [63:0] _T_356 = _T_350 ? res[63:0] : 64'hffffffffffffffff; // @[mdu.scala 174:24]
  wire  _T_358 = |io_b[31:0]; // @[mdu.scala 175:37]
  wire [31:0] _T_361 = res_divsw[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _T_362 = {_T_361,res_divsw}; // @[Cat.scala 29:58]
  wire [63:0] _T_364 = _T_358 ? _T_362 : 64'hffffffffffffffff; // @[mdu.scala 175:24]
  wire [63:0] _T_373 = _T_358 ? _T_268 : 64'hffffffffffffffff; // @[mdu.scala 176:25]
  wire [63:0] _T_375 = _T_350 ? res_rems : io_a; // @[mdu.scala 177:23]
  wire [63:0] _T_378 = _T_350 ? res[127:64] : io_a; // @[mdu.scala 178:24]
  wire [31:0] _T_383 = res_remsw[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _T_384 = {_T_383,res_remsw}; // @[Cat.scala 29:58]
  wire [63:0] _T_385 = _T_358 ? _T_384 : io_a; // @[mdu.scala 179:24]
  wire [31:0] _T_390 = res[95] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _T_392 = {_T_390,res[95:64]}; // @[Cat.scala 29:58]
  wire [63:0] _T_393 = _T_358 ? _T_392 : io_a; // @[mdu.scala 180:25]
  wire [63:0] _T_395 = _T_68 ? _T_352 : 64'h0; // @[Mux.scala 80:57]
  wire [63:0] _T_397 = _T_70 ? _T_356 : _T_395; // @[Mux.scala 80:57]
  wire [63:0] _T_399 = _T_72 ? _T_364 : _T_397; // @[Mux.scala 80:57]
  wire [63:0] _T_401 = _T_74 ? _T_373 : _T_399; // @[Mux.scala 80:57]
  wire [63:0] _T_403 = _T_76 ? _T_375 : _T_401; // @[Mux.scala 80:57]
  wire [63:0] _T_405 = _T_78 ? _T_378 : _T_403; // @[Mux.scala 80:57]
  wire [63:0] _T_407 = _T_80 ? _T_385 : _T_405; // @[Mux.scala 80:57]
  wire [63:0] _T_409 = _T_82 ? _T_393 : _T_407; // @[Mux.scala 80:57]
  assign io_stall_req = is_mult ? _T_263 : _T_349; // @[mdu.scala 157:18 mdu.scala 170:18]
  assign io_mult_out = is_mult ? _T_287 : _T_409; // @[mdu.scala 158:17 mdu.scala 171:17]
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {2{`RANDOM}};
  last_a = _RAND_0[63:0];
  _RAND_1 = {2{`RANDOM}};
  last_b = _RAND_1[63:0];
  _RAND_2 = {1{`RANDOM}};
  last_op = _RAND_2[4:0];
  _RAND_3 = {4{`RANDOM}};
  res = _RAND_3[127:0];
  _RAND_4 = {1{`RANDOM}};
  mult_cnt = _RAND_4[6:0];
  _RAND_5 = {1{`RANDOM}};
  div_cnt = _RAND_5[6:0];
  _RAND_6 = {1{`RANDOM}};
  last_stall_req = _RAND_6[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
  always @(posedge clock) begin
    if (reset) begin
      last_a <= 64'h0;
    end else if (io_start) begin
      last_a <= io_a;
    end
    if (reset) begin
      last_b <= 64'h0;
    end else if (io_start) begin
      last_b <= io_b;
    end
    if (reset) begin
      last_op <= 5'h0;
    end else if (io_start) begin
      last_op <= io_op;
    end
    if (reset) begin
      res <= 128'h0;
    end else if (io_start) begin
      if (is_mult) begin
        if (io_stall_req) begin
          if (_T_187) begin
            res <= _T_189;
          end else begin
            res <= _T_192;
          end
        end
      end else if (io_stall_req) begin
        if (_T_187) begin
          res <= _T_198;
        end else if (_T_199) begin
          res <= _T_204;
        end else if (is_mult) begin
          res <= _T_214;
        end else begin
          res <= _T_300;
        end
      end
    end
    if (reset) begin
      mult_cnt <= 7'h0;
    end else if (io_start) begin
      if (is_mult) begin
        if (io_stall_req) begin
          mult_cnt <= _T_186;
        end else begin
          mult_cnt <= 7'h0;
        end
      end
    end
    if (reset) begin
      div_cnt <= 7'h0;
    end else if (io_start) begin
      if (!(is_mult)) begin
        if (io_stall_req) begin
          div_cnt <= _T_194;
        end else begin
          div_cnt <= 7'h0;
        end
      end
    end
    if (reset) begin
      last_stall_req <= 1'h0;
    end else begin
      last_stall_req <= io_stall_req;
    end
  end
endmodule
module zzy_alu(
  input         clock,
  input         reset,
  input  [63:0] io_src1,
  input  [63:0] io_src2,
  input  [4:0]  io_op,
  output [63:0] io_res,
  output        io_stall
);
  wire  mdu_clock; // @[alu.scala 28:19]
  wire  mdu_reset; // @[alu.scala 28:19]
  wire  mdu_io_start; // @[alu.scala 28:19]
  wire [63:0] mdu_io_a; // @[alu.scala 28:19]
  wire [63:0] mdu_io_b; // @[alu.scala 28:19]
  wire [4:0] mdu_io_op; // @[alu.scala 28:19]
  wire  mdu_io_stall_req; // @[alu.scala 28:19]
  wire [63:0] mdu_io_mult_out; // @[alu.scala 28:19]
  wire [5:0] shamt = io_src2[5:0]; // @[alu.scala 20:22]
  wire  _T = io_op == 5'hd; // @[alu.scala 24:23]
  wire  _T_1 = io_op == 5'he; // @[alu.scala 24:47]
  wire  _T_2 = _T | _T_1; // @[alu.scala 24:38]
  wire  _T_3 = io_op == 5'hf; // @[alu.scala 24:70]
  wire  _T_4 = _T_2 | _T_3; // @[alu.scala 24:61]
  wire  _T_5 = io_op == 5'h10; // @[alu.scala 25:23]
  wire  _T_6 = _T_4 | _T_5; // @[alu.scala 24:83]
  wire  _T_7 = io_op == 5'h11; // @[alu.scala 25:47]
  wire  _T_8 = _T_6 | _T_7; // @[alu.scala 25:38]
  wire  _T_9 = io_op == 5'h12; // @[alu.scala 25:70]
  wire  _T_10 = _T_8 | _T_9; // @[alu.scala 25:61]
  wire  _T_11 = io_op == 5'h13; // @[alu.scala 26:23]
  wire  _T_12 = _T_10 | _T_11; // @[alu.scala 25:83]
  wire  _T_13 = io_op == 5'h14; // @[alu.scala 26:47]
  wire  _T_14 = _T_12 | _T_13; // @[alu.scala 26:38]
  wire  _T_15 = io_op == 5'h15; // @[alu.scala 26:70]
  wire  _T_16 = _T_14 | _T_15; // @[alu.scala 26:61]
  wire  _T_17 = io_op == 5'h16; // @[alu.scala 27:23]
  wire  _T_18 = _T_16 | _T_17; // @[alu.scala 26:83]
  wire  _T_19 = io_op == 5'h17; // @[alu.scala 27:47]
  wire  _T_20 = _T_18 | _T_19; // @[alu.scala 27:38]
  wire  _T_21 = io_op == 5'h18; // @[alu.scala 27:70]
  wire  use_mdu = _T_20 | _T_21; // @[alu.scala 27:61]
  wire  _T_23 = io_op == 5'h0; // @[alu.scala 37:9]
  wire [63:0] _T_25 = io_src1 + io_src2; // @[alu.scala 37:34]
  wire  _T_26 = io_op == 5'h1; // @[alu.scala 38:9]
  wire [63:0] _T_28 = io_src1 - io_src2; // @[alu.scala 38:34]
  wire  _T_29 = io_op == 5'h5; // @[alu.scala 39:9]
  wire [63:0] _T_30 = io_src1 & io_src2; // @[alu.scala 39:34]
  wire  _T_31 = io_op == 5'h6; // @[alu.scala 40:9]
  wire [63:0] _T_32 = io_src1 | io_src2; // @[alu.scala 40:34]
  wire  _T_33 = io_op == 5'h7; // @[alu.scala 41:9]
  wire [63:0] _T_34 = io_src1 ^ io_src2; // @[alu.scala 41:34]
  wire  _T_35 = io_op == 5'h8; // @[alu.scala 42:9]
  wire  _T_38 = $signed(io_src1) < $signed(io_src2); // @[alu.scala 42:43]
  wire  _T_39 = io_op == 5'h9; // @[alu.scala 43:9]
  wire  _T_40 = io_src1 < io_src2; // @[alu.scala 43:34]
  wire  _T_41 = io_op == 5'h2; // @[alu.scala 44:9]
  wire [126:0] _GEN_0 = {{63'd0}, io_src1}; // @[alu.scala 44:35]
  wire [126:0] _T_42 = _GEN_0 << shamt; // @[alu.scala 44:35]
  wire  _T_44 = io_op == 5'h4; // @[alu.scala 45:9]
  wire [63:0] _T_47 = $signed(io_src1) >>> shamt; // @[alu.scala 45:59]
  wire  _T_48 = io_op == 5'h3; // @[alu.scala 46:9]
  wire [63:0] _T_49 = io_src1 >> shamt; // @[alu.scala 46:43]
  wire  _T_50 = io_op == 5'h1a; // @[alu.scala 47:9]
  wire [63:0] _T_52 = io_src1 >> io_src2[4:0]; // @[alu.scala 47:43]
  wire  _T_53 = io_op == 5'ha; // @[alu.scala 48:9]
  wire  _T_54 = io_op == 5'hb; // @[alu.scala 49:9]
  wire  _T_55 = io_op == 5'hc; // @[alu.scala 50:9]
  wire [31:0] _T_58 = io_src1[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [31:0] _T_60 = io_src1[31:0]; // @[alu.scala 50:70]
  wire [31:0] _T_62 = $signed(_T_60) >>> shamt; // @[alu.scala 50:89]
  wire [63:0] _T_63 = {_T_58,_T_62}; // @[Cat.scala 29:58]
  wire [63:0] _T_64 = use_mdu ? mdu_io_mult_out : 64'h0; // @[Mux.scala 98:16]
  wire [63:0] _T_65 = _T_55 ? _T_63 : _T_64; // @[Mux.scala 98:16]
  wire [63:0] _T_66 = _T_54 ? io_src2 : _T_65; // @[Mux.scala 98:16]
  wire [63:0] _T_67 = _T_53 ? io_src1 : _T_66; // @[Mux.scala 98:16]
  wire [63:0] _T_68 = _T_50 ? _T_52 : _T_67; // @[Mux.scala 98:16]
  wire [63:0] _T_69 = _T_48 ? _T_49 : _T_68; // @[Mux.scala 98:16]
  wire [63:0] _T_70 = _T_44 ? _T_47 : _T_69; // @[Mux.scala 98:16]
  wire [63:0] _T_71 = _T_41 ? _T_42[63:0] : _T_70; // @[Mux.scala 98:16]
  wire [63:0] _T_72 = _T_39 ? {{63'd0}, _T_40} : _T_71; // @[Mux.scala 98:16]
  wire [63:0] _T_73 = _T_35 ? {{63'd0}, _T_38} : _T_72; // @[Mux.scala 98:16]
  wire [63:0] _T_74 = _T_33 ? _T_34 : _T_73; // @[Mux.scala 98:16]
  wire [63:0] _T_75 = _T_31 ? _T_32 : _T_74; // @[Mux.scala 98:16]
  wire [63:0] _T_76 = _T_29 ? _T_30 : _T_75; // @[Mux.scala 98:16]
  wire [63:0] _T_77 = _T_26 ? _T_28 : _T_76; // @[Mux.scala 98:16]
  zzy_Multiplier mdu ( // @[alu.scala 28:19]
    .clock(mdu_clock),
    .reset(mdu_reset),
    .io_start(mdu_io_start),
    .io_a(mdu_io_a),
    .io_b(mdu_io_b),
    .io_op(mdu_io_op),
    .io_stall_req(mdu_io_stall_req),
    .io_mult_out(mdu_io_mult_out)
  );
  assign io_res = _T_23 ? _T_25 : _T_77; // @[alu.scala 36:10]
  assign io_stall = use_mdu & mdu_io_stall_req; // @[alu.scala 34:16]
  assign mdu_clock = clock;
  assign mdu_reset = reset;
  assign mdu_io_start = _T_20 | _T_21; // @[alu.scala 30:16]
  assign mdu_io_a = io_src1; // @[alu.scala 31:13]
  assign mdu_io_b = io_src2; // @[alu.scala 32:13]
  assign mdu_io_op = io_op; // @[alu.scala 33:16]
endmodule
module zzy_Dpath(
  input         clock,
  input         reset,
  input         io_ctl_dec_stall,
  input         io_ctl_full_stall,
  input  [1:0]  io_ctl_exe_pc_sel,
  input  [3:0]  io_ctl_br_type,
  input         io_ctl_if_kill,
  input         io_ctl_dec_kill,
  input  [1:0]  io_ctl_op1_sel,
  input  [2:0]  io_ctl_op2_sel,
  input  [4:0]  io_ctl_alu_fun,
  input  [2:0]  io_ctl_wb_sel,
  input         io_ctl_rf_wen,
  input         io_ctl_mem_val,
  input  [1:0]  io_ctl_mem_fcn,
  input  [7:0]  io_ctl_mem_typ,
  input  [2:0]  io_ctl_mem_wid,
  output [63:0] io_dat_dec_inst,
  output        io_dat_exe_br_eq,
  output        io_dat_exe_br_lt,
  output        io_dat_exe_br_ltu,
  output [3:0]  io_dat_exe_br_type,
  output        io_dat_exe_ctrl_dmem_val,
  output        io_dat_inst_valid,
  output        io_dat_data_valid,
  output        io_imem_req_valid,
  output [63:0] io_imem_req_bits_addr,
  input         io_imem_resp_valid,
  input  [63:0] io_imem_resp_bits_data,
  output        io_dmem_req_valid,
  output [63:0] io_dmem_req_bits_addr,
  output [63:0] io_dmem_req_bits_data,
  output        io_dmem_req_bits_wr,
  output [7:0]  io_dmem_req_bits_msk,
  input         io_dmem_resp_valid,
  input  [63:0] io_dmem_resp_bits_data,
  output        io_inst_mmio,
  output        io_data_mmio
);
`ifdef RANDOMIZE_REG_INIT
  reg [63:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [63:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [63:0] _RAND_4;
  reg [63:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [63:0] _RAND_7;
  reg [31:0] _RAND_8;
  reg [63:0] _RAND_9;
  reg [63:0] _RAND_10;
  reg [63:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
  reg [31:0] _RAND_15;
  reg [31:0] _RAND_16;
  reg [31:0] _RAND_17;
  reg [31:0] _RAND_18;
  reg [31:0] _RAND_19;
  reg [31:0] _RAND_20;
  reg [63:0] _RAND_21;
  reg [63:0] _RAND_22;
  reg [31:0] _RAND_23;
  reg [31:0] _RAND_24;
  reg [31:0] _RAND_25;
  reg [31:0] _RAND_26;
  reg [31:0] _RAND_27;
  reg [63:0] _RAND_28;
  reg [63:0] _RAND_29;
  reg [31:0] _RAND_30;
  reg [63:0] _RAND_31;
  reg [31:0] _RAND_32;
  reg [63:0] _RAND_33;
  reg [31:0] _RAND_34;
`endif // RANDOMIZE_REG_INIT
  wire  regfile_clock; // @[dpath.scala 184:23]
  wire [4:0] regfile_io_rs1_addr; // @[dpath.scala 184:23]
  wire [63:0] regfile_io_rs1_data; // @[dpath.scala 184:23]
  wire [4:0] regfile_io_rs2_addr; // @[dpath.scala 184:23]
  wire [63:0] regfile_io_rs2_data; // @[dpath.scala 184:23]
  wire [4:0] regfile_io_waddr; // @[dpath.scala 184:23]
  wire [63:0] regfile_io_wdata; // @[dpath.scala 184:23]
  wire  regfile_io_wen; // @[dpath.scala 184:23]
  wire  alu_clock; // @[dpath.scala 318:19]
  wire  alu_reset; // @[dpath.scala 318:19]
  wire [63:0] alu_io_src1; // @[dpath.scala 318:19]
  wire [63:0] alu_io_src2; // @[dpath.scala 318:19]
  wire [4:0] alu_io_op; // @[dpath.scala 318:19]
  wire [63:0] alu_io_res; // @[dpath.scala 318:19]
  wire  alu_io_stall; // @[dpath.scala 318:19]
  reg [63:0] if_reg_pc; // @[dpath.scala 39:37]
  reg  inst_valid; // @[dpath.scala 40:37]
  reg [63:0] imm_data; // @[dpath.scala 41:37]
  reg  dec_reg_valid; // @[dpath.scala 44:37]
  reg [63:0] dec_reg_inst; // @[dpath.scala 45:37]
  reg [63:0] dec_reg_pc; // @[dpath.scala 46:37]
  reg  exe_reg_valid; // @[dpath.scala 48:37]
  reg [63:0] exe_reg_pc; // @[dpath.scala 50:37]
  reg [4:0] exe_reg_wbaddr; // @[dpath.scala 51:33]
  reg [63:0] exe_alu_op1; // @[dpath.scala 54:33]
  reg [63:0] brjmp_offset; // @[dpath.scala 55:33]
  reg [63:0] exe_reg_rs2_data; // @[dpath.scala 56:33]
  reg [3:0] exe_reg_ctrl_br_type; // @[dpath.scala 57:37]
  reg [4:0] exe_reg_ctrl_alu_fun; // @[dpath.scala 59:33]
  reg [2:0] exe_reg_ctrl_wb_sel; // @[dpath.scala 60:33]
  reg  exe_reg_ctrl_rf_wen; // @[dpath.scala 61:37]
  reg  exe_reg_ctrl_mem_val; // @[dpath.scala 62:37]
  reg [1:0] exe_reg_ctrl_mem_fcn; // @[dpath.scala 63:37]
  reg [7:0] exe_reg_ctrl_mem_typ; // @[dpath.scala 64:37]
  reg [2:0] exe_reg_ctrl_mem_wid; // @[dpath.scala 65:37]
  reg  mem_reg_valid; // @[dpath.scala 69:37]
  reg [63:0] mem_reg_pc; // @[dpath.scala 70:33]
  reg [63:0] mem_reg_alu_out; // @[dpath.scala 72:33]
  reg [4:0] mem_reg_wbaddr; // @[dpath.scala 73:33]
  reg  mem_reg_ctrl_rf_wen; // @[dpath.scala 79:37]
  reg [2:0] mem_reg_ctrl_wb_sel; // @[dpath.scala 83:33]
  reg [2:0] mem_reg_ctrl_mem_wid; // @[dpath.scala 84:37]
  reg  data_valid; // @[dpath.scala 86:37]
  reg [63:0] dmm_data_cache; // @[dpath.scala 87:37]
  reg [63:0] dmm_data; // @[dpath.scala 88:37]
  reg  wb_reg_valid; // @[dpath.scala 91:37]
  reg [63:0] wb_reg_pc; // @[dpath.scala 92:33]
  reg [4:0] wb_reg_wbaddr; // @[dpath.scala 94:33]
  reg [63:0] wb_reg_wbdata; // @[dpath.scala 95:33]
  reg  wb_reg_ctrl_rf_wen; // @[dpath.scala 96:37]
  wire  _T = ~io_ctl_dec_stall; // @[dpath.scala 106:10]
  wire  _T_1 = ~io_ctl_full_stall; // @[dpath.scala 106:31]
  wire  _T_2 = _T & _T_1; // @[dpath.scala 106:28]
  wire  alu_stall = alu_io_stall; // @[dpath.scala 104:23 dpath.scala 322:13]
  wire  _T_3 = ~alu_stall; // @[dpath.scala 106:53]
  wire  _T_4 = _T_2 & _T_3; // @[dpath.scala 106:50]
  wire  _T_7 = io_ctl_exe_pc_sel == 2'h0; // @[dpath.scala 113:39]
  wire [63:0] if_pc_plus4 = if_reg_pc + 64'h4; // @[dpath.scala 111:31]
  wire  _T_8 = io_ctl_exe_pc_sel == 2'h1; // @[dpath.scala 114:39]
  wire [63:0] exe_brjmp_target = exe_reg_pc + brjmp_offset; // @[dpath.scala 330:37]
  wire  _T_9 = io_ctl_exe_pc_sel == 2'h2; // @[dpath.scala 115:39]
  wire [63:0] exe_adder_out = exe_alu_op1 + brjmp_offset; // @[dpath.scala 327:36]
  wire  _GEN_1 = io_imem_resp_valid | inst_valid; // @[dpath.scala 126:38]
  wire [31:0] if_inst = if_reg_pc[2] ? imm_data[63:32] : imm_data[31:0]; // @[dpath.scala 139:20]
  wire  _GEN_10 = _T_4 ? 1'h0 : data_valid; // @[dpath.scala 147:3]
  wire [4:0] dec_rs1_addr = dec_reg_inst[19:15]; // @[dpath.scala 178:34]
  wire [4:0] dec_rs2_addr = dec_reg_inst[24:20]; // @[dpath.scala 179:34]
  wire [4:0] dec_wbaddr = dec_reg_inst[11:7]; // @[dpath.scala 180:34]
  wire [11:0] imm_itype = dec_reg_inst[31:20]; // @[dpath.scala 195:31]
  wire [11:0] imm_stype = {dec_reg_inst[31:25],dec_wbaddr}; // @[Cat.scala 29:58]
  wire [11:0] imm_sbtype = {dec_reg_inst[31],dec_reg_inst[7],dec_reg_inst[30:25],dec_reg_inst[11:8]}; // @[Cat.scala 29:58]
  wire [19:0] imm_utype = dec_reg_inst[31:12]; // @[dpath.scala 198:31]
  wire [19:0] imm_ujtype = {dec_reg_inst[31],dec_reg_inst[19:12],dec_reg_inst[20],dec_reg_inst[30:21]}; // @[Cat.scala 29:58]
  wire [31:0] imm_z = {27'h0,dec_rs1_addr}; // @[Cat.scala 29:58]
  wire [51:0] _T_46 = imm_itype[11] ? 52'hfffffffffffff : 52'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_itype_sext = {_T_46,imm_itype}; // @[Cat.scala 29:58]
  wire [51:0] _T_49 = imm_stype[11] ? 52'hfffffffffffff : 52'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_stype_sext = {_T_49,dec_reg_inst[31:25],dec_wbaddr}; // @[Cat.scala 29:58]
  wire [50:0] _T_52 = imm_sbtype[11] ? 51'h7ffffffffffff : 51'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_sbtype_sext = {_T_52,dec_reg_inst[31],dec_reg_inst[7],dec_reg_inst[30:25],dec_reg_inst[11:8],1'h0}; // @[Cat.scala 29:58]
  wire [31:0] _T_56 = imm_utype[19] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_utype_sext = {_T_56,imm_utype,12'h0}; // @[Cat.scala 29:58]
  wire [42:0] _T_61 = imm_ujtype[19] ? 43'h7ffffffffff : 43'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_ujtype_sext = {_T_61,dec_reg_inst[31],dec_reg_inst[19:12],dec_reg_inst[20],dec_reg_inst[30:21],1'h0}; // @[Cat.scala 29:58]
  wire  _T_63 = io_ctl_op2_sel == 3'h0; // @[dpath.scala 211:21]
  wire  _T_64 = io_ctl_op2_sel == 3'h1; // @[dpath.scala 212:21]
  wire  _T_65 = io_ctl_op2_sel == 3'h2; // @[dpath.scala 213:21]
  wire  _T_66 = io_ctl_op2_sel == 3'h3; // @[dpath.scala 214:21]
  wire  _T_67 = io_ctl_op2_sel == 3'h4; // @[dpath.scala 215:21]
  wire  _T_68 = io_ctl_op2_sel == 3'h5; // @[dpath.scala 216:21]
  wire  _T_74 = exe_reg_wbaddr == dec_rs1_addr; // @[dpath.scala 229:22]
  wire  _T_75 = dec_rs1_addr != 5'h0; // @[dpath.scala 229:57]
  wire  _T_76 = _T_74 & _T_75; // @[dpath.scala 229:40]
  wire  _T_77 = _T_76 & exe_reg_ctrl_rf_wen; // @[dpath.scala 229:66]
  wire  _T_78 = mem_reg_wbaddr == dec_rs1_addr; // @[dpath.scala 230:22]
  wire  _T_80 = _T_78 & _T_75; // @[dpath.scala 230:40]
  wire  _T_81 = _T_80 & mem_reg_ctrl_rf_wen; // @[dpath.scala 230:66]
  wire  _T_82 = wb_reg_wbaddr == dec_rs1_addr; // @[dpath.scala 231:22]
  wire  _T_84 = _T_82 & _T_75; // @[dpath.scala 231:40]
  wire  _T_85 = _T_84 & wb_reg_ctrl_rf_wen; // @[dpath.scala 231:66]
  wire [63:0] _T_86 = _T_85 ? wb_reg_wbdata : regfile_io_rs1_data; // @[Mux.scala 98:16]
  wire  _T_213 = mem_reg_ctrl_wb_sel == 3'h1; // @[dpath.scala 417:26]
  wire  _T_176 = mem_reg_ctrl_mem_wid == 3'h0; // @[dpath.scala 406:27]
  wire [55:0] _T_179 = dmm_data[7] ? 56'hffffffffffffff : 56'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _T_181 = {_T_179,dmm_data[7:0]}; // @[Cat.scala 29:58]
  wire  _T_182 = mem_reg_ctrl_mem_wid == 3'h1; // @[dpath.scala 407:27]
  wire [63:0] _T_185 = {56'h0,dmm_data[7:0]}; // @[Cat.scala 29:58]
  wire  _T_186 = mem_reg_ctrl_mem_wid == 3'h2; // @[dpath.scala 408:27]
  wire [47:0] _T_189 = dmm_data[15] ? 48'hffffffffffff : 48'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _T_191 = {_T_189,dmm_data[15:0]}; // @[Cat.scala 29:58]
  wire  _T_192 = mem_reg_ctrl_mem_wid == 3'h3; // @[dpath.scala 409:27]
  wire [63:0] _T_195 = {48'h0,dmm_data[15:0]}; // @[Cat.scala 29:58]
  wire  _T_196 = mem_reg_ctrl_mem_wid == 3'h4; // @[dpath.scala 410:27]
  wire [31:0] _T_199 = dmm_data[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _T_201 = {_T_199,dmm_data[31:0]}; // @[Cat.scala 29:58]
  wire  _T_202 = mem_reg_ctrl_mem_wid == 3'h5; // @[dpath.scala 411:27]
  wire [63:0] _T_205 = {32'h0,dmm_data[31:0]}; // @[Cat.scala 29:58]
  wire [63:0] _T_208 = _T_202 ? _T_205 : dmm_data; // @[Mux.scala 98:16]
  wire [63:0] _T_209 = _T_196 ? _T_201 : _T_208; // @[Mux.scala 98:16]
  wire [63:0] _T_210 = _T_192 ? _T_195 : _T_209; // @[Mux.scala 98:16]
  wire [63:0] _T_211 = _T_186 ? _T_191 : _T_210; // @[Mux.scala 98:16]
  wire [63:0] _T_212 = _T_182 ? _T_185 : _T_211; // @[Mux.scala 98:16]
  wire [63:0] mem_data = _T_176 ? _T_181 : _T_212; // @[Mux.scala 98:16]
  wire [63:0] mem_wbdata = _T_213 ? mem_data : mem_reg_alu_out; // @[Mux.scala 98:16]
  wire [63:0] _T_87 = _T_81 ? mem_wbdata : _T_86; // @[Mux.scala 98:16]
  wire  _T_148 = exe_reg_ctrl_wb_sel == 3'h4; // @[dpath.scala 324:28]
  wire [31:0] _T_151 = alu_io_res[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _T_153 = {_T_151,alu_io_res[31:0]}; // @[Cat.scala 29:58]
  wire [63:0] exe_alu_out = _T_148 ? _T_153 : alu_io_res; // @[Mux.scala 98:16]
  wire [63:0] dec_rs1_data = _T_77 ? exe_alu_out : _T_87; // @[Mux.scala 98:16]
  wire  _T_89 = io_ctl_op1_sel == 2'h2; // @[dpath.scala 235:21]
  wire  _T_90 = io_ctl_op1_sel == 2'h1; // @[dpath.scala 236:21]
  wire  _T_91 = io_ctl_op1_sel == 2'h3; // @[dpath.scala 237:21]
  wire [63:0] _T_94 = {32'h0,dec_rs1_data[31:0]}; // @[Cat.scala 29:58]
  wire  _T_98 = exe_reg_wbaddr == dec_rs2_addr; // @[dpath.scala 241:22]
  wire  _T_99 = dec_rs2_addr != 5'h0; // @[dpath.scala 241:57]
  wire  _T_100 = _T_98 & _T_99; // @[dpath.scala 241:40]
  wire  _T_101 = _T_100 & exe_reg_ctrl_rf_wen; // @[dpath.scala 241:66]
  wire  _T_103 = _T_101 & _T_63; // @[dpath.scala 241:89]
  wire  _T_104 = mem_reg_wbaddr == dec_rs2_addr; // @[dpath.scala 242:22]
  wire  _T_106 = _T_104 & _T_99; // @[dpath.scala 242:40]
  wire  _T_107 = _T_106 & mem_reg_ctrl_rf_wen; // @[dpath.scala 242:66]
  wire  _T_109 = _T_107 & _T_63; // @[dpath.scala 242:89]
  wire  _T_110 = wb_reg_wbaddr == dec_rs2_addr; // @[dpath.scala 243:22]
  wire  _T_112 = _T_110 & _T_99; // @[dpath.scala 243:40]
  wire  _T_113 = _T_112 & wb_reg_ctrl_rf_wen; // @[dpath.scala 243:66]
  wire  _T_115 = _T_113 & _T_63; // @[dpath.scala 243:89]
  wire  _T_135 = io_ctl_dec_stall & _T_1; // @[dpath.scala 253:27]
  wire  _T_137 = _T_135 & _T_3; // @[dpath.scala 253:49]
  wire [63:0] exe_pc_plus4 = exe_reg_pc + 64'h4; // @[dpath.scala 333:34]
  wire  _T_163 = _T_1 & _T_3; // @[dpath.scala 343:33]
  wire  _T_164 = exe_reg_ctrl_wb_sel == 3'h2; // @[dpath.scala 349:32]
  wire [5:0] _T_172 = {exe_alu_out[2:0], 3'h0}; // @[dpath.scala 399:67]
  wire [63:0] _T_173 = io_dmem_resp_bits_data >> _T_172; // @[dpath.scala 399:46]
  wire  _GEN_101 = io_dmem_resp_valid | _GEN_10; // @[dpath.scala 397:38]
  wire  _GEN_103 = _T_163 & mem_reg_valid; // @[dpath.scala 427:3]
  wire  _T_227 = exe_reg_ctrl_mem_typ == 8'h1; // @[dpath.scala 461:27]
  wire [63:0] _T_231 = {exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0]}; // @[Cat.scala 29:58]
  wire  _T_232 = exe_reg_ctrl_mem_typ == 8'h3; // @[dpath.scala 462:27]
  wire [63:0] _T_235 = {exe_reg_rs2_data[15:0],exe_reg_rs2_data[15:0],exe_reg_rs2_data[15:0],exe_reg_rs2_data[15:0]}; // @[Cat.scala 29:58]
  wire  _T_236 = exe_reg_ctrl_mem_typ == 8'hf; // @[dpath.scala 463:27]
  wire [63:0] _T_238 = {exe_reg_rs2_data[31:0],exe_reg_rs2_data[31:0]}; // @[Cat.scala 29:58]
  wire [63:0] _T_241 = _T_236 ? _T_238 : exe_reg_rs2_data; // @[Mux.scala 98:16]
  wire [63:0] _T_242 = _T_232 ? _T_235 : _T_241; // @[Mux.scala 98:16]
  wire  _T_247 = ~data_valid; // @[dpath.scala 471:52]
  wire  _T_248 = exe_reg_ctrl_mem_val & _T_247; // @[dpath.scala 471:49]
  wire [1:0] _T_256 = _T_236 ? 2'h2 : 2'h3; // @[Mux.scala 98:16]
  wire [1:0] _T_257 = _T_232 ? 2'h1 : _T_256; // @[Mux.scala 98:16]
  wire [1:0] _T_258 = _T_227 ? 2'h0 : _T_257; // @[Mux.scala 98:16]
  zzy_regfile regfile ( // @[dpath.scala 184:23]
    .clock(regfile_clock),
    .io_rs1_addr(regfile_io_rs1_addr),
    .io_rs1_data(regfile_io_rs1_data),
    .io_rs2_addr(regfile_io_rs2_addr),
    .io_rs2_data(regfile_io_rs2_data),
    .io_waddr(regfile_io_waddr),
    .io_wdata(regfile_io_wdata),
    .io_wen(regfile_io_wen)
  );
  zzy_alu alu ( // @[dpath.scala 318:19]
    .clock(alu_clock),
    .reset(alu_reset),
    .io_src1(alu_io_src1),
    .io_src2(alu_io_src2),
    .io_op(alu_io_op),
    .io_res(alu_io_res),
    .io_stall(alu_io_stall)
  );
  assign io_dat_dec_inst = dec_reg_inst; // @[dpath.scala 449:22]
  assign io_dat_exe_br_eq = exe_alu_op1 == exe_reg_rs2_data; // @[dpath.scala 450:22]
  assign io_dat_exe_br_lt = $signed(exe_alu_op1) < $signed(exe_reg_rs2_data); // @[dpath.scala 451:22]
  assign io_dat_exe_br_ltu = exe_alu_op1 < exe_reg_rs2_data; // @[dpath.scala 452:22]
  assign io_dat_exe_br_type = exe_reg_ctrl_br_type; // @[dpath.scala 453:22]
  assign io_dat_exe_ctrl_dmem_val = exe_reg_ctrl_mem_val; // @[dpath.scala 455:28]
  assign io_dat_inst_valid = inst_valid; // @[dpath.scala 457:21]
  assign io_dat_data_valid = data_valid; // @[dpath.scala 458:21]
  assign io_imem_req_valid = ~inst_valid; // @[dpath.scala 131:27]
  assign io_imem_req_bits_addr = if_reg_pc; // @[dpath.scala 134:27]
  assign io_dmem_req_valid = _T_248 & inst_valid; // @[dpath.scala 471:25]
  assign io_dmem_req_bits_addr = _T_148 ? _T_153 : alu_io_res; // @[dpath.scala 475:25]
  assign io_dmem_req_bits_data = _T_227 ? _T_231 : _T_242; // @[dpath.scala 476:25]
  assign io_dmem_req_bits_wr = exe_reg_ctrl_mem_fcn == 2'h2; // @[dpath.scala 477:25]
  assign io_dmem_req_bits_msk = {{6'd0}, _T_258}; // @[dpath.scala 478:25]
  assign io_inst_mmio = if_reg_pc < 64'h80000000; // @[dpath.scala 124:16]
  assign io_data_mmio = exe_alu_out < 64'h80000000; // @[dpath.scala 469:16]
  assign regfile_clock = clock;
  assign regfile_io_rs1_addr = dec_reg_inst[19:15]; // @[dpath.scala 185:23]
  assign regfile_io_rs2_addr = dec_reg_inst[24:20]; // @[dpath.scala 186:23]
  assign regfile_io_waddr = wb_reg_wbaddr; // @[dpath.scala 189:20]
  assign regfile_io_wdata = wb_reg_wbdata; // @[dpath.scala 190:20]
  assign regfile_io_wen = wb_reg_ctrl_rf_wen; // @[dpath.scala 192:20]
  assign alu_clock = clock;
  assign alu_reset = reset;
  assign alu_io_src1 = exe_alu_op1; // @[dpath.scala 320:15]
  assign alu_io_src2 = brjmp_offset; // @[dpath.scala 321:15]
  assign alu_io_op = exe_reg_ctrl_alu_fun; // @[dpath.scala 319:13]
`ifdef RANDOMIZE_GARBAGE_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_INVALID_ASSIGN
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_REG_INIT
`define RANDOMIZE
`endif
`ifdef RANDOMIZE_MEM_INIT
`define RANDOMIZE
`endif
`ifndef RANDOM
`define RANDOM $random
`endif
`ifdef RANDOMIZE_MEM_INIT
  integer initvar;
`endif
`ifndef SYNTHESIS
`ifdef FIRRTL_BEFORE_INITIAL
`FIRRTL_BEFORE_INITIAL
`endif
initial begin
  `ifdef RANDOMIZE
    `ifdef INIT_RANDOM
      `INIT_RANDOM
    `endif
    `ifndef VERILATOR
      `ifdef RANDOMIZE_DELAY
        #`RANDOMIZE_DELAY begin end
      `else
        #0.002 begin end
      `endif
    `endif
`ifdef RANDOMIZE_REG_INIT
  _RAND_0 = {2{`RANDOM}};
  if_reg_pc = _RAND_0[63:0];
  _RAND_1 = {1{`RANDOM}};
  inst_valid = _RAND_1[0:0];
  _RAND_2 = {2{`RANDOM}};
  imm_data = _RAND_2[63:0];
  _RAND_3 = {1{`RANDOM}};
  dec_reg_valid = _RAND_3[0:0];
  _RAND_4 = {2{`RANDOM}};
  dec_reg_inst = _RAND_4[63:0];
  _RAND_5 = {2{`RANDOM}};
  dec_reg_pc = _RAND_5[63:0];
  _RAND_6 = {1{`RANDOM}};
  exe_reg_valid = _RAND_6[0:0];
  _RAND_7 = {2{`RANDOM}};
  exe_reg_pc = _RAND_7[63:0];
  _RAND_8 = {1{`RANDOM}};
  exe_reg_wbaddr = _RAND_8[4:0];
  _RAND_9 = {2{`RANDOM}};
  exe_alu_op1 = _RAND_9[63:0];
  _RAND_10 = {2{`RANDOM}};
  brjmp_offset = _RAND_10[63:0];
  _RAND_11 = {2{`RANDOM}};
  exe_reg_rs2_data = _RAND_11[63:0];
  _RAND_12 = {1{`RANDOM}};
  exe_reg_ctrl_br_type = _RAND_12[3:0];
  _RAND_13 = {1{`RANDOM}};
  exe_reg_ctrl_alu_fun = _RAND_13[4:0];
  _RAND_14 = {1{`RANDOM}};
  exe_reg_ctrl_wb_sel = _RAND_14[2:0];
  _RAND_15 = {1{`RANDOM}};
  exe_reg_ctrl_rf_wen = _RAND_15[0:0];
  _RAND_16 = {1{`RANDOM}};
  exe_reg_ctrl_mem_val = _RAND_16[0:0];
  _RAND_17 = {1{`RANDOM}};
  exe_reg_ctrl_mem_fcn = _RAND_17[1:0];
  _RAND_18 = {1{`RANDOM}};
  exe_reg_ctrl_mem_typ = _RAND_18[7:0];
  _RAND_19 = {1{`RANDOM}};
  exe_reg_ctrl_mem_wid = _RAND_19[2:0];
  _RAND_20 = {1{`RANDOM}};
  mem_reg_valid = _RAND_20[0:0];
  _RAND_21 = {2{`RANDOM}};
  mem_reg_pc = _RAND_21[63:0];
  _RAND_22 = {2{`RANDOM}};
  mem_reg_alu_out = _RAND_22[63:0];
  _RAND_23 = {1{`RANDOM}};
  mem_reg_wbaddr = _RAND_23[4:0];
  _RAND_24 = {1{`RANDOM}};
  mem_reg_ctrl_rf_wen = _RAND_24[0:0];
  _RAND_25 = {1{`RANDOM}};
  mem_reg_ctrl_wb_sel = _RAND_25[2:0];
  _RAND_26 = {1{`RANDOM}};
  mem_reg_ctrl_mem_wid = _RAND_26[2:0];
  _RAND_27 = {1{`RANDOM}};
  data_valid = _RAND_27[0:0];
  _RAND_28 = {2{`RANDOM}};
  dmm_data_cache = _RAND_28[63:0];
  _RAND_29 = {2{`RANDOM}};
  dmm_data = _RAND_29[63:0];
  _RAND_30 = {1{`RANDOM}};
  wb_reg_valid = _RAND_30[0:0];
  _RAND_31 = {2{`RANDOM}};
  wb_reg_pc = _RAND_31[63:0];
  _RAND_32 = {1{`RANDOM}};
  wb_reg_wbaddr = _RAND_32[4:0];
  _RAND_33 = {2{`RANDOM}};
  wb_reg_wbdata = _RAND_33[63:0];
  _RAND_34 = {1{`RANDOM}};
  wb_reg_ctrl_rf_wen = _RAND_34[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
  always @(posedge clock) begin
    if (reset) begin
      if_reg_pc <= 64'h40000000;
    end else if (_T_4) begin
      if (_T_7) begin
        if_reg_pc <= if_pc_plus4;
      end else if (_T_8) begin
        if_reg_pc <= exe_brjmp_target;
      end else if (_T_9) begin
        if_reg_pc <= exe_adder_out;
      end else begin
        if_reg_pc <= 64'h4033;
      end
    end
    if (reset) begin
      inst_valid <= 1'h0;
    end else if (_T_4) begin
      inst_valid <= 1'h0;
    end else begin
      inst_valid <= _GEN_1;
    end
    if (reset) begin
      imm_data <= 64'h0;
    end else if (_T_4) begin
      imm_data <= 64'h0;
    end else if (io_imem_resp_valid) begin
      imm_data <= io_imem_resp_bits_data;
    end
    if (reset) begin
      dec_reg_valid <= 1'h0;
    end else if (_T_4) begin
      if (io_ctl_if_kill) begin
        dec_reg_valid <= 1'h0;
      end else begin
        dec_reg_valid <= 1'h1;
      end
    end
    if (reset) begin
      dec_reg_inst <= 64'h4033;
    end else if (_T_4) begin
      if (io_ctl_if_kill) begin
        dec_reg_inst <= 64'h4033;
      end else begin
        dec_reg_inst <= {{32'd0}, if_inst};
      end
    end
    if (reset) begin
      dec_reg_pc <= 64'h0;
    end else if (_T_4) begin
      dec_reg_pc <= if_reg_pc;
    end
    if (reset) begin
      exe_reg_valid <= 1'h0;
    end else if (_T_137) begin
      exe_reg_valid <= 1'h0;
    end else if (_T_4) begin
      if (io_ctl_dec_kill) begin
        exe_reg_valid <= 1'h0;
      end else begin
        exe_reg_valid <= dec_reg_valid;
      end
    end
    if (reset) begin
      exe_reg_pc <= 64'h0;
    end else if (!(_T_137)) begin
      if (_T_4) begin
        exe_reg_pc <= dec_reg_pc;
      end
    end
    if (_T_137) begin
      exe_reg_wbaddr <= 5'h0;
    end else if (_T_4) begin
      if (io_ctl_dec_kill) begin
        exe_reg_wbaddr <= 5'h0;
      end else begin
        exe_reg_wbaddr <= dec_wbaddr;
      end
    end
    if (!(_T_137)) begin
      if (_T_4) begin
        if (_T_89) begin
          exe_alu_op1 <= {{32'd0}, imm_z};
        end else if (_T_90) begin
          exe_alu_op1 <= dec_reg_pc;
        end else if (_T_91) begin
          exe_alu_op1 <= _T_94;
        end else if (_T_77) begin
          if (_T_148) begin
            exe_alu_op1 <= _T_153;
          end else begin
            exe_alu_op1 <= alu_io_res;
          end
        end else if (_T_81) begin
          if (_T_213) begin
            if (_T_176) begin
              exe_alu_op1 <= _T_181;
            end else if (_T_182) begin
              exe_alu_op1 <= _T_185;
            end else if (_T_186) begin
              exe_alu_op1 <= _T_191;
            end else if (_T_192) begin
              exe_alu_op1 <= _T_195;
            end else if (_T_196) begin
              exe_alu_op1 <= _T_201;
            end else if (_T_202) begin
              exe_alu_op1 <= _T_205;
            end else begin
              exe_alu_op1 <= dmm_data;
            end
          end else begin
            exe_alu_op1 <= mem_reg_alu_out;
          end
        end else if (_T_85) begin
          exe_alu_op1 <= wb_reg_wbdata;
        end else begin
          exe_alu_op1 <= regfile_io_rs1_data;
        end
      end
    end
    if (!(_T_137)) begin
      if (_T_4) begin
        if (_T_103) begin
          if (_T_148) begin
            brjmp_offset <= _T_153;
          end else begin
            brjmp_offset <= alu_io_res;
          end
        end else if (_T_109) begin
          if (_T_213) begin
            if (_T_176) begin
              brjmp_offset <= _T_181;
            end else if (_T_182) begin
              brjmp_offset <= _T_185;
            end else if (_T_186) begin
              brjmp_offset <= _T_191;
            end else if (_T_192) begin
              brjmp_offset <= _T_195;
            end else if (_T_196) begin
              brjmp_offset <= _T_201;
            end else if (_T_202) begin
              brjmp_offset <= _T_205;
            end else begin
              brjmp_offset <= dmm_data;
            end
          end else begin
            brjmp_offset <= mem_reg_alu_out;
          end
        end else if (_T_115) begin
          brjmp_offset <= wb_reg_wbdata;
        end else if (_T_63) begin
          brjmp_offset <= regfile_io_rs2_data;
        end else if (_T_64) begin
          brjmp_offset <= imm_itype_sext;
        end else if (_T_65) begin
          brjmp_offset <= imm_stype_sext;
        end else if (_T_66) begin
          brjmp_offset <= imm_sbtype_sext;
        end else if (_T_67) begin
          brjmp_offset <= imm_utype_sext;
        end else if (_T_68) begin
          brjmp_offset <= imm_ujtype_sext;
        end else begin
          brjmp_offset <= 64'h0;
        end
      end
    end
    if (!(_T_137)) begin
      if (_T_4) begin
        if (_T_101) begin
          if (_T_148) begin
            exe_reg_rs2_data <= _T_153;
          end else begin
            exe_reg_rs2_data <= alu_io_res;
          end
        end else if (_T_107) begin
          if (_T_213) begin
            if (_T_176) begin
              exe_reg_rs2_data <= _T_181;
            end else if (_T_182) begin
              exe_reg_rs2_data <= _T_185;
            end else if (_T_186) begin
              exe_reg_rs2_data <= _T_191;
            end else if (_T_192) begin
              exe_reg_rs2_data <= _T_195;
            end else if (_T_196) begin
              exe_reg_rs2_data <= _T_201;
            end else if (_T_202) begin
              exe_reg_rs2_data <= _T_205;
            end else begin
              exe_reg_rs2_data <= dmm_data;
            end
          end else begin
            exe_reg_rs2_data <= mem_reg_alu_out;
          end
        end else if (_T_113) begin
          exe_reg_rs2_data <= wb_reg_wbdata;
        end else begin
          exe_reg_rs2_data <= regfile_io_rs2_data;
        end
      end
    end
    if (reset) begin
      exe_reg_ctrl_br_type <= 4'h0;
    end else if (_T_137) begin
      exe_reg_ctrl_br_type <= 4'h0;
    end else if (_T_4) begin
      if (io_ctl_dec_kill) begin
        exe_reg_ctrl_br_type <= 4'h0;
      end else begin
        exe_reg_ctrl_br_type <= io_ctl_br_type;
      end
    end
    if (!(_T_137)) begin
      if (_T_4) begin
        exe_reg_ctrl_alu_fun <= io_ctl_alu_fun;
      end
    end
    if (!(_T_137)) begin
      if (_T_4) begin
        exe_reg_ctrl_wb_sel <= io_ctl_wb_sel;
      end
    end
    if (reset) begin
      exe_reg_ctrl_rf_wen <= 1'h0;
    end else if (_T_137) begin
      exe_reg_ctrl_rf_wen <= 1'h0;
    end else if (_T_4) begin
      if (io_ctl_dec_kill) begin
        exe_reg_ctrl_rf_wen <= 1'h0;
      end else begin
        exe_reg_ctrl_rf_wen <= io_ctl_rf_wen;
      end
    end
    if (reset) begin
      exe_reg_ctrl_mem_val <= 1'h0;
    end else if (_T_137) begin
      exe_reg_ctrl_mem_val <= 1'h0;
    end else if (_T_4) begin
      if (io_ctl_dec_kill) begin
        exe_reg_ctrl_mem_val <= 1'h0;
      end else begin
        exe_reg_ctrl_mem_val <= io_ctl_mem_val;
      end
    end
    if (reset) begin
      exe_reg_ctrl_mem_fcn <= 2'h0;
    end else if (_T_137) begin
      exe_reg_ctrl_mem_fcn <= 2'h0;
    end else if (_T_4) begin
      if (io_ctl_dec_kill) begin
        exe_reg_ctrl_mem_fcn <= 2'h0;
      end else begin
        exe_reg_ctrl_mem_fcn <= io_ctl_mem_fcn;
      end
    end
    if (reset) begin
      exe_reg_ctrl_mem_typ <= 8'hff;
    end else if (!(_T_137)) begin
      if (_T_4) begin
        if (!(io_ctl_dec_kill)) begin
          exe_reg_ctrl_mem_typ <= io_ctl_mem_typ;
        end
      end
    end
    if (reset) begin
      exe_reg_ctrl_mem_wid <= 3'h0;
    end else if (_T_137) begin
      exe_reg_ctrl_mem_wid <= 3'h0;
    end else if (_T_4) begin
      if (io_ctl_dec_kill) begin
        exe_reg_ctrl_mem_wid <= 3'h0;
      end else begin
        exe_reg_ctrl_mem_wid <= io_ctl_mem_wid;
      end
    end
    if (reset) begin
      mem_reg_valid <= 1'h0;
    end else if (_T_163) begin
      mem_reg_valid <= exe_reg_valid;
    end
    if (_T_163) begin
      mem_reg_pc <= exe_reg_pc;
    end
    if (_T_163) begin
      if (_T_164) begin
        mem_reg_alu_out <= exe_pc_plus4;
      end else if (_T_148) begin
        mem_reg_alu_out <= _T_153;
      end else begin
        mem_reg_alu_out <= alu_io_res;
      end
    end
    if (_T_163) begin
      mem_reg_wbaddr <= exe_reg_wbaddr;
    end
    if (reset) begin
      mem_reg_ctrl_rf_wen <= 1'h0;
    end else if (_T_163) begin
      mem_reg_ctrl_rf_wen <= exe_reg_ctrl_rf_wen;
    end
    if (_T_163) begin
      mem_reg_ctrl_wb_sel <= exe_reg_ctrl_wb_sel;
    end
    if (reset) begin
      mem_reg_ctrl_mem_wid <= 3'h0;
    end else if (_T_163) begin
      mem_reg_ctrl_mem_wid <= exe_reg_ctrl_mem_wid;
    end
    if (reset) begin
      data_valid <= 1'h0;
    end else begin
      data_valid <= _GEN_101;
    end
    if (reset) begin
      dmm_data_cache <= 64'h0;
    end else if (io_dmem_resp_valid) begin
      dmm_data_cache <= _T_173;
    end
    if (reset) begin
      dmm_data <= 64'h0;
    end else if (_T_163) begin
      dmm_data <= dmm_data_cache;
    end
    if (reset) begin
      wb_reg_valid <= 1'h0;
    end else begin
      wb_reg_valid <= _GEN_103;
    end
    if (_T_163) begin
      wb_reg_pc <= mem_reg_pc;
    end
    if (_T_163) begin
      wb_reg_wbaddr <= mem_reg_wbaddr;
    end
    if (_T_163) begin
      if (_T_213) begin
        if (_T_176) begin
          wb_reg_wbdata <= _T_181;
        end else if (_T_182) begin
          wb_reg_wbdata <= _T_185;
        end else if (_T_186) begin
          wb_reg_wbdata <= _T_191;
        end else if (_T_192) begin
          wb_reg_wbdata <= _T_195;
        end else if (_T_196) begin
          wb_reg_wbdata <= _T_201;
        end else if (_T_202) begin
          wb_reg_wbdata <= _T_205;
        end else begin
          wb_reg_wbdata <= dmm_data;
        end
      end else begin
        wb_reg_wbdata <= mem_reg_alu_out;
      end
    end
    if (reset) begin
      wb_reg_ctrl_rf_wen <= 1'h0;
    end else if (_T_163) begin
      wb_reg_ctrl_rf_wen <= mem_reg_ctrl_rf_wen;
    end
  end
endmodule
module ysyx_zzy(
  input         clock,
  input         reset,
  output [7:0]  io_mem_awid,
  output [31:0] io_mem_awaddr,
  output [7:0]  io_mem_awlen,
  output [2:0]  io_mem_awsize,
  output [1:0]  io_mem_awburst,
  output        io_mem_awlock,
  output [3:0]  io_mem_awcache,
  output [2:0]  io_mem_awprot,
  output        io_mem_awvalid,
  input         io_mem_awready,
  input  [3:0]  io_mem_awqos,
  input         io_mem_awuser,
  output [7:0]  io_mem_wid,
  output [63:0] io_mem_wdata,
  output [7:0]  io_mem_wstrb,
  output        io_mem_wlast,
  output        io_mem_wvalid,
  input         io_mem_wready,
  input  [7:0]  io_mem_bid,
  input  [1:0]  io_mem_bresp,
  input         io_mem_bvalid,
  output        io_mem_bready,
  output [7:0]  io_mem_arid,
  output [31:0] io_mem_araddr,
  output [7:0]  io_mem_arlen,
  output [2:0]  io_mem_arsize,
  output [1:0]  io_mem_arburst,
  output        io_mem_arlock,
  output [3:0]  io_mem_arcache,
  output [2:0]  io_mem_arprot,
  output        io_mem_arvalid,
  input         io_mem_arready,
  input         io_mem_aruser,
  input  [3:0]  io_mem_arqos,
  input  [7:0]  io_mem_rid,
  input  [63:0] io_mem_rdata,
  input  [1:0]  io_mem_rresp,
  input         io_mem_rlast,
  input         io_mem_rvalid,
  output        io_mem_rready,
  output [31:0] io_mmio_awaddr,
  output [2:0]  io_mmio_awprot,
  output        io_mmio_awvalid,
  input         io_mmio_awready,
  output [2:0]  io_mmio_awsize,
  output [63:0] io_mmio_wdata,
  output [7:0]  io_mmio_wstrb,
  output        io_mmio_wvalid,
  input         io_mmio_wready,
  input  [1:0]  io_mmio_bresp,
  input         io_mmio_bvalid,
  output        io_mmio_bready,
  output [31:0] io_mmio_araddr,
  output [2:0]  io_mmio_arprot,
  output        io_mmio_arvalid,
  input         io_mmio_arready,
  output [2:0]  io_mmio_arsize,
  input  [63:0] io_mmio_rdata,
  input  [1:0]  io_mmio_rresp,
  input         io_mmio_rvalid,
  output        io_mmio_rready,
  input         io_mtip,
  input         io_meip
);
  wire  cpath_clock; // @[ysyx_zzy.scala 20:21]
  wire  cpath_reset; // @[ysyx_zzy.scala 20:21]
  wire [63:0] cpath_io_dat_dec_inst; // @[ysyx_zzy.scala 20:21]
  wire  cpath_io_dat_exe_br_eq; // @[ysyx_zzy.scala 20:21]
  wire  cpath_io_dat_exe_br_lt; // @[ysyx_zzy.scala 20:21]
  wire  cpath_io_dat_exe_br_ltu; // @[ysyx_zzy.scala 20:21]
  wire [3:0] cpath_io_dat_exe_br_type; // @[ysyx_zzy.scala 20:21]
  wire  cpath_io_dat_exe_ctrl_dmem_val; // @[ysyx_zzy.scala 20:21]
  wire  cpath_io_dat_inst_valid; // @[ysyx_zzy.scala 20:21]
  wire  cpath_io_dat_data_valid; // @[ysyx_zzy.scala 20:21]
  wire  cpath_io_ctl_dec_stall; // @[ysyx_zzy.scala 20:21]
  wire  cpath_io_ctl_full_stall; // @[ysyx_zzy.scala 20:21]
  wire [1:0] cpath_io_ctl_exe_pc_sel; // @[ysyx_zzy.scala 20:21]
  wire [3:0] cpath_io_ctl_br_type; // @[ysyx_zzy.scala 20:21]
  wire  cpath_io_ctl_if_kill; // @[ysyx_zzy.scala 20:21]
  wire  cpath_io_ctl_dec_kill; // @[ysyx_zzy.scala 20:21]
  wire [1:0] cpath_io_ctl_op1_sel; // @[ysyx_zzy.scala 20:21]
  wire [2:0] cpath_io_ctl_op2_sel; // @[ysyx_zzy.scala 20:21]
  wire [4:0] cpath_io_ctl_alu_fun; // @[ysyx_zzy.scala 20:21]
  wire [2:0] cpath_io_ctl_wb_sel; // @[ysyx_zzy.scala 20:21]
  wire  cpath_io_ctl_rf_wen; // @[ysyx_zzy.scala 20:21]
  wire  cpath_io_ctl_mem_val; // @[ysyx_zzy.scala 20:21]
  wire [1:0] cpath_io_ctl_mem_fcn; // @[ysyx_zzy.scala 20:21]
  wire [7:0] cpath_io_ctl_mem_typ; // @[ysyx_zzy.scala 20:21]
  wire [2:0] cpath_io_ctl_mem_wid; // @[ysyx_zzy.scala 20:21]
  wire  dpath_clock; // @[ysyx_zzy.scala 21:21]
  wire  dpath_reset; // @[ysyx_zzy.scala 21:21]
  wire  dpath_io_ctl_dec_stall; // @[ysyx_zzy.scala 21:21]
  wire  dpath_io_ctl_full_stall; // @[ysyx_zzy.scala 21:21]
  wire [1:0] dpath_io_ctl_exe_pc_sel; // @[ysyx_zzy.scala 21:21]
  wire [3:0] dpath_io_ctl_br_type; // @[ysyx_zzy.scala 21:21]
  wire  dpath_io_ctl_if_kill; // @[ysyx_zzy.scala 21:21]
  wire  dpath_io_ctl_dec_kill; // @[ysyx_zzy.scala 21:21]
  wire [1:0] dpath_io_ctl_op1_sel; // @[ysyx_zzy.scala 21:21]
  wire [2:0] dpath_io_ctl_op2_sel; // @[ysyx_zzy.scala 21:21]
  wire [4:0] dpath_io_ctl_alu_fun; // @[ysyx_zzy.scala 21:21]
  wire [2:0] dpath_io_ctl_wb_sel; // @[ysyx_zzy.scala 21:21]
  wire  dpath_io_ctl_rf_wen; // @[ysyx_zzy.scala 21:21]
  wire  dpath_io_ctl_mem_val; // @[ysyx_zzy.scala 21:21]
  wire [1:0] dpath_io_ctl_mem_fcn; // @[ysyx_zzy.scala 21:21]
  wire [7:0] dpath_io_ctl_mem_typ; // @[ysyx_zzy.scala 21:21]
  wire [2:0] dpath_io_ctl_mem_wid; // @[ysyx_zzy.scala 21:21]
  wire [63:0] dpath_io_dat_dec_inst; // @[ysyx_zzy.scala 21:21]
  wire  dpath_io_dat_exe_br_eq; // @[ysyx_zzy.scala 21:21]
  wire  dpath_io_dat_exe_br_lt; // @[ysyx_zzy.scala 21:21]
  wire  dpath_io_dat_exe_br_ltu; // @[ysyx_zzy.scala 21:21]
  wire [3:0] dpath_io_dat_exe_br_type; // @[ysyx_zzy.scala 21:21]
  wire  dpath_io_dat_exe_ctrl_dmem_val; // @[ysyx_zzy.scala 21:21]
  wire  dpath_io_dat_inst_valid; // @[ysyx_zzy.scala 21:21]
  wire  dpath_io_dat_data_valid; // @[ysyx_zzy.scala 21:21]
  wire  dpath_io_imem_req_valid; // @[ysyx_zzy.scala 21:21]
  wire [63:0] dpath_io_imem_req_bits_addr; // @[ysyx_zzy.scala 21:21]
  wire  dpath_io_imem_resp_valid; // @[ysyx_zzy.scala 21:21]
  wire [63:0] dpath_io_imem_resp_bits_data; // @[ysyx_zzy.scala 21:21]
  wire  dpath_io_dmem_req_valid; // @[ysyx_zzy.scala 21:21]
  wire [63:0] dpath_io_dmem_req_bits_addr; // @[ysyx_zzy.scala 21:21]
  wire [63:0] dpath_io_dmem_req_bits_data; // @[ysyx_zzy.scala 21:21]
  wire  dpath_io_dmem_req_bits_wr; // @[ysyx_zzy.scala 21:21]
  wire [7:0] dpath_io_dmem_req_bits_msk; // @[ysyx_zzy.scala 21:21]
  wire  dpath_io_dmem_resp_valid; // @[ysyx_zzy.scala 21:21]
  wire [63:0] dpath_io_dmem_resp_bits_data; // @[ysyx_zzy.scala 21:21]
  wire  dpath_io_inst_mmio; // @[ysyx_zzy.scala 21:21]
  wire  dpath_io_data_mmio; // @[ysyx_zzy.scala 21:21]
  wire [7:0] CPU_Bridge_awid; // @[ysyx_zzy.scala 26:26]
  wire [31:0] CPU_Bridge_awaddr; // @[ysyx_zzy.scala 26:26]
  wire [7:0] CPU_Bridge_awlen; // @[ysyx_zzy.scala 26:26]
  wire [2:0] CPU_Bridge_awsize; // @[ysyx_zzy.scala 26:26]
  wire [1:0] CPU_Bridge_awburst; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_awlock; // @[ysyx_zzy.scala 26:26]
  wire [3:0] CPU_Bridge_awcache; // @[ysyx_zzy.scala 26:26]
  wire [2:0] CPU_Bridge_awprot; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_awvalid; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_awready; // @[ysyx_zzy.scala 26:26]
  wire [3:0] CPU_Bridge_awqos; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_awuser; // @[ysyx_zzy.scala 26:26]
  wire [7:0] CPU_Bridge_wid; // @[ysyx_zzy.scala 26:26]
  wire [63:0] CPU_Bridge_wdata; // @[ysyx_zzy.scala 26:26]
  wire [7:0] CPU_Bridge_wstrb; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_wlast; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_wvalid; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_wready; // @[ysyx_zzy.scala 26:26]
  wire [7:0] CPU_Bridge_bid; // @[ysyx_zzy.scala 26:26]
  wire [1:0] CPU_Bridge_bresp; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_bvalid; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_bready; // @[ysyx_zzy.scala 26:26]
  wire [7:0] CPU_Bridge_arid; // @[ysyx_zzy.scala 26:26]
  wire [31:0] CPU_Bridge_araddr; // @[ysyx_zzy.scala 26:26]
  wire [7:0] CPU_Bridge_arlen; // @[ysyx_zzy.scala 26:26]
  wire [2:0] CPU_Bridge_arsize; // @[ysyx_zzy.scala 26:26]
  wire [1:0] CPU_Bridge_arburst; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_arlock; // @[ysyx_zzy.scala 26:26]
  wire [3:0] CPU_Bridge_arcache; // @[ysyx_zzy.scala 26:26]
  wire [2:0] CPU_Bridge_arprot; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_arvalid; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_arready; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_aruser; // @[ysyx_zzy.scala 26:26]
  wire [3:0] CPU_Bridge_arqos; // @[ysyx_zzy.scala 26:26]
  wire [7:0] CPU_Bridge_rid; // @[ysyx_zzy.scala 26:26]
  wire [63:0] CPU_Bridge_rdata; // @[ysyx_zzy.scala 26:26]
  wire [1:0] CPU_Bridge_rresp; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_rlast; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_rvalid; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_rready; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_clock; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_reset; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_inst_req; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_inst_wr; // @[ysyx_zzy.scala 26:26]
  wire [1:0] CPU_Bridge_inst_size; // @[ysyx_zzy.scala 26:26]
  wire [63:0] CPU_Bridge_inst_addr; // @[ysyx_zzy.scala 26:26]
  wire [63:0] CPU_Bridge_inst_wdata; // @[ysyx_zzy.scala 26:26]
  wire [63:0] CPU_Bridge_inst_rdata; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_inst_addr_ok; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_inst_data_ok; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_data_req; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_data_wr; // @[ysyx_zzy.scala 26:26]
  wire [1:0] CPU_Bridge_data_size; // @[ysyx_zzy.scala 26:26]
  wire [63:0] CPU_Bridge_data_addr; // @[ysyx_zzy.scala 26:26]
  wire [63:0] CPU_Bridge_data_wdata; // @[ysyx_zzy.scala 26:26]
  wire [63:0] CPU_Bridge_data_rdata; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_data_addr_ok; // @[ysyx_zzy.scala 26:26]
  wire  CPU_Bridge_data_data_ok; // @[ysyx_zzy.scala 26:26]
  wire [7:0] MMIO_Bridge_awid; // @[ysyx_zzy.scala 44:27]
  wire [31:0] MMIO_Bridge_awaddr; // @[ysyx_zzy.scala 44:27]
  wire [7:0] MMIO_Bridge_awlen; // @[ysyx_zzy.scala 44:27]
  wire [2:0] MMIO_Bridge_awsize; // @[ysyx_zzy.scala 44:27]
  wire [1:0] MMIO_Bridge_awburst; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_awlock; // @[ysyx_zzy.scala 44:27]
  wire [3:0] MMIO_Bridge_awcache; // @[ysyx_zzy.scala 44:27]
  wire [2:0] MMIO_Bridge_awprot; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_awvalid; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_awready; // @[ysyx_zzy.scala 44:27]
  wire [3:0] MMIO_Bridge_awqos; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_awuser; // @[ysyx_zzy.scala 44:27]
  wire [7:0] MMIO_Bridge_wid; // @[ysyx_zzy.scala 44:27]
  wire [63:0] MMIO_Bridge_wdata; // @[ysyx_zzy.scala 44:27]
  wire [7:0] MMIO_Bridge_wstrb; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_wlast; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_wvalid; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_wready; // @[ysyx_zzy.scala 44:27]
  wire [7:0] MMIO_Bridge_bid; // @[ysyx_zzy.scala 44:27]
  wire [1:0] MMIO_Bridge_bresp; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_bvalid; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_bready; // @[ysyx_zzy.scala 44:27]
  wire [7:0] MMIO_Bridge_arid; // @[ysyx_zzy.scala 44:27]
  wire [31:0] MMIO_Bridge_araddr; // @[ysyx_zzy.scala 44:27]
  wire [7:0] MMIO_Bridge_arlen; // @[ysyx_zzy.scala 44:27]
  wire [2:0] MMIO_Bridge_arsize; // @[ysyx_zzy.scala 44:27]
  wire [1:0] MMIO_Bridge_arburst; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_arlock; // @[ysyx_zzy.scala 44:27]
  wire [3:0] MMIO_Bridge_arcache; // @[ysyx_zzy.scala 44:27]
  wire [2:0] MMIO_Bridge_arprot; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_arvalid; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_arready; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_aruser; // @[ysyx_zzy.scala 44:27]
  wire [3:0] MMIO_Bridge_arqos; // @[ysyx_zzy.scala 44:27]
  wire [7:0] MMIO_Bridge_rid; // @[ysyx_zzy.scala 44:27]
  wire [63:0] MMIO_Bridge_rdata; // @[ysyx_zzy.scala 44:27]
  wire [1:0] MMIO_Bridge_rresp; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_rlast; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_rvalid; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_rready; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_clock; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_reset; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_inst_req; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_inst_wr; // @[ysyx_zzy.scala 44:27]
  wire [1:0] MMIO_Bridge_inst_size; // @[ysyx_zzy.scala 44:27]
  wire [63:0] MMIO_Bridge_inst_addr; // @[ysyx_zzy.scala 44:27]
  wire [63:0] MMIO_Bridge_inst_wdata; // @[ysyx_zzy.scala 44:27]
  wire [63:0] MMIO_Bridge_inst_rdata; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_inst_addr_ok; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_inst_data_ok; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_data_req; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_data_wr; // @[ysyx_zzy.scala 44:27]
  wire [1:0] MMIO_Bridge_data_size; // @[ysyx_zzy.scala 44:27]
  wire [63:0] MMIO_Bridge_data_addr; // @[ysyx_zzy.scala 44:27]
  wire [63:0] MMIO_Bridge_data_wdata; // @[ysyx_zzy.scala 44:27]
  wire [63:0] MMIO_Bridge_data_rdata; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_data_addr_ok; // @[ysyx_zzy.scala 44:27]
  wire  MMIO_Bridge_data_data_ok; // @[ysyx_zzy.scala 44:27]
  wire  _T = ~dpath_io_inst_mmio; // @[ysyx_zzy.scala 32:58]
  wire  _T_2 = ~dpath_io_data_mmio; // @[ysyx_zzy.scala 38:58]
  wire  _T_6 = dpath_io_inst_mmio; // @[ysyx_zzy.scala 61:28]
  wire  _T_7 = dpath_io_data_mmio; // @[ysyx_zzy.scala 71:28]
  zzy_Cpath cpath ( // @[ysyx_zzy.scala 20:21]
    .clock(cpath_clock),
    .reset(cpath_reset),
    .io_dat_dec_inst(cpath_io_dat_dec_inst),
    .io_dat_exe_br_eq(cpath_io_dat_exe_br_eq),
    .io_dat_exe_br_lt(cpath_io_dat_exe_br_lt),
    .io_dat_exe_br_ltu(cpath_io_dat_exe_br_ltu),
    .io_dat_exe_br_type(cpath_io_dat_exe_br_type),
    .io_dat_exe_ctrl_dmem_val(cpath_io_dat_exe_ctrl_dmem_val),
    .io_dat_inst_valid(cpath_io_dat_inst_valid),
    .io_dat_data_valid(cpath_io_dat_data_valid),
    .io_ctl_dec_stall(cpath_io_ctl_dec_stall),
    .io_ctl_full_stall(cpath_io_ctl_full_stall),
    .io_ctl_exe_pc_sel(cpath_io_ctl_exe_pc_sel),
    .io_ctl_br_type(cpath_io_ctl_br_type),
    .io_ctl_if_kill(cpath_io_ctl_if_kill),
    .io_ctl_dec_kill(cpath_io_ctl_dec_kill),
    .io_ctl_op1_sel(cpath_io_ctl_op1_sel),
    .io_ctl_op2_sel(cpath_io_ctl_op2_sel),
    .io_ctl_alu_fun(cpath_io_ctl_alu_fun),
    .io_ctl_wb_sel(cpath_io_ctl_wb_sel),
    .io_ctl_rf_wen(cpath_io_ctl_rf_wen),
    .io_ctl_mem_val(cpath_io_ctl_mem_val),
    .io_ctl_mem_fcn(cpath_io_ctl_mem_fcn),
    .io_ctl_mem_typ(cpath_io_ctl_mem_typ),
    .io_ctl_mem_wid(cpath_io_ctl_mem_wid)
  );
  zzy_Dpath dpath ( // @[ysyx_zzy.scala 21:21]
    .clock(dpath_clock),
    .reset(dpath_reset),
    .io_ctl_dec_stall(dpath_io_ctl_dec_stall),
    .io_ctl_full_stall(dpath_io_ctl_full_stall),
    .io_ctl_exe_pc_sel(dpath_io_ctl_exe_pc_sel),
    .io_ctl_br_type(dpath_io_ctl_br_type),
    .io_ctl_if_kill(dpath_io_ctl_if_kill),
    .io_ctl_dec_kill(dpath_io_ctl_dec_kill),
    .io_ctl_op1_sel(dpath_io_ctl_op1_sel),
    .io_ctl_op2_sel(dpath_io_ctl_op2_sel),
    .io_ctl_alu_fun(dpath_io_ctl_alu_fun),
    .io_ctl_wb_sel(dpath_io_ctl_wb_sel),
    .io_ctl_rf_wen(dpath_io_ctl_rf_wen),
    .io_ctl_mem_val(dpath_io_ctl_mem_val),
    .io_ctl_mem_fcn(dpath_io_ctl_mem_fcn),
    .io_ctl_mem_typ(dpath_io_ctl_mem_typ),
    .io_ctl_mem_wid(dpath_io_ctl_mem_wid),
    .io_dat_dec_inst(dpath_io_dat_dec_inst),
    .io_dat_exe_br_eq(dpath_io_dat_exe_br_eq),
    .io_dat_exe_br_lt(dpath_io_dat_exe_br_lt),
    .io_dat_exe_br_ltu(dpath_io_dat_exe_br_ltu),
    .io_dat_exe_br_type(dpath_io_dat_exe_br_type),
    .io_dat_exe_ctrl_dmem_val(dpath_io_dat_exe_ctrl_dmem_val),
    .io_dat_inst_valid(dpath_io_dat_inst_valid),
    .io_dat_data_valid(dpath_io_dat_data_valid),
    .io_imem_req_valid(dpath_io_imem_req_valid),
    .io_imem_req_bits_addr(dpath_io_imem_req_bits_addr),
    .io_imem_resp_valid(dpath_io_imem_resp_valid),
    .io_imem_resp_bits_data(dpath_io_imem_resp_bits_data),
    .io_dmem_req_valid(dpath_io_dmem_req_valid),
    .io_dmem_req_bits_addr(dpath_io_dmem_req_bits_addr),
    .io_dmem_req_bits_data(dpath_io_dmem_req_bits_data),
    .io_dmem_req_bits_wr(dpath_io_dmem_req_bits_wr),
    .io_dmem_req_bits_msk(dpath_io_dmem_req_bits_msk),
    .io_dmem_resp_valid(dpath_io_dmem_resp_valid),
    .io_dmem_resp_bits_data(dpath_io_dmem_resp_bits_data),
    .io_inst_mmio(dpath_io_inst_mmio),
    .io_data_mmio(dpath_io_data_mmio)
  );
  zzy_AXI_Bridge CPU_Bridge ( // @[ysyx_zzy.scala 26:26]
    .awid(CPU_Bridge_awid),
    .awaddr(CPU_Bridge_awaddr),
    .awlen(CPU_Bridge_awlen),
    .awsize(CPU_Bridge_awsize),
    .awburst(CPU_Bridge_awburst),
    .awlock(CPU_Bridge_awlock),
    .awcache(CPU_Bridge_awcache),
    .awprot(CPU_Bridge_awprot),
    .awvalid(CPU_Bridge_awvalid),
    .awready(CPU_Bridge_awready),
    .awqos(CPU_Bridge_awqos),
    .awuser(CPU_Bridge_awuser),
    .wid(CPU_Bridge_wid),
    .wdata(CPU_Bridge_wdata),
    .wstrb(CPU_Bridge_wstrb),
    .wlast(CPU_Bridge_wlast),
    .wvalid(CPU_Bridge_wvalid),
    .wready(CPU_Bridge_wready),
    .bid(CPU_Bridge_bid),
    .bresp(CPU_Bridge_bresp),
    .bvalid(CPU_Bridge_bvalid),
    .bready(CPU_Bridge_bready),
    .arid(CPU_Bridge_arid),
    .araddr(CPU_Bridge_araddr),
    .arlen(CPU_Bridge_arlen),
    .arsize(CPU_Bridge_arsize),
    .arburst(CPU_Bridge_arburst),
    .arlock(CPU_Bridge_arlock),
    .arcache(CPU_Bridge_arcache),
    .arprot(CPU_Bridge_arprot),
    .arvalid(CPU_Bridge_arvalid),
    .arready(CPU_Bridge_arready),
    .aruser(CPU_Bridge_aruser),
    .arqos(CPU_Bridge_arqos),
    .rid(CPU_Bridge_rid),
    .rdata(CPU_Bridge_rdata),
    .rresp(CPU_Bridge_rresp),
    .rlast(CPU_Bridge_rlast),
    .rvalid(CPU_Bridge_rvalid),
    .rready(CPU_Bridge_rready),
    .clock(CPU_Bridge_clock),
    .reset(CPU_Bridge_reset),
    .inst_req(CPU_Bridge_inst_req),
    .inst_wr(CPU_Bridge_inst_wr),
    .inst_size(CPU_Bridge_inst_size),
    .inst_addr(CPU_Bridge_inst_addr),
    .inst_wdata(CPU_Bridge_inst_wdata),
    .inst_rdata(CPU_Bridge_inst_rdata),
    .inst_addr_ok(CPU_Bridge_inst_addr_ok),
    .inst_data_ok(CPU_Bridge_inst_data_ok),
    .data_req(CPU_Bridge_data_req),
    .data_wr(CPU_Bridge_data_wr),
    .data_size(CPU_Bridge_data_size),
    .data_addr(CPU_Bridge_data_addr),
    .data_wdata(CPU_Bridge_data_wdata),
    .data_rdata(CPU_Bridge_data_rdata),
    .data_addr_ok(CPU_Bridge_data_addr_ok),
    .data_data_ok(CPU_Bridge_data_data_ok)
  );
  zzy_AXI_Bridge MMIO_Bridge ( // @[ysyx_zzy.scala 44:27]
    .awid(MMIO_Bridge_awid),
    .awaddr(MMIO_Bridge_awaddr),
    .awlen(MMIO_Bridge_awlen),
    .awsize(MMIO_Bridge_awsize),
    .awburst(MMIO_Bridge_awburst),
    .awlock(MMIO_Bridge_awlock),
    .awcache(MMIO_Bridge_awcache),
    .awprot(MMIO_Bridge_awprot),
    .awvalid(MMIO_Bridge_awvalid),
    .awready(MMIO_Bridge_awready),
    .awqos(MMIO_Bridge_awqos),
    .awuser(MMIO_Bridge_awuser),
    .wid(MMIO_Bridge_wid),
    .wdata(MMIO_Bridge_wdata),
    .wstrb(MMIO_Bridge_wstrb),
    .wlast(MMIO_Bridge_wlast),
    .wvalid(MMIO_Bridge_wvalid),
    .wready(MMIO_Bridge_wready),
    .bid(MMIO_Bridge_bid),
    .bresp(MMIO_Bridge_bresp),
    .bvalid(MMIO_Bridge_bvalid),
    .bready(MMIO_Bridge_bready),
    .arid(MMIO_Bridge_arid),
    .araddr(MMIO_Bridge_araddr),
    .arlen(MMIO_Bridge_arlen),
    .arsize(MMIO_Bridge_arsize),
    .arburst(MMIO_Bridge_arburst),
    .arlock(MMIO_Bridge_arlock),
    .arcache(MMIO_Bridge_arcache),
    .arprot(MMIO_Bridge_arprot),
    .arvalid(MMIO_Bridge_arvalid),
    .arready(MMIO_Bridge_arready),
    .aruser(MMIO_Bridge_aruser),
    .arqos(MMIO_Bridge_arqos),
    .rid(MMIO_Bridge_rid),
    .rdata(MMIO_Bridge_rdata),
    .rresp(MMIO_Bridge_rresp),
    .rlast(MMIO_Bridge_rlast),
    .rvalid(MMIO_Bridge_rvalid),
    .rready(MMIO_Bridge_rready),
    .clock(MMIO_Bridge_clock),
    .reset(MMIO_Bridge_reset),
    .inst_req(MMIO_Bridge_inst_req),
    .inst_wr(MMIO_Bridge_inst_wr),
    .inst_size(MMIO_Bridge_inst_size),
    .inst_addr(MMIO_Bridge_inst_addr),
    .inst_wdata(MMIO_Bridge_inst_wdata),
    .inst_rdata(MMIO_Bridge_inst_rdata),
    .inst_addr_ok(MMIO_Bridge_inst_addr_ok),
    .inst_data_ok(MMIO_Bridge_inst_data_ok),
    .data_req(MMIO_Bridge_data_req),
    .data_wr(MMIO_Bridge_data_wr),
    .data_size(MMIO_Bridge_data_size),
    .data_addr(MMIO_Bridge_data_addr),
    .data_wdata(MMIO_Bridge_data_wdata),
    .data_rdata(MMIO_Bridge_data_rdata),
    .data_addr_ok(MMIO_Bridge_data_addr_ok),
    .data_data_ok(MMIO_Bridge_data_data_ok)
  );
  assign io_mem_awid = CPU_Bridge_awid; // @[ysyx_zzy.scala 81:25]
  assign io_mem_awaddr = CPU_Bridge_awaddr; // @[ysyx_zzy.scala 82:25]
  assign io_mem_awlen = CPU_Bridge_awlen; // @[ysyx_zzy.scala 83:25]
  assign io_mem_awsize = CPU_Bridge_awsize; // @[ysyx_zzy.scala 84:25]
  assign io_mem_awburst = CPU_Bridge_awburst; // @[ysyx_zzy.scala 85:25]
  assign io_mem_awlock = CPU_Bridge_awlock; // @[ysyx_zzy.scala 86:25]
  assign io_mem_awcache = CPU_Bridge_awcache; // @[ysyx_zzy.scala 87:25]
  assign io_mem_awprot = CPU_Bridge_awprot; // @[ysyx_zzy.scala 88:25]
  assign io_mem_awvalid = CPU_Bridge_awvalid; // @[ysyx_zzy.scala 89:25]
  assign io_mem_wid = CPU_Bridge_wid; // @[ysyx_zzy.scala 92:25]
  assign io_mem_wdata = CPU_Bridge_wdata; // @[ysyx_zzy.scala 93:25]
  assign io_mem_wstrb = CPU_Bridge_wstrb; // @[ysyx_zzy.scala 94:25]
  assign io_mem_wlast = CPU_Bridge_wlast; // @[ysyx_zzy.scala 95:25]
  assign io_mem_wvalid = CPU_Bridge_wvalid; // @[ysyx_zzy.scala 96:25]
  assign io_mem_bready = CPU_Bridge_bready; // @[ysyx_zzy.scala 102:25]
  assign io_mem_arid = CPU_Bridge_arid; // @[ysyx_zzy.scala 105:25]
  assign io_mem_araddr = CPU_Bridge_araddr; // @[ysyx_zzy.scala 106:25]
  assign io_mem_arlen = CPU_Bridge_arlen; // @[ysyx_zzy.scala 107:25]
  assign io_mem_arsize = CPU_Bridge_arsize; // @[ysyx_zzy.scala 108:25]
  assign io_mem_arburst = CPU_Bridge_arburst; // @[ysyx_zzy.scala 109:25]
  assign io_mem_arlock = CPU_Bridge_arlock; // @[ysyx_zzy.scala 110:25]
  assign io_mem_arcache = CPU_Bridge_arcache; // @[ysyx_zzy.scala 111:25]
  assign io_mem_arprot = CPU_Bridge_arcache[2:0]; // @[ysyx_zzy.scala 112:25]
  assign io_mem_arvalid = CPU_Bridge_arvalid; // @[ysyx_zzy.scala 113:25]
  assign io_mem_rready = CPU_Bridge_rready; // @[ysyx_zzy.scala 121:25]
  assign io_mmio_awaddr = MMIO_Bridge_awaddr; // @[ysyx_zzy.scala 124:26]
  assign io_mmio_awprot = MMIO_Bridge_awprot; // @[ysyx_zzy.scala 125:26]
  assign io_mmio_awvalid = MMIO_Bridge_awvalid; // @[ysyx_zzy.scala 126:26]
  assign io_mmio_awsize = MMIO_Bridge_awsize; // @[ysyx_zzy.scala 127:26]
  assign io_mmio_wdata = MMIO_Bridge_wdata; // @[ysyx_zzy.scala 130:26]
  assign io_mmio_wstrb = MMIO_Bridge_wstrb; // @[ysyx_zzy.scala 131:26]
  assign io_mmio_wvalid = MMIO_Bridge_wvalid; // @[ysyx_zzy.scala 132:26]
  assign io_mmio_bready = MMIO_Bridge_bready; // @[ysyx_zzy.scala 137:26]
  assign io_mmio_araddr = MMIO_Bridge_araddr; // @[ysyx_zzy.scala 139:26]
  assign io_mmio_arprot = MMIO_Bridge_arcache[2:0]; // @[ysyx_zzy.scala 140:26]
  assign io_mmio_arvalid = MMIO_Bridge_arvalid; // @[ysyx_zzy.scala 141:26]
  assign io_mmio_arsize = MMIO_Bridge_arsize; // @[ysyx_zzy.scala 142:26]
  assign io_mmio_rready = MMIO_Bridge_rready; // @[ysyx_zzy.scala 148:26]
  assign cpath_clock = clock;
  assign cpath_reset = reset;
  assign cpath_io_dat_dec_inst = dpath_io_dat_dec_inst; // @[ysyx_zzy.scala 24:16]
  assign cpath_io_dat_exe_br_eq = dpath_io_dat_exe_br_eq; // @[ysyx_zzy.scala 24:16]
  assign cpath_io_dat_exe_br_lt = dpath_io_dat_exe_br_lt; // @[ysyx_zzy.scala 24:16]
  assign cpath_io_dat_exe_br_ltu = dpath_io_dat_exe_br_ltu; // @[ysyx_zzy.scala 24:16]
  assign cpath_io_dat_exe_br_type = dpath_io_dat_exe_br_type; // @[ysyx_zzy.scala 24:16]
  assign cpath_io_dat_exe_ctrl_dmem_val = dpath_io_dat_exe_ctrl_dmem_val; // @[ysyx_zzy.scala 24:16]
  assign cpath_io_dat_inst_valid = dpath_io_dat_inst_valid; // @[ysyx_zzy.scala 24:16]
  assign cpath_io_dat_data_valid = dpath_io_dat_data_valid; // @[ysyx_zzy.scala 24:16]
  assign dpath_clock = clock;
  assign dpath_reset = reset;
  assign dpath_io_ctl_dec_stall = cpath_io_ctl_dec_stall; // @[ysyx_zzy.scala 23:16]
  assign dpath_io_ctl_full_stall = cpath_io_ctl_full_stall; // @[ysyx_zzy.scala 23:16]
  assign dpath_io_ctl_exe_pc_sel = cpath_io_ctl_exe_pc_sel; // @[ysyx_zzy.scala 23:16]
  assign dpath_io_ctl_br_type = cpath_io_ctl_br_type; // @[ysyx_zzy.scala 23:16]
  assign dpath_io_ctl_if_kill = cpath_io_ctl_if_kill; // @[ysyx_zzy.scala 23:16]
  assign dpath_io_ctl_dec_kill = cpath_io_ctl_dec_kill; // @[ysyx_zzy.scala 23:16]
  assign dpath_io_ctl_op1_sel = cpath_io_ctl_op1_sel; // @[ysyx_zzy.scala 23:16]
  assign dpath_io_ctl_op2_sel = cpath_io_ctl_op2_sel; // @[ysyx_zzy.scala 23:16]
  assign dpath_io_ctl_alu_fun = cpath_io_ctl_alu_fun; // @[ysyx_zzy.scala 23:16]
  assign dpath_io_ctl_wb_sel = cpath_io_ctl_wb_sel; // @[ysyx_zzy.scala 23:16]
  assign dpath_io_ctl_rf_wen = cpath_io_ctl_rf_wen; // @[ysyx_zzy.scala 23:16]
  assign dpath_io_ctl_mem_val = cpath_io_ctl_mem_val; // @[ysyx_zzy.scala 23:16]
  assign dpath_io_ctl_mem_fcn = cpath_io_ctl_mem_fcn; // @[ysyx_zzy.scala 23:16]
  assign dpath_io_ctl_mem_typ = cpath_io_ctl_mem_typ; // @[ysyx_zzy.scala 23:16]
  assign dpath_io_ctl_mem_wid = cpath_io_ctl_mem_wid; // @[ysyx_zzy.scala 23:16]
  assign dpath_io_imem_resp_valid = _T_6 ? MMIO_Bridge_inst_data_ok : CPU_Bridge_inst_data_ok; // @[ysyx_zzy.scala 63:36 ysyx_zzy.scala 67:36]
  assign dpath_io_imem_resp_bits_data = _T_6 ? MMIO_Bridge_inst_rdata : CPU_Bridge_inst_rdata; // @[ysyx_zzy.scala 64:36 ysyx_zzy.scala 68:36]
  assign dpath_io_dmem_resp_valid = _T_7 ? MMIO_Bridge_data_data_ok : CPU_Bridge_data_data_ok; // @[ysyx_zzy.scala 73:36 ysyx_zzy.scala 77:36]
  assign dpath_io_dmem_resp_bits_data = _T_7 ? MMIO_Bridge_data_rdata : CPU_Bridge_data_rdata; // @[ysyx_zzy.scala 74:36 ysyx_zzy.scala 78:36]
  assign CPU_Bridge_awready = io_mem_awready; // @[ysyx_zzy.scala 90:25]
  assign CPU_Bridge_awqos = 4'h0;
  assign CPU_Bridge_awuser = 1'h0;
  assign CPU_Bridge_wready = io_mem_wready; // @[ysyx_zzy.scala 97:25]
  assign CPU_Bridge_bid = io_mem_bid; // @[ysyx_zzy.scala 99:25]
  assign CPU_Bridge_bresp = io_mem_bresp; // @[ysyx_zzy.scala 100:25]
  assign CPU_Bridge_bvalid = io_mem_bvalid; // @[ysyx_zzy.scala 101:25]
  assign CPU_Bridge_arready = io_mem_arready; // @[ysyx_zzy.scala 114:25]
  assign CPU_Bridge_aruser = 1'h0;
  assign CPU_Bridge_arqos = 4'h0;
  assign CPU_Bridge_rid = io_mem_rid; // @[ysyx_zzy.scala 116:25]
  assign CPU_Bridge_rdata = io_mem_rdata; // @[ysyx_zzy.scala 117:25]
  assign CPU_Bridge_rresp = io_mem_rresp; // @[ysyx_zzy.scala 118:25]
  assign CPU_Bridge_rlast = io_mem_rlast; // @[ysyx_zzy.scala 119:25]
  assign CPU_Bridge_rvalid = io_mem_rvalid; // @[ysyx_zzy.scala 120:25]
  assign CPU_Bridge_clock = clock; // @[ysyx_zzy.scala 29:27]
  assign CPU_Bridge_reset = reset; // @[ysyx_zzy.scala 30:27]
  assign CPU_Bridge_inst_req = dpath_io_imem_req_valid & _T; // @[ysyx_zzy.scala 32:28]
  assign CPU_Bridge_inst_wr = 1'h0; // @[ysyx_zzy.scala 33:28]
  assign CPU_Bridge_inst_size = 2'h2; // @[ysyx_zzy.scala 34:28]
  assign CPU_Bridge_inst_addr = dpath_io_imem_req_bits_addr; // @[ysyx_zzy.scala 35:28]
  assign CPU_Bridge_inst_wdata = 64'h0; // @[ysyx_zzy.scala 36:28]
  assign CPU_Bridge_data_req = dpath_io_dmem_req_valid & _T_2; // @[ysyx_zzy.scala 38:28]
  assign CPU_Bridge_data_wr = dpath_io_dmem_req_bits_wr; // @[ysyx_zzy.scala 39:28]
  assign CPU_Bridge_data_size = dpath_io_dmem_req_bits_msk[1:0]; // @[ysyx_zzy.scala 40:28]
  assign CPU_Bridge_data_addr = dpath_io_dmem_req_bits_addr; // @[ysyx_zzy.scala 41:28]
  assign CPU_Bridge_data_wdata = dpath_io_dmem_req_bits_data; // @[ysyx_zzy.scala 42:28]
  assign MMIO_Bridge_awready = io_mmio_awready; // @[ysyx_zzy.scala 128:26]
  assign MMIO_Bridge_awqos = 4'h0;
  assign MMIO_Bridge_awuser = 1'h0;
  assign MMIO_Bridge_wready = io_mmio_wready; // @[ysyx_zzy.scala 133:26]
  assign MMIO_Bridge_bid = 8'h0;
  assign MMIO_Bridge_bresp = io_mmio_bresp; // @[ysyx_zzy.scala 135:26]
  assign MMIO_Bridge_bvalid = io_mmio_bvalid; // @[ysyx_zzy.scala 136:26]
  assign MMIO_Bridge_arready = io_mmio_arready; // @[ysyx_zzy.scala 143:26]
  assign MMIO_Bridge_aruser = 1'h0;
  assign MMIO_Bridge_arqos = 4'h0;
  assign MMIO_Bridge_rid = 8'h0;
  assign MMIO_Bridge_rdata = io_mmio_rdata; // @[ysyx_zzy.scala 145:26]
  assign MMIO_Bridge_rresp = io_mmio_rresp; // @[ysyx_zzy.scala 146:26]
  assign MMIO_Bridge_rlast = 1'h0;
  assign MMIO_Bridge_rvalid = io_mmio_rvalid; // @[ysyx_zzy.scala 147:26]
  assign MMIO_Bridge_clock = clock; // @[ysyx_zzy.scala 46:24]
  assign MMIO_Bridge_reset = reset; // @[ysyx_zzy.scala 47:24]
  assign MMIO_Bridge_inst_req = dpath_io_imem_req_valid & dpath_io_inst_mmio; // @[ysyx_zzy.scala 49:29]
  assign MMIO_Bridge_inst_wr = 1'h0; // @[ysyx_zzy.scala 50:29]
  assign MMIO_Bridge_inst_size = 2'h2; // @[ysyx_zzy.scala 51:29]
  assign MMIO_Bridge_inst_addr = dpath_io_imem_req_bits_addr; // @[ysyx_zzy.scala 52:29]
  assign MMIO_Bridge_inst_wdata = 64'h0; // @[ysyx_zzy.scala 53:29]
  assign MMIO_Bridge_data_req = dpath_io_dmem_req_valid & dpath_io_data_mmio; // @[ysyx_zzy.scala 55:29]
  assign MMIO_Bridge_data_wr = dpath_io_dmem_req_bits_wr; // @[ysyx_zzy.scala 56:29]
  assign MMIO_Bridge_data_size = dpath_io_dmem_req_bits_msk[1:0]; // @[ysyx_zzy.scala 57:29]
  assign MMIO_Bridge_data_addr = dpath_io_dmem_req_bits_addr; // @[ysyx_zzy.scala 58:29]
  assign MMIO_Bridge_data_wdata = dpath_io_dmem_req_bits_data; // @[ysyx_zzy.scala 59:29]
endmodule
