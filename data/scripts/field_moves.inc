EventScript_CutTree::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	goto_if_unset FLAG_BADGE02_GET, EventScript_CantCutTree
	checkpartymove MOVE_CUT
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantCutTree
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_CUT
	msgbox Text_CutTreeDown, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_DontCutTree
	msgbox Text_MonUsedMove
	closemessage
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

EventScript_FldEffCut::
	lockall
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end

EventScript_CutTreeDown::
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	releaseall
	end

Movement_CutTreeDown::
	cut_tree
	step_end

EventScript_CantCutTree::
	msgbox Text_TreeCanBeCutDown, MSGBOX_SIGN
	releaseall
	end

EventScript_DontCutTree::
	closemessage
	releaseall
	end

Text_CutTreeDown::
	.string "Bu ağaç KESİLEBİLİR gibi\n"
	.string "görünüyor!\p"
	.if ENG_MOVES == 1
	.string "CUT kullanmak ister misin?$"
	.else
	.string "KES kullanmak ister misin?$"
	.endif

Text_MonUsedMove::
	.string "{STR_VAR_1}, {STR_VAR_2} kullandı!$"

Text_TreeCanBeCutDown::
	.string "Bu ağaç KESİLEBİLİR gibi\n"
	.string "görünüyor!$"

EventScript_RockSmash::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	goto_if_unset FLAG_BADGE06_GET, EventScript_CantSmashRock
	checkpartymove MOVE_ROCK_SMASH
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSmashRock
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_ROCK_SMASH
	msgbox Text_UseRockSmash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_DontSmashRock
	msgbox Text_MonUsedMove
	closemessage
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_UseRockSmash
	end

EventScript_FldEffRockSmash::
	lockall
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_UseRockSmash
	end

EventScript_UseRockSmash::
	applymovement VAR_LAST_TALKED, Movement_BreakRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_RockSmashNoEncounter
	waitstate
	releaseall
	end

EventScript_RockSmashNoEncounter::
	releaseall
	end

Movement_BreakRock::
	rock_smash_break
	step_end

EventScript_CantSmashRock::
	msgbox Text_MonMaySmashRock, MSGBOX_SIGN
	end

EventScript_DontSmashRock::
	closemessage
	releaseall
	end

Text_UseRockSmash::
	.string "Bu kaya kırılabilir gibi duruyor.\n"
	.if ENG_MOVES == 1
	.string "ROCK SMASH kullanmak ister misin?$"
	.else
	.string "KAYA DARBESİ kullanmak ister misin?$"
	.endif

Text_MonMaySmashRock::
	.string "Bu sağlam bir kaya. Belki bir\n"
	.string "POKéMON onu parçalayabilir.$"

EventScript_StrengthBoulder::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	goto_if_unset FLAG_BADGE04_GET, EventScript_CantMoveBoulder
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_AlreadyUsedStrength
	checkpartymove MOVE_STRENGTH
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantMoveBoulder
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_UseStrength, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_DontUseStrength
	closemessage
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_UseStrength
	end

EventScript_FldEffStrength::
	lockall
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_UseStrength
	end

EventScript_UseStrength::
	setflag FLAG_SYS_USE_STRENGTH
	msgbox Text_MonUsedStrengthCanMoveBoulders, MSGBOX_SIGN
	end

EventScript_CantMoveBoulder::
	msgbox Text_MonMayPushBoulder, MSGBOX_SIGN
	end

EventScript_AlreadyUsedStrength::
	msgbox Text_StrengthMadeMovingBouldersPossible, MSGBOX_SIGN
	end

EventScript_DontUseStrength::
	closemessage
	releaseall
	end

Text_UseStrength::
	.string "Bu büyük bir kaya. Belki de bir\n"
	.string "POKéMON bunu ittirebilir.\p"
	.if ENG_MOVES == 1
	.string "STRENGTH kullanmak ister misin?$"
	.else
	.string "GÜÇ kullanmak ister misin?$"
	.endif

Text_MonUsedStrengthCanMoveBoulders::
	.if ENG_MOVES == 1
	.string "{STR_VAR_1}, STRENGTH kullandı!\p"
	.else
	.string "{STR_VAR_1}, GÜÇ kullandı!\p"
	.endif
	.string "{STR_VAR_1}'ın gücü artık\n"
	.string "kayaları yerinden oynatabilir!$"

Text_MonMayPushBoulder::
	.string "Bu büyük bir kaya. Belki de bir\n"
	.string "POKéMON bunu ittirebilir.$"

Text_StrengthMadeMovingBouldersPossible::
	.if ENG_MOVES == 1
	.string "STRENGTH sayesinde kayalar artık\n"
	.else
	.string "GÜÇ sayesinde kayalar artık\n"
	.endif
	.string "yerinden oynatılabilir.$"

EventScript_Waterfall::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	checkpartymove MOVE_WATERFALL
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_WaterCrashingDown
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_UseWaterfall, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndWaterfall
	msgbox Text_MonUsedWaterfall
	dofieldeffect FLDEFF_USE_WATERFALL
	goto EventScript_EndWaterfall

EventScript_CantUseWaterfall::
	lockall
EventScript_WaterCrashingDown:
	msgbox Text_WallOfWaterCrashingDown
EventScript_EndWaterfall:
	releaseall
	end

Text_WallOfWaterCrashingDown::
	.string "Sudan bir duvar adeta\n"
	.string "bir kükreme ile iniyor.$"

Text_UseWaterfall::
	.string "Bu büyük bir şelale.\n"
	.if ENG_MOVES == 1
	.string "WATERFALL kullanmak ister misin?$"
	.else
	.string "ŞELALE kullanmak ister misin?$"
	.endif

Text_MonUsedWaterfall::
	.if ENG_MOVES == 1
	.string "{STR_VAR_1}, WATERFALL kullandı.$"
	.else
	.string "{STR_VAR_1}, ŞELALE kullandı.$"
	.endif

@ Unused leftover from R/S
EventScript_DeepWater::
	lockall
	checkpartymove MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_MayGoUnderwater
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_SeaIsDeepUseDive, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndDive
	msgbox Text_MonUsedDive
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive

EventScript_CantDive::
	lockall
EventScript_MayGoUnderwater:
	msgbox Text_MonMayGoUnderwater
EventScript_EndDive:
	releaseall
	end

EventScript_TrySurface::
	lockall
	checkpartymove MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSurface
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_LightFilteringUseDive, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndSurface
	msgbox Text_MonUsedDive
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndSurface

EventScript_CantSurface::
	lockall
	msgbox Text_MonMaySurface
	goto EventScript_EndSurface

EventScript_ObstacleCantSurface::
	lockall
	msgbox Text_DiveCantBeUsedHere
EventScript_EndSurface:
	releaseall
	end

Text_MonMayGoUnderwater::
	.string "Su çok derin. Belki bir POKéMON\n"
	.string "dibe dalabilir.$"

Text_SeaIsDeepUseDive::
	.string "Su çok derin.\n"
	.if ENG_MOVES == 1
	.string "DIVE kullanmak ister misin?$"
	.else
	.string "DALIŞ kullanmak ister misin?$"
	.endif

Text_MonUsedDive::
	.if ENG_MOVES == 1
	.string "{STR_VAR_1}, DIVE kullandı.$"
	.else
	.string "{STR_VAR_1}, DALIŞ kullandı.$"
	.endif

Text_MonMaySurface::
	.string "Işık yukarıdan aşağı süzülüyor.\n"
	.string "Belki bir POKéMON yüzeye çıkabilir.$"

Text_LightFilteringUseDive::
	.string "Işık yukarıdan aşağı süzülüyor.\n"
	.if ENG_MOVES == 1
	.string "DIVE kullanmak ister misin?$"
	.else
	.string "DALIŞ kullanmak ister misin?$"
	.endif

Text_DiveCantBeUsedHere::
	.string "Tepede bir engel var.\n"
	.if ENG_MOVES == 1
	.string "DIVE burada kullanılamaz.$"
	.else
	.string "DALIŞ burada kullanılamaz.$"
	.endif

EventScript_FailSweetScent::
	msgbox Text_LooksLikeNothingHere, MSGBOX_SIGN
	end

Text_LooksLikeNothingHere::
	.string "Sanırım burada bir şey yok…$"
