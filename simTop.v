module Cpath(
  input         clock,
  input         reset,
  input  [63:0] io_dat_dec_inst,
  input         io_dat_exe_br_eq,
  input         io_dat_exe_br_lt,
  input         io_dat_exe_br_ltu,
  input  [3:0]  io_dat_exe_br_type,
  input         io_dat_csr_eret,
  output        io_ctl_dec_stall,
  output [1:0]  io_ctl_exe_pc_sel,
  output [3:0]  io_ctl_br_type,
  output        io_ctl_if_kill,
  output        io_ctl_dec_kill,
  output [1:0]  io_ctl_op1_sel,
  output [2:0]  io_ctl_op2_sel,
  output [4:0]  io_ctl_alu_fun,
  output [2:0]  io_ctl_wb_sel,
  output        io_ctl_rf_wen,
  output [1:0]  io_ctl_mem_fcn,
  output [7:0]  io_ctl_mem_typ,
  output [2:0]  io_ctl_mem_wid,
  output [2:0]  io_ctl_csr_cmd,
  output        io_ctl_fencei,
  output        io_ctl_pipeline_kill
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [31:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
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
  wire [4:0] _T_628 = _T_81 ? 5'h3 : _T_627; // @[Lookup.scala 33:37]
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
  wire  ifkill = _T_1288 | _T_1289; // @[cpath.scala 154:57]
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
  wire  _T_1293 = cs0_7 != 3'h0; // @[cpath.scala 194:47]
  wire  _T_1294 = cs0_7 != 3'h5; // @[cpath.scala 194:73]
  wire  _T_1295 = _T_1293 & _T_1294; // @[cpath.scala 194:58]
  wire  _T_1299 = cs0_4 == 2'h1; // @[cpath.scala 216:50]
  wire  _T_1300 = cs0_3 & _T_1299; // @[cpath.scala 216:35]
  reg  _T_1313; // @[cpath.scala 247:44]
  wire  _T_1319 = ~reset; // @[cpath.scala 253:9]
  assign io_ctl_dec_stall = _T_1311 | exe_reg_is_csr; // @[cpath.scala 230:21]
  assign io_ctl_exe_pc_sel = _T_1260 ? 2'h0 : _T_1285; // @[cpath.scala 232:21]
  assign io_ctl_br_type = _T_1 ? 4'h0 : _T_297; // @[cpath.scala 233:21]
  assign io_ctl_if_kill = _T_1288 | _T_1289; // @[cpath.scala 234:21]
  assign io_ctl_dec_kill = ctrl_exe_pc_sel != 2'h0; // @[cpath.scala 235:21]
  assign io_ctl_op1_sel = _T_1 ? 2'h0 : _T_371; // @[cpath.scala 236:21]
  assign io_ctl_op2_sel = _T_1 ? 3'h1 : _T_445; // @[cpath.scala 237:21]
  assign io_ctl_alu_fun = _T_1 ? 5'h0 : _T_667; // @[cpath.scala 238:21]
  assign io_ctl_wb_sel = _T_1 ? 3'h1 : _T_741; // @[cpath.scala 239:21]
  assign io_ctl_rf_wen = _T_1 | _T_815; // @[cpath.scala 240:21]
  assign io_ctl_mem_fcn = _T_1 ? 2'h1 : _T_963; // @[cpath.scala 243:21]
  assign io_ctl_mem_typ = _T_1 ? 8'hff : _T_1037; // @[cpath.scala 244:21]
  assign io_ctl_mem_wid = _T_1 ? 3'h6 : _T_1111; // @[cpath.scala 245:21]
  assign io_ctl_csr_cmd = _T_1295 ? 3'h1 : cs0_7; // @[cpath.scala 251:18]
  assign io_ctl_fencei = cs0_8 | _T_1313; // @[cpath.scala 247:21]
  assign io_ctl_pipeline_kill = io_dat_csr_eret; // @[cpath.scala 157:24]
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
  _RAND_4 = {1{`RANDOM}};
  _T_1313 = _RAND_4[0:0];
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
    if (_T_1290) begin
      if (_T_1287) begin
        exe_reg_wbaddr <= 5'h0;
      end else begin
        exe_reg_wbaddr <= dec_wbaddr;
      end
    end else if (stall) begin
      exe_reg_wbaddr <= 5'h0;
    end
    if (reset) begin
      exe_reg_is_csr <= 1'h0;
    end else if (_T_1290) begin
      if (_T_1287) begin
        exe_reg_is_csr <= 1'h0;
      end else begin
        exe_reg_is_csr <= _T_1295;
      end
    end else if (stall) begin
      exe_reg_is_csr <= 1'h0;
    end
    if (reset) begin
      exe_inst_is_load <= 1'h0;
    end else begin
      exe_inst_is_load <= _T_1300;
    end
    if (_T_1) begin
      _T_1313 <= 1'h0;
    end else if (_T_3) begin
      _T_1313 <= 1'h0;
    end else if (_T_5) begin
      _T_1313 <= 1'h0;
    end else if (_T_7) begin
      _T_1313 <= 1'h0;
    end else if (_T_9) begin
      _T_1313 <= 1'h0;
    end else if (_T_11) begin
      _T_1313 <= 1'h0;
    end else if (_T_13) begin
      _T_1313 <= 1'h0;
    end else if (_T_15) begin
      _T_1313 <= 1'h0;
    end else if (_T_17) begin
      _T_1313 <= 1'h0;
    end else if (_T_19) begin
      _T_1313 <= 1'h0;
    end else if (_T_21) begin
      _T_1313 <= 1'h0;
    end else if (_T_23) begin
      _T_1313 <= 1'h0;
    end else if (_T_25) begin
      _T_1313 <= 1'h0;
    end else if (_T_27) begin
      _T_1313 <= 1'h0;
    end else if (_T_29) begin
      _T_1313 <= 1'h0;
    end else if (_T_31) begin
      _T_1313 <= 1'h0;
    end else if (_T_33) begin
      _T_1313 <= 1'h0;
    end else if (_T_35) begin
      _T_1313 <= 1'h0;
    end else if (_T_37) begin
      _T_1313 <= 1'h0;
    end else if (_T_39) begin
      _T_1313 <= 1'h0;
    end else if (_T_41) begin
      _T_1313 <= 1'h0;
    end else if (_T_43) begin
      _T_1313 <= 1'h0;
    end else if (_T_45) begin
      _T_1313 <= 1'h0;
    end else if (_T_47) begin
      _T_1313 <= 1'h0;
    end else if (_T_49) begin
      _T_1313 <= 1'h0;
    end else if (_T_51) begin
      _T_1313 <= 1'h0;
    end else if (_T_53) begin
      _T_1313 <= 1'h0;
    end else if (_T_55) begin
      _T_1313 <= 1'h0;
    end else if (_T_57) begin
      _T_1313 <= 1'h0;
    end else if (_T_59) begin
      _T_1313 <= 1'h0;
    end else if (_T_61) begin
      _T_1313 <= 1'h0;
    end else if (_T_63) begin
      _T_1313 <= 1'h0;
    end else if (_T_65) begin
      _T_1313 <= 1'h0;
    end else if (_T_67) begin
      _T_1313 <= 1'h0;
    end else if (_T_69) begin
      _T_1313 <= 1'h0;
    end else if (_T_71) begin
      _T_1313 <= 1'h0;
    end else if (_T_73) begin
      _T_1313 <= 1'h0;
    end else if (_T_75) begin
      _T_1313 <= 1'h0;
    end else if (_T_77) begin
      _T_1313 <= 1'h0;
    end else if (_T_79) begin
      _T_1313 <= 1'h0;
    end else if (_T_81) begin
      _T_1313 <= 1'h0;
    end else if (_T_83) begin
      _T_1313 <= 1'h0;
    end else if (_T_85) begin
      _T_1313 <= 1'h0;
    end else if (_T_87) begin
      _T_1313 <= 1'h0;
    end else if (_T_89) begin
      _T_1313 <= 1'h0;
    end else if (_T_91) begin
      _T_1313 <= 1'h0;
    end else if (_T_93) begin
      _T_1313 <= 1'h0;
    end else if (_T_95) begin
      _T_1313 <= 1'h0;
    end else if (_T_97) begin
      _T_1313 <= 1'h0;
    end else if (_T_99) begin
      _T_1313 <= 1'h0;
    end else if (_T_101) begin
      _T_1313 <= 1'h0;
    end else if (_T_103) begin
      _T_1313 <= 1'h0;
    end else if (_T_105) begin
      _T_1313 <= 1'h0;
    end else if (_T_107) begin
      _T_1313 <= 1'h0;
    end else if (_T_109) begin
      _T_1313 <= 1'h0;
    end else if (_T_111) begin
      _T_1313 <= 1'h0;
    end else if (_T_113) begin
      _T_1313 <= 1'h0;
    end else if (_T_115) begin
      _T_1313 <= 1'h0;
    end else if (_T_117) begin
      _T_1313 <= 1'h0;
    end else if (_T_119) begin
      _T_1313 <= 1'h0;
    end else if (_T_121) begin
      _T_1313 <= 1'h0;
    end else if (_T_123) begin
      _T_1313 <= 1'h0;
    end else if (_T_125) begin
      _T_1313 <= 1'h0;
    end else if (_T_127) begin
      _T_1313 <= 1'h0;
    end else if (_T_129) begin
      _T_1313 <= 1'h0;
    end else if (_T_131) begin
      _T_1313 <= 1'h0;
    end else if (_T_133) begin
      _T_1313 <= 1'h0;
    end else if (_T_135) begin
      _T_1313 <= 1'h0;
    end else if (_T_137) begin
      _T_1313 <= 1'h0;
    end else if (_T_139) begin
      _T_1313 <= 1'h0;
    end else if (_T_141) begin
      _T_1313 <= 1'h0;
    end else if (_T_143) begin
      _T_1313 <= 1'h0;
    end else if (_T_145) begin
      _T_1313 <= 1'h0;
    end else begin
      _T_1313 <= _T_147;
    end
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_1319) begin
          $fwrite(32'h80000002,"CTRL : inst = %x, ifkill = %d, deckill = %d, stall = %d\n",io_dat_dec_inst,ifkill,_T_1287,stall); // @[cpath.scala 253:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
  end
endmodule
module regfile(
  input         clock,
  input         reset,
  input  [4:0]  io_rs1_addr,
  output [63:0] io_rs1_data,
  input  [4:0]  io_rs2_addr,
  output [63:0] io_rs2_data,
  input  [4:0]  io_waddr,
  input  [63:0] io_wdata,
  input         io_wen,
  output [63:0] _T_42_0_0,
  output [63:0] _T_42_0_1,
  output [63:0] _T_42_0_2,
  output [63:0] _T_42_0_3,
  output [63:0] _T_42_0_4,
  output [63:0] _T_42_0_5,
  output [63:0] _T_42_0_6,
  output [63:0] _T_42_0_7,
  output [63:0] _T_42_0_8,
  output [63:0] _T_42_0_9,
  output [63:0] _T_42_0_10,
  output [63:0] _T_42_0_11,
  output [63:0] _T_42_0_12,
  output [63:0] _T_42_0_13,
  output [63:0] _T_42_0_14,
  output [63:0] _T_42_0_15,
  output [63:0] _T_42_0_16,
  output [63:0] _T_42_0_17,
  output [63:0] _T_42_0_18,
  output [63:0] _T_42_0_19,
  output [63:0] _T_42_0_20,
  output [63:0] _T_42_0_21,
  output [63:0] _T_42_0_22,
  output [63:0] _T_42_0_23,
  output [63:0] _T_42_0_24,
  output [63:0] _T_42_0_25,
  output [63:0] _T_42_0_26,
  output [63:0] _T_42_0_27,
  output [63:0] _T_42_0_28,
  output [63:0] _T_42_0_29,
  output [63:0] _T_42_0_30,
  output [63:0] _T_42_0_31
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
  wire  _T_44 = ~reset; // @[regfile.scala 33:9]
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
  assign _T_42_0_0 = _T_42_0;
  assign _T_42_0_1 = _T_42_1;
  assign _T_42_0_2 = _T_42_2;
  assign _T_42_0_3 = _T_42_3;
  assign _T_42_0_4 = _T_42_4;
  assign _T_42_0_5 = _T_42_5;
  assign _T_42_0_6 = _T_42_6;
  assign _T_42_0_7 = _T_42_7;
  assign _T_42_0_8 = _T_42_8;
  assign _T_42_0_9 = _T_42_9;
  assign _T_42_0_10 = _T_42_10;
  assign _T_42_0_11 = _T_42_11;
  assign _T_42_0_12 = _T_42_12;
  assign _T_42_0_13 = _T_42_13;
  assign _T_42_0_14 = _T_42_14;
  assign _T_42_0_15 = _T_42_15;
  assign _T_42_0_16 = _T_42_16;
  assign _T_42_0_17 = _T_42_17;
  assign _T_42_0_18 = _T_42_18;
  assign _T_42_0_19 = _T_42_19;
  assign _T_42_0_20 = _T_42_20;
  assign _T_42_0_21 = _T_42_21;
  assign _T_42_0_22 = _T_42_22;
  assign _T_42_0_23 = _T_42_23;
  assign _T_42_0_24 = _T_42_24;
  assign _T_42_0_25 = _T_42_25;
  assign _T_42_0_26 = _T_42_26;
  assign _T_42_0_27 = _T_42_27;
  assign _T_42_0_28 = _T_42_28;
  assign _T_42_0_29 = _T_42_29;
  assign _T_42_0_30 = _T_42_30;
  assign _T_42_0_31 = _T_42_31;
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
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_44) begin
          $fwrite(32'h80000002,"RF: rdata1(%d)=[%x] rdata2(%d)=[%x] wdata(%d)=[%x] wen=%d\n",io_rs1_addr,io_rs1_data,io_rs1_addr,io_rs2_data,io_waddr,io_wdata,io_wen); // @[regfile.scala 33:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
  end
endmodule
module alu(
  input         clock,
  input         reset,
  input  [63:0] io_src1,
  input  [63:0] io_src2,
  input  [4:0]  io_op,
  output [63:0] io_res
);
  wire [5:0] shamt = io_src2[5:0]; // @[alu.scala 17:22]
  wire  _T = io_op == 5'h0; // @[alu.scala 20:9]
  wire [63:0] _T_2 = io_src1 + io_src2; // @[alu.scala 20:34]
  wire  _T_3 = io_op == 5'h1; // @[alu.scala 21:9]
  wire [63:0] _T_5 = io_src1 - io_src2; // @[alu.scala 21:34]
  wire  _T_6 = io_op == 5'h5; // @[alu.scala 22:9]
  wire [63:0] _T_7 = io_src1 & io_src2; // @[alu.scala 22:34]
  wire  _T_8 = io_op == 5'h6; // @[alu.scala 23:9]
  wire [63:0] _T_9 = io_src1 | io_src2; // @[alu.scala 23:34]
  wire  _T_10 = io_op == 5'h7; // @[alu.scala 24:9]
  wire [63:0] _T_11 = io_src1 ^ io_src2; // @[alu.scala 24:34]
  wire  _T_12 = io_op == 5'h8; // @[alu.scala 25:9]
  wire [63:0] _T_13 = io_src1; // @[alu.scala 25:40]
  wire  _T_15 = $signed(io_src1) < $signed(io_src2); // @[alu.scala 25:43]
  wire  _T_16 = io_op == 5'h9; // @[alu.scala 26:9]
  wire  _T_17 = io_src1 < io_src2; // @[alu.scala 26:34]
  wire  _T_18 = io_op == 5'h2; // @[alu.scala 27:9]
  wire [126:0] _GEN_0 = {{63'd0}, io_src1}; // @[alu.scala 27:35]
  wire [126:0] _T_19 = _GEN_0 << shamt; // @[alu.scala 27:35]
  wire  _T_21 = io_op == 5'h4; // @[alu.scala 28:9]
  wire [63:0] _T_24 = $signed(io_src1) >>> shamt; // @[alu.scala 28:59]
  wire  _T_25 = io_op == 5'h3; // @[alu.scala 29:9]
  wire [63:0] _T_26 = io_src1 >> shamt; // @[alu.scala 29:34]
  wire  _T_27 = io_op == 5'ha; // @[alu.scala 30:9]
  wire  _T_28 = io_op == 5'hb; // @[alu.scala 31:9]
  wire  _T_29 = io_op == 5'hc; // @[alu.scala 32:9]
  wire [31:0] _T_32 = io_src1[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [31:0] _T_34 = io_src1[31:0]; // @[alu.scala 32:70]
  wire [31:0] _T_36 = $signed(_T_34) >>> shamt; // @[alu.scala 32:89]
  wire [63:0] _T_37 = {_T_32,_T_36}; // @[Cat.scala 29:58]
  wire  _T_38 = io_op == 5'hd; // @[alu.scala 33:9]
  wire [127:0] _T_39 = io_src1 * io_src2; // @[alu.scala 33:30]
  wire  _T_41 = io_op == 5'he; // @[alu.scala 35:9]
  wire  _T_42 = io_src2 == 64'h0; // @[alu.scala 35:33]
  wire [63:0] _T_43 = io_src1 / io_src2; // @[alu.scala 35:51]
  wire [63:0] _T_44 = _T_42 ? 64'h0 : _T_43; // @[alu.scala 35:27]
  wire  _T_45 = io_op == 5'hf; // @[alu.scala 36:9]
  wire [31:0] _T_50 = io_src2[31:0]; // @[alu.scala 36:86]
  wire [31:0] _T_52 = $signed(_T_34) % $signed(_T_50); // @[alu.scala 36:96]
  wire [31:0] _T_53 = _T_42 ? 32'h0 : _T_52; // @[alu.scala 36:28]
  wire  _T_54 = io_op == 5'h10; // @[alu.scala 37:9]
  wire [31:0] _GEN_2 = io_src1[31:0] % io_src2[31:0]; // @[alu.scala 37:59]
  wire [31:0] _T_58 = _GEN_2[31:0]; // @[alu.scala 37:59]
  wire [31:0] _T_59 = _T_42 ? 32'h0 : _T_58; // @[alu.scala 37:29]
  wire  _T_60 = io_op == 5'h11; // @[alu.scala 38:9]
  wire [31:0] _T_64 = io_src1[31:0] / io_src2[31:0]; // @[alu.scala 38:59]
  wire [31:0] _T_65 = _T_42 ? 32'h0 : _T_64; // @[alu.scala 38:29]
  wire  _T_66 = io_op == 5'h12; // @[alu.scala 39:9]
  wire [127:0] _T_69 = $signed(io_src1) * $signed(io_src2); // @[alu.scala 39:41]
  wire  _T_71 = io_op == 5'h13; // @[alu.scala 40:9]
  wire [64:0] _T_73 = {1'b0,$signed(io_src2)}; // @[alu.scala 40:43]
  wire [64:0] _GEN_1 = {{1{_T_13[63]}},_T_13}; // @[alu.scala 40:43]
  wire [128:0] _T_74 = $signed(_GEN_1) * $signed(_T_73); // @[alu.scala 40:43]
  wire [127:0] _T_76 = _T_74[127:0]; // @[alu.scala 40:43]
  wire  _T_78 = io_op == 5'h14; // @[alu.scala 41:9]
  wire  _T_81 = io_op == 5'h15; // @[alu.scala 42:9]
  wire  _T_85 = io_op == 5'h16; // @[alu.scala 44:9]
  wire  _T_91 = io_op == 5'h17; // @[alu.scala 45:9]
  wire [63:0] _T_96 = $signed(io_src1) % $signed(io_src2); // @[alu.scala 45:84]
  wire [63:0] _T_97 = _T_42 ? 64'h0 : _T_96; // @[alu.scala 45:28]
  wire  _T_98 = io_op == 5'h18; // @[alu.scala 46:9]
  wire [63:0] _GEN_3 = io_src1 % io_src2; // @[alu.scala 46:53]
  wire [63:0] _T_100 = _GEN_3[63:0]; // @[alu.scala 46:53]
  wire [63:0] _T_101 = _T_42 ? 64'h0 : _T_100; // @[alu.scala 46:29]
  wire [63:0] _T_102 = _T_98 ? _T_101 : 64'h0; // @[Mux.scala 98:16]
  wire [63:0] _T_103 = _T_91 ? _T_97 : _T_102; // @[Mux.scala 98:16]
  wire [63:0] _T_104 = _T_85 ? {{32'd0}, _T_65} : _T_103; // @[Mux.scala 98:16]
  wire [63:0] _T_105 = _T_81 ? _T_44 : _T_104; // @[Mux.scala 98:16]
  wire [63:0] _T_106 = _T_78 ? _T_39[127:64] : _T_105; // @[Mux.scala 98:16]
  wire [63:0] _T_107 = _T_71 ? _T_76[127:64] : _T_106; // @[Mux.scala 98:16]
  wire [63:0] _T_108 = _T_66 ? _T_69[127:64] : _T_107; // @[Mux.scala 98:16]
  wire [63:0] _T_109 = _T_60 ? {{32'd0}, _T_65} : _T_108; // @[Mux.scala 98:16]
  wire [63:0] _T_110 = _T_54 ? {{32'd0}, _T_59} : _T_109; // @[Mux.scala 98:16]
  wire [63:0] _T_111 = _T_45 ? {{32'd0}, _T_53} : _T_110; // @[Mux.scala 98:16]
  wire [63:0] _T_112 = _T_41 ? _T_44 : _T_111; // @[Mux.scala 98:16]
  wire [63:0] _T_113 = _T_38 ? _T_39[63:0] : _T_112; // @[Mux.scala 98:16]
  wire [63:0] _T_114 = _T_29 ? _T_37 : _T_113; // @[Mux.scala 98:16]
  wire [63:0] _T_115 = _T_28 ? io_src2 : _T_114; // @[Mux.scala 98:16]
  wire [63:0] _T_116 = _T_27 ? io_src1 : _T_115; // @[Mux.scala 98:16]
  wire [63:0] _T_117 = _T_25 ? _T_26 : _T_116; // @[Mux.scala 98:16]
  wire [63:0] _T_118 = _T_21 ? _T_24 : _T_117; // @[Mux.scala 98:16]
  wire [63:0] _T_119 = _T_18 ? _T_19[63:0] : _T_118; // @[Mux.scala 98:16]
  wire [63:0] _T_120 = _T_16 ? {{63'd0}, _T_17} : _T_119; // @[Mux.scala 98:16]
  wire [63:0] _T_121 = _T_12 ? {{63'd0}, _T_15} : _T_120; // @[Mux.scala 98:16]
  wire [63:0] _T_122 = _T_10 ? _T_11 : _T_121; // @[Mux.scala 98:16]
  wire [63:0] _T_123 = _T_8 ? _T_9 : _T_122; // @[Mux.scala 98:16]
  wire [63:0] _T_124 = _T_6 ? _T_7 : _T_123; // @[Mux.scala 98:16]
  wire [63:0] _T_125 = _T_3 ? _T_5 : _T_124; // @[Mux.scala 98:16]
  wire  _T_128 = ~reset; // @[alu.scala 49:9]
  assign io_res = _T ? _T_2 : _T_125; // @[alu.scala 19:10]
  always @(posedge clock) begin
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_128) begin
          $fwrite(32'h80000002,"ALU: op = %d, src1=[%x] src2=[%x] result=[%x]\n",io_op,io_src1,io_src2,io_res); // @[alu.scala 49:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
  end
endmodule
module CSRfile(
  input         clock,
  input         reset,
  input  [31:0] io_inst,
  input  [2:0]  io_csr_op,
  input  [63:0] io_data_in,
  input  [63:0] io_in_mem_pc,
  input  [63:0] io_in_exe_pc,
  input  [63:0] io_in_dec_pc,
  input  [63:0] io_in_if_pc,
  output        io_is_redir
);
`ifdef RANDOMIZE_REG_INIT
  reg [63:0] _RAND_0;
  reg [63:0] _RAND_1;
  reg [63:0] _RAND_2;
  reg [31:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [31:0] _RAND_6;
  reg [63:0] _RAND_7;
  reg [63:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [63:0] _RAND_12;
  reg [63:0] _RAND_13;
  reg [63:0] _RAND_14;
  reg [63:0] _RAND_15;
  reg [63:0] _RAND_16;
  reg [63:0] _RAND_17;
  reg [63:0] _RAND_18;
  reg [63:0] _RAND_19;
  reg [63:0] _RAND_20;
  reg [63:0] _RAND_21;
  reg [63:0] _RAND_22;
  reg [63:0] _RAND_23;
  reg [63:0] _RAND_24;
  reg [63:0] _RAND_25;
  reg [63:0] _RAND_26;
  reg [63:0] _RAND_27;
  reg [63:0] _RAND_28;
  reg [63:0] _RAND_29;
  reg [63:0] _RAND_30;
  reg [63:0] _RAND_31;
  reg [63:0] _RAND_32;
  reg [63:0] _RAND_33;
  reg [63:0] _RAND_34;
  reg [63:0] _RAND_35;
  reg [63:0] _RAND_36;
  reg [63:0] _RAND_37;
  reg [63:0] _RAND_38;
  reg [63:0] _RAND_39;
  reg [63:0] _RAND_40;
  reg [63:0] _RAND_41;
  reg [63:0] _RAND_42;
  reg [63:0] _RAND_43;
  reg [63:0] _RAND_44;
  reg [63:0] _RAND_45;
  reg [63:0] _RAND_46;
  reg [63:0] _RAND_47;
  reg [63:0] _RAND_48;
  reg [63:0] _RAND_49;
  reg [63:0] _RAND_50;
  reg [63:0] _RAND_51;
  reg [63:0] _RAND_52;
  reg [63:0] _RAND_53;
  reg [63:0] _RAND_54;
  reg [63:0] _RAND_55;
  reg [63:0] _RAND_56;
  reg [63:0] _RAND_57;
  reg [63:0] _RAND_58;
  reg [63:0] _RAND_59;
  reg [63:0] _RAND_60;
  reg [63:0] _RAND_61;
  reg [63:0] _RAND_62;
  reg [63:0] _RAND_63;
  reg [63:0] _RAND_64;
  reg [63:0] _RAND_65;
  reg [63:0] _RAND_66;
  reg [63:0] _RAND_67;
  reg [63:0] _RAND_68;
  reg [63:0] _RAND_69;
  reg [63:0] _RAND_70;
  reg [63:0] _RAND_71;
  reg [63:0] _RAND_72;
  reg [63:0] _RAND_73;
  reg [63:0] _RAND_74;
  reg [63:0] _RAND_75;
  reg [63:0] _RAND_76;
  reg [63:0] _RAND_77;
  reg [63:0] _RAND_78;
  reg [63:0] _RAND_79;
  reg [63:0] _RAND_80;
  reg [63:0] _RAND_81;
  reg [63:0] _RAND_82;
  reg [63:0] _RAND_83;
  reg [63:0] _RAND_84;
  reg [63:0] _RAND_85;
  reg [63:0] _RAND_86;
  reg [63:0] _RAND_87;
  reg [63:0] _RAND_88;
  reg [63:0] _RAND_89;
  reg [63:0] _RAND_90;
`endif // RANDOMIZE_REG_INIT
  reg [63:0] reg_mtvec; // @[csr.scala 81:32]
  reg [63:0] reg_mepc; // @[csr.scala 82:32]
  reg [63:0] reg_mcause; // @[csr.scala 83:32]
  reg  reg_mie_mtip; // @[csr.scala 84:32]
  reg  reg_mie_msip; // @[csr.scala 84:32]
  reg  reg_mip_mtip; // @[csr.scala 85:32]
  reg  reg_mip_msip; // @[csr.scala 85:32]
  reg [63:0] reg_mtval; // @[csr.scala 86:32]
  reg [63:0] reg_mscratch; // @[csr.scala 87:32]
  reg [1:0] reg_mstatus_mpp; // @[csr.scala 88:32]
  reg  reg_mstatus_mpie; // @[csr.scala 88:32]
  reg  reg_mstatus_mie; // @[csr.scala 88:32]
  reg [63:0] reg_pmpcfg0; // @[csr.scala 91:31]
  reg [63:0] reg_pmpcfg1; // @[csr.scala 92:31]
  reg [63:0] regs_pmpaddr_0; // @[csr.scala 93:31]
  reg [63:0] regs_pmpaddr_1; // @[csr.scala 93:31]
  reg [63:0] regs_pmpaddr_2; // @[csr.scala 93:31]
  reg [63:0] regs_pmpaddr_3; // @[csr.scala 93:31]
  reg [63:0] regs_pmpaddr_4; // @[csr.scala 93:31]
  reg [63:0] regs_pmpaddr_5; // @[csr.scala 93:31]
  reg [63:0] regs_pmpaddr_6; // @[csr.scala 93:31]
  reg [63:0] regs_pmpaddr_7; // @[csr.scala 93:31]
  reg [63:0] regs_pmpaddr_8; // @[csr.scala 93:31]
  reg [63:0] regs_pmpaddr_9; // @[csr.scala 93:31]
  reg [63:0] regs_pmpaddr_10; // @[csr.scala 93:31]
  reg [63:0] regs_pmpaddr_11; // @[csr.scala 93:31]
  reg [63:0] regs_pmpaddr_12; // @[csr.scala 93:31]
  reg [63:0] regs_pmpaddr_13; // @[csr.scala 93:31]
  reg [63:0] regs_pmpaddr_14; // @[csr.scala 93:31]
  reg [63:0] regs_pmpaddr_15; // @[csr.scala 93:31]
  reg [63:0] reg_mcycle; // @[csr.scala 95:38]
  reg [63:0] reg_minstret; // @[csr.scala 96:38]
  reg [63:0] regs_mhpmcounter_0; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_1; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_2; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_3; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_4; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_5; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_6; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_7; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_8; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_9; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_10; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_11; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_12; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_13; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_14; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_15; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_16; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_17; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_18; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_19; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_20; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_21; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_22; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_23; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_24; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_25; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_26; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_27; // @[csr.scala 97:38]
  reg [63:0] regs_mhpmcounter_28; // @[csr.scala 97:38]
  reg [63:0] reg_mcounterinhibit; // @[csr.scala 98:38]
  reg [63:0] regs_mhpmevet_0; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_1; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_2; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_3; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_4; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_5; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_6; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_7; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_8; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_9; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_10; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_11; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_12; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_13; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_14; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_15; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_16; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_17; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_18; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_19; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_20; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_21; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_22; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_23; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_24; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_25; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_26; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_27; // @[csr.scala 99:38]
  reg [63:0] regs_mhpmevet_28; // @[csr.scala 99:38]
  wire [11:0] wire_csr_index = io_inst[31:20]; // @[csr.scala 105:42]
  wire  _T_7 = io_csr_op == 3'h3; // @[csr.scala 108:21]
  wire  _T_8 = io_csr_op == 3'h4; // @[csr.scala 108:44]
  wire  _T_9 = _T_7 | _T_8; // @[csr.scala 108:31]
  wire  _T_11 = io_inst[19:15] == 5'h0; // @[csr.scala 108:83]
  wire  _T_12 = _T_9 & _T_11; // @[csr.scala 108:55]
  wire [2:0] wire_csr_op = _T_12 ? 3'h1 : io_csr_op; // @[csr.scala 109:5]
  wire  csr_read_only = &wire_csr_index[11:10]; // @[csr.scala 120:47]
  wire  _T_14 = wire_csr_op == 3'h2; // @[csr.scala 121:39]
  wire  _T_15 = wire_csr_op == 3'h3; // @[csr.scala 121:64]
  wire  _T_16 = _T_14 | _T_15; // @[csr.scala 121:49]
  wire  _T_17 = wire_csr_op == 3'h4; // @[csr.scala 121:89]
  wire  _T_18 = _T_16 | _T_17; // @[csr.scala 121:74]
  wire  write_illegal = _T_18 & csr_read_only; // @[csr.scala 121:100]
  wire [10:0] _T_28 = {3'h0,reg_mstatus_mpie,2'h0,1'h0,reg_mstatus_mie,1'h0,2'h0}; // @[csr.scala 130:42]
  wire [63:0] _T_39 = {45'h0,4'h0,2'h0,reg_mstatus_mpp,_T_28}; // @[csr.scala 130:42]
  wire [15:0] _T_52 = {7'h0,1'h0,reg_mie_mtip,1'h0,2'h0,reg_mie_msip,3'h0}; // @[csr.scala 134:38]
  wire [15:0] _T_65 = {7'h0,1'h0,reg_mip_mtip,1'h0,2'h0,reg_mip_msip,3'h0}; // @[csr.scala 135:38]
  wire  _T_66 = wire_csr_index == 12'hf11; // @[csr.scala 165:89]
  wire  _T_67 = wire_csr_index == 12'hf12; // @[csr.scala 165:89]
  wire  _T_68 = wire_csr_index == 12'hf13; // @[csr.scala 165:89]
  wire  _T_69 = wire_csr_index == 12'hf14; // @[csr.scala 165:89]
  wire  _T_70 = wire_csr_index == 12'h300; // @[csr.scala 165:89]
  wire  _T_71 = wire_csr_index == 12'h301; // @[csr.scala 165:89]
  wire  _T_72 = wire_csr_index == 12'h302; // @[csr.scala 165:89]
  wire  _T_73 = wire_csr_index == 12'h303; // @[csr.scala 165:89]
  wire  _T_74 = wire_csr_index == 12'h304; // @[csr.scala 165:89]
  wire  _T_75 = wire_csr_index == 12'h344; // @[csr.scala 165:89]
  wire  _T_76 = wire_csr_index == 12'h305; // @[csr.scala 165:89]
  wire  _T_77 = wire_csr_index == 12'h306; // @[csr.scala 165:89]
  wire  _T_78 = wire_csr_index == 12'h340; // @[csr.scala 165:89]
  wire  _T_79 = wire_csr_index == 12'h341; // @[csr.scala 165:89]
  wire  _T_80 = wire_csr_index == 12'h342; // @[csr.scala 165:89]
  wire  _T_81 = wire_csr_index == 12'h343; // @[csr.scala 165:89]
  wire  _T_82 = wire_csr_index == 12'h3a0; // @[csr.scala 165:89]
  wire  _T_83 = wire_csr_index == 12'h3a1; // @[csr.scala 165:89]
  wire  _T_84 = wire_csr_index == 12'hb00; // @[csr.scala 165:89]
  wire  _T_85 = wire_csr_index == 12'hb02; // @[csr.scala 165:89]
  wire  _T_86 = wire_csr_index == 12'h320; // @[csr.scala 165:89]
  wire  _T_87 = wire_csr_index == 12'h3b0; // @[csr.scala 165:89]
  wire  _T_88 = wire_csr_index == 12'h3b1; // @[csr.scala 165:89]
  wire  _T_89 = wire_csr_index == 12'h3b2; // @[csr.scala 165:89]
  wire  _T_90 = wire_csr_index == 12'h3b3; // @[csr.scala 165:89]
  wire  _T_91 = wire_csr_index == 12'h3b4; // @[csr.scala 165:89]
  wire  _T_92 = wire_csr_index == 12'h3b5; // @[csr.scala 165:89]
  wire  _T_93 = wire_csr_index == 12'h3b6; // @[csr.scala 165:89]
  wire  _T_94 = wire_csr_index == 12'h3b7; // @[csr.scala 165:89]
  wire  _T_95 = wire_csr_index == 12'h3b8; // @[csr.scala 165:89]
  wire  _T_96 = wire_csr_index == 12'h3b9; // @[csr.scala 165:89]
  wire  _T_97 = wire_csr_index == 12'h3ba; // @[csr.scala 165:89]
  wire  _T_98 = wire_csr_index == 12'h3bb; // @[csr.scala 165:89]
  wire  _T_99 = wire_csr_index == 12'h3bc; // @[csr.scala 165:89]
  wire  _T_100 = wire_csr_index == 12'h3bd; // @[csr.scala 165:89]
  wire  _T_101 = wire_csr_index == 12'h3be; // @[csr.scala 165:89]
  wire  _T_102 = wire_csr_index == 12'h3bf; // @[csr.scala 165:89]
  wire  _T_103 = wire_csr_index == 12'hb03; // @[csr.scala 165:89]
  wire  _T_104 = wire_csr_index == 12'hb04; // @[csr.scala 165:89]
  wire  _T_105 = wire_csr_index == 12'hb05; // @[csr.scala 165:89]
  wire  _T_106 = wire_csr_index == 12'hb06; // @[csr.scala 165:89]
  wire  _T_107 = wire_csr_index == 12'hb07; // @[csr.scala 165:89]
  wire  _T_108 = wire_csr_index == 12'hb08; // @[csr.scala 165:89]
  wire  _T_109 = wire_csr_index == 12'hb09; // @[csr.scala 165:89]
  wire  _T_110 = wire_csr_index == 12'hb0a; // @[csr.scala 165:89]
  wire  _T_111 = wire_csr_index == 12'hb0b; // @[csr.scala 165:89]
  wire  _T_112 = wire_csr_index == 12'hb0c; // @[csr.scala 165:89]
  wire  _T_113 = wire_csr_index == 12'hb0d; // @[csr.scala 165:89]
  wire  _T_114 = wire_csr_index == 12'hb0e; // @[csr.scala 165:89]
  wire  _T_115 = wire_csr_index == 12'hb0f; // @[csr.scala 165:89]
  wire  _T_116 = wire_csr_index == 12'hb10; // @[csr.scala 165:89]
  wire  _T_117 = wire_csr_index == 12'hb11; // @[csr.scala 165:89]
  wire  _T_118 = wire_csr_index == 12'hb12; // @[csr.scala 165:89]
  wire  _T_119 = wire_csr_index == 12'hb13; // @[csr.scala 165:89]
  wire  _T_120 = wire_csr_index == 12'hb14; // @[csr.scala 165:89]
  wire  _T_121 = wire_csr_index == 12'hb15; // @[csr.scala 165:89]
  wire  _T_122 = wire_csr_index == 12'hb16; // @[csr.scala 165:89]
  wire  _T_123 = wire_csr_index == 12'hb17; // @[csr.scala 165:89]
  wire  _T_124 = wire_csr_index == 12'hb18; // @[csr.scala 165:89]
  wire  _T_125 = wire_csr_index == 12'hb19; // @[csr.scala 165:89]
  wire  _T_126 = wire_csr_index == 12'hb1a; // @[csr.scala 165:89]
  wire  _T_127 = wire_csr_index == 12'hb1b; // @[csr.scala 165:89]
  wire  _T_128 = wire_csr_index == 12'hb1c; // @[csr.scala 165:89]
  wire  _T_129 = wire_csr_index == 12'hb1d; // @[csr.scala 165:89]
  wire  _T_130 = wire_csr_index == 12'hb1e; // @[csr.scala 165:89]
  wire  _T_131 = wire_csr_index == 12'hb1f; // @[csr.scala 165:89]
  wire  _T_132 = wire_csr_index == 12'h323; // @[csr.scala 165:89]
  wire  _T_133 = wire_csr_index == 12'h324; // @[csr.scala 165:89]
  wire  _T_134 = wire_csr_index == 12'h325; // @[csr.scala 165:89]
  wire  _T_135 = wire_csr_index == 12'h326; // @[csr.scala 165:89]
  wire  _T_136 = wire_csr_index == 12'h327; // @[csr.scala 165:89]
  wire  _T_137 = wire_csr_index == 12'h328; // @[csr.scala 165:89]
  wire  _T_138 = wire_csr_index == 12'h329; // @[csr.scala 165:89]
  wire  _T_139 = wire_csr_index == 12'h32a; // @[csr.scala 165:89]
  wire  _T_140 = wire_csr_index == 12'h32b; // @[csr.scala 165:89]
  wire  _T_141 = wire_csr_index == 12'h32c; // @[csr.scala 165:89]
  wire  _T_142 = wire_csr_index == 12'h32d; // @[csr.scala 165:89]
  wire  _T_143 = wire_csr_index == 12'h32e; // @[csr.scala 165:89]
  wire  _T_144 = wire_csr_index == 12'h32f; // @[csr.scala 165:89]
  wire  _T_145 = wire_csr_index == 12'h330; // @[csr.scala 165:89]
  wire  _T_146 = wire_csr_index == 12'h331; // @[csr.scala 165:89]
  wire  _T_147 = wire_csr_index == 12'h332; // @[csr.scala 165:89]
  wire  _T_148 = wire_csr_index == 12'h333; // @[csr.scala 165:89]
  wire  _T_149 = wire_csr_index == 12'h334; // @[csr.scala 165:89]
  wire  _T_150 = wire_csr_index == 12'h335; // @[csr.scala 165:89]
  wire  _T_151 = wire_csr_index == 12'h336; // @[csr.scala 165:89]
  wire  _T_152 = wire_csr_index == 12'h337; // @[csr.scala 165:89]
  wire  _T_153 = wire_csr_index == 12'h338; // @[csr.scala 165:89]
  wire  _T_154 = wire_csr_index == 12'h339; // @[csr.scala 165:89]
  wire  _T_155 = wire_csr_index == 12'h33a; // @[csr.scala 165:89]
  wire  _T_156 = wire_csr_index == 12'h33b; // @[csr.scala 165:89]
  wire  _T_157 = wire_csr_index == 12'h33c; // @[csr.scala 165:89]
  wire  _T_158 = wire_csr_index == 12'h33d; // @[csr.scala 165:89]
  wire  _T_159 = wire_csr_index == 12'h33e; // @[csr.scala 165:89]
  wire  _T_160 = wire_csr_index == 12'h33f; // @[csr.scala 165:89]
  wire  _T_161 = _T_66 | _T_67; // @[csr.scala 165:108]
  wire  _T_162 = _T_161 | _T_68; // @[csr.scala 165:108]
  wire  _T_163 = _T_162 | _T_69; // @[csr.scala 165:108]
  wire  _T_164 = _T_163 | _T_70; // @[csr.scala 165:108]
  wire  _T_165 = _T_164 | _T_71; // @[csr.scala 165:108]
  wire  _T_166 = _T_165 | _T_72; // @[csr.scala 165:108]
  wire  _T_167 = _T_166 | _T_73; // @[csr.scala 165:108]
  wire  _T_168 = _T_167 | _T_74; // @[csr.scala 165:108]
  wire  _T_169 = _T_168 | _T_75; // @[csr.scala 165:108]
  wire  _T_170 = _T_169 | _T_76; // @[csr.scala 165:108]
  wire  _T_171 = _T_170 | _T_77; // @[csr.scala 165:108]
  wire  _T_172 = _T_171 | _T_78; // @[csr.scala 165:108]
  wire  _T_173 = _T_172 | _T_79; // @[csr.scala 165:108]
  wire  _T_174 = _T_173 | _T_80; // @[csr.scala 165:108]
  wire  _T_175 = _T_174 | _T_81; // @[csr.scala 165:108]
  wire  _T_176 = _T_175 | _T_82; // @[csr.scala 165:108]
  wire  _T_177 = _T_176 | _T_83; // @[csr.scala 165:108]
  wire  _T_178 = _T_177 | _T_84; // @[csr.scala 165:108]
  wire  _T_179 = _T_178 | _T_85; // @[csr.scala 165:108]
  wire  _T_180 = _T_179 | _T_86; // @[csr.scala 165:108]
  wire  _T_181 = _T_180 | _T_87; // @[csr.scala 165:108]
  wire  _T_182 = _T_181 | _T_88; // @[csr.scala 165:108]
  wire  _T_183 = _T_182 | _T_89; // @[csr.scala 165:108]
  wire  _T_184 = _T_183 | _T_90; // @[csr.scala 165:108]
  wire  _T_185 = _T_184 | _T_91; // @[csr.scala 165:108]
  wire  _T_186 = _T_185 | _T_92; // @[csr.scala 165:108]
  wire  _T_187 = _T_186 | _T_93; // @[csr.scala 165:108]
  wire  _T_188 = _T_187 | _T_94; // @[csr.scala 165:108]
  wire  _T_189 = _T_188 | _T_95; // @[csr.scala 165:108]
  wire  _T_190 = _T_189 | _T_96; // @[csr.scala 165:108]
  wire  _T_191 = _T_190 | _T_97; // @[csr.scala 165:108]
  wire  _T_192 = _T_191 | _T_98; // @[csr.scala 165:108]
  wire  _T_193 = _T_192 | _T_99; // @[csr.scala 165:108]
  wire  _T_194 = _T_193 | _T_100; // @[csr.scala 165:108]
  wire  _T_195 = _T_194 | _T_101; // @[csr.scala 165:108]
  wire  _T_196 = _T_195 | _T_102; // @[csr.scala 165:108]
  wire  _T_197 = _T_196 | _T_103; // @[csr.scala 165:108]
  wire  _T_198 = _T_197 | _T_104; // @[csr.scala 165:108]
  wire  _T_199 = _T_198 | _T_105; // @[csr.scala 165:108]
  wire  _T_200 = _T_199 | _T_106; // @[csr.scala 165:108]
  wire  _T_201 = _T_200 | _T_107; // @[csr.scala 165:108]
  wire  _T_202 = _T_201 | _T_108; // @[csr.scala 165:108]
  wire  _T_203 = _T_202 | _T_109; // @[csr.scala 165:108]
  wire  _T_204 = _T_203 | _T_110; // @[csr.scala 165:108]
  wire  _T_205 = _T_204 | _T_111; // @[csr.scala 165:108]
  wire  _T_206 = _T_205 | _T_112; // @[csr.scala 165:108]
  wire  _T_207 = _T_206 | _T_113; // @[csr.scala 165:108]
  wire  _T_208 = _T_207 | _T_114; // @[csr.scala 165:108]
  wire  _T_209 = _T_208 | _T_115; // @[csr.scala 165:108]
  wire  _T_210 = _T_209 | _T_116; // @[csr.scala 165:108]
  wire  _T_211 = _T_210 | _T_117; // @[csr.scala 165:108]
  wire  _T_212 = _T_211 | _T_118; // @[csr.scala 165:108]
  wire  _T_213 = _T_212 | _T_119; // @[csr.scala 165:108]
  wire  _T_214 = _T_213 | _T_120; // @[csr.scala 165:108]
  wire  _T_215 = _T_214 | _T_121; // @[csr.scala 165:108]
  wire  _T_216 = _T_215 | _T_122; // @[csr.scala 165:108]
  wire  _T_217 = _T_216 | _T_123; // @[csr.scala 165:108]
  wire  _T_218 = _T_217 | _T_124; // @[csr.scala 165:108]
  wire  _T_219 = _T_218 | _T_125; // @[csr.scala 165:108]
  wire  _T_220 = _T_219 | _T_126; // @[csr.scala 165:108]
  wire  _T_221 = _T_220 | _T_127; // @[csr.scala 165:108]
  wire  _T_222 = _T_221 | _T_128; // @[csr.scala 165:108]
  wire  _T_223 = _T_222 | _T_129; // @[csr.scala 165:108]
  wire  _T_224 = _T_223 | _T_130; // @[csr.scala 165:108]
  wire  _T_225 = _T_224 | _T_131; // @[csr.scala 165:108]
  wire  _T_226 = _T_225 | _T_132; // @[csr.scala 165:108]
  wire  _T_227 = _T_226 | _T_133; // @[csr.scala 165:108]
  wire  _T_228 = _T_227 | _T_134; // @[csr.scala 165:108]
  wire  _T_229 = _T_228 | _T_135; // @[csr.scala 165:108]
  wire  _T_230 = _T_229 | _T_136; // @[csr.scala 165:108]
  wire  _T_231 = _T_230 | _T_137; // @[csr.scala 165:108]
  wire  _T_232 = _T_231 | _T_138; // @[csr.scala 165:108]
  wire  _T_233 = _T_232 | _T_139; // @[csr.scala 165:108]
  wire  _T_234 = _T_233 | _T_140; // @[csr.scala 165:108]
  wire  _T_235 = _T_234 | _T_141; // @[csr.scala 165:108]
  wire  _T_236 = _T_235 | _T_142; // @[csr.scala 165:108]
  wire  _T_237 = _T_236 | _T_143; // @[csr.scala 165:108]
  wire  _T_238 = _T_237 | _T_144; // @[csr.scala 165:108]
  wire  _T_239 = _T_238 | _T_145; // @[csr.scala 165:108]
  wire  _T_240 = _T_239 | _T_146; // @[csr.scala 165:108]
  wire  _T_241 = _T_240 | _T_147; // @[csr.scala 165:108]
  wire  _T_242 = _T_241 | _T_148; // @[csr.scala 165:108]
  wire  _T_243 = _T_242 | _T_149; // @[csr.scala 165:108]
  wire  _T_244 = _T_243 | _T_150; // @[csr.scala 165:108]
  wire  _T_245 = _T_244 | _T_151; // @[csr.scala 165:108]
  wire  _T_246 = _T_245 | _T_152; // @[csr.scala 165:108]
  wire  _T_247 = _T_246 | _T_153; // @[csr.scala 165:108]
  wire  _T_248 = _T_247 | _T_154; // @[csr.scala 165:108]
  wire  _T_249 = _T_248 | _T_155; // @[csr.scala 165:108]
  wire  _T_250 = _T_249 | _T_156; // @[csr.scala 165:108]
  wire  _T_251 = _T_250 | _T_157; // @[csr.scala 165:108]
  wire  _T_252 = _T_251 | _T_158; // @[csr.scala 165:108]
  wire  _T_253 = _T_252 | _T_159; // @[csr.scala 165:108]
  wire  csr_legal = _T_253 | _T_160; // @[csr.scala 165:108]
  wire  _T_254 = io_csr_op != 3'h0; // @[csr.scala 166:35]
  wire  _T_255 = io_csr_op != 3'h5; // @[csr.scala 166:58]
  wire  _T_256 = _T_254 & _T_255; // @[csr.scala 166:45]
  wire  _T_257 = ~csr_legal; // @[csr.scala 166:74]
  wire  read_illegal = _T_256 & _T_257; // @[csr.scala 166:71]
  wire  exception_in_csr = read_illegal | write_illegal; // @[csr.scala 168:41]
  wire  _T_261 = ~read_illegal; // @[csr.scala 170:77]
  wire  csr_read_enable = _T_256 & _T_261; // @[csr.scala 170:74]
  wire  _T_266 = 12'h300 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_267 = 12'h301 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_270 = 12'h304 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_271 = 12'h344 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_272 = 12'h305 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_274 = 12'h340 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_275 = 12'h341 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_276 = 12'h342 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_277 = 12'h343 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_278 = 12'h3a0 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_279 = 12'h3a1 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_280 = 12'hb00 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_281 = 12'hb02 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_282 = 12'h320 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_283 = 12'h3b0 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_284 = 12'h3b1 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_285 = 12'h3b2 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_286 = 12'h3b3 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_287 = 12'h3b4 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_288 = 12'h3b5 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_289 = 12'h3b6 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_290 = 12'h3b7 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_291 = 12'h3b8 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_292 = 12'h3b9 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_293 = 12'h3ba == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_294 = 12'h3bb == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_295 = 12'h3bc == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_296 = 12'h3bd == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_297 = 12'h3be == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_298 = 12'h3bf == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_299 = 12'hb03 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_300 = 12'hb04 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_301 = 12'hb05 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_302 = 12'hb06 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_303 = 12'hb07 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_304 = 12'hb08 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_305 = 12'hb09 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_306 = 12'hb0a == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_307 = 12'hb0b == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_308 = 12'hb0c == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_309 = 12'hb0d == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_310 = 12'hb0e == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_311 = 12'hb0f == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_312 = 12'hb10 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_313 = 12'hb11 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_314 = 12'hb12 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_315 = 12'hb13 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_316 = 12'hb14 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_317 = 12'hb15 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_318 = 12'hb16 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_319 = 12'hb17 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_320 = 12'hb18 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_321 = 12'hb19 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_322 = 12'hb1a == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_323 = 12'hb1b == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_324 = 12'hb1c == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_325 = 12'hb1d == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_326 = 12'hb1e == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_327 = 12'hb1f == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_328 = 12'h323 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_329 = 12'h324 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_330 = 12'h325 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_331 = 12'h326 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_332 = 12'h327 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_333 = 12'h328 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_334 = 12'h329 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_335 = 12'h32a == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_336 = 12'h32b == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_337 = 12'h32c == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_338 = 12'h32d == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_339 = 12'h32e == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_340 = 12'h32f == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_341 = 12'h330 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_342 = 12'h331 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_343 = 12'h332 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_344 = 12'h333 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_345 = 12'h334 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_346 = 12'h335 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_347 = 12'h336 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_348 = 12'h337 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_349 = 12'h338 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_350 = 12'h339 == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_351 = 12'h33a == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_352 = 12'h33b == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_353 = 12'h33c == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_354 = 12'h33d == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_355 = 12'h33e == wire_csr_index; // @[csr.scala 176:61]
  wire  _T_356 = 12'h33f == wire_csr_index; // @[csr.scala 176:61]
  wire [63:0] _T_9291 = _T_266 ? _T_39 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9292 = _T_267 ? 64'h8000000000001100 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_40 = {{48'd0}, _T_52}; // @[csr.scala 134:38 csr.scala 134:38]
  wire [63:0] _T_9295 = _T_270 ? _T_40 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_53 = {{48'd0}, _T_65}; // @[csr.scala 135:38 csr.scala 135:38]
  wire [63:0] _T_9296 = _T_271 ? _T_53 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9297 = _T_272 ? reg_mtvec : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9299 = _T_274 ? reg_mscratch : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9300 = _T_275 ? reg_mepc : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9301 = _T_276 ? reg_mcause : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9302 = _T_277 ? reg_mtval : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9303 = _T_278 ? reg_pmpcfg0 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9304 = _T_279 ? reg_pmpcfg1 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9305 = _T_280 ? reg_mcycle : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9306 = _T_281 ? reg_minstret : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9307 = _T_282 ? reg_mcounterinhibit : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9308 = _T_283 ? regs_pmpaddr_0 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9309 = _T_284 ? regs_pmpaddr_1 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9310 = _T_285 ? regs_pmpaddr_2 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9311 = _T_286 ? regs_pmpaddr_3 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9312 = _T_287 ? regs_pmpaddr_4 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9313 = _T_288 ? regs_pmpaddr_5 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9314 = _T_289 ? regs_pmpaddr_6 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9315 = _T_290 ? regs_pmpaddr_7 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9316 = _T_291 ? regs_pmpaddr_8 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9317 = _T_292 ? regs_pmpaddr_9 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9318 = _T_293 ? regs_pmpaddr_10 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9319 = _T_294 ? regs_pmpaddr_11 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9320 = _T_295 ? regs_pmpaddr_12 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9321 = _T_296 ? regs_pmpaddr_13 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9322 = _T_297 ? regs_pmpaddr_14 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9323 = _T_298 ? regs_pmpaddr_15 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9324 = _T_299 ? regs_mhpmcounter_0 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9325 = _T_300 ? regs_mhpmcounter_1 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9326 = _T_301 ? regs_mhpmcounter_2 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9327 = _T_302 ? regs_mhpmcounter_3 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9328 = _T_303 ? regs_mhpmcounter_4 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9329 = _T_304 ? regs_mhpmcounter_5 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9330 = _T_305 ? regs_mhpmcounter_6 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9331 = _T_306 ? regs_mhpmcounter_7 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9332 = _T_307 ? regs_mhpmcounter_8 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9333 = _T_308 ? regs_mhpmcounter_9 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9334 = _T_309 ? regs_mhpmcounter_10 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9335 = _T_310 ? regs_mhpmcounter_11 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9336 = _T_311 ? regs_mhpmcounter_12 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9337 = _T_312 ? regs_mhpmcounter_13 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9338 = _T_313 ? regs_mhpmcounter_14 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9339 = _T_314 ? regs_mhpmcounter_15 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9340 = _T_315 ? regs_mhpmcounter_16 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9341 = _T_316 ? regs_mhpmcounter_17 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9342 = _T_317 ? regs_mhpmcounter_18 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9343 = _T_318 ? regs_mhpmcounter_19 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9344 = _T_319 ? regs_mhpmcounter_20 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9345 = _T_320 ? regs_mhpmcounter_21 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9346 = _T_321 ? regs_mhpmcounter_22 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9347 = _T_322 ? regs_mhpmcounter_23 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9348 = _T_323 ? regs_mhpmcounter_24 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9349 = _T_324 ? regs_mhpmcounter_25 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9350 = _T_325 ? regs_mhpmcounter_26 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9351 = _T_326 ? regs_mhpmcounter_27 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9352 = _T_327 ? regs_mhpmcounter_28 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9353 = _T_328 ? regs_mhpmevet_0 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9354 = _T_329 ? regs_mhpmevet_1 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9355 = _T_330 ? regs_mhpmevet_2 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9356 = _T_331 ? regs_mhpmevet_3 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9357 = _T_332 ? regs_mhpmevet_4 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9358 = _T_333 ? regs_mhpmevet_5 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9359 = _T_334 ? regs_mhpmevet_6 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9360 = _T_335 ? regs_mhpmevet_7 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9361 = _T_336 ? regs_mhpmevet_8 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9362 = _T_337 ? regs_mhpmevet_9 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9363 = _T_338 ? regs_mhpmevet_10 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9364 = _T_339 ? regs_mhpmevet_11 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9365 = _T_340 ? regs_mhpmevet_12 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9366 = _T_341 ? regs_mhpmevet_13 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9367 = _T_342 ? regs_mhpmevet_14 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9368 = _T_343 ? regs_mhpmevet_15 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9369 = _T_344 ? regs_mhpmevet_16 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9370 = _T_345 ? regs_mhpmevet_17 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9371 = _T_346 ? regs_mhpmevet_18 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9372 = _T_347 ? regs_mhpmevet_19 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9373 = _T_348 ? regs_mhpmevet_20 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9374 = _T_349 ? regs_mhpmevet_21 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9375 = _T_350 ? regs_mhpmevet_22 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9376 = _T_351 ? regs_mhpmevet_23 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9377 = _T_352 ? regs_mhpmevet_24 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9378 = _T_353 ? regs_mhpmevet_25 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9379 = _T_354 ? regs_mhpmevet_26 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9380 = _T_355 ? regs_mhpmevet_27 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9381 = _T_356 ? regs_mhpmevet_28 : 64'h0; // @[Mux.scala 27:72]
  wire [63:0] _T_9386 = _T_9291 | _T_9292; // @[Mux.scala 27:72]
  wire [63:0] _T_9389 = _T_9386 | _T_9295; // @[Mux.scala 27:72]
  wire [63:0] _T_9390 = _T_9389 | _T_9296; // @[Mux.scala 27:72]
  wire [63:0] _T_9391 = _T_9390 | _T_9297; // @[Mux.scala 27:72]
  wire [63:0] _T_9393 = _T_9391 | _T_9299; // @[Mux.scala 27:72]
  wire [63:0] _T_9394 = _T_9393 | _T_9300; // @[Mux.scala 27:72]
  wire [63:0] _T_9395 = _T_9394 | _T_9301; // @[Mux.scala 27:72]
  wire [63:0] _T_9396 = _T_9395 | _T_9302; // @[Mux.scala 27:72]
  wire [63:0] _T_9397 = _T_9396 | _T_9303; // @[Mux.scala 27:72]
  wire [63:0] _T_9398 = _T_9397 | _T_9304; // @[Mux.scala 27:72]
  wire [63:0] _T_9399 = _T_9398 | _T_9305; // @[Mux.scala 27:72]
  wire [63:0] _T_9400 = _T_9399 | _T_9306; // @[Mux.scala 27:72]
  wire [63:0] _T_9401 = _T_9400 | _T_9307; // @[Mux.scala 27:72]
  wire [63:0] _T_9402 = _T_9401 | _T_9308; // @[Mux.scala 27:72]
  wire [63:0] _T_9403 = _T_9402 | _T_9309; // @[Mux.scala 27:72]
  wire [63:0] _T_9404 = _T_9403 | _T_9310; // @[Mux.scala 27:72]
  wire [63:0] _T_9405 = _T_9404 | _T_9311; // @[Mux.scala 27:72]
  wire [63:0] _T_9406 = _T_9405 | _T_9312; // @[Mux.scala 27:72]
  wire [63:0] _T_9407 = _T_9406 | _T_9313; // @[Mux.scala 27:72]
  wire [63:0] _T_9408 = _T_9407 | _T_9314; // @[Mux.scala 27:72]
  wire [63:0] _T_9409 = _T_9408 | _T_9315; // @[Mux.scala 27:72]
  wire [63:0] _T_9410 = _T_9409 | _T_9316; // @[Mux.scala 27:72]
  wire [63:0] _T_9411 = _T_9410 | _T_9317; // @[Mux.scala 27:72]
  wire [63:0] _T_9412 = _T_9411 | _T_9318; // @[Mux.scala 27:72]
  wire [63:0] _T_9413 = _T_9412 | _T_9319; // @[Mux.scala 27:72]
  wire [63:0] _T_9414 = _T_9413 | _T_9320; // @[Mux.scala 27:72]
  wire [63:0] _T_9415 = _T_9414 | _T_9321; // @[Mux.scala 27:72]
  wire [63:0] _T_9416 = _T_9415 | _T_9322; // @[Mux.scala 27:72]
  wire [63:0] _T_9417 = _T_9416 | _T_9323; // @[Mux.scala 27:72]
  wire [63:0] _T_9418 = _T_9417 | _T_9324; // @[Mux.scala 27:72]
  wire [63:0] _T_9419 = _T_9418 | _T_9325; // @[Mux.scala 27:72]
  wire [63:0] _T_9420 = _T_9419 | _T_9326; // @[Mux.scala 27:72]
  wire [63:0] _T_9421 = _T_9420 | _T_9327; // @[Mux.scala 27:72]
  wire [63:0] _T_9422 = _T_9421 | _T_9328; // @[Mux.scala 27:72]
  wire [63:0] _T_9423 = _T_9422 | _T_9329; // @[Mux.scala 27:72]
  wire [63:0] _T_9424 = _T_9423 | _T_9330; // @[Mux.scala 27:72]
  wire [63:0] _T_9425 = _T_9424 | _T_9331; // @[Mux.scala 27:72]
  wire [63:0] _T_9426 = _T_9425 | _T_9332; // @[Mux.scala 27:72]
  wire [63:0] _T_9427 = _T_9426 | _T_9333; // @[Mux.scala 27:72]
  wire [63:0] _T_9428 = _T_9427 | _T_9334; // @[Mux.scala 27:72]
  wire [63:0] _T_9429 = _T_9428 | _T_9335; // @[Mux.scala 27:72]
  wire [63:0] _T_9430 = _T_9429 | _T_9336; // @[Mux.scala 27:72]
  wire [63:0] _T_9431 = _T_9430 | _T_9337; // @[Mux.scala 27:72]
  wire [63:0] _T_9432 = _T_9431 | _T_9338; // @[Mux.scala 27:72]
  wire [63:0] _T_9433 = _T_9432 | _T_9339; // @[Mux.scala 27:72]
  wire [63:0] _T_9434 = _T_9433 | _T_9340; // @[Mux.scala 27:72]
  wire [63:0] _T_9435 = _T_9434 | _T_9341; // @[Mux.scala 27:72]
  wire [63:0] _T_9436 = _T_9435 | _T_9342; // @[Mux.scala 27:72]
  wire [63:0] _T_9437 = _T_9436 | _T_9343; // @[Mux.scala 27:72]
  wire [63:0] _T_9438 = _T_9437 | _T_9344; // @[Mux.scala 27:72]
  wire [63:0] _T_9439 = _T_9438 | _T_9345; // @[Mux.scala 27:72]
  wire [63:0] _T_9440 = _T_9439 | _T_9346; // @[Mux.scala 27:72]
  wire [63:0] _T_9441 = _T_9440 | _T_9347; // @[Mux.scala 27:72]
  wire [63:0] _T_9442 = _T_9441 | _T_9348; // @[Mux.scala 27:72]
  wire [63:0] _T_9443 = _T_9442 | _T_9349; // @[Mux.scala 27:72]
  wire [63:0] _T_9444 = _T_9443 | _T_9350; // @[Mux.scala 27:72]
  wire [63:0] _T_9445 = _T_9444 | _T_9351; // @[Mux.scala 27:72]
  wire [63:0] _T_9446 = _T_9445 | _T_9352; // @[Mux.scala 27:72]
  wire [63:0] _T_9447 = _T_9446 | _T_9353; // @[Mux.scala 27:72]
  wire [63:0] _T_9448 = _T_9447 | _T_9354; // @[Mux.scala 27:72]
  wire [63:0] _T_9449 = _T_9448 | _T_9355; // @[Mux.scala 27:72]
  wire [63:0] _T_9450 = _T_9449 | _T_9356; // @[Mux.scala 27:72]
  wire [63:0] _T_9451 = _T_9450 | _T_9357; // @[Mux.scala 27:72]
  wire [63:0] _T_9452 = _T_9451 | _T_9358; // @[Mux.scala 27:72]
  wire [63:0] _T_9453 = _T_9452 | _T_9359; // @[Mux.scala 27:72]
  wire [63:0] _T_9454 = _T_9453 | _T_9360; // @[Mux.scala 27:72]
  wire [63:0] _T_9455 = _T_9454 | _T_9361; // @[Mux.scala 27:72]
  wire [63:0] _T_9456 = _T_9455 | _T_9362; // @[Mux.scala 27:72]
  wire [63:0] _T_9457 = _T_9456 | _T_9363; // @[Mux.scala 27:72]
  wire [63:0] _T_9458 = _T_9457 | _T_9364; // @[Mux.scala 27:72]
  wire [63:0] _T_9459 = _T_9458 | _T_9365; // @[Mux.scala 27:72]
  wire [63:0] _T_9460 = _T_9459 | _T_9366; // @[Mux.scala 27:72]
  wire [63:0] _T_9461 = _T_9460 | _T_9367; // @[Mux.scala 27:72]
  wire [63:0] _T_9462 = _T_9461 | _T_9368; // @[Mux.scala 27:72]
  wire [63:0] _T_9463 = _T_9462 | _T_9369; // @[Mux.scala 27:72]
  wire [63:0] _T_9464 = _T_9463 | _T_9370; // @[Mux.scala 27:72]
  wire [63:0] _T_9465 = _T_9464 | _T_9371; // @[Mux.scala 27:72]
  wire [63:0] _T_9466 = _T_9465 | _T_9372; // @[Mux.scala 27:72]
  wire [63:0] _T_9467 = _T_9466 | _T_9373; // @[Mux.scala 27:72]
  wire [63:0] _T_9468 = _T_9467 | _T_9374; // @[Mux.scala 27:72]
  wire [63:0] _T_9469 = _T_9468 | _T_9375; // @[Mux.scala 27:72]
  wire [63:0] _T_9470 = _T_9469 | _T_9376; // @[Mux.scala 27:72]
  wire [63:0] _T_9471 = _T_9470 | _T_9377; // @[Mux.scala 27:72]
  wire [63:0] _T_9472 = _T_9471 | _T_9378; // @[Mux.scala 27:72]
  wire [63:0] _T_9473 = _T_9472 | _T_9379; // @[Mux.scala 27:72]
  wire [63:0] _T_9474 = _T_9473 | _T_9380; // @[Mux.scala 27:72]
  wire [63:0] _T_9475 = _T_9474 | _T_9381; // @[Mux.scala 27:72]
  wire [63:0] csr_read_data = csr_read_enable ? _T_9475 : 64'h0; // @[csr.scala 181:5]
  wire  _T_9477 = io_csr_op == 3'h2; // @[csr.scala 190:20]
  wire [63:0] _T_9479 = csr_read_data | io_data_in; // @[csr.scala 191:49]
  wire [63:0] _T_9481 = ~io_data_in; // @[csr.scala 192:52]
  wire [63:0] _T_9482 = csr_read_data & _T_9481; // @[csr.scala 192:49]
  wire [63:0] _T_9483 = _T_7 ? _T_9482 : csr_read_data; // @[Mux.scala 98:16]
  wire [63:0] _T_9484 = _T_8 ? _T_9479 : _T_9483; // @[Mux.scala 98:16]
  wire [63:0] csr_write_data = _T_9477 ? io_data_in : _T_9484; // @[Mux.scala 98:16]
  wire  _T_9485 = ~write_illegal; // @[csr.scala 195:19]
  wire  _T_9486 = _T_9485 & csr_legal; // @[csr.scala 195:34]
  wire  _T_9491 = wire_csr_op != 3'h0; // @[csr.scala 195:101]
  wire  _T_9492 = wire_csr_op != 3'h5; // @[csr.scala 195:126]
  wire  _T_9493 = _T_9491 & _T_9492; // @[csr.scala 195:111]
  wire  _T_9494 = wire_csr_op != 3'h1; // @[csr.scala 195:153]
  wire  _T_9495 = _T_9493 & _T_9494; // @[csr.scala 195:138]
  wire  csr_wen = _T_9486 & _T_9495; // @[csr.scala 195:85]
  wire  _GEN_3 = _T_266 ? csr_write_data[7] : reg_mstatus_mpie; // @[csr.scala 199:33]
  wire [63:0] _T_10120 = {csr_write_data[63:2], 2'h0}; // @[csr.scala 217:66]
  wire  _GEN_92 = csr_wen ? _GEN_3 : reg_mstatus_mpie; // @[csr.scala 198:18]
  wire  _T_17721 = io_csr_op == 3'h5; // @[csr.scala 251:35]
  wire  _T_17722 = wire_csr_index == 12'h0; // @[csr.scala 251:67]
  wire  csr_isecall = _T_17721 & _T_17722; // @[csr.scala 251:48]
  wire  _T_17724 = wire_csr_index == 12'h1; // @[csr.scala 252:67]
  wire  csr_isebreak = _T_17721 & _T_17724; // @[csr.scala 252:48]
  wire  csr_ismret = _T_17721 & _T_72; // @[csr.scala 253:48]
  wire  _T_17727 = exception_in_csr | csr_isecall; // @[csr.scala 255:55]
  wire  csr_has_exception = _T_17727 | csr_isebreak; // @[csr.scala 255:70]
  wire [63:0] _T_17729 = reg_mcycle + 64'h1; // @[csr.scala 263:30]
  wire  _T_17732 = reg_mip_mtip & reg_mie_mtip; // @[csr.scala 272:23]
  wire  _T_17733 = _T_17732 & reg_mstatus_mie; // @[csr.scala 272:39]
  wire  _T_17736 = io_in_mem_pc != 64'h0; // @[csr.scala 272:91]
  wire  csr_has_interrupt = _T_17733 & _T_17736; // @[csr.scala 272:75]
  wire  _T_17741 = csr_ismret | csr_has_exception; // @[csr.scala 299:29]
  wire  _T_17742 = io_in_exe_pc != 64'h0; // @[csr.scala 302:37]
  wire  _T_17743 = io_in_dec_pc != 64'h0; // @[csr.scala 305:37]
  wire  _T_17744 = io_in_if_pc != 64'h0; // @[csr.scala 308:36]
  wire  _GEN_190 = csr_isebreak ? reg_mstatus_mie : reg_mstatus_mpie; // @[csr.scala 362:13]
  wire [1:0] _GEN_292 = csr_ismret ? reg_mstatus_mpp : 2'h3; // @[csr.scala 322:9]
  wire [1:0] prv_now = csr_has_interrupt ? 2'h3 : _GEN_292; // @[csr.scala 295:9]
  wire  _GEN_217 = csr_isecall ? reg_mstatus_mie : _GEN_190; // @[csr.scala 350:13]
  wire  _GEN_244 = exception_in_csr ? reg_mstatus_mie : _GEN_217; // @[csr.scala 337:13]
  wire  _GEN_199 = csr_isebreak ? _GEN_244 : _GEN_92; // @[csr.scala 362:13]
  wire  _GEN_226 = csr_isecall ? _GEN_244 : _GEN_199; // @[csr.scala 350:13]
  wire  _GEN_253 = exception_in_csr ? _GEN_244 : _GEN_226; // @[csr.scala 337:13]
  wire  _GEN_277 = csr_has_exception ? _GEN_253 : _GEN_92; // @[csr.scala 333:9]
  wire  _GEN_300 = csr_ismret | _GEN_277; // @[csr.scala 322:9]
  wire  _T_17750 = csr_has_exception | csr_has_interrupt; // @[csr.scala 380:28]
  assign io_is_redir = _T_17750 | csr_ismret; // @[csr.scala 382:21 csr.scala 385:21]
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
  reg_mtvec = _RAND_0[63:0];
  _RAND_1 = {2{`RANDOM}};
  reg_mepc = _RAND_1[63:0];
  _RAND_2 = {2{`RANDOM}};
  reg_mcause = _RAND_2[63:0];
  _RAND_3 = {1{`RANDOM}};
  reg_mie_mtip = _RAND_3[0:0];
  _RAND_4 = {1{`RANDOM}};
  reg_mie_msip = _RAND_4[0:0];
  _RAND_5 = {1{`RANDOM}};
  reg_mip_mtip = _RAND_5[0:0];
  _RAND_6 = {1{`RANDOM}};
  reg_mip_msip = _RAND_6[0:0];
  _RAND_7 = {2{`RANDOM}};
  reg_mtval = _RAND_7[63:0];
  _RAND_8 = {2{`RANDOM}};
  reg_mscratch = _RAND_8[63:0];
  _RAND_9 = {1{`RANDOM}};
  reg_mstatus_mpp = _RAND_9[1:0];
  _RAND_10 = {1{`RANDOM}};
  reg_mstatus_mpie = _RAND_10[0:0];
  _RAND_11 = {1{`RANDOM}};
  reg_mstatus_mie = _RAND_11[0:0];
  _RAND_12 = {2{`RANDOM}};
  reg_pmpcfg0 = _RAND_12[63:0];
  _RAND_13 = {2{`RANDOM}};
  reg_pmpcfg1 = _RAND_13[63:0];
  _RAND_14 = {2{`RANDOM}};
  regs_pmpaddr_0 = _RAND_14[63:0];
  _RAND_15 = {2{`RANDOM}};
  regs_pmpaddr_1 = _RAND_15[63:0];
  _RAND_16 = {2{`RANDOM}};
  regs_pmpaddr_2 = _RAND_16[63:0];
  _RAND_17 = {2{`RANDOM}};
  regs_pmpaddr_3 = _RAND_17[63:0];
  _RAND_18 = {2{`RANDOM}};
  regs_pmpaddr_4 = _RAND_18[63:0];
  _RAND_19 = {2{`RANDOM}};
  regs_pmpaddr_5 = _RAND_19[63:0];
  _RAND_20 = {2{`RANDOM}};
  regs_pmpaddr_6 = _RAND_20[63:0];
  _RAND_21 = {2{`RANDOM}};
  regs_pmpaddr_7 = _RAND_21[63:0];
  _RAND_22 = {2{`RANDOM}};
  regs_pmpaddr_8 = _RAND_22[63:0];
  _RAND_23 = {2{`RANDOM}};
  regs_pmpaddr_9 = _RAND_23[63:0];
  _RAND_24 = {2{`RANDOM}};
  regs_pmpaddr_10 = _RAND_24[63:0];
  _RAND_25 = {2{`RANDOM}};
  regs_pmpaddr_11 = _RAND_25[63:0];
  _RAND_26 = {2{`RANDOM}};
  regs_pmpaddr_12 = _RAND_26[63:0];
  _RAND_27 = {2{`RANDOM}};
  regs_pmpaddr_13 = _RAND_27[63:0];
  _RAND_28 = {2{`RANDOM}};
  regs_pmpaddr_14 = _RAND_28[63:0];
  _RAND_29 = {2{`RANDOM}};
  regs_pmpaddr_15 = _RAND_29[63:0];
  _RAND_30 = {2{`RANDOM}};
  reg_mcycle = _RAND_30[63:0];
  _RAND_31 = {2{`RANDOM}};
  reg_minstret = _RAND_31[63:0];
  _RAND_32 = {2{`RANDOM}};
  regs_mhpmcounter_0 = _RAND_32[63:0];
  _RAND_33 = {2{`RANDOM}};
  regs_mhpmcounter_1 = _RAND_33[63:0];
  _RAND_34 = {2{`RANDOM}};
  regs_mhpmcounter_2 = _RAND_34[63:0];
  _RAND_35 = {2{`RANDOM}};
  regs_mhpmcounter_3 = _RAND_35[63:0];
  _RAND_36 = {2{`RANDOM}};
  regs_mhpmcounter_4 = _RAND_36[63:0];
  _RAND_37 = {2{`RANDOM}};
  regs_mhpmcounter_5 = _RAND_37[63:0];
  _RAND_38 = {2{`RANDOM}};
  regs_mhpmcounter_6 = _RAND_38[63:0];
  _RAND_39 = {2{`RANDOM}};
  regs_mhpmcounter_7 = _RAND_39[63:0];
  _RAND_40 = {2{`RANDOM}};
  regs_mhpmcounter_8 = _RAND_40[63:0];
  _RAND_41 = {2{`RANDOM}};
  regs_mhpmcounter_9 = _RAND_41[63:0];
  _RAND_42 = {2{`RANDOM}};
  regs_mhpmcounter_10 = _RAND_42[63:0];
  _RAND_43 = {2{`RANDOM}};
  regs_mhpmcounter_11 = _RAND_43[63:0];
  _RAND_44 = {2{`RANDOM}};
  regs_mhpmcounter_12 = _RAND_44[63:0];
  _RAND_45 = {2{`RANDOM}};
  regs_mhpmcounter_13 = _RAND_45[63:0];
  _RAND_46 = {2{`RANDOM}};
  regs_mhpmcounter_14 = _RAND_46[63:0];
  _RAND_47 = {2{`RANDOM}};
  regs_mhpmcounter_15 = _RAND_47[63:0];
  _RAND_48 = {2{`RANDOM}};
  regs_mhpmcounter_16 = _RAND_48[63:0];
  _RAND_49 = {2{`RANDOM}};
  regs_mhpmcounter_17 = _RAND_49[63:0];
  _RAND_50 = {2{`RANDOM}};
  regs_mhpmcounter_18 = _RAND_50[63:0];
  _RAND_51 = {2{`RANDOM}};
  regs_mhpmcounter_19 = _RAND_51[63:0];
  _RAND_52 = {2{`RANDOM}};
  regs_mhpmcounter_20 = _RAND_52[63:0];
  _RAND_53 = {2{`RANDOM}};
  regs_mhpmcounter_21 = _RAND_53[63:0];
  _RAND_54 = {2{`RANDOM}};
  regs_mhpmcounter_22 = _RAND_54[63:0];
  _RAND_55 = {2{`RANDOM}};
  regs_mhpmcounter_23 = _RAND_55[63:0];
  _RAND_56 = {2{`RANDOM}};
  regs_mhpmcounter_24 = _RAND_56[63:0];
  _RAND_57 = {2{`RANDOM}};
  regs_mhpmcounter_25 = _RAND_57[63:0];
  _RAND_58 = {2{`RANDOM}};
  regs_mhpmcounter_26 = _RAND_58[63:0];
  _RAND_59 = {2{`RANDOM}};
  regs_mhpmcounter_27 = _RAND_59[63:0];
  _RAND_60 = {2{`RANDOM}};
  regs_mhpmcounter_28 = _RAND_60[63:0];
  _RAND_61 = {2{`RANDOM}};
  reg_mcounterinhibit = _RAND_61[63:0];
  _RAND_62 = {2{`RANDOM}};
  regs_mhpmevet_0 = _RAND_62[63:0];
  _RAND_63 = {2{`RANDOM}};
  regs_mhpmevet_1 = _RAND_63[63:0];
  _RAND_64 = {2{`RANDOM}};
  regs_mhpmevet_2 = _RAND_64[63:0];
  _RAND_65 = {2{`RANDOM}};
  regs_mhpmevet_3 = _RAND_65[63:0];
  _RAND_66 = {2{`RANDOM}};
  regs_mhpmevet_4 = _RAND_66[63:0];
  _RAND_67 = {2{`RANDOM}};
  regs_mhpmevet_5 = _RAND_67[63:0];
  _RAND_68 = {2{`RANDOM}};
  regs_mhpmevet_6 = _RAND_68[63:0];
  _RAND_69 = {2{`RANDOM}};
  regs_mhpmevet_7 = _RAND_69[63:0];
  _RAND_70 = {2{`RANDOM}};
  regs_mhpmevet_8 = _RAND_70[63:0];
  _RAND_71 = {2{`RANDOM}};
  regs_mhpmevet_9 = _RAND_71[63:0];
  _RAND_72 = {2{`RANDOM}};
  regs_mhpmevet_10 = _RAND_72[63:0];
  _RAND_73 = {2{`RANDOM}};
  regs_mhpmevet_11 = _RAND_73[63:0];
  _RAND_74 = {2{`RANDOM}};
  regs_mhpmevet_12 = _RAND_74[63:0];
  _RAND_75 = {2{`RANDOM}};
  regs_mhpmevet_13 = _RAND_75[63:0];
  _RAND_76 = {2{`RANDOM}};
  regs_mhpmevet_14 = _RAND_76[63:0];
  _RAND_77 = {2{`RANDOM}};
  regs_mhpmevet_15 = _RAND_77[63:0];
  _RAND_78 = {2{`RANDOM}};
  regs_mhpmevet_16 = _RAND_78[63:0];
  _RAND_79 = {2{`RANDOM}};
  regs_mhpmevet_17 = _RAND_79[63:0];
  _RAND_80 = {2{`RANDOM}};
  regs_mhpmevet_18 = _RAND_80[63:0];
  _RAND_81 = {2{`RANDOM}};
  regs_mhpmevet_19 = _RAND_81[63:0];
  _RAND_82 = {2{`RANDOM}};
  regs_mhpmevet_20 = _RAND_82[63:0];
  _RAND_83 = {2{`RANDOM}};
  regs_mhpmevet_21 = _RAND_83[63:0];
  _RAND_84 = {2{`RANDOM}};
  regs_mhpmevet_22 = _RAND_84[63:0];
  _RAND_85 = {2{`RANDOM}};
  regs_mhpmevet_23 = _RAND_85[63:0];
  _RAND_86 = {2{`RANDOM}};
  regs_mhpmevet_24 = _RAND_86[63:0];
  _RAND_87 = {2{`RANDOM}};
  regs_mhpmevet_25 = _RAND_87[63:0];
  _RAND_88 = {2{`RANDOM}};
  regs_mhpmevet_26 = _RAND_88[63:0];
  _RAND_89 = {2{`RANDOM}};
  regs_mhpmevet_27 = _RAND_89[63:0];
  _RAND_90 = {2{`RANDOM}};
  regs_mhpmevet_28 = _RAND_90[63:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
  always @(posedge clock) begin
    if (reset) begin
      reg_mtvec <= 64'h8000c09c;
    end else if (csr_wen) begin
      if (_T_272) begin
        if (_T_9477) begin
          reg_mtvec <= io_data_in;
        end else if (_T_8) begin
          reg_mtvec <= _T_9479;
        end else if (_T_7) begin
          reg_mtvec <= _T_9482;
        end else if (csr_read_enable) begin
          reg_mtvec <= _T_9475;
        end else begin
          reg_mtvec <= 64'h0;
        end
      end
    end
    if (reset) begin
      reg_mepc <= 64'h0;
    end else if (csr_has_interrupt) begin
      if (_T_17741) begin
        reg_mepc <= io_in_mem_pc;
      end else if (_T_17742) begin
        reg_mepc <= io_in_exe_pc;
      end else if (_T_17743) begin
        reg_mepc <= io_in_dec_pc;
      end else if (_T_17744) begin
        reg_mepc <= io_in_if_pc;
      end else if (csr_wen) begin
        if (_T_275) begin
          reg_mepc <= _T_10120;
        end
      end
    end else if (csr_ismret) begin
      if (csr_wen) begin
        if (_T_275) begin
          reg_mepc <= _T_10120;
        end
      end
    end else if (csr_has_exception) begin
      if (exception_in_csr) begin
        reg_mepc <= io_in_mem_pc;
      end else if (csr_isecall) begin
        reg_mepc <= io_in_mem_pc;
      end else if (csr_isebreak) begin
        reg_mepc <= io_in_mem_pc;
      end else if (csr_wen) begin
        if (_T_275) begin
          reg_mepc <= _T_10120;
        end
      end
    end else if (csr_wen) begin
      if (_T_275) begin
        reg_mepc <= _T_10120;
      end
    end
    if (reset) begin
      reg_mcause <= 64'h0;
    end else if (csr_has_interrupt) begin
      reg_mcause <= 64'h8000000000000007;
    end else if (csr_ismret) begin
      if (csr_wen) begin
        if (_T_276) begin
          if (_T_9477) begin
            reg_mcause <= io_data_in;
          end else if (_T_8) begin
            reg_mcause <= _T_9479;
          end else if (_T_7) begin
            reg_mcause <= _T_9482;
          end else if (csr_read_enable) begin
            reg_mcause <= _T_9475;
          end else begin
            reg_mcause <= 64'h0;
          end
        end
      end
    end else if (csr_has_exception) begin
      if (exception_in_csr) begin
        reg_mcause <= 64'h2;
      end else if (csr_isecall) begin
        reg_mcause <= 64'hb;
      end else if (csr_isebreak) begin
        reg_mcause <= 64'h3;
      end else if (csr_wen) begin
        if (_T_276) begin
          if (_T_9477) begin
            reg_mcause <= io_data_in;
          end else if (_T_8) begin
            reg_mcause <= _T_9479;
          end else if (_T_7) begin
            reg_mcause <= _T_9482;
          end else if (csr_read_enable) begin
            reg_mcause <= _T_9475;
          end else begin
            reg_mcause <= 64'h0;
          end
        end
      end
    end else if (csr_wen) begin
      if (_T_276) begin
        if (_T_9477) begin
          reg_mcause <= io_data_in;
        end else if (_T_8) begin
          reg_mcause <= _T_9479;
        end else if (_T_7) begin
          reg_mcause <= _T_9482;
        end else if (csr_read_enable) begin
          reg_mcause <= _T_9475;
        end else begin
          reg_mcause <= 64'h0;
        end
      end
    end
    if (reset) begin
      reg_mie_mtip <= 1'h0;
    end else if (csr_wen) begin
      if (_T_270) begin
        reg_mie_mtip <= csr_write_data[7];
      end
    end
    if (reset) begin
      reg_mie_msip <= 1'h0;
    end else if (csr_wen) begin
      if (_T_270) begin
        reg_mie_msip <= csr_write_data[3];
      end
    end
    if (reset) begin
      reg_mip_mtip <= 1'h0;
    end else if (csr_wen) begin
      if (_T_271) begin
        reg_mip_mtip <= csr_write_data[7];
      end
    end
    if (reset) begin
      reg_mip_msip <= 1'h0;
    end else if (csr_wen) begin
      if (_T_271) begin
        reg_mip_msip <= csr_write_data[3];
      end
    end
    if (reset) begin
      reg_mtval <= 64'h0;
    end else if (csr_has_interrupt) begin
      reg_mtval <= io_in_mem_pc;
    end else if (!(csr_ismret)) begin
      if (csr_has_exception) begin
        if (exception_in_csr) begin
          reg_mtval <= {{32'd0}, io_inst};
        end else if (csr_isecall) begin
          reg_mtval <= io_in_mem_pc;
        end else if (csr_isebreak) begin
          reg_mtval <= io_in_mem_pc;
        end
      end
    end
    if (reset) begin
      reg_mscratch <= 64'h0;
    end else if (csr_wen) begin
      if (_T_274) begin
        reg_mscratch <= csr_write_data;
      end
    end
    if (reset) begin
      reg_mstatus_mpp <= 2'h0;
    end else if (csr_has_interrupt) begin
      if (csr_has_interrupt) begin
        reg_mstatus_mpp <= 2'h3;
      end else if (!(csr_ismret)) begin
        reg_mstatus_mpp <= 2'h3;
      end
    end else if (!(csr_ismret)) begin
      if (csr_has_exception) begin
        if (exception_in_csr) begin
          if (exception_in_csr) begin
            if (csr_has_interrupt) begin
              reg_mstatus_mpp <= 2'h3;
            end else if (!(csr_ismret)) begin
              reg_mstatus_mpp <= 2'h3;
            end
          end else if (csr_isecall) begin
            if (csr_has_interrupt) begin
              reg_mstatus_mpp <= 2'h3;
            end else if (!(csr_ismret)) begin
              reg_mstatus_mpp <= 2'h3;
            end
          end else if (csr_isebreak) begin
            if (csr_has_interrupt) begin
              reg_mstatus_mpp <= 2'h3;
            end else if (!(csr_ismret)) begin
              reg_mstatus_mpp <= 2'h3;
            end
          end
        end else if (csr_isecall) begin
          if (exception_in_csr) begin
            reg_mstatus_mpp <= prv_now;
          end else if (csr_isecall) begin
            reg_mstatus_mpp <= prv_now;
          end else if (csr_isebreak) begin
            reg_mstatus_mpp <= prv_now;
          end
        end else if (csr_isebreak) begin
          if (exception_in_csr) begin
            reg_mstatus_mpp <= prv_now;
          end else if (csr_isecall) begin
            reg_mstatus_mpp <= prv_now;
          end else if (csr_isebreak) begin
            reg_mstatus_mpp <= prv_now;
          end
        end
      end
    end
    if (reset) begin
      reg_mstatus_mpie <= 1'h0;
    end else if (csr_has_interrupt) begin
      reg_mstatus_mpie <= reg_mstatus_mie;
    end else begin
      reg_mstatus_mpie <= _GEN_300;
    end
    if (reset) begin
      reg_mstatus_mie <= 1'h0;
    end else if (csr_has_interrupt) begin
      reg_mstatus_mie <= 1'h0;
    end else if (csr_ismret) begin
      reg_mstatus_mie <= reg_mstatus_mpie;
    end else if (csr_has_exception) begin
      if (exception_in_csr) begin
        if (exception_in_csr) begin
          reg_mstatus_mie <= 1'h0;
        end else if (csr_isecall) begin
          reg_mstatus_mie <= 1'h0;
        end else if (csr_isebreak) begin
          reg_mstatus_mie <= 1'h0;
        end
      end else if (csr_isecall) begin
        if (exception_in_csr) begin
          reg_mstatus_mie <= 1'h0;
        end else if (csr_isecall) begin
          reg_mstatus_mie <= 1'h0;
        end else if (csr_isebreak) begin
          reg_mstatus_mie <= 1'h0;
        end
      end else if (csr_isebreak) begin
        if (exception_in_csr) begin
          reg_mstatus_mie <= 1'h0;
        end else if (csr_isecall) begin
          reg_mstatus_mie <= 1'h0;
        end else if (csr_isebreak) begin
          reg_mstatus_mie <= 1'h0;
        end
      end else if (csr_wen) begin
        if (_T_266) begin
          reg_mstatus_mie <= csr_write_data[3];
        end
      end
    end else if (csr_wen) begin
      if (_T_266) begin
        reg_mstatus_mie <= csr_write_data[3];
      end
    end
    if (reset) begin
      reg_pmpcfg0 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_278) begin
        reg_pmpcfg0 <= csr_write_data;
      end
    end
    if (reset) begin
      reg_pmpcfg1 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_279) begin
        reg_pmpcfg1 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_pmpaddr_0 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_283) begin
        regs_pmpaddr_0 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_pmpaddr_1 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_284) begin
        regs_pmpaddr_1 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_pmpaddr_2 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_285) begin
        regs_pmpaddr_2 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_pmpaddr_3 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_286) begin
        regs_pmpaddr_3 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_pmpaddr_4 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_287) begin
        regs_pmpaddr_4 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_pmpaddr_5 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_288) begin
        regs_pmpaddr_5 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_pmpaddr_6 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_289) begin
        regs_pmpaddr_6 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_pmpaddr_7 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_290) begin
        regs_pmpaddr_7 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_pmpaddr_8 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_291) begin
        regs_pmpaddr_8 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_pmpaddr_9 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_292) begin
        regs_pmpaddr_9 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_pmpaddr_10 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_293) begin
        regs_pmpaddr_10 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_pmpaddr_11 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_294) begin
        regs_pmpaddr_11 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_pmpaddr_12 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_295) begin
        regs_pmpaddr_12 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_pmpaddr_13 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_296) begin
        regs_pmpaddr_13 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_pmpaddr_14 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_297) begin
        regs_pmpaddr_14 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_pmpaddr_15 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_298) begin
        regs_pmpaddr_15 <= csr_write_data;
      end
    end
    if (reset) begin
      reg_mcycle <= 64'h0;
    end else begin
      reg_mcycle <= _T_17729;
    end
    if (reset) begin
      reg_minstret <= 64'h0;
    end else if (csr_wen) begin
      if (_T_281) begin
        reg_minstret <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_0 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_299) begin
        regs_mhpmcounter_0 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_1 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_300) begin
        regs_mhpmcounter_1 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_2 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_301) begin
        regs_mhpmcounter_2 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_3 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_302) begin
        regs_mhpmcounter_3 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_4 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_303) begin
        regs_mhpmcounter_4 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_5 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_304) begin
        regs_mhpmcounter_5 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_6 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_305) begin
        regs_mhpmcounter_6 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_7 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_306) begin
        regs_mhpmcounter_7 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_8 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_307) begin
        regs_mhpmcounter_8 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_9 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_308) begin
        regs_mhpmcounter_9 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_10 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_309) begin
        regs_mhpmcounter_10 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_11 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_310) begin
        regs_mhpmcounter_11 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_12 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_311) begin
        regs_mhpmcounter_12 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_13 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_312) begin
        regs_mhpmcounter_13 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_14 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_313) begin
        regs_mhpmcounter_14 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_15 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_314) begin
        regs_mhpmcounter_15 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_16 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_315) begin
        regs_mhpmcounter_16 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_17 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_316) begin
        regs_mhpmcounter_17 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_18 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_317) begin
        regs_mhpmcounter_18 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_19 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_318) begin
        regs_mhpmcounter_19 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_20 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_319) begin
        regs_mhpmcounter_20 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_21 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_320) begin
        regs_mhpmcounter_21 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_22 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_321) begin
        regs_mhpmcounter_22 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_23 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_322) begin
        regs_mhpmcounter_23 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_24 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_323) begin
        regs_mhpmcounter_24 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_25 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_324) begin
        regs_mhpmcounter_25 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_26 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_325) begin
        regs_mhpmcounter_26 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_27 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_326) begin
        regs_mhpmcounter_27 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmcounter_28 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_327) begin
        regs_mhpmcounter_28 <= csr_write_data;
      end
    end
    if (reset) begin
      reg_mcounterinhibit <= 64'h0;
    end else if (csr_wen) begin
      if (_T_282) begin
        reg_mcounterinhibit <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_0 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_328) begin
        regs_mhpmevet_0 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_1 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_329) begin
        regs_mhpmevet_1 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_2 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_330) begin
        regs_mhpmevet_2 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_3 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_331) begin
        regs_mhpmevet_3 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_4 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_332) begin
        regs_mhpmevet_4 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_5 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_333) begin
        regs_mhpmevet_5 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_6 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_334) begin
        regs_mhpmevet_6 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_7 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_335) begin
        regs_mhpmevet_7 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_8 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_336) begin
        regs_mhpmevet_8 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_9 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_337) begin
        regs_mhpmevet_9 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_10 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_338) begin
        regs_mhpmevet_10 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_11 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_339) begin
        regs_mhpmevet_11 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_12 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_340) begin
        regs_mhpmevet_12 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_13 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_341) begin
        regs_mhpmevet_13 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_14 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_342) begin
        regs_mhpmevet_14 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_15 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_343) begin
        regs_mhpmevet_15 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_16 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_344) begin
        regs_mhpmevet_16 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_17 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_345) begin
        regs_mhpmevet_17 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_18 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_346) begin
        regs_mhpmevet_18 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_19 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_347) begin
        regs_mhpmevet_19 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_20 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_348) begin
        regs_mhpmevet_20 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_21 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_349) begin
        regs_mhpmevet_21 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_22 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_350) begin
        regs_mhpmevet_22 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_23 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_351) begin
        regs_mhpmevet_23 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_24 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_352) begin
        regs_mhpmevet_24 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_25 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_353) begin
        regs_mhpmevet_25 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_26 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_354) begin
        regs_mhpmevet_26 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_27 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_355) begin
        regs_mhpmevet_27 <= csr_write_data;
      end
    end
    if (reset) begin
      regs_mhpmevet_28 <= 64'h0;
    end else if (csr_wen) begin
      if (_T_356) begin
        regs_mhpmevet_28 <= csr_write_data;
      end
    end
  end
endmodule
module Dpath(
  input         clock,
  input         reset,
  input         io_ctl_dec_stall,
  input  [1:0]  io_ctl_exe_pc_sel,
  input  [3:0]  io_ctl_br_type,
  input         io_ctl_if_kill,
  input         io_ctl_dec_kill,
  input  [1:0]  io_ctl_op1_sel,
  input  [2:0]  io_ctl_op2_sel,
  input  [4:0]  io_ctl_alu_fun,
  input  [2:0]  io_ctl_wb_sel,
  input         io_ctl_rf_wen,
  input  [1:0]  io_ctl_mem_fcn,
  input  [7:0]  io_ctl_mem_typ,
  input  [2:0]  io_ctl_mem_wid,
  input  [2:0]  io_ctl_csr_cmd,
  input         io_ctl_fencei,
  input         io_ctl_pipeline_kill,
  output [63:0] io_dat_dec_inst,
  output        io_dat_exe_br_eq,
  output        io_dat_exe_br_lt,
  output        io_dat_exe_br_ltu,
  output [3:0]  io_dat_exe_br_type,
  output        io_dat_csr_eret,
  output [63:0] io_inst_readIO_addr,
  input  [63:0] io_inst_readIO_data,
  output [63:0] io_data_readIO_addr,
  input  [63:0] io_data_readIO_data,
  output        io_data_readIO_en,
  output [63:0] io_data_writeIO_addr,
  output [63:0] io_data_writeIO_data,
  output        io_data_writeIO_en,
  output [7:0]  io_data_writeIO_mask,
  output        wb_reg_valid_0,
  output [63:0] _T_42_0_0,
  output [63:0] _T_42_0_1,
  output [63:0] _T_42_0_2,
  output [63:0] _T_42_0_3,
  output [63:0] _T_42_0_4,
  output [63:0] _T_42_0_5,
  output [63:0] _T_42_0_6,
  output [63:0] _T_42_0_7,
  output [63:0] _T_42_0_8,
  output [63:0] _T_42_0_9,
  output [63:0] _T_42_0_10,
  output [63:0] _T_42_0_11,
  output [63:0] _T_42_0_12,
  output [63:0] _T_42_0_13,
  output [63:0] _T_42_0_14,
  output [63:0] _T_42_0_15,
  output [63:0] _T_42_0_16,
  output [63:0] _T_42_0_17,
  output [63:0] _T_42_0_18,
  output [63:0] _T_42_0_19,
  output [63:0] _T_42_0_20,
  output [63:0] _T_42_0_21,
  output [63:0] _T_42_0_22,
  output [63:0] _T_42_0_23,
  output [63:0] _T_42_0_24,
  output [63:0] _T_42_0_25,
  output [63:0] _T_42_0_26,
  output [63:0] _T_42_0_27,
  output [63:0] _T_42_0_28,
  output [63:0] _T_42_0_29,
  output [63:0] _T_42_0_30,
  output [63:0] _T_42_0_31,
  output [63:0] wb_reg_pc_0
);
`ifdef RANDOMIZE_REG_INIT
  reg [63:0] _RAND_0;
  reg [31:0] _RAND_1;
  reg [63:0] _RAND_2;
  reg [63:0] _RAND_3;
  reg [31:0] _RAND_4;
  reg [63:0] _RAND_5;
  reg [63:0] _RAND_6;
  reg [31:0] _RAND_7;
  reg [63:0] _RAND_8;
  reg [63:0] _RAND_9;
  reg [63:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [31:0] _RAND_13;
  reg [31:0] _RAND_14;
  reg [31:0] _RAND_15;
  reg [31:0] _RAND_16;
  reg [31:0] _RAND_17;
  reg [31:0] _RAND_18;
  reg [31:0] _RAND_19;
  reg [63:0] _RAND_20;
  reg [63:0] _RAND_21;
  reg [63:0] _RAND_22;
  reg [31:0] _RAND_23;
  reg [31:0] _RAND_24;
  reg [31:0] _RAND_25;
  reg [31:0] _RAND_26;
  reg [31:0] _RAND_27;
  reg [63:0] _RAND_28;
  reg [31:0] _RAND_29;
  reg [63:0] _RAND_30;
  reg [31:0] _RAND_31;
  reg [63:0] _RAND_32;
  reg [31:0] _RAND_33;
  reg [63:0] _RAND_34;
`endif // RANDOMIZE_REG_INIT
  wire  regfile_clock; // @[dpath.scala 155:23]
  wire  regfile_reset; // @[dpath.scala 155:23]
  wire [4:0] regfile_io_rs1_addr; // @[dpath.scala 155:23]
  wire [63:0] regfile_io_rs1_data; // @[dpath.scala 155:23]
  wire [4:0] regfile_io_rs2_addr; // @[dpath.scala 155:23]
  wire [63:0] regfile_io_rs2_data; // @[dpath.scala 155:23]
  wire [4:0] regfile_io_waddr; // @[dpath.scala 155:23]
  wire [63:0] regfile_io_wdata; // @[dpath.scala 155:23]
  wire  regfile_io_wen; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_0; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_1; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_2; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_3; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_4; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_5; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_6; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_7; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_8; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_9; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_10; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_11; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_12; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_13; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_14; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_15; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_16; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_17; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_18; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_19; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_20; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_21; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_22; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_23; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_24; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_25; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_26; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_27; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_28; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_29; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_30; // @[dpath.scala 155:23]
  wire [63:0] regfile__T_42_0_31; // @[dpath.scala 155:23]
  wire  alu_clock; // @[dpath.scala 286:19]
  wire  alu_reset; // @[dpath.scala 286:19]
  wire [63:0] alu_io_src1; // @[dpath.scala 286:19]
  wire [63:0] alu_io_src2; // @[dpath.scala 286:19]
  wire [4:0] alu_io_op; // @[dpath.scala 286:19]
  wire [63:0] alu_io_res; // @[dpath.scala 286:19]
  wire  csr_clock; // @[dpath.scala 339:19]
  wire  csr_reset; // @[dpath.scala 339:19]
  wire [31:0] csr_io_inst; // @[dpath.scala 339:19]
  wire [2:0] csr_io_csr_op; // @[dpath.scala 339:19]
  wire [63:0] csr_io_data_in; // @[dpath.scala 339:19]
  wire [63:0] csr_io_in_mem_pc; // @[dpath.scala 339:19]
  wire [63:0] csr_io_in_exe_pc; // @[dpath.scala 339:19]
  wire [63:0] csr_io_in_dec_pc; // @[dpath.scala 339:19]
  wire [63:0] csr_io_in_if_pc; // @[dpath.scala 339:19]
  wire  csr_io_is_redir; // @[dpath.scala 339:19]
  reg [63:0] if_reg_pc; // @[dpath.scala 35:37]
  reg  dec_reg_valid; // @[dpath.scala 38:37]
  reg [63:0] dec_reg_inst; // @[dpath.scala 39:37]
  reg [63:0] dec_reg_pc; // @[dpath.scala 40:37]
  reg  exe_reg_valid; // @[dpath.scala 42:37]
  reg [63:0] exe_reg_inst; // @[dpath.scala 43:37]
  reg [63:0] exe_reg_pc; // @[dpath.scala 44:37]
  reg [4:0] exe_reg_wbaddr; // @[dpath.scala 45:33]
  reg [63:0] exe_alu_op1; // @[dpath.scala 48:33]
  reg [63:0] brjmp_offset; // @[dpath.scala 49:33]
  reg [63:0] exe_reg_rs2_data; // @[dpath.scala 50:33]
  reg [3:0] exe_reg_ctrl_br_type; // @[dpath.scala 51:37]
  reg [4:0] exe_reg_ctrl_alu_fun; // @[dpath.scala 53:33]
  reg [2:0] exe_reg_ctrl_wb_sel; // @[dpath.scala 54:33]
  reg  exe_reg_ctrl_rf_wen; // @[dpath.scala 55:37]
  reg [1:0] exe_reg_ctrl_mem_fcn; // @[dpath.scala 57:37]
  reg [7:0] exe_reg_ctrl_mem_typ; // @[dpath.scala 58:37]
  reg [2:0] exe_reg_ctrl_mem_wid; // @[dpath.scala 59:37]
  reg [2:0] exe_reg_ctrl_csr_cmd; // @[dpath.scala 60:37]
  reg  mem_reg_valid; // @[dpath.scala 63:37]
  reg [63:0] mem_reg_pc; // @[dpath.scala 64:33]
  reg [63:0] mem_reg_inst; // @[dpath.scala 65:33]
  reg [63:0] mem_reg_alu_out; // @[dpath.scala 66:33]
  reg [4:0] mem_reg_wbaddr; // @[dpath.scala 67:33]
  reg  mem_reg_ctrl_rf_wen; // @[dpath.scala 73:37]
  reg [2:0] mem_reg_ctrl_wb_sel; // @[dpath.scala 77:33]
  reg [2:0] mem_reg_ctrl_mem_wid; // @[dpath.scala 78:37]
  reg [2:0] mem_reg_ctrl_csr_cmd; // @[dpath.scala 79:37]
  reg [63:0] mem_reg_dram_data; // @[dpath.scala 80:37]
  reg  wb_reg_valid; // @[dpath.scala 83:29]
  reg [63:0] wb_reg_pc; // @[dpath.scala 84:22]
  reg [4:0] wb_reg_wbaddr; // @[dpath.scala 86:26]
  reg [63:0] wb_reg_wbdata; // @[dpath.scala 87:26]
  reg  wb_reg_ctrl_rf_wen; // @[dpath.scala 88:35]
  wire  _T = ~io_ctl_dec_stall; // @[dpath.scala 98:10]
  wire  _T_3 = _T | io_ctl_pipeline_kill; // @[dpath.scala 98:51]
  wire  _T_11 = io_ctl_exe_pc_sel == 2'h0; // @[dpath.scala 110:44]
  wire  _T_12 = io_ctl_fencei & _T_11; // @[dpath.scala 110:23]
  wire  _T_14 = _T_12 & _T; // @[dpath.scala 110:53]
  wire  _T_17 = ~io_ctl_pipeline_kill; // @[dpath.scala 111:53]
  wire  _T_18 = _T_14 & _T_17; // @[dpath.scala 111:50]
  wire [63:0] if_pc_plus4 = if_reg_pc + 64'h4; // @[dpath.scala 103:31]
  wire  _T_6 = io_ctl_exe_pc_sel == 2'h1; // @[dpath.scala 106:39]
  wire [63:0] exe_brjmp_target = exe_reg_pc + brjmp_offset; // @[dpath.scala 297:37]
  wire  _T_7 = io_ctl_exe_pc_sel == 2'h2; // @[dpath.scala 107:39]
  wire [63:0] exe_adder_out = exe_alu_op1 + brjmp_offset; // @[dpath.scala 294:36]
  wire [63:0] _T_8 = _T_7 ? exe_adder_out : 64'h4033; // @[dpath.scala 107:20]
  wire [63:0] _T_9 = _T_6 ? exe_brjmp_target : _T_8; // @[dpath.scala 106:20]
  wire [63:0] _T_10 = _T_11 ? if_pc_plus4 : _T_9; // @[dpath.scala 105:20]
  wire [63:0] if_pc_next = _T_18 ? if_reg_pc : _T_10; // @[dpath.scala 112:3]
  wire  _T_23 = ~reset; // @[dpath.scala 143:9]
  wire [4:0] dec_rs1_addr = dec_reg_inst[19:15]; // @[dpath.scala 149:34]
  wire [4:0] dec_rs2_addr = dec_reg_inst[24:20]; // @[dpath.scala 150:34]
  wire [4:0] dec_wbaddr = dec_reg_inst[11:7]; // @[dpath.scala 151:32]
  wire [11:0] imm_itype = dec_reg_inst[31:20]; // @[dpath.scala 165:31]
  wire [11:0] imm_stype = {dec_reg_inst[31:25],dec_wbaddr}; // @[Cat.scala 29:58]
  wire [11:0] imm_sbtype = {dec_reg_inst[31],dec_reg_inst[7],dec_reg_inst[30:25],dec_reg_inst[11:8]}; // @[Cat.scala 29:58]
  wire [19:0] imm_utype = dec_reg_inst[31:12]; // @[dpath.scala 168:31]
  wire [19:0] imm_ujtype = {dec_reg_inst[31],dec_reg_inst[19:12],dec_reg_inst[20],dec_reg_inst[30:21]}; // @[Cat.scala 29:58]
  wire [31:0] imm_z = {27'h0,dec_rs1_addr}; // @[Cat.scala 29:58]
  wire [51:0] _T_42 = imm_itype[11] ? 52'hfffffffffffff : 52'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_itype_sext = {_T_42,imm_itype}; // @[Cat.scala 29:58]
  wire [51:0] _T_45 = imm_stype[11] ? 52'hfffffffffffff : 52'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_stype_sext = {_T_45,dec_reg_inst[31:25],dec_wbaddr}; // @[Cat.scala 29:58]
  wire [50:0] _T_48 = imm_sbtype[11] ? 51'h7ffffffffffff : 51'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_sbtype_sext = {_T_48,dec_reg_inst[31],dec_reg_inst[7],dec_reg_inst[30:25],dec_reg_inst[11:8],1'h0}; // @[Cat.scala 29:58]
  wire [31:0] _T_52 = imm_utype[19] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_utype_sext = {_T_52,imm_utype,12'h0}; // @[Cat.scala 29:58]
  wire [42:0] _T_57 = imm_ujtype[19] ? 43'h7ffffffffff : 43'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_ujtype_sext = {_T_57,dec_reg_inst[31],dec_reg_inst[19:12],dec_reg_inst[20],dec_reg_inst[30:21],1'h0}; // @[Cat.scala 29:58]
  wire  _T_59 = io_ctl_op2_sel == 3'h0; // @[dpath.scala 181:21]
  wire  _T_60 = io_ctl_op2_sel == 3'h1; // @[dpath.scala 182:21]
  wire  _T_61 = io_ctl_op2_sel == 3'h2; // @[dpath.scala 183:21]
  wire  _T_62 = io_ctl_op2_sel == 3'h3; // @[dpath.scala 184:21]
  wire  _T_63 = io_ctl_op2_sel == 3'h4; // @[dpath.scala 185:21]
  wire  _T_64 = io_ctl_op2_sel == 3'h5; // @[dpath.scala 186:21]
  wire [63:0] _T_65 = _T_64 ? imm_ujtype_sext : 64'h0; // @[Mux.scala 98:16]
  wire [63:0] _T_66 = _T_63 ? imm_utype_sext : _T_65; // @[Mux.scala 98:16]
  wire [63:0] _T_67 = _T_62 ? imm_sbtype_sext : _T_66; // @[Mux.scala 98:16]
  wire [63:0] _T_68 = _T_61 ? imm_stype_sext : _T_67; // @[Mux.scala 98:16]
  wire [63:0] _T_69 = _T_60 ? imm_itype_sext : _T_68; // @[Mux.scala 98:16]
  wire [63:0] dec_alu_op2 = _T_59 ? regfile_io_rs2_data : _T_69; // @[Mux.scala 98:16]
  wire  _T_70 = exe_reg_wbaddr == dec_rs1_addr; // @[dpath.scala 199:22]
  wire  _T_71 = dec_rs1_addr != 5'h0; // @[dpath.scala 199:57]
  wire  _T_72 = _T_70 & _T_71; // @[dpath.scala 199:40]
  wire  _T_73 = _T_72 & exe_reg_ctrl_rf_wen; // @[dpath.scala 199:66]
  wire  _T_74 = mem_reg_wbaddr == dec_rs1_addr; // @[dpath.scala 200:22]
  wire  _T_76 = _T_74 & _T_71; // @[dpath.scala 200:40]
  wire  _T_77 = _T_76 & mem_reg_ctrl_rf_wen; // @[dpath.scala 200:66]
  wire  _T_78 = wb_reg_wbaddr == dec_rs1_addr; // @[dpath.scala 201:21]
  wire  _T_80 = _T_78 & _T_71; // @[dpath.scala 201:39]
  wire  _T_81 = _T_80 & wb_reg_ctrl_rf_wen; // @[dpath.scala 201:65]
  wire [63:0] _T_82 = _T_81 ? wb_reg_wbdata : regfile_io_rs1_data; // @[Mux.scala 98:16]
  wire  _T_194 = mem_reg_ctrl_wb_sel == 3'h1; // @[dpath.scala 372:26]
  wire  _T_157 = mem_reg_ctrl_mem_wid == 3'h0; // @[dpath.scala 361:27]
  wire [55:0] _T_160 = mem_reg_dram_data[7] ? 56'hffffffffffffff : 56'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _T_162 = {_T_160,mem_reg_dram_data[7:0]}; // @[Cat.scala 29:58]
  wire  _T_163 = mem_reg_ctrl_mem_wid == 3'h1; // @[dpath.scala 362:27]
  wire [63:0] _T_166 = {56'h0,mem_reg_dram_data[7:0]}; // @[Cat.scala 29:58]
  wire  _T_167 = mem_reg_ctrl_mem_wid == 3'h2; // @[dpath.scala 363:27]
  wire [47:0] _T_170 = mem_reg_dram_data[15] ? 48'hffffffffffff : 48'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _T_172 = {_T_170,mem_reg_dram_data[15:0]}; // @[Cat.scala 29:58]
  wire  _T_173 = mem_reg_ctrl_mem_wid == 3'h3; // @[dpath.scala 364:27]
  wire [63:0] _T_176 = {48'h0,mem_reg_dram_data[15:0]}; // @[Cat.scala 29:58]
  wire  _T_177 = mem_reg_ctrl_mem_wid == 3'h4; // @[dpath.scala 365:27]
  wire [31:0] _T_180 = mem_reg_dram_data[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _T_182 = {_T_180,mem_reg_dram_data[31:0]}; // @[Cat.scala 29:58]
  wire  _T_183 = mem_reg_ctrl_mem_wid == 3'h5; // @[dpath.scala 366:27]
  wire [63:0] _T_186 = {32'h0,mem_reg_dram_data[31:0]}; // @[Cat.scala 29:58]
  wire [63:0] _T_189 = _T_183 ? _T_186 : mem_reg_dram_data; // @[Mux.scala 98:16]
  wire [63:0] _T_190 = _T_177 ? _T_182 : _T_189; // @[Mux.scala 98:16]
  wire [63:0] _T_191 = _T_173 ? _T_176 : _T_190; // @[Mux.scala 98:16]
  wire [63:0] _T_192 = _T_167 ? _T_172 : _T_191; // @[Mux.scala 98:16]
  wire [63:0] _T_193 = _T_163 ? _T_166 : _T_192; // @[Mux.scala 98:16]
  wire [63:0] mem_data = _T_157 ? _T_162 : _T_193; // @[Mux.scala 98:16]
  wire [63:0] mem_wbdata = _T_194 ? mem_data : mem_reg_alu_out; // @[Mux.scala 98:16]
  wire [63:0] _T_83 = _T_77 ? mem_wbdata : _T_82; // @[Mux.scala 98:16]
  wire  _T_136 = exe_reg_ctrl_wb_sel == 3'h4; // @[dpath.scala 291:28]
  wire [31:0] _T_139 = alu_io_res[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _T_141 = {_T_139,alu_io_res[31:0]}; // @[Cat.scala 29:58]
  wire [63:0] exe_alu_out = _T_136 ? _T_141 : alu_io_res; // @[Mux.scala 98:16]
  wire [63:0] dec_rs1_data = _T_73 ? exe_alu_out : _T_83; // @[Mux.scala 98:16]
  wire  _T_85 = io_ctl_op1_sel == 2'h2; // @[dpath.scala 205:21]
  wire  _T_86 = io_ctl_op1_sel == 2'h1; // @[dpath.scala 206:21]
  wire  _T_87 = io_ctl_op1_sel == 2'h3; // @[dpath.scala 207:21]
  wire [63:0] _T_90 = {32'h0,dec_rs1_data[31:0]}; // @[Cat.scala 29:58]
  wire [63:0] _T_91 = _T_87 ? _T_90 : dec_rs1_data; // @[Mux.scala 98:16]
  wire [63:0] _T_92 = _T_86 ? dec_reg_pc : _T_91; // @[Mux.scala 98:16]
  wire [63:0] dec_op1_data = _T_85 ? {{32'd0}, imm_z} : _T_92; // @[Mux.scala 98:16]
  wire  _T_94 = exe_reg_wbaddr == dec_rs2_addr; // @[dpath.scala 211:22]
  wire  _T_95 = dec_rs2_addr != 5'h0; // @[dpath.scala 211:57]
  wire  _T_96 = _T_94 & _T_95; // @[dpath.scala 211:40]
  wire  _T_97 = _T_96 & exe_reg_ctrl_rf_wen; // @[dpath.scala 211:66]
  wire  _T_99 = _T_97 & _T_59; // @[dpath.scala 211:89]
  wire  _T_100 = mem_reg_wbaddr == dec_rs2_addr; // @[dpath.scala 212:22]
  wire  _T_102 = _T_100 & _T_95; // @[dpath.scala 212:40]
  wire  _T_103 = _T_102 & mem_reg_ctrl_rf_wen; // @[dpath.scala 212:66]
  wire  _T_105 = _T_103 & _T_59; // @[dpath.scala 212:89]
  wire  _T_106 = wb_reg_wbaddr == dec_rs2_addr; // @[dpath.scala 213:22]
  wire  _T_108 = _T_106 & _T_95; // @[dpath.scala 213:40]
  wire  _T_109 = _T_108 & wb_reg_ctrl_rf_wen; // @[dpath.scala 213:66]
  wire  _T_111 = _T_109 & _T_59; // @[dpath.scala 213:89]
  wire [63:0] _T_112 = _T_111 ? wb_reg_wbdata : dec_alu_op2; // @[Mux.scala 98:16]
  wire [63:0] _T_113 = _T_105 ? mem_wbdata : _T_112; // @[Mux.scala 98:16]
  wire [63:0] dec_op2_data = _T_99 ? exe_alu_out : _T_113; // @[Mux.scala 98:16]
  wire  _T_132 = io_ctl_dec_stall | io_ctl_pipeline_kill; // @[dpath.scala 223:50]
  wire [63:0] exe_pc_plus4 = exe_reg_pc + 64'h4; // @[dpath.scala 300:34]
  wire  _T_150 = exe_reg_ctrl_wb_sel == 3'h2; // @[dpath.scala 316:32]
  reg [63:0] _T_198; // @[dpath.scala 387:119]
  wire  _T_206 = exe_reg_ctrl_mem_typ == 8'h1; // @[dpath.scala 400:27]
  wire [63:0] _T_210 = {exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0]}; // @[Cat.scala 29:58]
  wire  _T_211 = exe_reg_ctrl_mem_typ == 8'h3; // @[dpath.scala 401:27]
  wire [63:0] _T_214 = {exe_reg_rs2_data[15:0],exe_reg_rs2_data[15:0],exe_reg_rs2_data[15:0],exe_reg_rs2_data[15:0]}; // @[Cat.scala 29:58]
  wire  _T_215 = exe_reg_ctrl_mem_typ == 8'hf; // @[dpath.scala 402:27]
  wire [63:0] _T_217 = {exe_reg_rs2_data[31:0],exe_reg_rs2_data[31:0]}; // @[Cat.scala 29:58]
  wire [63:0] _T_220 = _T_215 ? _T_217 : exe_reg_rs2_data; // @[Mux.scala 98:16]
  wire [63:0] _T_221 = _T_211 ? _T_214 : _T_220; // @[Mux.scala 98:16]
  wire [14:0] _GEN_92 = {{7'd0}, exe_reg_ctrl_mem_typ}; // @[dpath.scala 406:39]
  wire [14:0] _T_223 = _GEN_92 << exe_alu_out[2:0]; // @[dpath.scala 406:39]
  regfile regfile ( // @[dpath.scala 155:23]
    .clock(regfile_clock),
    .reset(regfile_reset),
    .io_rs1_addr(regfile_io_rs1_addr),
    .io_rs1_data(regfile_io_rs1_data),
    .io_rs2_addr(regfile_io_rs2_addr),
    .io_rs2_data(regfile_io_rs2_data),
    .io_waddr(regfile_io_waddr),
    .io_wdata(regfile_io_wdata),
    .io_wen(regfile_io_wen),
    ._T_42_0_0(regfile__T_42_0_0),
    ._T_42_0_1(regfile__T_42_0_1),
    ._T_42_0_2(regfile__T_42_0_2),
    ._T_42_0_3(regfile__T_42_0_3),
    ._T_42_0_4(regfile__T_42_0_4),
    ._T_42_0_5(regfile__T_42_0_5),
    ._T_42_0_6(regfile__T_42_0_6),
    ._T_42_0_7(regfile__T_42_0_7),
    ._T_42_0_8(regfile__T_42_0_8),
    ._T_42_0_9(regfile__T_42_0_9),
    ._T_42_0_10(regfile__T_42_0_10),
    ._T_42_0_11(regfile__T_42_0_11),
    ._T_42_0_12(regfile__T_42_0_12),
    ._T_42_0_13(regfile__T_42_0_13),
    ._T_42_0_14(regfile__T_42_0_14),
    ._T_42_0_15(regfile__T_42_0_15),
    ._T_42_0_16(regfile__T_42_0_16),
    ._T_42_0_17(regfile__T_42_0_17),
    ._T_42_0_18(regfile__T_42_0_18),
    ._T_42_0_19(regfile__T_42_0_19),
    ._T_42_0_20(regfile__T_42_0_20),
    ._T_42_0_21(regfile__T_42_0_21),
    ._T_42_0_22(regfile__T_42_0_22),
    ._T_42_0_23(regfile__T_42_0_23),
    ._T_42_0_24(regfile__T_42_0_24),
    ._T_42_0_25(regfile__T_42_0_25),
    ._T_42_0_26(regfile__T_42_0_26),
    ._T_42_0_27(regfile__T_42_0_27),
    ._T_42_0_28(regfile__T_42_0_28),
    ._T_42_0_29(regfile__T_42_0_29),
    ._T_42_0_30(regfile__T_42_0_30),
    ._T_42_0_31(regfile__T_42_0_31)
  );
  alu alu ( // @[dpath.scala 286:19]
    .clock(alu_clock),
    .reset(alu_reset),
    .io_src1(alu_io_src1),
    .io_src2(alu_io_src2),
    .io_op(alu_io_op),
    .io_res(alu_io_res)
  );
  CSRfile csr ( // @[dpath.scala 339:19]
    .clock(csr_clock),
    .reset(csr_reset),
    .io_inst(csr_io_inst),
    .io_csr_op(csr_io_csr_op),
    .io_data_in(csr_io_data_in),
    .io_in_mem_pc(csr_io_in_mem_pc),
    .io_in_exe_pc(csr_io_in_exe_pc),
    .io_in_dec_pc(csr_io_in_dec_pc),
    .io_in_if_pc(csr_io_in_if_pc),
    .io_is_redir(csr_io_is_redir)
  );
  assign io_dat_dec_inst = dec_reg_inst; // @[dpath.scala 393:21]
  assign io_dat_exe_br_eq = exe_alu_op1 == exe_reg_rs2_data; // @[dpath.scala 394:21]
  assign io_dat_exe_br_lt = $signed(exe_alu_op1) < $signed(exe_reg_rs2_data); // @[dpath.scala 395:21]
  assign io_dat_exe_br_ltu = exe_alu_op1 < exe_reg_rs2_data; // @[dpath.scala 396:21]
  assign io_dat_exe_br_type = exe_reg_ctrl_br_type; // @[dpath.scala 397:21]
  assign io_dat_csr_eret = csr_io_is_redir; // @[dpath.scala 352:20]
  assign io_inst_readIO_addr = if_reg_pc; // @[dpath.scala 116:23]
  assign io_data_readIO_addr = _T_136 ? _T_141 : alu_io_res; // @[dpath.scala 356:24]
  assign io_data_readIO_en = exe_reg_ctrl_mem_fcn == 2'h1; // @[dpath.scala 355:24]
  assign io_data_writeIO_addr = _T_136 ? _T_141 : alu_io_res; // @[dpath.scala 410:24]
  assign io_data_writeIO_data = _T_206 ? _T_210 : _T_221; // @[dpath.scala 411:24]
  assign io_data_writeIO_en = exe_reg_ctrl_mem_fcn == 2'h2; // @[dpath.scala 409:24]
  assign io_data_writeIO_mask = _T_223[7:0]; // @[dpath.scala 412:24]
  assign wb_reg_valid_0 = wb_reg_valid;
  assign _T_42_0_0 = regfile__T_42_0_0;
  assign _T_42_0_1 = regfile__T_42_0_1;
  assign _T_42_0_2 = regfile__T_42_0_2;
  assign _T_42_0_3 = regfile__T_42_0_3;
  assign _T_42_0_4 = regfile__T_42_0_4;
  assign _T_42_0_5 = regfile__T_42_0_5;
  assign _T_42_0_6 = regfile__T_42_0_6;
  assign _T_42_0_7 = regfile__T_42_0_7;
  assign _T_42_0_8 = regfile__T_42_0_8;
  assign _T_42_0_9 = regfile__T_42_0_9;
  assign _T_42_0_10 = regfile__T_42_0_10;
  assign _T_42_0_11 = regfile__T_42_0_11;
  assign _T_42_0_12 = regfile__T_42_0_12;
  assign _T_42_0_13 = regfile__T_42_0_13;
  assign _T_42_0_14 = regfile__T_42_0_14;
  assign _T_42_0_15 = regfile__T_42_0_15;
  assign _T_42_0_16 = regfile__T_42_0_16;
  assign _T_42_0_17 = regfile__T_42_0_17;
  assign _T_42_0_18 = regfile__T_42_0_18;
  assign _T_42_0_19 = regfile__T_42_0_19;
  assign _T_42_0_20 = regfile__T_42_0_20;
  assign _T_42_0_21 = regfile__T_42_0_21;
  assign _T_42_0_22 = regfile__T_42_0_22;
  assign _T_42_0_23 = regfile__T_42_0_23;
  assign _T_42_0_24 = regfile__T_42_0_24;
  assign _T_42_0_25 = regfile__T_42_0_25;
  assign _T_42_0_26 = regfile__T_42_0_26;
  assign _T_42_0_27 = regfile__T_42_0_27;
  assign _T_42_0_28 = regfile__T_42_0_28;
  assign _T_42_0_29 = regfile__T_42_0_29;
  assign _T_42_0_30 = regfile__T_42_0_30;
  assign _T_42_0_31 = regfile__T_42_0_31;
  assign wb_reg_pc_0 = wb_reg_pc;
  assign regfile_clock = clock;
  assign regfile_reset = reset;
  assign regfile_io_rs1_addr = dec_reg_inst[19:15]; // @[dpath.scala 156:23]
  assign regfile_io_rs2_addr = dec_reg_inst[24:20]; // @[dpath.scala 157:23]
  assign regfile_io_waddr = wb_reg_wbaddr; // @[dpath.scala 160:20]
  assign regfile_io_wdata = wb_reg_wbdata; // @[dpath.scala 161:20]
  assign regfile_io_wen = wb_reg_ctrl_rf_wen; // @[dpath.scala 162:20]
  assign alu_clock = clock;
  assign alu_reset = reset;
  assign alu_io_src1 = exe_alu_op1; // @[dpath.scala 288:15]
  assign alu_io_src2 = brjmp_offset; // @[dpath.scala 289:15]
  assign alu_io_op = exe_reg_ctrl_alu_fun; // @[dpath.scala 287:13]
  assign csr_clock = clock;
  assign csr_reset = reset;
  assign csr_io_inst = mem_reg_inst[31:0]; // @[dpath.scala 341:15]
  assign csr_io_csr_op = mem_reg_ctrl_csr_cmd; // @[dpath.scala 342:17]
  assign csr_io_data_in = mem_reg_alu_out; // @[dpath.scala 343:18]
  assign csr_io_in_mem_pc = mem_reg_pc; // @[dpath.scala 347:20]
  assign csr_io_in_exe_pc = exe_reg_pc; // @[dpath.scala 348:20]
  assign csr_io_in_dec_pc = dec_reg_pc; // @[dpath.scala 349:20]
  assign csr_io_in_if_pc = if_reg_pc; // @[dpath.scala 350:20]
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
  dec_reg_valid = _RAND_1[0:0];
  _RAND_2 = {2{`RANDOM}};
  dec_reg_inst = _RAND_2[63:0];
  _RAND_3 = {2{`RANDOM}};
  dec_reg_pc = _RAND_3[63:0];
  _RAND_4 = {1{`RANDOM}};
  exe_reg_valid = _RAND_4[0:0];
  _RAND_5 = {2{`RANDOM}};
  exe_reg_inst = _RAND_5[63:0];
  _RAND_6 = {2{`RANDOM}};
  exe_reg_pc = _RAND_6[63:0];
  _RAND_7 = {1{`RANDOM}};
  exe_reg_wbaddr = _RAND_7[4:0];
  _RAND_8 = {2{`RANDOM}};
  exe_alu_op1 = _RAND_8[63:0];
  _RAND_9 = {2{`RANDOM}};
  brjmp_offset = _RAND_9[63:0];
  _RAND_10 = {2{`RANDOM}};
  exe_reg_rs2_data = _RAND_10[63:0];
  _RAND_11 = {1{`RANDOM}};
  exe_reg_ctrl_br_type = _RAND_11[3:0];
  _RAND_12 = {1{`RANDOM}};
  exe_reg_ctrl_alu_fun = _RAND_12[4:0];
  _RAND_13 = {1{`RANDOM}};
  exe_reg_ctrl_wb_sel = _RAND_13[2:0];
  _RAND_14 = {1{`RANDOM}};
  exe_reg_ctrl_rf_wen = _RAND_14[0:0];
  _RAND_15 = {1{`RANDOM}};
  exe_reg_ctrl_mem_fcn = _RAND_15[1:0];
  _RAND_16 = {1{`RANDOM}};
  exe_reg_ctrl_mem_typ = _RAND_16[7:0];
  _RAND_17 = {1{`RANDOM}};
  exe_reg_ctrl_mem_wid = _RAND_17[2:0];
  _RAND_18 = {1{`RANDOM}};
  exe_reg_ctrl_csr_cmd = _RAND_18[2:0];
  _RAND_19 = {1{`RANDOM}};
  mem_reg_valid = _RAND_19[0:0];
  _RAND_20 = {2{`RANDOM}};
  mem_reg_pc = _RAND_20[63:0];
  _RAND_21 = {2{`RANDOM}};
  mem_reg_inst = _RAND_21[63:0];
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
  mem_reg_ctrl_csr_cmd = _RAND_27[2:0];
  _RAND_28 = {2{`RANDOM}};
  mem_reg_dram_data = _RAND_28[63:0];
  _RAND_29 = {1{`RANDOM}};
  wb_reg_valid = _RAND_29[0:0];
  _RAND_30 = {2{`RANDOM}};
  wb_reg_pc = _RAND_30[63:0];
  _RAND_31 = {1{`RANDOM}};
  wb_reg_wbaddr = _RAND_31[4:0];
  _RAND_32 = {2{`RANDOM}};
  wb_reg_wbdata = _RAND_32[63:0];
  _RAND_33 = {1{`RANDOM}};
  wb_reg_ctrl_rf_wen = _RAND_33[0:0];
  _RAND_34 = {2{`RANDOM}};
  _T_198 = _RAND_34[63:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
  always @(posedge clock) begin
    if (reset) begin
      if_reg_pc <= 64'h80000000;
    end else if (_T_3) begin
      if (!(_T_18)) begin
        if (_T_11) begin
          if_reg_pc <= if_pc_plus4;
        end else if (_T_6) begin
          if_reg_pc <= exe_brjmp_target;
        end else if (_T_7) begin
          if_reg_pc <= exe_adder_out;
        end else begin
          if_reg_pc <= 64'h4033;
        end
      end
    end
    if (reset) begin
      dec_reg_valid <= 1'h0;
    end else if (io_ctl_pipeline_kill) begin
      dec_reg_valid <= 1'h0;
    end else if (_T) begin
      if (io_ctl_if_kill) begin
        dec_reg_valid <= 1'h0;
      end else begin
        dec_reg_valid <= 1'h1;
      end
    end
    if (reset) begin
      dec_reg_inst <= 64'h4033;
    end else if (io_ctl_pipeline_kill) begin
      dec_reg_inst <= 64'h4033;
    end else if (_T) begin
      if (io_ctl_if_kill) begin
        dec_reg_inst <= 64'h4033;
      end else begin
        dec_reg_inst <= io_inst_readIO_data;
      end
    end
    if (reset) begin
      dec_reg_pc <= 64'h0;
    end else if (!(io_ctl_pipeline_kill)) begin
      if (_T) begin
        dec_reg_pc <= if_reg_pc;
      end
    end
    if (reset) begin
      exe_reg_valid <= 1'h0;
    end else if (_T_132) begin
      exe_reg_valid <= 1'h0;
    end else if (_T) begin
      if (io_ctl_dec_kill) begin
        exe_reg_valid <= 1'h0;
      end else begin
        exe_reg_valid <= dec_reg_valid;
      end
    end
    if (reset) begin
      exe_reg_inst <= 64'h4033;
    end else if (_T_132) begin
      exe_reg_inst <= 64'h4033;
    end else if (_T) begin
      if (io_ctl_dec_kill) begin
        exe_reg_inst <= 64'h4033;
      end else begin
        exe_reg_inst <= dec_reg_inst;
      end
    end
    if (reset) begin
      exe_reg_pc <= 64'h0;
    end else if (!(_T_132)) begin
      if (_T) begin
        exe_reg_pc <= dec_reg_pc;
      end
    end
    if (_T_132) begin
      exe_reg_wbaddr <= 5'h0;
    end else if (_T) begin
      if (io_ctl_dec_kill) begin
        exe_reg_wbaddr <= 5'h0;
      end else begin
        exe_reg_wbaddr <= dec_wbaddr;
      end
    end
    if (!(_T_132)) begin
      if (_T) begin
        if (_T_85) begin
          exe_alu_op1 <= {{32'd0}, imm_z};
        end else if (_T_86) begin
          exe_alu_op1 <= dec_reg_pc;
        end else if (_T_87) begin
          exe_alu_op1 <= _T_90;
        end else if (_T_73) begin
          if (_T_136) begin
            exe_alu_op1 <= _T_141;
          end else begin
            exe_alu_op1 <= alu_io_res;
          end
        end else if (_T_77) begin
          if (_T_194) begin
            if (_T_157) begin
              exe_alu_op1 <= _T_162;
            end else if (_T_163) begin
              exe_alu_op1 <= _T_166;
            end else if (_T_167) begin
              exe_alu_op1 <= _T_172;
            end else if (_T_173) begin
              exe_alu_op1 <= _T_176;
            end else if (_T_177) begin
              exe_alu_op1 <= _T_182;
            end else if (_T_183) begin
              exe_alu_op1 <= _T_186;
            end else begin
              exe_alu_op1 <= mem_reg_dram_data;
            end
          end else begin
            exe_alu_op1 <= mem_reg_alu_out;
          end
        end else if (_T_81) begin
          exe_alu_op1 <= wb_reg_wbdata;
        end else begin
          exe_alu_op1 <= regfile_io_rs1_data;
        end
      end
    end
    if (!(_T_132)) begin
      if (_T) begin
        if (_T_99) begin
          if (_T_136) begin
            brjmp_offset <= _T_141;
          end else begin
            brjmp_offset <= alu_io_res;
          end
        end else if (_T_105) begin
          if (_T_194) begin
            if (_T_157) begin
              brjmp_offset <= _T_162;
            end else if (_T_163) begin
              brjmp_offset <= _T_166;
            end else if (_T_167) begin
              brjmp_offset <= _T_172;
            end else if (_T_173) begin
              brjmp_offset <= _T_176;
            end else if (_T_177) begin
              brjmp_offset <= _T_182;
            end else if (_T_183) begin
              brjmp_offset <= _T_186;
            end else begin
              brjmp_offset <= mem_reg_dram_data;
            end
          end else begin
            brjmp_offset <= mem_reg_alu_out;
          end
        end else if (_T_111) begin
          brjmp_offset <= wb_reg_wbdata;
        end else if (_T_59) begin
          brjmp_offset <= regfile_io_rs2_data;
        end else if (_T_60) begin
          brjmp_offset <= imm_itype_sext;
        end else if (_T_61) begin
          brjmp_offset <= imm_stype_sext;
        end else if (_T_62) begin
          brjmp_offset <= imm_sbtype_sext;
        end else if (_T_63) begin
          brjmp_offset <= imm_utype_sext;
        end else if (_T_64) begin
          brjmp_offset <= imm_ujtype_sext;
        end else begin
          brjmp_offset <= 64'h0;
        end
      end
    end
    if (!(_T_132)) begin
      if (_T) begin
        if (_T_97) begin
          if (_T_136) begin
            exe_reg_rs2_data <= _T_141;
          end else begin
            exe_reg_rs2_data <= alu_io_res;
          end
        end else if (_T_103) begin
          if (_T_194) begin
            if (_T_157) begin
              exe_reg_rs2_data <= _T_162;
            end else if (_T_163) begin
              exe_reg_rs2_data <= _T_166;
            end else if (_T_167) begin
              exe_reg_rs2_data <= _T_172;
            end else if (_T_173) begin
              exe_reg_rs2_data <= _T_176;
            end else if (_T_177) begin
              exe_reg_rs2_data <= _T_182;
            end else if (_T_183) begin
              exe_reg_rs2_data <= _T_186;
            end else begin
              exe_reg_rs2_data <= mem_reg_dram_data;
            end
          end else begin
            exe_reg_rs2_data <= mem_reg_alu_out;
          end
        end else if (_T_109) begin
          exe_reg_rs2_data <= wb_reg_wbdata;
        end else begin
          exe_reg_rs2_data <= regfile_io_rs2_data;
        end
      end
    end
    if (reset) begin
      exe_reg_ctrl_br_type <= 4'h0;
    end else if (_T_132) begin
      exe_reg_ctrl_br_type <= 4'h0;
    end else if (_T) begin
      if (io_ctl_dec_kill) begin
        exe_reg_ctrl_br_type <= 4'h0;
      end else begin
        exe_reg_ctrl_br_type <= io_ctl_br_type;
      end
    end
    if (!(_T_132)) begin
      if (_T) begin
        exe_reg_ctrl_alu_fun <= io_ctl_alu_fun;
      end
    end
    if (!(_T_132)) begin
      if (_T) begin
        exe_reg_ctrl_wb_sel <= io_ctl_wb_sel;
      end
    end
    if (reset) begin
      exe_reg_ctrl_rf_wen <= 1'h0;
    end else if (_T_132) begin
      exe_reg_ctrl_rf_wen <= 1'h0;
    end else if (_T) begin
      if (io_ctl_dec_kill) begin
        exe_reg_ctrl_rf_wen <= 1'h0;
      end else begin
        exe_reg_ctrl_rf_wen <= io_ctl_rf_wen;
      end
    end
    if (reset) begin
      exe_reg_ctrl_mem_fcn <= 2'h0;
    end else if (_T_132) begin
      exe_reg_ctrl_mem_fcn <= 2'h0;
    end else if (_T) begin
      if (io_ctl_dec_kill) begin
        exe_reg_ctrl_mem_fcn <= 2'h0;
      end else begin
        exe_reg_ctrl_mem_fcn <= io_ctl_mem_fcn;
      end
    end
    if (reset) begin
      exe_reg_ctrl_mem_typ <= 8'hff;
    end else if (!(_T_132)) begin
      if (_T) begin
        if (!(io_ctl_dec_kill)) begin
          exe_reg_ctrl_mem_typ <= io_ctl_mem_typ;
        end
      end
    end
    if (reset) begin
      exe_reg_ctrl_mem_wid <= 3'h0;
    end else if (_T_132) begin
      exe_reg_ctrl_mem_wid <= 3'h0;
    end else if (_T) begin
      if (io_ctl_dec_kill) begin
        exe_reg_ctrl_mem_wid <= 3'h0;
      end else begin
        exe_reg_ctrl_mem_wid <= io_ctl_mem_wid;
      end
    end
    if (reset) begin
      exe_reg_ctrl_csr_cmd <= 3'h0;
    end else if (_T_132) begin
      exe_reg_ctrl_csr_cmd <= 3'h0;
    end else if (_T) begin
      if (io_ctl_dec_kill) begin
        exe_reg_ctrl_csr_cmd <= 3'h0;
      end else begin
        exe_reg_ctrl_csr_cmd <= io_ctl_csr_cmd;
      end
    end
    if (reset) begin
      mem_reg_valid <= 1'h0;
    end else if (io_ctl_pipeline_kill) begin
      mem_reg_valid <= 1'h0;
    end else begin
      mem_reg_valid <= exe_reg_valid;
    end
    if (!(io_ctl_pipeline_kill)) begin
      mem_reg_pc <= exe_reg_pc;
    end
    if (io_ctl_pipeline_kill) begin
      mem_reg_inst <= 64'h4033;
    end else begin
      mem_reg_inst <= exe_reg_inst;
    end
    if (!(io_ctl_pipeline_kill)) begin
      if (_T_150) begin
        mem_reg_alu_out <= exe_pc_plus4;
      end else if (_T_136) begin
        mem_reg_alu_out <= _T_141;
      end else begin
        mem_reg_alu_out <= alu_io_res;
      end
    end
    if (!(io_ctl_pipeline_kill)) begin
      mem_reg_wbaddr <= exe_reg_wbaddr;
    end
    if (reset) begin
      mem_reg_ctrl_rf_wen <= 1'h0;
    end else if (io_ctl_pipeline_kill) begin
      mem_reg_ctrl_rf_wen <= 1'h0;
    end else begin
      mem_reg_ctrl_rf_wen <= exe_reg_ctrl_rf_wen;
    end
    if (!(io_ctl_pipeline_kill)) begin
      mem_reg_ctrl_wb_sel <= exe_reg_ctrl_wb_sel;
    end
    if (reset) begin
      mem_reg_ctrl_mem_wid <= 3'h0;
    end else if (!(io_ctl_pipeline_kill)) begin
      mem_reg_ctrl_mem_wid <= exe_reg_ctrl_mem_wid;
    end
    if (reset) begin
      mem_reg_ctrl_csr_cmd <= 3'h0;
    end else if (io_ctl_pipeline_kill) begin
      mem_reg_ctrl_csr_cmd <= 3'h0;
    end else begin
      mem_reg_ctrl_csr_cmd <= exe_reg_ctrl_csr_cmd;
    end
    if (reset) begin
      mem_reg_dram_data <= 64'h0;
    end else begin
      mem_reg_dram_data <= io_data_readIO_data;
    end
    if (reset) begin
      wb_reg_valid <= 1'h0;
    end else begin
      wb_reg_valid <= mem_reg_valid;
    end
    wb_reg_pc <= mem_reg_pc;
    wb_reg_wbaddr <= mem_reg_wbaddr;
    if (_T_194) begin
      if (_T_157) begin
        wb_reg_wbdata <= _T_162;
      end else if (_T_163) begin
        wb_reg_wbdata <= _T_166;
      end else if (_T_167) begin
        wb_reg_wbdata <= _T_172;
      end else if (_T_173) begin
        wb_reg_wbdata <= _T_176;
      end else if (_T_177) begin
        wb_reg_wbdata <= _T_182;
      end else if (_T_183) begin
        wb_reg_wbdata <= _T_186;
      end else begin
        wb_reg_wbdata <= mem_reg_dram_data;
      end
    end else begin
      wb_reg_wbdata <= mem_reg_alu_out;
    end
    if (reset) begin
      wb_reg_ctrl_rf_wen <= 1'h0;
    end else begin
      wb_reg_ctrl_rf_wen <= mem_reg_ctrl_rf_wen;
    end
    _T_198 <= mem_reg_inst;
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_23) begin
          $fwrite(32'h80000002,"IF : pc=[%x] inst=[%x] if_pc_next=[%x] pc_sel=[%d] e_bj_pc=[%x]\n",if_reg_pc,io_inst_readIO_data,if_pc_next,io_ctl_exe_pc_sel,exe_brjmp_target); // @[dpath.scala 143:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_23) begin
          $fwrite(32'h80000002,"DEC: valid = %d pc=[%x] inst=[%x] op1=[%x] alu2=[%x] op2=[%x]\n",dec_reg_valid,dec_reg_pc,dec_reg_inst,dec_op1_data,dec_alu_op2,dec_op2_data); // @[dpath.scala 278:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_23) begin
          $fwrite(32'h80000002,"EXE: valid = %d pc=[%x] inst=[%x] bj_target = [%x]\n",exe_reg_valid,exe_reg_pc,exe_reg_inst,exe_brjmp_target); // @[dpath.scala 332:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_23) begin
          $fwrite(32'h80000002,"MEM read data = [%x]\n",mem_reg_dram_data); // @[dpath.scala 358:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_23) begin
          $fwrite(32'h80000002,"MEM: valid = %d pc=[%x] inst=[%x] wb_sel=[%d] wbdata=[%x]\n",mem_reg_valid,mem_reg_pc,mem_reg_inst,mem_reg_ctrl_wb_sel,mem_wbdata); // @[dpath.scala 375:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_23) begin
          $fwrite(32'h80000002,"WB : valid = %d pc=[%x] inst=[%x], mem_wbdata=[%x], mem_reg_wbaddr=[%d]\n",wb_reg_valid,wb_reg_pc,_T_198,wb_reg_wbdata,wb_reg_wbaddr); // @[dpath.scala 387:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_23) begin
          $fwrite(32'h80000002,"store: mem_typ=[%x] offset=[%x]\n",exe_reg_ctrl_mem_typ,exe_alu_out[2:0]); // @[dpath.scala 407:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_23) begin
          $fwrite(32'h80000002,"store:addr = [%x] en=%d data = [%x] mask = %b\n ",io_data_writeIO_addr,io_data_writeIO_en,io_data_writeIO_data,io_data_writeIO_mask); // @[dpath.scala 413:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_23) begin
          $fwrite(32'h80000002,"pc=[%x]\n",wb_reg_pc); // @[dpath.scala 415:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
  end
endmodule
module njucore(
  input         clock,
  input         reset,
  output [63:0] io_inst_readIO_addr,
  input  [63:0] io_inst_readIO_data,
  output [63:0] io_data_readIO_addr,
  input  [63:0] io_data_readIO_data,
  output        io_data_readIO_en,
  output [63:0] io_data_writeIO_addr,
  output [63:0] io_data_writeIO_data,
  output        io_data_writeIO_en,
  output [7:0]  io_data_writeIO_mask,
  output        wb_reg_valid,
  output [63:0] _T_42_0,
  output [63:0] _T_42_1,
  output [63:0] _T_42_2,
  output [63:0] _T_42_3,
  output [63:0] _T_42_4,
  output [63:0] _T_42_5,
  output [63:0] _T_42_6,
  output [63:0] _T_42_7,
  output [63:0] _T_42_8,
  output [63:0] _T_42_9,
  output [63:0] _T_42_10,
  output [63:0] _T_42_11,
  output [63:0] _T_42_12,
  output [63:0] _T_42_13,
  output [63:0] _T_42_14,
  output [63:0] _T_42_15,
  output [63:0] _T_42_16,
  output [63:0] _T_42_17,
  output [63:0] _T_42_18,
  output [63:0] _T_42_19,
  output [63:0] _T_42_20,
  output [63:0] _T_42_21,
  output [63:0] _T_42_22,
  output [63:0] _T_42_23,
  output [63:0] _T_42_24,
  output [63:0] _T_42_25,
  output [63:0] _T_42_26,
  output [63:0] _T_42_27,
  output [63:0] _T_42_28,
  output [63:0] _T_42_29,
  output [63:0] _T_42_30,
  output [63:0] _T_42_31,
  output [63:0] wb_reg_pc
);
  wire  cpath_clock; // @[core.scala 14:21]
  wire  cpath_reset; // @[core.scala 14:21]
  wire [63:0] cpath_io_dat_dec_inst; // @[core.scala 14:21]
  wire  cpath_io_dat_exe_br_eq; // @[core.scala 14:21]
  wire  cpath_io_dat_exe_br_lt; // @[core.scala 14:21]
  wire  cpath_io_dat_exe_br_ltu; // @[core.scala 14:21]
  wire [3:0] cpath_io_dat_exe_br_type; // @[core.scala 14:21]
  wire  cpath_io_dat_csr_eret; // @[core.scala 14:21]
  wire  cpath_io_ctl_dec_stall; // @[core.scala 14:21]
  wire [1:0] cpath_io_ctl_exe_pc_sel; // @[core.scala 14:21]
  wire [3:0] cpath_io_ctl_br_type; // @[core.scala 14:21]
  wire  cpath_io_ctl_if_kill; // @[core.scala 14:21]
  wire  cpath_io_ctl_dec_kill; // @[core.scala 14:21]
  wire [1:0] cpath_io_ctl_op1_sel; // @[core.scala 14:21]
  wire [2:0] cpath_io_ctl_op2_sel; // @[core.scala 14:21]
  wire [4:0] cpath_io_ctl_alu_fun; // @[core.scala 14:21]
  wire [2:0] cpath_io_ctl_wb_sel; // @[core.scala 14:21]
  wire  cpath_io_ctl_rf_wen; // @[core.scala 14:21]
  wire [1:0] cpath_io_ctl_mem_fcn; // @[core.scala 14:21]
  wire [7:0] cpath_io_ctl_mem_typ; // @[core.scala 14:21]
  wire [2:0] cpath_io_ctl_mem_wid; // @[core.scala 14:21]
  wire [2:0] cpath_io_ctl_csr_cmd; // @[core.scala 14:21]
  wire  cpath_io_ctl_fencei; // @[core.scala 14:21]
  wire  cpath_io_ctl_pipeline_kill; // @[core.scala 14:21]
  wire  dpath_clock; // @[core.scala 15:21]
  wire  dpath_reset; // @[core.scala 15:21]
  wire  dpath_io_ctl_dec_stall; // @[core.scala 15:21]
  wire [1:0] dpath_io_ctl_exe_pc_sel; // @[core.scala 15:21]
  wire [3:0] dpath_io_ctl_br_type; // @[core.scala 15:21]
  wire  dpath_io_ctl_if_kill; // @[core.scala 15:21]
  wire  dpath_io_ctl_dec_kill; // @[core.scala 15:21]
  wire [1:0] dpath_io_ctl_op1_sel; // @[core.scala 15:21]
  wire [2:0] dpath_io_ctl_op2_sel; // @[core.scala 15:21]
  wire [4:0] dpath_io_ctl_alu_fun; // @[core.scala 15:21]
  wire [2:0] dpath_io_ctl_wb_sel; // @[core.scala 15:21]
  wire  dpath_io_ctl_rf_wen; // @[core.scala 15:21]
  wire [1:0] dpath_io_ctl_mem_fcn; // @[core.scala 15:21]
  wire [7:0] dpath_io_ctl_mem_typ; // @[core.scala 15:21]
  wire [2:0] dpath_io_ctl_mem_wid; // @[core.scala 15:21]
  wire [2:0] dpath_io_ctl_csr_cmd; // @[core.scala 15:21]
  wire  dpath_io_ctl_fencei; // @[core.scala 15:21]
  wire  dpath_io_ctl_pipeline_kill; // @[core.scala 15:21]
  wire [63:0] dpath_io_dat_dec_inst; // @[core.scala 15:21]
  wire  dpath_io_dat_exe_br_eq; // @[core.scala 15:21]
  wire  dpath_io_dat_exe_br_lt; // @[core.scala 15:21]
  wire  dpath_io_dat_exe_br_ltu; // @[core.scala 15:21]
  wire [3:0] dpath_io_dat_exe_br_type; // @[core.scala 15:21]
  wire  dpath_io_dat_csr_eret; // @[core.scala 15:21]
  wire [63:0] dpath_io_inst_readIO_addr; // @[core.scala 15:21]
  wire [63:0] dpath_io_inst_readIO_data; // @[core.scala 15:21]
  wire [63:0] dpath_io_data_readIO_addr; // @[core.scala 15:21]
  wire [63:0] dpath_io_data_readIO_data; // @[core.scala 15:21]
  wire  dpath_io_data_readIO_en; // @[core.scala 15:21]
  wire [63:0] dpath_io_data_writeIO_addr; // @[core.scala 15:21]
  wire [63:0] dpath_io_data_writeIO_data; // @[core.scala 15:21]
  wire  dpath_io_data_writeIO_en; // @[core.scala 15:21]
  wire [7:0] dpath_io_data_writeIO_mask; // @[core.scala 15:21]
  wire  dpath_wb_reg_valid_0; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_0; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_1; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_2; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_3; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_4; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_5; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_6; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_7; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_8; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_9; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_10; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_11; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_12; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_13; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_14; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_15; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_16; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_17; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_18; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_19; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_20; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_21; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_22; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_23; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_24; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_25; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_26; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_27; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_28; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_29; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_30; // @[core.scala 15:21]
  wire [63:0] dpath__T_42_0_31; // @[core.scala 15:21]
  wire [63:0] dpath_wb_reg_pc_0; // @[core.scala 15:21]
  Cpath cpath ( // @[core.scala 14:21]
    .clock(cpath_clock),
    .reset(cpath_reset),
    .io_dat_dec_inst(cpath_io_dat_dec_inst),
    .io_dat_exe_br_eq(cpath_io_dat_exe_br_eq),
    .io_dat_exe_br_lt(cpath_io_dat_exe_br_lt),
    .io_dat_exe_br_ltu(cpath_io_dat_exe_br_ltu),
    .io_dat_exe_br_type(cpath_io_dat_exe_br_type),
    .io_dat_csr_eret(cpath_io_dat_csr_eret),
    .io_ctl_dec_stall(cpath_io_ctl_dec_stall),
    .io_ctl_exe_pc_sel(cpath_io_ctl_exe_pc_sel),
    .io_ctl_br_type(cpath_io_ctl_br_type),
    .io_ctl_if_kill(cpath_io_ctl_if_kill),
    .io_ctl_dec_kill(cpath_io_ctl_dec_kill),
    .io_ctl_op1_sel(cpath_io_ctl_op1_sel),
    .io_ctl_op2_sel(cpath_io_ctl_op2_sel),
    .io_ctl_alu_fun(cpath_io_ctl_alu_fun),
    .io_ctl_wb_sel(cpath_io_ctl_wb_sel),
    .io_ctl_rf_wen(cpath_io_ctl_rf_wen),
    .io_ctl_mem_fcn(cpath_io_ctl_mem_fcn),
    .io_ctl_mem_typ(cpath_io_ctl_mem_typ),
    .io_ctl_mem_wid(cpath_io_ctl_mem_wid),
    .io_ctl_csr_cmd(cpath_io_ctl_csr_cmd),
    .io_ctl_fencei(cpath_io_ctl_fencei),
    .io_ctl_pipeline_kill(cpath_io_ctl_pipeline_kill)
  );
  Dpath dpath ( // @[core.scala 15:21]
    .clock(dpath_clock),
    .reset(dpath_reset),
    .io_ctl_dec_stall(dpath_io_ctl_dec_stall),
    .io_ctl_exe_pc_sel(dpath_io_ctl_exe_pc_sel),
    .io_ctl_br_type(dpath_io_ctl_br_type),
    .io_ctl_if_kill(dpath_io_ctl_if_kill),
    .io_ctl_dec_kill(dpath_io_ctl_dec_kill),
    .io_ctl_op1_sel(dpath_io_ctl_op1_sel),
    .io_ctl_op2_sel(dpath_io_ctl_op2_sel),
    .io_ctl_alu_fun(dpath_io_ctl_alu_fun),
    .io_ctl_wb_sel(dpath_io_ctl_wb_sel),
    .io_ctl_rf_wen(dpath_io_ctl_rf_wen),
    .io_ctl_mem_fcn(dpath_io_ctl_mem_fcn),
    .io_ctl_mem_typ(dpath_io_ctl_mem_typ),
    .io_ctl_mem_wid(dpath_io_ctl_mem_wid),
    .io_ctl_csr_cmd(dpath_io_ctl_csr_cmd),
    .io_ctl_fencei(dpath_io_ctl_fencei),
    .io_ctl_pipeline_kill(dpath_io_ctl_pipeline_kill),
    .io_dat_dec_inst(dpath_io_dat_dec_inst),
    .io_dat_exe_br_eq(dpath_io_dat_exe_br_eq),
    .io_dat_exe_br_lt(dpath_io_dat_exe_br_lt),
    .io_dat_exe_br_ltu(dpath_io_dat_exe_br_ltu),
    .io_dat_exe_br_type(dpath_io_dat_exe_br_type),
    .io_dat_csr_eret(dpath_io_dat_csr_eret),
    .io_inst_readIO_addr(dpath_io_inst_readIO_addr),
    .io_inst_readIO_data(dpath_io_inst_readIO_data),
    .io_data_readIO_addr(dpath_io_data_readIO_addr),
    .io_data_readIO_data(dpath_io_data_readIO_data),
    .io_data_readIO_en(dpath_io_data_readIO_en),
    .io_data_writeIO_addr(dpath_io_data_writeIO_addr),
    .io_data_writeIO_data(dpath_io_data_writeIO_data),
    .io_data_writeIO_en(dpath_io_data_writeIO_en),
    .io_data_writeIO_mask(dpath_io_data_writeIO_mask),
    .wb_reg_valid_0(dpath_wb_reg_valid_0),
    ._T_42_0_0(dpath__T_42_0_0),
    ._T_42_0_1(dpath__T_42_0_1),
    ._T_42_0_2(dpath__T_42_0_2),
    ._T_42_0_3(dpath__T_42_0_3),
    ._T_42_0_4(dpath__T_42_0_4),
    ._T_42_0_5(dpath__T_42_0_5),
    ._T_42_0_6(dpath__T_42_0_6),
    ._T_42_0_7(dpath__T_42_0_7),
    ._T_42_0_8(dpath__T_42_0_8),
    ._T_42_0_9(dpath__T_42_0_9),
    ._T_42_0_10(dpath__T_42_0_10),
    ._T_42_0_11(dpath__T_42_0_11),
    ._T_42_0_12(dpath__T_42_0_12),
    ._T_42_0_13(dpath__T_42_0_13),
    ._T_42_0_14(dpath__T_42_0_14),
    ._T_42_0_15(dpath__T_42_0_15),
    ._T_42_0_16(dpath__T_42_0_16),
    ._T_42_0_17(dpath__T_42_0_17),
    ._T_42_0_18(dpath__T_42_0_18),
    ._T_42_0_19(dpath__T_42_0_19),
    ._T_42_0_20(dpath__T_42_0_20),
    ._T_42_0_21(dpath__T_42_0_21),
    ._T_42_0_22(dpath__T_42_0_22),
    ._T_42_0_23(dpath__T_42_0_23),
    ._T_42_0_24(dpath__T_42_0_24),
    ._T_42_0_25(dpath__T_42_0_25),
    ._T_42_0_26(dpath__T_42_0_26),
    ._T_42_0_27(dpath__T_42_0_27),
    ._T_42_0_28(dpath__T_42_0_28),
    ._T_42_0_29(dpath__T_42_0_29),
    ._T_42_0_30(dpath__T_42_0_30),
    ._T_42_0_31(dpath__T_42_0_31),
    .wb_reg_pc_0(dpath_wb_reg_pc_0)
  );
  assign io_inst_readIO_addr = dpath_io_inst_readIO_addr; // @[core.scala 17:19]
  assign io_data_readIO_addr = dpath_io_data_readIO_addr; // @[core.scala 18:19]
  assign io_data_readIO_en = dpath_io_data_readIO_en; // @[core.scala 18:19]
  assign io_data_writeIO_addr = dpath_io_data_writeIO_addr; // @[core.scala 19:19]
  assign io_data_writeIO_data = dpath_io_data_writeIO_data; // @[core.scala 19:19]
  assign io_data_writeIO_en = dpath_io_data_writeIO_en; // @[core.scala 19:19]
  assign io_data_writeIO_mask = dpath_io_data_writeIO_mask; // @[core.scala 19:19]
  assign wb_reg_valid = dpath_wb_reg_valid_0;
  assign _T_42_0 = dpath__T_42_0_0;
  assign _T_42_1 = dpath__T_42_0_1;
  assign _T_42_2 = dpath__T_42_0_2;
  assign _T_42_3 = dpath__T_42_0_3;
  assign _T_42_4 = dpath__T_42_0_4;
  assign _T_42_5 = dpath__T_42_0_5;
  assign _T_42_6 = dpath__T_42_0_6;
  assign _T_42_7 = dpath__T_42_0_7;
  assign _T_42_8 = dpath__T_42_0_8;
  assign _T_42_9 = dpath__T_42_0_9;
  assign _T_42_10 = dpath__T_42_0_10;
  assign _T_42_11 = dpath__T_42_0_11;
  assign _T_42_12 = dpath__T_42_0_12;
  assign _T_42_13 = dpath__T_42_0_13;
  assign _T_42_14 = dpath__T_42_0_14;
  assign _T_42_15 = dpath__T_42_0_15;
  assign _T_42_16 = dpath__T_42_0_16;
  assign _T_42_17 = dpath__T_42_0_17;
  assign _T_42_18 = dpath__T_42_0_18;
  assign _T_42_19 = dpath__T_42_0_19;
  assign _T_42_20 = dpath__T_42_0_20;
  assign _T_42_21 = dpath__T_42_0_21;
  assign _T_42_22 = dpath__T_42_0_22;
  assign _T_42_23 = dpath__T_42_0_23;
  assign _T_42_24 = dpath__T_42_0_24;
  assign _T_42_25 = dpath__T_42_0_25;
  assign _T_42_26 = dpath__T_42_0_26;
  assign _T_42_27 = dpath__T_42_0_27;
  assign _T_42_28 = dpath__T_42_0_28;
  assign _T_42_29 = dpath__T_42_0_29;
  assign _T_42_30 = dpath__T_42_0_30;
  assign _T_42_31 = dpath__T_42_0_31;
  assign wb_reg_pc = dpath_wb_reg_pc_0;
  assign cpath_clock = clock;
  assign cpath_reset = reset;
  assign cpath_io_dat_dec_inst = dpath_io_dat_dec_inst; // @[core.scala 22:16]
  assign cpath_io_dat_exe_br_eq = dpath_io_dat_exe_br_eq; // @[core.scala 22:16]
  assign cpath_io_dat_exe_br_lt = dpath_io_dat_exe_br_lt; // @[core.scala 22:16]
  assign cpath_io_dat_exe_br_ltu = dpath_io_dat_exe_br_ltu; // @[core.scala 22:16]
  assign cpath_io_dat_exe_br_type = dpath_io_dat_exe_br_type; // @[core.scala 22:16]
  assign cpath_io_dat_csr_eret = dpath_io_dat_csr_eret; // @[core.scala 22:16]
  assign dpath_clock = clock;
  assign dpath_reset = reset;
  assign dpath_io_ctl_dec_stall = cpath_io_ctl_dec_stall; // @[core.scala 21:16]
  assign dpath_io_ctl_exe_pc_sel = cpath_io_ctl_exe_pc_sel; // @[core.scala 21:16]
  assign dpath_io_ctl_br_type = cpath_io_ctl_br_type; // @[core.scala 21:16]
  assign dpath_io_ctl_if_kill = cpath_io_ctl_if_kill; // @[core.scala 21:16]
  assign dpath_io_ctl_dec_kill = cpath_io_ctl_dec_kill; // @[core.scala 21:16]
  assign dpath_io_ctl_op1_sel = cpath_io_ctl_op1_sel; // @[core.scala 21:16]
  assign dpath_io_ctl_op2_sel = cpath_io_ctl_op2_sel; // @[core.scala 21:16]
  assign dpath_io_ctl_alu_fun = cpath_io_ctl_alu_fun; // @[core.scala 21:16]
  assign dpath_io_ctl_wb_sel = cpath_io_ctl_wb_sel; // @[core.scala 21:16]
  assign dpath_io_ctl_rf_wen = cpath_io_ctl_rf_wen; // @[core.scala 21:16]
  assign dpath_io_ctl_mem_fcn = cpath_io_ctl_mem_fcn; // @[core.scala 21:16]
  assign dpath_io_ctl_mem_typ = cpath_io_ctl_mem_typ; // @[core.scala 21:16]
  assign dpath_io_ctl_mem_wid = cpath_io_ctl_mem_wid; // @[core.scala 21:16]
  assign dpath_io_ctl_csr_cmd = cpath_io_ctl_csr_cmd; // @[core.scala 21:16]
  assign dpath_io_ctl_fencei = cpath_io_ctl_fencei; // @[core.scala 21:16]
  assign dpath_io_ctl_pipeline_kill = cpath_io_ctl_pipeline_kill; // @[core.scala 21:16]
  assign dpath_io_inst_readIO_data = io_inst_readIO_data; // @[core.scala 17:19]
  assign dpath_io_data_readIO_data = io_data_readIO_data; // @[core.scala 18:19]
endmodule
module simTop(
  input         clock,
  input         reset,
  output [63:0] io_diffTestIO_regfile_0,
  output [63:0] io_diffTestIO_regfile_1,
  output [63:0] io_diffTestIO_regfile_2,
  output [63:0] io_diffTestIO_regfile_3,
  output [63:0] io_diffTestIO_regfile_4,
  output [63:0] io_diffTestIO_regfile_5,
  output [63:0] io_diffTestIO_regfile_6,
  output [63:0] io_diffTestIO_regfile_7,
  output [63:0] io_diffTestIO_regfile_8,
  output [63:0] io_diffTestIO_regfile_9,
  output [63:0] io_diffTestIO_regfile_10,
  output [63:0] io_diffTestIO_regfile_11,
  output [63:0] io_diffTestIO_regfile_12,
  output [63:0] io_diffTestIO_regfile_13,
  output [63:0] io_diffTestIO_regfile_14,
  output [63:0] io_diffTestIO_regfile_15,
  output [63:0] io_diffTestIO_regfile_16,
  output [63:0] io_diffTestIO_regfile_17,
  output [63:0] io_diffTestIO_regfile_18,
  output [63:0] io_diffTestIO_regfile_19,
  output [63:0] io_diffTestIO_regfile_20,
  output [63:0] io_diffTestIO_regfile_21,
  output [63:0] io_diffTestIO_regfile_22,
  output [63:0] io_diffTestIO_regfile_23,
  output [63:0] io_diffTestIO_regfile_24,
  output [63:0] io_diffTestIO_regfile_25,
  output [63:0] io_diffTestIO_regfile_26,
  output [63:0] io_diffTestIO_regfile_27,
  output [63:0] io_diffTestIO_regfile_28,
  output [63:0] io_diffTestIO_regfile_29,
  output [63:0] io_diffTestIO_regfile_30,
  output [63:0] io_diffTestIO_regfile_31,
  output [63:0] io_diffTestIO_pc,
  output        io_diffTestIO_valid,
  output [63:0] io_coreIO_inst_readIO_addr,
  input  [63:0] io_coreIO_inst_readIO_data,
  output        io_coreIO_inst_readIO_en,
  output [63:0] io_coreIO_data_readIO_addr,
  input  [63:0] io_coreIO_data_readIO_data,
  output        io_coreIO_data_readIO_en,
  output [63:0] io_coreIO_data_writeIO_addr,
  output [63:0] io_coreIO_data_writeIO_data,
  output        io_coreIO_data_writeIO_en,
  output [7:0]  io_coreIO_data_writeIO_mask
);
  wire  mycore_clock; // @[simTop.scala 15:22]
  wire  mycore_reset; // @[simTop.scala 15:22]
  wire [63:0] mycore_io_inst_readIO_addr; // @[simTop.scala 15:22]
  wire [63:0] mycore_io_inst_readIO_data; // @[simTop.scala 15:22]
  wire [63:0] mycore_io_data_readIO_addr; // @[simTop.scala 15:22]
  wire [63:0] mycore_io_data_readIO_data; // @[simTop.scala 15:22]
  wire  mycore_io_data_readIO_en; // @[simTop.scala 15:22]
  wire [63:0] mycore_io_data_writeIO_addr; // @[simTop.scala 15:22]
  wire [63:0] mycore_io_data_writeIO_data; // @[simTop.scala 15:22]
  wire  mycore_io_data_writeIO_en; // @[simTop.scala 15:22]
  wire [7:0] mycore_io_data_writeIO_mask; // @[simTop.scala 15:22]
  wire  mycore_wb_reg_valid; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_0; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_1; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_2; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_3; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_4; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_5; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_6; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_7; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_8; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_9; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_10; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_11; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_12; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_13; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_14; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_15; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_16; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_17; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_18; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_19; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_20; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_21; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_22; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_23; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_24; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_25; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_26; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_27; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_28; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_29; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_30; // @[simTop.scala 15:22]
  wire [63:0] mycore__T_42_31; // @[simTop.scala 15:22]
  wire [63:0] mycore_wb_reg_pc; // @[simTop.scala 15:22]
  njucore mycore ( // @[simTop.scala 15:22]
    .clock(mycore_clock),
    .reset(mycore_reset),
    .io_inst_readIO_addr(mycore_io_inst_readIO_addr),
    .io_inst_readIO_data(mycore_io_inst_readIO_data),
    .io_data_readIO_addr(mycore_io_data_readIO_addr),
    .io_data_readIO_data(mycore_io_data_readIO_data),
    .io_data_readIO_en(mycore_io_data_readIO_en),
    .io_data_writeIO_addr(mycore_io_data_writeIO_addr),
    .io_data_writeIO_data(mycore_io_data_writeIO_data),
    .io_data_writeIO_en(mycore_io_data_writeIO_en),
    .io_data_writeIO_mask(mycore_io_data_writeIO_mask),
    .wb_reg_valid(mycore_wb_reg_valid),
    ._T_42_0(mycore__T_42_0),
    ._T_42_1(mycore__T_42_1),
    ._T_42_2(mycore__T_42_2),
    ._T_42_3(mycore__T_42_3),
    ._T_42_4(mycore__T_42_4),
    ._T_42_5(mycore__T_42_5),
    ._T_42_6(mycore__T_42_6),
    ._T_42_7(mycore__T_42_7),
    ._T_42_8(mycore__T_42_8),
    ._T_42_9(mycore__T_42_9),
    ._T_42_10(mycore__T_42_10),
    ._T_42_11(mycore__T_42_11),
    ._T_42_12(mycore__T_42_12),
    ._T_42_13(mycore__T_42_13),
    ._T_42_14(mycore__T_42_14),
    ._T_42_15(mycore__T_42_15),
    ._T_42_16(mycore__T_42_16),
    ._T_42_17(mycore__T_42_17),
    ._T_42_18(mycore__T_42_18),
    ._T_42_19(mycore__T_42_19),
    ._T_42_20(mycore__T_42_20),
    ._T_42_21(mycore__T_42_21),
    ._T_42_22(mycore__T_42_22),
    ._T_42_23(mycore__T_42_23),
    ._T_42_24(mycore__T_42_24),
    ._T_42_25(mycore__T_42_25),
    ._T_42_26(mycore__T_42_26),
    ._T_42_27(mycore__T_42_27),
    ._T_42_28(mycore__T_42_28),
    ._T_42_29(mycore__T_42_29),
    ._T_42_30(mycore__T_42_30),
    ._T_42_31(mycore__T_42_31),
    .wb_reg_pc(mycore_wb_reg_pc)
  );
  assign io_diffTestIO_regfile_0 = mycore__T_42_0;
  assign io_diffTestIO_regfile_1 = mycore__T_42_1;
  assign io_diffTestIO_regfile_2 = mycore__T_42_2;
  assign io_diffTestIO_regfile_3 = mycore__T_42_3;
  assign io_diffTestIO_regfile_4 = mycore__T_42_4;
  assign io_diffTestIO_regfile_5 = mycore__T_42_5;
  assign io_diffTestIO_regfile_6 = mycore__T_42_6;
  assign io_diffTestIO_regfile_7 = mycore__T_42_7;
  assign io_diffTestIO_regfile_8 = mycore__T_42_8;
  assign io_diffTestIO_regfile_9 = mycore__T_42_9;
  assign io_diffTestIO_regfile_10 = mycore__T_42_10;
  assign io_diffTestIO_regfile_11 = mycore__T_42_11;
  assign io_diffTestIO_regfile_12 = mycore__T_42_12;
  assign io_diffTestIO_regfile_13 = mycore__T_42_13;
  assign io_diffTestIO_regfile_14 = mycore__T_42_14;
  assign io_diffTestIO_regfile_15 = mycore__T_42_15;
  assign io_diffTestIO_regfile_16 = mycore__T_42_16;
  assign io_diffTestIO_regfile_17 = mycore__T_42_17;
  assign io_diffTestIO_regfile_18 = mycore__T_42_18;
  assign io_diffTestIO_regfile_19 = mycore__T_42_19;
  assign io_diffTestIO_regfile_20 = mycore__T_42_20;
  assign io_diffTestIO_regfile_21 = mycore__T_42_21;
  assign io_diffTestIO_regfile_22 = mycore__T_42_22;
  assign io_diffTestIO_regfile_23 = mycore__T_42_23;
  assign io_diffTestIO_regfile_24 = mycore__T_42_24;
  assign io_diffTestIO_regfile_25 = mycore__T_42_25;
  assign io_diffTestIO_regfile_26 = mycore__T_42_26;
  assign io_diffTestIO_regfile_27 = mycore__T_42_27;
  assign io_diffTestIO_regfile_28 = mycore__T_42_28;
  assign io_diffTestIO_regfile_29 = mycore__T_42_29;
  assign io_diffTestIO_regfile_30 = mycore__T_42_30;
  assign io_diffTestIO_regfile_31 = mycore__T_42_31;
  assign io_diffTestIO_pc = mycore_wb_reg_pc;
  assign io_diffTestIO_valid = mycore_wb_reg_valid;
  assign io_coreIO_inst_readIO_addr = mycore_io_inst_readIO_addr; // @[simTop.scala 19:13]
  assign io_coreIO_inst_readIO_en = 1'h1; // @[simTop.scala 19:13]
  assign io_coreIO_data_readIO_addr = mycore_io_data_readIO_addr; // @[simTop.scala 19:13]
  assign io_coreIO_data_readIO_en = mycore_io_data_readIO_en; // @[simTop.scala 19:13]
  assign io_coreIO_data_writeIO_addr = mycore_io_data_writeIO_addr; // @[simTop.scala 19:13]
  assign io_coreIO_data_writeIO_data = mycore_io_data_writeIO_data; // @[simTop.scala 19:13]
  assign io_coreIO_data_writeIO_en = mycore_io_data_writeIO_en; // @[simTop.scala 19:13]
  assign io_coreIO_data_writeIO_mask = mycore_io_data_writeIO_mask; // @[simTop.scala 19:13]
  assign mycore_clock = clock;
  assign mycore_reset = reset;
  assign mycore_io_inst_readIO_data = io_coreIO_inst_readIO_data; // @[simTop.scala 19:13]
  assign mycore_io_data_readIO_data = io_coreIO_data_readIO_data; // @[simTop.scala 19:13]
endmodule
