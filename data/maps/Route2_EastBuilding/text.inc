Route2_EastBuilding_Text_GiveHM05IfSeen10Mons:
    .string "Merhaba! Beni hatırladın mı?\n"
    .string "PROF. OAK'ın asistanlarından\l"
    .string "biriyim.\p"
    .string "POKéDEX'inde en az 10 tür\n"
    .string "kayıtlıysa, sana ödül\l"
    .string "vermem gerekiyor.\p"
    .string "PROF. OAK bana senin için\n"
    .string "HM05'i emanet etti.\p"
    .string "Öyleyse, {PLAYER}\p"
    .string "En az on çeşit POKéMON hakkında\n"
    .string "veri topladın mı?$"

Route2_EastBuilding_Text_GreatHereYouGo:
    .string "Harika! {STR_VAR_3} çeşit POKéMON\n"
    .string "yakalamış veya sahip olmuşsun!\p"
    .string "Tebrikler!\n"
    .string "İşte bu eşya senin!$"

Route2_EastBuilding_Text_ReceivedHM05FromAide:
    .string "{PLAYER} ASİSTAN'dan\n"
    .string "HM05 aldı.$"

Route2_EastBuilding_Text_ExplainHM05:
    .string "HM05 gizli hareket\n"
    .if ENG_MOVES == 1
    .string "FLASH'ı içerir.\p"
    .string "FLASH, en karanlık mağaraları ve\n"
    .else
    .string "FLAŞ'ı içerir.\p"
    .string "FLAŞ, en karanlık mağaraları ve\n"
    .endif
    .string "yeraltı şehirlerini aydınlatır.$"

Route2_EastBuilding_Text_CanGetThroughRockTunnel:
    .if ENG_MOVES == 1
    .string "Bir POKéMON, FLASH\n"
    .else
    .string "Bir POKéMON, FLAŞ\n"
    .endif
    .string "hamlesini öğrendiğinde,\l"
    .string "KAYA TÜNELİ'ni geçebilirsin.$"
