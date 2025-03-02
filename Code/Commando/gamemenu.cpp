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
 *                     $Archive:: /Commando/Code/Commando/gamemenu.cpp                        $*
 *                                                                                             *
 *                      $Author:: Bhayes                                                      $*
 *                                                                                             *
 *                     $Modtime:: 2/08/02 12:16p                                              $*
 *                                                                                             *
 *                    $Revision:: 191                                                        $*
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "gamemenu.h"
#include "_globals.h"
#include "assets.h"
#include "audiblesound.h"
#include "camera.h"
#include "ccamera.h"
#include "cnetwork.h"
#include "combatgmode.h"
#include "dazzle.h"
#include "debug.h"
#include "decophys.h"
#include "devoptions.h"
#include "dialogmgr.h"
#include "dlgmainmenu.h"
#include "dx8renderer.h"
#include "dx8wrapper.h"
#include "font3d.h"
#include "gamedata.h"
#include "gameinitmgr.h"
#include "gametype.h"
#include "input.h"
#include "langmode.h"
#include "menubackdrop.h"
#include "menudialog.h"
#include "miscutil.h"
#include "msgloop.h"
#include "netinterface.h"
#include "physlist.h"
#include "player.h"
#include "playermanager.h"
#include "playertype.h"
#include "popupdialog.h"
#include "pscene.h"
#include "rect.h"
#include "render2d.h"
#include "renegadedialogmgr.h"
#include "resource.h"
#include "saveloadstatus.h"
#include "scene.h"
#include "singlepl.h"
#include "string_ids.h"
#include "teammanager.h"
#include "textdisplay.h"
#include "texture.h"
#include "textureloader.h"
#include "thread.h"
#include "translatedb.h"
#include "useroptions.h"
#include "wolgmode.h"
#include "ww3d.h"
#include "wwaudio.h"
#include "wwmemlog.h"
#include "wwprofile.h"

bool g_is_loading = false;

////////////////////////////////////////////////////////////////////
//
//	MenuGameModeClass2
//
////////////////////////////////////////////////////////////////////
MenuGameModeClass2::MenuGameModeClass2(void)
    : MenuMusic(nullptr)
{
    return;
}

////////////////////////////////////////////////////////////////////
//
//	Init
//
////////////////////////////////////////////////////////////////////
void MenuGameModeClass2::Init(void)
{
    const char* MENU_MUSIC_FILENAME = "menu.mp3";

    //
    //	Create the background music
    //
    MenuMusic = WWAudioClass::Get_Instance()->Create_Sound_Effect(MENU_MUSIC_FILENAME);
    if (MenuMusic != nullptr) {
        MenuMusic->Set_Type(AudibleSoundClass::TYPE_MUSIC);
        MenuMusic->Set_Priority(1.0F);
        MenuMusic->Set_Loop_Count(0);
        MenuMusic->Set_Volume(1.0F);
    }

    if (MenuDialogClass::Get_BackDrop() && MenuDialogClass::Get_BackDrop()->Peek_Model() == nullptr) {
        MenuDialogClass::Get_BackDrop()->Set_Model("IF_BACK01");
        MenuDialogClass::Get_BackDrop()->Set_Animation("IF_BACK01.IF_BACK01");
    }

    return;
}

////////////////////////////////////////////////////////////////////
//
//	Shutdown
//
////////////////////////////////////////////////////////////////////
void MenuGameModeClass2::Shutdown(void)
{
    if (MenuMusic != nullptr) {
        MenuMusic->Stop();
        REF_PTR_RELEASE(MenuMusic);
    }

    return;
}

////////////////////////////////////////////////////////////////////
//
//	Think
//
////////////////////////////////////////////////////////////////////
void MenuGameModeClass2::Think(void)
{
    if (MenuMusic != nullptr) {

        //
        //	Start playing the music where necessary and stop the music
        // where necessary
        //
        if (Is_Active() && MenuMusic->Is_Playing() == false) {
            if (IS_SOLOPLAY || GameInitMgrClass::Is_Game_In_Progress() == false) {
                MenuMusic->Stop();
                MenuMusic->Play();
            }
        }
        else if (Is_Active() == false && MenuMusic->Is_Playing()) {
            MenuMusic->Stop();
        }
    }

    if (Is_Active() && DialogMgrClass::Get_Dialog_Count() == 0) {
        Deactivate();
    }

    return;
}

////////////////////////////////////////////////////////////////////
//
//	Think
//
////////////////////////////////////////////////////////////////////
void MenuGameModeClass2::Render(void)
{
    return;
}

////////////////////////////////////////////////////////////////////
//
//	Activate
//
////////////////////////////////////////////////////////////////////
void MenuGameModeClass2::Activate(void)
{
    WWMEMLOG(MEM_GAMEDATA);
    GameModeClass::Activate();

    //
    //	Pause game sounds and activate menu sounds
    //
    if (IS_SOLOPLAY && WWAudioClass::Get_Instance() != nullptr) {
        WWAudioClass::Get_Instance()->Set_Active_Sound_Page(WWAudioClass::PAGE_SECONDARY);
    }

    if (COMBAT_CAMERA != nullptr) {
        COMBAT_CAMERA->Set_Snap_Shot_Mode(false);
    }

    return;
}

////////////////////////////////////////////////////////////////////
//
//	Deactivate
//
////////////////////////////////////////////////////////////////////
void MenuGameModeClass2::Deactivate(void)
{
    WWMEMLOG(MEM_GAMEDATA);
    //
    //	Resume game sounds as necessary
    //
    if (WWAudioClass::Get_Instance() != nullptr) {
        WWAudioClass::Get_Instance()->Flush_Playlist(WWAudioClass::PAGE_SECONDARY);
        WWAudioClass::Get_Instance()->Set_Active_Sound_Page(WWAudioClass::PAGE_PRIMARY);
    }

    DialogMgrClass::Flush_Dialogs();
    GameModeClass::Deactivate();
    return;
}
