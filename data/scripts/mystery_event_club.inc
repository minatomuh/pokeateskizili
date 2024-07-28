.equ GAVE_PROFILE,  VAR_TEMP_1

MysteryEventClub_EventScript_Woman::
	lock
	faceplayer
	goto_if_eq GAVE_PROFILE, TRUE, EventScript_AlreadyGaveProfile
	goto_if_set FLAG_SYS_SET_TRAINER_CARD_PROFILE, EventScript_GivenProfileBefore
	msgbox Text_IdLoveToHearYourProfile
	goto EventScript_AskForProfile
	end

EventScript_AlreadyGaveProfile:
	msgbox Text_TellMoreNextTime
	release
	end

EventScript_AskForProfile:
	message Text_TellMeWhatsYourProfile
	waitmessage
	multichoice 18, 6, MULTICHOICE_YES_NO_INFO_2, FALSE
	switch VAR_RESULT
	case 0, EventScript_AcceptGiveProfile
	case 1, EventScript_DeclineGiveProfile
	case 2, EventScript_ProfileInfo
	case SCR_MENU_CANCEL, EventScript_DeclineGiveProfile
	end

EventScript_ProfileInfo:
	msgbox Text_ExplainProfile
	goto EventScript_AskForProfile
	end

EventScript_AcceptGiveProfile:
	msgbox Text_WhatsYourProfile
	closemessage
	goto EventScript_GiveProfile
	end

EventScript_CancelGiveProfile:
	msgbox Text_DecidedNotTo
	release
	end

EventScript_GaveProfile:
	setvar GAVE_PROFILE, TRUE
	setvar VAR_0x8004, 0
	special ShowEasyChatMessage
	waitmessage
	delay 80
	msgbox Text_ProfileSaysSomethingAboutYou
	release
	end

EventScript_DeclineGiveProfile:
	msgbox Text_DontBeLikeThat
	release
	end

EventScript_GivenProfileBefore:
	msgbox Text_HiWeMeetAgain
	goto EventScript_AskForNewProfile
	end

EventScript_AskForNewProfile:
	message Text_ChangeYourProfile
	waitmessage
	multichoice 18, 6, MULTICHOICE_YES_NO_INFO_2, FALSE
	switch VAR_RESULT
	case 0, EventScript_AcceptGiveNewProfile
	case 1, EventScript_DeclineGiveNewProfile
	case 2, EventScript_ProfileInfo2
	case SCR_MENU_CANCEL, EventScript_DeclineGiveNewProfile
	end

EventScript_ProfileInfo2:
	msgbox Text_ExplainProfile
	goto EventScript_AskForNewProfile
	end

EventScript_AcceptGiveNewProfile:
	msgbox Text_WhatAreYouLikeNow
	closemessage
	goto EventScript_GiveProfile
	end

EventScript_DeclineGiveNewProfile:
	msgbox Text_LikeProfileWayItIs
	release
	end

EventScript_GaveSpecialProfile:
	setvar GAVE_PROFILE, TRUE
	setvar VAR_0x8004, 0
	special ShowEasyChatMessage
	waitmessage
	delay 80
	msgbox Text_HeardThatBefore
	release
	end

EventScript_GiveProfile:
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_0x8004, 0, EventScript_GaveSpecialProfile
	goto_if_eq VAR_RESULT, FALSE, EventScript_CancelGiveProfile
	goto_if_eq VAR_RESULT, TRUE, EventScript_GaveProfile
	end

Text_IdLoveToHearYourProfile::
    .string "Merhaba, tanıştığımıza memnun\n"
	.string "oldum!\p"
    .string "…Bu pek dostça bir davranış değil.\n"
    .string "Geri selam vermez misin?\p"
    .string "Yani, hadi bakalım, kendinden\n"
    .string "bahset.\p"
    .string "Profilini duymak isterim!$"

Text_TellMeWhatsYourProfile::
    .string "Kendinle ilgili güzel bir şeyler\n"
    .string "söyle bana. Profilin nedir?$"

Text_ExplainProfile::
    .string "Bir profil dört kelime veya cümle\n"
    .string "kullanılarak yazılır.\p"
    .string "Profilin için seçilecek pek çok\n"
    .string "kelime var.\p"
    .string "Kelime ve cümleler birkaç uygun\n"
    .string "grupta yer alır.\p"
    .string "Önce bir grup seç, sonra bir\n"
    .string "kelime veya cümle seç.\p"
    .string "…Göründüğü kadar zor değil.\n"
    .string "Neden denemiyorsun?$"

Text_WhatsYourProfile::
    .string "Profilin nedir?$"

Text_DontBeLikeThat::
    .string "Aww… Böyle davranma.\n"
    .string "Profilini bana söyleyebilirsin.$"

Text_DecidedNotTo::
    .string "Oh, söylememeye mi karar verdin?\n"
    .string "Dengesizsin, değil mi?$"

Text_HiWeMeetAgain::
    .string "Merhaba!\n"
    .string "Tekrar karşılaştık!$"

Text_ChangeYourProfile::
    .string "Profilini değiştirmek ister\n"
    .string "misin?$"

Text_WhatAreYouLikeNow::
    .string "Şu anda nasıl birisin?\n"
    .string "Gerçekten merak ediyorum.$"

Text_LikeProfileWayItIs::
    .string "Tamam, profilini olduğu gibi\n"
    .string "seviyorsun.\p"
    .string "Ben de öyle düşünüyorum.$"

Text_ProfileSaysSomethingAboutYou::
    .string "Hmm…\p"
    .string "Profilin gerçekten kim olduğunu\n"
    .string "anlatıyor.\p"
    .string "Seni daha iyi tanıdım, bu da\n"
    .string "bizi daha iyi arkadaşlar yaptı!$"

Text_HeardThatBefore::
    .string "Oh, bunu daha önce duydum…\p"
    .string "Uzakta yaşayan kuzenim\n"
    .string "bunu hep söylerdi, sanırım.$"

Text_TellMoreNextTime::
    .string "Lütfen bir dahaki sefere\n"
    .string "kendin hakkında daha fazla bilgi\l"
    .string "ver.$"
