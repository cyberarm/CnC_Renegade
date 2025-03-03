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

/***********************************************************************************************
 ***                            Confidential - Westwood Studios                              ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Commando                                                     *
 *                                                                                             *
 *                     $Archive:: /Commando/Code/Commando/_globals.h                           $*
 *                                                                                             *
 *                      $Author:: Bhayes                                                      $*
 *                                                                                             *
 *                     $Modtime:: 3/06/02 5:36p                                               $*
 *                                                                                             *
 *                    $Revision:: 25                                                          $*
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#pragma once

#ifndef _GLOBALS_H
#define _GLOBALS_H

#include "specialbuilds.h"

/*
#ifdef FREEDEDICATEDSERVER
#define APP_SUB_KEY "Software\\Westwood\\RenegadeFDS"
#else  //FREEDEDICATEDSERVER

#ifdef MULTIPLAYERDEMO
#define APP_SUB_KEY "Software\\Westwood\\RenegadeMPDemo"
#else // MULTIPLAYERDEMO
#define APP_SUB_KEY "Software\\Westwood\\Renegade"
#endif //MULTIPLAYERDEMO

#endif //FREEDEDICATEDSERVER
*/

#if defined(FREEDEDICATEDSERVER)
#define APP_SUB_KEY "Software\\Westwood\\RenegadeFDS"
#elif defined(MULTIPLAYERDEMO)
#define APP_SUB_KEY "Software\\Westwood\\RenegadeMPDemo"
#elif defined(BETACLIENT)
#define APP_SUB_KEY "Software\\Westwood\\RenegadeBeta"
#elif defined(BETASERVER)
#define APP_SUB_KEY "Software\\Westwood\\RenegadeBeta"
#else
#define APP_SUB_KEY "Software\\Westwood\\Renegade"
#endif

extern char* Build_Registry_Location_String(char* base, char* modifier, char* sub);

#define APPLICATION_SUB_KEY_NAME Build_Registry_Location_String(APP_SUB_KEY, nullptr, "")

#define APPLICATION_SUB_KEY_NAME_RENDER Build_Registry_Location_String(APP_SUB_KEY, nullptr, "Render")
#define APPLICATION_SUB_KEY_NAME_OPTIONS                                                           \
    Build_Registry_Location_String(APP_SUB_KEY, nullptr, "Options")
#define APPLICATION_SUB_KEY_NAME_DEBUG Build_Registry_Location_String(APP_SUB_KEY, nullptr, "Debug")
#define APPLICATION_SUB_KEY_NAME_SYSTEM_SETTINGS                                                   \
    Build_Registry_Location_String(APP_SUB_KEY, nullptr, "System Settings")
#define APPLICATION_SUB_KEY_NAME_CONTROLS                                                          \
    Build_Registry_Location_String(APP_SUB_KEY, nullptr, "Controls")
#define APPLICATION_SUB_KEY_NAME_SOUND Build_Registry_Location_String(APP_SUB_KEY, nullptr, "Sound")
#define APPLICATION_SUB_KEY_NAME_MOVIES Build_Registry_Location_String(APP_SUB_KEY, nullptr, "Movies")
#define APPLICATION_SUB_KEY_NAME_WOLSETTINGS                                                       \
    Build_Registry_Location_String(APP_SUB_KEY, nullptr, "WOLSettings")
#define APPLICATION_SUB_KEY_NAME_MISSION_RANKS                                                     \
    Build_Registry_Location_String(APP_SUB_KEY, nullptr, "Ranks")
#define APPLICATION_SUB_KEY_NAME_INPUT Build_Registry_Location_String(APP_SUB_KEY, nullptr, "Input")
#define APPLICATION_SUB_KEY_NAME_GAMESPY                                                           \
    Build_Registry_Location_String(APP_SUB_KEY, nullptr, "GameSpy")
#define APPLICATION_SUB_KEY_NAME_WOLSETTINGS                                                       \
    Build_Registry_Location_String(APP_SUB_KEY, nullptr, "WOLSettings")
#define APPLICATION_SUB_KEY_NAME_URL                                                               \
    Build_Registry_Location_String(APP_SUB_KEY, nullptr, "WOLSettings\\URL")
#define APPLICATION_SUB_KEY_NAME_LOGINS                                                            \
    Build_Registry_Location_String(APP_SUB_KEY, nullptr, "WOLSettings\\Logins")
#define APPLICATION_SUB_KEY_NAME_QUICKMATCH                                                        \
    Build_Registry_Location_String(APP_SUB_KEY, nullptr, "WOLSettings\\QuickMatch")
#define APPLICATION_SUB_KEY_NAME_IGNORE_LIST                                                       \
    Build_Registry_Location_String(APP_SUB_KEY, nullptr, "WOLSettings\\Ignore List")
#define APPLICATION_SUB_KEY_NAME_SERVER_LIST                                                       \
    Build_Registry_Location_String(APP_SUB_KEY, nullptr, "WOLSettings\\Servers")
#define APPLICATION_SUB_KEY_NAME_SKIN_LIST                                                         \
    Build_Registry_Location_String(APP_SUB_KEY, nullptr, "MP Settings\\Skins")

#define APPLICATION_SUB_KEY_NAME_NETOPTIONS                                                        \
    Build_Registry_Location_String(APP_SUB_KEY, nullptr, "Networking\\Options")
#define APPLICATION_SUB_KEY_NAME_NETDEBUG                                                          \
    Build_Registry_Location_String(APP_SUB_KEY, nullptr, "Networking\\Debug")
#define APPLICATION_SUB_KEY_NAME_NET_FIREWALL                                                      \
    Build_Registry_Location_String(APP_SUB_KEY, nullptr, "Networking\\Firewall")
#define APPLICATION_SUB_KEY_NAME_NET_SLAVE                                                         \
    Build_Registry_Location_String(APP_SUB_KEY, nullptr, "Networking\\Slave")
#define APPLICATION_SUB_KEY_NAME_NET_SERVER_CONTROL                                                \
    Build_Registry_Location_String(APP_SUB_KEY, nullptr, "Networking\\ServerControl")

#define COMBAT_SUB_KEY_NAME_DEBUG Build_Registry_Location_String(APP_SUB_KEY, nullptr, "Debug")

#define APPLICATION_SUB_KEY_NAME_BANDTEST                                                          \
    Build_Registry_Location_String(APP_SUB_KEY, nullptr, "Bandtest")

#define RENEGADE_BASE_SKU 3072
#define RENEGADE_FDS_SKU 12288
#define RENEGADE_DEMO_SKU 13056

#endif