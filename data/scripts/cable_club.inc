CableClub_OnTransition::
	call CableClub_EventScript_HideOrShowMysteryGiftMan
	end

CableClub_EventScript_HideOrShowMysteryGiftMan::
	specialvar VAR_RESULT, ValidateSavedWonderCard
	goto_if_eq VAR_RESULT, FALSE, EventScript_HideMysteryGiftMan
	clearflag FLAG_HIDE_MG_DELIVERYMEN
	return

EventScript_HideMysteryGiftMan::
	setflag FLAG_HIDE_MG_DELIVERYMEN
	return

CableClub_EventScript_MysteryGiftMan::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	trywondercardscript

@ Unused
EventScript_MysteryGiftThankYou::
	msgbox Text_ThankYouForAccessingMysteryGift, MSGBOX_NPC
	end

CableClub_OnWarp::
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, EventScript_CheckTurnAttendant
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, EventScript_CheckTurnAttendant
	.2byte 0

EventScript_CheckTurnAttendant::
	goto_if_eq VAR_0x8007, 0, EventScript_CheckTurnAttendantEnd
	turnobject VAR_0x8007, DIR_WEST
EventScript_CheckTurnAttendantEnd:
	end

CableClub_OnLoad::
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, EventScript_OnLoadFromColosseum
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, EventScript_OnLoadFromColosseum
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, EventScript_OnLoadFromColosseum
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, EventScript_OnLoadFromTradeCenter
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, EventScript_OnLoadFromUnionRoom
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, EventScript_OnLoadFromBerryCrush
	goto_if_eq VAR_CABLE_CLUB_STATE, USING_MINIGAME, EventScript_OnLoadFromGameCorner
	end

EventScript_OnLoadFromColosseum::
	call CableClub_EventScript_OpenDirectCornerBarrier
	end

EventScript_OnLoadFromTradeCenter::
	call CableClub_EventScript_OpenDirectCornerBarrier
	end

EventScript_OnLoadFromUnionRoom::
	call CableClub_EventScript_OpenUnionRoomBarrier
	end

EventScript_OnLoadFromBerryCrush::
	call CableClub_EventScript_OpenDirectCornerBarrier
	end

EventScript_OnLoadFromGameCorner::
	call CableClub_EventScript_OpenGameCornerBarrier
	end

CableClub_OnFrame::
	map_script_2 VAR_MAP_SCENE_POKEMON_CENTER_TEALA, 1, CableClub_EventScript_Tutorial
	map_script_2 VAR_CABLE_CLUB_STATE, USING_SINGLE_BATTLE, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_DOUBLE_BATTLE, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MULTI_BATTLE, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_TRADE_CENTER, CableClub_EventScript_ExitTradeCenter
	map_script_2 VAR_CABLE_CLUB_STATE, USING_UNION_ROOM, CableClub_EventScript_ExitUnionRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_BERRY_CRUSH, CableClub_EventScript_ExitLinkRoom
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

CableClub_EventScript_ExitLinkRoom::
	lockall
	call CableClub_EventScript_CloseLinkAndExitLinkRoom
	call CableClub_EventScript_CloseDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_ExitMinigameRoom::
	lockall
	call CableClub_EventScript_CloseLinkAndExitLinkRoom
	call CableClub_EventScript_CloseGameCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_CloseLinkAndExitLinkRoom::
	special CloseLink
	special HelpSystem_Enable
	special QuestLog_StartRecordingInputsAfterDeferredEvent
	setvar VAR_CABLE_CLUB_STATE, 0
	textcolor NPC_TEXT_COLOR_FEMALE
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_PlayerExitLinkRoom
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
	return

CableClub_EventScript_ExitTradeCenter::
	lockall
	call CableClub_EventScript_PlayerExitTradeCenter
	call CableClub_EventScript_CloseDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_PlayerExitTradeCenter::
	special CloseLink
	special HelpSystem_Enable
	special QuestLog_StartRecordingInputsAfterDeferredEvent
	setvar VAR_CABLE_CLUB_STATE, 0
	textcolor NPC_TEXT_COLOR_FEMALE
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_PlayerExitLinkRoom
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerFaceAttendantRight
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	call CableClub_EventScript_TrainerCardDataOverwritten
	return

CableClub_EventScript_ExitUnionRoom::
	lockall
	call CableClub_EventScript_PlayerExitUnionRoom
	call CableClub_EventScript_CloseUnionRoomBarrier
	special DrawWholeMapView
	playse SE_CLICK
	erasebox 0, 0, 29, 19
	releaseall
	end

CableClub_EventScript_PlayerExitUnionRoom::
	special HelpSystem_Enable
	special QuestLog_StartRecordingInputsAfterDeferredEvent
	setvar VAR_CABLE_CLUB_STATE, 0
	textcolor NPC_TEXT_COLOR_FEMALE
	goto_if_eq VAR_0x8007, 0, CableClub_EventScript_PlayerExitLinkRoom
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerFaceAttendantRight
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceLeft
	waitmovement 0
	call CableClub_EventScript_TrainerCardDataOverwritten
	return

CableClub_EventScript_TrainerCardDataOverwritten::
	message CableClub_Text_TrainerCardDataOverwritten
	waitmessage
	playse SE_PIN
	message CableClub_Text_HopeToSeeYouAgain
	waitmessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	applymovement VAR_0x8007, Movement_AttendantFaceDown
	waitmovement 0
	return

CableClub_EventScript_PlayerExitLinkRoom::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerExitLinkRoom
	waitmovement 0
	return

CableClub_EventScript_Tutorial::
	lockall
	textcolor NPC_TEXT_COLOR_FEMALE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox CableClub_Text_FirstTimeRightThisWay
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachCounter
	waitmovement 0
	delay 30
	msgbox CableClub_Text_ExplainWirelessClubFirstTime
	setvar VAR_MAP_SCENE_POKEMON_CENTER_TEALA, 2
	releaseall
	end

Movement_PlayerApproachCounter:
	walk_up
	walk_up
	step_end

CableClub_EventScript_WelcomeToCableClub::
	message CableClub_Text_WelcomeWhichCableClubService
	waitmessage
	delay 15
	goto CableClub_EventScript_SelectCableClubRoom
	end

CableClub_EventScript_UnusedWelcomeToCableClub::
	msgbox CableClub_Text_WhichService
	goto CableClub_EventScript_SelectCableClubRoom
	end

CableClub_EventScript_SelectCableClubRoom::
	setvar VAR_0x8004, 0
	multichoice 0, 0, MULTICHOICE_TRADE_CENTER_COLOSSEUM, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TradeCenter
	case 1, CableClub_EventScript_Colosseum
	case 2, CableClub_EventScript_AbortLink
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_Colosseum::
	copyvar VAR_0x8007, VAR_LAST_TALKED
	goto CableClub_EventScript_SelectBattleMode
	end

CableClub_EventScript_SelectBattleMode::
	message CableClub_Text_PlayWhichBattleMode
	waitmessage
	multichoice 0, 0, MULTICHOICE_SINGLE_DOUBLE_MULTI_INFO_EXIT, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_SingleBattleMode
	case 1, CableClub_EventScript_DoubleBattleMode
	case 2, CableClub_EventScript_MultiBattleMode
	case 3, CableClub_EventScript_BattleModeInfo
	case 4, CableClub_EventScript_AbortLink
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_BattleModeInfo::
	msgbox CableClub_Text_ExplainBattleModes
	goto CableClub_EventScript_SelectBattleMode
	end

CableClub_EventScript_SingleBattleMode::
	setvar VAR_0x8004, USING_SINGLE_BATTLE
	goto CableClub_EventScript_TryEnterColosseum
	end

CableClub_EventScript_DoubleBattleMode::
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, CableClub_EventScript_NeedTwoMonsForDoubleBattle
	setvar VAR_0x8004, USING_DOUBLE_BATTLE
	goto CableClub_EventScript_TryEnterColosseum
	end

CableClub_EventScript_NeedTwoMonsForDoubleBattle::
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle
	goto CableClub_EventScript_SelectBattleMode
	end

CableClub_EventScript_MultiBattleMode::
	setvar VAR_0x8004, USING_MULTI_BATTLE
	goto CableClub_EventScript_TryEnterColosseum
	end

CableClub_EventScript_TryEnterColosseum::
	call EventScript_AskSaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	message CableClub_Text_PleaseWaitBCancel
	waitmessage
	special HelpSystem_Disable
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special TryBattleLinkup
	waitstate
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterColosseum
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
	end

CableClub_EventScript_EnterColosseum::
	special HealPlayerParty
	special SavePlayerParty
	special LoadPlayerBag
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll CableClub_Text_PleaseEnter
	waitmessage
	call CableClub_EventScript_OpenDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	closedoor 9, 1
	waitdooranim
	release
	goto_if_eq VAR_0x8004, USING_MULTI_BATTLE, CableClub_EventScript_WarpTo4PColosseum
	special SetCableClubWarp
	warp MAP_BATTLE_COLOSSEUM_2P, 6, 8
	special DoCableClubWarp
	waitstate
	end

@ Unused
CableClub_EventScript_PlayerApproachLinkRoomRight::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomRight
	waitmovement 0
	return

CableClub_EventScript_WarpTo4PColosseum::
	special SetCableClubWarp
	warp MAP_BATTLE_COLOSSEUM_4P, 5, 8
	special DoCableClubWarp
	waitstate
	end

CableClub_EventScript_AbortLinkIncorrectNumberOfBattlers::
	switch VAR_0x8004
	case USING_SINGLE_BATTLE, CableClub_EventScript_AbortLinkWrongNumberForSingleBattle
	case USING_DOUBLE_BATTLE, CableClub_EventScript_AbortLinkWrongNumberForDoubleBattle
	case USING_MULTI_BATTLE, CableClub_EventScript_AbortLinkNeedFourPlayers
	goto CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
	end

CableClub_EventScript_AbortLinkNeedFourPlayers::
	special CloseLink
	msgbox CableClub_Text_NeedFourPlayers
	goto CableClub_EventScript_ConfirmNumberAndRestart
	end

CableClub_EventScript_AbortLinkWrongNumberForDoubleBattle::
	special CloseLink
	msgbox CableClub_Text_CantDoubleBattleWithXPlayers
	goto CableClub_EventScript_ConfirmNumberAndRestart
	end

CableClub_EventScript_AbortLinkWrongNumberForSingleBattle::
	special CloseLink
	msgbox CableClub_Text_CantSingleBattleWithXPlayers
	goto CableClub_EventScript_ConfirmNumberAndRestart
	end

CableClub_EventScript_ConfirmNumberAndRestart::
	special CloseLink  @ Redundant
	special HelpSystem_Enable
	msgbox CableClub_Text_PleaseConfirmNumberAndRestart
	release
	end

CableClub_EventScript_TradeCenter::
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_CheckPartyTradeRequirements
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	call EventScript_AskSaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	message CableClub_Text_PleaseWaitBCancel
	waitmessage
	special HelpSystem_Disable
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special TryTradeLinkup
	waitstate
	call EventScript_RestorePrevTextColor
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterTradeCenter
	goto_if_eq VAR_RESULT, LINKUP_SOMEONE_NOT_READY, CableClub_EventScript_AbortLinkSomeoneNotReady
	goto_if_eq VAR_RESULT, LINKUP_DIFF_SELECTIONS, CableClub_EventScript_AbortLinkDifferentSelections
	goto_if_eq VAR_RESULT, LINKUP_WRONG_NUM_PLAYERS, CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_AbortLink
	goto_if_eq VAR_RESULT, LINKUP_CONNECTION_ERROR, CableClub_EventScript_AbortLinkConnectionError
	goto_if_eq VAR_RESULT, LINKUP_PLAYER_NOT_READY, CableClub_EventScript_AbortLinkPlayerNotReady
	goto_if_eq VAR_RESULT, LINKUP_PARTNER_NOT_READY, CableClub_EventScript_AbortLinkOtherTrainerNotReady
	end

CableClub_EventScript_EnterTradeCenter::
	setvar VAR_0x8004, USING_TRADE_CENTER
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	messageautoscroll CableClub_Text_PleaseEnter
	waitmessage
	call CableClub_EventScript_OpenDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	closedoor 9, 1
	waitdooranim
	release
	special SetCableClubWarp
	setwarp MAP_TRADE_CENTER, 5, 8
	special DoCableClubWarp
	waitstate
	end

CableClub_EventScript_CheckPartyTradeRequirements::
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_lt VAR_RESULT, 2, CableClub_EventScript_NeedTwoMonsToTrade
	specialvar VAR_RESULT, DoesPartyHaveEnigmaBerry
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_CantTradeEnigmaBerry
	setvar VAR_RESULT, TRUE
	return

CableClub_EventScript_NeedTwoMonsToTrade::
	msgbox CableClub_Text_NeedTwoMonsToTrade
	setvar VAR_RESULT, FALSE
	return

CableClub_EventScript_CantTradeEnigmaBerry::
	msgbox CableClub_Text_CantTradeEnigmaBerry
	setvar VAR_RESULT, FALSE
	return

@ Record Corner is nopped in FRLG
CableClub_EventScript_RecordCorner::
	end

CableClub_EventScript_AbortLinkPlayerNotReady::
	special CloseLink
	special HelpSystem_Enable
	msgbox CableClub_Text_NotSetUpForFarAwayRegion
	release
	end

CableClub_EventScript_AbortLinkOtherTrainerNotReady::
	special CloseLink
	special HelpSystem_Enable
	msgbox CableClub_Text_OtherTrainerNotReady
	release
	end

CableClub_EventScript_AbortLinkConnectionError::
	special CloseLink
	special HelpSystem_Enable
	msgbox CableClub_Text_LinkErrorPleaseReset
	release
	end

CableClub_EventScript_AbortLinkSomeoneNotReady::
	special CloseLink
	special HelpSystem_Enable
	msgbox CableClub_Text_SomeoneIsNotReadyToLink
	release
	end

CableClub_EventScript_AbortLinkDifferentSelections::
	special CloseLink
	special HelpSystem_Enable
	msgbox CableClub_Text_PlayersMadeDifferentSelections
	release
	end

CableClub_EventScript_AbortLink::
	special CloseLink
	special HelpSystem_Enable
	msgbox CableClub_Text_PleaseVisitAgain
	release
	end

CableClub_EventScript_AbortMinigame::
	special CloseLink
	special HelpSystem_Enable
	msgbox CableClub_Text_ComeAgain
	release
	end

@ Unused
CableClub_EventScript_CableClubWarp::
	special SetCableClubWarp
	special DoCableClubWarp
	waitstate
	end

CableClub_EventScript_AbortLinkIncorrectNumberOfParticipants::
	special CloseLink
	special HelpSystem_Enable
	msgbox CableClub_Text_IncorrectNumberOfParticipants
	release
	end

CableClub_EventScript_AbortLinkPlayerHasBadEgg::
	special CloseLink
	special HelpSystem_Enable
	msgbox CableClub_Text_YouHaveAMonThatCantBeTaken
	release
	end

CableClub_EventScript_WirelessClubAdjustements::
	msgbox Text_WirelessClubUndergoingAdjustments
	release
	end

CableClub_EventScript_NotReadyYet::
	msgbox Text_AppearsToBeUndergoingAdjustments
	releaseall
	end

Movement_AttendantFaceDown::
	face_down
	step_end

@ Unused
Movement_AttendantFaceRight::
	face_right
	step_end

Movement_AttendantFaceLeft::
	face_left
	step_end

Movement_PlayerExitLinkRoom::
	walk_down
	walk_down
	step_end

Movement_PlayerApproachLinkRoomRight::
	walk_right
	walk_up
	walk_up
	step_end

Movement_PlayerApproachLinkRoomLeft::
	walk_left
	walk_up
	walk_up
	step_end

Movement_PlayerEnterLinkRoom::
	walk_up
	step_end

@ Unused
Movement_PlayerFaceAttendantLeft::
	face_left
	step_end

Movement_PlayerFaceAttendantRight::
	face_right
	step_end

Movement_PlayerEnterMinigameRoom::
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

CableClub_EventScript_ShowBattleRecords::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 0
	special ShowBattleRecords
	waitstate
	releaseall
	end

BattleColosseum_2P_EventScript_PlayerSpot0::
	setvar VAR_0x8005, 0
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special EnterColosseumPlayerSpot
	waitstate
	end

BattleColosseum_2P_EventScript_PlayerSpot1::
	setvar VAR_0x8005, 1
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special EnterColosseumPlayerSpot
	waitstate
	end

BattleColosseum_4P_EventScript_PlayerSpot0::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleColosseum_4P_EventScript_CancelSpotTrigger
	setvar VAR_0x8005, 0
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special EnterColosseumPlayerSpot
	waitstate
	end

BattleColosseum_4P_EventScript_PlayerSpot1::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleColosseum_4P_EventScript_CancelSpotTrigger
	setvar VAR_0x8005, 1
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special EnterColosseumPlayerSpot
	waitstate
	end

BattleColosseum_4P_EventScript_PlayerSpot2::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleColosseum_4P_EventScript_CancelSpotTrigger
	setvar VAR_0x8005, 2
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special EnterColosseumPlayerSpot
	waitstate
	end

BattleColosseum_4P_EventScript_PlayerSpot3::
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleColosseum_4P_EventScript_CancelSpotTrigger
	setvar VAR_0x8005, 3
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special EnterColosseumPlayerSpot
	waitstate
	end

BattleColosseum_4P_EventScript_CancelSpotTrigger::
	end

TradeCenter_EventScript_Chair0::
	setvar VAR_0x8005, 0
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special EnterTradeSeat
	waitstate
	end

TradeCenter_EventScript_Chair1::
	setvar VAR_0x8005, 1
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special EnterTradeSeat
	waitstate
	end

@ Unused
TradeCenter_EventScript_Chair2::
	setvar VAR_0x8005, 2
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special EnterTradeSeat
	waitstate
	end

@ Unused
TradeCenter_EventScript_Chair3::
	setvar VAR_0x8005, 3
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special EnterTradeSeat
	waitstate
	end

@ Nop in FRLG
@ Separate labels to match GetDirectionForEventScript
RecordCorner_EventScript_Spot0::
RecordCorner_EventScript_Spot1::
RecordCorner_EventScript_Spot2::
RecordCorner_EventScript_Spot3::
	end

CableClub_EventScript_ReadTrainerCard::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_LookedAtPlayersTrainerCard
	fadescreen FADE_TO_BLACK
	special Script_ShowLinkTrainerCard
	waitstate
	end

CableClub_EventScript_ReadTrainerCardColored::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_LookedAtPlayersTrainerCardColored
	fadescreen FADE_TO_BLACK
	special Script_ShowLinkTrainerCard
	waitstate
	end

CableClub_EventScript_TooBusyToNotice::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_TrainerTooBusyToNotice
	closemessage
	end

BattleColosseum_2P_EventScript_Attendant::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special Script_FacePlayer
	msgbox Text_TakeSeatStartBattle
	special Script_ClearHeldMovement
	closemessage
	end

TradeCenter_EventScript_Attendant::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	special Script_FacePlayer
	msgbox Text_TakeSeatStartTrade
	special Script_ClearHeldMovement
	closemessage
	end

@ Nop in FRLG
RecordCorner_EventScript_Attendant::
	end

TradeCenter_ConfirmLeaveRoom::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	msgbox Text_TerminateLinkIfYouLeaveRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TradeCenter_TerminateLink
	erasebox 0, 0, 29, 19
	releaseall
	end

TradeCenter_TerminateLink::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	messageautoscroll Text_TerminateLinkConfirmation
	waitmessage
	special ExitLinkRoom
	end

CableClub_EventScript_DoLinkRoomExit::
	special CleanupLinkRoomState
	special ReturnFromLinkRoom
	waitstate
	end

CableClub_EventScript_UnionRoomAttendant::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
	specialvar VAR_RESULT, IsBadEggInParty
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_AbortLinkPlayerHasBadEgg
	copyvar VAR_0x8007, VAR_LAST_TALKED
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_UnionRoomAdapterNotConnected
	message CableClub_Text_WelcomeUnionRoomEnter
	waitmessage
	goto CableClub_EventScript_AskEnterUnionRoom
	end

CableClub_EventScript_AskEnterUnionRoom::
	multichoice 18, 6, MULTICHOICE_YES_NO_INFO, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_EnterUnionRoom
	case 1, CableClub_EventScript_AbortLink
	case 2, CableClub_EventScript_UnionRoomInfo
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_UnionRoomInfo::
	message CableClub_Text_UnionRoomInfo
	waitmessage
	goto CableClub_EventScript_AskEnterUnionRoom
	end

CableClub_EventScript_EnterUnionRoom::
	call CableClub_EventScript_CheckPartyUnionRoomRequirements
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_AbortLink
	call EventScript_AskSaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	msgbox CableClub_Text_EnjoyUnionRoom
	closemessage
	special HealPlayerParty
	setvar VAR_0x8004, USING_UNION_ROOM
	copyvar VAR_CABLE_CLUB_STATE, VAR_0x8004
	special HelpSystem_Disable
	call CableClub_EventScript_OpenUnionRoomBarrier
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 5, 1
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	closedoor 5, 1
	waitdooranim
	special Script_ResetUnionRoomTrade
	special SetCableClubWarp
	warpspinenter MAP_UNION_ROOM, 7, 11
	waitstate
	special RunUnionRoom
	waitstate
	end

CableClub_EventScript_CheckPartyUnionRoomRequirements::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_lt VAR_RESULT, 2, CableClub_EventScript_NeedTwoMonsForUnionRoom
	specialvar VAR_RESULT, DoesPartyHaveEnigmaBerry
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_NoEnigmaBerryInUnionRoom
	setvar VAR_RESULT, TRUE
	return

CableClub_EventScript_NeedTwoMonsForUnionRoom::
	msgbox CableClub_Text_NeedTwoMonsForUnionRoom
	goto EventScript_SetResultFalse
	end

CableClub_EventScript_NoEnigmaBerryInUnionRoom::
	msgbox CableClub_Text_NoEnigmaBerryInUnionRoom
	goto EventScript_SetResultFalse
	end

CableClub_EventScript_UnionRoomAdapterNotConnected::
	msgbox CableClub_Text_UnionRoomAdapterNotConnected
	release
	return

CableClub_EventScript_WirelessClubAttendant::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
	msgbox CableClub_Text_AskAboutLinking, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_DontAskAboutLinking
	msgbox CableClub_Text_ExplainWirelessClub
	release
	return

CableClub_EventScript_DontAskAboutLinking::
	msgbox CableClub_Text_HopeYouEnjoyWirelessSystem
	release
	return

CableClub_EventScript_DirectCornerAttendant::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_WirelessClubAdjustements
	specialvar VAR_RESULT, IsBadEggInParty
	goto_if_eq VAR_RESULT, TRUE, CableClub_EventScript_AbortLinkPlayerHasBadEgg
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_WelcomeToCableClub
	message CableClub_Text_WelcomeWhichDirectCornerRoom
	waitmessage
	delay 15
	goto CableClub_EventScript_DirectCornerSelectService
	end

CableClub_EventScript_DirectCornerSelectService::
	goto_if_unset FLAG_GOT_POWDER_JAR, CableClub_EventScript_DirectCornerNoBerry
	multichoice 0, 0, MULTICHOICE_TRADE_COLOSSEUM_CRUSH, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade
	case 1, CableClub_EventScript_WirelessBattleSelect
	case 2, CableClub_EventScript_WirelessBerryCrush
	case 3, CableClub_EventScript_AbortLink
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_DirectCornerNoBerry::
	multichoice 0, 0, MULTICHOICE_TRADE_COLOSSEUM_2, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessTrade
	case 1, CableClub_EventScript_WirelessBattleSelect
	case 2, CableClub_EventScript_AbortLink
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_WirelessTrade::
	msgbox CableClub_Text_TradePokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_AbortLink
	call CableClub_EventScript_CheckPartyTradeRequirements
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_AbortLink
	setvar VAR_0x8004, LINK_GROUP_TRADE
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_WirelessBattleSelect::
	message CableClub_Text_PlayWhichBattleMode
	waitmessage
	multichoice 0, 0, MULTICHOICE_SINGLE_DOUBLE_MULTI_INFO_EXIT, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_WirelessSingleBattle
	case 1, CableClub_EventScript_WirelessDoubleBattle
	case 2, CableClub_EventScript_WirelessMultiBattle
	case 3, CableClub_EventScript_WirelessBattleInfo
	case 4, CableClub_EventScript_AbortLink
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_WirelessSingleBattle::
	setvar VAR_0x8004, LINK_GROUP_SINGLE_BATTLE
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_WirelessDoubleBattle::
	special HasEnoughMonsForDoubleBattle
	goto_if_ne VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS, CableClub_EventScript_TwoMonsNeededForWirelessDoubleBattle
	setvar VAR_0x8004, LINK_GROUP_DOUBLE_BATTLE
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_TwoMonsNeededForWirelessDoubleBattle::
	msgbox CableClub_Text_NeedTwoMonsForDoubleBattle
	goto CableClub_EventScript_WirelessBattleSelect
	end

CableClub_EventScript_WirelessMultiBattle::
	setvar VAR_0x8004, LINK_GROUP_MULTI_BATTLE
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_WirelessBattleInfo::
	msgbox CableClub_Text_ExplainBattleModes
	goto CableClub_EventScript_WirelessBattleSelect
	end

CableClub_EventScript_WirelessBerryCrush::
	msgbox CableClub_Text_UseBerryCrush, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_AbortLink
	special HasAtLeastOneBerry
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_NeedBerryForBerryCrush
	setvar VAR_0x8004, LINK_GROUP_BERRY_CRUSH
	goto CableClub_EventScript_SaveAndChooseLinkLeader
	end

CableClub_EventScript_NeedBerryForBerryCrush::
	msgbox CableClub_Text_NeedBerryForBerryCrush
	goto CableClub_EventScript_DirectCornerSelectService
	end

CableClub_EventScript_SaveAndChooseLinkLeader::
	call EventScript_AskSaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortLink
	switch VAR_0x8004
	case LINK_GROUP_TRADE, CableClub_EventScript_ChooseLinkLeaderFrom2
	case LINK_GROUP_SINGLE_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom2
	case LINK_GROUP_DOUBLE_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom2
	case LINK_GROUP_MULTI_BATTLE, CableClub_EventScript_ChooseLinkLeaderFrom4
	case LINK_GROUP_BERRY_CRUSH, CableClub_EventScript_ChooseLinkLeader
	end

CableClub_EventScript_ChooseLinkLeaderFrom2::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message CableClub_Text_ChooseGroupLeaderOfTwo
	waitmessage
	call EventScript_RestorePrevTextColor
	multichoice 13, 6, MULTICHOICE_JOIN_OR_LEAD, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroup2Players
	case 1, CableClub_EventScript_TryLeadGroup2Players
	case 2, CableClub_EventScript_AbortLink
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_TryLeadGroup2Players::
	call CableClub_EventScript_TryBecomeLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom2
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryLeadGroup2Players
	release
	return

CableClub_EventScript_TryJoinGroup2Players::
	call CableClub_EventScript_TryJoinLinkGroup
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom2
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinGroup2Players
	release
	return

CableClub_EventScript_ChooseLinkLeaderFrom4::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message CableClub_Text_ChooseGroupLeaderOfFour
	waitmessage
	call EventScript_RestorePrevTextColor
	multichoice 13, 6, MULTICHOICE_JOIN_OR_LEAD, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroup4Players
	case 1, CableClub_EventScript_TryLeadGroup4Players
	case 2, CableClub_EventScript_AbortLink
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_TryLeadGroup4Players::
	call CableClub_EventScript_TryBecomeLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom4
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryLeadGroup4Players
	release
	return

CableClub_EventScript_TryJoinGroup4Players::
	call CableClub_EventScript_TryJoinLinkGroup
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderFrom4
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinGroup4Players
	release
	return

CableClub_EventScript_ChooseLinkLeader::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message CableClub_Text_ChooseGroupLeader
	waitmessage
	call EventScript_RestorePrevTextColor
	multichoice 13, 6, MULTICHOICE_JOIN_OR_LEAD, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinGroupXPlayers
	case 1, CableClub_EventScript_TryLeadGroupXPlayers
	case 2, CableClub_EventScript_AbortLink
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortLink
	end

CableClub_EventScript_TryLeadGroupXPlayers::
	call CableClub_EventScript_TryBecomeLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryLeadGroupXPlayers
	release
	return

CableClub_EventScript_TryJoinGroupXPlayers::
	call CableClub_EventScript_TryJoinLinkGroup
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterWirelessLinkRoom
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinGroupXPlayers
	release
	return

CableClub_EventScript_TryBecomeLinkLeader::
	special HelpSystem_Disable
	special TryBecomeLinkLeader
	waitstate
	return

CableClub_EventScript_TryJoinLinkGroup::
	special HelpSystem_Disable
	special TryJoinLinkGroup
	waitstate
	return

CableClub_EventScript_EnterWirelessLinkRoom::
	messageautoscroll CableClub_Text_DirectYouToYourRoom
	waitmessage
	delay 60
	closemessage
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_OpenDirectCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerApproachLinkRoomLeft
	waitmovement 0
	opendoor 9, 1
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterLinkRoom
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	closedoor 9, 1
	waitdooranim
	release
	waitstate
	end

CableClub_EventScript_ShowWirelessCommunicationScreen::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	goto_if_unset FLAG_SYS_POKEDEX_GET, CableClub_EventScript_NotReadyYet
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_AdapterNotConnected
	special HelpSystem_Disable
	fadescreen FADE_TO_BLACK
	special ShowWirelessCommunicationScreen
	waitstate
	msgbox CableClub_Text_ParticipantsStepUpToCounter
	special HelpSystem_Enable
	releaseall
	end

CableClub_EventScript_AdapterNotConnected::
	msgbox CableClub_Text_AdapterNotConnected
	releaseall
	end

CableClub_EventScript_OpenUnionRoomBarrier::
	setmetatile 5, 3, METATILE_PokemonCenter_Floor_ShadeLeft, 0
	return

CableClub_EventScript_CloseUnionRoomBarrier::
	setmetatile 5, 3, METATILE_PokemonCenter_CounterBarrier, 1
	return

CableClub_EventScript_OpenDirectCornerBarrier::
	setmetatile 9, 3, METATILE_PokemonCenter_Floor_ShadeLeft, 0
	return

CableClub_EventScript_CloseDirectCornerBarrier::
	setmetatile 9, 3, METATILE_PokemonCenter_CounterBarrier, 1
	return

CableClub_EventScript_OpenGameCornerBarrier::
	setmetatile 5, 3, METATILE_GameCorner_CheckeredFloor_ShadeLeft, 0
	return

CableClub_EventScript_CloseGameCornerBarrier::
	setmetatile 5, 3, METATILE_GameCorner_CounterBarrier, 1
	return

CableClub_OnResume::
	special InitUnionRoom
	end

JoyfulGameCorner_EventScript_InfoMan2::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	message Text_DescribeWhichGame
	waitmessage
	multichoice 0, 0, MULTICHOICE_POKEJUMP_DODRIO, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_PokemonJumpInfo
	case 1, CableClub_EventScript_DodrioBerryPickingInfo
	case 2, CableClub_EventScript_MinigameInfoExit
	case SCR_MENU_CANCEL, CableClub_EventScript_MinigameInfoExit
	end

CableClub_EventScript_PokemonJumpInfo::
	msgbox Text_PokemonJumpInfo
	release
	end

CableClub_EventScript_DodrioBerryPickingInfo::
	msgbox Text_DodrioBerryPickingInfo
	release
	end

CableClub_EventScript_MinigameInfoExit::
	msgbox Text_TalkToManToPlay
	release
	end

JoyfulGameCorner_EventScript_MinigameAttendant::
	goto_if_questlog EventScript_ReleaseEnd
	special QuestLog_CutRecording
	lock
	faceplayer
	message Text_WelcomeCanYouWait
	waitmessage
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_AdapterNotConnectedMinigame
	delay 60
	special HelpSystem_Disable
	message Text_PlayWhichGame
	waitmessage
	multichoice 0, 0, MULTICHOICE_POKEJUMP_DODRIO, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_PlayPokemonJump
	case 1, CableClub_EventScript_PlayDodrioBerryPicking
	case 2, CableClub_EventScript_AbortMinigame
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortMinigame
	end

CableClub_EventScript_PlayPokemonJump::
	setvar VAR_0x8005, 0
	special IsPokemonJumpSpeciesInParty
	goto_if_eq VAR_RESULT, FALSE, CableClub_EventScript_NoEligiblePkmn
	msgbox Text_EnterWhichPokemon
	setvar VAR_0x8005, 0
	special ChooseMonForWirelessMinigame
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, CableClub_EventScript_AbortMinigame
	call EventScript_AskSaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortMinigame
	setvar VAR_0x8004, LINK_GROUP_POKEMON_JUMP
	goto CableClub_EventScript_ChooseLinkLeaderMinigame
	end

CableClub_EventScript_PlayDodrioBerryPicking::
	setvar VAR_0x8005, 1
	special IsDodrioInParty
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_NoEligiblePkmn
	msgbox Text_EnterWhichPokemon
	setvar VAR_0x8005, 1
	special ChooseMonForWirelessMinigame
	waitstate
	goto_if_ge VAR_0x8004, PARTY_SIZE, CableClub_EventScript_AbortMinigame
	call EventScript_AskSaveGame
	goto_if_eq VAR_RESULT, 0, CableClub_EventScript_AbortMinigame
	setvar VAR_0x8004, LINK_GROUP_BERRY_PICKING
	goto CableClub_EventScript_ChooseLinkLeaderMinigame
	end

CableClub_EventScript_ChooseLinkLeaderMinigame::
	textcolor NPC_TEXT_COLOR_NEUTRAL
	message CableClub_Text_ChooseGroupLeader
	waitmessage
	call EventScript_RestorePrevTextColor
	multichoice 13, 6, MULTICHOICE_JOIN_OR_LEAD, FALSE
	switch VAR_RESULT
	case 0, CableClub_EventScript_TryJoinMinigameLinkGroup
	case 1, CableClub_EventScript_TryBecomeMinigameLinkLeader
	case 2, CableClub_EventScript_AbortMinigame
	case SCR_MENU_CANCEL, CableClub_EventScript_AbortMinigame
	end

CableClub_EventScript_TryBecomeMinigameLinkLeader::
	call CableClub_EventScript_TryBecomeLinkLeader
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterMinigame
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderMinigame
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryBecomeMinigameLinkLeader
	release
	return

CableClub_EventScript_TryJoinMinigameLinkGroup::
	call CableClub_EventScript_TryJoinLinkGroup
	goto_if_eq VAR_RESULT, LINKUP_SUCCESS, CableClub_EventScript_EnterMinigame
	goto_if_eq VAR_RESULT, LINKUP_FAILED, CableClub_EventScript_ChooseLinkLeaderMinigame
	goto_if_eq VAR_RESULT, LINKUP_RETRY_ROLE_ASSIGN, CableClub_EventScript_TryJoinMinigameLinkGroup
	release
	return

CableClub_EventScript_EnterMinigame::
	messageautoscroll Text_AllGoodToGo
	waitmessage
	delay 120
	closemessage
	copyvar VAR_0x8007, VAR_LAST_TALKED
	call CableClub_EventScript_OpenGameCornerBarrier
	special DrawWholeMapView
	playse SE_CLICK
	delay 60
	applymovement VAR_LAST_TALKED, Movement_AttendantFaceLeft
	waitmovement 0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerEnterMinigameRoom
	waitmovement 0
	hideobjectat OBJ_EVENT_ID_PLAYER, 0
	release
	waitstate
	end

CableClub_EventScript_AdapterNotConnectedMinigame::
	msgbox Text_AdapterNotConnectedMinigame
	release
	end

CableClub_EventScript_NoEligiblePkmn::
	msgbox EventScript_ExplainPokemonJumpRequirements, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, CableClub_EventScript_AbortMinigame
	call_if_eq VAR_0x8005, 0, CableClub_EventScript_ExplainPokemonJumpRequirements
	call_if_eq VAR_0x8005, 1, CableClub_EventScript_ExplainDodrioBerryPickingRequirements
	goto CableClub_EventScript_AbortMinigame
	end

CableClub_EventScript_ExplainPokemonJumpRequirements::
	msgbox Text_ShortJumpingPokemonAllowed
	return

CableClub_EventScript_ExplainDodrioBerryPickingRequirements::
	msgbox Text_OnlyDodrioAllowed
	return

TwoIsland_JoyfulGameCorner_EventScript_ShowPokemonJumpRecords::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	special ShowPokemonJumpRecords
	waitstate
	releaseall
	end

TwoIsland_JoyfulGameCorner_EventScript_ShowDodrioBerryPickingRecords::
	goto_if_questlog EventScript_ReleaseEnd
	lockall
	special ShowDodrioBerryPickingRecords
	waitstate
	releaseall
	end

CableClub_Text_WelcomeWhichCableClubService::
	.string "POKéMON KABLO KULÜBÜ'ne\n"
	.string "hoşgeldiniz.\p"
	.string "Hangi servislerimizi kullanmak\n"
	.string "istersiniz?$"

CableClub_Text_WhichService::
	.string "Hangi servislerimizi kullanmak\n"
	.string "istersiniz?$"

CableClub_Text_TradeMonsUsingLinkCable::
	.string "Başka birisi ile GBA Link Kablosu\n"
	.string "kullanarak POKéMON takası yap.$"

CableClub_Text_BattleUsingLinkCable::
	.string "GBA Link Kablosu ile başka bir\n"
	.string "EĞİTMEN ile savaşabilirsin.$"

@ Unused, translated in Emerald
CableClub_Text_CloseThisMenu::
	.string "おわります$"

CableClub_Text_NeedTwoMonsForDoubleBattle::
	.string "ÇİFTLİ SAVAŞ için en az iki\n"
	.string "POKéMON gerekiyor.$"

CableClub_Text_NeedTwoMonsToTrade::
	.string "Takas yapmak için en az iki\n"
	.string "POKéMON'unun olması gerekiyor.$"

CableClub_Text_CantTradeEnigmaBerry::
	.string "{STR_VAR_1} MEYVESİ tutan\n"
	.string "POKéMON takas edilemez.$"

CableClub_Text_PleaseWaitBCancel::
	.string "Lütfen bekleyin.\n"
	.string "… … B Tuşu: İptal$"

CableClub_Text_WhenAllPlayersReadyAConfirmBCancel::
	.string "Tüm oyuncular hazır olunca…\n"
	.string "A Tuşu: Onay\l"
	.string "B Tuşu: İptal$"

CableClub_Text_StartLinkWithXPlayersAConfirmBCancel::
	.string "{STR_VAR_1} oyuncu ile bağlantıyı\n"
	.string "başlat.\l"
	.string "A Tuşu: Onay\l"
	.string "B Tuşu: İptal$"

CableClub_Text_AwaitingLinkupBCancel::
	.string "Bağlantı bekleniyor…\n"
	.string "… … B Tuşu: İptal$"

@ Unused, translated in Emerald
CableClub_Text_OkayToSaveProgress::
	.string "はじめる　まえに　レポートを\n"
	.string "かきますが　よろしいですか？$"

CableClub_Text_PleaseEnter::
	.string "Lütfen girin.$"

CableClub_Text_DirectYouToYourRoom::
	.string "Sizi şimdi odanıza yönlendireceğim.$"

CableClub_Text_SomeoneIsNotReadyToLink::
	.string "Birisi bağlantıya hazır değil.\p"
	.string "Lütfen herkes hazır olduğunda\n"
	.string "tekrar gelin.$"

CableClub_Text_LinkErrorPleaseReset::
	.string "Bağlantı hatası oluştu…\n"
	.string "Lütfen tekrar deneyin.$"

CableClub_Text_PlayersMadeDifferentSelections::
	.string "Bağlantı partnerleri farklı seçim\n"
	.string "yapmış görünüyor.$"

CableClub_Text_PleaseVisitAgain::
	.string "Yine bekleriz.$"

CableClub_Text_IncorrectNumberOfParticipants::
	.string "Katılımcı sayısı hatalı.$"

CableClub_Text_CantSingleBattleWithXPlayers::
	.string "TEKLİ SAVAŞ modu {STR_VAR_1} adet\n"
	.string "oyuncu ile oynanılamaz.$"

CableClub_Text_CantDoubleBattleWithXPlayers::
	.string "ÇİFTLİ SAVAŞ modu {STR_VAR_1} adet\n"
	.string "oyuncu ile oynanılamaz.$"

CableClub_Text_NeedFourPlayers::
	.string "Bu savaş modu için 4 kişi\n"
	.string "gerekiyor.$"

CableClub_Text_PleaseConfirmNumberAndRestart::
	.string "Lütfen oyuncu sayısını tasdik\n"
	.string "edip tekrar deneyin.$"

Text_TerminateLinkIfYouLeaveRoom::
	.string "Eğer odayı terkederseniz bağlantı\n"
	.string "kesilecek. Kabul ediyor musun?$"

Text_TerminateLinkConfirmation::
	.string "Bağlantı kesiliyor…\n"
	.string "Odanın dışına çıkarılacaksınız.\l"
	.string "Lütfen bekleyin.$"

Text_TrainerTooBusyToNotice::
    .string "Bu EĞİTMEN çok meşgul, fark\n"
    .string "edemiyor…$"

Text_LookedAtPlayersTrainerCard::
    .string "Harika! {STR_VAR_1}'in\n"
    .string "EĞİTMEN KARTI'nı inceledim!$"

Text_LookedAtPlayersTrainerCardColored::
    .string "Harika! {STR_VAR_1}'in\n"
    .string "EĞİTMEN KARTI'nı inceledim!\p"
    .string "Bu bir {STR_VAR_2} kartı!$"

Text_TakeSeatStartBattle::
    .string "Lütfen yerinizi alın ve\n"
    .string "mücadelenize başlayın.$"

Text_TakeSeatStartTrade::
    .string "Lütfen yerinizi alın ve\n"
    .string "takasa başlayın.$"

@ Unused, leftover from RS
RecordCorner_Text_ThanksForComing::
	.string "ごりよう　ありがとう　ございました$"

CableClub_Text_TrainerCardDataOverwritten::
    .string "EĞİTMEN KARTI verileri\n"
    .string "üzerine yazılacak.$"

CableClub_Text_HopeToSeeYouAgain::
    .string "Tekrar görüşmek dileğiyle!$"

CableClub_Text_NotSetUpForFarAwayRegion::
    .string "Çok özür dilerim.\p"
    .string "Henüz uzak bir bölgede bulunan\n"
    .string "EĞİTMENLER ile ticaret yapabilecek\l"
    .string "şekilde ayarlı değiliz…$"

CableClub_Text_OtherTrainerNotReady::
    .string "Diğer EĞİTMEN hazır değil.$"

CableClub_Text_YouHaveAMonThatCantBeTaken::
    .string "Elinizde alınamayan en az bir\n"
    .string "POKéMON var.$"

CableClub_Text_AdapterNotConnected::
    .string "Kablosuz Adaptör doğru\n"
    .string "şekilde bağlı değil.$"

CableClub_Text_ParticipantsStepUpToCounter::
    .string "Katılımcıların resepsiyon\n"
    .string "tezgahına yaklaşmaları isteniyor.$"

@ Unused, translated in Emerald
CableClub_Text_Hello::
	.string "こんにちは！$"

@ Unused, translated in Emerald
CableClub_Text_PleaseWait::
	.string "しょうしょう　おまちください$"

CableClub_Text_YouMayTradeHere::
    .string "Burada POKéMON'unuzu başka bir\n"
    .string "EĞİTMEN ile takas edebilirsiniz.$"

CableClub_Text_YouMayBattleHere::
    .string "Burada arkadaşlarınızla\n"
    .string "dövüşebilirsiniz.$"

CableClub_Text_CanMakeBerryPowder::
    .string "İki ila beş EĞİTMEN birlikte\n"
    .string "MEYVE TOZU yapabilir.$"

@ Unused, Record Mix nopped
CableClub_Text_CanMixRecords::
	.string "ワイヤレス　クラブでの\n"
	.string "あそびかたを　せつめいします$"

CableClub_Text_CancelSelectedItem::
    .string "Seçilen MENÜ ögesini iptal eder.$"

@ Unused, translated in Emerald
CableClub_Text_WhichBattleMode::
	.string "どちらの　しょうぶに　しますか？$"

@ Unused, translated in Emerald
CableClub_Text_ReturnsToPreviousStep::
	.string "ひとつ　まえに　もどります$"

CableClub_Text_NeedBerryForBerryCrush::
    .string "MEYVE EZ hizmetini kullanmak için\n"
    .string "en az bir MEYVE'ye sahip\l"
	.string "olmalısınız.$"

CableClub_Text_NeedTwoMonsForUnionRoom::
    .string "BİRLİK ODASI'na girmek için en az\n"
    .string "iki POKéMON'a sahip olmalısınız.$"

CableClub_Text_NoEnigmaBerryInUnionRoom::
    .string "BİRLİK ODASI'na {STR_VAR_1} MEYVE'ye\n"
    .string "sahip bir POKéMON giremez.$"

CableClub_Text_UnionRoomAdapterNotConnected::
    .string "Bu POKéMON KABLOSUZ KULÜBÜ\n"
    .string "BİRLİK ODASI'dır.\p"
    .string "Maalesef, Kablosuz Adaptörünüz\n"
    .string "doğru şekilde bağlanmamış.\p"
    .string "Lütfen tekrar gelin.$"

@ Unused, translated in Emerald
CableClub_Text_OhExcuseMe::
	.string "あ‥‥\n"
	.string "おきゃくさま！$"

Text_PlayerIsPlayingRightNowGoForIt::
    .string "{STR_VAR_1} şu anda oynuyor gibi\n"
    .string "görünüyor.\l"
    .string "Hadi yapabilirsin!$"

Text_DescribeWhichGame::
    .string "Oyun kurallarını açıklayabilirim,\n"
    .string "eğer istersen.\p"
    .string "Hangi oyunu açıklayayım?$"

Text_PokemonJumpInfo::
    .string "“POKÉMON ZIPLA”\p"
    .string "POKÉMON'unuzu A Düğmesi ile\n"
    .string "KAMÇI YAPRAK ipinin üzerinden\l"
    .string "atlatarak atlattırın.\p"
    .string "Sadece 28 inç veya daha küçük\n"
    .string "POKÉMON'lar katılabilir.\p"
    .string "Sadece yüzme, kazma veya\n"
    .string "uçma yeteneği olan POKÉMON'lar\l"
    .string "atlama konusunda iyi değildir.\p"
    .string "Bu nedenle, bu POKÉMON'lar\n"
    .string "katılamayabilir.\p"
    .string "Herkes zamanında atlarsa\n"
    .string "güzel şeyler olur.$"

Text_DodrioBerryPickingInfo::
    .string "“DODRIO MEYVE-TOPLAMA”\p"
    .string "DODRIO'nun üç başını düşen\n"
    .string "MEYVELERİ yakalamak için oynatın.\p"
    .string "Kafaları hareket ettirmek için\n"
    .string "{PLUS} Kontrol Düğmesi'nde sağa,\l"
    .string "yukarıya veya sola basın.\p"
    .string "Bu oyunu oynayabilmek için\n"
    .string "bir DODRIO'nuz olmalı.$"

Text_TalkToManToPlay::
    .string "Bir oyun oynamak istiyorsanız,\n"
    .string "yanımda duran adama söyleyin.$"

Text_WelcomeCanYouWait::
    .string "Merhaba, hoş geldiniz!\n"
    .string "Oyunları Kablosuz İletişim Sistemi\n"
    .string "üzerinden oynayabilirsiniz.\p"
    .string "Biraz bekleyebilir misiniz?$"

CableClub_Text_ComeAgain::
    .string "Tamam, tekrar gelin!$"

Text_AdapterNotConnectedMinigame::
    .string "Kablosuz Adaptör bağlı değil.\n"
    .string "Bağladıktan sonra geri gelin!$"

Text_PlayWhichGame::
    .string "Tamam, hangi oyunu oynamak\n"
    .string "istiyorsunuz?$"

Text_EnterWhichPokemon::
    .string "Hangi POKéMON ile girmek\n"
    .string "istersiniz?$"

Text_AllGoodToGo::
    .string "Tamam, her şey hazır.\n"
    .string "Diğerlerinin seni yenmesine izin verme!$"

@ Unused, translated in Emerald
Text_LeavingDoComeAgain::
	.string "きょうは　けえるのか？\n"
	.string "またこいよ！$"

EventScript_ExplainPokemonJumpRequirements::
    .string "Görünüşe göre girebileceğin hiç\n"
    .string "POKéMON'un yok…\p"
    .string "Hangi tür POKéMON'ların girebileceğini\n"
    .string "açıklamamı ister misin?$"

Text_ShortJumpingPokemonAllowed::
    .string "“POKéMON ZIPLA” sadece 28 inç\n"
    .string "veya daha kısa olan POKéMON'lara.\l"
	.string "açıktır.\p"
    .string "Girebileceğin POKéMON'lar\n"
	.string "zıplayabilenlerdir.\p"
    .string "Sadece yüzen, kazan veya uçan\n"
    .string "POKéMON'lar bu oyuna giremezler.\p"
    .string "Bilmen gereken her şey bu.$"

Text_OnlyDodrioAllowed::
    .string "“DODRIO MEYVE-TOPLAMA”…\n"
    .string "Eh, ismi her şeyi anlatıyor.\p"
    .string "Bu oyunu oynamak için bir\n"
    .string "DODRIO'ya sahip olmalısın.$"

@ Unused, translated in Emerald
Text_RetryFromStartPlease::
	.string "もういちど　はじめから\n"
	.string "やりなおして　みて　くれ$"

CableClub_Text_WelcomeWhichDirectCornerRoom::
    .string "POKéMON KABLOSUZ KULÜBÜ DİREKT\n"
    .string "KÖŞESİ'ne hoş geldin.\p"
    .string "Burada arkadaşlarınla doğrudan\n"
    .string "iletişim kurabilirsin.\p"
    .string "Hangi odaya girmek istersin?$"

CableClub_Text_TradePokemon::
    .string "POKéMON takası yapmak ister misin?$"

CableClub_Text_PlayWhichBattleMode::
    .string "Hangi Savaş Modunu oynamak istersin?$"

CableClub_Text_UseBerryCrush::
    .string "MEYVE EZ Sistemi'ni kullanmak\n"
    .string "ister misin?$"

CableClub_Text_ExplainBattleModes::
    .string "Üç tane Savaş Modu bulunmaktadır.\p"
    .string "TEKLİ SAVAŞ, her birinin bir veya\n"
    .string "daha fazla POKéMON'a sahip olduğu\l"
    .string "iki EĞİTMEN içindir.\p"
    .string "Her EĞİTMEN savaşta bir seferde bir\n"
    .string "POKéMON kullanabilir.\p"
    .string "İKİLİ SAVAŞ, her birinin iki veya\n"
    .string "daha fazla POKéMON'a sahip olduğu\n"
    .string "iki EĞİTMEN içindir.\p"
    .string "Her EĞİTMEN savaşta bir seferde iki\n"
    .string "POKéMON gönderir.\p"
    .string "ÇOKLU SAVAŞ, her birinin bir veya\n"
    .string "daha fazla POKéMON'a sahip olduğu\l"
    .string "dört EĞİTMEN içindir.\p"
    .string "Her EĞİTMEN savaşta bir seferde bir\n"
    .string "POKéMON kullanabilir.$"

CableClub_Text_ChooseGroupLeaderOfTwo::
    .string "Lütfen ikinizden hangisinin\n"
    .string "GRUP LİDERİ olacağını seçin.\p"
    .string "Diğer oyuncu ardından “GRUP \n"
    .string "KATIL” seçeneğini seçmelidir.$"

CableClub_Text_ChooseGroupLeaderOfFour::
    .string "Lütfen dördünüzden hangisinin\n"
    .string "GRUP LİDERİ olacağını seçin.\p"
    .string "Diğer oyuncular ardından “GRUP\n"
    .string "KATIL”seçeneğini seçmelidir.$"

CableClub_Text_ChooseGroupLeader::
    .string "Lütfen hanginizin\n"
    .string "GRUP LİDERİ olacağını seçin.\p"
    .string "Diğer oyuncular ardından “GRUP\n"
    .string "KATIL” seçeneğini seçmelidir.$"

CableClub_Text_WelcomeUnionRoomEnter::
    .string "POKéMON KABLOSUZ KULÜP\n"
    .string "BİRLİK ODASI'na hoş geldiniz.\p"
    .string "Burada diğer EĞİTMENLER ile\n"
    .string "iletişim kurabilirsiniz. Bazıları\n"
    .string "belki de tanımadığınız kişiler.\l"
	.string "olabilir.\p"
    .string "Odaya girmek ister misiniz?$"

CableClub_Text_UnionRoomInfo::
    .string "BİRLİK ODASI'ndaki EĞİTMENLER\n"
    .string "etrafınızdaki ve ODA'ya giren\l"
    .string "oyuncular olacaktır.\p"
    .string "Burada selamlaşma gibi her türlü\n"
    .string "etkileşimde bulunabilirsiniz.\p"
    .string "Bire-bir savaş için iki POKéMON'u\n"
    .string "Lv. 30'a kadar seçebilirsiniz.\p"
    .string "İki ila beş kişiyle sohbet\n"
	.string "edebilirsiniz.\p"
    .string "Veya bir POKéMON'u takas için\n"
	.string "kaydedebilirsiniz.\p"
    .string "Odaya girmek ister misiniz?$"

CableClub_Text_EnjoyUnionRoom::
	.string "Umarım BİRLİK ODASI'nda iyi\n"
	.string "zaman geçirirsiniz.$"

CableClub_Text_FirstTimeRightThisWay::
    .string "Merhaba!\n"
    .string "Benim adım TEALA.\p"
    .string "Burada yeni olduğunuz belli.\p"
    .string "Kablosuz İletişim Sistemi'ni nasıl\n"
    .string "kullanacağınızı göstereceğim.\p"
    .string "Öncelikle, POKéMON MERKEZİ'mizin\n"
    .string "bu katını göstermek istiyorum.\p"
    .string "Bu yoldan ilerleyin, lütfen.$"

CableClub_Text_ExplainWirelessClubFirstTime::
    .string "Üst katta iki oda var.\p"
    .string "Birincisi soldaki oda.\n"
    .string "Bu oda BİRLİK ODASI'dır.\p"
    .string "Burada etrafınızdaki ve BİRLİK\n"
    .string "ODASI'na giren EĞİTMENLER ile\l"
	.string "bağlanabilirsiniz.\p"
    .string "Onlarla sohbet edebilir,\n"
    .string "savaşabilir ve takas\l"
	.string "yapabilirsiniz.\p"
    .string "İkincisi, sağdaki oda\n"
    .string "DİREKT KÖŞE'dir.\p"
    .string "Bu odada arkadaşlarınızla POKéMON\n"
    .string "takas edebilir veya\l"
	.string "savaşabilirsiniz.\p"
    .string "Kablosuz Adaptör bağlı değilse,\n"
    .string "GBA Link Kablosu kullanarak da\l"
    .string "bağlanabilirsiniz.\p"
    .string "Bu durumda, DİREKT KÖŞE'ye\n"
	.string "gitmelisiniz.\p"
    .string "Kablosuz İletişim Sistemi'ni\n"
    .string "beğenmenizi umuyorum.$"

CableClub_Text_AskAboutLinking::
    .string "Merhaba, {PLAYER}!\p"
    .string "Ben TEALA, POKéMON MERKEZİ 2. kat\n"
    .string "görevlisiyim.\p"
    .string "Bağlantı hakkında bana sormak\n"
    .string "istediğiniz bir şey var mı?$"

CableClub_Text_ExplainWirelessClub::
    .string "POKéMON KABLOSUZ KULÜP'ün nasıl\n"
    .string "çalıştığını açıklayayım.\p"
    .string "Bu, üst kattaki iki odadan\n"
    .string "birincisi soldaki odadır.\p"
    .string "Bu, BİRLİK ODASI'dır.\p"
    .string "Burada, BİRLİK ODASI'na giriş\n"
    .string "yapan diğer EĞİTMENLER ile\n"
    .string "bağlantı kurabilirsiniz.\p"
    .string "Onlarla sohbet edebilir,\n"
    .string "savaşabilir ve ticaret\l"
	.string "yapabilirsiniz.\p"
    .string "İkincisi, sağdaki oda ise\n"
    .string "DİREKT KÖŞE'dir.\p"
    .string "Bu odada arkadaşlarınızla POKéMON\n"
    .string "ticareti yapabilir veya\l"
	.string "savaşabilirsiniz.\p"
    .string "Bazen BİRLİK ODASI veya DİREKT\n"
    .string "KÖŞE'de arkadaşlarınızı\l"
	.string "bulamayabilirsiniz.\p"
    .string "Bu durumda, arkadaşlarınıza daha\n"
    .string "yakınlaşmanızı öneririm.\p"
    .string "Eğer Kablosuz Adaptör bağlı\n"
    .string "değilse, hala GBA Link Kablosunu\l"
    .string "kullanarak bağlantı yapabilirsiniz.\p"
    .string "Böyle bir durumda, DİREKT KÖŞE'ye\n"
    .string "gitmelisiniz.\p"
    .string "Kablosuz İletişim Sistemini\n"
    .string "beğenmenizi umarım.$"

CableClub_Text_HopeYouEnjoyWirelessSystem::
	.string "Kablosuz İletişim Sistemini\n"
    .string "beğenmenizi umarım.$"
