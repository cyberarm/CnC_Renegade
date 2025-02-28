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

#if !defined(AFX_BACKGROUNDCOLORDIALOG_H__AF3CDE8C_61EC_11D2_9FC7_00104B791122__INCLUDED_)
#define AFX_BACKGROUNDCOLORDIALOG_H__AF3CDE8C_61EC_11D2_9FC7_00104B791122__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// BackgroundColorDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBackgroundColorDialog dialog

class CBackgroundColorDialog : public CDialog
{
    // Construction
public:
    CBackgroundColorDialog(CWnd* pParent = NULL); // standard constructor

    // Dialog Data
    //{{AFX_DATA(CBackgroundColorDialog)
    enum
    {
        IDD = IDD_BACKGROUND_COLOR
    };
    CSliderCtrl m_blueSlider;
    CSliderCtrl m_greenSlider;
    CSliderCtrl m_redSlider;
    //}}AFX_DATA

    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CBackgroundColorDialog)
protected:
    virtual void DoDataExchange(CDataExchange* pDX); // DDX/DDV support
    virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
    //}}AFX_VIRTUAL

    // Implementation
protected:
    // Generated message map functions
    //{{AFX_MSG(CBackgroundColorDialog)
    virtual BOOL OnInitDialog();
    afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    afx_msg void OnGrayscaleCheck();
    virtual void OnCancel();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

public:
    int m_initialRed;
    int m_initialGreen;
    int m_initialBlue;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous
// line.

#endif // !defined(AFX_BACKGROUNDCOLORDIALOG_H__AF3CDE8C_61EC_11D2_9FC7_00104B791122__INCLUDED_)
