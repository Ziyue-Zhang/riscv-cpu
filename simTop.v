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
  output [3:0]  io_ctl_alu_fun,
  output [1:0]  io_ctl_wb_sel,
  output        io_ctl_rf_wen,
  output [1:0]  io_ctl_mem_fcn,
  output [2:0]  io_ctl_mem_typ
);
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  wire [63:0] _T = io_dat_dec_inst & 64'h707f; // @[Lookup.scala 31:38]
  wire  _T_1 = 64'h2003 == _T; // @[Lookup.scala 31:38]
  wire  _T_3 = 64'h3 == _T; // @[Lookup.scala 31:38]
  wire  _T_5 = 64'h4003 == _T; // @[Lookup.scala 31:38]
  wire  _T_7 = 64'h1003 == _T; // @[Lookup.scala 31:38]
  wire  _T_9 = 64'h5003 == _T; // @[Lookup.scala 31:38]
  wire  _T_11 = 64'h2023 == _T; // @[Lookup.scala 31:38]
  wire  _T_13 = 64'h23 == _T; // @[Lookup.scala 31:38]
  wire  _T_15 = 64'h1023 == _T; // @[Lookup.scala 31:38]
  wire [63:0] _T_16 = io_dat_dec_inst & 64'h7f; // @[Lookup.scala 31:38]
  wire  _T_17 = 64'h17 == _T_16; // @[Lookup.scala 31:38]
  wire  _T_19 = 64'h37 == _T_16; // @[Lookup.scala 31:38]
  wire  _T_21 = 64'h13 == _T; // @[Lookup.scala 31:38]
  wire  _T_23 = 64'h7013 == _T; // @[Lookup.scala 31:38]
  wire  _T_25 = 64'h6013 == _T; // @[Lookup.scala 31:38]
  wire  _T_27 = 64'h4013 == _T; // @[Lookup.scala 31:38]
  wire  _T_29 = 64'h2013 == _T; // @[Lookup.scala 31:38]
  wire  _T_31 = 64'h3013 == _T; // @[Lookup.scala 31:38]
  wire [63:0] _T_32 = io_dat_dec_inst & 64'hfc00707f; // @[Lookup.scala 31:38]
  wire  _T_33 = 64'h1013 == _T_32; // @[Lookup.scala 31:38]
  wire  _T_35 = 64'h40005013 == _T_32; // @[Lookup.scala 31:38]
  wire  _T_37 = 64'h5013 == _T_32; // @[Lookup.scala 31:38]
  wire [63:0] _T_38 = io_dat_dec_inst & 64'hfe00707f; // @[Lookup.scala 31:38]
  wire  _T_39 = 64'h1033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_41 = 64'h33 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_43 = 64'h40000033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_45 = 64'h2033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_47 = 64'h3033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_49 = 64'h7033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_51 = 64'h6033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_53 = 64'h4033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_55 = 64'h40005033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_57 = 64'h5033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_59 = 64'h6f == _T_16; // @[Lookup.scala 31:38]
  wire  _T_61 = 64'h67 == _T; // @[Lookup.scala 31:38]
  wire  _T_63 = 64'h63 == _T; // @[Lookup.scala 31:38]
  wire  _T_65 = 64'h1063 == _T; // @[Lookup.scala 31:38]
  wire  _T_67 = 64'h5063 == _T; // @[Lookup.scala 31:38]
  wire  _T_69 = 64'h7063 == _T; // @[Lookup.scala 31:38]
  wire  _T_71 = 64'h4063 == _T; // @[Lookup.scala 31:38]
  wire  _T_73 = 64'h6063 == _T; // @[Lookup.scala 31:38]
  wire  _T_75 = _T_71 | _T_73; // @[Lookup.scala 33:37]
  wire  _T_76 = _T_69 | _T_75; // @[Lookup.scala 33:37]
  wire  _T_77 = _T_67 | _T_76; // @[Lookup.scala 33:37]
  wire  _T_78 = _T_65 | _T_77; // @[Lookup.scala 33:37]
  wire  _T_79 = _T_63 | _T_78; // @[Lookup.scala 33:37]
  wire  _T_80 = _T_61 | _T_79; // @[Lookup.scala 33:37]
  wire [3:0] _T_110 = _T_73 ? 4'h6 : 4'h0; // @[Lookup.scala 33:37]
  wire [3:0] _T_111 = _T_71 ? 4'h5 : _T_110; // @[Lookup.scala 33:37]
  wire [3:0] _T_112 = _T_69 ? 4'h4 : _T_111; // @[Lookup.scala 33:37]
  wire [3:0] _T_113 = _T_67 ? 4'h3 : _T_112; // @[Lookup.scala 33:37]
  wire [3:0] _T_114 = _T_65 ? 4'h1 : _T_113; // @[Lookup.scala 33:37]
  wire [3:0] _T_115 = _T_63 ? 4'h2 : _T_114; // @[Lookup.scala 33:37]
  wire [3:0] _T_116 = _T_61 ? 4'h8 : _T_115; // @[Lookup.scala 33:37]
  wire [3:0] _T_117 = _T_59 ? 4'h7 : _T_116; // @[Lookup.scala 33:37]
  wire [3:0] _T_118 = _T_57 ? 4'h0 : _T_117; // @[Lookup.scala 33:37]
  wire [3:0] _T_119 = _T_55 ? 4'h0 : _T_118; // @[Lookup.scala 33:37]
  wire [3:0] _T_120 = _T_53 ? 4'h0 : _T_119; // @[Lookup.scala 33:37]
  wire [3:0] _T_121 = _T_51 ? 4'h0 : _T_120; // @[Lookup.scala 33:37]
  wire [3:0] _T_122 = _T_49 ? 4'h0 : _T_121; // @[Lookup.scala 33:37]
  wire [3:0] _T_123 = _T_47 ? 4'h0 : _T_122; // @[Lookup.scala 33:37]
  wire [3:0] _T_124 = _T_45 ? 4'h0 : _T_123; // @[Lookup.scala 33:37]
  wire [3:0] _T_125 = _T_43 ? 4'h0 : _T_124; // @[Lookup.scala 33:37]
  wire [3:0] _T_126 = _T_41 ? 4'h0 : _T_125; // @[Lookup.scala 33:37]
  wire [3:0] _T_127 = _T_39 ? 4'h0 : _T_126; // @[Lookup.scala 33:37]
  wire [3:0] _T_128 = _T_37 ? 4'h0 : _T_127; // @[Lookup.scala 33:37]
  wire [3:0] _T_129 = _T_35 ? 4'h0 : _T_128; // @[Lookup.scala 33:37]
  wire [3:0] _T_130 = _T_33 ? 4'h0 : _T_129; // @[Lookup.scala 33:37]
  wire [3:0] _T_131 = _T_31 ? 4'h0 : _T_130; // @[Lookup.scala 33:37]
  wire [3:0] _T_132 = _T_29 ? 4'h0 : _T_131; // @[Lookup.scala 33:37]
  wire [3:0] _T_133 = _T_27 ? 4'h0 : _T_132; // @[Lookup.scala 33:37]
  wire [3:0] _T_134 = _T_25 ? 4'h0 : _T_133; // @[Lookup.scala 33:37]
  wire [3:0] _T_135 = _T_23 ? 4'h0 : _T_134; // @[Lookup.scala 33:37]
  wire [3:0] _T_136 = _T_21 ? 4'h0 : _T_135; // @[Lookup.scala 33:37]
  wire [3:0] _T_137 = _T_19 ? 4'h0 : _T_136; // @[Lookup.scala 33:37]
  wire [3:0] _T_138 = _T_17 ? 4'h0 : _T_137; // @[Lookup.scala 33:37]
  wire [3:0] _T_139 = _T_15 ? 4'h0 : _T_138; // @[Lookup.scala 33:37]
  wire [3:0] _T_140 = _T_13 ? 4'h0 : _T_139; // @[Lookup.scala 33:37]
  wire [3:0] _T_141 = _T_11 ? 4'h0 : _T_140; // @[Lookup.scala 33:37]
  wire [3:0] _T_142 = _T_9 ? 4'h0 : _T_141; // @[Lookup.scala 33:37]
  wire [3:0] _T_143 = _T_7 ? 4'h0 : _T_142; // @[Lookup.scala 33:37]
  wire [3:0] _T_144 = _T_5 ? 4'h0 : _T_143; // @[Lookup.scala 33:37]
  wire [3:0] _T_145 = _T_3 ? 4'h0 : _T_144; // @[Lookup.scala 33:37]
  wire [1:0] _T_174 = _T_17 ? 2'h1 : 2'h0; // @[Lookup.scala 33:37]
  wire [1:0] _T_175 = _T_15 ? 2'h0 : _T_174; // @[Lookup.scala 33:37]
  wire [1:0] _T_176 = _T_13 ? 2'h0 : _T_175; // @[Lookup.scala 33:37]
  wire [1:0] _T_177 = _T_11 ? 2'h0 : _T_176; // @[Lookup.scala 33:37]
  wire [1:0] _T_178 = _T_9 ? 2'h0 : _T_177; // @[Lookup.scala 33:37]
  wire [1:0] _T_179 = _T_7 ? 2'h0 : _T_178; // @[Lookup.scala 33:37]
  wire [1:0] _T_180 = _T_5 ? 2'h0 : _T_179; // @[Lookup.scala 33:37]
  wire [1:0] _T_181 = _T_3 ? 2'h0 : _T_180; // @[Lookup.scala 33:37]
  wire [2:0] _T_182 = _T_73 ? 3'h3 : 3'h0; // @[Lookup.scala 33:37]
  wire [2:0] _T_183 = _T_71 ? 3'h3 : _T_182; // @[Lookup.scala 33:37]
  wire [2:0] _T_184 = _T_69 ? 3'h3 : _T_183; // @[Lookup.scala 33:37]
  wire [2:0] _T_185 = _T_67 ? 3'h3 : _T_184; // @[Lookup.scala 33:37]
  wire [2:0] _T_186 = _T_65 ? 3'h3 : _T_185; // @[Lookup.scala 33:37]
  wire [2:0] _T_187 = _T_63 ? 3'h3 : _T_186; // @[Lookup.scala 33:37]
  wire [2:0] _T_188 = _T_61 ? 3'h1 : _T_187; // @[Lookup.scala 33:37]
  wire [2:0] _T_189 = _T_59 ? 3'h5 : _T_188; // @[Lookup.scala 33:37]
  wire [2:0] _T_190 = _T_57 ? 3'h0 : _T_189; // @[Lookup.scala 33:37]
  wire [2:0] _T_191 = _T_55 ? 3'h0 : _T_190; // @[Lookup.scala 33:37]
  wire [2:0] _T_192 = _T_53 ? 3'h0 : _T_191; // @[Lookup.scala 33:37]
  wire [2:0] _T_193 = _T_51 ? 3'h0 : _T_192; // @[Lookup.scala 33:37]
  wire [2:0] _T_194 = _T_49 ? 3'h0 : _T_193; // @[Lookup.scala 33:37]
  wire [2:0] _T_195 = _T_47 ? 3'h0 : _T_194; // @[Lookup.scala 33:37]
  wire [2:0] _T_196 = _T_45 ? 3'h0 : _T_195; // @[Lookup.scala 33:37]
  wire [2:0] _T_197 = _T_43 ? 3'h0 : _T_196; // @[Lookup.scala 33:37]
  wire [2:0] _T_198 = _T_41 ? 3'h0 : _T_197; // @[Lookup.scala 33:37]
  wire [2:0] _T_199 = _T_39 ? 3'h0 : _T_198; // @[Lookup.scala 33:37]
  wire [2:0] _T_200 = _T_37 ? 3'h1 : _T_199; // @[Lookup.scala 33:37]
  wire [2:0] _T_201 = _T_35 ? 3'h1 : _T_200; // @[Lookup.scala 33:37]
  wire [2:0] _T_202 = _T_33 ? 3'h1 : _T_201; // @[Lookup.scala 33:37]
  wire [2:0] _T_203 = _T_31 ? 3'h1 : _T_202; // @[Lookup.scala 33:37]
  wire [2:0] _T_204 = _T_29 ? 3'h1 : _T_203; // @[Lookup.scala 33:37]
  wire [2:0] _T_205 = _T_27 ? 3'h1 : _T_204; // @[Lookup.scala 33:37]
  wire [2:0] _T_206 = _T_25 ? 3'h1 : _T_205; // @[Lookup.scala 33:37]
  wire [2:0] _T_207 = _T_23 ? 3'h1 : _T_206; // @[Lookup.scala 33:37]
  wire [2:0] _T_208 = _T_21 ? 3'h1 : _T_207; // @[Lookup.scala 33:37]
  wire [2:0] _T_209 = _T_19 ? 3'h4 : _T_208; // @[Lookup.scala 33:37]
  wire [2:0] _T_210 = _T_17 ? 3'h4 : _T_209; // @[Lookup.scala 33:37]
  wire [2:0] _T_211 = _T_15 ? 3'h2 : _T_210; // @[Lookup.scala 33:37]
  wire [2:0] _T_212 = _T_13 ? 3'h2 : _T_211; // @[Lookup.scala 33:37]
  wire [2:0] _T_213 = _T_11 ? 3'h2 : _T_212; // @[Lookup.scala 33:37]
  wire [2:0] _T_214 = _T_9 ? 3'h1 : _T_213; // @[Lookup.scala 33:37]
  wire [2:0] _T_215 = _T_7 ? 3'h1 : _T_214; // @[Lookup.scala 33:37]
  wire [2:0] _T_216 = _T_5 ? 3'h1 : _T_215; // @[Lookup.scala 33:37]
  wire [2:0] _T_217 = _T_3 ? 3'h1 : _T_216; // @[Lookup.scala 33:37]
  wire  _T_225 = _T_59 ? 1'h0 : _T_80; // @[Lookup.scala 33:37]
  wire  _T_226 = _T_57 | _T_225; // @[Lookup.scala 33:37]
  wire  _T_227 = _T_55 | _T_226; // @[Lookup.scala 33:37]
  wire  _T_228 = _T_53 | _T_227; // @[Lookup.scala 33:37]
  wire  _T_229 = _T_51 | _T_228; // @[Lookup.scala 33:37]
  wire  _T_230 = _T_49 | _T_229; // @[Lookup.scala 33:37]
  wire  _T_231 = _T_47 | _T_230; // @[Lookup.scala 33:37]
  wire  _T_232 = _T_45 | _T_231; // @[Lookup.scala 33:37]
  wire  _T_233 = _T_43 | _T_232; // @[Lookup.scala 33:37]
  wire  _T_234 = _T_41 | _T_233; // @[Lookup.scala 33:37]
  wire  _T_235 = _T_39 | _T_234; // @[Lookup.scala 33:37]
  wire  _T_236 = _T_37 | _T_235; // @[Lookup.scala 33:37]
  wire  _T_237 = _T_35 | _T_236; // @[Lookup.scala 33:37]
  wire  _T_238 = _T_33 | _T_237; // @[Lookup.scala 33:37]
  wire  _T_239 = _T_31 | _T_238; // @[Lookup.scala 33:37]
  wire  _T_240 = _T_29 | _T_239; // @[Lookup.scala 33:37]
  wire  _T_241 = _T_27 | _T_240; // @[Lookup.scala 33:37]
  wire  _T_242 = _T_25 | _T_241; // @[Lookup.scala 33:37]
  wire  _T_243 = _T_23 | _T_242; // @[Lookup.scala 33:37]
  wire  _T_244 = _T_21 | _T_243; // @[Lookup.scala 33:37]
  wire  _T_245 = _T_19 ? 1'h0 : _T_244; // @[Lookup.scala 33:37]
  wire  _T_246 = _T_17 ? 1'h0 : _T_245; // @[Lookup.scala 33:37]
  wire  _T_247 = _T_15 | _T_246; // @[Lookup.scala 33:37]
  wire  _T_248 = _T_13 | _T_247; // @[Lookup.scala 33:37]
  wire  _T_249 = _T_11 | _T_248; // @[Lookup.scala 33:37]
  wire  _T_250 = _T_9 | _T_249; // @[Lookup.scala 33:37]
  wire  _T_251 = _T_7 | _T_250; // @[Lookup.scala 33:37]
  wire  _T_252 = _T_5 | _T_251; // @[Lookup.scala 33:37]
  wire  _T_253 = _T_3 | _T_252; // @[Lookup.scala 33:37]
  wire  cs_rs1_oen = _T_1 | _T_253; // @[Lookup.scala 33:37]
  wire  _T_260 = _T_61 ? 1'h0 : _T_79; // @[Lookup.scala 33:37]
  wire  _T_261 = _T_59 ? 1'h0 : _T_260; // @[Lookup.scala 33:37]
  wire  _T_262 = _T_57 | _T_261; // @[Lookup.scala 33:37]
  wire  _T_263 = _T_55 | _T_262; // @[Lookup.scala 33:37]
  wire  _T_264 = _T_53 | _T_263; // @[Lookup.scala 33:37]
  wire  _T_265 = _T_51 | _T_264; // @[Lookup.scala 33:37]
  wire  _T_266 = _T_49 | _T_265; // @[Lookup.scala 33:37]
  wire  _T_267 = _T_47 | _T_266; // @[Lookup.scala 33:37]
  wire  _T_268 = _T_45 | _T_267; // @[Lookup.scala 33:37]
  wire  _T_269 = _T_43 | _T_268; // @[Lookup.scala 33:37]
  wire  _T_270 = _T_41 | _T_269; // @[Lookup.scala 33:37]
  wire  _T_271 = _T_39 | _T_270; // @[Lookup.scala 33:37]
  wire  _T_272 = _T_37 ? 1'h0 : _T_271; // @[Lookup.scala 33:37]
  wire  _T_273 = _T_35 ? 1'h0 : _T_272; // @[Lookup.scala 33:37]
  wire  _T_274 = _T_33 ? 1'h0 : _T_273; // @[Lookup.scala 33:37]
  wire  _T_275 = _T_31 ? 1'h0 : _T_274; // @[Lookup.scala 33:37]
  wire  _T_276 = _T_29 ? 1'h0 : _T_275; // @[Lookup.scala 33:37]
  wire  _T_277 = _T_27 ? 1'h0 : _T_276; // @[Lookup.scala 33:37]
  wire  _T_278 = _T_25 ? 1'h0 : _T_277; // @[Lookup.scala 33:37]
  wire  _T_279 = _T_23 ? 1'h0 : _T_278; // @[Lookup.scala 33:37]
  wire  _T_280 = _T_21 ? 1'h0 : _T_279; // @[Lookup.scala 33:37]
  wire  _T_281 = _T_19 ? 1'h0 : _T_280; // @[Lookup.scala 33:37]
  wire  _T_282 = _T_17 ? 1'h0 : _T_281; // @[Lookup.scala 33:37]
  wire  _T_283 = _T_15 | _T_282; // @[Lookup.scala 33:37]
  wire  _T_284 = _T_13 | _T_283; // @[Lookup.scala 33:37]
  wire  _T_285 = _T_11 | _T_284; // @[Lookup.scala 33:37]
  wire  _T_286 = _T_9 ? 1'h0 : _T_285; // @[Lookup.scala 33:37]
  wire  _T_287 = _T_7 ? 1'h0 : _T_286; // @[Lookup.scala 33:37]
  wire  _T_288 = _T_5 ? 1'h0 : _T_287; // @[Lookup.scala 33:37]
  wire  _T_289 = _T_3 ? 1'h0 : _T_288; // @[Lookup.scala 33:37]
  wire  cs_rs2_oen = _T_1 ? 1'h0 : _T_289; // @[Lookup.scala 33:37]
  wire [3:0] _T_298 = _T_57 ? 4'h3 : 4'h0; // @[Lookup.scala 33:37]
  wire [3:0] _T_299 = _T_55 ? 4'h4 : _T_298; // @[Lookup.scala 33:37]
  wire [3:0] _T_300 = _T_53 ? 4'h7 : _T_299; // @[Lookup.scala 33:37]
  wire [3:0] _T_301 = _T_51 ? 4'h6 : _T_300; // @[Lookup.scala 33:37]
  wire [3:0] _T_302 = _T_49 ? 4'h5 : _T_301; // @[Lookup.scala 33:37]
  wire [3:0] _T_303 = _T_47 ? 4'h9 : _T_302; // @[Lookup.scala 33:37]
  wire [3:0] _T_304 = _T_45 ? 4'h8 : _T_303; // @[Lookup.scala 33:37]
  wire [3:0] _T_305 = _T_43 ? 4'h1 : _T_304; // @[Lookup.scala 33:37]
  wire [3:0] _T_306 = _T_41 ? 4'h0 : _T_305; // @[Lookup.scala 33:37]
  wire [3:0] _T_307 = _T_39 ? 4'h2 : _T_306; // @[Lookup.scala 33:37]
  wire [3:0] _T_308 = _T_37 ? 4'h3 : _T_307; // @[Lookup.scala 33:37]
  wire [3:0] _T_309 = _T_35 ? 4'h4 : _T_308; // @[Lookup.scala 33:37]
  wire [3:0] _T_310 = _T_33 ? 4'h2 : _T_309; // @[Lookup.scala 33:37]
  wire [3:0] _T_311 = _T_31 ? 4'h9 : _T_310; // @[Lookup.scala 33:37]
  wire [3:0] _T_312 = _T_29 ? 4'h8 : _T_311; // @[Lookup.scala 33:37]
  wire [3:0] _T_313 = _T_27 ? 4'h7 : _T_312; // @[Lookup.scala 33:37]
  wire [3:0] _T_314 = _T_25 ? 4'h6 : _T_313; // @[Lookup.scala 33:37]
  wire [3:0] _T_315 = _T_23 ? 4'h5 : _T_314; // @[Lookup.scala 33:37]
  wire [3:0] _T_316 = _T_21 ? 4'h0 : _T_315; // @[Lookup.scala 33:37]
  wire [3:0] _T_317 = _T_19 ? 4'hb : _T_316; // @[Lookup.scala 33:37]
  wire [3:0] _T_318 = _T_17 ? 4'h0 : _T_317; // @[Lookup.scala 33:37]
  wire [3:0] _T_319 = _T_15 ? 4'h0 : _T_318; // @[Lookup.scala 33:37]
  wire [3:0] _T_320 = _T_13 ? 4'h0 : _T_319; // @[Lookup.scala 33:37]
  wire [3:0] _T_321 = _T_11 ? 4'h0 : _T_320; // @[Lookup.scala 33:37]
  wire [3:0] _T_322 = _T_9 ? 4'h0 : _T_321; // @[Lookup.scala 33:37]
  wire [3:0] _T_323 = _T_7 ? 4'h0 : _T_322; // @[Lookup.scala 33:37]
  wire [3:0] _T_324 = _T_5 ? 4'h0 : _T_323; // @[Lookup.scala 33:37]
  wire [3:0] _T_325 = _T_3 ? 4'h0 : _T_324; // @[Lookup.scala 33:37]
  wire [1:0] _T_332 = _T_61 ? 2'h2 : 2'h0; // @[Lookup.scala 33:37]
  wire [1:0] _T_333 = _T_59 ? 2'h2 : _T_332; // @[Lookup.scala 33:37]
  wire [1:0] _T_334 = _T_57 ? 2'h0 : _T_333; // @[Lookup.scala 33:37]
  wire [1:0] _T_335 = _T_55 ? 2'h0 : _T_334; // @[Lookup.scala 33:37]
  wire [1:0] _T_336 = _T_53 ? 2'h0 : _T_335; // @[Lookup.scala 33:37]
  wire [1:0] _T_337 = _T_51 ? 2'h0 : _T_336; // @[Lookup.scala 33:37]
  wire [1:0] _T_338 = _T_49 ? 2'h0 : _T_337; // @[Lookup.scala 33:37]
  wire [1:0] _T_339 = _T_47 ? 2'h0 : _T_338; // @[Lookup.scala 33:37]
  wire [1:0] _T_340 = _T_45 ? 2'h0 : _T_339; // @[Lookup.scala 33:37]
  wire [1:0] _T_341 = _T_43 ? 2'h0 : _T_340; // @[Lookup.scala 33:37]
  wire [1:0] _T_342 = _T_41 ? 2'h0 : _T_341; // @[Lookup.scala 33:37]
  wire [1:0] _T_343 = _T_39 ? 2'h0 : _T_342; // @[Lookup.scala 33:37]
  wire [1:0] _T_344 = _T_37 ? 2'h0 : _T_343; // @[Lookup.scala 33:37]
  wire [1:0] _T_345 = _T_35 ? 2'h0 : _T_344; // @[Lookup.scala 33:37]
  wire [1:0] _T_346 = _T_33 ? 2'h0 : _T_345; // @[Lookup.scala 33:37]
  wire [1:0] _T_347 = _T_31 ? 2'h0 : _T_346; // @[Lookup.scala 33:37]
  wire [1:0] _T_348 = _T_29 ? 2'h0 : _T_347; // @[Lookup.scala 33:37]
  wire [1:0] _T_349 = _T_27 ? 2'h0 : _T_348; // @[Lookup.scala 33:37]
  wire [1:0] _T_350 = _T_25 ? 2'h0 : _T_349; // @[Lookup.scala 33:37]
  wire [1:0] _T_351 = _T_23 ? 2'h0 : _T_350; // @[Lookup.scala 33:37]
  wire [1:0] _T_352 = _T_21 ? 2'h0 : _T_351; // @[Lookup.scala 33:37]
  wire [1:0] _T_353 = _T_19 ? 2'h0 : _T_352; // @[Lookup.scala 33:37]
  wire [1:0] _T_354 = _T_17 ? 2'h0 : _T_353; // @[Lookup.scala 33:37]
  wire [1:0] _T_355 = _T_15 ? 2'h0 : _T_354; // @[Lookup.scala 33:37]
  wire [1:0] _T_356 = _T_13 ? 2'h0 : _T_355; // @[Lookup.scala 33:37]
  wire [1:0] _T_357 = _T_11 ? 2'h0 : _T_356; // @[Lookup.scala 33:37]
  wire [1:0] _T_358 = _T_9 ? 2'h1 : _T_357; // @[Lookup.scala 33:37]
  wire [1:0] _T_359 = _T_7 ? 2'h1 : _T_358; // @[Lookup.scala 33:37]
  wire [1:0] _T_360 = _T_5 ? 2'h1 : _T_359; // @[Lookup.scala 33:37]
  wire [1:0] _T_361 = _T_3 ? 2'h1 : _T_360; // @[Lookup.scala 33:37]
  wire  _T_369 = _T_59 | _T_61; // @[Lookup.scala 33:37]
  wire  _T_370 = _T_57 | _T_369; // @[Lookup.scala 33:37]
  wire  _T_371 = _T_55 | _T_370; // @[Lookup.scala 33:37]
  wire  _T_372 = _T_53 | _T_371; // @[Lookup.scala 33:37]
  wire  _T_373 = _T_51 | _T_372; // @[Lookup.scala 33:37]
  wire  _T_374 = _T_49 | _T_373; // @[Lookup.scala 33:37]
  wire  _T_375 = _T_47 | _T_374; // @[Lookup.scala 33:37]
  wire  _T_376 = _T_45 | _T_375; // @[Lookup.scala 33:37]
  wire  _T_377 = _T_43 | _T_376; // @[Lookup.scala 33:37]
  wire  _T_378 = _T_41 | _T_377; // @[Lookup.scala 33:37]
  wire  _T_379 = _T_39 | _T_378; // @[Lookup.scala 33:37]
  wire  _T_380 = _T_37 | _T_379; // @[Lookup.scala 33:37]
  wire  _T_381 = _T_35 | _T_380; // @[Lookup.scala 33:37]
  wire  _T_382 = _T_33 | _T_381; // @[Lookup.scala 33:37]
  wire  _T_383 = _T_31 | _T_382; // @[Lookup.scala 33:37]
  wire  _T_384 = _T_29 | _T_383; // @[Lookup.scala 33:37]
  wire  _T_385 = _T_27 | _T_384; // @[Lookup.scala 33:37]
  wire  _T_386 = _T_25 | _T_385; // @[Lookup.scala 33:37]
  wire  _T_387 = _T_23 | _T_386; // @[Lookup.scala 33:37]
  wire  _T_388 = _T_21 | _T_387; // @[Lookup.scala 33:37]
  wire  _T_389 = _T_19 | _T_388; // @[Lookup.scala 33:37]
  wire  _T_390 = _T_17 | _T_389; // @[Lookup.scala 33:37]
  wire  _T_391 = _T_15 ? 1'h0 : _T_390; // @[Lookup.scala 33:37]
  wire  _T_392 = _T_13 ? 1'h0 : _T_391; // @[Lookup.scala 33:37]
  wire  _T_393 = _T_11 ? 1'h0 : _T_392; // @[Lookup.scala 33:37]
  wire  _T_394 = _T_9 | _T_393; // @[Lookup.scala 33:37]
  wire  _T_395 = _T_7 | _T_394; // @[Lookup.scala 33:37]
  wire  _T_396 = _T_5 | _T_395; // @[Lookup.scala 33:37]
  wire  _T_397 = _T_3 | _T_396; // @[Lookup.scala 33:37]
  wire  _T_428 = _T_13 | _T_15; // @[Lookup.scala 33:37]
  wire  _T_429 = _T_11 | _T_428; // @[Lookup.scala 33:37]
  wire  _T_430 = _T_9 | _T_429; // @[Lookup.scala 33:37]
  wire  _T_431 = _T_7 | _T_430; // @[Lookup.scala 33:37]
  wire  _T_432 = _T_5 | _T_431; // @[Lookup.scala 33:37]
  wire  _T_433 = _T_3 | _T_432; // @[Lookup.scala 33:37]
  wire  cs0_3 = _T_1 | _T_433; // @[Lookup.scala 33:37]
  wire [1:0] _T_463 = _T_15 ? 2'h2 : 2'h0; // @[Lookup.scala 33:37]
  wire [1:0] _T_464 = _T_13 ? 2'h2 : _T_463; // @[Lookup.scala 33:37]
  wire [1:0] _T_465 = _T_11 ? 2'h2 : _T_464; // @[Lookup.scala 33:37]
  wire [1:0] _T_466 = _T_9 ? 2'h1 : _T_465; // @[Lookup.scala 33:37]
  wire [1:0] _T_467 = _T_7 ? 2'h1 : _T_466; // @[Lookup.scala 33:37]
  wire [1:0] _T_468 = _T_5 ? 2'h1 : _T_467; // @[Lookup.scala 33:37]
  wire [1:0] _T_469 = _T_3 ? 2'h1 : _T_468; // @[Lookup.scala 33:37]
  wire [1:0] cs0_4 = _T_1 ? 2'h1 : _T_469; // @[Lookup.scala 33:37]
  wire [2:0] _T_499 = _T_15 ? 3'h2 : 3'h0; // @[Lookup.scala 33:37]
  wire [2:0] _T_500 = _T_13 ? 3'h1 : _T_499; // @[Lookup.scala 33:37]
  wire [2:0] _T_501 = _T_11 ? 3'h3 : _T_500; // @[Lookup.scala 33:37]
  wire [2:0] _T_502 = _T_9 ? 3'h6 : _T_501; // @[Lookup.scala 33:37]
  wire [2:0] _T_503 = _T_7 ? 3'h2 : _T_502; // @[Lookup.scala 33:37]
  wire [2:0] _T_504 = _T_5 ? 3'h5 : _T_503; // @[Lookup.scala 33:37]
  wire [2:0] _T_505 = _T_3 ? 3'h1 : _T_504; // @[Lookup.scala 33:37]
  wire  _T_578 = io_dat_exe_br_type == 4'h0; // @[cpath.scala 91:48]
  wire  _T_579 = io_dat_exe_br_type == 4'h1; // @[cpath.scala 92:48]
  wire  _T_580 = ~io_dat_exe_br_eq; // @[cpath.scala 92:64]
  wire [1:0] _T_581 = _T_580 ? 2'h1 : 2'h0; // @[cpath.scala 92:63]
  wire  _T_582 = io_dat_exe_br_type == 4'h2; // @[cpath.scala 93:48]
  wire [1:0] _T_583 = io_dat_exe_br_eq ? 2'h1 : 2'h0; // @[cpath.scala 93:63]
  wire  _T_584 = io_dat_exe_br_type == 4'h3; // @[cpath.scala 94:48]
  wire  _T_585 = ~io_dat_exe_br_lt; // @[cpath.scala 94:64]
  wire [1:0] _T_586 = _T_585 ? 2'h1 : 2'h0; // @[cpath.scala 94:63]
  wire  _T_587 = io_dat_exe_br_type == 4'h4; // @[cpath.scala 95:48]
  wire  _T_588 = ~io_dat_exe_br_ltu; // @[cpath.scala 95:64]
  wire [1:0] _T_589 = _T_588 ? 2'h1 : 2'h0; // @[cpath.scala 95:63]
  wire  _T_590 = io_dat_exe_br_type == 4'h5; // @[cpath.scala 96:48]
  wire [1:0] _T_591 = io_dat_exe_br_lt ? 2'h1 : 2'h0; // @[cpath.scala 96:63]
  wire  _T_592 = io_dat_exe_br_type == 4'h6; // @[cpath.scala 97:48]
  wire [1:0] _T_593 = io_dat_exe_br_ltu ? 2'h1 : 2'h0; // @[cpath.scala 97:63]
  wire  _T_594 = io_dat_exe_br_type == 4'h7; // @[cpath.scala 98:48]
  wire  _T_595 = io_dat_exe_br_type == 4'h8; // @[cpath.scala 99:48]
  wire [1:0] _T_596 = _T_595 ? 2'h2 : 2'h0; // @[cpath.scala 99:28]
  wire [1:0] _T_597 = _T_594 ? 2'h1 : _T_596; // @[cpath.scala 98:28]
  wire [1:0] _T_598 = _T_592 ? _T_593 : _T_597; // @[cpath.scala 97:28]
  wire [1:0] _T_599 = _T_590 ? _T_591 : _T_598; // @[cpath.scala 96:28]
  wire [1:0] _T_600 = _T_587 ? _T_589 : _T_599; // @[cpath.scala 95:28]
  wire [1:0] _T_601 = _T_584 ? _T_586 : _T_600; // @[cpath.scala 94:28]
  wire [1:0] _T_602 = _T_582 ? _T_583 : _T_601; // @[cpath.scala 93:28]
  wire [1:0] _T_603 = _T_579 ? _T_581 : _T_602; // @[cpath.scala 92:28]
  wire [1:0] ctrl_exe_pc_sel = _T_578 ? 2'h0 : _T_603; // @[cpath.scala 91:28]
  wire  ifkill = ctrl_exe_pc_sel != 2'h0; // @[cpath.scala 103:34]
  wire [4:0] dec_rs1_addr = io_dat_dec_inst[19:15]; // @[cpath.scala 108:37]
  wire [4:0] dec_rs2_addr = io_dat_dec_inst[24:20]; // @[cpath.scala 109:37]
  wire [4:0] dec_wbaddr = io_dat_dec_inst[11:7]; // @[cpath.scala 110:37]
  wire  dec_rs1_oen = ifkill ? 1'h0 : cs_rs1_oen; // @[cpath.scala 111:25]
  wire  dec_rs2_oen = ifkill ? 1'h0 : cs_rs2_oen; // @[cpath.scala 112:25]
  reg [4:0] exe_reg_wbaddr; // @[cpath.scala 114:32]
  reg  exe_inst_is_load; // @[cpath.scala 151:33]
  wire  _T_608 = exe_reg_wbaddr == dec_rs1_addr; // @[cpath.scala 160:51]
  wire  _T_609 = exe_inst_is_load & _T_608; // @[cpath.scala 160:32]
  wire  _T_610 = exe_reg_wbaddr != 5'h0; // @[cpath.scala 160:88]
  wire  _T_611 = _T_609 & _T_610; // @[cpath.scala 160:69]
  wire  _T_612 = _T_611 & dec_rs1_oen; // @[cpath.scala 160:97]
  wire  _T_613 = exe_reg_wbaddr == dec_rs2_addr; // @[cpath.scala 161:51]
  wire  _T_614 = exe_inst_is_load & _T_613; // @[cpath.scala 161:32]
  wire  _T_616 = _T_614 & _T_610; // @[cpath.scala 161:69]
  wire  _T_617 = _T_616 & dec_rs2_oen; // @[cpath.scala 161:97]
  wire  stall = _T_612 | _T_617; // @[cpath.scala 160:113]
  wire  _T_605 = ~stall; // @[cpath.scala 126:9]
  wire  _T_606 = cs0_4 == 2'h1; // @[cpath.scala 154:48]
  wire  _T_607 = cs0_3 & _T_606; // @[cpath.scala 154:33]
  wire  _T_625 = ~reset; // @[cpath.scala 183:9]
  assign io_ctl_dec_stall = _T_612 | _T_617; // @[cpath.scala 164:21]
  assign io_ctl_exe_pc_sel = _T_578 ? 2'h0 : _T_603; // @[cpath.scala 165:22]
  assign io_ctl_br_type = _T_1 ? 4'h0 : _T_145; // @[cpath.scala 166:22]
  assign io_ctl_if_kill = ctrl_exe_pc_sel != 2'h0; // @[cpath.scala 167:22]
  assign io_ctl_dec_kill = ctrl_exe_pc_sel != 2'h0; // @[cpath.scala 168:22]
  assign io_ctl_op1_sel = _T_1 ? 2'h0 : _T_181; // @[cpath.scala 169:22]
  assign io_ctl_op2_sel = _T_1 ? 3'h1 : _T_217; // @[cpath.scala 170:22]
  assign io_ctl_alu_fun = _T_1 ? 4'h0 : _T_325; // @[cpath.scala 171:22]
  assign io_ctl_wb_sel = _T_1 ? 2'h1 : _T_361; // @[cpath.scala 172:22]
  assign io_ctl_rf_wen = _T_1 | _T_397; // @[cpath.scala 173:22]
  assign io_ctl_mem_fcn = _T_1 ? 2'h1 : _T_469; // @[cpath.scala 176:22]
  assign io_ctl_mem_typ = _T_1 ? 3'h3 : _T_505; // @[cpath.scala 177:22]
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
    if (_T_605) begin
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
      exe_inst_is_load <= _T_607;
    end
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_625) begin
          $fwrite(32'h80000002,"CTRL : inst = %x, ifkill = %d, deckill = %d, stall = %d\n",io_dat_dec_inst,ifkill,ifkill,stall); // @[cpath.scala 183:9]
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
  input  [3:0]  io_op,
  output [63:0] io_res
);
  wire [5:0] shamt = io_src2[5:0]; // @[alu.scala 17:22]
  wire  _T = io_op == 4'h0; // @[alu.scala 20:9]
  wire [63:0] _T_2 = io_src1 + io_src2; // @[alu.scala 20:34]
  wire  _T_3 = io_op == 4'h1; // @[alu.scala 21:9]
  wire [63:0] _T_5 = io_src1 - io_src2; // @[alu.scala 21:34]
  wire  _T_6 = io_op == 4'h5; // @[alu.scala 22:9]
  wire [63:0] _T_7 = io_src1 & io_src2; // @[alu.scala 22:34]
  wire  _T_8 = io_op == 4'h6; // @[alu.scala 23:9]
  wire [63:0] _T_9 = io_src1 | io_src2; // @[alu.scala 23:34]
  wire  _T_10 = io_op == 4'h7; // @[alu.scala 24:9]
  wire [63:0] _T_11 = io_src1 ^ io_src2; // @[alu.scala 24:34]
  wire  _T_12 = io_op == 4'h8; // @[alu.scala 25:9]
  wire  _T_15 = $signed(io_src1) < $signed(io_src2); // @[alu.scala 25:43]
  wire  _T_16 = io_op == 4'h9; // @[alu.scala 26:9]
  wire  _T_17 = io_src1 < io_src2; // @[alu.scala 26:34]
  wire  _T_18 = io_op == 4'h2; // @[alu.scala 27:9]
  wire [126:0] _GEN_0 = {{63'd0}, io_src1}; // @[alu.scala 27:35]
  wire [126:0] _T_19 = _GEN_0 << shamt; // @[alu.scala 27:35]
  wire  _T_21 = io_op == 4'h4; // @[alu.scala 28:9]
  wire [63:0] _T_24 = $signed(io_src1) >>> shamt; // @[alu.scala 28:59]
  wire  _T_25 = io_op == 4'h3; // @[alu.scala 29:9]
  wire [63:0] _T_26 = io_src1 >> shamt; // @[alu.scala 29:34]
  wire  _T_27 = io_op == 4'ha; // @[alu.scala 30:9]
  wire  _T_28 = io_op == 4'hb; // @[alu.scala 31:9]
  wire [63:0] _T_29 = _T_28 ? io_src2 : 64'h0; // @[Mux.scala 98:16]
  wire [63:0] _T_30 = _T_27 ? io_src1 : _T_29; // @[Mux.scala 98:16]
  wire [63:0] _T_31 = _T_25 ? _T_26 : _T_30; // @[Mux.scala 98:16]
  wire [63:0] _T_32 = _T_21 ? _T_24 : _T_31; // @[Mux.scala 98:16]
  wire [63:0] _T_33 = _T_18 ? _T_19[63:0] : _T_32; // @[Mux.scala 98:16]
  wire [63:0] _T_34 = _T_16 ? {{63'd0}, _T_17} : _T_33; // @[Mux.scala 98:16]
  wire [63:0] _T_35 = _T_12 ? {{63'd0}, _T_15} : _T_34; // @[Mux.scala 98:16]
  wire [63:0] _T_36 = _T_10 ? _T_11 : _T_35; // @[Mux.scala 98:16]
  wire [63:0] _T_37 = _T_8 ? _T_9 : _T_36; // @[Mux.scala 98:16]
  wire [63:0] _T_38 = _T_6 ? _T_7 : _T_37; // @[Mux.scala 98:16]
  wire [63:0] _T_39 = _T_3 ? _T_5 : _T_38; // @[Mux.scala 98:16]
  wire  _T_42 = ~reset; // @[alu.scala 34:9]
  assign io_res = _T ? _T_2 : _T_39; // @[alu.scala 19:10]
  always @(posedge clock) begin
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_42) begin
          $fwrite(32'h80000002,"ALU: op = %d, src1=[%x] src2=[%x] result=[%x]\n",io_op,io_src1,io_src2,io_res); // @[alu.scala 34:9]
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
  input  [3:0]  io_ctl_alu_fun,
  input  [1:0]  io_ctl_wb_sel,
  input         io_ctl_rf_wen,
  input  [1:0]  io_ctl_mem_fcn,
  input  [2:0]  io_ctl_mem_typ,
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
  reg [63:0] _RAND_20;
  reg [63:0] _RAND_21;
  reg [63:0] _RAND_22;
  reg [31:0] _RAND_23;
  reg [31:0] _RAND_24;
  reg [31:0] _RAND_25;
  reg [63:0] _RAND_26;
  reg [63:0] _RAND_27;
  reg [31:0] _RAND_28;
  reg [31:0] _RAND_29;
  reg [63:0] _RAND_30;
  reg [31:0] _RAND_31;
  reg [63:0] _RAND_32;
  reg [63:0] _RAND_33;
  reg [31:0] _RAND_34;
  reg [63:0] _RAND_35;
  reg [31:0] _RAND_36;
  reg [63:0] _RAND_37;
  reg [31:0] _RAND_38;
  reg [63:0] _RAND_39;
  reg [31:0] _RAND_40;
  reg [63:0] _RAND_41;
`endif // RANDOMIZE_REG_INIT
  wire  regfile_clock; // @[dpath.scala 141:23]
  wire  regfile_reset; // @[dpath.scala 141:23]
  wire [4:0] regfile_io_rs1_addr; // @[dpath.scala 141:23]
  wire [63:0] regfile_io_rs1_data; // @[dpath.scala 141:23]
  wire [4:0] regfile_io_rs2_addr; // @[dpath.scala 141:23]
  wire [63:0] regfile_io_rs2_data; // @[dpath.scala 141:23]
  wire [4:0] regfile_io_waddr; // @[dpath.scala 141:23]
  wire [63:0] regfile_io_wdata; // @[dpath.scala 141:23]
  wire  regfile_io_wen; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_0; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_1; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_2; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_3; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_4; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_5; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_6; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_7; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_8; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_9; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_10; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_11; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_12; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_13; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_14; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_15; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_16; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_17; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_18; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_19; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_20; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_21; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_22; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_23; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_24; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_25; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_26; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_27; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_28; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_29; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_30; // @[dpath.scala 141:23]
  wire [63:0] regfile__T_42_0_31; // @[dpath.scala 141:23]
  wire  alu_clock; // @[dpath.scala 271:19]
  wire  alu_reset; // @[dpath.scala 271:19]
  wire [63:0] alu_io_src1; // @[dpath.scala 271:19]
  wire [63:0] alu_io_src2; // @[dpath.scala 271:19]
  wire [3:0] alu_io_op; // @[dpath.scala 271:19]
  wire [63:0] alu_io_res; // @[dpath.scala 271:19]
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
  reg [3:0] exe_reg_ctrl_alu_fun; // @[dpath.scala 52:33]
  reg [1:0] exe_reg_ctrl_wb_sel; // @[dpath.scala 53:32]
  reg  exe_reg_ctrl_rf_wen; // @[dpath.scala 54:36]
  reg [1:0] exe_reg_ctrl_mem_fcn; // @[dpath.scala 56:38]
  reg [2:0] exe_reg_ctrl_mem_typ; // @[dpath.scala 57:38]
  reg  mem_reg_valid; // @[dpath.scala 61:30]
  reg [63:0] mem_reg_pc; // @[dpath.scala 62:23]
  reg [63:0] mem_reg_inst; // @[dpath.scala 63:25]
  reg [63:0] mem_reg_alu_out; // @[dpath.scala 64:28]
  reg [4:0] mem_reg_wbaddr; // @[dpath.scala 65:27]
  reg [4:0] mem_reg_rs1_addr; // @[dpath.scala 66:29]
  reg [4:0] mem_reg_rs2_addr; // @[dpath.scala 67:29]
  reg [63:0] mem_reg_op1_data; // @[dpath.scala 68:29]
  reg [63:0] mem_reg_op2_data; // @[dpath.scala 69:29]
  reg  mem_reg_ctrl_rf_wen; // @[dpath.scala 71:36]
  reg [1:0] mem_reg_ctrl_wb_sel; // @[dpath.scala 75:32]
  reg [63:0] mem_reg_dram_data; // @[dpath.scala 77:34]
  reg  wb_reg_valid; // @[dpath.scala 80:29]
  reg [63:0] wb_reg_pc; // @[dpath.scala 81:22]
  reg [63:0] wb_reg_inst; // @[dpath.scala 82:24]
  reg [4:0] wb_reg_wbaddr; // @[dpath.scala 83:26]
  reg [63:0] wb_reg_wbdata; // @[dpath.scala 84:26]
  reg  wb_reg_ctrl_rf_wen; // @[dpath.scala 85:35]
  wire  _T = ~io_ctl_dec_stall; // @[dpath.scala 95:9]
  wire  _T_2 = io_ctl_exe_pc_sel == 2'h0; // @[dpath.scala 102:39]
  wire [63:0] if_pc_plus4 = if_reg_pc + 64'h4; // @[dpath.scala 100:31]
  wire  _T_3 = io_ctl_exe_pc_sel == 2'h1; // @[dpath.scala 103:39]
  wire [63:0] exe_brjmp_target = exe_reg_pc + brjmp_offset; // @[dpath.scala 280:37]
  wire  _T_4 = io_ctl_exe_pc_sel == 2'h2; // @[dpath.scala 104:39]
  wire [63:0] exe_adder_out = exe_alu_op1 + brjmp_offset; // @[dpath.scala 277:36]
  wire [63:0] _T_5 = _T_4 ? exe_adder_out : 64'h4033; // @[dpath.scala 104:20]
  wire [63:0] _T_6 = _T_3 ? exe_brjmp_target : _T_5; // @[dpath.scala 103:20]
  wire [63:0] if_pc_next = _T_2 ? if_pc_plus4 : _T_6; // @[dpath.scala 102:20]
  wire  _T_10 = ~reset; // @[dpath.scala 129:9]
  wire [4:0] dec_rs1_addr = dec_reg_inst[19:15]; // @[dpath.scala 135:34]
  wire [4:0] dec_rs2_addr = dec_reg_inst[24:20]; // @[dpath.scala 136:34]
  wire [4:0] dec_wbaddr = dec_reg_inst[11:7]; // @[dpath.scala 137:32]
  wire [11:0] imm_itype = dec_reg_inst[31:20]; // @[dpath.scala 152:31]
  wire [11:0] imm_stype = {dec_reg_inst[31:25],dec_wbaddr}; // @[Cat.scala 29:58]
  wire [11:0] imm_sbtype = {dec_reg_inst[31],dec_reg_inst[7],dec_reg_inst[30:25],dec_reg_inst[11:8]}; // @[Cat.scala 29:58]
  wire [19:0] imm_utype = dec_reg_inst[31:12]; // @[dpath.scala 155:31]
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
  wire  _T_46 = io_ctl_op2_sel == 3'h0; // @[dpath.scala 168:21]
  wire  _T_47 = io_ctl_op2_sel == 3'h1; // @[dpath.scala 169:21]
  wire  _T_48 = io_ctl_op2_sel == 3'h2; // @[dpath.scala 170:21]
  wire  _T_49 = io_ctl_op2_sel == 3'h3; // @[dpath.scala 171:21]
  wire  _T_50 = io_ctl_op2_sel == 3'h4; // @[dpath.scala 172:21]
  wire  _T_51 = io_ctl_op2_sel == 3'h5; // @[dpath.scala 173:21]
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
  wire  _T_128 = mem_reg_ctrl_wb_sel == 2'h1; // @[dpath.scala 319:26]
  wire [63:0] mem_wbdata = _T_128 ? mem_reg_dram_data : mem_reg_alu_out; // @[Mux.scala 98:16]
  wire [63:0] _T_70 = _T_64 ? mem_wbdata : _T_69; // @[Mux.scala 98:16]
  wire [63:0] exe_alu_out = alu_io_res; // @[dpath.scala 177:26 dpath.scala 275:15]
  wire [63:0] dec_rs1_data = _T_60 ? exe_alu_out : _T_70; // @[Mux.scala 98:16]
  wire  _T_72 = io_ctl_op1_sel == 2'h2; // @[dpath.scala 194:21]
  wire  _T_73 = io_ctl_op1_sel == 2'h1; // @[dpath.scala 195:21]
  wire [63:0] _T_74 = _T_73 ? dec_reg_pc : dec_rs1_data; // @[Mux.scala 98:16]
  wire [63:0] dec_op1_data = _T_72 ? {{32'd0}, imm_z} : _T_74; // @[Mux.scala 98:16]
  wire  _T_76 = exe_reg_wbaddr == dec_rs2_addr; // @[dpath.scala 199:22]
  wire  _T_77 = dec_rs2_addr != 5'h0; // @[dpath.scala 199:57]
  wire  _T_78 = _T_76 & _T_77; // @[dpath.scala 199:40]
  wire  _T_79 = _T_78 & exe_reg_ctrl_rf_wen; // @[dpath.scala 199:66]
  wire  _T_81 = _T_79 & _T_46; // @[dpath.scala 199:89]
  wire  _T_82 = mem_reg_wbaddr == dec_rs2_addr; // @[dpath.scala 200:22]
  wire  _T_84 = _T_82 & _T_77; // @[dpath.scala 200:40]
  wire  _T_85 = _T_84 & mem_reg_ctrl_rf_wen; // @[dpath.scala 200:66]
  wire  _T_87 = _T_85 & _T_46; // @[dpath.scala 200:89]
  wire  _T_88 = wb_reg_wbaddr == dec_rs2_addr; // @[dpath.scala 201:21]
  wire  _T_90 = _T_88 & _T_77; // @[dpath.scala 201:40]
  wire  _T_91 = _T_90 & wb_reg_ctrl_rf_wen; // @[dpath.scala 201:66]
  wire  _T_93 = _T_91 & _T_46; // @[dpath.scala 201:89]
  wire [63:0] _T_94 = _T_93 ? wb_reg_wbdata : dec_alu_op2; // @[Mux.scala 98:16]
  wire [63:0] _T_95 = _T_87 ? mem_wbdata : _T_94; // @[Mux.scala 98:16]
  wire [63:0] dec_op2_data = _T_81 ? exe_alu_out : _T_95; // @[Mux.scala 98:16]
  wire [63:0] exe_pc_plus4 = exe_reg_pc + 64'h4; // @[dpath.scala 283:34]
  wire  _T_121 = exe_reg_ctrl_wb_sel == 2'h2; // @[dpath.scala 289:28]
  reg [63:0] _T_132; // @[dpath.scala 334:119]
  wire  _T_140 = exe_reg_ctrl_mem_typ == 3'h1; // @[dpath.scala 347:27]
  wire [63:0] _T_144 = {exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0],exe_reg_rs2_data[7:0]}; // @[Cat.scala 29:58]
  wire  _T_145 = exe_reg_ctrl_mem_typ == 3'h2; // @[dpath.scala 348:27]
  wire [63:0] _T_148 = {exe_reg_rs2_data[15:0],exe_reg_rs2_data[15:0],exe_reg_rs2_data[15:0],exe_reg_rs2_data[15:0]}; // @[Cat.scala 29:58]
  wire  _T_149 = exe_reg_ctrl_mem_typ == 3'h3; // @[dpath.scala 349:27]
  wire [63:0] _T_151 = {exe_reg_rs2_data[31:0],exe_reg_rs2_data[31:0]}; // @[Cat.scala 29:58]
  wire [63:0] _T_154 = _T_149 ? _T_151 : exe_reg_rs2_data; // @[Mux.scala 98:16]
  wire [63:0] _T_155 = _T_145 ? _T_148 : _T_154; // @[Mux.scala 98:16]
  wire [9:0] _GEN_51 = {{7'd0}, exe_reg_ctrl_mem_typ}; // @[dpath.scala 353:38]
  wire [9:0] _T_157 = _GEN_51 << exe_alu_out[2:0]; // @[dpath.scala 353:38]
  reg [4:0] _T_162; // @[dpath.scala 366:12]
  reg [63:0] _T_163; // @[dpath.scala 367:12]
  reg [4:0] _T_164; // @[dpath.scala 368:12]
  reg [63:0] _T_165; // @[dpath.scala 369:12]
  regfile regfile ( // @[dpath.scala 141:23]
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
  alu alu ( // @[dpath.scala 271:19]
    .clock(alu_clock),
    .reset(alu_reset),
    .io_src1(alu_io_src1),
    .io_src2(alu_io_src2),
    .io_op(alu_io_op),
    .io_res(alu_io_res)
  );
  assign io_dat_dec_inst = dec_reg_inst; // @[dpath.scala 340:21]
  assign io_dat_exe_br_eq = exe_alu_op1 == exe_reg_rs2_data; // @[dpath.scala 341:21]
  assign io_dat_exe_br_lt = $signed(exe_alu_op1) < $signed(exe_reg_rs2_data); // @[dpath.scala 342:21]
  assign io_dat_exe_br_ltu = exe_alu_op1 < exe_reg_rs2_data; // @[dpath.scala 343:21]
  assign io_dat_exe_br_type = exe_reg_ctrl_br_type; // @[dpath.scala 344:21]
  assign io_inst_readIO_addr = if_reg_pc; // @[dpath.scala 107:23]
  assign io_inst_readIO_en = 1'h1; // @[dpath.scala 108:21]
  assign io_data_readIO_addr = alu_io_res; // @[dpath.scala 313:24]
  assign io_data_readIO_en = exe_reg_ctrl_mem_fcn == 2'h1; // @[dpath.scala 312:24]
  assign io_data_writeIO_addr = alu_io_res; // @[dpath.scala 356:24]
  assign io_data_writeIO_data = _T_140 ? _T_144 : _T_155; // @[dpath.scala 357:24]
  assign io_data_writeIO_en = exe_reg_ctrl_mem_fcn == 2'h2; // @[dpath.scala 355:24]
  assign io_data_writeIO_mask = _T_157[7:0]; // @[dpath.scala 358:24]
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
  assign regfile_io_rs1_addr = dec_reg_inst[19:15]; // @[dpath.scala 142:23]
  assign regfile_io_rs2_addr = dec_reg_inst[24:20]; // @[dpath.scala 143:23]
  assign regfile_io_waddr = wb_reg_wbaddr; // @[dpath.scala 146:20]
  assign regfile_io_wdata = wb_reg_wbdata; // @[dpath.scala 147:20]
  assign regfile_io_wen = wb_reg_ctrl_rf_wen; // @[dpath.scala 148:20]
  assign alu_clock = clock;
  assign alu_reset = reset;
  assign alu_io_src1 = exe_alu_op1; // @[dpath.scala 273:15]
  assign alu_io_src2 = brjmp_offset; // @[dpath.scala 274:15]
  assign alu_io_op = exe_reg_ctrl_alu_fun; // @[dpath.scala 272:13]
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
  exe_reg_ctrl_alu_fun = _RAND_14[3:0];
  _RAND_15 = {1{`RANDOM}};
  exe_reg_ctrl_wb_sel = _RAND_15[1:0];
  _RAND_16 = {1{`RANDOM}};
  exe_reg_ctrl_rf_wen = _RAND_16[0:0];
  _RAND_17 = {1{`RANDOM}};
  exe_reg_ctrl_mem_fcn = _RAND_17[1:0];
  _RAND_18 = {1{`RANDOM}};
  exe_reg_ctrl_mem_typ = _RAND_18[2:0];
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
  mem_reg_rs1_addr = _RAND_24[4:0];
  _RAND_25 = {1{`RANDOM}};
  mem_reg_rs2_addr = _RAND_25[4:0];
  _RAND_26 = {2{`RANDOM}};
  mem_reg_op1_data = _RAND_26[63:0];
  _RAND_27 = {2{`RANDOM}};
  mem_reg_op2_data = _RAND_27[63:0];
  _RAND_28 = {1{`RANDOM}};
  mem_reg_ctrl_rf_wen = _RAND_28[0:0];
  _RAND_29 = {1{`RANDOM}};
  mem_reg_ctrl_wb_sel = _RAND_29[1:0];
  _RAND_30 = {2{`RANDOM}};
  mem_reg_dram_data = _RAND_30[63:0];
  _RAND_31 = {1{`RANDOM}};
  wb_reg_valid = _RAND_31[0:0];
  _RAND_32 = {2{`RANDOM}};
  wb_reg_pc = _RAND_32[63:0];
  _RAND_33 = {2{`RANDOM}};
  wb_reg_inst = _RAND_33[63:0];
  _RAND_34 = {1{`RANDOM}};
  wb_reg_wbaddr = _RAND_34[4:0];
  _RAND_35 = {2{`RANDOM}};
  wb_reg_wbdata = _RAND_35[63:0];
  _RAND_36 = {1{`RANDOM}};
  wb_reg_ctrl_rf_wen = _RAND_36[0:0];
  _RAND_37 = {2{`RANDOM}};
  _T_132 = _RAND_37[63:0];
  _RAND_38 = {1{`RANDOM}};
  _T_162 = _RAND_38[4:0];
  _RAND_39 = {2{`RANDOM}};
  _T_163 = _RAND_39[63:0];
  _RAND_40 = {1{`RANDOM}};
  _T_164 = _RAND_40[4:0];
  _RAND_41 = {2{`RANDOM}};
  _T_165 = _RAND_41[63:0];
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
        end else if (_T_60) begin
          exe_alu_op1 <= exe_alu_out;
        end else if (_T_64) begin
          if (_T_128) begin
            exe_alu_op1 <= mem_reg_dram_data;
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
        if (_T_81) begin
          brjmp_offset <= exe_alu_out;
        end else if (_T_87) begin
          if (_T_128) begin
            brjmp_offset <= mem_reg_dram_data;
          end else begin
            brjmp_offset <= mem_reg_alu_out;
          end
        end else if (_T_93) begin
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
        if (_T_79) begin
          exe_reg_rs2_data <= exe_alu_out;
        end else if (_T_85) begin
          if (_T_128) begin
            exe_reg_rs2_data <= mem_reg_dram_data;
          end else begin
            exe_reg_rs2_data <= mem_reg_alu_out;
          end
        end else if (_T_91) begin
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
      exe_reg_ctrl_mem_typ <= 3'h0;
    end else if (!(io_ctl_dec_stall)) begin
      if (_T) begin
        if (!(io_ctl_dec_kill)) begin
          exe_reg_ctrl_mem_typ <= io_ctl_mem_typ;
        end
      end
    end
    if (reset) begin
      mem_reg_valid <= 1'h0;
    end else begin
      mem_reg_valid <= exe_reg_valid;
    end
    mem_reg_pc <= exe_reg_pc;
    mem_reg_inst <= exe_reg_inst;
    if (_T_121) begin
      mem_reg_alu_out <= exe_pc_plus4;
    end else begin
      mem_reg_alu_out <= exe_alu_out;
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
    if (_T_128) begin
      wb_reg_wbdata <= mem_reg_dram_data;
    end else begin
      wb_reg_wbdata <= mem_reg_alu_out;
    end
    if (reset) begin
      wb_reg_ctrl_rf_wen <= 1'h0;
    end else begin
      wb_reg_ctrl_rf_wen <= mem_reg_ctrl_rf_wen;
    end
    _T_132 <= mem_reg_inst;
    _T_162 <= mem_reg_rs1_addr;
    _T_163 <= mem_reg_op1_data;
    _T_164 <= mem_reg_rs2_addr;
    _T_165 <= mem_reg_op2_data;
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_10) begin
          $fwrite(32'h80000002,"IF : pc=[%x] inst=[%x] if_pc_next=[%x] en=%d pc_sel=[%d] e_bj_pc=[%x]\n",if_reg_pc,io_inst_readIO_data,if_pc_next,io_inst_readIO_en,io_ctl_exe_pc_sel,exe_brjmp_target); // @[dpath.scala 129:9]
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
          $fwrite(32'h80000002,"DEC: valid = %d pc=[%x] inst=[%x] op1=[%x] alu2=[%x] op2=[%x]\n",dec_reg_valid,dec_reg_pc,dec_reg_inst,dec_op1_data,dec_alu_op2,dec_op2_data); // @[dpath.scala 263:9]
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
          $fwrite(32'h80000002,"EXE: valid = %d pc=[%x] inst=[%x] bj_target = [%x]\n",exe_reg_valid,exe_reg_pc,exe_reg_inst,exe_brjmp_target); // @[dpath.scala 307:9]
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
          $fwrite(32'h80000002,"MEM read data = [%x]\n",mem_reg_dram_data); // @[dpath.scala 315:9]
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
          $fwrite(32'h80000002,"MEM: valid = %d pc=[%x] inst=[%x] wb_sel=[%d] wbdata=[%x]\n",mem_reg_valid,mem_reg_pc,mem_reg_inst,mem_reg_ctrl_wb_sel,mem_wbdata); // @[dpath.scala 322:9]
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
          $fwrite(32'h80000002,"WB : valid = %d pc=[%x] inst=[%x], mem_wbdata=[%x], mem_reg_wbaddr=[%d]\n",wb_reg_valid,wb_reg_pc,_T_132,wb_reg_wbdata,wb_reg_wbaddr); // @[dpath.scala 334:9]
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
          $fwrite(32'h80000002,"store:addr = [%x] en=%d data = [%x] mask = %b\n ",io_data_writeIO_addr,io_data_writeIO_en,io_data_writeIO_data,io_data_writeIO_mask); // @[dpath.scala 359:9]
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
          $fwrite(32'h80000002,"pc=[%x] W[r%d=%x][%d] Op1=[r%d][%x] Op2=[r%d][%x] inst=[%x]\n\n",wb_reg_pc,wb_reg_wbaddr,wb_reg_wbdata,wb_reg_ctrl_rf_wen,_T_162,_T_163,_T_164,_T_165,wb_reg_inst); // @[dpath.scala 361:9]
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
  wire [3:0] cpath_io_ctl_alu_fun; // @[core.scala 14:21]
  wire [1:0] cpath_io_ctl_wb_sel; // @[core.scala 14:21]
  wire  cpath_io_ctl_rf_wen; // @[core.scala 14:21]
  wire [1:0] cpath_io_ctl_mem_fcn; // @[core.scala 14:21]
  wire [2:0] cpath_io_ctl_mem_typ; // @[core.scala 14:21]
  wire  dpath_clock; // @[core.scala 15:21]
  wire  dpath_reset; // @[core.scala 15:21]
  wire  dpath_io_ctl_dec_stall; // @[core.scala 15:21]
  wire [1:0] dpath_io_ctl_exe_pc_sel; // @[core.scala 15:21]
  wire [3:0] dpath_io_ctl_br_type; // @[core.scala 15:21]
  wire  dpath_io_ctl_if_kill; // @[core.scala 15:21]
  wire  dpath_io_ctl_dec_kill; // @[core.scala 15:21]
  wire [1:0] dpath_io_ctl_op1_sel; // @[core.scala 15:21]
  wire [2:0] dpath_io_ctl_op2_sel; // @[core.scala 15:21]
  wire [3:0] dpath_io_ctl_alu_fun; // @[core.scala 15:21]
  wire [1:0] dpath_io_ctl_wb_sel; // @[core.scala 15:21]
  wire  dpath_io_ctl_rf_wen; // @[core.scala 15:21]
  wire [1:0] dpath_io_ctl_mem_fcn; // @[core.scala 15:21]
  wire [2:0] dpath_io_ctl_mem_typ; // @[core.scala 15:21]
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
    .io_ctl_mem_typ(cpath_io_ctl_mem_typ)
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
