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

// PresetGeneralTab.cpp : implementation file
//

#include "CollisionGroups.h"
#include "SceneEditor.h"
#include "cameramgr.h"
#include "decophys.h"
#include "definition.h"
#include "hlod.h"
#include "leveledit.h"
#include "objectnode.h"
#include "parameter.h"
#include "preset.h"
#include "presetzonetab.h"
#include "rendobj.h"
#include "staticphys.h"
#include "stdafx.h"
#include "utils.h"
#include "wheelvehicle.h"
#include "zone.h"
#include "zoneeditdialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Constants
/////////////////////////////////////////////////////////////////////////////
const float DROP_POS = 5.0F;
const float DROP_HEIGHT = 5.0F;

const int COL_NAME = 0;

/////////////////////////////////////////////////////////////////////////////
//
// PresetZoneTabClass
//
/////////////////////////////////////////////////////////////////////////////
PresetZoneTabClass::PresetZoneTabClass(PresetClass* preset)
    : m_Preset(preset),
      m_PhysObj(nullptr),
      m_ZoneList(nullptr),
      DockableFormClass(PresetZoneTabClass::IDD)
{
    //{{AFX_DATA_INIT(PresetZoneTabClass)
    // NOTE: the ClassWizard will add member initialization here
    //}}AFX_DATA_INIT
    return;
}

/////////////////////////////////////////////////////////////////////////////
//
// ~PresetZoneTabClass
//
/////////////////////////////////////////////////////////////////////////////
PresetZoneTabClass::~PresetZoneTabClass(void)
{
    MEMBER_RELEASE(m_PhysObj);
    return;
}

/////////////////////////////////////////////////////////////////////////////
//
// DoDataExchange
//
/////////////////////////////////////////////////////////////////////////////
void PresetZoneTabClass::DoDataExchange(CDataExchange* pDX)
{
    DockableFormClass::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(PresetZoneTabClass)
    DDX_Control(pDX, IDC_ZONE_LIST, m_ListCtrl);
    //}}AFX_DATA_MAP
    return;
}

BEGIN_MESSAGE_MAP(PresetZoneTabClass, DockableFormClass)
//{{AFX_MSG_MAP(PresetZoneTabClass)
ON_NOTIFY(NM_DBLCLK, IDC_ZONE_LIST, OnDblclkZoneList)
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

#ifdef _DEBUG
void PresetZoneTabClass::AssertValid() const
{
    DockableFormClass::AssertValid();
}

void PresetZoneTabClass::Dump(CDumpContext& dc) const
{
    DockableFormClass::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
//
// HandleInitDialog
//
/////////////////////////////////////////////////////////////////////////////
void PresetZoneTabClass::HandleInitDialog(void)
{
    ASSERT(m_Preset != nullptr);

    ListView_SetExtendedListViewStyle(m_ListCtrl, LVS_EX_FULLROWSELECT);
    m_ListCtrl.InsertColumn(COL_NAME, "Name");

    //
    //	Add the zones to the list ctrl
    //
    int count = m_ZoneList->Count();
    for (int index = 0; index < count; index++) {

        //
        //	Insert this zone into the control
        //
        ZoneParameterClass* parameter = (*m_ZoneList)[index];
        if (parameter != nullptr) {
            m_ListCtrl.InsertItem(index, parameter->Get_Name(), 0);
        }
    }

    //
    //	Size the columns
    //
    CRect rect;
    m_ListCtrl.GetWindowRect(&rect);
    m_ListCtrl.SetColumnWidth(COL_NAME, (rect.Width()) - (::GetSystemMetrics(SM_CXVSCROLL) + 1));
    m_ListCtrl.SetFocus();
    return;
}

/////////////////////////////////////////////////////////////////////////////
//
// Apply_Changes
//
/////////////////////////////////////////////////////////////////////////////
bool PresetZoneTabClass::Apply_Changes(void)
{
    return true;
}

/////////////////////////////////////////////////////////////////////////////
//
// Modify_Selected_Zone
//
/////////////////////////////////////////////////////////////////////////////
void PresetZoneTabClass::Modify_Selected_Zone(void)
{
    Create_Phys_Obj();
    if (m_PhysObj != nullptr) {

        //
        //	Get the currently selected item
        //
        int index = m_ListCtrl.GetNextItem(-1, LVNI_ALL | LVNI_SELECTED);
        if (index >= 0) {

            ZoneParameterClass* parameter = (*m_ZoneList)[index];
            if (parameter != nullptr) {

                //
                //	Show the zone edit dialog
                //
                ZoneEditDialogClass dialog(this);
                dialog.Set_Phys_Obj(m_PhysObj);
                dialog.Set_Zone(parameter->Get_Zone());
                if (dialog.DoModal() == IDOK) {
                    parameter->Set_Zone(dialog.Get_Zone());
                }
            }
        }
    }

    return;
}

/////////////////////////////////////////////////////////////////////////////
//
// Create_Phys_Obj
//
/////////////////////////////////////////////////////////////////////////////
void PresetZoneTabClass::Create_Phys_Obj(void)
{
    CWaitCursor wait_cursor;

    if (m_PhysObj == nullptr && m_Preset != nullptr) {

        //
        //	Instantiate the node
        //
        NodeClass* node = (NodeClass*)m_Preset->Create();
        ASSERT(node != nullptr);
        if (node != nullptr) {

            //
            //	Initialize the node and get its phys object pointer
            //
            node->Initialize();
            PhysClass* phys_obj = node->Peek_Physics_Obj();
            ASSERT(phys_obj != nullptr);
            if (phys_obj != nullptr) {

                //
                //	Keep a copy of the physics object for our own uses.
                //
                m_PhysObj = phys_obj;
                m_PhysObj->Add_Ref();

                //
                //	Force the object to use its highest LOD
                //
                /*if (m_RenderObj->Class_ID () == RenderObjClass::CLASSID_HLOD) {
                        HLodClass *lod_obj = (HLodClass *)m_RenderObj;
                        lod_obj->Set_LOD_Level (lod_obj->Get_LOD_Count () - 1);
                }*/
            }

            MEMBER_RELEASE(node);
        }
    }

    return;
}

/////////////////////////////////////////////////////////////////////////////
//
// OnDblclkZoneList
//
/////////////////////////////////////////////////////////////////////////////
void PresetZoneTabClass::OnDblclkZoneList(NMHDR* pNMHDR, LRESULT* pResult)
{
    (*pResult) = 0;
    Modify_Selected_Zone();
    return;
}
