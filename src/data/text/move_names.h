const u8 gMoveNames[MOVES_COUNT][MOVE_NAME_LENGTH + 1] = {
    [MOVE_NONE]          = _("-$$$$$$"),
    [MOVE_POUND]         = _("VUR"),
    [MOVE_KARATE_CHOP]   = _("KARATE BİÇİŞ"),
    [MOVE_DOUBLE_SLAP]   = _("ÇİFT"),
    [MOVE_COMET_PUNCH]   = _("YILDIZYUMRUK"),
    [MOVE_MEGA_PUNCH]    = _("MEGA YUMRUK"),
    [MOVE_PAY_DAY]       = _("HESAP GÜNÜ"),
    [MOVE_FIRE_PUNCH]    = _("ATEŞ YUMRUĞU"),
    [MOVE_ICE_PUNCH]     = _("BUZ YUMRUĞU"),
    [MOVE_THUNDER_PUNCH] = _("ŞİMŞEKYUMRUK"),
    [MOVE_SCRATCH]       = _("TIRMALA"),
    [MOVE_VICE_GRIP]     = _("KISKAÇ"),
    [MOVE_GUILLOTINE]    = _("GİYOTİN"),
    [MOVE_RAZOR_WIND]    = _("JİLET RÜZGAR"),
    [MOVE_SWORDS_DANCE]  = _("KILIÇ DANSI"),
    [MOVE_CUT]           = _("KES"),
    [MOVE_GUST]          = _("KASIRGA"),
    [MOVE_WING_ATTACK]   = _("KANAT VURUŞU"),
    [MOVE_WHIRLWIND]     = _("KASIRGA"),
    [MOVE_FLY]           = _("UÇ"),
    [MOVE_BIND]          = _("BAĞLA"),
    [MOVE_SLAM]          = _("ÇARP"),
    [MOVE_VINE_WHIP]     = _("KAMÇI YAPRAK"),
    [MOVE_STOMP]         = _("EZME"),
    [MOVE_DOUBLE_KICK]   = _("ÇİFTE TEKME"),
    [MOVE_MEGA_KICK]     = _("MEGA TEKME"),
    [MOVE_JUMP_KICK]     = _("HAVADA TEKME"),
    [MOVE_ROLLING_KICK]  = _("DÖNEN TEKME"),
    [MOVE_SAND_ATTACK]   = _("KUMSALDIRISI"),
    [MOVE_HEADBUTT]      = _("KAFA DARBESİ"),
    [MOVE_HORN_ATTACK]   = _("BOYNUZVURUŞU"),
    [MOVE_FURY_ATTACK]   = _("ÖFKE VURUŞU"),
    [MOVE_HORN_DRILL]    = _("MATKAPBOYNUZ"),
    [MOVE_TACKLE]        = _("TOSLAMA"),
    [MOVE_BODY_SLAM]     = _("VÜCUT VURUŞU"),
    [MOVE_WRAP]          = _("YAKALAMA"),
    [MOVE_TAKE_DOWN]     = _("YERE İNDİRME"),
    [MOVE_THRASH]        = _("PATAKLAMA"),
    [MOVE_DOUBLE_EDGE]   = _("RİSKLİ VURUŞ"),
    [MOVE_TAIL_WHIP]     = _("KUYRUK KAMÇI"),
    [MOVE_POISON_STING]  = _("ZEHİR İĞNE"),
    [MOVE_TWINEEDLE]     = _("ÇİFT İĞNE"),
    [MOVE_PIN_MISSILE]   = _("FÜZE İĞNE"),
    [MOVE_LEER]          = _("KESKİN BAKIŞ"),
    [MOVE_BITE]          = _("ISIR"),
    [MOVE_GROWL]         = _("ALAYLI BAKIŞ"),
    [MOVE_ROAR]          = _("KÜKRE"),
    [MOVE_SING]          = _("ŞARKI SÖYLE"),
    [MOVE_SUPERSONIC]    = _("SÜPERSONİK"),
    [MOVE_SONIC_BOOM]    = _("SONİKPATLAMA"),
    [MOVE_DISABLE]       = _("ENGELLE"),
    [MOVE_ACID]          = _("ASİT"),
    [MOVE_EMBER]         = _("KÖZ"),
    [MOVE_FLAMETHROWER]  = _("ALEV PÜSKÜR"),
    [MOVE_MIST]          = _("SİS"),
    [MOVE_WATER_GUN]     = _("SU TABANCASI"),
    [MOVE_HYDRO_PUMP]    = _("SU POMPASI"),
    [MOVE_SURF]          = _("SÖRF"),
    [MOVE_ICE_BEAM]      = _("BUZ IŞINI"),
    [MOVE_BLIZZARD]      = _("KARFIRTINASI"),
    [MOVE_PSYBEAM]       = _("PSİŞİK IŞIN"),
    [MOVE_BUBBLE_BEAM]   = _("BALONCUKIŞIN"),
    [MOVE_AURORA_BEAM]   = _("AURORAIŞINI"),
    [MOVE_HYPER_BEAM]    = _("HİPER IŞIN"),
    [MOVE_PECK]          = _("GAGALAMA"),
    [MOVE_DRILL_PECK]    = _("MATKAP GAGA"),
    [MOVE_SUBMISSION]    = _("TESLİMİYET"),
    [MOVE_LOW_KICK]      = _("ALÇAK TEKME"),
    [MOVE_COUNTER]       = _("KARŞILIK"),
    [MOVE_SEISMIC_TOSS]  = _("SİSMİK ATIŞ"),
    [MOVE_STRENGTH]      = _("GÜÇ"),
    [MOVE_ABSORB]        = _("ABSORBE ET"),
    [MOVE_MEGA_DRAIN]    = _("MEGA EMİŞ"),
    [MOVE_LEECH_SEED]    = _("EMİŞ TOHUMU"),
    [MOVE_GROWTH]        = _("BÜYÜME"),
    [MOVE_RAZOR_LEAF]    = _("JİLET YAPRAK"),
    [MOVE_SOLAR_BEAM]    = _("SOLAR IŞIN"),
    [MOVE_POISON_POWDER] = _("ZEHİR TOZU"),
    [MOVE_STUN_SPORE]    = _("FELÇ TOZU"),
    [MOVE_SLEEP_POWDER]  = _("UYKU TOZU"),
    [MOVE_PETAL_DANCE]   = _("ÇİÇEK DANSI"),
    [MOVE_STRING_SHOT]   = _("İPEK VURUŞU"),
    [MOVE_DRAGON_RAGE]   = _("EJDER ÖFKESİ"),
    [MOVE_FIRE_SPIN]     = _("ATEŞ DÖNÜŞÜ"),
    [MOVE_THUNDER_SHOCK] = _("YILDIRIMŞOKU"),
    [MOVE_THUNDERBOLT]   = _("YILDIRIM"),
    [MOVE_THUNDER_WAVE]  = _("ŞİMŞEK DALGA"),
    [MOVE_THUNDER]       = _("GÖKGÜRÜLTÜSÜ"),
    [MOVE_ROCK_THROW]    = _("KAYA ATIŞI"),
    [MOVE_EARTHQUAKE]    = _("DEPREM"),
    [MOVE_FISSURE]       = _("YARIK"),
    [MOVE_DIG]           = _("KAZ"),
    [MOVE_TOXIC]         = _("TOKSİK"),
    [MOVE_CONFUSION]     = _("AFALLAT"),
    [MOVE_PSYCHIC]       = _("PSİŞİK"),
    [MOVE_HYPNOSIS]      = _("HİPNOZ"),
    [MOVE_MEDITATE]      = _("MEDİTASYON"),
    [MOVE_AGILITY]       = _("ÇEVİKLİK"),
    [MOVE_QUICK_ATTACK]  = _("TEZ SALDIRI"),
    [MOVE_RAGE]          = _("ÖFKE"),
    [MOVE_TELEPORT]      = _("IŞINLANMA"),
    [MOVE_NIGHT_SHADE]   = _("GECE GÖLGESİ"),
    [MOVE_MIMIC]         = _("MİMİK"),
    [MOVE_SCREECH]       = _("ÇIĞLIK"),
    [MOVE_DOUBLE_TEAM]   = _("ÇİFTE TAKIM"),
    [MOVE_RECOVER]       = _("YENİLEN"),
    [MOVE_HARDEN]        = _("SERTLEŞ"),
    [MOVE_MINIMIZE]      = _("KÜÇÜL"),
    [MOVE_SMOKESCREEN]   = _("DUMAN DUVARI"),
    [MOVE_CONFUSE_RAY]   = _("AFALLA IŞINI"),
    [MOVE_WITHDRAW]      = _("GERİ ÇEK"),
    [MOVE_DEFENSE_CURL]  = _("İÇE KIVRIL"),
    [MOVE_BARRIER]       = _("BARİYER"),
    [MOVE_LIGHT_SCREEN]  = _("IŞIK DUVARI"),
    [MOVE_HAZE]          = _("PUS"),
    [MOVE_REFLECT]       = _("YANSIT"),
    [MOVE_FOCUS_ENERGY]  = _("ODAKLAN"),
    [MOVE_BIDE]          = _("SABIR"),
    [MOVE_METRONOME]     = _("METRONOM"),
    [MOVE_MIRROR_MOVE]   = _("AYNA SALDIRI"),
    [MOVE_SELF_DESTRUCT] = _("KENDİNİYOKET"),
    [MOVE_EGG_BOMB]      = _("YUMURTABOMBA"),
    [MOVE_LICK]          = _("YALA"),
    [MOVE_SMOG]          = _("DUMAN"),
    [MOVE_SLUDGE]        = _("BALÇIK"),
    [MOVE_BONE_CLUB]     = _("KEMİK SOPA"),
    [MOVE_FIRE_BLAST]    = _("ATEŞPATLAMA"),
    [MOVE_WATERFALL]     = _("ŞELALE"),
    [MOVE_CLAMP]         = _("KABUĞA KAPAN"),
    [MOVE_SWIFT]         = _("HIZ YILDIZI"),
    [MOVE_SKULL_BASH]    = _("KAFATASIATAK"),
    [MOVE_SPIKE_CANNON]  = _("DİKEN TOPU"),
    [MOVE_CONSTRICT]     = _("SARMALA"),
    [MOVE_AMNESIA]       = _("AMNEZİ"),
    [MOVE_KINESIS]       = _("KİNESİ"),
    [MOVE_SOFT_BOILED]   = _("RAFADAN"),
    [MOVE_HI_JUMP_KICK]  = _("TEPEDENTEKME"),
    [MOVE_GLARE]         = _("YILAN BAKIŞI"),
    [MOVE_DREAM_EATER]   = _("RÜYA YİYEN"),
    [MOVE_POISON_GAS]    = _("ZEHİRLİ GAZ"),
    [MOVE_BARRAGE]       = _("TOP ATIŞI"),
    [MOVE_LEECH_LIFE]    = _("CAN ÇEKİŞİ"),
    [MOVE_LOVELY_KISS]   = _("ŞEYTAN ÖPÜŞÜ"),
    [MOVE_SKY_ATTACK]    = _("GÖK ATAĞI"),
    [MOVE_TRANSFORM]     = _("DÖNÜŞÜM"),
    [MOVE_BUBBLE]        = _("BALONCUK"),
    [MOVE_DIZZY_PUNCH]   = _("SERSEMYUMRUK"),
    [MOVE_SPORE]         = _("SPOR"),
    [MOVE_FLASH]         = _("FLAŞ"),
    [MOVE_PSYWAVE]       = _("PSİ-DALGA"),
    [MOVE_SPLASH]        = _("SU SIÇRATMA"),
    [MOVE_ACID_ARMOR]    = _("ASİT ZIRHI"),
    [MOVE_CRABHAMMER]    = _("YENGEÇ ÇEKİÇ"),
    [MOVE_EXPLOSION]     = _("PATLAMA"),
    [MOVE_FURY_SWIPES]   = _("ÖFKE KESİŞİ"),
    [MOVE_BONEMERANG]    = _("KEMİKERANG"),
    [MOVE_REST]          = _("DİNLEN"),
    [MOVE_ROCK_SLIDE]    = _("KAYA DÜŞÜŞÜ"),
    [MOVE_HYPER_FANG]    = _("HİPER DİŞ"),
    [MOVE_SHARPEN]       = _("KESKİNLEŞTİR"),
    [MOVE_CONVERSION]    = _("DÖNÜŞTÜR"),
    [MOVE_TRI_ATTACK]    = _("ÜÇLÜ ATAK"),
    [MOVE_SUPER_FANG]    = _("SÜPER DİŞ"),
    [MOVE_SLASH]         = _("BİÇ"),
    [MOVE_SUBSTITUTE]    = _("KOPYA"),
    [MOVE_STRUGGLE]      = _("MÜCADELE"),
    [MOVE_SKETCH]        = _("ÇİZİK"),
    [MOVE_TRIPLE_KICK]   = _("ÜÇLÜ TEKME"),
    [MOVE_THIEF]         = _("ÇAL"),
    [MOVE_SPIDER_WEB]    = _("ÖRÜMCEK AĞI"),
    [MOVE_MIND_READER]   = _("ZİHİN OKU"),
    [MOVE_NIGHTMARE]     = _("KABUS"),
    [MOVE_FLAME_WHEEL]   = _("ALEV ÇEMBERİ"),
    [MOVE_SNORE]         = _("HORLA"),
    [MOVE_CURSE]         = _("LANET"),
    [MOVE_FLAIL]         = _("SALLAN"),
    [MOVE_CONVERSION_2]  = _("CONVERSION 2"),
    [MOVE_AEROBLAST]     = _("HAVA DARBESİ"),
    [MOVE_COTTON_SPORE]  = _("PAMUK SPORU"),
    [MOVE_REVERSAL]      = _("GERİ DÖNÜŞ"),
    [MOVE_SPITE]         = _("KİN"),
    [MOVE_POWDER_SNOW]   = _("TOZ KAR"),
    [MOVE_PROTECT]       = _("KORUN"),
    [MOVE_MACH_PUNCH]    = _("MACH YUMRUK"),
    [MOVE_SCARY_FACE]    = _("KORKUNÇ YÜZ"),
    [MOVE_FAINT_ATTACK]  = _("SİNSİ ATAK"),
    [MOVE_SWEET_KISS]    = _("TATLI ÖPÜCÜK"),
    [MOVE_BELLY_DRUM]    = _("GÖBEK DAVULU"),
    [MOVE_SLUDGE_BOMB]   = _("BALÇIK BOMBA"),
    [MOVE_MUD_SLAP]      = _("ÇAMUR TOKADI"),
    [MOVE_OCTAZOOKA]     = _("OKTAZUKA"),
    [MOVE_SPIKES]        = _("DİKEN"),
    [MOVE_ZAP_CANNON]    = _("ELEKTRİK TOP"),
    [MOVE_FORESIGHT]     = _("İLERİ GÖRÜŞ"),
    [MOVE_DESTINY_BOND]  = _("KADER BAĞI"),
    [MOVE_PERISH_SONG]   = _("ÖLÜM ŞARKISI"),
    [MOVE_ICY_WIND]      = _("SOĞUK RÜZGAR"),
    [MOVE_DETECT]        = _("TESPİT ET"),
    [MOVE_BONE_RUSH]     = _("KEMİK ÖFKESİ"),
    [MOVE_LOCK_ON]       = _("KİLİTLEN"),
    [MOVE_OUTRAGE]       = _("ÖFKE KRİZİ"),
    [MOVE_SANDSTORM]     = _("KUMFIRTINASI"),
    [MOVE_GIGA_DRAIN]    = _("GİGA EMİŞ"),
    [MOVE_ENDURE]        = _("DAYAN"),
    [MOVE_CHARM]         = _("CAZİBE"),
    [MOVE_ROLLOUT]       = _("YUVARLANMA"),
    [MOVE_FALSE_SWIPE]   = _("TERS DARBE"),
    [MOVE_SWAGGER]       = _("TERS KÖŞE"),
    [MOVE_MILK_DRINK]    = _("SÜT İÇİŞİ"),
    [MOVE_SPARK]         = _("KIVILCIM"),
    [MOVE_FURY_CUTTER]   = _("ÖFKELİ KESİŞ"),
    [MOVE_STEEL_WING]    = _("ÇELİK KANAT"),
    [MOVE_MEAN_LOOK]     = _("MANALI BAKIŞ"),
    [MOVE_ATTRACT]       = _("ÇEKİCİLİK"),
    [MOVE_SLEEP_TALK]    = _("SAYIKLAMA"),
    [MOVE_HEAL_BELL]     = _("CAN ÇANI"),
    [MOVE_RETURN]        = _("KARŞILIK"),
    [MOVE_PRESENT]       = _("HEDİYE"),
    [MOVE_FRUSTRATION]   = _("HÜSRAN"),
    [MOVE_SAFEGUARD]     = _("MİSTİKKORUMA"),
    [MOVE_PAIN_SPLIT]    = _("ACI BÖLÜŞÜ"),
    [MOVE_SACRED_FIRE]   = _("KUTSAL ATEŞ"),
    [MOVE_MAGNITUDE]     = _("DEPREM"),
    [MOVE_DYNAMIC_PUNCH] = _("DİNAMİKYUMRK"),
    [MOVE_MEGAHORN]      = _("MEGA BOYNUZ"),
    [MOVE_DRAGON_BREATH] = _("EJDER NEFESİ"),
    [MOVE_BATON_PASS]    = _("DEĞNEKGEÇİŞİ"),
    [MOVE_ENCORE]        = _("TEZAHÜRAT"),
    [MOVE_PURSUIT]       = _("SIKI TAKİP"),
    [MOVE_RAPID_SPIN]    = _("ANİ DÖNÜŞ"),
    [MOVE_SWEET_SCENT]   = _("TATLI KOKU"),
    [MOVE_IRON_TAIL]     = _("DEMİR KUYRUK"),
    [MOVE_METAL_CLAW]    = _("METAL PENÇE"),
    [MOVE_VITAL_THROW]   = _("HAYATİ VURUŞ"),
    [MOVE_MORNING_SUN]   = _("SABAH GÜNEŞİ"),
    [MOVE_SYNTHESIS]     = _("SENTEZ"),
    [MOVE_MOONLIGHT]     = _("AY IŞIĞI"),
    [MOVE_HIDDEN_POWER]  = _("GİZLİ GÜÇ"),
    [MOVE_CROSS_CHOP]    = _("ÇAPRAZ KESME"),
    [MOVE_TWISTER]       = _("HORTUM"),
    [MOVE_RAIN_DANCE]    = _("YAĞMUR DANSI"),
    [MOVE_SUNNY_DAY]     = _("GÜNEŞLİ GÜN"),
    [MOVE_CRUNCH]        = _("ÇİĞNE"),
    [MOVE_MIRROR_COAT]   = _("AYNA ZIRH"),
    [MOVE_PSYCH_UP]      = _("MORAL ARTTIR"),
    [MOVE_EXTREME_SPEED] = _("AŞIRI HIZ"),
    [MOVE_ANCIENT_POWER] = _("ANTİK GÜÇ"),
    [MOVE_SHADOW_BALL]   = _("GÖLGE TOPU"),
    [MOVE_FUTURE_SIGHT]  = _("İLERİ GÖRÜŞ"),
    [MOVE_ROCK_SMASH]    = _("KAYA DARBESİ"),
    [MOVE_WHIRLPOOL]     = _("GİRDAP"),
    [MOVE_BEAT_UP]       = _("BEAT UP"),
    [MOVE_FAKE_OUT]      = _("FAKE OUT"),
    [MOVE_UPROAR]        = _("KARGAŞA"),
    [MOVE_STOCKPILE]     = _("STOKLA"),
    [MOVE_SPIT_UP]       = _("TÜKÜR"),
    [MOVE_SWALLOW]       = _("YUT"),
    [MOVE_HEAT_WAVE]     = _("ISI DALGASI"),
    [MOVE_HAIL]          = _("DOLU"),
    [MOVE_TORMENT]       = _("EZİYET"),
    [MOVE_FLATTER]       = _("ŞIMART"),
    [MOVE_WILL_O_WISP]   = _("YAKAMOZ"),
    [MOVE_MEMENTO]       = _("HATIRA"),
    [MOVE_FACADE]        = _("CESARET"),
    [MOVE_FOCUS_PUNCH]   = _("ODAK YUMRUĞU"),
    [MOVE_SMELLING_SALT] = _("TUZ KOKLA"),
    [MOVE_FOLLOW_ME]     = _("TAKİP ET"),
    [MOVE_NATURE_POWER]  = _("DOĞA GÜCÜ"),
    [MOVE_CHARGE]        = _("ŞARJ OL"),
    [MOVE_TAUNT]         = _("ALAY ET"),
    [MOVE_HELPING_HAND]  = _("YARDIM ELİ"),
    [MOVE_TRICK]         = _("NUMARA"),
    [MOVE_ROLE_PLAY]     = _("ROL YAP"),
    [MOVE_WISH]          = _("DİLEK"),
    [MOVE_ASSIST]        = _("YARDIM ET"),
    [MOVE_INGRAIN]       = _("KÖK SAL"),
    [MOVE_SUPERPOWER]    = _("SÜPER GÜÇ"),
    [MOVE_MAGIC_COAT]    = _("BÜYÜLÜ ZIRH"),
    [MOVE_RECYCLE]       = _("GERİDÖNÜŞTÜR"),
    [MOVE_REVENGE]       = _("İNTİKAM"),
    [MOVE_BRICK_BREAK]   = _("TUĞLA KIRMA"),
    [MOVE_YAWN]          = _("ESNEME"),
    [MOVE_KNOCK_OFF]     = _("VUR DÜŞÜR"),
    [MOVE_ENDEAVOR]      = _("ÇABA"),
    [MOVE_ERUPTION]      = _("VOLKANPATLAT"),
    [MOVE_SKILL_SWAP]    = _("GÜÇ DEĞİŞ"),
    [MOVE_IMPRISON]      = _("MÜHÜRLE"),
    [MOVE_REFRESH]       = _("YENİLE"),
    [MOVE_GRUDGE]        = _("KİN"),
    [MOVE_SNATCH]        = _("KAPKAÇ"),
    [MOVE_SECRET_POWER]  = _("GİZLİ GÜÇ"),
    [MOVE_DIVE]          = _("DALIŞ"),
    [MOVE_ARM_THRUST]    = _("İTME"),
    [MOVE_CAMOUFLAGE]    = _("KAMUFLAJ"),
    [MOVE_TAIL_GLOW]     = _("KUYRUKPARLAT"),
    [MOVE_LUSTER_PURGE]  = _("SAF IŞIK"),
    [MOVE_MIST_BALL]     = _("PUS TOPU"),
    [MOVE_FEATHER_DANCE] = _("TÜY DANSI"),
    [MOVE_TEETER_DANCE]  = _("SERSEM DANS"),
    [MOVE_BLAZE_KICK]    = _("ALEV TEKME"),
    [MOVE_MUD_SPORT]     = _("ÇAMUR SPORU"),
    [MOVE_ICE_BALL]      = _("BUZ TOPU"),
    [MOVE_NEEDLE_ARM]    = _("İĞNE KOL"),
    [MOVE_SLACK_OFF]     = _("GEVŞE"),
    [MOVE_HYPER_VOICE]   = _("HİPER SES"),
    [MOVE_POISON_FANG]   = _("ZEHİRLİ DİŞ"),
    [MOVE_CRUSH_CLAW]    = _("PARÇALAPENÇE"),
    [MOVE_BLAST_BURN]    = _("TAHRİPYANIĞI"),
    [MOVE_HYDRO_CANNON]  = _("SU TOPU"),
    [MOVE_METEOR_MASH]   = _("METEOR DARBE"),
    [MOVE_ASTONISH]      = _("ŞAŞIRTMA"),
    [MOVE_WEATHER_BALL]  = _("HAVA TOPU"),
    [MOVE_AROMATHERAPY]  = _("AROMATERAPİ"),
    [MOVE_FAKE_TEARS]    = _("SAHTEGÖZYAŞI"),
    [MOVE_AIR_CUTTER]    = _("HAVA KESİCİ"),
    [MOVE_OVERHEAT]      = _("AŞIRI ISINMA"),
    [MOVE_ODOR_SLEUTH]   = _("KOKUYU BUL"),
    [MOVE_ROCK_TOMB]     = _("KAYA MEZAR"),
    [MOVE_SILVER_WIND]   = _("GÜMÜŞ RÜZGAR"),
    [MOVE_METAL_SOUND]   = _("METAL SESİ"),
    [MOVE_GRASS_WHISTLE] = _("ÇİMFISILTISI"),
    [MOVE_TICKLE]        = _("GIDIKLA"),
    [MOVE_COSMIC_POWER]  = _("KOZMİK GÜÇ"),
    [MOVE_WATER_SPOUT]   = _("SU PÜSKÜRT"),
    [MOVE_SIGNAL_BEAM]   = _("SİNYAL IŞIN"),
    [MOVE_SHADOW_PUNCH]  = _("GÖLGE YUMRUK"),
    [MOVE_EXTRASENSORY]  = _("ALGI ÖTESİ"),
    [MOVE_SKY_UPPERCUT]  = _("GÖK APERKATI"),
    [MOVE_SAND_TOMB]     = _("KUM MEZAR"),
    [MOVE_SHEER_COLD]    = _("MUTLAK SIFIR"),
    [MOVE_MUDDY_WATER]   = _("ÇAMURLU SU"),
    [MOVE_BULLET_SEED]   = _("MERMİ TOHUMU"),
    [MOVE_AERIAL_ACE]    = _("GÖK HAKİMİ"),
    [MOVE_ICICLE_SPEAR]  = _("SARKITMIZRAK"),
    [MOVE_IRON_DEFENSE]  = _("DEMİR DEFANS"),
    [MOVE_BLOCK]         = _("BLOK"),
    [MOVE_HOWL]          = _("ULUMA"),
    [MOVE_DRAGON_CLAW]   = _("EJDERPENÇESİ"),
    [MOVE_FRENZY_PLANT]  = _("ÇILGIN BİTKİ"),
    [MOVE_BULK_UP]       = _("GELİŞ"),
    [MOVE_BOUNCE]        = _("ZIPLAMA"),
    [MOVE_MUD_SHOT]      = _("ÇAMUR ATIŞI"),
    [MOVE_POISON_TAIL]   = _("ZEHİR KUYRUK"),
    [MOVE_COVET]         = _("YALVARMA"),
    [MOVE_VOLT_TACKLE]   = _("VOLT TOSLAMA"),
    [MOVE_MAGICAL_LEAF]  = _("BÜYÜLÜYAPRAK"),
    [MOVE_WATER_SPORT]   = _("SU OYUNU"),
    [MOVE_CALM_MIND]     = _("SAKİNLEŞ"),
    [MOVE_LEAF_BLADE]    = _("BIÇAK YAPRAK"),
    [MOVE_DRAGON_DANCE]  = _("EJDER DANSI"),
    [MOVE_ROCK_BLAST]    = _("KAYA YAĞMURU"),
    [MOVE_SHOCK_WAVE]    = _("ŞOK DALGASI"),
    [MOVE_WATER_PULSE]   = _("SU VURUŞU"),
    [MOVE_DOOM_DESIRE]   = _("KADER KARARI"),
    [MOVE_PSYCHO_BOOST]  = _("PSİŞİK ARTIŞ")
};
