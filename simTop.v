module Cpath(
  input         clock,
  input         reset,
  input  [63:0] io_dat_dec_inst,
  input         io_dat_exe_br_eq,
  input         io_dat_exe_br_lt,
  input         io_dat_exe_br_ltu,
  input  [3:0]  io_dat_exe_br_type,
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
  output [2:0]  io_ctl_mem_ext
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
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
  wire  _T_125 = _T_121 | _T_123; // @[Lookup.scala 33:37]
  wire  _T_126 = _T_119 | _T_125; // @[Lookup.scala 33:37]
  wire  _T_127 = _T_117 | _T_126; // @[Lookup.scala 33:37]
  wire  _T_128 = _T_115 | _T_127; // @[Lookup.scala 33:37]
  wire  _T_129 = _T_113 | _T_128; // @[Lookup.scala 33:37]
  wire  _T_130 = _T_111 | _T_129; // @[Lookup.scala 33:37]
  wire  _T_131 = _T_109 | _T_130; // @[Lookup.scala 33:37]
  wire  _T_132 = _T_107 | _T_131; // @[Lookup.scala 33:37]
  wire  _T_133 = _T_105 | _T_132; // @[Lookup.scala 33:37]
  wire  _T_134 = _T_103 | _T_133; // @[Lookup.scala 33:37]
  wire  _T_135 = _T_101 | _T_134; // @[Lookup.scala 33:37]
  wire  _T_136 = _T_99 | _T_135; // @[Lookup.scala 33:37]
  wire  _T_137 = _T_97 | _T_136; // @[Lookup.scala 33:37]
  wire  _T_138 = _T_95 | _T_137; // @[Lookup.scala 33:37]
  wire  _T_139 = _T_93 | _T_138; // @[Lookup.scala 33:37]
  wire  _T_140 = _T_91 | _T_139; // @[Lookup.scala 33:37]
  wire  _T_141 = _T_89 | _T_140; // @[Lookup.scala 33:37]
  wire  _T_142 = _T_87 | _T_141; // @[Lookup.scala 33:37]
  wire  _T_143 = _T_85 | _T_142; // @[Lookup.scala 33:37]
  wire [3:0] _T_198 = _T_97 ? 4'h6 : 4'h0; // @[Lookup.scala 33:37]
  wire [3:0] _T_199 = _T_95 ? 4'h5 : _T_198; // @[Lookup.scala 33:37]
  wire [3:0] _T_200 = _T_93 ? 4'h4 : _T_199; // @[Lookup.scala 33:37]
  wire [3:0] _T_201 = _T_91 ? 4'h3 : _T_200; // @[Lookup.scala 33:37]
  wire [3:0] _T_202 = _T_89 ? 4'h1 : _T_201; // @[Lookup.scala 33:37]
  wire [3:0] _T_203 = _T_87 ? 4'h2 : _T_202; // @[Lookup.scala 33:37]
  wire [3:0] _T_204 = _T_85 ? 4'h8 : _T_203; // @[Lookup.scala 33:37]
  wire [3:0] _T_205 = _T_83 ? 4'h7 : _T_204; // @[Lookup.scala 33:37]
  wire [3:0] _T_206 = _T_81 ? 4'h0 : _T_205; // @[Lookup.scala 33:37]
  wire [3:0] _T_207 = _T_79 ? 4'h0 : _T_206; // @[Lookup.scala 33:37]
  wire [3:0] _T_208 = _T_77 ? 4'h0 : _T_207; // @[Lookup.scala 33:37]
  wire [3:0] _T_209 = _T_75 ? 4'h0 : _T_208; // @[Lookup.scala 33:37]
  wire [3:0] _T_210 = _T_73 ? 4'h0 : _T_209; // @[Lookup.scala 33:37]
  wire [3:0] _T_211 = _T_71 ? 4'h0 : _T_210; // @[Lookup.scala 33:37]
  wire [3:0] _T_212 = _T_69 ? 4'h0 : _T_211; // @[Lookup.scala 33:37]
  wire [3:0] _T_213 = _T_67 ? 4'h0 : _T_212; // @[Lookup.scala 33:37]
  wire [3:0] _T_214 = _T_65 ? 4'h0 : _T_213; // @[Lookup.scala 33:37]
  wire [3:0] _T_215 = _T_63 ? 4'h0 : _T_214; // @[Lookup.scala 33:37]
  wire [3:0] _T_216 = _T_61 ? 4'h0 : _T_215; // @[Lookup.scala 33:37]
  wire [3:0] _T_217 = _T_59 ? 4'h0 : _T_216; // @[Lookup.scala 33:37]
  wire [3:0] _T_218 = _T_57 ? 4'h0 : _T_217; // @[Lookup.scala 33:37]
  wire [3:0] _T_219 = _T_55 ? 4'h0 : _T_218; // @[Lookup.scala 33:37]
  wire [3:0] _T_220 = _T_53 ? 4'h0 : _T_219; // @[Lookup.scala 33:37]
  wire [3:0] _T_221 = _T_51 ? 4'h0 : _T_220; // @[Lookup.scala 33:37]
  wire [3:0] _T_222 = _T_49 ? 4'h0 : _T_221; // @[Lookup.scala 33:37]
  wire [3:0] _T_223 = _T_47 ? 4'h0 : _T_222; // @[Lookup.scala 33:37]
  wire [3:0] _T_224 = _T_45 ? 4'h0 : _T_223; // @[Lookup.scala 33:37]
  wire [3:0] _T_225 = _T_43 ? 4'h0 : _T_224; // @[Lookup.scala 33:37]
  wire [3:0] _T_226 = _T_41 ? 4'h0 : _T_225; // @[Lookup.scala 33:37]
  wire [3:0] _T_227 = _T_39 ? 4'h0 : _T_226; // @[Lookup.scala 33:37]
  wire [3:0] _T_228 = _T_37 ? 4'h0 : _T_227; // @[Lookup.scala 33:37]
  wire [3:0] _T_229 = _T_35 ? 4'h0 : _T_228; // @[Lookup.scala 33:37]
  wire [3:0] _T_230 = _T_33 ? 4'h0 : _T_229; // @[Lookup.scala 33:37]
  wire [3:0] _T_231 = _T_31 ? 4'h0 : _T_230; // @[Lookup.scala 33:37]
  wire [3:0] _T_232 = _T_29 ? 4'h0 : _T_231; // @[Lookup.scala 33:37]
  wire [3:0] _T_233 = _T_27 ? 4'h0 : _T_232; // @[Lookup.scala 33:37]
  wire [3:0] _T_234 = _T_25 ? 4'h0 : _T_233; // @[Lookup.scala 33:37]
  wire [3:0] _T_235 = _T_23 ? 4'h0 : _T_234; // @[Lookup.scala 33:37]
  wire [3:0] _T_236 = _T_21 ? 4'h0 : _T_235; // @[Lookup.scala 33:37]
  wire [3:0] _T_237 = _T_19 ? 4'h0 : _T_236; // @[Lookup.scala 33:37]
  wire [3:0] _T_238 = _T_17 ? 4'h0 : _T_237; // @[Lookup.scala 33:37]
  wire [3:0] _T_239 = _T_15 ? 4'h0 : _T_238; // @[Lookup.scala 33:37]
  wire [3:0] _T_240 = _T_13 ? 4'h0 : _T_239; // @[Lookup.scala 33:37]
  wire [3:0] _T_241 = _T_11 ? 4'h0 : _T_240; // @[Lookup.scala 33:37]
  wire [3:0] _T_242 = _T_9 ? 4'h0 : _T_241; // @[Lookup.scala 33:37]
  wire [3:0] _T_243 = _T_7 ? 4'h0 : _T_242; // @[Lookup.scala 33:37]
  wire [3:0] _T_244 = _T_5 ? 4'h0 : _T_243; // @[Lookup.scala 33:37]
  wire [3:0] _T_245 = _T_3 ? 4'h0 : _T_244; // @[Lookup.scala 33:37]
  wire [1:0] _T_267 = _T_81 ? 2'h3 : 2'h0; // @[Lookup.scala 33:37]
  wire [1:0] _T_268 = _T_79 ? 2'h3 : _T_267; // @[Lookup.scala 33:37]
  wire [1:0] _T_269 = _T_77 ? 2'h3 : _T_268; // @[Lookup.scala 33:37]
  wire [1:0] _T_270 = _T_75 ? 2'h0 : _T_269; // @[Lookup.scala 33:37]
  wire [1:0] _T_271 = _T_73 ? 2'h0 : _T_270; // @[Lookup.scala 33:37]
  wire [1:0] _T_272 = _T_71 ? 2'h3 : _T_271; // @[Lookup.scala 33:37]
  wire [1:0] _T_273 = _T_69 ? 2'h3 : _T_272; // @[Lookup.scala 33:37]
  wire [1:0] _T_274 = _T_67 ? 2'h3 : _T_273; // @[Lookup.scala 33:37]
  wire [1:0] _T_275 = _T_65 ? 2'h0 : _T_274; // @[Lookup.scala 33:37]
  wire [1:0] _T_276 = _T_63 ? 2'h0 : _T_275; // @[Lookup.scala 33:37]
  wire [1:0] _T_277 = _T_61 ? 2'h0 : _T_276; // @[Lookup.scala 33:37]
  wire [1:0] _T_278 = _T_59 ? 2'h0 : _T_277; // @[Lookup.scala 33:37]
  wire [1:0] _T_279 = _T_57 ? 2'h0 : _T_278; // @[Lookup.scala 33:37]
  wire [1:0] _T_280 = _T_55 ? 2'h0 : _T_279; // @[Lookup.scala 33:37]
  wire [1:0] _T_281 = _T_53 ? 2'h0 : _T_280; // @[Lookup.scala 33:37]
  wire [1:0] _T_282 = _T_51 ? 2'h0 : _T_281; // @[Lookup.scala 33:37]
  wire [1:0] _T_283 = _T_49 ? 2'h0 : _T_282; // @[Lookup.scala 33:37]
  wire [1:0] _T_284 = _T_47 ? 2'h0 : _T_283; // @[Lookup.scala 33:37]
  wire [1:0] _T_285 = _T_45 ? 2'h0 : _T_284; // @[Lookup.scala 33:37]
  wire [1:0] _T_286 = _T_43 ? 2'h0 : _T_285; // @[Lookup.scala 33:37]
  wire [1:0] _T_287 = _T_41 ? 2'h0 : _T_286; // @[Lookup.scala 33:37]
  wire [1:0] _T_288 = _T_39 ? 2'h0 : _T_287; // @[Lookup.scala 33:37]
  wire [1:0] _T_289 = _T_37 ? 2'h0 : _T_288; // @[Lookup.scala 33:37]
  wire [1:0] _T_290 = _T_35 ? 2'h0 : _T_289; // @[Lookup.scala 33:37]
  wire [1:0] _T_291 = _T_33 ? 2'h0 : _T_290; // @[Lookup.scala 33:37]
  wire [1:0] _T_292 = _T_31 ? 2'h0 : _T_291; // @[Lookup.scala 33:37]
  wire [1:0] _T_293 = _T_29 ? 2'h0 : _T_292; // @[Lookup.scala 33:37]
  wire [1:0] _T_294 = _T_27 ? 2'h0 : _T_293; // @[Lookup.scala 33:37]
  wire [1:0] _T_295 = _T_25 ? 2'h0 : _T_294; // @[Lookup.scala 33:37]
  wire [1:0] _T_296 = _T_23 ? 2'h1 : _T_295; // @[Lookup.scala 33:37]
  wire [1:0] _T_297 = _T_21 ? 2'h0 : _T_296; // @[Lookup.scala 33:37]
  wire [1:0] _T_298 = _T_19 ? 2'h0 : _T_297; // @[Lookup.scala 33:37]
  wire [1:0] _T_299 = _T_17 ? 2'h0 : _T_298; // @[Lookup.scala 33:37]
  wire [1:0] _T_300 = _T_15 ? 2'h0 : _T_299; // @[Lookup.scala 33:37]
  wire [1:0] _T_301 = _T_13 ? 2'h0 : _T_300; // @[Lookup.scala 33:37]
  wire [1:0] _T_302 = _T_11 ? 2'h0 : _T_301; // @[Lookup.scala 33:37]
  wire [1:0] _T_303 = _T_9 ? 2'h0 : _T_302; // @[Lookup.scala 33:37]
  wire [1:0] _T_304 = _T_7 ? 2'h0 : _T_303; // @[Lookup.scala 33:37]
  wire [1:0] _T_305 = _T_5 ? 2'h0 : _T_304; // @[Lookup.scala 33:37]
  wire [1:0] _T_306 = _T_3 ? 2'h0 : _T_305; // @[Lookup.scala 33:37]
  wire [2:0] _T_320 = _T_97 ? 3'h3 : 3'h0; // @[Lookup.scala 33:37]
  wire [2:0] _T_321 = _T_95 ? 3'h3 : _T_320; // @[Lookup.scala 33:37]
  wire [2:0] _T_322 = _T_93 ? 3'h3 : _T_321; // @[Lookup.scala 33:37]
  wire [2:0] _T_323 = _T_91 ? 3'h3 : _T_322; // @[Lookup.scala 33:37]
  wire [2:0] _T_324 = _T_89 ? 3'h3 : _T_323; // @[Lookup.scala 33:37]
  wire [2:0] _T_325 = _T_87 ? 3'h3 : _T_324; // @[Lookup.scala 33:37]
  wire [2:0] _T_326 = _T_85 ? 3'h1 : _T_325; // @[Lookup.scala 33:37]
  wire [2:0] _T_327 = _T_83 ? 3'h5 : _T_326; // @[Lookup.scala 33:37]
  wire [2:0] _T_328 = _T_81 ? 3'h0 : _T_327; // @[Lookup.scala 33:37]
  wire [2:0] _T_329 = _T_79 ? 3'h0 : _T_328; // @[Lookup.scala 33:37]
  wire [2:0] _T_330 = _T_77 ? 3'h0 : _T_329; // @[Lookup.scala 33:37]
  wire [2:0] _T_331 = _T_75 ? 3'h0 : _T_330; // @[Lookup.scala 33:37]
  wire [2:0] _T_332 = _T_73 ? 3'h0 : _T_331; // @[Lookup.scala 33:37]
  wire [2:0] _T_333 = _T_71 ? 3'h1 : _T_332; // @[Lookup.scala 33:37]
  wire [2:0] _T_334 = _T_69 ? 3'h1 : _T_333; // @[Lookup.scala 33:37]
  wire [2:0] _T_335 = _T_67 ? 3'h1 : _T_334; // @[Lookup.scala 33:37]
  wire [2:0] _T_336 = _T_65 ? 3'h1 : _T_335; // @[Lookup.scala 33:37]
  wire [2:0] _T_337 = _T_63 ? 3'h0 : _T_336; // @[Lookup.scala 33:37]
  wire [2:0] _T_338 = _T_61 ? 3'h0 : _T_337; // @[Lookup.scala 33:37]
  wire [2:0] _T_339 = _T_59 ? 3'h0 : _T_338; // @[Lookup.scala 33:37]
  wire [2:0] _T_340 = _T_57 ? 3'h0 : _T_339; // @[Lookup.scala 33:37]
  wire [2:0] _T_341 = _T_55 ? 3'h0 : _T_340; // @[Lookup.scala 33:37]
  wire [2:0] _T_342 = _T_53 ? 3'h0 : _T_341; // @[Lookup.scala 33:37]
  wire [2:0] _T_343 = _T_51 ? 3'h0 : _T_342; // @[Lookup.scala 33:37]
  wire [2:0] _T_344 = _T_49 ? 3'h0 : _T_343; // @[Lookup.scala 33:37]
  wire [2:0] _T_345 = _T_47 ? 3'h0 : _T_344; // @[Lookup.scala 33:37]
  wire [2:0] _T_346 = _T_45 ? 3'h0 : _T_345; // @[Lookup.scala 33:37]
  wire [2:0] _T_347 = _T_43 ? 3'h1 : _T_346; // @[Lookup.scala 33:37]
  wire [2:0] _T_348 = _T_41 ? 3'h1 : _T_347; // @[Lookup.scala 33:37]
  wire [2:0] _T_349 = _T_39 ? 3'h1 : _T_348; // @[Lookup.scala 33:37]
  wire [2:0] _T_350 = _T_37 ? 3'h1 : _T_349; // @[Lookup.scala 33:37]
  wire [2:0] _T_351 = _T_35 ? 3'h1 : _T_350; // @[Lookup.scala 33:37]
  wire [2:0] _T_352 = _T_33 ? 3'h1 : _T_351; // @[Lookup.scala 33:37]
  wire [2:0] _T_353 = _T_31 ? 3'h1 : _T_352; // @[Lookup.scala 33:37]
  wire [2:0] _T_354 = _T_29 ? 3'h1 : _T_353; // @[Lookup.scala 33:37]
  wire [2:0] _T_355 = _T_27 ? 3'h1 : _T_354; // @[Lookup.scala 33:37]
  wire [2:0] _T_356 = _T_25 ? 3'h4 : _T_355; // @[Lookup.scala 33:37]
  wire [2:0] _T_357 = _T_23 ? 3'h4 : _T_356; // @[Lookup.scala 33:37]
  wire [2:0] _T_358 = _T_21 ? 3'h2 : _T_357; // @[Lookup.scala 33:37]
  wire [2:0] _T_359 = _T_19 ? 3'h2 : _T_358; // @[Lookup.scala 33:37]
  wire [2:0] _T_360 = _T_17 ? 3'h2 : _T_359; // @[Lookup.scala 33:37]
  wire [2:0] _T_361 = _T_15 ? 3'h2 : _T_360; // @[Lookup.scala 33:37]
  wire [2:0] _T_362 = _T_13 ? 3'h1 : _T_361; // @[Lookup.scala 33:37]
  wire [2:0] _T_363 = _T_11 ? 3'h1 : _T_362; // @[Lookup.scala 33:37]
  wire [2:0] _T_364 = _T_9 ? 3'h1 : _T_363; // @[Lookup.scala 33:37]
  wire [2:0] _T_365 = _T_7 ? 3'h1 : _T_364; // @[Lookup.scala 33:37]
  wire [2:0] _T_366 = _T_5 ? 3'h1 : _T_365; // @[Lookup.scala 33:37]
  wire [2:0] _T_367 = _T_3 ? 3'h1 : _T_366; // @[Lookup.scala 33:37]
  wire  _T_388 = _T_83 ? 1'h0 : _T_143; // @[Lookup.scala 33:37]
  wire  _T_389 = _T_81 | _T_388; // @[Lookup.scala 33:37]
  wire  _T_390 = _T_79 | _T_389; // @[Lookup.scala 33:37]
  wire  _T_391 = _T_77 | _T_390; // @[Lookup.scala 33:37]
  wire  _T_392 = _T_75 | _T_391; // @[Lookup.scala 33:37]
  wire  _T_393 = _T_73 | _T_392; // @[Lookup.scala 33:37]
  wire  _T_394 = _T_71 | _T_393; // @[Lookup.scala 33:37]
  wire  _T_395 = _T_69 | _T_394; // @[Lookup.scala 33:37]
  wire  _T_396 = _T_67 | _T_395; // @[Lookup.scala 33:37]
  wire  _T_397 = _T_65 | _T_396; // @[Lookup.scala 33:37]
  wire  _T_398 = _T_63 | _T_397; // @[Lookup.scala 33:37]
  wire  _T_399 = _T_61 | _T_398; // @[Lookup.scala 33:37]
  wire  _T_400 = _T_59 | _T_399; // @[Lookup.scala 33:37]
  wire  _T_401 = _T_57 | _T_400; // @[Lookup.scala 33:37]
  wire  _T_402 = _T_55 | _T_401; // @[Lookup.scala 33:37]
  wire  _T_403 = _T_53 | _T_402; // @[Lookup.scala 33:37]
  wire  _T_404 = _T_51 | _T_403; // @[Lookup.scala 33:37]
  wire  _T_405 = _T_49 | _T_404; // @[Lookup.scala 33:37]
  wire  _T_406 = _T_47 | _T_405; // @[Lookup.scala 33:37]
  wire  _T_407 = _T_45 | _T_406; // @[Lookup.scala 33:37]
  wire  _T_408 = _T_43 | _T_407; // @[Lookup.scala 33:37]
  wire  _T_409 = _T_41 | _T_408; // @[Lookup.scala 33:37]
  wire  _T_410 = _T_39 | _T_409; // @[Lookup.scala 33:37]
  wire  _T_411 = _T_37 | _T_410; // @[Lookup.scala 33:37]
  wire  _T_412 = _T_35 | _T_411; // @[Lookup.scala 33:37]
  wire  _T_413 = _T_33 | _T_412; // @[Lookup.scala 33:37]
  wire  _T_414 = _T_31 | _T_413; // @[Lookup.scala 33:37]
  wire  _T_415 = _T_29 | _T_414; // @[Lookup.scala 33:37]
  wire  _T_416 = _T_27 | _T_415; // @[Lookup.scala 33:37]
  wire  _T_417 = _T_25 ? 1'h0 : _T_416; // @[Lookup.scala 33:37]
  wire  _T_418 = _T_23 ? 1'h0 : _T_417; // @[Lookup.scala 33:37]
  wire  _T_419 = _T_21 | _T_418; // @[Lookup.scala 33:37]
  wire  _T_420 = _T_19 | _T_419; // @[Lookup.scala 33:37]
  wire  _T_421 = _T_17 | _T_420; // @[Lookup.scala 33:37]
  wire  _T_422 = _T_15 | _T_421; // @[Lookup.scala 33:37]
  wire  _T_423 = _T_13 | _T_422; // @[Lookup.scala 33:37]
  wire  _T_424 = _T_11 | _T_423; // @[Lookup.scala 33:37]
  wire  _T_425 = _T_9 | _T_424; // @[Lookup.scala 33:37]
  wire  _T_426 = _T_7 | _T_425; // @[Lookup.scala 33:37]
  wire  _T_427 = _T_5 | _T_426; // @[Lookup.scala 33:37]
  wire  _T_428 = _T_3 | _T_427; // @[Lookup.scala 33:37]
  wire  cs_rs1_oen = _T_1 | _T_428; // @[Lookup.scala 33:37]
  wire  _T_448 = _T_85 ? 1'h0 : _T_142; // @[Lookup.scala 33:37]
  wire  _T_449 = _T_83 ? 1'h0 : _T_448; // @[Lookup.scala 33:37]
  wire  _T_450 = _T_81 | _T_449; // @[Lookup.scala 33:37]
  wire  _T_451 = _T_79 | _T_450; // @[Lookup.scala 33:37]
  wire  _T_452 = _T_77 | _T_451; // @[Lookup.scala 33:37]
  wire  _T_453 = _T_75 | _T_452; // @[Lookup.scala 33:37]
  wire  _T_454 = _T_73 | _T_453; // @[Lookup.scala 33:37]
  wire  _T_455 = _T_71 ? 1'h0 : _T_454; // @[Lookup.scala 33:37]
  wire  _T_456 = _T_69 ? 1'h0 : _T_455; // @[Lookup.scala 33:37]
  wire  _T_457 = _T_67 ? 1'h0 : _T_456; // @[Lookup.scala 33:37]
  wire  _T_458 = _T_65 ? 1'h0 : _T_457; // @[Lookup.scala 33:37]
  wire  _T_459 = _T_63 | _T_458; // @[Lookup.scala 33:37]
  wire  _T_460 = _T_61 | _T_459; // @[Lookup.scala 33:37]
  wire  _T_461 = _T_59 | _T_460; // @[Lookup.scala 33:37]
  wire  _T_462 = _T_57 | _T_461; // @[Lookup.scala 33:37]
  wire  _T_463 = _T_55 | _T_462; // @[Lookup.scala 33:37]
  wire  _T_464 = _T_53 | _T_463; // @[Lookup.scala 33:37]
  wire  _T_465 = _T_51 | _T_464; // @[Lookup.scala 33:37]
  wire  _T_466 = _T_49 | _T_465; // @[Lookup.scala 33:37]
  wire  _T_467 = _T_47 | _T_466; // @[Lookup.scala 33:37]
  wire  _T_468 = _T_45 | _T_467; // @[Lookup.scala 33:37]
  wire  _T_469 = _T_43 ? 1'h0 : _T_468; // @[Lookup.scala 33:37]
  wire  _T_470 = _T_41 ? 1'h0 : _T_469; // @[Lookup.scala 33:37]
  wire  _T_471 = _T_39 ? 1'h0 : _T_470; // @[Lookup.scala 33:37]
  wire  _T_472 = _T_37 ? 1'h0 : _T_471; // @[Lookup.scala 33:37]
  wire  _T_473 = _T_35 ? 1'h0 : _T_472; // @[Lookup.scala 33:37]
  wire  _T_474 = _T_33 ? 1'h0 : _T_473; // @[Lookup.scala 33:37]
  wire  _T_475 = _T_31 ? 1'h0 : _T_474; // @[Lookup.scala 33:37]
  wire  _T_476 = _T_29 ? 1'h0 : _T_475; // @[Lookup.scala 33:37]
  wire  _T_477 = _T_27 ? 1'h0 : _T_476; // @[Lookup.scala 33:37]
  wire  _T_478 = _T_25 ? 1'h0 : _T_477; // @[Lookup.scala 33:37]
  wire  _T_479 = _T_23 ? 1'h0 : _T_478; // @[Lookup.scala 33:37]
  wire  _T_480 = _T_21 | _T_479; // @[Lookup.scala 33:37]
  wire  _T_481 = _T_19 | _T_480; // @[Lookup.scala 33:37]
  wire  _T_482 = _T_17 | _T_481; // @[Lookup.scala 33:37]
  wire  _T_483 = _T_15 | _T_482; // @[Lookup.scala 33:37]
  wire  _T_484 = _T_13 ? 1'h0 : _T_483; // @[Lookup.scala 33:37]
  wire  _T_485 = _T_11 ? 1'h0 : _T_484; // @[Lookup.scala 33:37]
  wire  _T_486 = _T_9 ? 1'h0 : _T_485; // @[Lookup.scala 33:37]
  wire  _T_487 = _T_7 ? 1'h0 : _T_486; // @[Lookup.scala 33:37]
  wire  _T_488 = _T_5 ? 1'h0 : _T_487; // @[Lookup.scala 33:37]
  wire  _T_489 = _T_3 ? 1'h0 : _T_488; // @[Lookup.scala 33:37]
  wire  cs_rs2_oen = _T_1 ? 1'h0 : _T_489; // @[Lookup.scala 33:37]
  wire [4:0] _T_490 = _T_123 ? 5'h18 : 5'h0; // @[Lookup.scala 33:37]
  wire [4:0] _T_491 = _T_121 ? 5'h17 : _T_490; // @[Lookup.scala 33:37]
  wire [4:0] _T_492 = _T_119 ? 5'h10 : _T_491; // @[Lookup.scala 33:37]
  wire [4:0] _T_493 = _T_117 ? 5'hf : _T_492; // @[Lookup.scala 33:37]
  wire [4:0] _T_494 = _T_115 ? 5'h16 : _T_493; // @[Lookup.scala 33:37]
  wire [4:0] _T_495 = _T_113 ? 5'h15 : _T_494; // @[Lookup.scala 33:37]
  wire [4:0] _T_496 = _T_111 ? 5'h11 : _T_495; // @[Lookup.scala 33:37]
  wire [4:0] _T_497 = _T_109 ? 5'he : _T_496; // @[Lookup.scala 33:37]
  wire [4:0] _T_498 = _T_107 ? 5'h14 : _T_497; // @[Lookup.scala 33:37]
  wire [4:0] _T_499 = _T_105 ? 5'h13 : _T_498; // @[Lookup.scala 33:37]
  wire [4:0] _T_500 = _T_103 ? 5'h12 : _T_499; // @[Lookup.scala 33:37]
  wire [4:0] _T_501 = _T_101 ? 5'hd : _T_500; // @[Lookup.scala 33:37]
  wire [4:0] _T_502 = _T_99 ? 5'hd : _T_501; // @[Lookup.scala 33:37]
  wire [4:0] _T_503 = _T_97 ? 5'h0 : _T_502; // @[Lookup.scala 33:37]
  wire [4:0] _T_504 = _T_95 ? 5'h0 : _T_503; // @[Lookup.scala 33:37]
  wire [4:0] _T_505 = _T_93 ? 5'h0 : _T_504; // @[Lookup.scala 33:37]
  wire [4:0] _T_506 = _T_91 ? 5'h0 : _T_505; // @[Lookup.scala 33:37]
  wire [4:0] _T_507 = _T_89 ? 5'h0 : _T_506; // @[Lookup.scala 33:37]
  wire [4:0] _T_508 = _T_87 ? 5'h0 : _T_507; // @[Lookup.scala 33:37]
  wire [4:0] _T_509 = _T_85 ? 5'h0 : _T_508; // @[Lookup.scala 33:37]
  wire [4:0] _T_510 = _T_83 ? 5'h0 : _T_509; // @[Lookup.scala 33:37]
  wire [4:0] _T_511 = _T_81 ? 5'h3 : _T_510; // @[Lookup.scala 33:37]
  wire [4:0] _T_512 = _T_79 ? 5'hc : _T_511; // @[Lookup.scala 33:37]
  wire [4:0] _T_513 = _T_77 ? 5'h2 : _T_512; // @[Lookup.scala 33:37]
  wire [4:0] _T_514 = _T_75 ? 5'h1 : _T_513; // @[Lookup.scala 33:37]
  wire [4:0] _T_515 = _T_73 ? 5'h0 : _T_514; // @[Lookup.scala 33:37]
  wire [4:0] _T_516 = _T_71 ? 5'hc : _T_515; // @[Lookup.scala 33:37]
  wire [4:0] _T_517 = _T_69 ? 5'h3 : _T_516; // @[Lookup.scala 33:37]
  wire [4:0] _T_518 = _T_67 ? 5'h2 : _T_517; // @[Lookup.scala 33:37]
  wire [4:0] _T_519 = _T_65 ? 5'h0 : _T_518; // @[Lookup.scala 33:37]
  wire [4:0] _T_520 = _T_63 ? 5'h3 : _T_519; // @[Lookup.scala 33:37]
  wire [4:0] _T_521 = _T_61 ? 5'h4 : _T_520; // @[Lookup.scala 33:37]
  wire [4:0] _T_522 = _T_59 ? 5'h7 : _T_521; // @[Lookup.scala 33:37]
  wire [4:0] _T_523 = _T_57 ? 5'h6 : _T_522; // @[Lookup.scala 33:37]
  wire [4:0] _T_524 = _T_55 ? 5'h5 : _T_523; // @[Lookup.scala 33:37]
  wire [4:0] _T_525 = _T_53 ? 5'h9 : _T_524; // @[Lookup.scala 33:37]
  wire [4:0] _T_526 = _T_51 ? 5'h8 : _T_525; // @[Lookup.scala 33:37]
  wire [4:0] _T_527 = _T_49 ? 5'h1 : _T_526; // @[Lookup.scala 33:37]
  wire [4:0] _T_528 = _T_47 ? 5'h0 : _T_527; // @[Lookup.scala 33:37]
  wire [4:0] _T_529 = _T_45 ? 5'h2 : _T_528; // @[Lookup.scala 33:37]
  wire [4:0] _T_530 = _T_43 ? 5'h3 : _T_529; // @[Lookup.scala 33:37]
  wire [4:0] _T_531 = _T_41 ? 5'h4 : _T_530; // @[Lookup.scala 33:37]
  wire [4:0] _T_532 = _T_39 ? 5'h2 : _T_531; // @[Lookup.scala 33:37]
  wire [4:0] _T_533 = _T_37 ? 5'h9 : _T_532; // @[Lookup.scala 33:37]
  wire [4:0] _T_534 = _T_35 ? 5'h8 : _T_533; // @[Lookup.scala 33:37]
  wire [4:0] _T_535 = _T_33 ? 5'h7 : _T_534; // @[Lookup.scala 33:37]
  wire [4:0] _T_536 = _T_31 ? 5'h6 : _T_535; // @[Lookup.scala 33:37]
  wire [4:0] _T_537 = _T_29 ? 5'h5 : _T_536; // @[Lookup.scala 33:37]
  wire [4:0] _T_538 = _T_27 ? 5'h0 : _T_537; // @[Lookup.scala 33:37]
  wire [4:0] _T_539 = _T_25 ? 5'hb : _T_538; // @[Lookup.scala 33:37]
  wire [4:0] _T_540 = _T_23 ? 5'h0 : _T_539; // @[Lookup.scala 33:37]
  wire [4:0] _T_541 = _T_21 ? 5'h0 : _T_540; // @[Lookup.scala 33:37]
  wire [4:0] _T_542 = _T_19 ? 5'h0 : _T_541; // @[Lookup.scala 33:37]
  wire [4:0] _T_543 = _T_17 ? 5'h0 : _T_542; // @[Lookup.scala 33:37]
  wire [4:0] _T_544 = _T_15 ? 5'h0 : _T_543; // @[Lookup.scala 33:37]
  wire [4:0] _T_545 = _T_13 ? 5'h0 : _T_544; // @[Lookup.scala 33:37]
  wire [4:0] _T_546 = _T_11 ? 5'h0 : _T_545; // @[Lookup.scala 33:37]
  wire [4:0] _T_547 = _T_9 ? 5'h0 : _T_546; // @[Lookup.scala 33:37]
  wire [4:0] _T_548 = _T_7 ? 5'h0 : _T_547; // @[Lookup.scala 33:37]
  wire [4:0] _T_549 = _T_5 ? 5'h0 : _T_548; // @[Lookup.scala 33:37]
  wire [4:0] _T_550 = _T_3 ? 5'h0 : _T_549; // @[Lookup.scala 33:37]
  wire [2:0] _T_562 = _T_101 ? 3'h4 : 3'h0; // @[Lookup.scala 33:37]
  wire [2:0] _T_563 = _T_99 ? 3'h0 : _T_562; // @[Lookup.scala 33:37]
  wire [2:0] _T_564 = _T_97 ? 3'h0 : _T_563; // @[Lookup.scala 33:37]
  wire [2:0] _T_565 = _T_95 ? 3'h0 : _T_564; // @[Lookup.scala 33:37]
  wire [2:0] _T_566 = _T_93 ? 3'h0 : _T_565; // @[Lookup.scala 33:37]
  wire [2:0] _T_567 = _T_91 ? 3'h0 : _T_566; // @[Lookup.scala 33:37]
  wire [2:0] _T_568 = _T_89 ? 3'h0 : _T_567; // @[Lookup.scala 33:37]
  wire [2:0] _T_569 = _T_87 ? 3'h0 : _T_568; // @[Lookup.scala 33:37]
  wire [2:0] _T_570 = _T_85 ? 3'h2 : _T_569; // @[Lookup.scala 33:37]
  wire [2:0] _T_571 = _T_83 ? 3'h2 : _T_570; // @[Lookup.scala 33:37]
  wire [2:0] _T_572 = _T_81 ? 3'h4 : _T_571; // @[Lookup.scala 33:37]
  wire [2:0] _T_573 = _T_79 ? 3'h4 : _T_572; // @[Lookup.scala 33:37]
  wire [2:0] _T_574 = _T_77 ? 3'h4 : _T_573; // @[Lookup.scala 33:37]
  wire [2:0] _T_575 = _T_75 ? 3'h4 : _T_574; // @[Lookup.scala 33:37]
  wire [2:0] _T_576 = _T_73 ? 3'h4 : _T_575; // @[Lookup.scala 33:37]
  wire [2:0] _T_577 = _T_71 ? 3'h4 : _T_576; // @[Lookup.scala 33:37]
  wire [2:0] _T_578 = _T_69 ? 3'h4 : _T_577; // @[Lookup.scala 33:37]
  wire [2:0] _T_579 = _T_67 ? 3'h4 : _T_578; // @[Lookup.scala 33:37]
  wire [2:0] _T_580 = _T_65 ? 3'h4 : _T_579; // @[Lookup.scala 33:37]
  wire [2:0] _T_581 = _T_63 ? 3'h0 : _T_580; // @[Lookup.scala 33:37]
  wire [2:0] _T_582 = _T_61 ? 3'h0 : _T_581; // @[Lookup.scala 33:37]
  wire [2:0] _T_583 = _T_59 ? 3'h0 : _T_582; // @[Lookup.scala 33:37]
  wire [2:0] _T_584 = _T_57 ? 3'h0 : _T_583; // @[Lookup.scala 33:37]
  wire [2:0] _T_585 = _T_55 ? 3'h0 : _T_584; // @[Lookup.scala 33:37]
  wire [2:0] _T_586 = _T_53 ? 3'h0 : _T_585; // @[Lookup.scala 33:37]
  wire [2:0] _T_587 = _T_51 ? 3'h0 : _T_586; // @[Lookup.scala 33:37]
  wire [2:0] _T_588 = _T_49 ? 3'h0 : _T_587; // @[Lookup.scala 33:37]
  wire [2:0] _T_589 = _T_47 ? 3'h0 : _T_588; // @[Lookup.scala 33:37]
  wire [2:0] _T_590 = _T_45 ? 3'h0 : _T_589; // @[Lookup.scala 33:37]
  wire [2:0] _T_591 = _T_43 ? 3'h0 : _T_590; // @[Lookup.scala 33:37]
  wire [2:0] _T_592 = _T_41 ? 3'h0 : _T_591; // @[Lookup.scala 33:37]
  wire [2:0] _T_593 = _T_39 ? 3'h0 : _T_592; // @[Lookup.scala 33:37]
  wire [2:0] _T_594 = _T_37 ? 3'h0 : _T_593; // @[Lookup.scala 33:37]
  wire [2:0] _T_595 = _T_35 ? 3'h0 : _T_594; // @[Lookup.scala 33:37]
  wire [2:0] _T_596 = _T_33 ? 3'h0 : _T_595; // @[Lookup.scala 33:37]
  wire [2:0] _T_597 = _T_31 ? 3'h0 : _T_596; // @[Lookup.scala 33:37]
  wire [2:0] _T_598 = _T_29 ? 3'h0 : _T_597; // @[Lookup.scala 33:37]
  wire [2:0] _T_599 = _T_27 ? 3'h0 : _T_598; // @[Lookup.scala 33:37]
  wire [2:0] _T_600 = _T_25 ? 3'h0 : _T_599; // @[Lookup.scala 33:37]
  wire [2:0] _T_601 = _T_23 ? 3'h0 : _T_600; // @[Lookup.scala 33:37]
  wire [2:0] _T_602 = _T_21 ? 3'h0 : _T_601; // @[Lookup.scala 33:37]
  wire [2:0] _T_603 = _T_19 ? 3'h0 : _T_602; // @[Lookup.scala 33:37]
  wire [2:0] _T_604 = _T_17 ? 3'h0 : _T_603; // @[Lookup.scala 33:37]
  wire [2:0] _T_605 = _T_15 ? 3'h0 : _T_604; // @[Lookup.scala 33:37]
  wire [2:0] _T_606 = _T_13 ? 3'h1 : _T_605; // @[Lookup.scala 33:37]
  wire [2:0] _T_607 = _T_11 ? 3'h1 : _T_606; // @[Lookup.scala 33:37]
  wire [2:0] _T_608 = _T_9 ? 3'h1 : _T_607; // @[Lookup.scala 33:37]
  wire [2:0] _T_609 = _T_7 ? 3'h1 : _T_608; // @[Lookup.scala 33:37]
  wire [2:0] _T_610 = _T_5 ? 3'h1 : _T_609; // @[Lookup.scala 33:37]
  wire [2:0] _T_611 = _T_3 ? 3'h1 : _T_610; // @[Lookup.scala 33:37]
  wire  _T_625 = _T_97 ? 1'h0 : _T_136; // @[Lookup.scala 33:37]
  wire  _T_626 = _T_95 ? 1'h0 : _T_625; // @[Lookup.scala 33:37]
  wire  _T_627 = _T_93 ? 1'h0 : _T_626; // @[Lookup.scala 33:37]
  wire  _T_628 = _T_91 ? 1'h0 : _T_627; // @[Lookup.scala 33:37]
  wire  _T_629 = _T_89 ? 1'h0 : _T_628; // @[Lookup.scala 33:37]
  wire  _T_630 = _T_87 ? 1'h0 : _T_629; // @[Lookup.scala 33:37]
  wire  _T_631 = _T_85 | _T_630; // @[Lookup.scala 33:37]
  wire  _T_632 = _T_83 | _T_631; // @[Lookup.scala 33:37]
  wire  _T_633 = _T_81 | _T_632; // @[Lookup.scala 33:37]
  wire  _T_634 = _T_79 | _T_633; // @[Lookup.scala 33:37]
  wire  _T_635 = _T_77 | _T_634; // @[Lookup.scala 33:37]
  wire  _T_636 = _T_75 | _T_635; // @[Lookup.scala 33:37]
  wire  _T_637 = _T_73 | _T_636; // @[Lookup.scala 33:37]
  wire  _T_638 = _T_71 | _T_637; // @[Lookup.scala 33:37]
  wire  _T_639 = _T_69 | _T_638; // @[Lookup.scala 33:37]
  wire  _T_640 = _T_67 | _T_639; // @[Lookup.scala 33:37]
  wire  _T_641 = _T_65 | _T_640; // @[Lookup.scala 33:37]
  wire  _T_642 = _T_63 | _T_641; // @[Lookup.scala 33:37]
  wire  _T_643 = _T_61 | _T_642; // @[Lookup.scala 33:37]
  wire  _T_644 = _T_59 | _T_643; // @[Lookup.scala 33:37]
  wire  _T_645 = _T_57 | _T_644; // @[Lookup.scala 33:37]
  wire  _T_646 = _T_55 | _T_645; // @[Lookup.scala 33:37]
  wire  _T_647 = _T_53 | _T_646; // @[Lookup.scala 33:37]
  wire  _T_648 = _T_51 | _T_647; // @[Lookup.scala 33:37]
  wire  _T_649 = _T_49 | _T_648; // @[Lookup.scala 33:37]
  wire  _T_650 = _T_47 | _T_649; // @[Lookup.scala 33:37]
  wire  _T_651 = _T_45 | _T_650; // @[Lookup.scala 33:37]
  wire  _T_652 = _T_43 | _T_651; // @[Lookup.scala 33:37]
  wire  _T_653 = _T_41 | _T_652; // @[Lookup.scala 33:37]
  wire  _T_654 = _T_39 | _T_653; // @[Lookup.scala 33:37]
  wire  _T_655 = _T_37 | _T_654; // @[Lookup.scala 33:37]
  wire  _T_656 = _T_35 | _T_655; // @[Lookup.scala 33:37]
  wire  _T_657 = _T_33 | _T_656; // @[Lookup.scala 33:37]
  wire  _T_658 = _T_31 | _T_657; // @[Lookup.scala 33:37]
  wire  _T_659 = _T_29 | _T_658; // @[Lookup.scala 33:37]
  wire  _T_660 = _T_27 | _T_659; // @[Lookup.scala 33:37]
  wire  _T_661 = _T_25 | _T_660; // @[Lookup.scala 33:37]
  wire  _T_662 = _T_23 | _T_661; // @[Lookup.scala 33:37]
  wire  _T_663 = _T_21 ? 1'h0 : _T_662; // @[Lookup.scala 33:37]
  wire  _T_664 = _T_19 ? 1'h0 : _T_663; // @[Lookup.scala 33:37]
  wire  _T_665 = _T_17 ? 1'h0 : _T_664; // @[Lookup.scala 33:37]
  wire  _T_666 = _T_15 ? 1'h0 : _T_665; // @[Lookup.scala 33:37]
  wire  _T_667 = _T_13 | _T_666; // @[Lookup.scala 33:37]
  wire  _T_668 = _T_11 | _T_667; // @[Lookup.scala 33:37]
  wire  _T_669 = _T_9 | _T_668; // @[Lookup.scala 33:37]
  wire  _T_670 = _T_7 | _T_669; // @[Lookup.scala 33:37]
  wire  _T_671 = _T_5 | _T_670; // @[Lookup.scala 33:37]
  wire  _T_672 = _T_3 | _T_671; // @[Lookup.scala 33:37]
  wire  _T_725 = _T_19 | _T_21; // @[Lookup.scala 33:37]
  wire  _T_726 = _T_17 | _T_725; // @[Lookup.scala 33:37]
  wire  _T_727 = _T_15 | _T_726; // @[Lookup.scala 33:37]
  wire  _T_728 = _T_13 | _T_727; // @[Lookup.scala 33:37]
  wire  _T_729 = _T_11 | _T_728; // @[Lookup.scala 33:37]
  wire  _T_730 = _T_9 | _T_729; // @[Lookup.scala 33:37]
  wire  _T_731 = _T_7 | _T_730; // @[Lookup.scala 33:37]
  wire  _T_732 = _T_5 | _T_731; // @[Lookup.scala 33:37]
  wire  _T_733 = _T_3 | _T_732; // @[Lookup.scala 33:37]
  wire  cs0_3 = _T_1 | _T_733; // @[Lookup.scala 33:37]
  wire [1:0] _T_785 = _T_21 ? 2'h2 : 2'h0; // @[Lookup.scala 33:37]
  wire [1:0] _T_786 = _T_19 ? 2'h2 : _T_785; // @[Lookup.scala 33:37]
  wire [1:0] _T_787 = _T_17 ? 2'h2 : _T_786; // @[Lookup.scala 33:37]
  wire [1:0] _T_788 = _T_15 ? 2'h2 : _T_787; // @[Lookup.scala 33:37]
  wire [1:0] _T_789 = _T_13 ? 2'h1 : _T_788; // @[Lookup.scala 33:37]
  wire [1:0] _T_790 = _T_11 ? 2'h1 : _T_789; // @[Lookup.scala 33:37]
  wire [1:0] _T_791 = _T_9 ? 2'h1 : _T_790; // @[Lookup.scala 33:37]
  wire [1:0] _T_792 = _T_7 ? 2'h1 : _T_791; // @[Lookup.scala 33:37]
  wire [1:0] _T_793 = _T_5 ? 2'h1 : _T_792; // @[Lookup.scala 33:37]
  wire [1:0] _T_794 = _T_3 ? 2'h1 : _T_793; // @[Lookup.scala 33:37]
  wire [1:0] cs0_4 = _T_1 ? 2'h1 : _T_794; // @[Lookup.scala 33:37]
  wire [7:0] _T_846 = _T_21 ? 8'h3 : 8'hff; // @[Lookup.scala 33:37]
  wire [7:0] _T_847 = _T_19 ? 8'h1 : _T_846; // @[Lookup.scala 33:37]
  wire [7:0] _T_848 = _T_17 ? 8'hf : _T_847; // @[Lookup.scala 33:37]
  wire [7:0] _T_849 = _T_15 ? 8'hff : _T_848; // @[Lookup.scala 33:37]
  wire [7:0] _T_850 = _T_13 ? 8'hff : _T_849; // @[Lookup.scala 33:37]
  wire [7:0] _T_851 = _T_11 ? 8'hff : _T_850; // @[Lookup.scala 33:37]
  wire [7:0] _T_852 = _T_9 ? 8'hff : _T_851; // @[Lookup.scala 33:37]
  wire [7:0] _T_853 = _T_7 ? 8'hff : _T_852; // @[Lookup.scala 33:37]
  wire [7:0] _T_854 = _T_5 ? 8'hff : _T_853; // @[Lookup.scala 33:37]
  wire [7:0] _T_855 = _T_3 ? 8'hff : _T_854; // @[Lookup.scala 33:37]
  wire [2:0] _T_911 = _T_13 ? 3'h3 : 3'h0; // @[Lookup.scala 33:37]
  wire [2:0] _T_912 = _T_11 ? 3'h2 : _T_911; // @[Lookup.scala 33:37]
  wire [2:0] _T_913 = _T_9 ? 3'h1 : _T_912; // @[Lookup.scala 33:37]
  wire [2:0] _T_914 = _T_7 ? 3'h0 : _T_913; // @[Lookup.scala 33:37]
  wire [2:0] _T_915 = _T_5 ? 3'h5 : _T_914; // @[Lookup.scala 33:37]
  wire [2:0] _T_916 = _T_3 ? 3'h4 : _T_915; // @[Lookup.scala 33:37]
  wire  _T_1039 = io_dat_exe_br_type == 4'h0; // @[cpath.scala 118:48]
  wire  _T_1040 = io_dat_exe_br_type == 4'h1; // @[cpath.scala 119:48]
  wire  _T_1041 = ~io_dat_exe_br_eq; // @[cpath.scala 119:64]
  wire [1:0] _T_1042 = _T_1041 ? 2'h1 : 2'h0; // @[cpath.scala 119:63]
  wire  _T_1043 = io_dat_exe_br_type == 4'h2; // @[cpath.scala 120:48]
  wire [1:0] _T_1044 = io_dat_exe_br_eq ? 2'h1 : 2'h0; // @[cpath.scala 120:63]
  wire  _T_1045 = io_dat_exe_br_type == 4'h3; // @[cpath.scala 121:48]
  wire  _T_1046 = ~io_dat_exe_br_lt; // @[cpath.scala 121:64]
  wire [1:0] _T_1047 = _T_1046 ? 2'h1 : 2'h0; // @[cpath.scala 121:63]
  wire  _T_1048 = io_dat_exe_br_type == 4'h4; // @[cpath.scala 122:48]
  wire  _T_1049 = ~io_dat_exe_br_ltu; // @[cpath.scala 122:64]
  wire [1:0] _T_1050 = _T_1049 ? 2'h1 : 2'h0; // @[cpath.scala 122:63]
  wire  _T_1051 = io_dat_exe_br_type == 4'h5; // @[cpath.scala 123:48]
  wire [1:0] _T_1052 = io_dat_exe_br_lt ? 2'h1 : 2'h0; // @[cpath.scala 123:63]
  wire  _T_1053 = io_dat_exe_br_type == 4'h6; // @[cpath.scala 124:48]
  wire [1:0] _T_1054 = io_dat_exe_br_ltu ? 2'h1 : 2'h0; // @[cpath.scala 124:63]
  wire  _T_1055 = io_dat_exe_br_type == 4'h7; // @[cpath.scala 125:48]
  wire  _T_1056 = io_dat_exe_br_type == 4'h8; // @[cpath.scala 126:48]
  wire [1:0] _T_1057 = _T_1056 ? 2'h2 : 2'h0; // @[cpath.scala 126:28]
  wire [1:0] _T_1058 = _T_1055 ? 2'h1 : _T_1057; // @[cpath.scala 125:28]
  wire [1:0] _T_1059 = _T_1053 ? _T_1054 : _T_1058; // @[cpath.scala 124:28]
  wire [1:0] _T_1060 = _T_1051 ? _T_1052 : _T_1059; // @[cpath.scala 123:28]
  wire [1:0] _T_1061 = _T_1048 ? _T_1050 : _T_1060; // @[cpath.scala 122:28]
  wire [1:0] _T_1062 = _T_1045 ? _T_1047 : _T_1061; // @[cpath.scala 121:28]
  wire [1:0] _T_1063 = _T_1043 ? _T_1044 : _T_1062; // @[cpath.scala 120:28]
  wire [1:0] _T_1064 = _T_1040 ? _T_1042 : _T_1063; // @[cpath.scala 119:28]
  wire [1:0] ctrl_exe_pc_sel = _T_1039 ? 2'h0 : _T_1064; // @[cpath.scala 118:28]
  wire  ifkill = ctrl_exe_pc_sel != 2'h0; // @[cpath.scala 130:34]
  wire [4:0] dec_rs1_addr = io_dat_dec_inst[19:15]; // @[cpath.scala 135:37]
  wire [4:0] dec_rs2_addr = io_dat_dec_inst[24:20]; // @[cpath.scala 136:37]
  wire [4:0] dec_wbaddr = io_dat_dec_inst[11:7]; // @[cpath.scala 137:37]
  wire  dec_rs1_oen = ifkill ? 1'h0 : cs_rs1_oen; // @[cpath.scala 138:25]
  wire  dec_rs2_oen = ifkill ? 1'h0 : cs_rs2_oen; // @[cpath.scala 139:25]
  reg [4:0] exe_reg_wbaddr; // @[cpath.scala 141:32]
  reg  exe_inst_is_load; // @[cpath.scala 178:33]
  wire  _T_1069 = exe_reg_wbaddr == dec_rs1_addr; // @[cpath.scala 187:51]
  wire  _T_1070 = exe_inst_is_load & _T_1069; // @[cpath.scala 187:32]
  wire  _T_1071 = exe_reg_wbaddr != 5'h0; // @[cpath.scala 187:88]
  wire  _T_1072 = _T_1070 & _T_1071; // @[cpath.scala 187:69]
  wire  _T_1073 = _T_1072 & dec_rs1_oen; // @[cpath.scala 187:97]
  wire  _T_1074 = exe_reg_wbaddr == dec_rs2_addr; // @[cpath.scala 188:51]
  wire  _T_1075 = exe_inst_is_load & _T_1074; // @[cpath.scala 188:32]
  wire  _T_1077 = _T_1075 & _T_1071; // @[cpath.scala 188:69]
  wire  _T_1078 = _T_1077 & dec_rs2_oen; // @[cpath.scala 188:97]
  wire  stall = _T_1073 | _T_1078; // @[cpath.scala 187:113]
  wire  _T_1066 = ~stall; // @[cpath.scala 153:9]
  wire  _T_1067 = cs0_4 == 2'h1; // @[cpath.scala 181:48]
  wire  _T_1068 = cs0_3 & _T_1067; // @[cpath.scala 181:33]
  wire  _T_1086 = ~reset; // @[cpath.scala 211:9]
  assign io_ctl_dec_stall = _T_1073 | _T_1078; // @[cpath.scala 191:21]
  assign io_ctl_exe_pc_sel = _T_1039 ? 2'h0 : _T_1064; // @[cpath.scala 192:22]
  assign io_ctl_br_type = _T_1 ? 4'h0 : _T_245; // @[cpath.scala 193:22]
  assign io_ctl_if_kill = ctrl_exe_pc_sel != 2'h0; // @[cpath.scala 194:22]
  assign io_ctl_dec_kill = ctrl_exe_pc_sel != 2'h0; // @[cpath.scala 195:22]
  assign io_ctl_op1_sel = _T_1 ? 2'h0 : _T_306; // @[cpath.scala 196:22]
  assign io_ctl_op2_sel = _T_1 ? 3'h1 : _T_367; // @[cpath.scala 197:22]
  assign io_ctl_alu_fun = _T_1 ? 5'h0 : _T_550; // @[cpath.scala 198:22]
  assign io_ctl_wb_sel = _T_1 ? 3'h1 : _T_611; // @[cpath.scala 199:22]
  assign io_ctl_rf_wen = _T_1 | _T_672; // @[cpath.scala 200:22]
  assign io_ctl_mem_fcn = _T_1 ? 2'h1 : _T_794; // @[cpath.scala 203:22]
  assign io_ctl_mem_typ = _T_1 ? 8'hff : _T_855; // @[cpath.scala 204:22]
  assign io_ctl_mem_ext = _T_1 ? 3'h6 : _T_916; // @[cpath.scala 205:22]
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
  exe_reg_wbaddr = _RAND_0[4:0];
  _RAND_1 = {1{`RANDOM}};
  exe_inst_is_load = _RAND_1[0:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
  always @(posedge clock) begin
    if (_T_1066) begin
      if (ifkill) begin
        exe_reg_wbaddr <= 5'h0;
      end else begin
        exe_reg_wbaddr <= dec_wbaddr;
      end
    end else if (stall) begin
      exe_reg_wbaddr <= 5'h0;
    end
    if (reset) begin
      exe_inst_is_load <= 1'h0;
    end else begin
      exe_inst_is_load <= _T_1068;
    end
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_1086) begin
          $fwrite(32'h80000002,"CTRL : inst = %x, ifkill = %d, deckill = %d, stall = %d\n",io_dat_dec_inst,ifkill,ifkill,stall); // @[cpath.scala 211:9]
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
  wire  _T_41 = io_op == 5'he; // @[alu.scala 34:9]
  wire  _T_42 = io_src2 == 64'h0; // @[alu.scala 34:33]
  wire [64:0] _T_46 = $signed(io_src1) / $signed(io_src2); // @[alu.scala 34:83]
  wire [64:0] _T_47 = _T_42 ? 65'h0 : _T_46; // @[alu.scala 34:27]
  wire  _T_48 = io_op == 5'hf; // @[alu.scala 35:9]
  wire [31:0] _T_53 = io_src2[31:0]; // @[alu.scala 35:86]
  wire [31:0] _T_55 = $signed(_T_34) % $signed(_T_53); // @[alu.scala 35:96]
  wire [31:0] _T_56 = _T_42 ? 32'h0 : _T_55; // @[alu.scala 35:28]
  wire  _T_57 = io_op == 5'h10; // @[alu.scala 36:9]
  wire [31:0] _GEN_2 = io_src1[31:0] % io_src2[31:0]; // @[alu.scala 36:59]
  wire [31:0] _T_61 = _GEN_2[31:0]; // @[alu.scala 36:59]
  wire [31:0] _T_62 = _T_42 ? 32'h0 : _T_61; // @[alu.scala 36:29]
  wire  _T_63 = io_op == 5'h11; // @[alu.scala 37:9]
  wire [31:0] _T_67 = io_src1[31:0] / io_src2[31:0]; // @[alu.scala 37:59]
  wire [31:0] _T_68 = _T_42 ? 32'h0 : _T_67; // @[alu.scala 37:29]
  wire  _T_69 = io_op == 5'h12; // @[alu.scala 38:9]
  wire [127:0] _T_72 = $signed(io_src1) * $signed(io_src2); // @[alu.scala 38:41]
  wire  _T_74 = io_op == 5'h13; // @[alu.scala 39:9]
  wire [64:0] _T_76 = {1'b0,$signed(io_src2)}; // @[alu.scala 39:43]
  wire [64:0] _GEN_1 = {{1{_T_13[63]}},_T_13}; // @[alu.scala 39:43]
  wire [128:0] _T_77 = $signed(_GEN_1) * $signed(_T_76); // @[alu.scala 39:43]
  wire [127:0] _T_79 = _T_77[127:0]; // @[alu.scala 39:43]
  wire  _T_81 = io_op == 5'h14; // @[alu.scala 40:9]
  wire  _T_84 = io_op == 5'h15; // @[alu.scala 41:9]
  wire [63:0] _T_86 = io_src1 / io_src2; // @[alu.scala 41:53]
  wire [63:0] _T_87 = _T_42 ? 64'h0 : _T_86; // @[alu.scala 41:29]
  wire  _T_88 = io_op == 5'h16; // @[alu.scala 42:9]
  wire [32:0] _T_95 = $signed(_T_34) / $signed(_T_53); // @[alu.scala 42:97]
  wire [32:0] _T_96 = _T_42 ? 33'h0 : _T_95; // @[alu.scala 42:29]
  wire  _T_97 = io_op == 5'h17; // @[alu.scala 43:9]
  wire [63:0] _T_102 = $signed(io_src1) % $signed(io_src2); // @[alu.scala 43:84]
  wire [63:0] _T_103 = _T_42 ? 64'h0 : _T_102; // @[alu.scala 43:28]
  wire  _T_104 = io_op == 5'h18; // @[alu.scala 44:9]
  wire [63:0] _GEN_3 = io_src1 % io_src2; // @[alu.scala 44:53]
  wire [63:0] _T_106 = _GEN_3[63:0]; // @[alu.scala 44:53]
  wire [63:0] _T_107 = _T_42 ? 64'h0 : _T_106; // @[alu.scala 44:29]
  wire [63:0] _T_108 = _T_104 ? _T_107 : 64'h0; // @[Mux.scala 98:16]
  wire [63:0] _T_109 = _T_97 ? _T_103 : _T_108; // @[Mux.scala 98:16]
  wire [63:0] _T_110 = _T_88 ? {{31'd0}, _T_96} : _T_109; // @[Mux.scala 98:16]
  wire [63:0] _T_111 = _T_84 ? _T_87 : _T_110; // @[Mux.scala 98:16]
  wire [63:0] _T_112 = _T_81 ? _T_39[127:64] : _T_111; // @[Mux.scala 98:16]
  wire [63:0] _T_113 = _T_74 ? _T_79[127:64] : _T_112; // @[Mux.scala 98:16]
  wire [63:0] _T_114 = _T_69 ? _T_72[127:64] : _T_113; // @[Mux.scala 98:16]
  wire [63:0] _T_115 = _T_63 ? {{32'd0}, _T_68} : _T_114; // @[Mux.scala 98:16]
  wire [63:0] _T_116 = _T_57 ? {{32'd0}, _T_62} : _T_115; // @[Mux.scala 98:16]
  wire [63:0] _T_117 = _T_48 ? {{32'd0}, _T_56} : _T_116; // @[Mux.scala 98:16]
  wire [64:0] _T_118 = _T_41 ? _T_47 : {{1'd0}, _T_117}; // @[Mux.scala 98:16]
  wire [64:0] _T_119 = _T_38 ? {{1'd0}, _T_39[63:0]} : _T_118; // @[Mux.scala 98:16]
  wire [64:0] _T_120 = _T_29 ? {{1'd0}, _T_37} : _T_119; // @[Mux.scala 98:16]
  wire [64:0] _T_121 = _T_28 ? {{1'd0}, io_src2} : _T_120; // @[Mux.scala 98:16]
  wire [64:0] _T_122 = _T_27 ? {{1'd0}, io_src1} : _T_121; // @[Mux.scala 98:16]
  wire [64:0] _T_123 = _T_25 ? {{1'd0}, _T_26} : _T_122; // @[Mux.scala 98:16]
  wire [64:0] _T_124 = _T_21 ? {{1'd0}, _T_24} : _T_123; // @[Mux.scala 98:16]
  wire [64:0] _T_125 = _T_18 ? {{1'd0}, _T_19[63:0]} : _T_124; // @[Mux.scala 98:16]
  wire [64:0] _T_126 = _T_16 ? {{64'd0}, _T_17} : _T_125; // @[Mux.scala 98:16]
  wire [64:0] _T_127 = _T_12 ? {{64'd0}, _T_15} : _T_126; // @[Mux.scala 98:16]
  wire [64:0] _T_128 = _T_10 ? {{1'd0}, _T_11} : _T_127; // @[Mux.scala 98:16]
  wire [64:0] _T_129 = _T_8 ? {{1'd0}, _T_9} : _T_128; // @[Mux.scala 98:16]
  wire [64:0] _T_130 = _T_6 ? {{1'd0}, _T_7} : _T_129; // @[Mux.scala 98:16]
  wire [64:0] _T_131 = _T_3 ? {{1'd0}, _T_5} : _T_130; // @[Mux.scala 98:16]
  wire [64:0] _T_132 = _T ? {{1'd0}, _T_2} : _T_131; // @[Mux.scala 98:16]
  wire  _T_134 = ~reset; // @[alu.scala 47:9]
  assign io_res = _T_132[63:0]; // @[alu.scala 19:10]
  always @(posedge clock) begin
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_134) begin
          $fwrite(32'h80000002,"ALU: op = %d, src1=[%x] src2=[%x] result=[%x]\n",io_op,io_src1,io_src2,io_res); // @[alu.scala 47:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
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
  input  [2:0]  io_ctl_mem_ext,
  output [63:0] io_dat_dec_inst,
  output        io_dat_exe_br_eq,
  output        io_dat_exe_br_lt,
  output        io_dat_exe_br_ltu,
  output [3:0]  io_dat_exe_br_type,
  output [63:0] io_inst_readIO_addr,
  input  [63:0] io_inst_readIO_data,
  output        io_inst_readIO_en,
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
  reg [31:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [63:0] _RAND_10;
  reg [63:0] _RAND_11;
  reg [63:0] _RAND_12;
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
  reg [63:0] _RAND_23;
  reg [31:0] _RAND_24;
  reg [31:0] _RAND_25;
  reg [31:0] _RAND_26;
  reg [63:0] _RAND_27;
  reg [63:0] _RAND_28;
  reg [31:0] _RAND_29;
  reg [31:0] _RAND_30;
  reg [31:0] _RAND_31;
  reg [63:0] _RAND_32;
  reg [31:0] _RAND_33;
  reg [63:0] _RAND_34;
  reg [63:0] _RAND_35;
  reg [31:0] _RAND_36;
  reg [63:0] _RAND_37;
  reg [31:0] _RAND_38;
  reg [63:0] _RAND_39;
  reg [31:0] _RAND_40;
  reg [63:0] _RAND_41;
  reg [31:0] _RAND_42;
  reg [63:0] _RAND_43;
`endif // RANDOMIZE_REG_INIT
  wire  regfile_clock; // @[dpath.scala 143:23]
  wire  regfile_reset; // @[dpath.scala 143:23]
  wire [4:0] regfile_io_rs1_addr; // @[dpath.scala 143:23]
  wire [63:0] regfile_io_rs1_data; // @[dpath.scala 143:23]
  wire [4:0] regfile_io_rs2_addr; // @[dpath.scala 143:23]
  wire [63:0] regfile_io_rs2_data; // @[dpath.scala 143:23]
  wire [4:0] regfile_io_waddr; // @[dpath.scala 143:23]
  wire [63:0] regfile_io_wdata; // @[dpath.scala 143:23]
  wire  regfile_io_wen; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_0; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_1; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_2; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_3; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_4; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_5; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_6; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_7; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_8; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_9; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_10; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_11; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_12; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_13; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_14; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_15; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_16; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_17; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_18; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_19; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_20; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_21; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_22; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_23; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_24; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_25; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_26; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_27; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_28; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_29; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_30; // @[dpath.scala 143:23]
  wire [63:0] regfile__T_42_0_31; // @[dpath.scala 143:23]
  wire  alu_clock; // @[dpath.scala 275:19]
  wire  alu_reset; // @[dpath.scala 275:19]
  wire [63:0] alu_io_src1; // @[dpath.scala 275:19]
  wire [63:0] alu_io_src2; // @[dpath.scala 275:19]
  wire [4:0] alu_io_op; // @[dpath.scala 275:19]
  wire [63:0] alu_io_res; // @[dpath.scala 275:19]
  reg [63:0] if_reg_pc; // @[dpath.scala 34:26]
  reg  dec_reg_valid; // @[dpath.scala 37:30]
  reg [63:0] dec_reg_inst; // @[dpath.scala 38:29]
  reg [63:0] dec_reg_pc; // @[dpath.scala 39:27]
  reg  exe_reg_valid; // @[dpath.scala 41:30]
  reg [63:0] exe_reg_inst; // @[dpath.scala 42:29]
  reg [63:0] exe_reg_pc; // @[dpath.scala 43:27]
  reg [4:0] exe_reg_wbaddr; // @[dpath.scala 44:27]
  reg [4:0] exe_reg_rs1_addr; // @[dpath.scala 45:29]
  reg [4:0] exe_reg_rs2_addr; // @[dpath.scala 46:29]
  reg [63:0] exe_alu_op1; // @[dpath.scala 47:29]
  reg [63:0] brjmp_offset; // @[dpath.scala 48:29]
  reg [63:0] exe_reg_rs2_data; // @[dpath.scala 49:29]
  reg [3:0] exe_reg_ctrl_br_type; // @[dpath.scala 50:38]
  reg [4:0] exe_reg_ctrl_alu_fun; // @[dpath.scala 52:33]
  reg [2:0] exe_reg_ctrl_wb_sel; // @[dpath.scala 53:32]
  reg  exe_reg_ctrl_rf_wen; // @[dpath.scala 54:36]
  reg [1:0] exe_reg_ctrl_mem_fcn; // @[dpath.scala 56:38]
  reg [7:0] exe_reg_ctrl_mem_typ; // @[dpath.scala 57:38]
  reg [2:0] exe_reg_ctrl_mem_ext; // @[dpath.scala 58:37]
  reg  mem_reg_valid; // @[dpath.scala 62:30]
  reg [63:0] mem_reg_pc; // @[dpath.scala 63:23]
  reg [63:0] mem_reg_inst; // @[dpath.scala 64:25]
  reg [63:0] mem_reg_alu_out; // @[dpath.scala 65:28]
  reg [4:0] mem_reg_wbaddr; // @[dpath.scala 66:27]
  reg [4:0] mem_reg_rs1_addr; // @[dpath.scala 67:29]
  reg [4:0] mem_reg_rs2_addr; // @[dpath.scala 68:29]
  reg [63:0] mem_reg_op1_data; // @[dpath.scala 69:29]
  reg [63:0] mem_reg_op2_data; // @[dpath.scala 70:29]
  reg  mem_reg_ctrl_rf_wen; // @[dpath.scala 72:36]
  reg [2:0] mem_reg_ctrl_wb_sel; // @[dpath.scala 76:32]
  reg [2:0] mem_reg_ctrl_mem_ext; // @[dpath.scala 77:37]
  reg [63:0] mem_reg_dram_data; // @[dpath.scala 79:34]
  reg  wb_reg_valid; // @[dpath.scala 82:29]
  reg [63:0] wb_reg_pc; // @[dpath.scala 83:22]
  reg [63:0] wb_reg_inst; // @[dpath.scala 84:24]
  reg [4:0] wb_reg_wbaddr; // @[dpath.scala 85:26]
  reg [63:0] wb_reg_wbdata; // @[dpath.scala 86:26]
  reg  wb_reg_ctrl_rf_wen; // @[dpath.scala 87:35]
  wire  _T = ~io_ctl_dec_stall; // @[dpath.scala 97:9]
  wire  _T_2 = io_ctl_exe_pc_sel == 2'h0; // @[dpath.scala 104:39]
  wire [63:0] if_pc_plus4 = if_reg_pc + 64'h4; // @[dpath.scala 102:31]
  wire  _T_3 = io_ctl_exe_pc_sel == 2'h1; // @[dpath.scala 105:39]
  wire [63:0] exe_brjmp_target = exe_reg_pc + brjmp_offset; // @[dpath.scala 286:37]
  wire  _T_4 = io_ctl_exe_pc_sel == 2'h2; // @[dpath.scala 106:39]
  wire [63:0] exe_adder_out = exe_alu_op1 + brjmp_offset; // @[dpath.scala 283:36]
  wire [63:0] _T_5 = _T_4 ? exe_adder_out : 64'h4033; // @[dpath.scala 106:20]
  wire [63:0] _T_6 = _T_3 ? exe_brjmp_target : _T_5; // @[dpath.scala 105:20]
  wire [63:0] if_pc_next = _T_2 ? if_pc_plus4 : _T_6; // @[dpath.scala 104:20]
  wire  _T_10 = ~reset; // @[dpath.scala 131:9]
  wire [4:0] dec_rs1_addr = dec_reg_inst[19:15]; // @[dpath.scala 137:34]
  wire [4:0] dec_rs2_addr = dec_reg_inst[24:20]; // @[dpath.scala 138:34]
  wire [4:0] dec_wbaddr = dec_reg_inst[11:7]; // @[dpath.scala 139:32]
  wire [11:0] imm_itype = dec_reg_inst[31:20]; // @[dpath.scala 154:31]
  wire [11:0] imm_stype = {dec_reg_inst[31:25],dec_wbaddr}; // @[Cat.scala 29:58]
  wire [11:0] imm_sbtype = {dec_reg_inst[31],dec_reg_inst[7],dec_reg_inst[30:25],dec_reg_inst[11:8]}; // @[Cat.scala 29:58]
  wire [19:0] imm_utype = dec_reg_inst[31:12]; // @[dpath.scala 157:31]
  wire [19:0] imm_ujtype = {dec_reg_inst[31],dec_reg_inst[19:12],dec_reg_inst[20],dec_reg_inst[30:21]}; // @[Cat.scala 29:58]
  wire [31:0] imm_z = {27'h0,dec_rs1_addr}; // @[Cat.scala 29:58]
  wire [51:0] _T_29 = imm_itype[11] ? 52'hfffffffffffff : 52'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_itype_sext = {_T_29,imm_itype}; // @[Cat.scala 29:58]
  wire [51:0] _T_32 = imm_stype[11] ? 52'hfffffffffffff : 52'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_stype_sext = {_T_32,dec_reg_inst[31:25],dec_wbaddr}; // @[Cat.scala 29:58]
  wire [50:0] _T_35 = imm_sbtype[11] ? 51'h7ffffffffffff : 51'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_sbtype_sext = {_T_35,dec_reg_inst[31],dec_reg_inst[7],dec_reg_inst[30:25],dec_reg_inst[11:8],1'h0}; // @[Cat.scala 29:58]
  wire [31:0] _T_39 = imm_utype[19] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_utype_sext = {_T_39,imm_utype,12'h0}; // @[Cat.scala 29:58]
  wire [42:0] _T_44 = imm_ujtype[19] ? 43'h7ffffffffff : 43'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_ujtype_sext = {_T_44,dec_reg_inst[31],dec_reg_inst[19:12],dec_reg_inst[20],dec_reg_inst[30:21],1'h0}; // @[Cat.scala 29:58]
  wire  _T_46 = io_ctl_op2_sel == 3'h0; // @[dpath.scala 170:21]
  wire  _T_47 = io_ctl_op2_sel == 3'h1; // @[dpath.scala 171:21]
  wire  _T_48 = io_ctl_op2_sel == 3'h2; // @[dpath.scala 172:21]
  wire  _T_49 = io_ctl_op2_sel == 3'h3; // @[dpath.scala 173:21]
  wire  _T_50 = io_ctl_op2_sel == 3'h4; // @[dpath.scala 174:21]
  wire  _T_51 = io_ctl_op2_sel == 3'h5; // @[dpath.scala 175:21]
  wire [63:0] _T_52 = _T_51 ? imm_ujtype_sext : 64'h0; // @[Mux.scala 98:16]
  wire [63:0] _T_53 = _T_50 ? imm_utype_sext : _T_52; // @[Mux.scala 98:16]
  wire [63:0] _T_54 = _T_49 ? imm_sbtype_sext : _T_53; // @[Mux.scala 98:16]
  wire [63:0] _T_55 = _T_48 ? imm_stype_sext : _T_54; // @[Mux.scala 98:16]
  wire [63:0] _T_56 = _T_47 ? imm_itype_sext : _T_55; // @[Mux.scala 98:16]
  wire [63:0] dec_alu_op2 = _T_46 ? regfile_io_rs2_data : _T_56; // @[Mux.scala 98:16]
  wire  _T_57 = exe_reg_wbaddr == dec_rs1_addr; // @[dpath.scala 188:22]
  wire  _T_58 = dec_rs1_addr != 5'h0; // @[dpath.scala 188:57]
  wire  _T_59 = _T_57 & _T_58; // @[dpath.scala 188:40]
  wire  _T_60 = _T_59 & exe_reg_ctrl_rf_wen; // @[dpath.scala 188:66]
  wire  _T_61 = mem_reg_wbaddr == dec_rs1_addr; // @[dpath.scala 189:22]
  wire  _T_63 = _T_61 & _T_58; // @[dpath.scala 189:40]
  wire  _T_64 = _T_63 & mem_reg_ctrl_rf_wen; // @[dpath.scala 189:66]
  wire  _T_65 = wb_reg_wbaddr == dec_rs1_addr; // @[dpath.scala 190:21]
  wire  _T_67 = _T_65 & _T_58; // @[dpath.scala 190:39]
  wire  _T_68 = _T_67 & wb_reg_ctrl_rf_wen; // @[dpath.scala 190:65]
  wire [63:0] _T_69 = _T_68 ? wb_reg_wbdata : regfile_io_rs1_data; // @[Mux.scala 98:16]
  wire  _T_177 = mem_reg_ctrl_wb_sel == 3'h1; // @[dpath.scala 336:26]
  wire  _T_140 = mem_reg_ctrl_mem_ext == 3'h0; // @[dpath.scala 325:27]
  wire [55:0] _T_143 = mem_reg_dram_data[7] ? 56'hffffffffffffff : 56'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _T_145 = {_T_143,mem_reg_dram_data[7:0]}; // @[Cat.scala 29:58]
  wire  _T_146 = mem_reg_ctrl_mem_ext == 3'h1; // @[dpath.scala 326:27]
  wire [63:0] _T_149 = {56'h0,mem_reg_dram_data[7:0]}; // @[Cat.scala 29:58]
  wire  _T_150 = mem_reg_ctrl_mem_ext == 3'h2; // @[dpath.scala 327:27]
  wire [47:0] _T_153 = mem_reg_dram_data[15] ? 48'hffffffffffff : 48'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _T_155 = {_T_153,mem_reg_dram_data[15:0]}; // @[Cat.scala 29:58]
  wire  _T_156 = mem_reg_ctrl_mem_ext == 3'h3; // @[dpath.scala 328:27]
  wire [63:0] _T_159 = {48'h0,mem_reg_dram_data[15:0]}; // @[Cat.scala 29:58]
  wire  _T_160 = mem_reg_ctrl_mem_ext == 3'h4; // @[dpath.scala 329:27]
  wire [31:0] _T_163 = mem_reg_dram_data[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _T_165 = {_T_163,mem_reg_dram_data[31:0]}; // @[Cat.scala 29:58]
  wire  _T_166 = mem_reg_ctrl_mem_ext == 3'h5; // @[dpath.scala 330:27]
  wire [63:0] _T_169 = {32'h0,mem_reg_dram_data[31:0]}; // @[Cat.scala 29:58]
  wire [63:0] _T_172 = _T_166 ? _T_169 : mem_reg_dram_data; // @[Mux.scala 98:16]
  wire [63:0] _T_173 = _T_160 ? _T_165 : _T_172; // @[Mux.scala 98:16]
  wire [63:0] _T_174 = _T_156 ? _T_159 : _T_173; // @[Mux.scala 98:16]
  wire [63:0] _T_175 = _T_150 ? _T_155 : _T_174; // @[Mux.scala 98:16]
  wire [63:0] _T_176 = _T_146 ? _T_149 : _T_175; // @[Mux.scala 98:16]
  wire [63:0] mem_data = _T_140 ? _T_145 : _T_176; // @[Mux.scala 98:16]
  wire [63:0] mem_wbdata = _T_177 ? mem_data : mem_reg_alu_out; // @[Mux.scala 98:16]
  wire [63:0] _T_70 = _T_64 ? mem_wbdata : _T_69; // @[Mux.scala 98:16]
  wire  _T_120 = exe_reg_ctrl_wb_sel == 3'h4; // @[dpath.scala 280:28]
  wire [31:0] _T_123 = alu_io_res[31] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] _T_125 = {_T_123,alu_io_res[31:0]}; // @[Cat.scala 29:58]
  wire [63:0] exe_alu_out = _T_120 ? _T_125 : alu_io_res; // @[Mux.scala 98:16]
  wire [63:0] dec_rs1_data = _T_60 ? exe_alu_out : _T_70; // @[Mux.scala 98:16]
  wire  _T_72 = io_ctl_op1_sel == 2'h2; // @[dpath.scala 194:21]
  wire  _T_73 = io_ctl_op1_sel == 2'h1; // @[dpath.scala 195:21]
  wire  _T_74 = io_ctl_op1_sel == 2'h3; // @[dpath.scala 196:21]
  wire [63:0] _T_77 = {32'h0,dec_rs1_data[31:0]}; // @[Cat.scala 29:58]
  wire [63:0] _T_78 = _T_74 ? _T_77 : dec_rs1_data; // @[Mux.scala 98:16]
  wire [63:0] _T_79 = _T_73 ? dec_reg_pc : _T_78; // @[Mux.scala 98:16]
  wire [63:0] dec_op1_data = _T_72 ? {{32'd0}, imm_z} : _T_79; // @[Mux.scala 98:16]
  wire  _T_81 = exe_reg_wbaddr == dec_rs2_addr; // @[dpath.scala 200:22]
  wire  _T_82 = dec_rs2_addr != 5'h0; // @[dpath.scala 200:57]
  wire  _T_83 = _T_81 & _T_82; // @[dpath.scala 200:40]
  wire  _T_84 = _T_83 & exe_reg_ctrl_rf_wen; // @[dpath.scala 200:66]
  wire  _T_86 = _T_84 & _T_46; // @[dpath.scala 200:89]
  wire  _T_87 = mem_reg_wbaddr == dec_rs2_addr; // @[dpath.scala 201:22]
  wire  _T_89 = _T_87 & _T_82; // @[dpath.scala 201:40]
  wire  _T_90 = _T_89 & mem_reg_ctrl_rf_wen; // @[dpath.scala 201:66]
  wire  _T_92 = _T_90 & _T_46; // @[dpath.scala 201:89]
  wire  _T_93 = wb_reg_wbaddr == dec_rs2_addr; // @[dpath.scala 202:21]
  wire  _T_95 = _T_93 & _T_82; // @[dpath.scala 202:40]
  wire  _T_96 = _T_95 & wb_reg_ctrl_rf_wen; // @[dpath.scala 202:66]
  wire  _T_98 = _T_96 & _T_46; // @[dpath.scala 202:89]
  wire [63:0] _T_99 = _T_98 ? wb_reg_wbdata : dec_alu_op2; // @[Mux.scala 98:16]
  wire [63:0] _T_100 = _T_92 ? mem_wbdata : _T_99; // @[Mux.scala 98:16]
  wire [63:0] dec_op2_data = _T_86 ? exe_alu_out : _T_100; // @[Mux.scala 98:16]
  wire [63:0] exe_pc_plus4 = exe_reg_pc + 64'h4; // @[dpath.scala 289:34]
  wire  _T_133 = exe_reg_ctrl_wb_sel == 3'h2; // @[dpath.scala 295:28]
  reg [63:0] _T_181; // @[dpath.scala 351:119]
  wire  _T_189 = exe_reg_ctrl_mem_typ == 8'h1; // @[dpath.scala 364:27]
  wire [63:0] _T_193 = {exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0]}; // @[Cat.scala 29:58]
  wire  _T_194 = exe_reg_ctrl_mem_typ == 8'h3; // @[dpath.scala 365:27]
  wire [63:0] _T_197 = {exe_reg_rs2_data[15:0],exe_reg_rs2_data[15:0],exe_reg_rs2_data[15:0],exe_reg_rs2_data[15:0]}; // @[Cat.scala 29:58]
  wire  _T_198 = exe_reg_ctrl_mem_typ == 8'hf; // @[dpath.scala 366:27]
  wire [63:0] _T_200 = {exe_reg_rs2_data[31:0],exe_reg_rs2_data[31:0]}; // @[Cat.scala 29:58]
  wire [63:0] _T_203 = _T_198 ? _T_200 : exe_reg_rs2_data; // @[Mux.scala 98:16]
  wire [63:0] _T_204 = _T_194 ? _T_197 : _T_203; // @[Mux.scala 98:16]
  wire [14:0] _GEN_54 = {{7'd0}, exe_reg_ctrl_mem_typ}; // @[dpath.scala 370:39]
  wire [14:0] _T_206 = _GEN_54 << exe_alu_out[2:0]; // @[dpath.scala 370:39]
  reg [4:0] _T_214; // @[dpath.scala 384:12]
  reg [63:0] _T_215; // @[dpath.scala 385:12]
  reg [4:0] _T_216; // @[dpath.scala 386:12]
  reg [63:0] _T_217; // @[dpath.scala 387:12]
  regfile regfile ( // @[dpath.scala 143:23]
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
  alu alu ( // @[dpath.scala 275:19]
    .clock(alu_clock),
    .reset(alu_reset),
    .io_src1(alu_io_src1),
    .io_src2(alu_io_src2),
    .io_op(alu_io_op),
    .io_res(alu_io_res)
  );
  assign io_dat_dec_inst = dec_reg_inst; // @[dpath.scala 357:21]
  assign io_dat_exe_br_eq = exe_alu_op1 == exe_reg_rs2_data; // @[dpath.scala 358:21]
  assign io_dat_exe_br_lt = $signed(exe_alu_op1) < $signed(exe_reg_rs2_data); // @[dpath.scala 359:21]
  assign io_dat_exe_br_ltu = exe_alu_op1 < exe_reg_rs2_data; // @[dpath.scala 360:21]
  assign io_dat_exe_br_type = exe_reg_ctrl_br_type; // @[dpath.scala 361:21]
  assign io_inst_readIO_addr = if_reg_pc; // @[dpath.scala 109:23]
  assign io_inst_readIO_en = 1'h1; // @[dpath.scala 110:21]
  assign io_data_readIO_addr = _T_120 ? _T_125 : alu_io_res; // @[dpath.scala 320:24]
  assign io_data_readIO_en = exe_reg_ctrl_mem_fcn == 2'h1; // @[dpath.scala 319:24]
  assign io_data_writeIO_addr = _T_120 ? _T_125 : alu_io_res; // @[dpath.scala 374:24]
  assign io_data_writeIO_data = _T_189 ? _T_193 : _T_204; // @[dpath.scala 375:24]
  assign io_data_writeIO_en = exe_reg_ctrl_mem_fcn == 2'h2; // @[dpath.scala 373:24]
  assign io_data_writeIO_mask = _T_206[7:0]; // @[dpath.scala 376:24]
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
  assign regfile_io_rs1_addr = dec_reg_inst[19:15]; // @[dpath.scala 144:23]
  assign regfile_io_rs2_addr = dec_reg_inst[24:20]; // @[dpath.scala 145:23]
  assign regfile_io_waddr = wb_reg_wbaddr; // @[dpath.scala 148:20]
  assign regfile_io_wdata = wb_reg_wbdata; // @[dpath.scala 149:20]
  assign regfile_io_wen = wb_reg_ctrl_rf_wen; // @[dpath.scala 150:20]
  assign alu_clock = clock;
  assign alu_reset = reset;
  assign alu_io_src1 = exe_alu_op1; // @[dpath.scala 277:15]
  assign alu_io_src2 = brjmp_offset; // @[dpath.scala 278:15]
  assign alu_io_op = exe_reg_ctrl_alu_fun; // @[dpath.scala 276:13]
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
  _RAND_8 = {1{`RANDOM}};
  exe_reg_rs1_addr = _RAND_8[4:0];
  _RAND_9 = {1{`RANDOM}};
  exe_reg_rs2_addr = _RAND_9[4:0];
  _RAND_10 = {2{`RANDOM}};
  exe_alu_op1 = _RAND_10[63:0];
  _RAND_11 = {2{`RANDOM}};
  brjmp_offset = _RAND_11[63:0];
  _RAND_12 = {2{`RANDOM}};
  exe_reg_rs2_data = _RAND_12[63:0];
  _RAND_13 = {1{`RANDOM}};
  exe_reg_ctrl_br_type = _RAND_13[3:0];
  _RAND_14 = {1{`RANDOM}};
  exe_reg_ctrl_alu_fun = _RAND_14[4:0];
  _RAND_15 = {1{`RANDOM}};
  exe_reg_ctrl_wb_sel = _RAND_15[2:0];
  _RAND_16 = {1{`RANDOM}};
  exe_reg_ctrl_rf_wen = _RAND_16[0:0];
  _RAND_17 = {1{`RANDOM}};
  exe_reg_ctrl_mem_fcn = _RAND_17[1:0];
  _RAND_18 = {1{`RANDOM}};
  exe_reg_ctrl_mem_typ = _RAND_18[7:0];
  _RAND_19 = {1{`RANDOM}};
  exe_reg_ctrl_mem_ext = _RAND_19[2:0];
  _RAND_20 = {1{`RANDOM}};
  mem_reg_valid = _RAND_20[0:0];
  _RAND_21 = {2{`RANDOM}};
  mem_reg_pc = _RAND_21[63:0];
  _RAND_22 = {2{`RANDOM}};
  mem_reg_inst = _RAND_22[63:0];
  _RAND_23 = {2{`RANDOM}};
  mem_reg_alu_out = _RAND_23[63:0];
  _RAND_24 = {1{`RANDOM}};
  mem_reg_wbaddr = _RAND_24[4:0];
  _RAND_25 = {1{`RANDOM}};
  mem_reg_rs1_addr = _RAND_25[4:0];
  _RAND_26 = {1{`RANDOM}};
  mem_reg_rs2_addr = _RAND_26[4:0];
  _RAND_27 = {2{`RANDOM}};
  mem_reg_op1_data = _RAND_27[63:0];
  _RAND_28 = {2{`RANDOM}};
  mem_reg_op2_data = _RAND_28[63:0];
  _RAND_29 = {1{`RANDOM}};
  mem_reg_ctrl_rf_wen = _RAND_29[0:0];
  _RAND_30 = {1{`RANDOM}};
  mem_reg_ctrl_wb_sel = _RAND_30[2:0];
  _RAND_31 = {1{`RANDOM}};
  mem_reg_ctrl_mem_ext = _RAND_31[2:0];
  _RAND_32 = {2{`RANDOM}};
  mem_reg_dram_data = _RAND_32[63:0];
  _RAND_33 = {1{`RANDOM}};
  wb_reg_valid = _RAND_33[0:0];
  _RAND_34 = {2{`RANDOM}};
  wb_reg_pc = _RAND_34[63:0];
  _RAND_35 = {2{`RANDOM}};
  wb_reg_inst = _RAND_35[63:0];
  _RAND_36 = {1{`RANDOM}};
  wb_reg_wbaddr = _RAND_36[4:0];
  _RAND_37 = {2{`RANDOM}};
  wb_reg_wbdata = _RAND_37[63:0];
  _RAND_38 = {1{`RANDOM}};
  wb_reg_ctrl_rf_wen = _RAND_38[0:0];
  _RAND_39 = {2{`RANDOM}};
  _T_181 = _RAND_39[63:0];
  _RAND_40 = {1{`RANDOM}};
  _T_214 = _RAND_40[4:0];
  _RAND_41 = {2{`RANDOM}};
  _T_215 = _RAND_41[63:0];
  _RAND_42 = {1{`RANDOM}};
  _T_216 = _RAND_42[4:0];
  _RAND_43 = {2{`RANDOM}};
  _T_217 = _RAND_43[63:0];
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
    end else if (_T) begin
      if (_T_2) begin
        if_reg_pc <= if_pc_plus4;
      end else if (_T_3) begin
        if_reg_pc <= exe_brjmp_target;
      end else if (_T_4) begin
        if_reg_pc <= exe_adder_out;
      end else begin
        if_reg_pc <= 64'h4033;
      end
    end
    if (reset) begin
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
    end else if (_T) begin
      if (io_ctl_if_kill) begin
        dec_reg_inst <= 64'h4033;
      end else begin
        dec_reg_inst <= io_inst_readIO_data;
      end
    end
    if (reset) begin
      dec_reg_pc <= 64'h0;
    end else if (_T) begin
      dec_reg_pc <= if_reg_pc;
    end
    if (reset) begin
      exe_reg_valid <= 1'h0;
    end else if (io_ctl_dec_stall) begin
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
    end else if (io_ctl_dec_stall) begin
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
    end else if (!(io_ctl_dec_stall)) begin
      if (_T) begin
        exe_reg_pc <= dec_reg_pc;
      end
    end
    if (io_ctl_dec_stall) begin
      exe_reg_wbaddr <= 5'h0;
    end else if (_T) begin
      if (io_ctl_dec_kill) begin
        exe_reg_wbaddr <= 5'h0;
      end else begin
        exe_reg_wbaddr <= dec_wbaddr;
      end
    end
    if (!(io_ctl_dec_stall)) begin
      if (_T) begin
        exe_reg_rs1_addr <= dec_rs1_addr;
      end
    end
    if (!(io_ctl_dec_stall)) begin
      if (_T) begin
        exe_reg_rs2_addr <= dec_rs2_addr;
      end
    end
    if (!(io_ctl_dec_stall)) begin
      if (_T) begin
        if (_T_72) begin
          exe_alu_op1 <= {{32'd0}, imm_z};
        end else if (_T_73) begin
          exe_alu_op1 <= dec_reg_pc;
        end else if (_T_74) begin
          exe_alu_op1 <= _T_77;
        end else if (_T_60) begin
          if (_T_120) begin
            exe_alu_op1 <= _T_125;
          end else begin
            exe_alu_op1 <= alu_io_res;
          end
        end else if (_T_64) begin
          if (_T_177) begin
            if (_T_140) begin
              exe_alu_op1 <= _T_145;
            end else if (_T_146) begin
              exe_alu_op1 <= _T_149;
            end else if (_T_150) begin
              exe_alu_op1 <= _T_155;
            end else if (_T_156) begin
              exe_alu_op1 <= _T_159;
            end else if (_T_160) begin
              exe_alu_op1 <= _T_165;
            end else if (_T_166) begin
              exe_alu_op1 <= _T_169;
            end else begin
              exe_alu_op1 <= mem_reg_dram_data;
            end
          end else begin
            exe_alu_op1 <= mem_reg_alu_out;
          end
        end else if (_T_68) begin
          exe_alu_op1 <= wb_reg_wbdata;
        end else begin
          exe_alu_op1 <= regfile_io_rs1_data;
        end
      end
    end
    if (!(io_ctl_dec_stall)) begin
      if (_T) begin
        if (_T_86) begin
          if (_T_120) begin
            brjmp_offset <= _T_125;
          end else begin
            brjmp_offset <= alu_io_res;
          end
        end else if (_T_92) begin
          if (_T_177) begin
            if (_T_140) begin
              brjmp_offset <= _T_145;
            end else if (_T_146) begin
              brjmp_offset <= _T_149;
            end else if (_T_150) begin
              brjmp_offset <= _T_155;
            end else if (_T_156) begin
              brjmp_offset <= _T_159;
            end else if (_T_160) begin
              brjmp_offset <= _T_165;
            end else if (_T_166) begin
              brjmp_offset <= _T_169;
            end else begin
              brjmp_offset <= mem_reg_dram_data;
            end
          end else begin
            brjmp_offset <= mem_reg_alu_out;
          end
        end else if (_T_98) begin
          brjmp_offset <= wb_reg_wbdata;
        end else if (_T_46) begin
          brjmp_offset <= regfile_io_rs2_data;
        end else if (_T_47) begin
          brjmp_offset <= imm_itype_sext;
        end else if (_T_48) begin
          brjmp_offset <= imm_stype_sext;
        end else if (_T_49) begin
          brjmp_offset <= imm_sbtype_sext;
        end else if (_T_50) begin
          brjmp_offset <= imm_utype_sext;
        end else if (_T_51) begin
          brjmp_offset <= imm_ujtype_sext;
        end else begin
          brjmp_offset <= 64'h0;
        end
      end
    end
    if (!(io_ctl_dec_stall)) begin
      if (_T) begin
        if (_T_84) begin
          if (_T_120) begin
            exe_reg_rs2_data <= _T_125;
          end else begin
            exe_reg_rs2_data <= alu_io_res;
          end
        end else if (_T_90) begin
          if (_T_177) begin
            if (_T_140) begin
              exe_reg_rs2_data <= _T_145;
            end else if (_T_146) begin
              exe_reg_rs2_data <= _T_149;
            end else if (_T_150) begin
              exe_reg_rs2_data <= _T_155;
            end else if (_T_156) begin
              exe_reg_rs2_data <= _T_159;
            end else if (_T_160) begin
              exe_reg_rs2_data <= _T_165;
            end else if (_T_166) begin
              exe_reg_rs2_data <= _T_169;
            end else begin
              exe_reg_rs2_data <= mem_reg_dram_data;
            end
          end else begin
            exe_reg_rs2_data <= mem_reg_alu_out;
          end
        end else if (_T_96) begin
          exe_reg_rs2_data <= wb_reg_wbdata;
        end else begin
          exe_reg_rs2_data <= regfile_io_rs2_data;
        end
      end
    end
    if (reset) begin
      exe_reg_ctrl_br_type <= 4'h0;
    end else if (io_ctl_dec_stall) begin
      exe_reg_ctrl_br_type <= 4'h0;
    end else if (_T) begin
      if (io_ctl_dec_kill) begin
        exe_reg_ctrl_br_type <= 4'h0;
      end else begin
        exe_reg_ctrl_br_type <= io_ctl_br_type;
      end
    end
    if (!(io_ctl_dec_stall)) begin
      if (_T) begin
        exe_reg_ctrl_alu_fun <= io_ctl_alu_fun;
      end
    end
    if (!(io_ctl_dec_stall)) begin
      if (_T) begin
        exe_reg_ctrl_wb_sel <= io_ctl_wb_sel;
      end
    end
    if (reset) begin
      exe_reg_ctrl_rf_wen <= 1'h0;
    end else if (io_ctl_dec_stall) begin
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
    end else if (io_ctl_dec_stall) begin
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
    end else if (!(io_ctl_dec_stall)) begin
      if (_T) begin
        if (!(io_ctl_dec_kill)) begin
          exe_reg_ctrl_mem_typ <= io_ctl_mem_typ;
        end
      end
    end
    if (reset) begin
      exe_reg_ctrl_mem_ext <= 3'h0;
    end else if (io_ctl_dec_stall) begin
      exe_reg_ctrl_mem_ext <= 3'h0;
    end else if (_T) begin
      if (io_ctl_dec_kill) begin
        exe_reg_ctrl_mem_ext <= 3'h0;
      end else begin
        exe_reg_ctrl_mem_ext <= io_ctl_mem_ext;
      end
    end
    if (reset) begin
      mem_reg_valid <= 1'h0;
    end else begin
      mem_reg_valid <= exe_reg_valid;
    end
    mem_reg_pc <= exe_reg_pc;
    mem_reg_inst <= exe_reg_inst;
    if (_T_133) begin
      mem_reg_alu_out <= exe_pc_plus4;
    end else if (_T_120) begin
      mem_reg_alu_out <= _T_125;
    end else begin
      mem_reg_alu_out <= alu_io_res;
    end
    mem_reg_wbaddr <= exe_reg_wbaddr;
    mem_reg_rs1_addr <= exe_reg_rs1_addr;
    mem_reg_rs2_addr <= exe_reg_rs2_addr;
    mem_reg_op1_data <= exe_alu_op1;
    mem_reg_op2_data <= brjmp_offset;
    if (reset) begin
      mem_reg_ctrl_rf_wen <= 1'h0;
    end else begin
      mem_reg_ctrl_rf_wen <= exe_reg_ctrl_rf_wen;
    end
    mem_reg_ctrl_wb_sel <= exe_reg_ctrl_wb_sel;
    if (reset) begin
      mem_reg_ctrl_mem_ext <= 3'h0;
    end else begin
      mem_reg_ctrl_mem_ext <= exe_reg_ctrl_mem_ext;
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
    wb_reg_inst <= mem_reg_inst;
    wb_reg_wbaddr <= mem_reg_wbaddr;
    if (_T_177) begin
      if (_T_140) begin
        wb_reg_wbdata <= _T_145;
      end else if (_T_146) begin
        wb_reg_wbdata <= _T_149;
      end else if (_T_150) begin
        wb_reg_wbdata <= _T_155;
      end else if (_T_156) begin
        wb_reg_wbdata <= _T_159;
      end else if (_T_160) begin
        wb_reg_wbdata <= _T_165;
      end else if (_T_166) begin
        wb_reg_wbdata <= _T_169;
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
    _T_181 <= mem_reg_inst;
    _T_214 <= mem_reg_rs1_addr;
    _T_215 <= mem_reg_op1_data;
    _T_216 <= mem_reg_rs2_addr;
    _T_217 <= mem_reg_op2_data;
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_10) begin
          $fwrite(32'h80000002,"IF : pc=[%x] inst=[%x] if_pc_next=[%x] en=%d pc_sel=[%d] e_bj_pc=[%x]\n",if_reg_pc,io_inst_readIO_data,if_pc_next,io_inst_readIO_en,io_ctl_exe_pc_sel,exe_brjmp_target); // @[dpath.scala 131:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_10) begin
          $fwrite(32'h80000002,"DEC: valid = %d pc=[%x] inst=[%x] op1=[%x] alu2=[%x] op2=[%x]\n",dec_reg_valid,dec_reg_pc,dec_reg_inst,dec_op1_data,dec_alu_op2,dec_op2_data); // @[dpath.scala 267:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_10) begin
          $fwrite(32'h80000002,"EXE: valid = %d pc=[%x] inst=[%x] bj_target = [%x]\n",exe_reg_valid,exe_reg_pc,exe_reg_inst,exe_brjmp_target); // @[dpath.scala 314:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_10) begin
          $fwrite(32'h80000002,"MEM read data = [%x]\n",mem_reg_dram_data); // @[dpath.scala 322:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_10) begin
          $fwrite(32'h80000002,"MEM: valid = %d pc=[%x] inst=[%x] wb_sel=[%d] wbdata=[%x]\n",mem_reg_valid,mem_reg_pc,mem_reg_inst,mem_reg_ctrl_wb_sel,mem_wbdata); // @[dpath.scala 339:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_10) begin
          $fwrite(32'h80000002,"WB : valid = %d pc=[%x] inst=[%x], mem_wbdata=[%x], mem_reg_wbaddr=[%d]\n",wb_reg_valid,wb_reg_pc,_T_181,wb_reg_wbdata,wb_reg_wbaddr); // @[dpath.scala 351:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_10) begin
          $fwrite(32'h80000002,"store: mem_typ=[%x] offset=[%x]\n",exe_reg_ctrl_mem_typ,exe_alu_out[2:0]); // @[dpath.scala 371:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_10) begin
          $fwrite(32'h80000002,"store:addr = [%x] en=%d data = [%x] mask = %b\n ",io_data_writeIO_addr,io_data_writeIO_en,io_data_writeIO_data,io_data_writeIO_mask); // @[dpath.scala 377:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_10) begin
          $fwrite(32'h80000002,"pc=[%x] W[r%d=%x][%d] Op1=[r%d][%x] Op2=[r%d][%x] inst=[%x]\n\n",wb_reg_pc,wb_reg_wbaddr,wb_reg_wbdata,wb_reg_ctrl_rf_wen,_T_214,_T_215,_T_216,_T_217,wb_reg_inst); // @[dpath.scala 379:9]
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
  wire [2:0] cpath_io_ctl_mem_ext; // @[core.scala 14:21]
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
  wire [2:0] dpath_io_ctl_mem_ext; // @[core.scala 15:21]
  wire [63:0] dpath_io_dat_dec_inst; // @[core.scala 15:21]
  wire  dpath_io_dat_exe_br_eq; // @[core.scala 15:21]
  wire  dpath_io_dat_exe_br_lt; // @[core.scala 15:21]
  wire  dpath_io_dat_exe_br_ltu; // @[core.scala 15:21]
  wire [3:0] dpath_io_dat_exe_br_type; // @[core.scala 15:21]
  wire [63:0] dpath_io_inst_readIO_addr; // @[core.scala 15:21]
  wire [63:0] dpath_io_inst_readIO_data; // @[core.scala 15:21]
  wire  dpath_io_inst_readIO_en; // @[core.scala 15:21]
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
    .io_ctl_mem_ext(cpath_io_ctl_mem_ext)
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
    .io_ctl_mem_ext(dpath_io_ctl_mem_ext),
    .io_dat_dec_inst(dpath_io_dat_dec_inst),
    .io_dat_exe_br_eq(dpath_io_dat_exe_br_eq),
    .io_dat_exe_br_lt(dpath_io_dat_exe_br_lt),
    .io_dat_exe_br_ltu(dpath_io_dat_exe_br_ltu),
    .io_dat_exe_br_type(dpath_io_dat_exe_br_type),
    .io_inst_readIO_addr(dpath_io_inst_readIO_addr),
    .io_inst_readIO_data(dpath_io_inst_readIO_data),
    .io_inst_readIO_en(dpath_io_inst_readIO_en),
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
  assign dpath_io_ctl_mem_ext = cpath_io_ctl_mem_ext; // @[core.scala 21:16]
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
