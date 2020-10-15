module cpath(
  input  [63:0] io_dat_dec_inst,
  input         io_dat_exe_br_eq,
  input         io_dat_exe_br_lt,
  input         io_dat_exe_br_ltu,
  input  [3:0]  io_dat_exe_br_type,
  output [1:0]  io_ctl_exe_pc_sel,
  output [3:0]  io_ctl_br_type,
  output [1:0]  io_ctl_op1_sel,
  output [2:0]  io_ctl_op2_sel,
  output [3:0]  io_ctl_alu_fun,
  output [1:0]  io_ctl_wb_sel,
  output        io_ctl_rf_wen
);
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
  wire  _T_578 = io_dat_exe_br_type == 4'h0; // @[cpath.scala 102:49]
  wire  _T_579 = io_dat_exe_br_type == 4'h1; // @[cpath.scala 103:49]
  wire  _T_580 = ~io_dat_exe_br_eq; // @[cpath.scala 103:65]
  wire [1:0] _T_581 = _T_580 ? 2'h1 : 2'h0; // @[cpath.scala 103:64]
  wire  _T_582 = io_dat_exe_br_type == 4'h2; // @[cpath.scala 104:49]
  wire [1:0] _T_583 = io_dat_exe_br_eq ? 2'h1 : 2'h0; // @[cpath.scala 104:64]
  wire  _T_584 = io_dat_exe_br_type == 4'h3; // @[cpath.scala 105:49]
  wire  _T_585 = ~io_dat_exe_br_lt; // @[cpath.scala 105:65]
  wire [1:0] _T_586 = _T_585 ? 2'h1 : 2'h0; // @[cpath.scala 105:64]
  wire  _T_587 = io_dat_exe_br_type == 4'h4; // @[cpath.scala 106:49]
  wire  _T_588 = ~io_dat_exe_br_ltu; // @[cpath.scala 106:65]
  wire [1:0] _T_589 = _T_588 ? 2'h1 : 2'h0; // @[cpath.scala 106:64]
  wire  _T_590 = io_dat_exe_br_type == 4'h5; // @[cpath.scala 107:49]
  wire [1:0] _T_591 = io_dat_exe_br_lt ? 2'h1 : 2'h0; // @[cpath.scala 107:64]
  wire  _T_592 = io_dat_exe_br_type == 4'h6; // @[cpath.scala 108:49]
  wire [1:0] _T_593 = io_dat_exe_br_ltu ? 2'h1 : 2'h0; // @[cpath.scala 108:64]
  wire  _T_594 = io_dat_exe_br_type == 4'h7; // @[cpath.scala 109:49]
  wire  _T_595 = io_dat_exe_br_type == 4'h8; // @[cpath.scala 110:49]
  wire [1:0] _T_596 = _T_595 ? 2'h2 : 2'h0; // @[cpath.scala 110:29]
  wire [1:0] _T_597 = _T_594 ? 2'h1 : _T_596; // @[cpath.scala 109:29]
  wire [1:0] _T_598 = _T_592 ? _T_593 : _T_597; // @[cpath.scala 108:29]
  wire [1:0] _T_599 = _T_590 ? _T_591 : _T_598; // @[cpath.scala 107:29]
  wire [1:0] _T_600 = _T_587 ? _T_589 : _T_599; // @[cpath.scala 106:29]
  wire [1:0] _T_601 = _T_584 ? _T_586 : _T_600; // @[cpath.scala 105:29]
  wire [1:0] _T_602 = _T_582 ? _T_583 : _T_601; // @[cpath.scala 104:29]
  wire [1:0] _T_603 = _T_579 ? _T_581 : _T_602; // @[cpath.scala 103:29]
  assign io_ctl_exe_pc_sel = _T_578 ? 2'h0 : _T_603; // @[cpath.scala 119:22]
  assign io_ctl_br_type = _T_1 ? 4'h0 : _T_145; // @[cpath.scala 120:22]
  assign io_ctl_op1_sel = _T_1 ? 2'h0 : _T_181; // @[cpath.scala 123:22]
  assign io_ctl_op2_sel = _T_1 ? 3'h1 : _T_217; // @[cpath.scala 124:22]
  assign io_ctl_alu_fun = _T_1 ? 4'h0 : _T_325; // @[cpath.scala 125:22]
  assign io_ctl_wb_sel = _T_1 ? 2'h1 : _T_361; // @[cpath.scala 126:22]
  assign io_ctl_rf_wen = _T_1 | _T_397; // @[cpath.scala 127:22]
endmodule
module REGFILE(
  input         clock,
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
  reg [63:0] regfile [0:31]; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_5_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_5_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_8_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_8_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_10_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_10_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_11_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_11_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_12_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_12_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_13_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_13_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_14_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_14_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_15_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_15_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_16_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_16_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_17_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_17_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_18_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_18_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_19_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_19_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_20_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_20_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_21_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_21_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_22_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_22_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_23_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_23_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_24_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_24_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_25_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_25_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_26_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_26_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_27_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_27_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_28_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_28_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_29_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_29_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_30_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_30_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_31_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_31_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_32_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_32_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_33_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_33_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_34_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_34_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_35_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_35_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_36_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_36_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_37_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_37_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_38_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_38_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_39_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_39_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_40_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_40_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_41_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_41_addr; // @[regfile.scala 25:21]
  wire [63:0] regfile__T_3_data; // @[regfile.scala 25:21]
  wire [4:0] regfile__T_3_addr; // @[regfile.scala 25:21]
  wire  regfile__T_3_mask; // @[regfile.scala 25:21]
  wire  regfile__T_3_en; // @[regfile.scala 25:21]
  wire  _T_1 = io_waddr != 5'h0; // @[regfile.scala 27:39]
  wire  _T_4 = io_rs1_addr != 5'h0; // @[regfile.scala 32:36]
  wire  _T_7 = io_rs2_addr != 5'h0; // @[regfile.scala 33:36]
  wire [63:0] _T_42_0 = regfile__T_10_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_1 = regfile__T_11_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_2 = regfile__T_12_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_3 = regfile__T_13_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_4 = regfile__T_14_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_5 = regfile__T_15_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_6 = regfile__T_16_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_7 = regfile__T_17_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_8 = regfile__T_18_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_9 = regfile__T_19_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_10 = regfile__T_20_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_11 = regfile__T_21_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_12 = regfile__T_22_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_13 = regfile__T_23_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_14 = regfile__T_24_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_15 = regfile__T_25_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_16 = regfile__T_26_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_17 = regfile__T_27_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_18 = regfile__T_28_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_19 = regfile__T_29_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_20 = regfile__T_30_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_21 = regfile__T_31_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_22 = regfile__T_32_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_23 = regfile__T_33_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_24 = regfile__T_34_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_25 = regfile__T_35_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_26 = regfile__T_36_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_27 = regfile__T_37_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_28 = regfile__T_38_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_29 = regfile__T_39_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_30 = regfile__T_40_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  wire [63:0] _T_42_31 = regfile__T_41_data; // @[regfile.scala 35:33 regfile.scala 35:33]
  assign regfile__T_5_addr = io_rs1_addr;
  assign regfile__T_5_data = regfile[regfile__T_5_addr]; // @[regfile.scala 25:21]
  assign regfile__T_8_addr = io_rs2_addr;
  assign regfile__T_8_data = regfile[regfile__T_8_addr]; // @[regfile.scala 25:21]
  assign regfile__T_10_addr = 5'h0;
  assign regfile__T_10_data = regfile[regfile__T_10_addr]; // @[regfile.scala 25:21]
  assign regfile__T_11_addr = 5'h1;
  assign regfile__T_11_data = regfile[regfile__T_11_addr]; // @[regfile.scala 25:21]
  assign regfile__T_12_addr = 5'h2;
  assign regfile__T_12_data = regfile[regfile__T_12_addr]; // @[regfile.scala 25:21]
  assign regfile__T_13_addr = 5'h3;
  assign regfile__T_13_data = regfile[regfile__T_13_addr]; // @[regfile.scala 25:21]
  assign regfile__T_14_addr = 5'h4;
  assign regfile__T_14_data = regfile[regfile__T_14_addr]; // @[regfile.scala 25:21]
  assign regfile__T_15_addr = 5'h5;
  assign regfile__T_15_data = regfile[regfile__T_15_addr]; // @[regfile.scala 25:21]
  assign regfile__T_16_addr = 5'h6;
  assign regfile__T_16_data = regfile[regfile__T_16_addr]; // @[regfile.scala 25:21]
  assign regfile__T_17_addr = 5'h7;
  assign regfile__T_17_data = regfile[regfile__T_17_addr]; // @[regfile.scala 25:21]
  assign regfile__T_18_addr = 5'h8;
  assign regfile__T_18_data = regfile[regfile__T_18_addr]; // @[regfile.scala 25:21]
  assign regfile__T_19_addr = 5'h9;
  assign regfile__T_19_data = regfile[regfile__T_19_addr]; // @[regfile.scala 25:21]
  assign regfile__T_20_addr = 5'ha;
  assign regfile__T_20_data = regfile[regfile__T_20_addr]; // @[regfile.scala 25:21]
  assign regfile__T_21_addr = 5'hb;
  assign regfile__T_21_data = regfile[regfile__T_21_addr]; // @[regfile.scala 25:21]
  assign regfile__T_22_addr = 5'hc;
  assign regfile__T_22_data = regfile[regfile__T_22_addr]; // @[regfile.scala 25:21]
  assign regfile__T_23_addr = 5'hd;
  assign regfile__T_23_data = regfile[regfile__T_23_addr]; // @[regfile.scala 25:21]
  assign regfile__T_24_addr = 5'he;
  assign regfile__T_24_data = regfile[regfile__T_24_addr]; // @[regfile.scala 25:21]
  assign regfile__T_25_addr = 5'hf;
  assign regfile__T_25_data = regfile[regfile__T_25_addr]; // @[regfile.scala 25:21]
  assign regfile__T_26_addr = 5'h10;
  assign regfile__T_26_data = regfile[regfile__T_26_addr]; // @[regfile.scala 25:21]
  assign regfile__T_27_addr = 5'h11;
  assign regfile__T_27_data = regfile[regfile__T_27_addr]; // @[regfile.scala 25:21]
  assign regfile__T_28_addr = 5'h12;
  assign regfile__T_28_data = regfile[regfile__T_28_addr]; // @[regfile.scala 25:21]
  assign regfile__T_29_addr = 5'h13;
  assign regfile__T_29_data = regfile[regfile__T_29_addr]; // @[regfile.scala 25:21]
  assign regfile__T_30_addr = 5'h14;
  assign regfile__T_30_data = regfile[regfile__T_30_addr]; // @[regfile.scala 25:21]
  assign regfile__T_31_addr = 5'h15;
  assign regfile__T_31_data = regfile[regfile__T_31_addr]; // @[regfile.scala 25:21]
  assign regfile__T_32_addr = 5'h16;
  assign regfile__T_32_data = regfile[regfile__T_32_addr]; // @[regfile.scala 25:21]
  assign regfile__T_33_addr = 5'h17;
  assign regfile__T_33_data = regfile[regfile__T_33_addr]; // @[regfile.scala 25:21]
  assign regfile__T_34_addr = 5'h18;
  assign regfile__T_34_data = regfile[regfile__T_34_addr]; // @[regfile.scala 25:21]
  assign regfile__T_35_addr = 5'h19;
  assign regfile__T_35_data = regfile[regfile__T_35_addr]; // @[regfile.scala 25:21]
  assign regfile__T_36_addr = 5'h1a;
  assign regfile__T_36_data = regfile[regfile__T_36_addr]; // @[regfile.scala 25:21]
  assign regfile__T_37_addr = 5'h1b;
  assign regfile__T_37_data = regfile[regfile__T_37_addr]; // @[regfile.scala 25:21]
  assign regfile__T_38_addr = 5'h1c;
  assign regfile__T_38_data = regfile[regfile__T_38_addr]; // @[regfile.scala 25:21]
  assign regfile__T_39_addr = 5'h1d;
  assign regfile__T_39_data = regfile[regfile__T_39_addr]; // @[regfile.scala 25:21]
  assign regfile__T_40_addr = 5'h1e;
  assign regfile__T_40_data = regfile[regfile__T_40_addr]; // @[regfile.scala 25:21]
  assign regfile__T_41_addr = 5'h1f;
  assign regfile__T_41_data = regfile[regfile__T_41_addr]; // @[regfile.scala 25:21]
  assign regfile__T_3_data = io_wdata;
  assign regfile__T_3_addr = io_waddr;
  assign regfile__T_3_mask = 1'h1;
  assign regfile__T_3_en = io_wen & _T_1;
  assign io_rs1_data = _T_4 ? regfile__T_5_data : 64'h0; // @[regfile.scala 32:16]
  assign io_rs2_data = _T_7 ? regfile__T_8_data : 64'h0; // @[regfile.scala 33:16]
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
    if(regfile__T_3_en & regfile__T_3_mask) begin
      regfile[regfile__T_3_addr] <= regfile__T_3_data; // @[regfile.scala 25:21]
    end
  end
endmodule
module alu(
  input  [63:0] io_src1,
  input  [63:0] io_src2,
  input  [3:0]  io_op,
  output [63:0] io_res
);
  wire [5:0] shamt = io_src2[5:0]; // @[Alu.scala 17:24]
  wire  _T = io_op == 4'h0; // @[Alu.scala 20:16]
  wire [63:0] _T_2 = io_src1 + io_src2; // @[Alu.scala 20:39]
  wire  _T_3 = io_op == 4'h1; // @[Alu.scala 21:16]
  wire [63:0] _T_5 = io_src1 - io_src2; // @[Alu.scala 21:39]
  wire  _T_6 = io_op == 4'h5; // @[Alu.scala 22:16]
  wire [63:0] _T_7 = io_src1 & io_src2; // @[Alu.scala 22:39]
  wire  _T_8 = io_op == 4'h6; // @[Alu.scala 23:16]
  wire [63:0] _T_9 = io_src1 | io_src2; // @[Alu.scala 23:39]
  wire  _T_10 = io_op == 4'h7; // @[Alu.scala 24:16]
  wire [63:0] _T_11 = io_src1 ^ io_src2; // @[Alu.scala 24:39]
  wire  _T_12 = io_op == 4'h8; // @[Alu.scala 25:16]
  wire  _T_15 = $signed(io_src1) < $signed(io_src2); // @[Alu.scala 25:48]
  wire  _T_16 = io_op == 4'h9; // @[Alu.scala 26:16]
  wire  _T_17 = io_src1 < io_src2; // @[Alu.scala 26:39]
  wire  _T_18 = io_op == 4'h2; // @[Alu.scala 27:16]
  wire [126:0] _GEN_0 = {{63'd0}, io_src1}; // @[Alu.scala 27:40]
  wire [126:0] _T_19 = _GEN_0 << shamt; // @[Alu.scala 27:40]
  wire  _T_21 = io_op == 4'h4; // @[Alu.scala 28:16]
  wire [63:0] _T_24 = $signed(io_src1) >>> shamt; // @[Alu.scala 28:64]
  wire  _T_25 = io_op == 4'h3; // @[Alu.scala 29:16]
  wire [63:0] _T_26 = io_src1 >> shamt; // @[Alu.scala 29:39]
  wire  _T_27 = io_op == 4'ha; // @[Alu.scala 30:16]
  wire [63:0] _T_28 = _T_27 ? io_src1 : 64'h0; // @[Mux.scala 98:16]
  wire [63:0] _T_29 = _T_25 ? _T_26 : _T_28; // @[Mux.scala 98:16]
  wire [63:0] _T_30 = _T_21 ? _T_24 : _T_29; // @[Mux.scala 98:16]
  wire [63:0] _T_31 = _T_18 ? _T_19[63:0] : _T_30; // @[Mux.scala 98:16]
  wire [63:0] _T_32 = _T_16 ? {{63'd0}, _T_17} : _T_31; // @[Mux.scala 98:16]
  wire [63:0] _T_33 = _T_12 ? {{63'd0}, _T_15} : _T_32; // @[Mux.scala 98:16]
  wire [63:0] _T_34 = _T_10 ? _T_11 : _T_33; // @[Mux.scala 98:16]
  wire [63:0] _T_35 = _T_8 ? _T_9 : _T_34; // @[Mux.scala 98:16]
  wire [63:0] _T_36 = _T_6 ? _T_7 : _T_35; // @[Mux.scala 98:16]
  wire [63:0] _T_37 = _T_3 ? _T_5 : _T_36; // @[Mux.scala 98:16]
  assign io_res = _T ? _T_2 : _T_37; // @[Alu.scala 19:12]
endmodule
module dpath(
  input         clock,
  input         reset,
  output [63:0] io_instReadIO_addr,
  input  [63:0] io_instReadIO_data,
  output [63:0] io_dataWriteIO_addr,
  output [63:0] io_dataWriteIO_data,
  input  [1:0]  io_ctl_exe_pc_sel,
  input  [3:0]  io_ctl_br_type,
  input  [1:0]  io_ctl_op1_sel,
  input  [2:0]  io_ctl_op2_sel,
  input  [3:0]  io_ctl_alu_fun,
  input  [1:0]  io_ctl_wb_sel,
  input         io_ctl_rf_wen,
  output [63:0] io_dat_dec_inst,
  output        io_dat_exe_br_eq,
  output        io_dat_exe_br_lt,
  output        io_dat_exe_br_ltu,
  output [3:0]  io_dat_exe_br_type,
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
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_0;
  reg [63:0] _RAND_1;
  reg [63:0] _RAND_2;
  reg [63:0] _RAND_3;
  reg [63:0] _RAND_4;
  reg [31:0] _RAND_5;
  reg [63:0] _RAND_6;
  reg [63:0] _RAND_7;
  reg [63:0] _RAND_8;
  reg [31:0] _RAND_9;
  reg [31:0] _RAND_10;
  reg [31:0] _RAND_11;
  reg [31:0] _RAND_12;
  reg [63:0] _RAND_13;
  reg [63:0] _RAND_14;
  reg [63:0] _RAND_15;
  reg [31:0] _RAND_16;
  reg [63:0] _RAND_17;
  reg [31:0] _RAND_18;
  reg [31:0] _RAND_19;
  reg [31:0] _RAND_20;
  reg [63:0] _RAND_21;
  reg [31:0] _RAND_22;
  reg [63:0] _RAND_23;
  reg [63:0] _RAND_24;
`endif // RANDOMIZE_REG_INIT
  wire  regfile_clock; // @[dpath.scala 132:23]
  wire [4:0] regfile_io_rs1_addr; // @[dpath.scala 132:23]
  wire [63:0] regfile_io_rs1_data; // @[dpath.scala 132:23]
  wire [4:0] regfile_io_rs2_addr; // @[dpath.scala 132:23]
  wire [63:0] regfile_io_rs2_data; // @[dpath.scala 132:23]
  wire [4:0] regfile_io_waddr; // @[dpath.scala 132:23]
  wire [63:0] regfile_io_wdata; // @[dpath.scala 132:23]
  wire  regfile_io_wen; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_0; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_1; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_2; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_3; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_4; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_5; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_6; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_7; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_8; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_9; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_10; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_11; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_12; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_13; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_14; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_15; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_16; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_17; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_18; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_19; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_20; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_21; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_22; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_23; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_24; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_25; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_26; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_27; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_28; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_29; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_30; // @[dpath.scala 132:23]
  wire [63:0] regfile__T_42_0_31; // @[dpath.scala 132:23]
  wire [63:0] alu_io_src1; // @[dpath.scala 216:19]
  wire [63:0] alu_io_src2; // @[dpath.scala 216:19]
  wire [3:0] alu_io_op; // @[dpath.scala 216:19]
  wire [63:0] alu_io_res; // @[dpath.scala 216:19]
  reg [31:0] if_reg_pc; // @[dpath.scala 44:38]
  reg [63:0] dec_reg_inst; // @[dpath.scala 48:38]
  reg [63:0] dec_reg_pc; // @[dpath.scala 49:38]
  reg [63:0] exe_reg_inst; // @[dpath.scala 53:38]
  reg [63:0] exe_reg_pc; // @[dpath.scala 54:38]
  reg [4:0] exe_reg_wbaddr; // @[dpath.scala 55:34]
  reg [63:0] exe_alu_op1; // @[dpath.scala 58:34]
  reg [63:0] brjmp_offset; // @[dpath.scala 59:34]
  reg [63:0] exe_reg_rs2_data; // @[dpath.scala 60:34]
  reg [3:0] exe_reg_ctrl_br_type; // @[dpath.scala 61:38]
  reg [3:0] exe_reg_ctrl_alu_fun; // @[dpath.scala 63:34]
  reg [1:0] exe_reg_ctrl_wb_sel; // @[dpath.scala 64:34]
  reg  exe_reg_ctrl_rf_wen; // @[dpath.scala 65:38]
  reg [63:0] mem_reg_pc; // @[dpath.scala 73:34]
  reg [63:0] mem_reg_inst; // @[dpath.scala 74:34]
  reg [63:0] mem_reg_alu_out; // @[dpath.scala 75:34]
  reg [4:0] mem_reg_wbaddr; // @[dpath.scala 76:34]
  reg [63:0] mem_reg_rs2_data; // @[dpath.scala 81:34]
  reg  mem_reg_ctrl_rf_wen; // @[dpath.scala 82:38]
  reg [1:0] mem_reg_ctrl_wb_sel; // @[dpath.scala 86:34]
  reg [4:0] wb_reg_wbaddr; // @[dpath.scala 91:34]
  reg [63:0] wb_reg_wbdata; // @[dpath.scala 92:34]
  reg  wb_reg_ctrl_rf_wen; // @[dpath.scala 93:38]
  wire [63:0] _GEN_0 = {{32'd0}, if_reg_pc}; // @[dpath.scala 103:32]
  wire [63:0] if_pc_plus4 = _GEN_0 + 64'h4; // @[dpath.scala 103:32]
  wire  _T_1 = io_ctl_exe_pc_sel == 2'h0; // @[dpath.scala 106:39]
  wire  _T_2 = io_ctl_exe_pc_sel == 2'h1; // @[dpath.scala 107:39]
  wire  _T_3 = io_ctl_exe_pc_sel == 2'h2; // @[dpath.scala 108:39]
  wire [63:0] exe_adder_out = exe_alu_op1 + brjmp_offset; // @[dpath.scala 221:36]
  wire [63:0] _T_4 = _T_3 ? exe_adder_out : 64'h4033; // @[dpath.scala 108:20]
  wire [63:0] exe_brjmp_target = exe_reg_pc + brjmp_offset; // @[dpath.scala 225:37]
  wire [63:0] _T_5 = _T_2 ? exe_brjmp_target : _T_4; // @[dpath.scala 107:20]
  wire [63:0] if_pc_next = _T_1 ? if_pc_plus4 : _T_5; // @[dpath.scala 106:20]
  wire [4:0] dec_rs1_addr = dec_reg_inst[19:15]; // @[dpath.scala 126:34]
  wire [4:0] dec_wbaddr = dec_reg_inst[11:7]; // @[dpath.scala 128:34]
  wire [11:0] imm_itype = dec_reg_inst[31:20]; // @[dpath.scala 143:32]
  wire [11:0] imm_stype = {dec_reg_inst[31:25],dec_wbaddr}; // @[Cat.scala 29:58]
  wire [11:0] imm_sbtype = {dec_reg_inst[31],dec_reg_inst[7],dec_reg_inst[30:25],dec_reg_inst[11:8]}; // @[Cat.scala 29:58]
  wire [19:0] imm_utype = dec_reg_inst[31:12]; // @[dpath.scala 146:32]
  wire [19:0] imm_ujtype = {dec_reg_inst[31],dec_reg_inst[19:12],dec_reg_inst[20],dec_reg_inst[30:21]}; // @[Cat.scala 29:58]
  wire [31:0] imm_z = {27'h0,dec_rs1_addr}; // @[Cat.scala 29:58]
  wire [51:0] _T_25 = imm_itype[11] ? 52'hfffffffffffff : 52'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_itype_sext = {_T_25,imm_itype}; // @[Cat.scala 29:58]
  wire [51:0] _T_28 = imm_stype[11] ? 52'hfffffffffffff : 52'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_stype_sext = {_T_28,dec_reg_inst[31:25],dec_wbaddr}; // @[Cat.scala 29:58]
  wire [50:0] _T_31 = imm_sbtype[11] ? 51'h7ffffffffffff : 51'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_sbtype_sext = {_T_31,dec_reg_inst[31],dec_reg_inst[7],dec_reg_inst[30:25],dec_reg_inst[11:8],1'h0}; // @[Cat.scala 29:58]
  wire [31:0] _T_35 = imm_utype[19] ? 32'hffffffff : 32'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_utype_sext = {_T_35,imm_utype,12'h0}; // @[Cat.scala 29:58]
  wire [42:0] _T_40 = imm_ujtype[19] ? 43'h7ffffffffff : 43'h0; // @[Bitwise.scala 72:12]
  wire [63:0] imm_ujtype_sext = {_T_40,dec_reg_inst[31],dec_reg_inst[19:12],dec_reg_inst[20],dec_reg_inst[30:21],1'h0}; // @[Cat.scala 29:58]
  wire  _T_42 = io_ctl_op2_sel == 3'h0; // @[dpath.scala 161:32]
  wire  _T_43 = io_ctl_op2_sel == 3'h1; // @[dpath.scala 162:32]
  wire  _T_44 = io_ctl_op2_sel == 3'h2; // @[dpath.scala 163:32]
  wire  _T_45 = io_ctl_op2_sel == 3'h3; // @[dpath.scala 164:32]
  wire  _T_46 = io_ctl_op2_sel == 3'h4; // @[dpath.scala 165:32]
  wire  _T_47 = io_ctl_op2_sel == 3'h5; // @[dpath.scala 166:32]
  wire  _T_53 = io_ctl_op1_sel == 2'h2; // @[dpath.scala 182:22]
  wire  _T_54 = io_ctl_op1_sel == 2'h1; // @[dpath.scala 183:22]
  wire  _T_62 = ~reset; // @[dpath.scala 246:9]
  reg [63:0] _T_71; // @[dpath.scala 269:45]
  reg [63:0] _T_72; // @[dpath.scala 269:66]
  wire [63:0] exe_alu_out = alu_io_res; // @[dpath.scala 171:26 dpath.scala 220:17]
  REGFILE regfile ( // @[dpath.scala 132:23]
    .clock(regfile_clock),
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
  alu alu ( // @[dpath.scala 216:19]
    .io_src1(alu_io_src1),
    .io_src2(alu_io_src2),
    .io_op(alu_io_op),
    .io_res(alu_io_res)
  );
  assign io_instReadIO_addr = {{32'd0}, if_reg_pc}; // @[dpath.scala 114:22]
  assign io_dataWriteIO_addr = mem_reg_alu_out; // @[dpath.scala 283:25]
  assign io_dataWriteIO_data = mem_reg_rs2_data; // @[dpath.scala 284:25]
  assign io_dat_dec_inst = dec_reg_inst; // @[dpath.scala 275:22]
  assign io_dat_exe_br_eq = exe_alu_op1 == exe_reg_rs2_data; // @[dpath.scala 276:22]
  assign io_dat_exe_br_lt = $signed(exe_alu_op1) < $signed(exe_reg_rs2_data); // @[dpath.scala 277:22]
  assign io_dat_exe_br_ltu = exe_alu_op1 < exe_reg_rs2_data; // @[dpath.scala 278:22]
  assign io_dat_exe_br_type = exe_reg_ctrl_br_type; // @[dpath.scala 279:22]
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
  assign regfile_clock = clock;
  assign regfile_io_rs1_addr = dec_reg_inst[19:15]; // @[dpath.scala 133:23]
  assign regfile_io_rs2_addr = dec_reg_inst[24:20]; // @[dpath.scala 134:23]
  assign regfile_io_waddr = wb_reg_wbaddr; // @[dpath.scala 137:20]
  assign regfile_io_wdata = wb_reg_wbdata; // @[dpath.scala 138:20]
  assign regfile_io_wen = wb_reg_ctrl_rf_wen; // @[dpath.scala 139:20]
  assign alu_io_src1 = exe_alu_op1; // @[dpath.scala 218:17]
  assign alu_io_src2 = brjmp_offset; // @[dpath.scala 219:17]
  assign alu_io_op = exe_reg_ctrl_alu_fun; // @[dpath.scala 217:13]
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
  if_reg_pc = _RAND_0[31:0];
  _RAND_1 = {2{`RANDOM}};
  dec_reg_inst = _RAND_1[63:0];
  _RAND_2 = {2{`RANDOM}};
  dec_reg_pc = _RAND_2[63:0];
  _RAND_3 = {2{`RANDOM}};
  exe_reg_inst = _RAND_3[63:0];
  _RAND_4 = {2{`RANDOM}};
  exe_reg_pc = _RAND_4[63:0];
  _RAND_5 = {1{`RANDOM}};
  exe_reg_wbaddr = _RAND_5[4:0];
  _RAND_6 = {2{`RANDOM}};
  exe_alu_op1 = _RAND_6[63:0];
  _RAND_7 = {2{`RANDOM}};
  brjmp_offset = _RAND_7[63:0];
  _RAND_8 = {2{`RANDOM}};
  exe_reg_rs2_data = _RAND_8[63:0];
  _RAND_9 = {1{`RANDOM}};
  exe_reg_ctrl_br_type = _RAND_9[3:0];
  _RAND_10 = {1{`RANDOM}};
  exe_reg_ctrl_alu_fun = _RAND_10[3:0];
  _RAND_11 = {1{`RANDOM}};
  exe_reg_ctrl_wb_sel = _RAND_11[1:0];
  _RAND_12 = {1{`RANDOM}};
  exe_reg_ctrl_rf_wen = _RAND_12[0:0];
  _RAND_13 = {2{`RANDOM}};
  mem_reg_pc = _RAND_13[63:0];
  _RAND_14 = {2{`RANDOM}};
  mem_reg_inst = _RAND_14[63:0];
  _RAND_15 = {2{`RANDOM}};
  mem_reg_alu_out = _RAND_15[63:0];
  _RAND_16 = {1{`RANDOM}};
  mem_reg_wbaddr = _RAND_16[4:0];
  _RAND_17 = {2{`RANDOM}};
  mem_reg_rs2_data = _RAND_17[63:0];
  _RAND_18 = {1{`RANDOM}};
  mem_reg_ctrl_rf_wen = _RAND_18[0:0];
  _RAND_19 = {1{`RANDOM}};
  mem_reg_ctrl_wb_sel = _RAND_19[1:0];
  _RAND_20 = {1{`RANDOM}};
  wb_reg_wbaddr = _RAND_20[4:0];
  _RAND_21 = {2{`RANDOM}};
  wb_reg_wbdata = _RAND_21[63:0];
  _RAND_22 = {1{`RANDOM}};
  wb_reg_ctrl_rf_wen = _RAND_22[0:0];
  _RAND_23 = {2{`RANDOM}};
  _T_71 = _RAND_23[63:0];
  _RAND_24 = {2{`RANDOM}};
  _T_72 = _RAND_24[63:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
  always @(posedge clock) begin
    if (reset) begin
      if_reg_pc <= 32'h80000000;
    end else begin
      if_reg_pc <= if_pc_next[31:0];
    end
    if (reset) begin
      dec_reg_inst <= 64'h4033;
    end else begin
      dec_reg_inst <= io_instReadIO_data;
    end
    if (reset) begin
      dec_reg_pc <= 64'h0;
    end else begin
      dec_reg_pc <= {{32'd0}, if_reg_pc};
    end
    if (reset) begin
      exe_reg_inst <= 64'h4033;
    end else begin
      exe_reg_inst <= dec_reg_inst;
    end
    if (reset) begin
      exe_reg_pc <= 64'h0;
    end else begin
      exe_reg_pc <= dec_reg_pc;
    end
    exe_reg_wbaddr <= dec_reg_inst[11:7];
    if (_T_53) begin
      exe_alu_op1 <= {{32'd0}, imm_z};
    end else if (_T_54) begin
      exe_alu_op1 <= dec_reg_pc;
    end else begin
      exe_alu_op1 <= regfile_io_rs1_data;
    end
    if (_T_42) begin
      brjmp_offset <= regfile_io_rs2_data;
    end else if (_T_43) begin
      brjmp_offset <= imm_itype_sext;
    end else if (_T_44) begin
      brjmp_offset <= imm_stype_sext;
    end else if (_T_45) begin
      brjmp_offset <= imm_sbtype_sext;
    end else if (_T_46) begin
      brjmp_offset <= imm_utype_sext;
    end else if (_T_47) begin
      brjmp_offset <= imm_ujtype_sext;
    end else begin
      brjmp_offset <= 64'h0;
    end
    exe_reg_rs2_data <= regfile_io_rs2_data;
    if (reset) begin
      exe_reg_ctrl_br_type <= 4'h0;
    end else begin
      exe_reg_ctrl_br_type <= io_ctl_br_type;
    end
    exe_reg_ctrl_alu_fun <= io_ctl_alu_fun;
    exe_reg_ctrl_wb_sel <= io_ctl_wb_sel;
    if (reset) begin
      exe_reg_ctrl_rf_wen <= 1'h0;
    end else begin
      exe_reg_ctrl_rf_wen <= io_ctl_rf_wen;
    end
    mem_reg_pc <= exe_reg_pc;
    mem_reg_inst <= exe_reg_inst;
    mem_reg_alu_out <= alu_io_res;
    mem_reg_wbaddr <= exe_reg_wbaddr;
    mem_reg_rs2_data <= exe_reg_rs2_data;
    if (reset) begin
      mem_reg_ctrl_rf_wen <= 1'h0;
    end else begin
      mem_reg_ctrl_rf_wen <= exe_reg_ctrl_rf_wen;
    end
    mem_reg_ctrl_wb_sel <= exe_reg_ctrl_wb_sel;
    wb_reg_wbaddr <= mem_reg_wbaddr;
    wb_reg_wbdata <= mem_reg_alu_out;
    if (reset) begin
      wb_reg_ctrl_rf_wen <= 1'h0;
    end else begin
      wb_reg_ctrl_rf_wen <= mem_reg_ctrl_rf_wen;
    end
    _T_71 <= mem_reg_pc;
    _T_72 <= mem_reg_inst;
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_62) begin
          $fwrite(32'h80000002,"EXE: alu_op=[%x] alu_out=[%x] \n",alu_io_op,exe_alu_out); // @[dpath.scala 246:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_62) begin
          $fwrite(32'h80000002,"EXE: pc=[%x] inst=[%x] \n",exe_reg_pc,exe_reg_inst); // @[dpath.scala 247:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_62) begin
          $fwrite(32'h80000002,"MEM: pc=[%x] inst=[%x] wb_sel=[%d] wbdata=[%x]\n",mem_reg_pc,mem_reg_inst,mem_reg_ctrl_wb_sel,mem_reg_alu_out); // @[dpath.scala 259:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
    `ifndef SYNTHESIS
    `ifdef PRINTF_COND
      if (`PRINTF_COND) begin
    `endif
        if (_T_62) begin
          $fwrite(32'h80000002,"WB : pc=[%x] inst=[%x]\n",_T_71,_T_72); // @[dpath.scala 269:9]
        end
    `ifdef PRINTF_COND
      end
    `endif
    `endif // SYNTHESIS
  end
endmodule
module core(
  input         clock,
  input         reset,
  output [63:0] io_instReadIO_addr,
  input  [63:0] io_instReadIO_data,
  output [63:0] io_dataWriteIO_addr,
  output [63:0] io_dataWriteIO_data,
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
  output [63:0] _T_42_31
);
  wire [63:0] cpath_io_dat_dec_inst; // @[core.scala 14:21]
  wire  cpath_io_dat_exe_br_eq; // @[core.scala 14:21]
  wire  cpath_io_dat_exe_br_lt; // @[core.scala 14:21]
  wire  cpath_io_dat_exe_br_ltu; // @[core.scala 14:21]
  wire [3:0] cpath_io_dat_exe_br_type; // @[core.scala 14:21]
  wire [1:0] cpath_io_ctl_exe_pc_sel; // @[core.scala 14:21]
  wire [3:0] cpath_io_ctl_br_type; // @[core.scala 14:21]
  wire [1:0] cpath_io_ctl_op1_sel; // @[core.scala 14:21]
  wire [2:0] cpath_io_ctl_op2_sel; // @[core.scala 14:21]
  wire [3:0] cpath_io_ctl_alu_fun; // @[core.scala 14:21]
  wire [1:0] cpath_io_ctl_wb_sel; // @[core.scala 14:21]
  wire  cpath_io_ctl_rf_wen; // @[core.scala 14:21]
  wire  dpath_clock; // @[core.scala 15:21]
  wire  dpath_reset; // @[core.scala 15:21]
  wire [63:0] dpath_io_instReadIO_addr; // @[core.scala 15:21]
  wire [63:0] dpath_io_instReadIO_data; // @[core.scala 15:21]
  wire [63:0] dpath_io_dataWriteIO_addr; // @[core.scala 15:21]
  wire [63:0] dpath_io_dataWriteIO_data; // @[core.scala 15:21]
  wire [1:0] dpath_io_ctl_exe_pc_sel; // @[core.scala 15:21]
  wire [3:0] dpath_io_ctl_br_type; // @[core.scala 15:21]
  wire [1:0] dpath_io_ctl_op1_sel; // @[core.scala 15:21]
  wire [2:0] dpath_io_ctl_op2_sel; // @[core.scala 15:21]
  wire [3:0] dpath_io_ctl_alu_fun; // @[core.scala 15:21]
  wire [1:0] dpath_io_ctl_wb_sel; // @[core.scala 15:21]
  wire  dpath_io_ctl_rf_wen; // @[core.scala 15:21]
  wire [63:0] dpath_io_dat_dec_inst; // @[core.scala 15:21]
  wire  dpath_io_dat_exe_br_eq; // @[core.scala 15:21]
  wire  dpath_io_dat_exe_br_lt; // @[core.scala 15:21]
  wire  dpath_io_dat_exe_br_ltu; // @[core.scala 15:21]
  wire [3:0] dpath_io_dat_exe_br_type; // @[core.scala 15:21]
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
  cpath cpath ( // @[core.scala 14:21]
    .io_dat_dec_inst(cpath_io_dat_dec_inst),
    .io_dat_exe_br_eq(cpath_io_dat_exe_br_eq),
    .io_dat_exe_br_lt(cpath_io_dat_exe_br_lt),
    .io_dat_exe_br_ltu(cpath_io_dat_exe_br_ltu),
    .io_dat_exe_br_type(cpath_io_dat_exe_br_type),
    .io_ctl_exe_pc_sel(cpath_io_ctl_exe_pc_sel),
    .io_ctl_br_type(cpath_io_ctl_br_type),
    .io_ctl_op1_sel(cpath_io_ctl_op1_sel),
    .io_ctl_op2_sel(cpath_io_ctl_op2_sel),
    .io_ctl_alu_fun(cpath_io_ctl_alu_fun),
    .io_ctl_wb_sel(cpath_io_ctl_wb_sel),
    .io_ctl_rf_wen(cpath_io_ctl_rf_wen)
  );
  dpath dpath ( // @[core.scala 15:21]
    .clock(dpath_clock),
    .reset(dpath_reset),
    .io_instReadIO_addr(dpath_io_instReadIO_addr),
    .io_instReadIO_data(dpath_io_instReadIO_data),
    .io_dataWriteIO_addr(dpath_io_dataWriteIO_addr),
    .io_dataWriteIO_data(dpath_io_dataWriteIO_data),
    .io_ctl_exe_pc_sel(dpath_io_ctl_exe_pc_sel),
    .io_ctl_br_type(dpath_io_ctl_br_type),
    .io_ctl_op1_sel(dpath_io_ctl_op1_sel),
    .io_ctl_op2_sel(dpath_io_ctl_op2_sel),
    .io_ctl_alu_fun(dpath_io_ctl_alu_fun),
    .io_ctl_wb_sel(dpath_io_ctl_wb_sel),
    .io_ctl_rf_wen(dpath_io_ctl_rf_wen),
    .io_dat_dec_inst(dpath_io_dat_dec_inst),
    .io_dat_exe_br_eq(dpath_io_dat_exe_br_eq),
    .io_dat_exe_br_lt(dpath_io_dat_exe_br_lt),
    .io_dat_exe_br_ltu(dpath_io_dat_exe_br_ltu),
    .io_dat_exe_br_type(dpath_io_dat_exe_br_type),
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
    ._T_42_0_31(dpath__T_42_0_31)
  );
  assign io_instReadIO_addr = dpath_io_instReadIO_addr; // @[core.scala 18:17]
  assign io_dataWriteIO_addr = dpath_io_dataWriteIO_addr; // @[core.scala 20:18]
  assign io_dataWriteIO_data = dpath_io_dataWriteIO_data; // @[core.scala 20:18]
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
  assign cpath_io_dat_dec_inst = dpath_io_dat_dec_inst; // @[core.scala 24:16]
  assign cpath_io_dat_exe_br_eq = dpath_io_dat_exe_br_eq; // @[core.scala 24:16]
  assign cpath_io_dat_exe_br_lt = dpath_io_dat_exe_br_lt; // @[core.scala 24:16]
  assign cpath_io_dat_exe_br_ltu = dpath_io_dat_exe_br_ltu; // @[core.scala 24:16]
  assign cpath_io_dat_exe_br_type = dpath_io_dat_exe_br_type; // @[core.scala 24:16]
  assign dpath_clock = clock;
  assign dpath_reset = reset;
  assign dpath_io_instReadIO_data = io_instReadIO_data; // @[core.scala 18:17]
  assign dpath_io_ctl_exe_pc_sel = cpath_io_ctl_exe_pc_sel; // @[core.scala 23:16]
  assign dpath_io_ctl_br_type = cpath_io_ctl_br_type; // @[core.scala 23:16]
  assign dpath_io_ctl_op1_sel = cpath_io_ctl_op1_sel; // @[core.scala 23:16]
  assign dpath_io_ctl_op2_sel = cpath_io_ctl_op2_sel; // @[core.scala 23:16]
  assign dpath_io_ctl_alu_fun = cpath_io_ctl_alu_fun; // @[core.scala 23:16]
  assign dpath_io_ctl_wb_sel = cpath_io_ctl_wb_sel; // @[core.scala 23:16]
  assign dpath_io_ctl_rf_wen = cpath_io_ctl_rf_wen; // @[core.scala 23:16]
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
  output [63:0] io_coreIO_instReadIO_addr,
  input  [63:0] io_coreIO_instReadIO_data,
  output        io_coreIO_instReadIO_en,
  output [63:0] io_coreIO_dataReadIO_addr,
  input  [63:0] io_coreIO_dataReadIO_data,
  output        io_coreIO_dataReadIO_en,
  output [63:0] io_coreIO_dataWriteIO_addr,
  output [63:0] io_coreIO_dataWriteIO_data,
  output        io_coreIO_dataWriteIO_en
);
  wire  mycore_clock; // @[simTop.scala 15:22]
  wire  mycore_reset; // @[simTop.scala 15:22]
  wire [63:0] mycore_io_instReadIO_addr; // @[simTop.scala 15:22]
  wire [63:0] mycore_io_instReadIO_data; // @[simTop.scala 15:22]
  wire [63:0] mycore_io_dataWriteIO_addr; // @[simTop.scala 15:22]
  wire [63:0] mycore_io_dataWriteIO_data; // @[simTop.scala 15:22]
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
  core mycore ( // @[simTop.scala 15:22]
    .clock(mycore_clock),
    .reset(mycore_reset),
    .io_instReadIO_addr(mycore_io_instReadIO_addr),
    .io_instReadIO_data(mycore_io_instReadIO_data),
    .io_dataWriteIO_addr(mycore_io_dataWriteIO_addr),
    .io_dataWriteIO_data(mycore_io_dataWriteIO_data),
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
    ._T_42_31(mycore__T_42_31)
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
  assign io_diffTestIO_pc = 64'h0;
  assign io_coreIO_instReadIO_addr = mycore_io_instReadIO_addr; // @[simTop.scala 18:13]
  assign io_coreIO_instReadIO_en = 1'h1; // @[simTop.scala 18:13]
  assign io_coreIO_dataReadIO_addr = 64'h0; // @[simTop.scala 18:13]
  assign io_coreIO_dataReadIO_en = 1'h0; // @[simTop.scala 18:13]
  assign io_coreIO_dataWriteIO_addr = mycore_io_dataWriteIO_addr; // @[simTop.scala 18:13]
  assign io_coreIO_dataWriteIO_data = mycore_io_dataWriteIO_data; // @[simTop.scala 18:13]
  assign io_coreIO_dataWriteIO_en = 1'h1; // @[simTop.scala 18:13]
  assign mycore_clock = clock;
  assign mycore_reset = reset;
  assign mycore_io_instReadIO_data = io_coreIO_instReadIO_data; // @[simTop.scala 18:13]
endmodule
