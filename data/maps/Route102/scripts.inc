Route102_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route102_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, Route102_OnResume
	.byte 0

Route102_OnTransition:
	special GetEncounterTime
	goto_if_eq VAR_RESULT, 3, Route102_OnTransition_Night
	goto_if_eq VAR_RESULT, 2, Route102_OnTransition_Evening
	goto_if_eq VAR_RESULT, 1, Route102_OnTransition_Day
	goto_if_eq VAR_RESULT, 0, Route102_OnTransition_Morning
	end

Route102_OnTransition_Morning:
	setvar VAR_DAYNIGHT, 0
	end

Route102_OnTransition_Day:
	setvar VAR_DAYNIGHT, 1
	end

Route102_OnTransition_Evening:
	setvar VAR_DAYNIGHT, 2
	end

Route102_OnTransition_Night:
	setvar VAR_DAYNIGHT, 3
	end

Route102_OnResume:
	special GetEncounterTime
	goto_if_eq VAR_RESULT, 3, Route102_OnResume_Night
	goto_if_eq VAR_RESULT, 2, Route102_OnResume_Evening
	goto_if_eq VAR_RESULT, 1, Route102_OnResume_Day
	goto_if_eq VAR_RESULT, 0, Route102_OnResume_Morning
	end

Route102_OnResume_Night:
	setvar VAR_DAYNIGHT, 3
	end
	
Route102_OnResume_Evening:
	setvar VAR_DAYNIGHT, 2
	end

Route102_OnResume_Day:
	setvar VAR_DAYNIGHT, 1
	end
	
Route102_OnResume_Morning:
	setvar VAR_DAYNIGHT, 0
	end

Route102_EventScript_LittleBoy::
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
	end

Route102_EventScript_RouteSignOldale::
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg::
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route102_EventScript_Boy::
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

Route102_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
	release
	end

Route102_EventScript_CalvinRegisterMatchCall::
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegister::
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinRematch::
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_Text_ImNotVeryTall:
	.string "{COLOR BLUE}I'm…not very tall, so I sink right\n"
	.string "into tall grass.\p"
	.string "The grass goes up my nose and…\n"
	.string "Fwafwafwafwafwa…\p"
	.string "Fwatchoo!$"

Route102_Text_CatchWholeBunchOfPokemon:
	.string "{COLOR BLUE}I'm going to catch a whole bunch of\n"
	.string "{COLOR RED}Pokémon{COLOR BLUE}!$"

Route102_Text_RouteSignOldale:
	.string "{COLOR RED}Route 102\n"
	.string "{COLOR GREEN}{RIGHT_ARROW} {COLOR RED}Oldale Town$"

Route102_Text_RouteSignPetalburg:
	.string "{COLOR RED}Route 102\n"
	.string "{COLOR GREEN}{LEFT_ARROW} {COLOR RED}Petalburg City$"

