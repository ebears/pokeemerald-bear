.set LOCALID_BIRCH, 2
.set LOCALID_ZIGZAGOON, 4

Route101_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route101_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
	.byte 0

Route101_OnTransition:
	special GetEncounterTime
	goto_if_eq VAR_RESULT, 3, Route101_OnTransition_Night
	goto_if_eq VAR_RESULT, 2, Route101_OnTransition_Evening
	goto_if_eq VAR_RESULT, 1, Route101_OnTransition_Day
	goto_if_eq VAR_RESULT, 0, Route101_OnTransition_Morning
	end

Route101_OnTransition_Morning:
	setvar VAR_DAYNIGHT, 0
	call ProfBirch_EventScript_UpdateLocation
	end

Route101_OnTransition_Day:
	setvar VAR_DAYNIGHT, 1
	call ProfBirch_EventScript_UpdateLocation
	end

Route101_OnTransition_Evening:
	setvar VAR_DAYNIGHT, 2
	call ProfBirch_EventScript_UpdateLocation
	end

Route101_OnTransition_Night:
	setvar VAR_DAYNIGHT, 3
	call ProfBirch_EventScript_UpdateLocation
	end

Route101_OnResume:
	special GetEncounterTime
	goto_if_eq VAR_RESULT, 3, Route101_OnResume_Night
	goto_if_eq VAR_RESULT, 2, Route101_OnResume_Evening
	goto_if_eq VAR_RESULT, 1, Route101_OnResume_Day
	goto_if_eq VAR_RESULT, 0, Route101_OnResume_Morning
	end

Route101_OnResume_Night:
	setvar VAR_DAYNIGHT, 3
	end
	
Route101_OnResume_Evening:
	setvar VAR_DAYNIGHT, 2
	end

Route101_OnResume_Day:
	setvar VAR_DAYNIGHT, 1
	end
	
Route101_OnResume_Morning:
	setvar VAR_DAYNIGHT, 0
	end

Route101_OnFrame:
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
	.2byte 0

Route101_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_ROUTE101_STATE, 1
	end

Route101_EventScript_StartBirchRescue::
	lockall
	playbgm MUS_HELP, TRUE
	msgbox Route101_Text_HelpMe, MSGBOX_DEFAULT
	closemessage
	setobjectxy LOCALID_BIRCH, 10, 15
	setobjectxy LOCALID_ZIGZAGOON, 10, 16
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_EnterScene
	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunAway1
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChase1
	waitmovement 0
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonChaseInCircles
	applymovement LOCALID_BIRCH, Route101_Movement_BirchRunInCircles
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_ZIGZAGOON, Route101_Movement_ZigzagoonFaceBirch
	applymovement LOCALID_BIRCH, Route101_Movement_BirchFaceZigzagoon
	waitmovement 0
	msgbox Route101_Text_PleaseHelp, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ROUTE101_STATE, 2
	releaseall
	end

Route101_EventScript_PreventExitSouth::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitSouth
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitWest::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitWest
	waitmovement 0
	releaseall
	end

Route101_EventScript_PreventExitNorth::
	lockall
	msgbox Route101_Text_DontLeaveMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PreventExitNorth
	waitmovement 0
	releaseall
	end

Route101_Movement_PreventExitSouth:
	walk_up
	step_end

Route101_Movement_PreventExitWest:
	walk_right
	step_end

Route101_Movement_PreventExitNorth:
	walk_down
	step_end

Route101_Movement_ZigzagoonChaseInCircles:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_ZigzagoonChase1:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_ZigzagoonFaceBirch:
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

Route101_Movement_EnterScene:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_in_place_faster_left
	step_end

Route101_Movement_BirchRunInCircles:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route101_Movement_BirchRunAway1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	step_end

@ Leftover data? This command is unused.
	step_end

Route101_Movement_BirchFaceZigzagoon:
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_in_place_fast_right
	step_end

Route101_Movement_Unused1:
	walk_up
	walk_up
	step_end

Route101_Movement_Unused2:
	walk_up
	walk_left
	walk_up
	step_end

Route101_EventScript_Youngster::
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
	end

Route101_EventScript_Boy::
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
	end

Route101_EventScript_RouteSign::
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end

Route101_EventScript_BirchsBag::
	lock
	faceplayer
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ZIGZAGOON
	setobjectxy OBJ_EVENT_ID_PLAYER, 16, 13
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	special ChooseStarter
	waitstate
	applymovement LOCALID_BIRCH, Route101_Movement_BirchApproachPlayer
	waitmovement 0
	msgbox Route101_Text_YouSavedMe, MSGBOX_DEFAULT
	special HealPlayerParty
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route101_EventScript_HideMayInBedroom
	call_if_eq VAR_RESULT, FEMALE, Route101_EventScript_HideBrendanInBedroom
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 6, 5
	waitstate
	release
	end

Route101_EventScript_HideMayInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	return

Route101_EventScript_HideBrendanInBedroom::
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	return

Route101_Movement_BirchApproachPlayer:
	walk_right
	step_end

Route101_Text_HelpMe:
	.string "{COLOR BLUE}H-help me!$"

Route101_Text_PleaseHelp:
	.string "{COLOR BLUE}Hello! You over there!\n"
	.string "Please! Help!\p"
	.string "In my {COLOR RED}Bag{COLOR BLUE}!\n"
	.string "There's a {COLOR RED}Poké Ball{COLOR BLUE}!$"

Route101_Text_DontLeaveMe:
	.string "{COLOR BLUE}Wh-Where are you going?!\n"
	.string "Don't leave me like this!$"

Route101_Text_YouSavedMe:
	.string "{COLOR BLUE}Prof. Birch: Whew…\p"
	.string "I was in the tall grass studying wild\n"
	.string "{COLOR RED}Pokémon {COLOR BLUE}when I was jumped.\p"
	.string "You saved me.\n"
	.string "Thanks a lot!\p"
	.string "Oh?\p"
	.string "Hi, you're {COLOR LIGHT_GREEN}{PLAYER}{KUN}{COLOR BLUE}!\p"
	.string "This is not the place to chat, so come\n"
	.string "by my {COLOR RED}Pokémon Lab {COLOR BLUE}later, okay?$"

Route101_Text_TakeTiredPokemonToPokeCenter:
	.string "{COLOR BLUE}If {COLOR RED}Pokémon {COLOR BLUE}get tired, take them to\n"
	.string "a {COLOR RED}Pokémon Center{COLOR BLUE}.\p"
	.string "There's a {COLOR RED}Pokémon Center {COLOR BLUE}in {COLOR RED}Oldale\n"
	.string "Town {COLOR BLUE}right close by.$"

Route101_Text_WildPokemonInTallGrass:
	.string "{COLOR BLUE}Wild {COLOR RED}Pokémon {COLOR BLUE}will jump out at you in\n"
	.string "tall grass.\p"
	.string "If you want to catch {COLOR RED}Pokémon{COLOR BLUE}, you have\n"
	.string "to go into the tall grass and search.$"

Route101_Text_RouteSign:
	.string "{COLOR RED}Route 101\n"
	.string "{COLOR GREEN}{UP_ARROW} {COLOR RED}Oldale Town$"
