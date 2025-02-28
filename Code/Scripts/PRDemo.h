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
 *     PRDemo.h
 *
 * DESCRIPTION
 *     PR Demo level definitions
 *
 * PROGRAMMER
 *     Design Team
 *
 * VERSION INFO
 *     $Author: Rich_d $
 *     $Revision: 15 $
 *     $Modtime: 6/13/00 11:29a $
 *     $Archive: /Commando/Code/Scripts/PRDemo.h $
 *
 ******************************************************************************/

#ifndef _PRDEMO_H_
#define _PRDEMO_H_

// Defines and Includes

#include "toolkit.h"

// Custom Types

typedef enum
{
    MPR_CUSTOM_START_DEL = SCMD_PRDEMO,
    MPR_CUSTOM_EXPLODE_BRIDGE_DEL,
    MPR_CUSTOM_FOLLOW_ME_DEL,
    MPR_CUSTOM_I_AM_DEAD_DEL,
    MPR_CUSTOM_ESCORT_ATTACKED_DEL,
    MPR_CUSTOM_EVAC_CALL_DEL,
    MPR_CUSTOM_APACHE_GOTO_POSITION_DEL,
    MPR_CUSTOM_APACHE_SHOOT_DEL,
    MPR_A01_CUSTOM_ORCA_TURRETSTRIKE_RAD,
    MPR_A04_CUSTOM_OBELISK_FIRING_RAD,
    MPR_A05_CUSTOM_TEMPLE_ZONE_ENTERED_RAD,
    MPR_A05_CUSTOM_MAMMOTH_RAD,
    MPR_A02_CUSTOM_DRILL_INSTRUCTOR_JDG,
    MPR_A02_CUSTOM_CADET_1_JDG,
    MPR_A02_CUSTOM_CADET_2_JDG,
    MPR_A02_CUSTOM_CADET_3_JDG,
    MPR_A02_CUSTOM_DRIVEBY_HARVESTER_JDG,
} PRCMD_EVENTS;

// Custom Parameters

typedef enum
{
    MPR_A02_PARAM_CADETS_TEN_HUT_JDG = 0,
    MPR_A02_PARAM_CADETS_AT_ATTENTION_JDG,
    MPR_A02_PARAM_CADETS_MADE_MISTAKE_JDG,
    MPR_A02_PARAM_CADETS_GOTO_INNATE_JDG,
    MPR_A00_PARAM_HAVOC_IN_ENTER_ZONE_JDG,
} PRCMD_PARAMS;

// Timers

typedef enum
{
    MPR_TIMER_START_DEL = STIMER_PRDEMO,
    MPR_TIMER_HARVESTER_DONE_DEL,
    MPR_TIMER_HARVESTER_MOVE_DEL,
    MPR_TIMER_APACHE_SHOOT_DEL,
    MPR_TIMER_TIBERIUM_PMP,
    MPR_TIMER_DELAY_01_PMP,
    MPR_TIMER_EVAC_PMP,
    MPR_TIMER_WANDER_PMP,
    MPR_TIMER_DELAY_01_04_PMP,
    MPR_TIMER_DELAY_01_03_PMP,
    MPR_TIMER_DELAY_01_02_PMP,
    MPR_A01_TIMER_ORCASTRIKE_RAD,
    MPR_A01_TIMER_ORCASTRIKE_OFF_RAD,
    MPR_A02_TIMER_CADET_1_TEN_HUT_DELAY_JDG,
    MPR_A02_TIMER_CADET_1_PUSHUPS_DELAY_JDG,
    MPR_A02_TIMER_CADET_1_SITUPS_DELAY_JDG,
    MPR_A02_TIMER_CADET_1_JUMPING_JACKS_DELAY_JDG,
    MPR_A02_TIMER_CADET_1_MISTAKE_DELAY_JDG,
    MPR_A02_TIMER_CADET_2_TEN_HUT_DELAY_JDG,
    MPR_A02_TIMER_CADET_2_PUSHUPS_DELAY_JDG,
    MPR_A02_TIMER_CADET_2_SITUPS_DELAY_JDG,
    MPR_A02_TIMER_CADET_2_JUMPING_JACKS_DELAY_JDG,
    MPR_A02_TIMER_CADET_2_MISTAKE_DELAY_JDG,
    MPR_A02_TIMER_CADET_3_TEN_HUT_DELAY_JDG,
    MPR_A02_TIMER_CADET_3_PUSHUPS_DELAY_JDG,
    MPR_A02_TIMER_CADET_3_SITUPS_DELAY_JDG,
    MPR_A02_TIMER_CADET_3_JUMPING_JACKS_DELAY_JDG,
    MPR_A02_TIMER_CADET_3_MISTAKE_DELAY_JDG,
    MPR_A02_TIMER_DRILL_INSTRUCTOR_ATTACK_DELAY_JDG,
    MPR_A02_TIMER_CADET_1_ATTACK_DELAY_JDG,
    MPR_A02_TIMER_CADET_2_ATTACK_DELAY_JDG,
    MPR_A02_TIMER_CADET_3_ATTACK_DELAY_JDG,
    MPR_A02_TIMER_DI_PRE_GIVE_ORDER_JDG,
    MPR_A03_TIMER_BRIDGESCENE_ENGINEER_HAVOC_IN_ZONE_DELAY_JDG,
    MPR_A03_TIMER_BRIDGESCENE_ENTER_ZONE_EXPLOSION_DELAY_JDG,
    MPR_A03_TIMER_INJURED_PILOT_CRAWL_1_JDG,
    MPR_A04_TIMER_SUICIDERUN_NOD_MINIGUNNER_HAVOC_IN_ZONE_DELAY_JDG,
    MPR_A04_TIMER_SUICIDERUN_GDI_MINIGUNNER_1_CHASE_DELAY_JDG,
    MPR_A04_TIMER_SUICIDERUN_GDI_MINIGUNNER_2_CHASE_DELAY_JDG,
    MPR_A04_TIMER_SUICIDERUN_GDI_MINIGUNNER_1_FOLLOW_TANK_DELAY_JDG,
    MPR_A04_TIMER_SUICIDERUN_GDI_MINIGUNNER_2_FOLLOW_TANK_DELAY_JDG,
    MPR_A04_TIMER_SUICIDERUN_NOD_LIGHTTANK_ATTACK_MEDIUMTANK_DELAY_JDG,
    MPR_A04_TIMER_SUICIDERUN_GDI_MINIGUNNER_1_ATTACK_LIGHTTANK_DELAY_JDG,
    MPR_A04_TIMER_SUICIDERUN_GDI_MINIGUNNER_2_ATTACK_LIGHTTANK_DELAY_JDG,
    MPR_A04_TIMER_SUICIDERUN_GDI_MEDIUMTANK_ATTACK_LIGHTTANK_DELAY_JDG,
    MPR_A04_TIMER_SUICIDERUN_GDI_MINIGUNNER_1_ATTACK_OBELISK_DELAY_JDG,
    MPR_A04_TIMER_SUICIDERUN_GDI_MINIGUNNER_2_ATTACK_OBELISK_DELAY_JDG,
    MPR_A04_TIMER_SUICIDERUN_GDI_MEDIUMTANK_ATTACK_OBELISK_DELAY_JDG,
    MPR_A04_TIMER_SUICIDERUN_GDI_MINIGUNNER_1_OBELISK_IS_DEAD_DELAY_JDG,
    MPR_A04_TIMER_SUICIDERUN_GDI_MINIGUNNER_2_OBELISK_IS_DEAD_DELAY_JDG,
    MPR_A04_TIMER_SUICIDERUN_GDI_MEDIUMTANK_OBELISK_IS_DEAD_DELAY_JDG,
    MPR_A04_TIMER_OBELISK_FIRING_RAD,
    MPR_A04_TIMER_OBELISK_STOPFIRING_RAD,
    MPR_A04_TIMER_OBELISK_PREFIRING_RAD,
    MPR_A05_TIMER_MAMMOTH_RAD,
    MPR_A05_TIMER_MAMMOTH_2_RAD,
    MPR_A05_TIMER_MAMMOTH_3_RAD,
    MPR_A05_TIMER_DROP_OBJECT_RMV,
    MPR_A05_TIMER_DIE_RMV,
} PRTIMER_TIMERS;

// Public Variables

bool MPR_nod_dead_PMP;
bool MPR_evacing_to_chinook_PMP;
bool MPR_A01_startstrike_RAD;

// Predefined Constants

const Vector3 MPR_A05_tank_move_locations_RAD[4] = {
    Vector3(-8.0f, 676.0f, 4.0f), // Mammoth Tank temple location
    Vector3(177.0f, 615.0f, 3.0f), // Airfield Flame Tank airstrip location
    Vector3(-180.0f, 522.0f, 2.0f), // Temple Flame Tank temple location
    Vector3(-160.0f, 521.0f, 4.0f) // Temple Flame Tank temple location
};

const char* MPR_control_klaxons_RAD[]
    = { "HONalert", "HONalert", "HONalert", "HONalert", "HONalert" };

const float MPR_A01_orca_attack_stoptime_RAD
    = 0.2f; // How long the ORCA turret attack should stay on.
const float MPR_A01_obelisk_firing_time_RAD = 2.0f; // How much time delay between Obelisk attacks.

#define MPR_A02_DRILL_INSTRUCTOR_X1_JDG -57.75f
#define MPR_A02_DRILL_INSTRUCTOR_Y1_JDG -12.79f
#define MPR_A02_DRILL_INSTRUCTOR_Z1_JDG 2.42f
#define MPR_A02_DRILL_INSTRUCTOR_X2_JDG -52.80f
#define MPR_A02_DRILL_INSTRUCTOR_Y2_JDG -7.26f
#define MPR_A02_DRILL_INSTRUCTOR_Z2_JDG 2.42f
#define MPR_A02_CADET_1_X_JDG -51.62f
#define MPR_A02_CADET_1_Y_JDG -10.56f
#define MPR_A02_CADET_1_Z_JDG 2.42f
#define MPR_A02_CADET_2_X_JDG -53.05f
#define MPR_A02_CADET_2_Y_JDG -11.93f
#define MPR_A02_CADET_2_Z_JDG 2.42f
#define MPR_A02_CADET_3_X_JDG -54.58f
#define MPR_A02_CADET_3_Y_JDG -13.31f
#define MPR_A02_CADET_3_Z_JDG 2.42f
#define MPR_A03_BRIDGESCENE_BRIDGE_ID_JDG 16016

// Typedefined Enumerations

typedef enum
{
    PUSHUPS = 0,
    SITUPS,
    JUMPING_JACKS,
} Exercise;

Exercise exercise;

typedef enum
{
    MPR_A04_SUICIDERUN_LIGHTTANK_ALIVE = 0,
    MPR_A04_SUICIDERUN_LIGHTTANK_DEAD,
} LIGHTTANKState;

LIGHTTANKState state;

typedef enum
{
    MPR_A04_SUICIDERUN_CONSOLE_ALIVE = 0,
    MPR_A04_SUICIDERUN_CONSOLE_DEAD,
} CONSOLEState;

CONSOLEState status;

// ID Values that need permanent address in the Level Editor

int MPR_A01_BARNZONE_GOTHERE_ID_PMP;
int MPR_A01_CIV01_ID_PMP;
int MPR_A01_CIV02_ID_PMP;
int MPR_A01_CIV03_ID_PMP;
int MPR_A01_orca_turret1_RAD;
int MPR_A01_orca_turret2_RAD;
int MPR_A02_drill_instructor_id_JDG;
int MPR_A02_cadet_1_id_JDG;
int MPR_A02_cadet_2_id_JDG;
int MPR_A02_cadet_3_id_JDG;
int MPR_A02_drill_zone_id_JDG;
int MPR_A02_driveby_harvester_id_JDG;
int MPR_A03_helicopter_injured_nod_pilot_id_JDG;
int MPR_A03_bridgescene_enterzone_id_JDG;
int MPR_A03_bridgescene_engineer_id_JDG;
int MPR_A03_bridgescene_blowupzone_id_JDG;
int MPR_A04_suiciderun_enterzone_id_JDG;
int MPR_A04_suiciderun_gdi_minigunner_1_id_JDG;
int MPR_A04_suiciderun_gdi_minigunner_2_id_JDG;
int MPR_A04_suiciderun_nod_minigunner_id_JDG;
int MPR_A04_suiciderun_gdi_medium_tank_id_JDG;
int MPR_A04_suiciderun_nod_light_tank_id_JDG;
int MPR_A05_mammoth_tank_id_RAD;

#define MPR_A02_HARVESTER_WAYPATH_JDG 364188
#define MPR_A02_HARVESTER_WAYPATH_START_JDG 364187
#define MPR_A02_HARVESTER_WAYPATH_STOP_JDG 364199

#endif // _PRDEMO_H_
