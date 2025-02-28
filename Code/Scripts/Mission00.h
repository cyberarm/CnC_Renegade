/*
**	Command & Conquer Renegade(tm)
**	Copyright 2025 Electronic Arts Inc.
**
**	This program is free software: you can redistribute it and/or modify
**	it under the terms of the GNU General Public License as published by
**	the Free Software Foundation, either version 3 of the License, or
**	(at your option) any later version.
**
**	This program is distributed in the hope that it will be useful,
**	but WITHOUT ANY WARRANTY; without even the implied warranty of
**	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
**	GNU General Public License for more details.
**
**	You should have received a copy of the GNU General Public License
**	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/******************************************************************************
 *
 * FILE
 *     Mission00.h
 *
 * DESCRIPTION
 *     Mission 0 definitions
 *
 * PROGRAMMER
 *     Design Team
 *
 * VERSION INFO
 *     $Author: Rich_d $
 *     $Revision: 45 $
 *     $Modtime: 11/28/01 10:47a $
 *     $Archive: /Commando/Code/Scripts/Mission00.h $
 *
 ******************************************************************************/

#ifndef _MISSION0_H_
#define _MISSION0_H_

// Defines and Includes

#include "toolkit.h"

// Available Characters

#define MTU_CONTROLLER 400099
#define MTU_LOGAN 400005
#define MTU_GATE_GUARD 400006
#define MTU_SYDNEY 400007
#define MTU_GUNNER 400008
#define MTU_HOTWIRE 400009
#define MTU_MOBIUS 400010
#define MTU_PETROVA 400011
#define MTU_GDI_01 400012
#define MTU_GDI_02 400013
#define MTU_BARRACKS 450938
#define MTU_POWERPLANT 450937
#define MTU_TOWER 450939
#define MTU_SPAWN_01 400157
#define MTU_SPAWN_02 400158
#define MTU_SPAWN_03 400159

// Available Zones

#define MTU_ZONE_JUMP_HUD_INFO 300001
#define MTU_ZONE_TRIGGER_SNEAK_TRAINING 400014
#define MTU_ZONE_TRIGGER_JUMP_TRAINING 400015
#define MTU_ZONE_TRIGGER_EVA_TRAINING 400016
#define MTU_ZONE_TRIGGER_MOVE_TO_AGT 400017
#define MTU_ZONE_TRIGGER_KEYCARD_TRAINING 400018
#define MTU_ZONE_RESET_SYDNEY 400019
#define MTU_ZONE_START_SYDNEY 400020
#define MTU_ZONE_INTRODUCE_BARRACKS 400021
#define MTU_ZONE_RESET_GUNNER 400022
#define MTU_ZONE_START_GUNNER 400023
#define MTU_ZONE_SETUP_RANGE 400024
#define MTU_ZONE_RESET_RANGE 400025
#define MTU_ZONE_GUNNER_NEXT_WEAPON 400026
#define MTU_ZONE_BEACON_PLACEMENT 400027
#define MTU_ZONE_INTRODUCE_WEAPONS_FACTORY 400028
#define MTU_ZONE_RESET_HOTWIRE_01 400029
#define MTU_ZONE_RESET_HOTWIRE_02 400030
#define MTU_ZONE_START_HOTWIRE 400031
#define MTU_ZONE_VEHICLE_APPROACHED 400032
#define MTU_ZONE_CHECKPOINT_01 400033
#define MTU_ZONE_CHECKPOINT_02 400034
#define MTU_ZONE_CHECKPOINT_03 400035
#define MTU_ZONE_CHECKPOINT_04 400036
#define MTU_ZONE_INTRODUCE_REFINERY 400037
#define MTU_ZONE_RESET_IGNATIO 400038
#define MTU_ZONE_START_IGNATIO 400039
#define MTU_ZONE_INTRODUCE_POWER_PLANT 400040
#define MTU_ZONE_RESET_PETROVA 400041
#define MTU_ZONE_START_PETROVA 400042
#define MTU_ZONE_START_INVASION_01 400043
#define MTU_ZONE_START_INVASION_02 400044

// Available Waypath IDs

#define MTU_WAYPATH_LOGAN_JUMP_TRAINING 400049
#define MTU_WAYPATH_LOGAN_EVA_TRAINING 400067
#define MTU_WAYPATH_GDI_SOLDIER_PATROL 400083
#define MTU_WAYPATH_LOGAN_COURSE_EXTERIOR 400074
#define MTU_WAYPATH_APACHE_FLYOVER 400100

// Obstacle Course Gates

#define MTU_GATE_01 400142
#define MTU_GATE_02 400143
#define MTU_GATE_03 400144
#define MTU_GATE_04 400146

// Enumated Constant Custom Types

enum
{
    MTU_TYPE_DEFAULT,
    MTU_TYPE_STAR,
    MTU_TYPE_LOGAN,
    MTU_TYPE_SYDNEY,
    MTU_TYPE_HEALTH_POWERUP_ADD,
    MTU_TYPE_HEALTH_POWERUP_SUBTRACT,
    MTU_TYPE_ALL_POWERUPS_RESET,
    MTU_TYPE_ARMOR_POWERUP_ADD,
    MTU_TYPE_ARMOR_POWERUP_SUBTRACT,
    MTU_TYPE_GUNNER,
    MTU_TYPE_RANGE_CLEANUP_TARGETS,
    MTU_TYPE_RANGE_CHECK_TARGETS,
    MTU_TYPE_RANGE_SETUP_HANDGUN,
    MTU_TYPE_RANGE_TARGET_DESTROYED,
    MTU_TYPE_RANGE_SETUP_SNIPER_RIFLE,
    MTU_TYPE_RANGE_POWERUP_RETRIEVED,
    MTU_TYPE_RANGE_SETUP_AUTORIFLE,
    MTU_TYPE_RANGE_SETUP_GRENADE,
    MTU_TYPE_RANGE_SETUP_CHAINGUN,
    MTU_TYPE_RANGE_SETUP_FLAMETHROWER,
    MTU_TYPE_RANGE_SETUP_ROCKET,
    MTU_TYPE_RANGE_SETUP_C4,
    MTU_TYPE_RANGE_SETUP_ION,
    MTU_TYPE_SYDNEY_RESET,
    MTU_TYPE_SYDNEY_CHECK_RESET,
    MTU_TYPE_SYDNEY_IS_RESET,
    MTU_TYPE_WEAP_FACTORY_CLEANUP,
    MTU_TYPE_WEAP_ATTEMPT_RESET,
    MTU_TYPE_WEAP_FORCE_RESET,
    MTU_TYPE_HOTWIRE_START,
    MTU_TYPE_HOTWIRE,
    MTU_TYPE_WEAP_CREATE_HUMMVEE,
    MTU_TYPE_RESET_TRIGGER_ONCE,
    MTU_TYPE_RESET_CHECKPOINT_COUNT,
    MTU_TYPE_ADD_CHECKPOINT,
    MTU_TYPE_WEAP_CREATE_MEDTANK,
    MTU_TYPE_WEAP_CREATE_SQUISHIES,
    MTU_TYPE_BUILDING_DAMAGEABLE,
    MTU_TYPE_MOBIUS_RESET,
    MTU_TYPE_MOBIUS_CHECK_RESET,
    MTU_TYPE_MOBIUS,
    MTU_TYPE_RESET_PETROVA,
    MTU_TYPE_PETROVA_CHECK_RESET,
    MTU_TYPE_PETROVA,
    MTU_TYPE_ACTIVATE_FINALE,
    MTU_TYPE_CHECK_FINALE_START,
    MTU_TYPE_LIEUTENANT,
    MTU_TYPE_LIEUTENANT_START,
    MTU_TYPE_BUILDING_POWER_OFF,
    MTU_TYPE_BUILDING_POWER_ON,
    MTU_TYPE_BUILDING_DESTROY,
    MTU_TYPE_MOCK_INVASION,
    MTU_TYPE_GDI_SOLDIER_PATROL,
    MTU_TYPE_TRIGGER_SPAWNER,
    MTU_TYPE_COUNT_OFFICERS,
    MTU_TYPE_STAR_FACING,
    MTU_TYPE_REMOVE_OBJECTIVES
};

// Enumerated Constant Custom Parameters

enum
{
    MTU_PARAM_DEFAULT,
    MTU_PARAM_CONTROL_ENABLE,
    MTU_PARAM_CONTROL_DISABLE,
    MTU_PARAM_SPEECH_INTRO,
    MTU_PARAM_SPEECH_CROUCH,
    MTU_PARAM_SPEECH_JUMP,
    MTU_PARAM_SPEECH_EVA,
    MTU_PARAM_SPEECH_COURSE_DONE,
    MTU_PARAM_ACTION_KEYCARD_TRAIN,
    MTU_PARAM_ACTION_GOTO_AGT_RESET,
    MTU_PARAM_SPEECH_SYDNEY_START,
    MTU_PARAM_SPEECH_HEALTH,
    MTU_PARAM_SPEECH_PICKUP,
    MTU_PARAM_SPEECH_SHOOT_AGAIN,
    MTU_PARAM_SYDNEY_SHOT_RESET,
    MTU_PARAM_SPEECH_LAST_TIME,
    MTU_PARAM_SPEECH_RADAR,
    MTU_PARAM_ACTION_GOTO_INFANTRY,
    MTU_PARAM_GUNNER_RESET,
    MTU_PARAM_CHECK_TARGETS,
    MTU_PARAM_SPEECH_MORE_TARGETS,
    MTU_PARAM_TARGETS_ELIMINATED,
    MTU_PARAM_ACTION_GOTO_WEAPONS,
    MTU_PARAM_SPEECH_WEAP_INTRO,
    MTU_PARAM_SPEECH_WEAP_MOVEOUT,
    MTU_PARAM_SPEECH_WEAP_ACTION,
    MTU_PARAM_SPEECH_WEAP_MEDTANK,
    MTU_PARAM_SPEECH_WEAP_UNFINISHED,
    MTU_PARAM_SPEECH_WEAP_SQUISH,
    MTU_PARAM_SPEECH_WEAP_BIKE,
    MTU_PARAM_ACTION_PREPARE_REFINERY,
    MTU_PARAM_SPEECH_MOBIUS_REFINERY,
    MTU_PARAM_ACTION_PREPARE_POWER,
    MTU_PARAM_SPEECH_INTRO_POWER,
    MTU_PARAM_SPEECH_PETROVA_POWER,
    MTU_PARAM_ACTION_PREPARE_FINALE,
    MTU_PARAM_SPEECH_LIEUTENANT_START,
    MTU_PARAM_ACTION_GOTO_REFINERY,
    MTU_PARAM_SPEECH_INTRO_INFANTRY,
    MTU_PARAM_ACTION_PREPARE_INFANTRY,
    MTU_PARAM_SPEECH_INTRO_REFINERY,
    MTU_PARAM_ACTION_GOTO_POWER,
    MTU_PARAM_ACTION_PREPARE_WEAPONS,
    MTU_PARAM_ACTION_GOTO_HAVOC,
    MTU_PARAM_SPEECH_RETICULE
};

// Enumerated Constant Timers

enum
{
    MTU_TIMER_DEFAULT,
    MTU_TIMER_MISSION_START,
    MTU_TIMER_APACHE_DESTROY,
    MTU_TIMER_SYDNEY_CONTINUE,
    MTU_TIMER_GUNNER_DELAY_SPEECH,
    MTU_TIMER_GUNNER_SNIPER_AMMO,
    MTU_TIMER_GUNNER_AUTORIFLE_AMMO,
    MTU_TIMER_GUNNER_GRENADE_AMMO,
    MTU_TIMER_GUNNER_CHAINGUN_AMMO,
    MTU_TIMER_GUNNER_FLAMETHROWER_AMMO,
    MTU_TIMER_GUNNER_ROCKET_AMMO,
    MTU_TIMER_GUNNER_C4_AMMO,
    MTU_TIMER_GUNNER_ION_AMMO,
    MTU_TIMER_LOGAN_WAIT_FOR_HAVOC,
    MTU_TIMER_LOGAN_WAIT_REFINERY,
    MTU_TIMER_LOGAN_WAIT_POWER,
    MTU_TIMER_LOGAN_WAIT_POWER_02,
    MTU_TIMER_LOGAN_WAIT_AGT,
    MTU_TIMER_LOGAN_WAIT_INFANTRY,
    MTU_TIMER_LIEUTENANT_WAIT,
    MTU_TIMER_GDI_CONVERSATION,
    MTU_TIMER_ENDGAME,
    MTU_TIMER_FLYOVERS,
    MTU_TIMER_COMMANDO_CAMERA_01,
    MTU_TIMER_COMMANDO_CAMERA_02,
    MTU_TIMER_ANOTHER_APACHE,
    MTU_TIMER_MCT_ATTACK,
    MTU_TIMER_POKE_DELAY,
    MTU_TIMER_NOD_SOLDIER_REMOVAL
};

// Enumerated Constant Action and Conversation Identifiers

enum
{
    MTU_ACTION_DEFAULT,
    MTU_ACTION_LOGAN_JUMP_TEST,
    MTU_ACTION_LOGAN_EVA_TRAIN,
    MTU_ACTION_LOGAN_COURSE_DONE,
    MTU_ACTION_LOGAN_GOTO_AGT,
    MTU_SPEECH_LOGAN_START,
    MTU_SPEECH_LOGAN_CROUCH,
    MTU_SPEECH_LOGAN_CROUCH_TEST,
    MTU_SPEECH_LOGAN_HEARD,
    MTU_SPEECH_LOGAN_SNEAK_WIN,
    MTU_SPEECH_LOGAN_SNEAK_LOSE,
    MTU_SPEECH_LOGAN_JUMP_TEST,
    MTU_SPEECH_LOGAN_EVA,
    MTU_SPEECH_LOGAN_POKE,
    MTU_SPEECH_GATEGUARD_POKE,
    MTU_SPEECH_LOGAN_COURSE_DONE,
    MTU_SPEECH_LOGAN_KEYCARDS,
    MTU_SPEECH_LOGAN_GO_INSIDE,
    MTU_ACTION_GATEGUARD_OUTSIDE,
    MTU_ACTION_GATEGUARD_PATROL,
    MTU_SPEECH_SYDNEY_START,
    MTU_SPEECH_SYDNEY_HEALTH,
    MTU_SPEECH_SYDNEY_PICKUP,
    MTU_SPEECH_SYDNEY_ARMOR,
    MTU_SPEECH_SYDNEY_SHOOT_AGAIN,
    MTU_SPEECH_SYDNEY_LAST_TIME,
    MTU_SPEECH_SYDNEY_RADAR,
    MTU_SPEECH_INTRODUCE_BARRACKS,
    MTU_SPEECH_GUNNER_START,
    MTU_SPEECH_GUNNER_RETICULE,
    MTU_SPEECH_GUNNER_SNIPER_RIFLE,
    MTU_SPEECH_GUNNER_AUTORIFLE,
    MTU_SPEECH_GUNNER_GRENADE,
    MTU_SPEECH_GUNNER_CHAINGUN,
    MTU_SPEECH_GUNNER_FLAMETHROWER,
    MTU_SPEECH_GUNNER_ROCKET,
    MTU_SPEECH_GUNNER_C4,
    MTU_SPEECH_GUNNER_ION,
    MTU_SPEECH_GUNNER_MORE_TARGETS,
    MTU_SPEECH_GUNNER_ENDING,
    MTU_SPEECH_INTRODUCE_WEAP_FACTORY,
    MTU_SPEECH_HOTWIRE_INTRO,
    MTU_SPEECH_HOTWIRE_GO_OUT,
    MTU_SPEECH_HOTWIRE_MOVEOUT,
    MTU_SPEECH_HOTWIRE_ACTION,
    MTU_SPEECH_HOTWIRE_MEDTANK,
    MTU_SPEECH_HOTWIRE_UNFINISHED,
    MTU_SPEECH_HOTWIRE_SQUISH,
    MTU_SPEECH_HOTWIRE_BIKE,
    MTU_SPEECH_LOGAN_WHATSNEXT,
    MTU_SPEECH_INTRODUCE_REFINERY,
    MTU_SPEECH_MOBIUS_REFINERY,
    MTU_SPEECH_LOGAN_PREPARE_POWER,
    MTU_SPEECH_INTRODUCE_POWER,
    MTU_SPEECH_PETROVA_POWER,
    MTU_SPEECH_PETROVA_POWER_END,
    MTU_SPEECH_LOGAN_PREPARE_FINALE,
    MTU_SPEECH_LIEUTENANT_START,
    MTU_SPEECH_LIEUTENANT_LETIN,
    MTU_SPEECH_LIEUTENANT_MCT,
    MTU_SPEECH_LIEUTENANT_AFTER,
    MTU_ACTION_MOVE_LOGAN_WEAPONS,
    MTU_SPEECH_LOGAN_PREPARE_INFANTRY,
    MTU_ACTION_MOVE_LOGAN_EXIT,
    MTU_ACTION_MOVE_LIEUTENANT_HAVOC,
    MTU_ACTION_LIEUTENANT_LEAVE
};

// Movement Destination Identifiers

enum
{
    MTU_MOVE_DEFAULT,
    MTU_MOVE_LOGAN_JUMP_TRAINING,
    MTU_MOVE_LOGAN_EVA_TRAINING,
    MTU_MOVE_LOGAN_COURSE_EXTERIOR,
    MTU_MOVE_LOGAN_AGT,
    MTU_MOVE_LOGAN_INFANTRY,
    MTU_MOVE_LOGAN_WEAPONS,
    MTU_MOVE_LOGAN_REFINERY,
    MTU_MOVE_LOGAN_POWER,
    MTU_MOVE_LOGAN_EXIT,
    MTU_MOVE_LIEUTENANT_HAVOC
};

// Gunner Range State Identifiers

enum
{
    MTU_RANGE_STATE_DEFAULT
};

// Objective Identifiers

enum
{
    MTU_OBJECTIVE_01 = 1,
    MTU_OBJECTIVE_02,
    MTU_OBJECTIVE_03,
    MTU_OBJECTIVE_04,
    MTU_OBJECTIVE_05,
    MTU_OBJECTIVE_06,
    MTU_RADAR_GUNNER,
    MTU_RADAR_COURSE_01,
    MTU_RADAR_COURSE_02,
    MTU_RADAR_COURSE_03,
    MTU_RADAR_COURSE_04,
    MTU_RADAR_MCT_01,
    MTU_RADAR_MCT_02,
    MTU_RADAR_MCT_03,
    MTU_RADAR_MCT_04,
    MTU_RADAR_MCT_05
};

inline float Get_Obj_Distance(GameObject* obj1, GameObject* obj2)
{
    Vector3 loc1 = Vector3(0, 0, 0);
    Vector3 loc2 = Vector3(0, 0, 0);

    if (obj1) {
        loc1 = Commands->Get_Position(obj1);
    }
    if (obj2) {
        loc2 = Commands->Get_Position(obj2);
    }
    return Commands->Get_Distance(loc1, loc2);
};

// THESE DEFINES ARE FOR THE SKIRMISH MODE IN MULTIPLAYER

#define MSK_CONTROLLER 300203

#define MSK_GDI_DEF_01 300052
#define MSK_GDI_DEF_02 300064
#define MSK_GDI_DEF_03 300072
#define MSK_GDI_DEF_04 300081
#define MSK_GDI_ATK_01 300091
#define MSK_GDI_ATK_02 300092
#define MSK_GDI_ATK_03 300093

#define MSK_NOD_DEF_01 300001
#define MSK_NOD_DEF_02 300016
#define MSK_NOD_DEF_03 300028
#define MSK_NOD_DEF_04 300042
#define MSK_NOD_ATK_01 300150
#define MSK_NOD_ATK_02 300151
#define MSK_NOD_ATK_03 300152

#define MSK_GDI_DEF_PATH_01 300053
#define MSK_GDI_DEF_PATH_02 300065
#define MSK_GDI_DEF_PATH_03 300073
#define MSK_GDI_DEF_PATH_04 300082
#define MSK_GDI_ATK_PATH_01 300094
#define MSK_GDI_ATK_PATH_02 300111
#define MSK_GDI_ATK_PATH_03 300126

#define MSK_NOD_DEF_PATH_01 300002
#define MSK_NOD_DEF_PATH_02 300017
#define MSK_NOD_DEF_PATH_03 300029
#define MSK_NOD_DEF_PATH_04 300043
#define MSK_NOD_ATK_PATH_01 300153
#define MSK_NOD_ATK_PATH_02 300166
#define MSK_NOD_ATK_PATH_03 300178

#define MSK_SOLDIER_DEAD 100
#define MSK_TIMER 101
#define MSK_TIMER_02 102

#endif // _MISSION2_H_
