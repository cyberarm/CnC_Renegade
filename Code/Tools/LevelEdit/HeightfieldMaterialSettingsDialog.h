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

#if !defined(                                                                                      \
    AFX_HEIGHTFIELDMATERIALSETTINGSDIALOG_H__E4621EB8_6CB2_4BEC_A103_1FD3525618E3__INCLUDED_)
#define AFX_HEIGHTFIELDMATERIALSETTINGSDIALOG_H__E4621EB8_6CB2_4BEC_A103_1FD3525618E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HeightfieldMaterialSettingsDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// HeightfieldMaterialSettingsDialogClass dialog

class HeightfieldMaterialSettingsDialogClass : public CDialog
{
    // Construction
public:
    HeightfieldMaterialSettingsDialogClass(CWnd* pParent = nullptr); // standard constructor

    // Dialog Data
    //{{AFX_DATA(HeightfieldMaterialSettingsDialogClass)
    enum
    {
        IDD = IDD_HEIGHTFIELD_MATERIAL_SETTINGS
    };
    // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA

    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(HeightfieldMaterialSettingsDialogClass)
protected:
    virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV support
    //}}AFX_VIRTUAL

    // Implementation
protected:
    // Generated message map functions
    //{{AFX_MSG(HeightfieldMaterialSettingsDialogClass)
    virtual BOOL OnInitDialog();
    virtual void OnOK();
    afx_msg void OnBrowse();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

public:
    ////////////////////////////////////////////////////////////////
    //	Public methods
    ////////////////////////////////////////////////////////////////

    //
    //	Material access
    //
    void Set_Material(int index) { MaterialIndex = index; }

private:
    ////////////////////////////////////////////////////////////////
    //	Private member data
    ////////////////////////////////////////////////////////////////
    int MaterialIndex;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HEIGHTFIELDMATERIALSETTINGSDIALOG_H__E4621EB8_6CB2_4BEC_A103_1FD3525618E3__INCLUDED_)
