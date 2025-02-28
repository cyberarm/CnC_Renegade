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

#if !defined(AFX_RANGEDIALOG_H__C44E4EC7_F133_11D3_A08F_00104B791122__INCLUDED_)
#define AFX_RANGEDIALOG_H__C44E4EC7_F133_11D3_A08F_00104B791122__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RangeDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRangeDialog dialog

class CRangeDialog : public CDialog
{
    // Construction
public:
    CRangeDialog(CWnd* pParent = NULL); // standard constructor

    // Dialog Data
    //{{AFX_DATA(CRangeDialog)
    enum
    {
        IDD = IDD_RANGES
    };
    // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA

    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CRangeDialog)
protected:
    virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV support
    //}}AFX_VIRTUAL

    // Implementation
protected:
    // Generated message map functions
    //{{AFX_MSG(CRangeDialog)
    virtual BOOL OnInitDialog();
    virtual void OnOK();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RANGEDIALOG_H__C44E4EC7_F133_11D3_A08F_00104B791122__INCLUDED_)
