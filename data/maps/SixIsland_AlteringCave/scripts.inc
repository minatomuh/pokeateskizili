SixIsland_AlteringCave_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SixIsland_AlteringCave_OnTransition
	.byte 0

SixIsland_AlteringCave_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_SIX_ISLAND_ALTERING_CAVE
	end

SixIsland_Text_AuroraTicket:
	.string "Bu bir gemi bileti.\pBırakılalı uzun zaman olmuş gibi\nduruyor.$"

SixIsland_OutsideEast_EventScript_ItemAuroraTicket::
	finditem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	msgbox SixIsland_Text_AuroraTicket, MSGBOX_DEFAULT
	closemessage
	end