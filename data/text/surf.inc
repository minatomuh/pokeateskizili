Text_WantToSurf::
  .string "Su masmavi görünüyor…\nSörf yapmak ister misiniz?$"

Text_UsedSurf::
  .if ENG_MOVES == 1
  .string "{STR_VAR_1}, SURF kullandı!$"
	.else
  .string "{STR_VAR_1}, SÖRF kullandı!$"
	.endif

Text_CurrentTooFast::
  .if ENG_MOVES == 1
  .string "Akıntı çok hızlı!\n"
  .string "SURF burada kullanılamaz…$"
	.else
  .string "Akıntı çok hızlı!\n"
  .string "SÖRF burada kullanılamaz…$"
	.endif

