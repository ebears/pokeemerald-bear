OldaleTown_Mart_MapScripts::
	.byte 0

OldaleTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_ExpandedItems
	pokemart OldaleTown_Mart_Pokemart_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Basic:
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE
	release
	end

OldaleTown_Mart_ExpandedItems::
	pokemart OldaleTown_Mart_Pokemart_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OldaleTown_Mart_Pokemart_Expanded:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE
	release
	end

OldaleTown_Mart_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_PokeBallsInStock
	msgbox OldaleTown_Mart_Text_PokeBallsAreSoldOut, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_PokeBallsInStock::
	msgbox OldaleTown_Mart_Text_ImGoingToBuyPokeBalls, MSGBOX_DEFAULT
	release
	end

OldaleTown_Mart_EventScript_Boy::
	msgbox OldaleTown_Mart_Text_RestoreHPWithPotion, MSGBOX_NPC
	end

OldaleTown_Mart_Text_PokeBallsAreSoldOut:
	.string "{COLOR BLUE}The clerk says they're all sold out.\n"
	.string "I can't buy any {COLOR RED}Poké Balls{COLOR BLUE}.$"

OldaleTown_Mart_Text_ImGoingToBuyPokeBalls:
	.string "{COLOR BLUE}I'm going to buy a bunch of {COLOR RED}Poké Balls\n"
	.string "{COLOR BLUE}and catch a bunch of {COLOR RED}Pokémon{COLOR BLUE}!$"

OldaleTown_Mart_Text_RestoreHPWithPotion:
	.string "{COLOR BLUE}If a {COLOR RED}Pokémon {COLOR BLUE}gets hurt and loses its {COLOR RED}HP{COLOR BLUE}\n"
	.string "and faints, it won't be able to battle.\p"
	.string "To prevent your {COLOR RED}Pokémon {COLOR BLUE}from fainting,\n"
	.string "restore its {COLOR RED}HP {COLOR BLUE}with a {COLOR RED}Potion{COLOR BLUE}.$"

