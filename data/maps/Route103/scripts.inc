.set LOCALID_RIVAL, 2

Route103_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route103_OnResume
	map_script MAP_SCRIPT_ON_LOAD, Route103_OnLoad
	.byte 0

Route103_OnTransition:
	special GetEncounterTime
	goto_if_eq VAR_RESULT, 3, Route103_OnTransition_Night
	goto_if_eq VAR_RESULT, 2, Route103_OnTransition_Evening
	goto_if_eq VAR_RESULT, 1, Route103_OnTransition_Day
	goto_if_eq VAR_RESULT, 0, Route103_OnTransition_Morning
	call Common_EventScript_SetupRivalGfxId
	call ProfBirch_EventScript_UpdateLocation
	end

Route103_OnTransition_Morning:
	setvar VAR_DAYNIGHT, 0
	end

Route103_OnTransition_Day:
	setvar VAR_DAYNIGHT, 1
	end

Route103_OnTransition_Evening:
	setvar VAR_DAYNIGHT, 2
	end

Route103_OnTransition_Night:
	setvar VAR_DAYNIGHT, 3
	end

Route103_OnResume:
	special GetEncounterTime
	goto_if_eq VAR_RESULT, 3, Route103_OnResume_Night
	goto_if_eq VAR_RESULT, 2, Route103_OnResume_Evening
	goto_if_eq VAR_RESULT, 1, Route103_OnResume_Day
	goto_if_eq VAR_RESULT, 0, Route103_OnResume_Morning
	end

Route103_OnResume_Night:
	setvar VAR_DAYNIGHT, 3
	end
	
Route103_OnResume_Evening:
	setvar VAR_DAYNIGHT, 2
	end

Route103_OnResume_Day:
	setvar VAR_DAYNIGHT, 1
	end
	
Route103_OnResume_Morning:
	setvar VAR_DAYNIGHT, 0
	end

Route103_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_OpenAlteringCave
	end

Route103_EventScript_OpenAlteringCave::
	setmetatile 45, 5, METATILE_General_CaveEntrance_Top, TRUE
	setmetatile 45, 6, METATILE_General_CaveEntrance_Bottom, FALSE
	return

Route103_EventScript_Rival::
	lockall
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route103_EventScript_RivalMay
	goto_if_eq VAR_RESULT, FEMALE, Route103_EventScript_RivalBrendan
	end

Route103_EventScript_RivalMay::
	msgbox Route103_Text_MayRoute103Pokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_MAY, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartMayBattleBulbasaur
	case 1, Route103_EventScript_StartMayBattleCharmander
	case 2, Route103_EventScript_StartMayBattleSquirtle
	case 3, Route103_EventScript_StartMayBattleChikorita
	case 4, Route103_EventScript_StartMayBattleCyndaquil
	case 5, Route103_EventScript_StartMayBattleTotodile
	case 6, Route103_EventScript_StartMayBattleTreecko
	case 7, Route103_EventScript_StartMayBattleTorchic
	case 8, Route103_EventScript_StartMayBattleMudkip
	case 9, Route103_EventScript_StartMayBattleTurtwig
	case 10, Route103_EventScript_StartMayBattleChimchar
	case 11, Route103_EventScript_StartMayBattlePiplup
	end

Route103_EventScript_RivalBrendan::
	msgbox Route103_Text_BrendanRoute103Pokemon, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement LOCALID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_StartBrendanBattleBulbasaur
	case 1, Route103_EventScript_StartBrendanBattleCharmander
	case 2, Route103_EventScript_StartBrendanBattleSquirtle
	case 3, Route103_EventScript_StartBrendanBattleChikorita
	case 4, Route103_EventScript_StartBrendanBattleCyndaquil
	case 5, Route103_EventScript_StartBrendanBattleTotodile
	case 6, Route103_EventScript_StartBrendanBattleTreecko
	case 7, Route103_EventScript_StartBrendanBattleTorchic
	case 8, Route103_EventScript_StartBrendanBattleMudkip
	case 9, Route103_EventScript_StartBrendanBattleTurtwig
	case 10, Route103_EventScript_StartBrendanBattleChimchar
	case 11, Route103_EventScript_StartBrendanBattlePiplup
	end

Route103_EventScript_StartMayBattleBulbasaur::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_BULBASAUR, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleCharmander::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_CHARMANDER, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleSquirtle::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_SQUIRTLE, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleChikorita::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_CHIKORITA, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleCyndaquil::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_CYNDAQUIL, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleTotodile::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TOTODILE, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TREECKO, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TORCHIC, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_MUDKIP, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleTurtwig::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_TURTWIG, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattleChimchar::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_CHIMCHAR, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartMayBattlePiplup::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_103_PIPLUP, Route103_Text_MayDefeated
	goto Route103_EventScript_AfterMayBattle
	end

Route103_EventScript_StartBrendanBattleBulbasaur::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_BULBASAUR, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleCharmander::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_CHARMANDER, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleSquirtle::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_SQUIRTLE, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleChikorita::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_CHIKORITA, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleCyndaquil::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_CYNDAQUIL, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleTotodile::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TOTODILE, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TREECKO, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TORCHIC, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleTurtwig::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_TURTWIG, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattleChimchar::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_CHIMCHAR, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_StartBrendanBattlePiplup::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_PIPLUP, Route103_Text_BrendanDefeated
	goto Route103_EventScript_AfterBrendanBattle
	end

Route103_EventScript_AfterMayBattle::
	msgbox Route103_Text_MayTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_AfterBrendanBattle::
	msgbox Route103_Text_BrendanTimeToHeadBack, MSGBOX_DEFAULT
	goto Route103_EventScript_RivalExit
	end

Route103_EventScript_RivalExit::
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, Route103_EventScript_RivalExitFacingSouth
	case DIR_NORTH, Route103_EventScript_RivalExitFacingNorth
	case DIR_WEST, Route103_EventScript_RivalExitFacingEastOrWest
	case DIR_EAST, Route103_EventScript_RivalExitFacingEastOrWest
	end

Route103_EventScript_RivalExitFacingNorth::
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingNorth
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExitFacingNorth1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_RIVAL, Route103_EventScript_RivalExitFacingNorth2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingEastOrWest::
	applymovement OBJ_EVENT_ID_PLAYER, Route103_Movement_WatchRivalExitFacingEastOrWest
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalExitFacingSouth::
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit1
	waitmovement 0
	playse SE_LEDGE
	applymovement LOCALID_RIVAL, Route103_Movement_RivalExit2
	waitmovement 0
	goto Route103_EventScript_RivalEnd
	end

Route103_EventScript_RivalEnd::
	removeobject LOCALID_RIVAL
	setvar VAR_BIRCH_LAB_STATE, 4
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	setvar VAR_OLDALE_RIVAL_STATE, 1
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	questmenu QUEST_MENU_SET_REWARD QUEST_RIVAL_BATTLE
	releaseall
	returnqueststate QUEST_RIVAL_BATTLE
	openquestmenu
	end

Route103_Movement_RivalExitFacingNorth1:
	walk_left
	walk_down
	step_end

Route103_EventScript_RivalExitFacingNorth2:
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingNorth:
	delay_16
	delay_4
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

Route103_Movement_RivalExit1:
	walk_down
	step_end

Route103_Movement_RivalExit2:
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

Route103_Movement_WatchRivalExitFacingEastOrWest:
	delay_16
	walk_in_place_faster_down
	step_end

Route103_EventScript_Boy::
	msgbox Route103_Text_ShouldHaveBroughtPotion, MSGBOX_NPC
	end

Route103_EventScript_Man::
	msgbox Route103_Text_ShortcutToOldale, MSGBOX_NPC
	end

Route103_EventScript_RouteSign::
	msgbox Route103_Text_RouteSign, MSGBOX_SIGN
	end

Route103_EventScript_Daisy::
	trainerbattle_single TRAINER_DAISY, Route103_Text_DaisyIntro, Route103_Text_DaisyDefeated
	msgbox Route103_Text_DaisyPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Amy::
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyIntro, Route103_Text_AmyDefeated, Route103_Text_AmyNotEnoughPokemon, Route102_EventScript_AmyRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_AmyRematch
	msgbox Route103_Text_AmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_AmyRegisterMatchCallAfterBattle::
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_AmyRematch::
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_AmyRematchIntro, Route103_Text_AmyRematchDefeated, Route103_Text_AmyRematchNotEnoughPokemon
	msgbox Route103_Text_AmyRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Liv::
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivIntro, Route103_Text_LivDefeated, Route103_Text_LivNotEnoughPokemon, Route102_EventScript_LivRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_LivRematch
	msgbox Route103_Text_LivPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_LivRegisterMatchCallAfterBattle::
	msgbox Route103_Text_AmyLivRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end

Route102_EventScript_LivRematch::
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_LivRematchIntro, Route103_Text_LivRematchDefeated, Route103_Text_LivRematchNotEnoughPokemon
	msgbox Route103_Text_LivRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Andrew::
	trainerbattle_single TRAINER_ANDREW, Route103_Text_AndrewIntro, Route103_Text_AndrewDefeated
	msgbox Route103_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Miguel::
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_MiguelIntro, Route103_Text_MiguelDefeated, Route102_EventScript_MiguelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route103_EventScript_MiguelRematch
	msgbox Route103_Text_MiguelPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_MiguelRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route103_Text_MiguelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_MIGUEL_1
	release
	end

Route103_EventScript_MiguelRematch::
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_MiguelRematchIntro, Route103_Text_MiguelRematchDefeated
	msgbox Route103_Text_MiguelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Marcos::
	trainerbattle_single TRAINER_MARCOS, Route103_Text_MarcosIntro, Route103_Text_MarcosDefeated
	msgbox Route103_Text_MarcosPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Rhett::
	trainerbattle_single TRAINER_RHETT, Route103_Text_RhettIntro, Route103_Text_RhettDefeated
	msgbox Route103_Text_RhettPostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Pete::
	trainerbattle_single TRAINER_PETE, Route103_Text_PeteIntro, Route103_Text_PeteDefeated
	msgbox Route103_Text_PetePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_EventScript_Isabelle::
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_IsabelleIntro, Route103_Text_IsabelleDefeated
	msgbox Route103_Text_IsabellePostBattle, MSGBOX_AUTOCLOSE
	end

Route103_Text_MayRoute103Pokemon:
	.string "{COLOR BLUE}Let's see… The {COLOR RED}Pokémon {COLOR BLUE}found\n"
	.string "on {COLOR RED}Route 103 {COLOR BLUE}include…$"

Route103_Text_MayLetsBattle:
	.string "{COLOR BLUE}Oh, hi, {COLOR LIGHT_GREEN}{PLAYER}{KUN}{COLOR BLUE}!\p"
	.string "…Oh, I see, my dad gave you\n"
	.string "a {COLOR RED}Pokémon {COLOR BLUE}as a gift.\p"
	.string "Since we're here, let's have a quick\n"
	.string "battle!\p"
	.string "I'll give you a taste of what being\n"
	.string "a trainer is like.$"

Route103_Text_MayDefeated:
	.string "{COLOR BLUE}Wow! That's great!\n"
	.string "{COLOR LIGHT_GREEN}{PLAYER}{KUN}{COLOR BLUE}, you're pretty good!$"

Route103_Text_MayTimeToHeadBack:
	.string "{COLOR BLUE}I think I know why my dad has\n"
	.string "an eye out for you now.\p"
	.string "I mean, you just got that {COLOR RED}Pokémon{COLOR BLUE},\n"
	.string "but it already likes you.\p"
	.string "You might be able to befriend any\n"
	.string "kind of {COLOR RED}Pokémon {COLOR BLUE}easily.\p"
	.string "Well, it's time to head back to\n"
	.string "the {COLOR RED}Lab{COLOR BLUE}.$"

Route103_Text_BrendanRoute103Pokemon:
	.string "{COLOR BLUE}Okay, so it's this one and\n"
	.string "that one that live on {COLOR RED}Route 103{COLOR BLUE}…$"

Route103_Text_BrendanLetsBattle:
	.string "{COLOR BLUE}Hey, it's {COLOR LIGHT_GREEN}{PLAYER}{COLOR BLUE}!\p"
	.string "…Oh, yeah, {COLOR RED}Dad {COLOR BLUE}gave you a {COLOR RED}Pokémon{COLOR BLUE}.\p"
	.string "Since we're here, how about a little\n"
	.string "battle?\p"
	.string "I'll teach you what being a trainer's\n"
	.string "about!$"

Route103_Text_BrendanDefeated:
	.string "{COLOR BLUE}Huh, {COLOR LIGHT_GREEN}{PLAYER}{COLOR BLUE}, you're not too shabby.$"

Route103_Text_BrendanTimeToHeadBack:
	.string "{COLOR BLUE}I think I get it.\n"
	.string "I think I know why my dad has his eye\l"
	.string "out for you now.\p"
	.string "Look, your {COLOR RED}Pokémon {COLOR BLUE}already likes you,\n"
	.string "even though you just got it.\p"
	.string "{COLOR LIGHT_GREEN}{PLAYER}{COLOR BLUE}, I get the feeling that you\n"
	.string "could befriend any {COLOR RED}Pokémon {COLOR BLUE}with ease.\p"
	.string "We should head back to the {COLOR RED}Lab{COLOR BLUE}.$"

Route103_Text_ShouldHaveBroughtPotion:
	.string "{COLOR BLUE}My {COLOR RED}Pokémon {COLOR BLUE}is staggeringly tired…\n"
	.string "I should have brought a {COLOR RED}Potion{COLOR BLUE}…$"

Route103_Text_ShortcutToOldale:
	.string "{COLOR BLUE}If you cross the sea from here,\n"
	.string "it'll be a shortcut to {COLOR RED}Oldale Town{COLOR BLUE}.\p"
	.string "Fufufu, that's useful, isn't it?$"

Route103_Text_RouteSign:
	.string "{COLOR RED}Route 103\n"
	.string "{COLOR GREEN}{DOWN_ARROW} {COLOR RED}Oldale Town$"

