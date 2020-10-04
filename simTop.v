module cpath(
  input  [31:0] io_dat_inst,
  input         io_dat_br_eq,
  input         io_dat_br_lt,
  input         io_dat_br_ltu,
  output [2:0]  io_ctl_pc_sel,
  output [1:0]  io_ctl_op1_sel,
  output [1:0]  io_ctl_op2_sel,
  output [3:0]  io_ctl_alu_fun,
  output [1:0]  io_ctl_wb_sel,
  output        io_ctl_rf_wen
);
  wire [31:0] _T = io_dat_inst & 32'h707f; // @[Lookup.scala 31:38]
  wire  _T_1 = 32'h2003 == _T; // @[Lookup.scala 31:38]
  wire  _T_3 = 32'h3 == _T; // @[Lookup.scala 31:38]
  wire  _T_5 = 32'h4003 == _T; // @[Lookup.scala 31:38]
  wire  _T_7 = 32'h1003 == _T; // @[Lookup.scala 31:38]
  wire  _T_9 = 32'h5003 == _T; // @[Lookup.scala 31:38]
  wire  _T_11 = 32'h2023 == _T; // @[Lookup.scala 31:38]
  wire  _T_13 = 32'h23 == _T; // @[Lookup.scala 31:38]
  wire  _T_15 = 32'h1023 == _T; // @[Lookup.scala 31:38]
  wire [31:0] _T_16 = io_dat_inst & 32'h7f; // @[Lookup.scala 31:38]
  wire  _T_17 = 32'h17 == _T_16; // @[Lookup.scala 31:38]
  wire  _T_19 = 32'h37 == _T_16; // @[Lookup.scala 31:38]
  wire  _T_21 = 32'h13 == _T; // @[Lookup.scala 31:38]
  wire  _T_23 = 32'h7013 == _T; // @[Lookup.scala 31:38]
  wire  _T_25 = 32'h6013 == _T; // @[Lookup.scala 31:38]
  wire  _T_27 = 32'h4013 == _T; // @[Lookup.scala 31:38]
  wire  _T_29 = 32'h2013 == _T; // @[Lookup.scala 31:38]
  wire  _T_31 = 32'h3013 == _T; // @[Lookup.scala 31:38]
  wire [31:0] _T_32 = io_dat_inst & 32'hfc00707f; // @[Lookup.scala 31:38]
  wire  _T_33 = 32'h1013 == _T_32; // @[Lookup.scala 31:38]
  wire  _T_35 = 32'h40005013 == _T_32; // @[Lookup.scala 31:38]
  wire  _T_37 = 32'h5013 == _T_32; // @[Lookup.scala 31:38]
  wire [31:0] _T_38 = io_dat_inst & 32'hfe00707f; // @[Lookup.scala 31:38]
  wire  _T_39 = 32'h1033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_41 = 32'h33 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_43 = 32'h40000033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_45 = 32'h2033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_47 = 32'h3033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_49 = 32'h7033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_51 = 32'h6033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_53 = 32'h4033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_55 = 32'h40005033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_57 = 32'h5033 == _T_38; // @[Lookup.scala 31:38]
  wire  _T_59 = 32'h6f == _T_16; // @[Lookup.scala 31:38]
  wire  _T_61 = 32'h67 == _T; // @[Lookup.scala 31:38]
  wire  _T_63 = 32'h63 == _T; // @[Lookup.scala 31:38]
  wire  _T_65 = 32'h1063 == _T; // @[Lookup.scala 31:38]
  wire  _T_67 = 32'h5063 == _T; // @[Lookup.scala 31:38]
  wire  _T_69 = 32'h7063 == _T; // @[Lookup.scala 31:38]
  wire  _T_71 = 32'h4063 == _T; // @[Lookup.scala 31:38]
  wire  _T_73 = 32'h6063 == _T; // @[Lookup.scala 31:38]
  wire  _T_75 = 32'h5073 == _T; // @[Lookup.scala 31:38]
  wire  _T_77 = 32'h6073 == _T; // @[Lookup.scala 31:38]
  wire  _T_79 = 32'h7073 == _T; // @[Lookup.scala 31:38]
  wire  _T_81 = 32'h1073 == _T; // @[Lookup.scala 31:38]
  wire  _T_83 = 32'h2073 == _T; // @[Lookup.scala 31:38]
  wire  _T_85 = 32'h3073 == _T; // @[Lookup.scala 31:38]
  wire [3:0] _T_162 = _T_73 ? 4'h6 : 4'h0; // @[Lookup.scala 33:37]
  wire [3:0] _T_163 = _T_71 ? 4'h5 : _T_162; // @[Lookup.scala 33:37]
  wire [3:0] _T_164 = _T_69 ? 4'h4 : _T_163; // @[Lookup.scala 33:37]
  wire [3:0] _T_165 = _T_67 ? 4'h3 : _T_164; // @[Lookup.scala 33:37]
  wire [3:0] _T_166 = _T_65 ? 4'h1 : _T_165; // @[Lookup.scala 33:37]
  wire [3:0] _T_167 = _T_63 ? 4'h2 : _T_166; // @[Lookup.scala 33:37]
  wire [3:0] _T_168 = _T_61 ? 4'h8 : _T_167; // @[Lookup.scala 33:37]
  wire [3:0] _T_169 = _T_59 ? 4'h7 : _T_168; // @[Lookup.scala 33:37]
  wire [3:0] _T_170 = _T_57 ? 4'h0 : _T_169; // @[Lookup.scala 33:37]
  wire [3:0] _T_171 = _T_55 ? 4'h0 : _T_170; // @[Lookup.scala 33:37]
  wire [3:0] _T_172 = _T_53 ? 4'h0 : _T_171; // @[Lookup.scala 33:37]
  wire [3:0] _T_173 = _T_51 ? 4'h0 : _T_172; // @[Lookup.scala 33:37]
  wire [3:0] _T_174 = _T_49 ? 4'h0 : _T_173; // @[Lookup.scala 33:37]
  wire [3:0] _T_175 = _T_47 ? 4'h0 : _T_174; // @[Lookup.scala 33:37]
  wire [3:0] _T_176 = _T_45 ? 4'h0 : _T_175; // @[Lookup.scala 33:37]
  wire [3:0] _T_177 = _T_43 ? 4'h0 : _T_176; // @[Lookup.scala 33:37]
  wire [3:0] _T_178 = _T_41 ? 4'h0 : _T_177; // @[Lookup.scala 33:37]
  wire [3:0] _T_179 = _T_39 ? 4'h0 : _T_178; // @[Lookup.scala 33:37]
  wire [3:0] _T_180 = _T_37 ? 4'h0 : _T_179; // @[Lookup.scala 33:37]
  wire [3:0] _T_181 = _T_35 ? 4'h0 : _T_180; // @[Lookup.scala 33:37]
  wire [3:0] _T_182 = _T_33 ? 4'h0 : _T_181; // @[Lookup.scala 33:37]
  wire [3:0] _T_183 = _T_31 ? 4'h0 : _T_182; // @[Lookup.scala 33:37]
  wire [3:0] _T_184 = _T_29 ? 4'h0 : _T_183; // @[Lookup.scala 33:37]
  wire [3:0] _T_185 = _T_27 ? 4'h0 : _T_184; // @[Lookup.scala 33:37]
  wire [3:0] _T_186 = _T_25 ? 4'h0 : _T_185; // @[Lookup.scala 33:37]
  wire [3:0] _T_187 = _T_23 ? 4'h0 : _T_186; // @[Lookup.scala 33:37]
  wire [3:0] _T_188 = _T_21 ? 4'h0 : _T_187; // @[Lookup.scala 33:37]
  wire [3:0] _T_189 = _T_19 ? 4'h0 : _T_188; // @[Lookup.scala 33:37]
  wire [3:0] _T_190 = _T_17 ? 4'h0 : _T_189; // @[Lookup.scala 33:37]
  wire [3:0] _T_191 = _T_15 ? 4'h0 : _T_190; // @[Lookup.scala 33:37]
  wire [3:0] _T_192 = _T_13 ? 4'h0 : _T_191; // @[Lookup.scala 33:37]
  wire [3:0] _T_193 = _T_11 ? 4'h0 : _T_192; // @[Lookup.scala 33:37]
  wire [3:0] _T_194 = _T_9 ? 4'h0 : _T_193; // @[Lookup.scala 33:37]
  wire [3:0] _T_195 = _T_7 ? 4'h0 : _T_194; // @[Lookup.scala 33:37]
  wire [3:0] _T_196 = _T_5 ? 4'h0 : _T_195; // @[Lookup.scala 33:37]
  wire [3:0] _T_197 = _T_3 ? 4'h0 : _T_196; // @[Lookup.scala 33:37]
  wire [3:0] cs_br_type = _T_1 ? 4'h0 : _T_197; // @[Lookup.scala 33:37]
  wire [1:0] _T_208 = _T_79 ? 2'h2 : 2'h0; // @[Lookup.scala 33:37]
  wire [1:0] _T_209 = _T_77 ? 2'h2 : _T_208; // @[Lookup.scala 33:37]
  wire [1:0] _T_210 = _T_75 ? 2'h2 : _T_209; // @[Lookup.scala 33:37]
  wire [1:0] _T_211 = _T_73 ? 2'h0 : _T_210; // @[Lookup.scala 33:37]
  wire [1:0] _T_212 = _T_71 ? 2'h0 : _T_211; // @[Lookup.scala 33:37]
  wire [1:0] _T_213 = _T_69 ? 2'h0 : _T_212; // @[Lookup.scala 33:37]
  wire [1:0] _T_214 = _T_67 ? 2'h0 : _T_213; // @[Lookup.scala 33:37]
  wire [1:0] _T_215 = _T_65 ? 2'h0 : _T_214; // @[Lookup.scala 33:37]
  wire [1:0] _T_216 = _T_63 ? 2'h0 : _T_215; // @[Lookup.scala 33:37]
  wire [1:0] _T_217 = _T_61 ? 2'h0 : _T_216; // @[Lookup.scala 33:37]
  wire [1:0] _T_218 = _T_59 ? 2'h0 : _T_217; // @[Lookup.scala 33:37]
  wire [1:0] _T_219 = _T_57 ? 2'h0 : _T_218; // @[Lookup.scala 33:37]
  wire [1:0] _T_220 = _T_55 ? 2'h0 : _T_219; // @[Lookup.scala 33:37]
  wire [1:0] _T_221 = _T_53 ? 2'h0 : _T_220; // @[Lookup.scala 33:37]
  wire [1:0] _T_222 = _T_51 ? 2'h0 : _T_221; // @[Lookup.scala 33:37]
  wire [1:0] _T_223 = _T_49 ? 2'h0 : _T_222; // @[Lookup.scala 33:37]
  wire [1:0] _T_224 = _T_47 ? 2'h0 : _T_223; // @[Lookup.scala 33:37]
  wire [1:0] _T_225 = _T_45 ? 2'h0 : _T_224; // @[Lookup.scala 33:37]
  wire [1:0] _T_226 = _T_43 ? 2'h0 : _T_225; // @[Lookup.scala 33:37]
  wire [1:0] _T_227 = _T_41 ? 2'h0 : _T_226; // @[Lookup.scala 33:37]
  wire [1:0] _T_228 = _T_39 ? 2'h0 : _T_227; // @[Lookup.scala 33:37]
  wire [1:0] _T_229 = _T_37 ? 2'h0 : _T_228; // @[Lookup.scala 33:37]
  wire [1:0] _T_230 = _T_35 ? 2'h0 : _T_229; // @[Lookup.scala 33:37]
  wire [1:0] _T_231 = _T_33 ? 2'h0 : _T_230; // @[Lookup.scala 33:37]
  wire [1:0] _T_232 = _T_31 ? 2'h0 : _T_231; // @[Lookup.scala 33:37]
  wire [1:0] _T_233 = _T_29 ? 2'h0 : _T_232; // @[Lookup.scala 33:37]
  wire [1:0] _T_234 = _T_27 ? 2'h0 : _T_233; // @[Lookup.scala 33:37]
  wire [1:0] _T_235 = _T_25 ? 2'h0 : _T_234; // @[Lookup.scala 33:37]
  wire [1:0] _T_236 = _T_23 ? 2'h0 : _T_235; // @[Lookup.scala 33:37]
  wire [1:0] _T_237 = _T_21 ? 2'h0 : _T_236; // @[Lookup.scala 33:37]
  wire [1:0] _T_238 = _T_19 ? 2'h1 : _T_237; // @[Lookup.scala 33:37]
  wire [1:0] _T_239 = _T_17 ? 2'h1 : _T_238; // @[Lookup.scala 33:37]
  wire [1:0] _T_240 = _T_15 ? 2'h0 : _T_239; // @[Lookup.scala 33:37]
  wire [1:0] _T_241 = _T_13 ? 2'h0 : _T_240; // @[Lookup.scala 33:37]
  wire [1:0] _T_242 = _T_11 ? 2'h0 : _T_241; // @[Lookup.scala 33:37]
  wire [1:0] _T_243 = _T_9 ? 2'h0 : _T_242; // @[Lookup.scala 33:37]
  wire [1:0] _T_244 = _T_7 ? 2'h0 : _T_243; // @[Lookup.scala 33:37]
  wire [1:0] _T_245 = _T_5 ? 2'h0 : _T_244; // @[Lookup.scala 33:37]
  wire [1:0] _T_246 = _T_3 ? 2'h0 : _T_245; // @[Lookup.scala 33:37]
  wire [1:0] _T_266 = _T_61 ? 2'h1 : 2'h0; // @[Lookup.scala 33:37]
  wire [1:0] _T_267 = _T_59 ? 2'h0 : _T_266; // @[Lookup.scala 33:37]
  wire [1:0] _T_268 = _T_57 ? 2'h0 : _T_267; // @[Lookup.scala 33:37]
  wire [1:0] _T_269 = _T_55 ? 2'h0 : _T_268; // @[Lookup.scala 33:37]
  wire [1:0] _T_270 = _T_53 ? 2'h0 : _T_269; // @[Lookup.scala 33:37]
  wire [1:0] _T_271 = _T_51 ? 2'h0 : _T_270; // @[Lookup.scala 33:37]
  wire [1:0] _T_272 = _T_49 ? 2'h0 : _T_271; // @[Lookup.scala 33:37]
  wire [1:0] _T_273 = _T_47 ? 2'h0 : _T_272; // @[Lookup.scala 33:37]
  wire [1:0] _T_274 = _T_45 ? 2'h0 : _T_273; // @[Lookup.scala 33:37]
  wire [1:0] _T_275 = _T_43 ? 2'h0 : _T_274; // @[Lookup.scala 33:37]
  wire [1:0] _T_276 = _T_41 ? 2'h0 : _T_275; // @[Lookup.scala 33:37]
  wire [1:0] _T_277 = _T_39 ? 2'h0 : _T_276; // @[Lookup.scala 33:37]
  wire [1:0] _T_278 = _T_37 ? 2'h1 : _T_277; // @[Lookup.scala 33:37]
  wire [1:0] _T_279 = _T_35 ? 2'h1 : _T_278; // @[Lookup.scala 33:37]
  wire [1:0] _T_280 = _T_33 ? 2'h1 : _T_279; // @[Lookup.scala 33:37]
  wire [1:0] _T_281 = _T_31 ? 2'h1 : _T_280; // @[Lookup.scala 33:37]
  wire [1:0] _T_282 = _T_29 ? 2'h1 : _T_281; // @[Lookup.scala 33:37]
  wire [1:0] _T_283 = _T_27 ? 2'h1 : _T_282; // @[Lookup.scala 33:37]
  wire [1:0] _T_284 = _T_25 ? 2'h1 : _T_283; // @[Lookup.scala 33:37]
  wire [1:0] _T_285 = _T_23 ? 2'h1 : _T_284; // @[Lookup.scala 33:37]
  wire [1:0] _T_286 = _T_21 ? 2'h1 : _T_285; // @[Lookup.scala 33:37]
  wire [1:0] _T_287 = _T_19 ? 2'h0 : _T_286; // @[Lookup.scala 33:37]
  wire [1:0] _T_288 = _T_17 ? 2'h3 : _T_287; // @[Lookup.scala 33:37]
  wire [1:0] _T_289 = _T_15 ? 2'h2 : _T_288; // @[Lookup.scala 33:37]
  wire [1:0] _T_290 = _T_13 ? 2'h2 : _T_289; // @[Lookup.scala 33:37]
  wire [1:0] _T_291 = _T_11 ? 2'h2 : _T_290; // @[Lookup.scala 33:37]
  wire [1:0] _T_292 = _T_9 ? 2'h1 : _T_291; // @[Lookup.scala 33:37]
  wire [1:0] _T_293 = _T_7 ? 2'h1 : _T_292; // @[Lookup.scala 33:37]
  wire [1:0] _T_294 = _T_5 ? 2'h1 : _T_293; // @[Lookup.scala 33:37]
  wire [1:0] _T_295 = _T_3 ? 2'h1 : _T_294; // @[Lookup.scala 33:37]
  wire [3:0] _T_303 = _T_85 ? 4'ha : 4'h0; // @[Lookup.scala 33:37]
  wire [3:0] _T_304 = _T_83 ? 4'ha : _T_303; // @[Lookup.scala 33:37]
  wire [3:0] _T_305 = _T_81 ? 4'ha : _T_304; // @[Lookup.scala 33:37]
  wire [3:0] _T_306 = _T_79 ? 4'ha : _T_305; // @[Lookup.scala 33:37]
  wire [3:0] _T_307 = _T_77 ? 4'ha : _T_306; // @[Lookup.scala 33:37]
  wire [3:0] _T_308 = _T_75 ? 4'ha : _T_307; // @[Lookup.scala 33:37]
  wire [3:0] _T_309 = _T_73 ? 4'h0 : _T_308; // @[Lookup.scala 33:37]
  wire [3:0] _T_310 = _T_71 ? 4'h0 : _T_309; // @[Lookup.scala 33:37]
  wire [3:0] _T_311 = _T_69 ? 4'h0 : _T_310; // @[Lookup.scala 33:37]
  wire [3:0] _T_312 = _T_67 ? 4'h0 : _T_311; // @[Lookup.scala 33:37]
  wire [3:0] _T_313 = _T_65 ? 4'h0 : _T_312; // @[Lookup.scala 33:37]
  wire [3:0] _T_314 = _T_63 ? 4'h0 : _T_313; // @[Lookup.scala 33:37]
  wire [3:0] _T_315 = _T_61 ? 4'h0 : _T_314; // @[Lookup.scala 33:37]
  wire [3:0] _T_316 = _T_59 ? 4'h0 : _T_315; // @[Lookup.scala 33:37]
  wire [3:0] _T_317 = _T_57 ? 4'h9 : _T_316; // @[Lookup.scala 33:37]
  wire [3:0] _T_318 = _T_55 ? 4'h8 : _T_317; // @[Lookup.scala 33:37]
  wire [3:0] _T_319 = _T_53 ? 4'h4 : _T_318; // @[Lookup.scala 33:37]
  wire [3:0] _T_320 = _T_51 ? 4'h3 : _T_319; // @[Lookup.scala 33:37]
  wire [3:0] _T_321 = _T_49 ? 4'h2 : _T_320; // @[Lookup.scala 33:37]
  wire [3:0] _T_322 = _T_47 ? 4'h6 : _T_321; // @[Lookup.scala 33:37]
  wire [3:0] _T_323 = _T_45 ? 4'h5 : _T_322; // @[Lookup.scala 33:37]
  wire [3:0] _T_324 = _T_43 ? 4'h1 : _T_323; // @[Lookup.scala 33:37]
  wire [3:0] _T_325 = _T_41 ? 4'h0 : _T_324; // @[Lookup.scala 33:37]
  wire [3:0] _T_326 = _T_39 ? 4'h7 : _T_325; // @[Lookup.scala 33:37]
  wire [3:0] _T_327 = _T_37 ? 4'h9 : _T_326; // @[Lookup.scala 33:37]
  wire [3:0] _T_328 = _T_35 ? 4'h8 : _T_327; // @[Lookup.scala 33:37]
  wire [3:0] _T_329 = _T_33 ? 4'h7 : _T_328; // @[Lookup.scala 33:37]
  wire [3:0] _T_330 = _T_31 ? 4'h6 : _T_329; // @[Lookup.scala 33:37]
  wire [3:0] _T_331 = _T_29 ? 4'h5 : _T_330; // @[Lookup.scala 33:37]
  wire [3:0] _T_332 = _T_27 ? 4'h4 : _T_331; // @[Lookup.scala 33:37]
  wire [3:0] _T_333 = _T_25 ? 4'h3 : _T_332; // @[Lookup.scala 33:37]
  wire [3:0] _T_334 = _T_23 ? 4'h2 : _T_333; // @[Lookup.scala 33:37]
  wire [3:0] _T_335 = _T_21 ? 4'h0 : _T_334; // @[Lookup.scala 33:37]
  wire [3:0] _T_336 = _T_19 ? 4'ha : _T_335; // @[Lookup.scala 33:37]
  wire [3:0] _T_337 = _T_17 ? 4'h0 : _T_336; // @[Lookup.scala 33:37]
  wire [3:0] _T_338 = _T_15 ? 4'h0 : _T_337; // @[Lookup.scala 33:37]
  wire [3:0] _T_339 = _T_13 ? 4'h0 : _T_338; // @[Lookup.scala 33:37]
  wire [3:0] _T_340 = _T_11 ? 4'h0 : _T_339; // @[Lookup.scala 33:37]
  wire [3:0] _T_341 = _T_9 ? 4'h0 : _T_340; // @[Lookup.scala 33:37]
  wire [3:0] _T_342 = _T_7 ? 4'h0 : _T_341; // @[Lookup.scala 33:37]
  wire [3:0] _T_343 = _T_5 ? 4'h0 : _T_342; // @[Lookup.scala 33:37]
  wire [3:0] _T_344 = _T_3 ? 4'h0 : _T_343; // @[Lookup.scala 33:37]
  wire [1:0] _T_352 = _T_85 ? 2'h3 : 2'h0; // @[Lookup.scala 33:37]
  wire [1:0] _T_353 = _T_83 ? 2'h3 : _T_352; // @[Lookup.scala 33:37]
  wire [1:0] _T_354 = _T_81 ? 2'h3 : _T_353; // @[Lookup.scala 33:37]
  wire [1:0] _T_355 = _T_79 ? 2'h3 : _T_354; // @[Lookup.scala 33:37]
  wire [1:0] _T_356 = _T_77 ? 2'h3 : _T_355; // @[Lookup.scala 33:37]
  wire [1:0] _T_357 = _T_75 ? 2'h3 : _T_356; // @[Lookup.scala 33:37]
  wire [1:0] _T_358 = _T_73 ? 2'h0 : _T_357; // @[Lookup.scala 33:37]
  wire [1:0] _T_359 = _T_71 ? 2'h0 : _T_358; // @[Lookup.scala 33:37]
  wire [1:0] _T_360 = _T_69 ? 2'h0 : _T_359; // @[Lookup.scala 33:37]
  wire [1:0] _T_361 = _T_67 ? 2'h0 : _T_360; // @[Lookup.scala 33:37]
  wire [1:0] _T_362 = _T_65 ? 2'h0 : _T_361; // @[Lookup.scala 33:37]
  wire [1:0] _T_363 = _T_63 ? 2'h0 : _T_362; // @[Lookup.scala 33:37]
  wire [1:0] _T_364 = _T_61 ? 2'h2 : _T_363; // @[Lookup.scala 33:37]
  wire [1:0] _T_365 = _T_59 ? 2'h2 : _T_364; // @[Lookup.scala 33:37]
  wire [1:0] _T_366 = _T_57 ? 2'h0 : _T_365; // @[Lookup.scala 33:37]
  wire [1:0] _T_367 = _T_55 ? 2'h0 : _T_366; // @[Lookup.scala 33:37]
  wire [1:0] _T_368 = _T_53 ? 2'h0 : _T_367; // @[Lookup.scala 33:37]
  wire [1:0] _T_369 = _T_51 ? 2'h0 : _T_368; // @[Lookup.scala 33:37]
  wire [1:0] _T_370 = _T_49 ? 2'h0 : _T_369; // @[Lookup.scala 33:37]
  wire [1:0] _T_371 = _T_47 ? 2'h0 : _T_370; // @[Lookup.scala 33:37]
  wire [1:0] _T_372 = _T_45 ? 2'h0 : _T_371; // @[Lookup.scala 33:37]
  wire [1:0] _T_373 = _T_43 ? 2'h0 : _T_372; // @[Lookup.scala 33:37]
  wire [1:0] _T_374 = _T_41 ? 2'h0 : _T_373; // @[Lookup.scala 33:37]
  wire [1:0] _T_375 = _T_39 ? 2'h0 : _T_374; // @[Lookup.scala 33:37]
  wire [1:0] _T_376 = _T_37 ? 2'h0 : _T_375; // @[Lookup.scala 33:37]
  wire [1:0] _T_377 = _T_35 ? 2'h0 : _T_376; // @[Lookup.scala 33:37]
  wire [1:0] _T_378 = _T_33 ? 2'h0 : _T_377; // @[Lookup.scala 33:37]
  wire [1:0] _T_379 = _T_31 ? 2'h0 : _T_378; // @[Lookup.scala 33:37]
  wire [1:0] _T_380 = _T_29 ? 2'h0 : _T_379; // @[Lookup.scala 33:37]
  wire [1:0] _T_381 = _T_27 ? 2'h0 : _T_380; // @[Lookup.scala 33:37]
  wire [1:0] _T_382 = _T_25 ? 2'h0 : _T_381; // @[Lookup.scala 33:37]
  wire [1:0] _T_383 = _T_23 ? 2'h0 : _T_382; // @[Lookup.scala 33:37]
  wire [1:0] _T_384 = _T_21 ? 2'h0 : _T_383; // @[Lookup.scala 33:37]
  wire [1:0] _T_385 = _T_19 ? 2'h0 : _T_384; // @[Lookup.scala 33:37]
  wire [1:0] _T_386 = _T_17 ? 2'h0 : _T_385; // @[Lookup.scala 33:37]
  wire [1:0] _T_387 = _T_15 ? 2'h0 : _T_386; // @[Lookup.scala 33:37]
  wire [1:0] _T_388 = _T_13 ? 2'h0 : _T_387; // @[Lookup.scala 33:37]
  wire [1:0] _T_389 = _T_11 ? 2'h0 : _T_388; // @[Lookup.scala 33:37]
  wire [1:0] _T_390 = _T_9 ? 2'h1 : _T_389; // @[Lookup.scala 33:37]
  wire [1:0] _T_391 = _T_7 ? 2'h1 : _T_390; // @[Lookup.scala 33:37]
  wire [1:0] _T_392 = _T_5 ? 2'h1 : _T_391; // @[Lookup.scala 33:37]
  wire [1:0] _T_393 = _T_3 ? 2'h1 : _T_392; // @[Lookup.scala 33:37]
  wire  _T_402 = _T_83 | _T_85; // @[Lookup.scala 33:37]
  wire  _T_403 = _T_81 | _T_402; // @[Lookup.scala 33:37]
  wire  _T_404 = _T_79 | _T_403; // @[Lookup.scala 33:37]
  wire  _T_405 = _T_77 | _T_404; // @[Lookup.scala 33:37]
  wire  _T_406 = _T_75 | _T_405; // @[Lookup.scala 33:37]
  wire  _T_407 = _T_73 ? 1'h0 : _T_406; // @[Lookup.scala 33:37]
  wire  _T_408 = _T_71 ? 1'h0 : _T_407; // @[Lookup.scala 33:37]
  wire  _T_409 = _T_69 ? 1'h0 : _T_408; // @[Lookup.scala 33:37]
  wire  _T_410 = _T_67 ? 1'h0 : _T_409; // @[Lookup.scala 33:37]
  wire  _T_411 = _T_65 ? 1'h0 : _T_410; // @[Lookup.scala 33:37]
  wire  _T_412 = _T_63 ? 1'h0 : _T_411; // @[Lookup.scala 33:37]
  wire  _T_413 = _T_61 | _T_412; // @[Lookup.scala 33:37]
  wire  _T_414 = _T_59 | _T_413; // @[Lookup.scala 33:37]
  wire  _T_415 = _T_57 | _T_414; // @[Lookup.scala 33:37]
  wire  _T_416 = _T_55 | _T_415; // @[Lookup.scala 33:37]
  wire  _T_417 = _T_53 | _T_416; // @[Lookup.scala 33:37]
  wire  _T_418 = _T_51 | _T_417; // @[Lookup.scala 33:37]
  wire  _T_419 = _T_49 | _T_418; // @[Lookup.scala 33:37]
  wire  _T_420 = _T_47 | _T_419; // @[Lookup.scala 33:37]
  wire  _T_421 = _T_45 | _T_420; // @[Lookup.scala 33:37]
  wire  _T_422 = _T_43 | _T_421; // @[Lookup.scala 33:37]
  wire  _T_423 = _T_41 | _T_422; // @[Lookup.scala 33:37]
  wire  _T_424 = _T_39 | _T_423; // @[Lookup.scala 33:37]
  wire  _T_425 = _T_37 | _T_424; // @[Lookup.scala 33:37]
  wire  _T_426 = _T_35 | _T_425; // @[Lookup.scala 33:37]
  wire  _T_427 = _T_33 | _T_426; // @[Lookup.scala 33:37]
  wire  _T_428 = _T_31 | _T_427; // @[Lookup.scala 33:37]
  wire  _T_429 = _T_29 | _T_428; // @[Lookup.scala 33:37]
  wire  _T_430 = _T_27 | _T_429; // @[Lookup.scala 33:37]
  wire  _T_431 = _T_25 | _T_430; // @[Lookup.scala 33:37]
  wire  _T_432 = _T_23 | _T_431; // @[Lookup.scala 33:37]
  wire  _T_433 = _T_21 | _T_432; // @[Lookup.scala 33:37]
  wire  _T_434 = _T_19 | _T_433; // @[Lookup.scala 33:37]
  wire  _T_435 = _T_17 | _T_434; // @[Lookup.scala 33:37]
  wire  _T_436 = _T_15 ? 1'h0 : _T_435; // @[Lookup.scala 33:37]
  wire  _T_437 = _T_13 ? 1'h0 : _T_436; // @[Lookup.scala 33:37]
  wire  _T_438 = _T_11 ? 1'h0 : _T_437; // @[Lookup.scala 33:37]
  wire  _T_439 = _T_9 | _T_438; // @[Lookup.scala 33:37]
  wire  _T_440 = _T_7 | _T_439; // @[Lookup.scala 33:37]
  wire  _T_441 = _T_5 | _T_440; // @[Lookup.scala 33:37]
  wire  _T_442 = _T_3 | _T_441; // @[Lookup.scala 33:37]
  wire  _T_639 = cs_br_type == 4'h0; // @[cpath.scala 131:37]
  wire  _T_640 = cs_br_type == 4'h1; // @[cpath.scala 132:37]
  wire  _T_641 = ~io_dat_br_eq; // @[cpath.scala 132:54]
  wire [2:0] _T_642 = _T_641 ? 3'h1 : 3'h0; // @[cpath.scala 132:53]
  wire  _T_643 = cs_br_type == 4'h2; // @[cpath.scala 133:37]
  wire [2:0] _T_644 = io_dat_br_eq ? 3'h1 : 3'h0; // @[cpath.scala 133:53]
  wire  _T_645 = cs_br_type == 4'h3; // @[cpath.scala 134:37]
  wire  _T_646 = ~io_dat_br_lt; // @[cpath.scala 134:54]
  wire [2:0] _T_647 = _T_646 ? 3'h1 : 3'h0; // @[cpath.scala 134:53]
  wire  _T_648 = cs_br_type == 4'h4; // @[cpath.scala 135:37]
  wire  _T_649 = ~io_dat_br_ltu; // @[cpath.scala 135:54]
  wire [2:0] _T_650 = _T_649 ? 3'h1 : 3'h0; // @[cpath.scala 135:53]
  wire  _T_651 = cs_br_type == 4'h5; // @[cpath.scala 136:37]
  wire [2:0] _T_652 = io_dat_br_lt ? 3'h1 : 3'h0; // @[cpath.scala 136:53]
  wire  _T_653 = cs_br_type == 4'h6; // @[cpath.scala 137:37]
  wire [2:0] _T_654 = io_dat_br_ltu ? 3'h1 : 3'h0; // @[cpath.scala 137:53]
  wire  _T_655 = cs_br_type == 4'h7; // @[cpath.scala 138:37]
  wire  _T_656 = cs_br_type == 4'h8; // @[cpath.scala 139:37]
  wire [2:0] _T_657 = _T_656 ? 3'h3 : 3'h0; // @[cpath.scala 139:25]
  wire [2:0] _T_658 = _T_655 ? 3'h2 : _T_657; // @[cpath.scala 138:25]
  wire [2:0] _T_659 = _T_653 ? _T_654 : _T_658; // @[cpath.scala 137:25]
  wire [2:0] _T_660 = _T_651 ? _T_652 : _T_659; // @[cpath.scala 136:25]
  wire [2:0] _T_661 = _T_648 ? _T_650 : _T_660; // @[cpath.scala 135:25]
  wire [2:0] _T_662 = _T_645 ? _T_647 : _T_661; // @[cpath.scala 134:25]
  wire [2:0] _T_663 = _T_643 ? _T_644 : _T_662; // @[cpath.scala 133:25]
  wire [2:0] _T_664 = _T_640 ? _T_642 : _T_663; // @[cpath.scala 132:25]
  assign io_ctl_pc_sel = _T_639 ? 3'h0 : _T_664; // @[cpath.scala 149:20]
  assign io_ctl_op1_sel = _T_1 ? 2'h0 : _T_246; // @[cpath.scala 150:20]
  assign io_ctl_op2_sel = _T_1 ? 2'h1 : _T_295; // @[cpath.scala 151:20]
  assign io_ctl_alu_fun = _T_1 ? 4'h0 : _T_344; // @[cpath.scala 152:20]
  assign io_ctl_wb_sel = _T_1 ? 2'h1 : _T_393; // @[cpath.scala 153:20]
  assign io_ctl_rf_wen = _T_1 | _T_442; // @[cpath.scala 154:20]
endmodule
module dpath(
  input         clock,
  input         reset,
  output [31:0] io_instReadIO_addr,
  input  [31:0] io_instReadIO_data,
  output [31:0] io_dataReadIO_addr,
  input  [31:0] io_dataReadIO_data,
  output [31:0] io_dataWriteIO_addr,
  output [31:0] io_dataWriteIO_data,
  input  [2:0]  io_ctl_pc_sel,
  input  [1:0]  io_ctl_op1_sel,
  input  [1:0]  io_ctl_op2_sel,
  input  [3:0]  io_ctl_alu_fun,
  input  [1:0]  io_ctl_wb_sel,
  input         io_ctl_rf_wen,
  output [31:0] io_dat_inst,
  output        io_dat_br_eq,
  output        io_dat_br_lt,
  output        io_dat_br_ltu,
  output [31:0] _T_149_0_0,
  output [31:0] _T_149_0_1,
  output [31:0] _T_149_0_2,
  output [31:0] _T_149_0_3,
  output [31:0] _T_149_0_4,
  output [31:0] _T_149_0_5,
  output [31:0] _T_149_0_6,
  output [31:0] _T_149_0_7,
  output [31:0] _T_149_0_8,
  output [31:0] _T_149_0_9,
  output [31:0] _T_149_0_10,
  output [31:0] _T_149_0_11,
  output [31:0] _T_149_0_12,
  output [31:0] _T_149_0_13,
  output [31:0] _T_149_0_14,
  output [31:0] _T_149_0_15,
  output [31:0] _T_149_0_16,
  output [31:0] _T_149_0_17,
  output [31:0] _T_149_0_18,
  output [31:0] _T_149_0_19,
  output [31:0] _T_149_0_20,
  output [31:0] _T_149_0_21,
  output [31:0] _T_149_0_22,
  output [31:0] _T_149_0_23,
  output [31:0] _T_149_0_24,
  output [31:0] _T_149_0_25,
  output [31:0] _T_149_0_26,
  output [31:0] _T_149_0_27,
  output [31:0] _T_149_0_28,
  output [31:0] _T_149_0_29,
  output [31:0] _T_149_0_30,
  output [31:0] _T_149_0_31,
  output [31:0] pc_reg_0
);
`ifdef RANDOMIZE_MEM_INIT
  reg [31:0] _RAND_0;
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  reg [31:0] _RAND_1;
`endif // RANDOMIZE_REG_INIT
  reg [31:0] regfile [0:31]; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_15_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_15_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_17_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_17_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_117_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_117_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_118_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_118_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_119_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_119_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_120_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_120_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_121_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_121_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_122_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_122_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_123_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_123_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_124_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_124_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_125_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_125_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_126_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_126_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_127_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_127_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_128_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_128_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_129_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_129_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_130_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_130_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_131_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_131_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_132_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_132_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_133_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_133_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_134_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_134_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_135_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_135_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_136_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_136_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_137_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_137_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_138_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_138_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_139_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_139_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_140_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_140_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_141_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_141_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_142_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_142_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_143_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_143_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_144_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_144_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_145_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_145_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_146_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_146_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_147_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_147_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_148_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_148_addr; // @[dpath.scala 99:20]
  wire [31:0] regfile__T_13_data; // @[dpath.scala 99:20]
  wire [4:0] regfile__T_13_addr; // @[dpath.scala 99:20]
  wire  regfile__T_13_mask; // @[dpath.scala 99:20]
  wire  regfile__T_13_en; // @[dpath.scala 99:20]
  wire  _T = io_ctl_pc_sel == 3'h0; // @[dpath.scala 58:34]
  wire  _T_1 = io_ctl_pc_sel == 3'h1; // @[dpath.scala 59:34]
  wire  _T_2 = io_ctl_pc_sel == 3'h2; // @[dpath.scala 60:34]
  wire  _T_3 = io_ctl_pc_sel == 3'h3; // @[dpath.scala 61:34]
  wire [4:0] rs1_addr = io_instReadIO_data[19:15]; // @[dpath.scala 89:22]
  wire  _T_14 = rs1_addr != 5'h0; // @[dpath.scala 110:32]
  wire [31:0] rs1_data = _T_14 ? regfile__T_15_data : 32'h0; // @[dpath.scala 110:21]
  wire [11:0] imm_i = io_instReadIO_data[31:20]; // @[dpath.scala 116:19]
  wire [19:0] _T_36 = imm_i[11] ? 20'hfffff : 20'h0; // @[Bitwise.scala 72:12]
  wire [31:0] imm_i_sext = {_T_36,imm_i}; // @[Cat.scala 29:58]
  wire [31:0] jump_reg_target = rs1_data + imm_i_sext; // @[dpath.scala 179:41]
  reg [31:0] pc_reg; // @[dpath.scala 66:23]
  wire [31:0] pc_plus4 = pc_reg + 32'h4; // @[dpath.scala 75:23]
  wire [19:0] imm_j = {io_instReadIO_data[31],io_instReadIO_data[19:12],io_instReadIO_data[20],io_instReadIO_data[30:21]}; // @[Cat.scala 29:58]
  wire [10:0] _T_47 = imm_j[19] ? 11'h7ff : 11'h0; // @[Bitwise.scala 72:12]
  wire [31:0] imm_j_sext = {_T_47,io_instReadIO_data[31],io_instReadIO_data[19:12],io_instReadIO_data[20],io_instReadIO_data[30:21],1'h0}; // @[Cat.scala 29:58]
  wire [31:0] jmp_target = pc_reg + imm_j_sext; // @[dpath.scala 178:29]
  wire [11:0] imm_b = {io_instReadIO_data[31],io_instReadIO_data[7],io_instReadIO_data[30:25],io_instReadIO_data[11:8]}; // @[Cat.scala 29:58]
  wire [18:0] _T_42 = imm_b[11] ? 19'h7ffff : 19'h0; // @[Bitwise.scala 72:12]
  wire [31:0] imm_b_sext = {_T_42,io_instReadIO_data[31],io_instReadIO_data[7],io_instReadIO_data[30:25],io_instReadIO_data[11:8],1'h0}; // @[Cat.scala 29:58]
  wire [31:0] br_target = pc_reg + imm_b_sext; // @[dpath.scala 177:29]
  wire [4:0] rs2_addr = io_instReadIO_data[24:20]; // @[dpath.scala 90:22]
  wire [4:0] wb_addr = io_instReadIO_data[11:7]; // @[dpath.scala 91:22]
  wire  _T_11 = wb_addr != 5'h0; // @[dpath.scala 103:28]
  wire  _T_106 = io_ctl_wb_sel == 2'h0; // @[dpath.scala 216:34]
  wire  _T_61 = io_ctl_alu_fun == 4'h0; // @[dpath.scala 159:35]
  wire  _T_49 = io_ctl_op1_sel == 2'h0; // @[dpath.scala 135:32]
  wire  _T_50 = io_ctl_op1_sel == 2'h1; // @[dpath.scala 136:32]
  wire [19:0] imm_u = io_instReadIO_data[31:12]; // @[dpath.scala 119:19]
  wire [31:0] imm_u_sext = {imm_u,12'h0}; // @[Cat.scala 29:58]
  wire  _T_51 = io_ctl_op1_sel == 2'h2; // @[dpath.scala 137:32]
  wire [31:0] imm_z = {27'h0,rs1_addr}; // @[Cat.scala 29:58]
  wire [31:0] _T_52 = _T_51 ? imm_z : 32'h0; // @[Mux.scala 98:16]
  wire [31:0] _T_53 = _T_50 ? imm_u_sext : _T_52; // @[Mux.scala 98:16]
  wire [31:0] alu_op1 = _T_49 ? rs1_data : _T_53; // @[Mux.scala 98:16]
  wire  _T_54 = io_ctl_op2_sel == 2'h0; // @[dpath.scala 143:32]
  wire  _T_16 = rs2_addr != 5'h0; // @[dpath.scala 111:32]
  wire [31:0] rs2_data = _T_16 ? regfile__T_17_data : 32'h0; // @[dpath.scala 111:21]
  wire  _T_55 = io_ctl_op2_sel == 2'h3; // @[dpath.scala 144:32]
  wire  _T_56 = io_ctl_op2_sel == 2'h1; // @[dpath.scala 145:32]
  wire  _T_57 = io_ctl_op2_sel == 2'h2; // @[dpath.scala 146:32]
  wire [11:0] imm_s = {io_instReadIO_data[31:25],wb_addr}; // @[Cat.scala 29:58]
  wire [19:0] _T_39 = imm_s[11] ? 20'hfffff : 20'h0; // @[Bitwise.scala 72:12]
  wire [31:0] imm_s_sext = {_T_39,io_instReadIO_data[31:25],wb_addr}; // @[Cat.scala 29:58]
  wire [31:0] _T_58 = _T_57 ? imm_s_sext : 32'h0; // @[Mux.scala 98:16]
  wire [31:0] _T_59 = _T_56 ? imm_i_sext : _T_58; // @[Mux.scala 98:16]
  wire [31:0] _T_60 = _T_55 ? pc_reg : _T_59; // @[Mux.scala 98:16]
  wire [31:0] alu_op2 = _T_54 ? rs2_data : _T_60; // @[Mux.scala 98:16]
  wire [31:0] _T_63 = alu_op1 + alu_op2; // @[dpath.scala 159:61]
  wire  _T_64 = io_ctl_alu_fun == 4'h1; // @[dpath.scala 160:35]
  wire [31:0] _T_66 = alu_op1 - alu_op2; // @[dpath.scala 160:61]
  wire  _T_67 = io_ctl_alu_fun == 4'h2; // @[dpath.scala 161:35]
  wire [31:0] _T_68 = alu_op1 & alu_op2; // @[dpath.scala 161:61]
  wire  _T_69 = io_ctl_alu_fun == 4'h3; // @[dpath.scala 162:35]
  wire [31:0] _T_70 = alu_op1 | alu_op2; // @[dpath.scala 162:61]
  wire  _T_71 = io_ctl_alu_fun == 4'h4; // @[dpath.scala 163:35]
  wire [31:0] _T_72 = alu_op1 ^ alu_op2; // @[dpath.scala 163:61]
  wire  _T_73 = io_ctl_alu_fun == 4'h5; // @[dpath.scala 164:35]
  wire [31:0] _T_74 = _T_49 ? rs1_data : _T_53; // @[dpath.scala 164:67]
  wire [31:0] _T_75 = _T_54 ? rs2_data : _T_60; // @[dpath.scala 164:86]
  wire  _T_76 = $signed(_T_74) < $signed(_T_75); // @[dpath.scala 164:70]
  wire  _T_77 = io_ctl_alu_fun == 4'h6; // @[dpath.scala 165:35]
  wire  _T_78 = alu_op1 < alu_op2; // @[dpath.scala 165:61]
  wire  _T_79 = io_ctl_alu_fun == 4'h7; // @[dpath.scala 166:35]
  wire [4:0] alu_shamt = alu_op2[4:0]; // @[dpath.scala 155:26]
  wire [62:0] _GEN_6 = {{31'd0}, alu_op1}; // @[dpath.scala 166:62]
  wire [62:0] _T_80 = _GEN_6 << alu_shamt; // @[dpath.scala 166:62]
  wire  _T_82 = io_ctl_alu_fun == 4'h8; // @[dpath.scala 167:35]
  wire [31:0] _T_85 = $signed(_T_74) >>> alu_shamt; // @[dpath.scala 167:90]
  wire  _T_86 = io_ctl_alu_fun == 4'h9; // @[dpath.scala 168:35]
  wire [31:0] _T_87 = alu_op1 >> alu_shamt; // @[dpath.scala 168:61]
  wire  _T_88 = io_ctl_alu_fun == 4'ha; // @[dpath.scala 169:35]
  wire [31:0] _T_89 = _T_88 ? alu_op1 : 32'h0; // @[Mux.scala 98:16]
  wire [31:0] _T_90 = _T_86 ? _T_87 : _T_89; // @[Mux.scala 98:16]
  wire [31:0] _T_91 = _T_82 ? _T_85 : _T_90; // @[Mux.scala 98:16]
  wire [32:0] _T_92 = _T_79 ? _T_80[32:0] : {{1'd0}, _T_91}; // @[Mux.scala 98:16]
  wire [32:0] _T_93 = _T_77 ? {{32'd0}, _T_78} : _T_92; // @[Mux.scala 98:16]
  wire [32:0] _T_94 = _T_73 ? {{32'd0}, _T_76} : _T_93; // @[Mux.scala 98:16]
  wire [32:0] _T_95 = _T_71 ? {{1'd0}, _T_72} : _T_94; // @[Mux.scala 98:16]
  wire [32:0] _T_96 = _T_69 ? {{1'd0}, _T_70} : _T_95; // @[Mux.scala 98:16]
  wire [32:0] _T_97 = _T_67 ? {{1'd0}, _T_68} : _T_96; // @[Mux.scala 98:16]
  wire [32:0] _T_98 = _T_64 ? {{1'd0}, _T_66} : _T_97; // @[Mux.scala 98:16]
  wire [32:0] _T_99 = _T_61 ? {{1'd0}, _T_63} : _T_98; // @[Mux.scala 98:16]
  wire [31:0] alu_out = _T_99[31:0]; // @[dpath.scala 152:23 dpath.scala 158:11]
  wire  _T_107 = io_ctl_wb_sel == 2'h1; // @[dpath.scala 217:34]
  wire  _T_108 = io_ctl_wb_sel == 2'h2; // @[dpath.scala 218:34]
  wire [31:0] _T_109 = _T_108 ? pc_plus4 : alu_out; // @[Mux.scala 98:16]
  wire [31:0] _T_110 = _T_107 ? io_dataReadIO_data : _T_109; // @[Mux.scala 98:16]
  wire [31:0] _T_113 = _T_14 ? regfile__T_15_data : 32'h0; // @[dpath.scala 230:36]
  wire [31:0] _T_114 = _T_16 ? regfile__T_17_data : 32'h0; // @[dpath.scala 230:56]
  wire [31:0] _T_149_0 = regfile__T_117_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_1 = regfile__T_118_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_2 = regfile__T_119_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_3 = regfile__T_120_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_4 = regfile__T_121_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_5 = regfile__T_122_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_6 = regfile__T_123_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_7 = regfile__T_124_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_8 = regfile__T_125_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_9 = regfile__T_126_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_10 = regfile__T_127_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_11 = regfile__T_128_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_12 = regfile__T_129_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_13 = regfile__T_130_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_14 = regfile__T_131_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_15 = regfile__T_132_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_16 = regfile__T_133_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_17 = regfile__T_134_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_18 = regfile__T_135_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_19 = regfile__T_136_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_20 = regfile__T_137_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_21 = regfile__T_138_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_22 = regfile__T_139_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_23 = regfile__T_140_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_24 = regfile__T_141_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_25 = regfile__T_142_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_26 = regfile__T_143_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_27 = regfile__T_144_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_28 = regfile__T_145_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_29 = regfile__T_146_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_30 = regfile__T_147_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  wire [31:0] _T_149_31 = regfile__T_148_data; // @[dpath.scala 239:32 dpath.scala 239:32]
  assign regfile__T_15_addr = io_instReadIO_data[19:15];
  assign regfile__T_15_data = regfile[regfile__T_15_addr]; // @[dpath.scala 99:20]
  assign regfile__T_17_addr = io_instReadIO_data[24:20];
  assign regfile__T_17_data = regfile[regfile__T_17_addr]; // @[dpath.scala 99:20]
  assign regfile__T_117_addr = 5'h0;
  assign regfile__T_117_data = regfile[regfile__T_117_addr]; // @[dpath.scala 99:20]
  assign regfile__T_118_addr = 5'h1;
  assign regfile__T_118_data = regfile[regfile__T_118_addr]; // @[dpath.scala 99:20]
  assign regfile__T_119_addr = 5'h2;
  assign regfile__T_119_data = regfile[regfile__T_119_addr]; // @[dpath.scala 99:20]
  assign regfile__T_120_addr = 5'h3;
  assign regfile__T_120_data = regfile[regfile__T_120_addr]; // @[dpath.scala 99:20]
  assign regfile__T_121_addr = 5'h4;
  assign regfile__T_121_data = regfile[regfile__T_121_addr]; // @[dpath.scala 99:20]
  assign regfile__T_122_addr = 5'h5;
  assign regfile__T_122_data = regfile[regfile__T_122_addr]; // @[dpath.scala 99:20]
  assign regfile__T_123_addr = 5'h6;
  assign regfile__T_123_data = regfile[regfile__T_123_addr]; // @[dpath.scala 99:20]
  assign regfile__T_124_addr = 5'h7;
  assign regfile__T_124_data = regfile[regfile__T_124_addr]; // @[dpath.scala 99:20]
  assign regfile__T_125_addr = 5'h8;
  assign regfile__T_125_data = regfile[regfile__T_125_addr]; // @[dpath.scala 99:20]
  assign regfile__T_126_addr = 5'h9;
  assign regfile__T_126_data = regfile[regfile__T_126_addr]; // @[dpath.scala 99:20]
  assign regfile__T_127_addr = 5'ha;
  assign regfile__T_127_data = regfile[regfile__T_127_addr]; // @[dpath.scala 99:20]
  assign regfile__T_128_addr = 5'hb;
  assign regfile__T_128_data = regfile[regfile__T_128_addr]; // @[dpath.scala 99:20]
  assign regfile__T_129_addr = 5'hc;
  assign regfile__T_129_data = regfile[regfile__T_129_addr]; // @[dpath.scala 99:20]
  assign regfile__T_130_addr = 5'hd;
  assign regfile__T_130_data = regfile[regfile__T_130_addr]; // @[dpath.scala 99:20]
  assign regfile__T_131_addr = 5'he;
  assign regfile__T_131_data = regfile[regfile__T_131_addr]; // @[dpath.scala 99:20]
  assign regfile__T_132_addr = 5'hf;
  assign regfile__T_132_data = regfile[regfile__T_132_addr]; // @[dpath.scala 99:20]
  assign regfile__T_133_addr = 5'h10;
  assign regfile__T_133_data = regfile[regfile__T_133_addr]; // @[dpath.scala 99:20]
  assign regfile__T_134_addr = 5'h11;
  assign regfile__T_134_data = regfile[regfile__T_134_addr]; // @[dpath.scala 99:20]
  assign regfile__T_135_addr = 5'h12;
  assign regfile__T_135_data = regfile[regfile__T_135_addr]; // @[dpath.scala 99:20]
  assign regfile__T_136_addr = 5'h13;
  assign regfile__T_136_data = regfile[regfile__T_136_addr]; // @[dpath.scala 99:20]
  assign regfile__T_137_addr = 5'h14;
  assign regfile__T_137_data = regfile[regfile__T_137_addr]; // @[dpath.scala 99:20]
  assign regfile__T_138_addr = 5'h15;
  assign regfile__T_138_data = regfile[regfile__T_138_addr]; // @[dpath.scala 99:20]
  assign regfile__T_139_addr = 5'h16;
  assign regfile__T_139_data = regfile[regfile__T_139_addr]; // @[dpath.scala 99:20]
  assign regfile__T_140_addr = 5'h17;
  assign regfile__T_140_data = regfile[regfile__T_140_addr]; // @[dpath.scala 99:20]
  assign regfile__T_141_addr = 5'h18;
  assign regfile__T_141_data = regfile[regfile__T_141_addr]; // @[dpath.scala 99:20]
  assign regfile__T_142_addr = 5'h19;
  assign regfile__T_142_data = regfile[regfile__T_142_addr]; // @[dpath.scala 99:20]
  assign regfile__T_143_addr = 5'h1a;
  assign regfile__T_143_data = regfile[regfile__T_143_addr]; // @[dpath.scala 99:20]
  assign regfile__T_144_addr = 5'h1b;
  assign regfile__T_144_data = regfile[regfile__T_144_addr]; // @[dpath.scala 99:20]
  assign regfile__T_145_addr = 5'h1c;
  assign regfile__T_145_data = regfile[regfile__T_145_addr]; // @[dpath.scala 99:20]
  assign regfile__T_146_addr = 5'h1d;
  assign regfile__T_146_data = regfile[regfile__T_146_addr]; // @[dpath.scala 99:20]
  assign regfile__T_147_addr = 5'h1e;
  assign regfile__T_147_data = regfile[regfile__T_147_addr]; // @[dpath.scala 99:20]
  assign regfile__T_148_addr = 5'h1f;
  assign regfile__T_148_data = regfile[regfile__T_148_addr]; // @[dpath.scala 99:20]
  assign regfile__T_13_data = _T_106 ? alu_out : _T_110;
  assign regfile__T_13_addr = io_instReadIO_data[11:7];
  assign regfile__T_13_mask = 1'h1;
  assign regfile__T_13_en = io_ctl_rf_wen & _T_11;
  assign io_instReadIO_addr = pc_reg; // @[dpath.scala 82:22]
  assign io_dataReadIO_addr = _T_99[31:0]; // @[dpath.scala 214:22]
  assign io_dataWriteIO_addr = _T_99[31:0]; // @[dpath.scala 236:23]
  assign io_dataWriteIO_data = _T_16 ? regfile__T_17_data : 32'h0; // @[dpath.scala 237:23]
  assign io_dat_inst = io_instReadIO_data; // @[dpath.scala 228:17]
  assign io_dat_br_eq = rs1_data == rs2_data; // @[dpath.scala 229:17]
  assign io_dat_br_lt = $signed(_T_113) < $signed(_T_114); // @[dpath.scala 230:17]
  assign io_dat_br_ltu = rs1_data < rs2_data; // @[dpath.scala 231:17]
  assign _T_149_0_0 = _T_149_0;
  assign _T_149_0_1 = _T_149_1;
  assign _T_149_0_2 = _T_149_2;
  assign _T_149_0_3 = _T_149_3;
  assign _T_149_0_4 = _T_149_4;
  assign _T_149_0_5 = _T_149_5;
  assign _T_149_0_6 = _T_149_6;
  assign _T_149_0_7 = _T_149_7;
  assign _T_149_0_8 = _T_149_8;
  assign _T_149_0_9 = _T_149_9;
  assign _T_149_0_10 = _T_149_10;
  assign _T_149_0_11 = _T_149_11;
  assign _T_149_0_12 = _T_149_12;
  assign _T_149_0_13 = _T_149_13;
  assign _T_149_0_14 = _T_149_14;
  assign _T_149_0_15 = _T_149_15;
  assign _T_149_0_16 = _T_149_16;
  assign _T_149_0_17 = _T_149_17;
  assign _T_149_0_18 = _T_149_18;
  assign _T_149_0_19 = _T_149_19;
  assign _T_149_0_20 = _T_149_20;
  assign _T_149_0_21 = _T_149_21;
  assign _T_149_0_22 = _T_149_22;
  assign _T_149_0_23 = _T_149_23;
  assign _T_149_0_24 = _T_149_24;
  assign _T_149_0_25 = _T_149_25;
  assign _T_149_0_26 = _T_149_26;
  assign _T_149_0_27 = _T_149_27;
  assign _T_149_0_28 = _T_149_28;
  assign _T_149_0_29 = _T_149_29;
  assign _T_149_0_30 = _T_149_30;
  assign _T_149_0_31 = _T_149_31;
  assign pc_reg_0 = pc_reg;
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
  _RAND_0 = {1{`RANDOM}};
  for (initvar = 0; initvar < 32; initvar = initvar+1)
    regfile[initvar] = _RAND_0[31:0];
`endif // RANDOMIZE_MEM_INIT
`ifdef RANDOMIZE_REG_INIT
  _RAND_1 = {1{`RANDOM}};
  pc_reg = _RAND_1[31:0];
`endif // RANDOMIZE_REG_INIT
  `endif // RANDOMIZE
end // initial
`ifdef FIRRTL_AFTER_INITIAL
`FIRRTL_AFTER_INITIAL
`endif
`endif // SYNTHESIS
  always @(posedge clock) begin
    if(regfile__T_13_en & regfile__T_13_mask) begin
      regfile[regfile__T_13_addr] <= regfile__T_13_data; // @[dpath.scala 99:20]
    end
    if (reset) begin
      pc_reg <= 32'h80000000;
    end else if (_T) begin
      pc_reg <= pc_plus4;
    end else if (_T_1) begin
      pc_reg <= br_target;
    end else if (_T_2) begin
      pc_reg <= jmp_target;
    end else if (_T_3) begin
      pc_reg <= jump_reg_target;
    end else begin
      pc_reg <= pc_plus4;
    end
  end
endmodule
module core(
  input         clock,
  input         reset,
  output [31:0] io_instReadIO_addr,
  input  [31:0] io_instReadIO_data,
  output [31:0] io_dataReadIO_addr,
  input  [31:0] io_dataReadIO_data,
  output [31:0] io_dataWriteIO_addr,
  output [31:0] io_dataWriteIO_data,
  output [31:0] _T_149_0,
  output [31:0] _T_149_1,
  output [31:0] _T_149_2,
  output [31:0] _T_149_3,
  output [31:0] _T_149_4,
  output [31:0] _T_149_5,
  output [31:0] _T_149_6,
  output [31:0] _T_149_7,
  output [31:0] _T_149_8,
  output [31:0] _T_149_9,
  output [31:0] _T_149_10,
  output [31:0] _T_149_11,
  output [31:0] _T_149_12,
  output [31:0] _T_149_13,
  output [31:0] _T_149_14,
  output [31:0] _T_149_15,
  output [31:0] _T_149_16,
  output [31:0] _T_149_17,
  output [31:0] _T_149_18,
  output [31:0] _T_149_19,
  output [31:0] _T_149_20,
  output [31:0] _T_149_21,
  output [31:0] _T_149_22,
  output [31:0] _T_149_23,
  output [31:0] _T_149_24,
  output [31:0] _T_149_25,
  output [31:0] _T_149_26,
  output [31:0] _T_149_27,
  output [31:0] _T_149_28,
  output [31:0] _T_149_29,
  output [31:0] _T_149_30,
  output [31:0] _T_149_31,
  output [31:0] pc_reg
);
  wire [31:0] cpath_io_dat_inst; // @[core.scala 14:21]
  wire  cpath_io_dat_br_eq; // @[core.scala 14:21]
  wire  cpath_io_dat_br_lt; // @[core.scala 14:21]
  wire  cpath_io_dat_br_ltu; // @[core.scala 14:21]
  wire [2:0] cpath_io_ctl_pc_sel; // @[core.scala 14:21]
  wire [1:0] cpath_io_ctl_op1_sel; // @[core.scala 14:21]
  wire [1:0] cpath_io_ctl_op2_sel; // @[core.scala 14:21]
  wire [3:0] cpath_io_ctl_alu_fun; // @[core.scala 14:21]
  wire [1:0] cpath_io_ctl_wb_sel; // @[core.scala 14:21]
  wire  cpath_io_ctl_rf_wen; // @[core.scala 14:21]
  wire  dpath_clock; // @[core.scala 15:21]
  wire  dpath_reset; // @[core.scala 15:21]
  wire [31:0] dpath_io_instReadIO_addr; // @[core.scala 15:21]
  wire [31:0] dpath_io_instReadIO_data; // @[core.scala 15:21]
  wire [31:0] dpath_io_dataReadIO_addr; // @[core.scala 15:21]
  wire [31:0] dpath_io_dataReadIO_data; // @[core.scala 15:21]
  wire [31:0] dpath_io_dataWriteIO_addr; // @[core.scala 15:21]
  wire [31:0] dpath_io_dataWriteIO_data; // @[core.scala 15:21]
  wire [2:0] dpath_io_ctl_pc_sel; // @[core.scala 15:21]
  wire [1:0] dpath_io_ctl_op1_sel; // @[core.scala 15:21]
  wire [1:0] dpath_io_ctl_op2_sel; // @[core.scala 15:21]
  wire [3:0] dpath_io_ctl_alu_fun; // @[core.scala 15:21]
  wire [1:0] dpath_io_ctl_wb_sel; // @[core.scala 15:21]
  wire  dpath_io_ctl_rf_wen; // @[core.scala 15:21]
  wire [31:0] dpath_io_dat_inst; // @[core.scala 15:21]
  wire  dpath_io_dat_br_eq; // @[core.scala 15:21]
  wire  dpath_io_dat_br_lt; // @[core.scala 15:21]
  wire  dpath_io_dat_br_ltu; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_0; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_1; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_2; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_3; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_4; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_5; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_6; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_7; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_8; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_9; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_10; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_11; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_12; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_13; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_14; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_15; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_16; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_17; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_18; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_19; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_20; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_21; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_22; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_23; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_24; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_25; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_26; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_27; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_28; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_29; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_30; // @[core.scala 15:21]
  wire [31:0] dpath__T_149_0_31; // @[core.scala 15:21]
  wire [31:0] dpath_pc_reg_0; // @[core.scala 15:21]
  cpath cpath ( // @[core.scala 14:21]
    .io_dat_inst(cpath_io_dat_inst),
    .io_dat_br_eq(cpath_io_dat_br_eq),
    .io_dat_br_lt(cpath_io_dat_br_lt),
    .io_dat_br_ltu(cpath_io_dat_br_ltu),
    .io_ctl_pc_sel(cpath_io_ctl_pc_sel),
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
    .io_dataReadIO_addr(dpath_io_dataReadIO_addr),
    .io_dataReadIO_data(dpath_io_dataReadIO_data),
    .io_dataWriteIO_addr(dpath_io_dataWriteIO_addr),
    .io_dataWriteIO_data(dpath_io_dataWriteIO_data),
    .io_ctl_pc_sel(dpath_io_ctl_pc_sel),
    .io_ctl_op1_sel(dpath_io_ctl_op1_sel),
    .io_ctl_op2_sel(dpath_io_ctl_op2_sel),
    .io_ctl_alu_fun(dpath_io_ctl_alu_fun),
    .io_ctl_wb_sel(dpath_io_ctl_wb_sel),
    .io_ctl_rf_wen(dpath_io_ctl_rf_wen),
    .io_dat_inst(dpath_io_dat_inst),
    .io_dat_br_eq(dpath_io_dat_br_eq),
    .io_dat_br_lt(dpath_io_dat_br_lt),
    .io_dat_br_ltu(dpath_io_dat_br_ltu),
    ._T_149_0_0(dpath__T_149_0_0),
    ._T_149_0_1(dpath__T_149_0_1),
    ._T_149_0_2(dpath__T_149_0_2),
    ._T_149_0_3(dpath__T_149_0_3),
    ._T_149_0_4(dpath__T_149_0_4),
    ._T_149_0_5(dpath__T_149_0_5),
    ._T_149_0_6(dpath__T_149_0_6),
    ._T_149_0_7(dpath__T_149_0_7),
    ._T_149_0_8(dpath__T_149_0_8),
    ._T_149_0_9(dpath__T_149_0_9),
    ._T_149_0_10(dpath__T_149_0_10),
    ._T_149_0_11(dpath__T_149_0_11),
    ._T_149_0_12(dpath__T_149_0_12),
    ._T_149_0_13(dpath__T_149_0_13),
    ._T_149_0_14(dpath__T_149_0_14),
    ._T_149_0_15(dpath__T_149_0_15),
    ._T_149_0_16(dpath__T_149_0_16),
    ._T_149_0_17(dpath__T_149_0_17),
    ._T_149_0_18(dpath__T_149_0_18),
    ._T_149_0_19(dpath__T_149_0_19),
    ._T_149_0_20(dpath__T_149_0_20),
    ._T_149_0_21(dpath__T_149_0_21),
    ._T_149_0_22(dpath__T_149_0_22),
    ._T_149_0_23(dpath__T_149_0_23),
    ._T_149_0_24(dpath__T_149_0_24),
    ._T_149_0_25(dpath__T_149_0_25),
    ._T_149_0_26(dpath__T_149_0_26),
    ._T_149_0_27(dpath__T_149_0_27),
    ._T_149_0_28(dpath__T_149_0_28),
    ._T_149_0_29(dpath__T_149_0_29),
    ._T_149_0_30(dpath__T_149_0_30),
    ._T_149_0_31(dpath__T_149_0_31),
    .pc_reg_0(dpath_pc_reg_0)
  );
  assign io_instReadIO_addr = dpath_io_instReadIO_addr; // @[core.scala 18:17]
  assign io_dataReadIO_addr = dpath_io_dataReadIO_addr; // @[core.scala 19:17]
  assign io_dataWriteIO_addr = dpath_io_dataWriteIO_addr; // @[core.scala 20:18]
  assign io_dataWriteIO_data = dpath_io_dataWriteIO_data; // @[core.scala 20:18]
  assign _T_149_0 = dpath__T_149_0_0;
  assign _T_149_1 = dpath__T_149_0_1;
  assign _T_149_2 = dpath__T_149_0_2;
  assign _T_149_3 = dpath__T_149_0_3;
  assign _T_149_4 = dpath__T_149_0_4;
  assign _T_149_5 = dpath__T_149_0_5;
  assign _T_149_6 = dpath__T_149_0_6;
  assign _T_149_7 = dpath__T_149_0_7;
  assign _T_149_8 = dpath__T_149_0_8;
  assign _T_149_9 = dpath__T_149_0_9;
  assign _T_149_10 = dpath__T_149_0_10;
  assign _T_149_11 = dpath__T_149_0_11;
  assign _T_149_12 = dpath__T_149_0_12;
  assign _T_149_13 = dpath__T_149_0_13;
  assign _T_149_14 = dpath__T_149_0_14;
  assign _T_149_15 = dpath__T_149_0_15;
  assign _T_149_16 = dpath__T_149_0_16;
  assign _T_149_17 = dpath__T_149_0_17;
  assign _T_149_18 = dpath__T_149_0_18;
  assign _T_149_19 = dpath__T_149_0_19;
  assign _T_149_20 = dpath__T_149_0_20;
  assign _T_149_21 = dpath__T_149_0_21;
  assign _T_149_22 = dpath__T_149_0_22;
  assign _T_149_23 = dpath__T_149_0_23;
  assign _T_149_24 = dpath__T_149_0_24;
  assign _T_149_25 = dpath__T_149_0_25;
  assign _T_149_26 = dpath__T_149_0_26;
  assign _T_149_27 = dpath__T_149_0_27;
  assign _T_149_28 = dpath__T_149_0_28;
  assign _T_149_29 = dpath__T_149_0_29;
  assign _T_149_30 = dpath__T_149_0_30;
  assign _T_149_31 = dpath__T_149_0_31;
  assign pc_reg = dpath_pc_reg_0;
  assign cpath_io_dat_inst = dpath_io_dat_inst; // @[core.scala 24:16]
  assign cpath_io_dat_br_eq = dpath_io_dat_br_eq; // @[core.scala 24:16]
  assign cpath_io_dat_br_lt = dpath_io_dat_br_lt; // @[core.scala 24:16]
  assign cpath_io_dat_br_ltu = dpath_io_dat_br_ltu; // @[core.scala 24:16]
  assign dpath_clock = clock;
  assign dpath_reset = reset;
  assign dpath_io_instReadIO_data = io_instReadIO_data; // @[core.scala 18:17]
  assign dpath_io_dataReadIO_data = io_dataReadIO_data; // @[core.scala 19:17]
  assign dpath_io_ctl_pc_sel = cpath_io_ctl_pc_sel; // @[core.scala 23:16]
  assign dpath_io_ctl_op1_sel = cpath_io_ctl_op1_sel; // @[core.scala 23:16]
  assign dpath_io_ctl_op2_sel = cpath_io_ctl_op2_sel; // @[core.scala 23:16]
  assign dpath_io_ctl_alu_fun = cpath_io_ctl_alu_fun; // @[core.scala 23:16]
  assign dpath_io_ctl_wb_sel = cpath_io_ctl_wb_sel; // @[core.scala 23:16]
  assign dpath_io_ctl_rf_wen = cpath_io_ctl_rf_wen; // @[core.scala 23:16]
endmodule
module simTop(
  input         clock,
  input         reset,
  output [31:0] io_diffTestIO_regfile_0,
  output [31:0] io_diffTestIO_regfile_1,
  output [31:0] io_diffTestIO_regfile_2,
  output [31:0] io_diffTestIO_regfile_3,
  output [31:0] io_diffTestIO_regfile_4,
  output [31:0] io_diffTestIO_regfile_5,
  output [31:0] io_diffTestIO_regfile_6,
  output [31:0] io_diffTestIO_regfile_7,
  output [31:0] io_diffTestIO_regfile_8,
  output [31:0] io_diffTestIO_regfile_9,
  output [31:0] io_diffTestIO_regfile_10,
  output [31:0] io_diffTestIO_regfile_11,
  output [31:0] io_diffTestIO_regfile_12,
  output [31:0] io_diffTestIO_regfile_13,
  output [31:0] io_diffTestIO_regfile_14,
  output [31:0] io_diffTestIO_regfile_15,
  output [31:0] io_diffTestIO_regfile_16,
  output [31:0] io_diffTestIO_regfile_17,
  output [31:0] io_diffTestIO_regfile_18,
  output [31:0] io_diffTestIO_regfile_19,
  output [31:0] io_diffTestIO_regfile_20,
  output [31:0] io_diffTestIO_regfile_21,
  output [31:0] io_diffTestIO_regfile_22,
  output [31:0] io_diffTestIO_regfile_23,
  output [31:0] io_diffTestIO_regfile_24,
  output [31:0] io_diffTestIO_regfile_25,
  output [31:0] io_diffTestIO_regfile_26,
  output [31:0] io_diffTestIO_regfile_27,
  output [31:0] io_diffTestIO_regfile_28,
  output [31:0] io_diffTestIO_regfile_29,
  output [31:0] io_diffTestIO_regfile_30,
  output [31:0] io_diffTestIO_regfile_31,
  output [31:0] io_diffTestIO_pc,
  output [31:0] io_coreIO_instReadIO_addr,
  input  [31:0] io_coreIO_instReadIO_data,
  output        io_coreIO_instReadIO_en,
  output [31:0] io_coreIO_dataReadIO_addr,
  input  [31:0] io_coreIO_dataReadIO_data,
  output        io_coreIO_dataReadIO_en,
  output [31:0] io_coreIO_dataWriteIO_addr,
  output [31:0] io_coreIO_dataWriteIO_data,
  output        io_coreIO_dataWriteIO_en
);
  wire  mycore_clock; // @[simTop.scala 15:22]
  wire  mycore_reset; // @[simTop.scala 15:22]
  wire [31:0] mycore_io_instReadIO_addr; // @[simTop.scala 15:22]
  wire [31:0] mycore_io_instReadIO_data; // @[simTop.scala 15:22]
  wire [31:0] mycore_io_dataReadIO_addr; // @[simTop.scala 15:22]
  wire [31:0] mycore_io_dataReadIO_data; // @[simTop.scala 15:22]
  wire [31:0] mycore_io_dataWriteIO_addr; // @[simTop.scala 15:22]
  wire [31:0] mycore_io_dataWriteIO_data; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_0; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_1; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_2; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_3; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_4; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_5; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_6; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_7; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_8; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_9; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_10; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_11; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_12; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_13; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_14; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_15; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_16; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_17; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_18; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_19; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_20; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_21; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_22; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_23; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_24; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_25; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_26; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_27; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_28; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_29; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_30; // @[simTop.scala 15:22]
  wire [31:0] mycore__T_149_31; // @[simTop.scala 15:22]
  wire [31:0] mycore_pc_reg; // @[simTop.scala 15:22]
  core mycore ( // @[simTop.scala 15:22]
    .clock(mycore_clock),
    .reset(mycore_reset),
    .io_instReadIO_addr(mycore_io_instReadIO_addr),
    .io_instReadIO_data(mycore_io_instReadIO_data),
    .io_dataReadIO_addr(mycore_io_dataReadIO_addr),
    .io_dataReadIO_data(mycore_io_dataReadIO_data),
    .io_dataWriteIO_addr(mycore_io_dataWriteIO_addr),
    .io_dataWriteIO_data(mycore_io_dataWriteIO_data),
    ._T_149_0(mycore__T_149_0),
    ._T_149_1(mycore__T_149_1),
    ._T_149_2(mycore__T_149_2),
    ._T_149_3(mycore__T_149_3),
    ._T_149_4(mycore__T_149_4),
    ._T_149_5(mycore__T_149_5),
    ._T_149_6(mycore__T_149_6),
    ._T_149_7(mycore__T_149_7),
    ._T_149_8(mycore__T_149_8),
    ._T_149_9(mycore__T_149_9),
    ._T_149_10(mycore__T_149_10),
    ._T_149_11(mycore__T_149_11),
    ._T_149_12(mycore__T_149_12),
    ._T_149_13(mycore__T_149_13),
    ._T_149_14(mycore__T_149_14),
    ._T_149_15(mycore__T_149_15),
    ._T_149_16(mycore__T_149_16),
    ._T_149_17(mycore__T_149_17),
    ._T_149_18(mycore__T_149_18),
    ._T_149_19(mycore__T_149_19),
    ._T_149_20(mycore__T_149_20),
    ._T_149_21(mycore__T_149_21),
    ._T_149_22(mycore__T_149_22),
    ._T_149_23(mycore__T_149_23),
    ._T_149_24(mycore__T_149_24),
    ._T_149_25(mycore__T_149_25),
    ._T_149_26(mycore__T_149_26),
    ._T_149_27(mycore__T_149_27),
    ._T_149_28(mycore__T_149_28),
    ._T_149_29(mycore__T_149_29),
    ._T_149_30(mycore__T_149_30),
    ._T_149_31(mycore__T_149_31),
    .pc_reg(mycore_pc_reg)
  );
  assign io_diffTestIO_regfile_0 = mycore__T_149_0;
  assign io_diffTestIO_regfile_1 = mycore__T_149_1;
  assign io_diffTestIO_regfile_2 = mycore__T_149_2;
  assign io_diffTestIO_regfile_3 = mycore__T_149_3;
  assign io_diffTestIO_regfile_4 = mycore__T_149_4;
  assign io_diffTestIO_regfile_5 = mycore__T_149_5;
  assign io_diffTestIO_regfile_6 = mycore__T_149_6;
  assign io_diffTestIO_regfile_7 = mycore__T_149_7;
  assign io_diffTestIO_regfile_8 = mycore__T_149_8;
  assign io_diffTestIO_regfile_9 = mycore__T_149_9;
  assign io_diffTestIO_regfile_10 = mycore__T_149_10;
  assign io_diffTestIO_regfile_11 = mycore__T_149_11;
  assign io_diffTestIO_regfile_12 = mycore__T_149_12;
  assign io_diffTestIO_regfile_13 = mycore__T_149_13;
  assign io_diffTestIO_regfile_14 = mycore__T_149_14;
  assign io_diffTestIO_regfile_15 = mycore__T_149_15;
  assign io_diffTestIO_regfile_16 = mycore__T_149_16;
  assign io_diffTestIO_regfile_17 = mycore__T_149_17;
  assign io_diffTestIO_regfile_18 = mycore__T_149_18;
  assign io_diffTestIO_regfile_19 = mycore__T_149_19;
  assign io_diffTestIO_regfile_20 = mycore__T_149_20;
  assign io_diffTestIO_regfile_21 = mycore__T_149_21;
  assign io_diffTestIO_regfile_22 = mycore__T_149_22;
  assign io_diffTestIO_regfile_23 = mycore__T_149_23;
  assign io_diffTestIO_regfile_24 = mycore__T_149_24;
  assign io_diffTestIO_regfile_25 = mycore__T_149_25;
  assign io_diffTestIO_regfile_26 = mycore__T_149_26;
  assign io_diffTestIO_regfile_27 = mycore__T_149_27;
  assign io_diffTestIO_regfile_28 = mycore__T_149_28;
  assign io_diffTestIO_regfile_29 = mycore__T_149_29;
  assign io_diffTestIO_regfile_30 = mycore__T_149_30;
  assign io_diffTestIO_regfile_31 = mycore__T_149_31;
  assign io_diffTestIO_pc = mycore_pc_reg;
  assign io_coreIO_instReadIO_addr = mycore_io_instReadIO_addr; // @[simTop.scala 18:13]
  assign io_coreIO_instReadIO_en = 1'h1; // @[simTop.scala 18:13]
  assign io_coreIO_dataReadIO_addr = mycore_io_dataReadIO_addr; // @[simTop.scala 18:13]
  assign io_coreIO_dataReadIO_en = 1'h1; // @[simTop.scala 18:13]
  assign io_coreIO_dataWriteIO_addr = mycore_io_dataWriteIO_addr; // @[simTop.scala 18:13]
  assign io_coreIO_dataWriteIO_data = mycore_io_dataWriteIO_data; // @[simTop.scala 18:13]
  assign io_coreIO_dataWriteIO_en = 1'h1; // @[simTop.scala 18:13]
  assign mycore_clock = clock;
  assign mycore_reset = reset;
  assign mycore_io_instReadIO_data = io_coreIO_instReadIO_data; // @[simTop.scala 18:13]
  assign mycore_io_dataReadIO_data = io_coreIO_dataReadIO_data; // @[simTop.scala 18:13]
endmodule
