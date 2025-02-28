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

#if !defined(AFX_WHEELEDVEHICLEDIALOG_H__14B8CCA2_F28E_11D2_9BD8_00A0C9988171__INCLUDED_)
#define AFX_WHEELEDVEHICLEDIALOG_H__14B8CCA2_F28E_11D2_9BD8_00A0C9988171__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WheeledVehicleDialog.h : header file
//

class WheeledVehicleClass;

/////////////////////////////////////////////////////////////////////////////
// CWheeledVehicleDialog dialog

class CWheeledVehicleDialog : public CDialog
{
    // Construction
public:
    CWheeledVehicleDialog(CWnd* pParent, WheeledVehicleClass* obj);

    // Dialog Data
    //{{AFX_DATA(CWheeledVehicleDialog)
    enum
    {
        IDD = IDD_WHEELEDVEHICLE_DIALOG
    };
    CSpinButtonCtrl m_LengthSpin;
    CSpinButtonCtrl m_KSSpin;
    CSpinButtonCtrl m_KDSpin;
    //}}AFX_DATA

    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CWheeledVehicleDialog)
protected:
    virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV support
    virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
    //}}AFX_VIRTUAL

    // Implementation
protected:
    WheeledVehicleClass* EditedObject;

    float GetDlgItemFloat(int controlid);
    void SetDlgItemFloat(int controlid, float val);

    // Generated message map functions
    //{{AFX_MSG(CWheeledVehicleDialog)
    virtual void OnOK();
    virtual BOOL OnInitDialog();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WHEELEDVEHICLEDIALOG_H__14B8CCA2_F28E_11D2_9BD8_00A0C9988171__INCLUDED_)
