SevenIsland_TanobyRuins_ViapoisChamber_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SevenIsland_TanobyRuins_ViapoisChamber_OnTransition
	.byte 0

SevenIsland_TanobyRuins_ViapoisChamber_OnTransition::
	call EventScript_TryDarkenRuins
	end

ViapoisChamber_Text_MysticTicket:
	.string "Bu bir gemi bileti.\pBırakılalı uzun zaman olmuş gibi\nduruyor.$"

ViapoisChamber_OutsideEast_EventScript_ItemMysticTicket::
	finditem ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	msgbox ViapoisChamber_Text_MysticTicket, MSGBOX_DEFAULT
	closemessage
	end
