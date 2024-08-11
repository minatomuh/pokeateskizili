#include "global.h"
#include "link_rfu.h"
#include "mystery_gift_server.h"
#include "mystery_gift_client.h"
#include "constants/union_room.h"

ALIGNED(4) const u8 gText_UR_EmptyString[] = _("");
ALIGNED(4) const u8 gText_UR_Colon[] = _(":");
ALIGNED(4) const u8 gText_UR_ID[] = _("{ID}");
ALIGNED(4) const u8 gText_UR_PleaseStartOver[] = _("Lütfen baştan başlayın.");
ALIGNED(4) const u8 gText_UR_WirelessSearchCanceled[] = _("KABLOSUZ İLETİŞİM\nSİSTEM araması iptal edildi.");
ALIGNED(4) static const u8 sText_AwaitingCommunucation2[] = _("ともだちからの れんらくを\nまっています");
ALIGNED(4) const u8 gText_UR_AwaitingCommunication[] = _("{STR_VAR_1}! Başka bir\noyuncudan iletişim bekleniyor.");
ALIGNED(4) const u8 gText_UR_AwaitingLinkPressStart[] = _("{STR_VAR_1}! Bağlantı bekleniyor!\nHerkes hazır olunca START'a basın.");

ALIGNED(4) static const u8 sText_SingleBattle[] = _("シングルバトルを かいさいする");
ALIGNED(4) static const u8 sText_DoubleBattle[] = _("ダブルバトルを かいさいする");
ALIGNED(4) static const u8 sText_MultiBattle[] = _("マルチバトルを かいさいする");
ALIGNED(4) static const u8 sText_TradePokemon[] = _("ポケモンこうかんを かいさいする");
ALIGNED(4) static const u8 sText_Chat[] = _("チャットを かいさいする");
ALIGNED(4) static const u8 sText_DistWonderCard[] = _("ふしぎなカードをくばる");
ALIGNED(4) static const u8 sText_DistWonderNews[] = _("ふしぎなニュースをくばる");
ALIGNED(4) static const u8 sText_DistMysteryEvent[] = _("ふしぎなできごとを かいさいする");
ALIGNED(4) static const u8 sText_HoldPokemonJump[] = _("なわとびを かいさいする");
ALIGNED(4) static const u8 sText_HoldBerryCrush[] = _("きのみマッシャーを かいさいする");
ALIGNED(4) static const u8 sText_HoldBerryPicking[] = _("きのみどりを かいさいする");
ALIGNED(4) static const u8 sText_HoldSpinTrade[] = _("ぐるぐるこうかんを かいさいする");
ALIGNED(4) static const u8 sText_HoldSpinShop[] = _("ぐるぐるショップを かいさいする");

// Unused
static const u8 *const sLinkGroupActionTexts[] = {
    sText_SingleBattle,
    sText_DoubleBattle,
    sText_MultiBattle,
    sText_TradePokemon,
    sText_Chat,
    sText_DistWonderCard,
    sText_DistWonderNews,
    sText_DistWonderCard,
    sText_HoldPokemonJump,
    sText_HoldBerryCrush,
    sText_HoldBerryPicking,
    sText_HoldBerryPicking,
    sText_HoldSpinTrade,
    sText_HoldSpinShop
};

static const u8 sText_1PlayerNeeded[] = _("1 oyuncu\ngerekiyor.");
static const u8 sText_2PlayersNeeded[] = _("2 oyuncu\ngerekiyor.");
static const u8 sText_3PlayersNeeded[] = _("3 oyuncu\ngerekiyor.");
static const u8 sText_4PlayersNeeded[] = _("あと4にん\nひつよう");
static const u8 sText_2PlayerMode[] = _("2-OYUNCU\nMODU");
static const u8 sText_3PlayerMode[] = _("3-OYUNCU\nMODU");
static const u8 sText_4PlayerMode[] = _("4-OYUNCU\nMODU");
static const u8 sText_5PlayerMode[] = _("5-OYUNCU\nMODU");

const u8 *const gTexts_UR_PlayersNeededOrMode[][5] = {
    { // 2 players required
        sText_1PlayerNeeded,
        sText_2PlayerMode
    },
    { // 4 players required
        sText_3PlayersNeeded,
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_4PlayerMode
    },
    { // 2-5 players required
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    { // 3-5 players required
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    }
};

ALIGNED(4) const u8 gText_UR_BButtonCancel[] = _("{B_BUTTON}İPTAL");
ALIGNED(4) static const u8 sText_SearchingForParticipants[] = _("ため\nさんかしゃ ぼしゅうちゅう です！");
ALIGNED(4) const u8 gText_UR_PlayerContactedYouForXAccept[] = _("{STR_VAR_2}, {STR_VAR_1} için\nileişime geçti. Kabul?");
ALIGNED(4) const u8 gText_UR_PlayerContactedYouShareX[] = _("{STR_VAR_2} iletişime geçti.\n{STR_VAR_1}'ı paylaşır mısın?");
ALIGNED(4) const u8 gText_UR_PlayerContactedYouAddToMembers[] = _("{STR_VAR_2} iletişime geçti.\nÜyelere eklensin mi?");
ALIGNED(4) const u8 gText_UR_AreTheseMembersOK[] = _("{STR_VAR_1}!\nBu üyeler tamam mı?");
ALIGNED(4) const u8 gText_UR_CancelModeWithTheseMembers[] = _("{STR_VAR_1} MODU bu üyelerle\niptal edilsin mi?");
ALIGNED(4) const u8 gText_UR_AnOKWasSentToPlayer[] = _("“TAMAM” mesajı {STR_VAR_1}'e\ngönderildi.");

ALIGNED(4) static const u8 sText_OtherTrainerUnavailableNow[] = _("Diğer EĞİTMEN şu anda mevcut\nolmayabilir…\p");
ALIGNED(4) static const u8 sText_CantTransmitTrainerTooFar[] = _("Çok uzak bir EĞİTMEN ile\niletişim kuramazsınız.\p");
ALIGNED(4) static const u8 sText_TrainersNotReadyYet[] = _("Diğer EĞİTMEN(LER) henüz\nhazır değil.\p");

const u8 *const gTexts_UR_CantTransmitToTrainer[] = {
    sText_CantTransmitTrainerTooFar,
    sText_TrainersNotReadyYet
};

ALIGNED(4) const u8 gText_UR_ModeWithTheseMembersWillBeCanceled[] = _("Bu üyelerle {STR_VAR_1} MODU\niptal edilecektir.{PAUSE 90}");
ALIGNED(4) static const u8 sText_MemberNoLongerAvailable[] = _("Artık mevcut olmayan bir\nüye var.\p");


const u8 *const gTexts_UR_PlayerUnavailable[] = {
    sText_OtherTrainerUnavailableNow,
    sText_MemberNoLongerAvailable
};

ALIGNED(4) static const u8 sText_TrainerAppearsUnavailable[] = _("Diğer EĞİTMEN mevcut değil gibi\ngörünüyor…\p");
ALIGNED(4) const u8 gText_UR_PlayerSentBackOK[] = _("{STR_VAR_1} “TAMAM” yanıtını gönderdi!");
ALIGNED(4) const u8 gText_UR_PlayerOKdRegistration[] = _("{STR_VAR_1} kaydınızı üye olarak\ntamamladı.");
ALIGNED(4) static const u8 sText_PlayerRepliedNo[] = _("{STR_VAR_1} “Hayır…” yanıtını verdi.\p");
ALIGNED(4) const u8 gText_UR_AwaitingOtherMembers[] = _("{STR_VAR_1}!\nDiğer üyeleri bekliyoruz!");
ALIGNED(4) const u8 gText_UR_QuitBeingMember[] = _("Üye olmayı bırakmak mı istiyorsunuz?");
ALIGNED(4) static const u8 sText_StoppedBeingMember[] = _("Üye olmayı bıraktınız.\p");


const u8 *const gTexts_UR_PlayerDisconnected[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_MemberNoLongerAvailable,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_TrainerAppearsUnavailable,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = sText_StoppedBeingMember
};

ALIGNED(4) const u8 gText_UR_WirelessLinkEstablished[] = _("KABLOSUZ İLETİŞİM SİSTEMİ\nbağlantısı kurulmuştur.");
ALIGNED(4) const u8 gText_UR_WirelessLinkDropped[] = _("KABLOSUZ İLETİŞİM SİSTEMİ\nbağlantısı kesilmiştir…");
ALIGNED(4) const u8 gText_UR_LinkWithFriendDropped[] = _("Arkadaşınızla olan bağlantı\ntesil edilmiştir…");
ALIGNED(4) static const u8 sText_PlayerRepliedNo2[] = _("{STR_VAR_1} “Hayır…” yanıtını verdi.");

const u8 *const gTexts_UR_LinkDropped[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = gText_UR_LinkWithFriendDropped,
    [RFU_STATUS_CONNECTION_ERROR]    = gText_UR_LinkWithFriendDropped,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo2,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = NULL
};

ALIGNED(4) static const u8 sText_DoYouWantXMode[] = _("Bu {STR_VAR_2}\nMODU'nu ister misiniz?");
ALIGNED(4) static const u8 sText_DoYouWantXMode2[] = _("Bu {STR_VAR_2}\nMODU'nu ister misiniz?");

// Unused
static const u8 *const sDoYouWantModeTexts[] = {
    sText_DoYouWantXMode,
    sText_DoYouWantXMode2
};

ALIGNED(4) static const u8 sText_CommunicatingPleaseWait[] = _("はなしかけています…\nしょうしょう おまちください"); // Unused
ALIGNED(4) const u8 gText_UR_AwaitingPlayersResponseAboutTrade[] = _("Takas hakkında {STR_VAR_1}'in\ncevabını bekliyoruz…");

ALIGNED(4) static const u8 sText_Communicating[] = _("İletişim kuruluyor{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_CommunicatingWithPlayer[] = _("{STR_VAR_1} ile iletişim kuruluyor{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_PleaseWaitAWhile[] = _("Lütfen bir süre bekleyin{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");

const u8 *const gTexts_UR_CommunicatingWait[] = {
    sText_Communicating,
    sText_CommunicatingWithPlayer,
    sText_PleaseWaitAWhile
};

ALIGNED(4) static const u8 sText_HiDoSomethingMale[] = _("Merhaba! Yapmak istediğin bir şey\nmi var?");
ALIGNED(4) static const u8 sText_HiDoSomethingFemale[] = _("Merhaba!\nBir şeyler yapmak ister misin?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainMale[] = _("{STR_VAR_1}: Merhaba, tekrar karşılaştık!\nBu sefer ne yapmak istersin?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainFemale[] = _("{STR_VAR_1}: Oh! {PLAYER}, merhaba!\nBir şeyler yapmak ister misin?");


const u8 *const gTexts_UR_HiDoSomething[][GENDER_COUNT] = {
    {
        sText_HiDoSomethingMale,
        sText_HiDoSomethingFemale
    }, {
        sText_HiDoSomethingAgainMale,
        sText_HiDoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_DoSomethingMale[] = _("Bir şeyler yapmak ister misin?");
ALIGNED(4) static const u8 sText_DoSomethingFemale[] = _("Bir şeyler yapmak ister misin?");
ALIGNED(4) static const u8 sText_DoSomethingAgainMale[] = _("{STR_VAR_1}: Şimdi ne yapmak istersin?");
ALIGNED(4) static const u8 sText_DoSomethingAgainFemale[] = _("{STR_VAR_1}‘また なにかする？");

// Unused
static const u8 *const sDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_DoSomethingMale,
        sText_DoSomethingFemale
    }, {
        sText_DoSomethingAgainMale,
        sText_DoSomethingAgainMale // was probably supposed to be sText_DoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_SomebodyHasContactedYou[] = _("Birisi seninle iletişime geçti.{PAUSE 60}");
ALIGNED(4) static const u8 sText_PlayerHasContactedYou[] = _("{STR_VAR_1} seninle iletişime geçti.{PAUSE 60}");

const u8 *const gTexts_UR_PlayerContactedYou[] = {
    sText_SomebodyHasContactedYou,
    sText_PlayerHasContactedYou
};

ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer[] = _("Diğer EĞİTMENDEN yanıt\nbekleniyor…");
ALIGNED(4) static const u8 sText_AwaitingResponseFromPlayer[] = _("{STR_VAR_1}'den yanıt\nbekleniyor…");

const u8 *const gTexts_UR_AwaitingResponse[] = {
    sText_AwaitingResponseFromTrainer,
    sText_AwaitingResponseFromPlayer
};

ALIGNED(4) static const u8 sText_AwaitingResponseCancelBButton[] = _("あいての ていあんを まっています\nビーボタンで キャンセル");

ALIGNED(4) const u8 gText_UR_ShowTrainerCard[] = _("Diğer EĞİTMEN size EĞİTMEN\nKARTINI gösterdi.\pKendi EĞİTMEN KARTINIZI\ngöstermek ister misiniz?");
ALIGNED(4) const u8 gText_UR_BattleChallenge[] = _("Diğer EĞİTMEN size dövüş için\nmeydan okudu.\pDövüş meydan okumayı\nkabul edecek misiniz?");
ALIGNED(4) const u8 gText_UR_ChatInvitation[] = _("Diğer EĞİTMEN sizi sohbet etmeye\ndavet ediyor.\pSohbet davetini kabul edecek\nmisiniz?");
ALIGNED(4) const u8 gText_UR_OfferToTradeMon[] = _("Kaydedilmiş Lv. {DYNAMIC 0} {DYNAMIC 1}\nkarşılığında\pLv. {DYNAMIC 2} {DYNAMIC 3}\ntakas teklifi var.\pBu takas teklifini kabul edecek misiniz?");
ALIGNED(4) const u8 gText_UR_OfferToTradeEgg[] = _("Kaydedilmiş YUMURTA'nıza takas\nteklifi var.\lBu takas teklifini kabul edecek misiniz?");
ALIGNED(4) const u8 gText_UR_ChatDropped[] = _("Sohbet kesildi.\p");
ALIGNED(4) const u8 gText_UR_OfferDeclined1[] = _("Teklifi reddettiniz.\p");
ALIGNED(4) const u8 gText_UR_OfferDeclined2[] = _("Teklifi reddettiniz.\p");
ALIGNED(4) const u8 gText_UR_ChatEnded[] = _("Sohbet sona erdi.\p");

// Unused
static const u8 *const sInvitationTexts[] = {
    gText_UR_ShowTrainerCard,
    gText_UR_BattleChallenge,
    gText_UR_ChatInvitation,
    gText_UR_OfferToTradeMon
};

ALIGNED(4) static const u8 sText_JoinChatMale[] = _("Oh, merhaba! Şu anda bir sohbetteyiz.\nBize katılmak ister misin?");
ALIGNED(4) static const u8 sText_PlayerJoinChatMale[] = _("{STR_VAR_1}: Hey, {PLAYER}!\nŞu anda bir sohbetteyiz.\lBize katılmak ister misin?");
ALIGNED(4) static const u8 sText_JoinChatFemale[] = _("Oh, merhaba! Şu anda bir\nsohbetteyiz.\lBize katılmak ister misin?");
ALIGNED(4) static const u8 sText_PlayerJoinChatFemale[] = _("{STR_VAR_1}: Oh, merhaba, {PLAYER}!\nŞu anda bir sohbetteyiz.\lBize katılmak ister misin?");

const u8 *const gTexts_UR_JoinChat[][GENDER_COUNT] = {
    {
        sText_JoinChatMale,
        sText_JoinChatFemale
    }, {
        sText_PlayerJoinChatMale,
        sText_PlayerJoinChatFemale
    }
};

ALIGNED(4) const u8 gText_UR_TrainerAppearsBusy[] = _("……\nEĞİTMEN meşgul görünüyor…\p");
ALIGNED(4) static const u8 sText_WaitForBattleMale[] = _("Bir savaş mı?\nTamam, biraz zamana ihtiyacım var.");
ALIGNED(4) static const u8 sText_WaitForChatMale[] = _("Sohbet mi istiyorsun?\nTabii, biraz beklemen gerek.");
ALIGNED(4) static const u8 sText_ShowTrainerCardMale[] = _("Tabii ki! “Selamlaşma” olarak,\nbu benim EĞİTMEN KARTIM.");
ALIGNED(4) static const u8 sText_WaitForBattleFemale[] = _("Bir savaş mı? Elbette, ama\nhazırlanmak için zamana ihtiyacım\lvar.");
ALIGNED(4) static const u8 sText_WaitForChatFemale[] = _("Sohbet mi etmek istiyorsun?\nTamam, ama lütfen biraz bekle.");
ALIGNED(4) static const u8 sText_ShowTrainerCardFemale[] = _("Tanıtım olarak, sana\nEĞİTMEN KARTIMI göstereceğim.");

const u8 *const gTexts_UR_WaitOrShowCard[GENDER_COUNT][4] = {
    {
        sText_WaitForBattleMale,
        sText_WaitForChatMale,
        NULL,
        sText_ShowTrainerCardMale
    }, {
        sText_WaitForBattleFemale,
        sText_WaitForChatFemale,
        NULL,
        sText_ShowTrainerCardFemale
    }
};

ALIGNED(4) static const u8 sText_WaitForChatMale2[] = _("チャットだね！\nわかった ちょっと まってて！");
ALIGNED(4) static const u8 sText_DoneWaitingBattleMale[] = _("Beklediğin için teşekkürler!\nHadi savaşımıza başlayalım!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatMale[] = _("Tamam!\nSohbet edelim!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingBattleFemale[] = _("Beklettiğim için üzgünüm!\nHadi başlayalım!{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatFemale[] = _("Beklettiğim için üzgünüm!\nHadi sohbet edelim.{PAUSE 60}");
ALIGNED(4) static const u8 sText_TradeWillBeStarted[] = _("Takas başlayacak.{PAUSE 60}");
ALIGNED(4) static const u8 sText_BattleWillBeStarted[] = _("Savaş başlayacak.{PAUSE 60}");
ALIGNED(4) static const u8 sText_EnteringChat[] = _("Sohbete giriliyor…{PAUSE 60}");

const u8 *const gTexts_UR_StartActivity[][GENDER_COUNT][3] = {
    {
        {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }, {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }
    }, {
        {
            sText_DoneWaitingBattleMale,
            sText_DoneWaitingChatMale,
            sText_TradeWillBeStarted
        }, {
            sText_DoneWaitingBattleFemale,
            sText_DoneWaitingChatFemale,
            sText_TradeWillBeStarted
        }
    }
};

ALIGNED(4) static const u8 sText_BattleDeclinedMale[] = _("Üzgünüm! POKéMON'larım şu anda pek\niyi hissetmiyor.\lBaşka bir zaman savaşalım.\p");
ALIGNED(4) static const u8 sText_BattleDeclinedFemale[] = _("Çok üzgünüm, ama POKéMON'larım\niyi hissetmiyor…\lBaşka bir zaman savaşalım.\p");

const u8 *const gTexts_UR_BattleDeclined[GENDER_COUNT] = {
    sText_BattleDeclinedMale,
    sText_BattleDeclinedFemale
};

ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedMale[] = _("He? EĞİTMEN KARTIM…\nŞimdi nereye gitmiş olabilir?\lÜzgünüm! Başka bir zaman!\p");
ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedFemale[] = _("Oh? EĞİTMEN KARTIMI nereye\nkoymuştum?\l…Üzgünüm! Daha sonra!\p");

const u8 *const gTexts_UR_ShowTrainerCardDeclined[GENDER_COUNT] = {
    sText_ShowTrainerCardDeclinedMale,
    sText_ShowTrainerCardDeclinedFemale
};

ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingMale[] = _("Eğer benimle bir şeyler\nyapmak istersen,\lsadece seslen!\p");
ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingFemale[] = _("Eğer benimle bir şeyler\nyapmak istersen,\lutangaç olma.\p");

const u8 *const gTexts_UR_IfYouWantToDoSomething[GENDER_COUNT] = {
    sText_IfYouWantToDoSomethingMale,
    sText_IfYouWantToDoSomethingFemale
};

ALIGNED(4) const u8 gText_UR_TrainerBattleBusy[] = _("Ayy! Üzgünüm, ama başka bir şey\nyapmam gerekiyor.\lBaşka bir zaman, tamam mı?\p");
ALIGNED(4) const u8 gText_UR_NeedTwoMonsOfLevel30OrLower1[] = _("Bir dövüş yapmak istiyorsan,\nLv. 30'un altında iki\lPOKéMON'a ihtiyacın var.\p");
ALIGNED(4) const u8 gText_UR_NeedTwoMonsOfLevel30OrLower2[] = _("Bir dövüş için, Lv. 30'un altında\niki POKéMON'a ihtiyacın var.\p");

ALIGNED(4) static const u8 sText_DeclineChatMale[] = _("Tamam, anladım.\nHer zaman gel, tamam mı?\p");
ALIGNED(4) static const u8 stext_DeclineChatFemale[] = _("Ah…\nHer zaman uğrayabilirsin.\p");

// Response from partner when player declines chat
const u8 *const gTexts_UR_DeclineChat[GENDER_COUNT] = {
    sText_DeclineChatMale,
    stext_DeclineChatFemale
};

ALIGNED(4) static const u8 sText_ChatDeclinedMale[] = _("Oh, üzgünüm!\nŞu anda yapamam.\lBaşka bir zaman sohbet ederiz.\p");
ALIGNED(4) static const u8 sText_ChatDeclinedFemale[] = _("Ah, üzgünüm.\nŞu anda çok meşgulüm.\lBaşka bir zaman sohbet ederiz.\p");

// Response from partner when they decline chat
const u8 *const gTexts_UR_ChatDeclined[GENDER_COUNT] = {
    sText_ChatDeclinedMale,
    sText_ChatDeclinedFemale
};

ALIGNED(4) static const u8 sText_YoureToughMale[] = _("Vay!\nGerçekten zorlu olduğunu görebiliyorum!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveMale[] = _("O hamleyi mi kullandın?\nBu iyi bir strateji!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseMale[] = _("Harika iş!\nBu gerçekten göz açıcıydı!\p");
ALIGNED(4) static const u8 sText_SwitchedMonsMale[] = _("Oh! O POKéMON'u o durumda nasıl\nkullanabildin?\p");
ALIGNED(4) static const u8 sText_YoureToughFemale[] = _("Bu POKéMON…\nGerçekten iyi yetiştirilmiş!\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveFemale[] = _("İşte bu!\nBu hareket tam zamanı!\p");
ALIGNED(4) static const u8 sText_BattleSurpriseFemale[] = _("Bu harika!\nBu şekilde savaşabiliyor musun?\p");
ALIGNED(4) static const u8 sText_SwitchedMonsFemale[] = _("POKéMON değişiminde harika\nbir zamanlama yapıyorsun!\p");

const u8 *const gTexts_UR_BattleReaction[GENDER_COUNT][4] = {
    {
        sText_YoureToughMale,
        sText_UsedGoodMoveMale,
        sText_BattleSurpriseMale,
        sText_SwitchedMonsMale
    }, {
        sText_YoureToughFemale,
        sText_UsedGoodMoveFemale,
        sText_BattleSurpriseFemale,
        sText_SwitchedMonsFemale
    }
};

ALIGNED(4) static const u8 sText_LearnedSomethingMale[] = _("Oh, anlıyorum!\nBu eğitici oldu!\p");
ALIGNED(4) static const u8 sText_ThatsFunnyMale[] = _("Artık komik bir şey söyleme!\nGülmekten ağrılarım var!\p");
ALIGNED(4) static const u8 sText_RandomChatMale1[] = _("Oh?\nÖyle bir şey mi olmuş.\p");
ALIGNED(4) static const u8 sText_RandomChatMale2[] = _("Hmhm… Ne?\nYani demek istediğin bu mu?\p");
ALIGNED(4) static const u8 sText_LearnedSomethingFemale[] = _("Gerçekten mi?\nBunu bilmiyordum.\p");
ALIGNED(4) static const u8 sText_ThatsFunnyFemale[] = _("Ahaha!\nBu ne hakkında?\p");
ALIGNED(4) static const u8 sText_RandomChatFemale1[] = _("Evet, tam olarak bu!\nDemek istediğim buydu.\p");
ALIGNED(4) static const u8 sText_RandomChatFemale2[] = _("Başka bir deyişle…\nEvet! Bu doğru!\p");

const u8 *const gTexts_UR_ChatReaction[GENDER_COUNT][4] = {
    {
        sText_LearnedSomethingMale,
        sText_ThatsFunnyMale,
        sText_RandomChatMale1,
        sText_RandomChatMale2
    }, {
        sText_LearnedSomethingFemale,
        sText_ThatsFunnyFemale,
        sText_RandomChatFemale1,
        sText_RandomChatFemale2
    }
};

ALIGNED(4) static const u8 sText_ShowedTrainerCardMale1[] = _("Selamlaşma şeklim olarak\nEĞİTMENİ KARTIMI gösteriyorum.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardMale2[] = _("Seni daha iyi tanıyabilmeyi\numuyorum!\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale1[] = _("Tanışmak için birbirimize\nEĞİTMEN KARTLARIMIZI gösteriyoruz.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale2[] = _("Tanıştığımıza memnun oldum.\nLütfen yabancı kalma!\p");

const u8 *const gTexts_UR_TrainerCardReaction[GENDER_COUNT][2] = {
    {
        sText_ShowedTrainerCardMale1,
        sText_ShowedTrainerCardMale2
    }, {
        sText_ShowedTrainerCardFemale1,
        sText_ShowedTrainerCardFemale2
    }
};

ALIGNED(4) static const u8 sText_MaleTraded1[] = _("Evet! Bu POKéMON'u gerçekten\nistiyordum!\p");
ALIGNED(4) static const u8 sText_MaleTraded2[] = _("Sonunda, uzun zamandır istediğim\nPOKéMON'u takasla aldım.\p");
ALIGNED(4) static const u8 sText_FemaleTraded1[] = _("Şu anda POKéMON takas ediyorum.\p");
ALIGNED(4) static const u8 sText_FemaleTraded2[] = _("Sonunda, takasla istediğim\nPOKéMON'u aldım!\p");

const u8 *const gTexts_UR_TradeReaction[GENDER_COUNT][4] = {
    {
        sText_MaleTraded1,
        sText_MaleTraded2
    }, {
        sText_FemaleTraded1,
        sText_FemaleTraded2
    }
};

const u8 gText_UR_XCheckedTradingBoard[] = _("{STR_VAR_1} takas panosunu\nkontrol etti.\p");
ALIGNED(4) const u8 gText_UR_RegisterMonAtTradingBoard[] = _("Takas Panosu'na hoş geldiniz.\pPOKéMON'unuzu kaydedebilir ve\ntakas için teklif edebilirsiniz.\pBir POKéMON'unuzu kaydetmek ister misiniz?");
ALIGNED(4) const u8 gText_UR_TradingBoardInfo[] = _("Bu TAKAS PANOSU, bir POKéMON'u\n"
                                                    "takas için teklif etmenizi sağlar.\p"
                                                    "Tek yapmanız gereken, bir POKéMON'u\n"
                                                    "takas için kaydetmektir.\p"
                                                    "Başka bir EĞİTMEN, takas karşılığında\n"
                                                    "bir parti POKéMON'u teklif edebilir.\p"
                                                    "POKéMON'larınızı kaydetmenizi ve\n"
                                                    "birçok başka EĞİTMEN ile takas\lyapmanızı umuyoruz.\l"
                                                    "Bir POKéMON'unuzu kaydetmek ister misiniz?");
ALIGNED(4) static const u8 sText_ThankYouForRegistering[] = _("Kayıt işlemi tamamlandı.\nKullanımınız için teşekkür ederiz!\p");
ALIGNED(4) static const u8 sText_NobodyHasRegistered[] = _("Panoya kimse POKéMON\nkayıt etmedi.\p");
ALIGNED(4) const u8 gText_UR_ChooseRequestedMonType[] = _("Takas için hangi tür POKéMON\nistediğinizi seçin.\n");
ALIGNED(4) const u8 gText_UR_WhichMonWillYouOffer[] = _("Hangi takım POKéMON'unuzu\ntakas için vereceksiniz?\p");
ALIGNED(4) const u8 gText_UR_RegistrationCanceled[] = _("Kayıt iptal edildi.\p");
ALIGNED(4) const u8 gText_UR_RegistraionCompleted[] = _("Kayıt tamamlandı.\p");
ALIGNED(4) const u8 gText_UR_TradeCanceled[] = _("Takas iptal edildi.\p");
ALIGNED(4) const u8 gText_UR_CancelRegistrationOfMon[] = _("Lv. {STR_VAR_2} {STR_VAR_1} POKéMON'unuzun\nkayıt işlemini iptal etmek ister misiniz?");
ALIGNED(4) const u8 gText_UR_CancelRegistrationOfEgg[] = _("YUMURTA'nızın kayıt işlemini\niptal etmek ister misiniz?");
ALIGNED(4) const u8 gText_UR_RegistrationCanceled2[] = _("Kayıt iptal edildi.\p");
ALIGNED(4) static const u8 sText_TradeTrainersWillBeListed[] = _("Takas isteyen kişilerin listesi\ngösterilecektir.");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith2[] = _("Takas yapmak istediğiniz\nEĞİTMENİ seçin.");
ALIGNED(4) const u8 gText_UR_AskTrainerToMakeTrade[] = _("{STR_VAR_1} ile takas yapmak ister\nmisiniz?");
ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer2[] = _("……\nRakibin yanıtını bekliyorum.");
ALIGNED(4) static const u8 sText_NotRegisteredAMonForTrade[] = _("Takas için POKéMON'unuz\nkayıtlı değil.\p");
ALIGNED(4) const u8 gText_UR_DontHaveTypeTrainerWants[] = _("{STR_VAR_1}'ın istediği {STR_VAR_2}-tipi\nPOKéMON'unuz yok.\p");
ALIGNED(4) const u8 gText_UR_DontHaveEggTrainerWants[] = _("{STR_VAR_1}'ın istediği\nYUMURTA'nız yok.\p");

ALIGNED(4) static const u8 sText_PlayerCantTradeForYourMon[] = _("{STR_VAR_1} şu anda POKéMON'unuz\nile takas yapamaz.\p");
ALIGNED(4) static const u8 sText_CantTradeForPartnersMon[] = _("Şu anda {STR_VAR_1}'ın POKéMON'u\nile takas yapamazsınız.\p");

// Unused
static const u8 *const sCantTradeMonTexts[] = {
    sText_PlayerCantTradeForYourMon,
    sText_CantTradeForPartnersMon
};

ALIGNED(4) const u8 gText_UR_TradeOfferRejected[] = _("Takas teklifiniz reddedildi.\p");
ALIGNED(4) const u8 gText_UR_EggTrade[] = _("YUMURTA TAKASI");
ALIGNED(4) const u8 gText_UR_ChooseJoinCancel[] = _("{DPAD_UPDOWN}SEÇ  {A_BUTTON}KATIL  {B_BUTTON}İPTAL");
ALIGNED(4) const u8 gText_UR_ChooseTrainer[] = _("Lütfen bir EĞİTMEN seçin.");
ALIGNED(4) static const u8 sText_ChooseTrainerSingleBattle[] = _("Tekli savaş için bir EĞİTMEN\nseçin.");
ALIGNED(4) static const u8 sText_ChooseTrainerDoubleBattle[] = _("Çiftli savaş için bir EĞİTMEN\nseçin.");
ALIGNED(4) static const u8 sText_ChooseLeaderMultiBattle[] = _("Çoklu savaş için LİDER\nseçin.");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith[] = _("Takas yapmak için bir EĞİTMEN\nseçin.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderCards[] = _("HARİKA KARTLAR paylaşan EĞİTMENİ\nseçin.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderNews[] = _("HARİKA HABERLER paylaşan EĞİTMENİ\nseçin.");
ALIGNED(4) static const u8 sText_ChooseLeaderPokemonJump[] = _("Mini POKéMON ile zıpla!\nLütfen LİDERİ seçin.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryCrush[] = _("MEYVE EZME!\nLütfen LİDERİ seçin.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryPicking[] = _("DODRIO MEYVE TOPLAMA!\nLütfen LİDERİ seçin.");

const u8 *const gTexts_UR_ChooseTrainer[] = {
    [LINK_GROUP_SINGLE_BATTLE] = sText_ChooseTrainerSingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE] = sText_ChooseTrainerDoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]  = sText_ChooseLeaderMultiBattle,
    [LINK_GROUP_TRADE]         = sText_ChooseTrainerToTradeWith,
    [LINK_GROUP_POKEMON_JUMP]  = sText_ChooseLeaderPokemonJump,
    [LINK_GROUP_BERRY_CRUSH]   = sText_ChooseLeaderBerryCrush,
    [LINK_GROUP_BERRY_PICKING] = sText_ChooseLeaderBerryPicking,
    [LINK_GROUP_WONDER_CARD]   = sText_ChooseTrainerToShareWonderCards,
    [LINK_GROUP_WONDER_NEWS]   = sText_ChooseTrainerToShareWonderNews
};

ALIGNED(4) const u8 gText_UR_SearchingForWirelessSystemWait[] = _("KABLOSUZ İLETİŞİM SİSTEMİ aranıyor.\nLütfen bekleyin...");
ALIGNED(4) static const u8 sText_MustHaveTwoMonsForDoubleBattle[] = _("Çift savaş için 2 veya daha fazla\nPOKéMON'a ihtiyacınız var.\p");
ALIGNED(4) const u8 gText_UR_AwaitingPlayersResponse[] = _("{STR_VAR_1}'in yanıtı bekleniyor…");
ALIGNED(4) const u8 gText_UR_PlayerHasBeenAskedToRegisterYouPleaseWait[] = _("{STR_VAR_1}'e sizi üye olarak\nkaydetmesi istendi. Lütfen bekleyin.");
ALIGNED(4) const u8 gText_UR_AwaitingResponseFromWirelessSystem[] = _("KABLOSUZ İLETİŞİM SİSTEMİ'nden\nbir yanıt bekleniyor.");
ALIGNED(4) static const u8 sText_PleaseWaitForOtherTrainersToGather[] = _("Diğer katılımcıların toplanmasını\nbekleyin.");

ALIGNED(4) static const u8 sText_NoCardsSharedRightNow[] = _("Şu anda paylaşılmış KART yok.");
ALIGNED(4) static const u8 sText_NoNewsSharedRightNow[] = _("Şu anda paylaşılmış HABER yok.");

const u8 *const gTexts_UR_NoWonderShared[] = {
    sText_NoCardsSharedRightNow,
    sText_NoNewsSharedRightNow
};

ALIGNED(4) const u8 gText_UR_Battle[] = _("SAVAŞ");
ALIGNED(4) const u8 gText_UR_Chat2[] = _("SOHBET");
ALIGNED(4) const u8 gText_UR_Greetings[] = _("SELAMLAŞMA");
ALIGNED(4) const u8 gText_UR_Exit[] = _("ÇIKIŞ");

ALIGNED(4) const u8 gText_UR_Exit2[] = _("ÇIKIŞ");
ALIGNED(4) const u8 gText_UR_Info[] = _("BİLGİ");
ALIGNED(4) const u8 gText_UR_NameWantedOfferLv[] = _("İSİM{CLEAR_TO 0x3C}ARANAN{CLEAR_TO 0x6E}TEKLİF{CLEAR_TO 0xC6}SV.");

ALIGNED(4) const u8 gText_UR_SingleBattle[] = _("TEKLI SAVAŞ");
ALIGNED(4) const u8 gText_UR_DoubleBattle[] = _("ÇİFT SAVAŞ");
ALIGNED(4) const u8 gText_UR_MultiBattle[] = _("ÇOKLU SAVAŞ");
ALIGNED(4) const u8 gText_UR_PokemonTrades[] = _("POKéMON TAKASLARI");
ALIGNED(4) const u8 gText_UR_Chat[] = _("SOHBET");
ALIGNED(4) const u8 gText_UR_Cards[] = _("KARTLAR");
ALIGNED(4) const u8 gText_UR_WonderCards[] = _("HARİKA KARTLAR");
ALIGNED(4) const u8 gText_UR_WonderNews[] = _("HARİKA HABERLER");
ALIGNED(4) const u8 gText_UR_PokemonJump[] = _("POKéMON ZIPLAMASI");
ALIGNED(4) const u8 gText_UR_BerryCrush[] = _("MEYVE EZME");
ALIGNED(4) const u8 gText_UR_BerryPicking[] = _("MEYVE TOPLAMA");
ALIGNED(4) const u8 gText_UR_Search[] = _("ARA");
ALIGNED(4) const u8 gText_UR_SpinTrade[] = _("DÖNÜŞ TAKASI");
ALIGNED(4) const u8 gText_UR_ItemTrade[] = _("EŞYA TAKASI");

ALIGNED(4) static const u8 sText_ItsNormalCard[] = _("Bu NORMAL bir KART.");
ALIGNED(4) static const u8 sText_ItsBronzeCard[] = _("Bu bir BRONZ KART!");
ALIGNED(4) static const u8 sText_ItsCopperCard[] = _("Bu bir BAKIR KART!");
ALIGNED(4) static const u8 sText_ItsSilverCard[] = _("Bu bir GÜMÜŞ KART!");
ALIGNED(4) static const u8 sText_ItsGoldCard[] = _("Bu bir ALTIN KART!");

const u8 *const gTexts_UR_CardColor[] = {
    sText_ItsNormalCard,
    sText_ItsBronzeCard,
    sText_ItsCopperCard,
    sText_ItsSilverCard,
    sText_ItsGoldCard
};

ALIGNED(4) const u8 gText_UR_TrainerCardInfoPage1[] = _("{DYNAMIC 0} {DYNAMIC 1}'ın\nEĞİTMEN KARTI...\l{DYNAMIC 2}\pPOKéDEX: {DYNAMIC 3}\nZAMAN:    {DYNAMIC 4}:{DYNAMIC 5}\p");
ALIGNED(4) const u8 gText_UR_TrainerCardInfoPage2[] = _("SAVAŞLAR: {DYNAMIC 0} GALİBİYET  {DYNAMIC 2} YENİLGİ\nTAKASLAR:  {DYNAMIC 3} KEZ\p“{DYNAMIC 4} {DYNAMIC 5}\n{DYNAMIC 6} {DYNAMIC 7}”\p");
ALIGNED(4) static const u8 sText_GladToMeetYouMale[] = _("{DYNAMIC 1}: Tanıştığımıza memnun oldum!{PAUSE 60}");
ALIGNED(4) static const u8 sText_GladToMeetYouFemale[] = _("{DYNAMIC 1}: Tanıştığımıza memnun oldum!{PAUSE 60}");

const u8 *const gTexts_UR_GladToMeetYou[GENDER_COUNT] = {
    sText_GladToMeetYouMale,
    sText_GladToMeetYouFemale
};

ALIGNED(4) const u8 gText_UR_FinishedCheckingPlayersTrainerCard[] = _("{DYNAMIC 1}'ın\nEĞİTMEN KARTINI kontrol etmeyi bitirdin.{PAUSE 60}");
ALIGNED(4) static const u8 sText_CanceledReadingCard[] = _("Kartı okumayı iptal ettin.");

static const struct MysteryGiftClientCmd sClientScript_DynamicError[] = {
    {CLI_RECV, MG_LINKID_DYNAMIC_MSG},
    {CLI_COPY_MSG},
    {CLI_SEND_READY_END},
    {CLI_RETURN, CLI_MSG_BUFFER_FAILURE}
};

const struct MysteryGiftServerCmd gServerScript_ClientCanceledCard[] = {
    {SVR_LOAD_CLIENT_SCRIPT, PTR_ARG(sClientScript_DynamicError)},
    {SVR_SEND},
    {SVR_LOAD_MSG, PTR_ARG(sText_CanceledReadingCard)},
    {SVR_SEND},
    {SVR_RECV, MG_LINKID_READY_END},
    {SVR_RETURN, SVR_MSG_CLIENT_CANCELED}
};
