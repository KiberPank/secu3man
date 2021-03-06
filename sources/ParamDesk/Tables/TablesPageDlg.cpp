/* SECU-3  - An open source, free engine control unit
   Copyright (C) 2007 Alexey A. Shabelnikov. Ukraine, Gorlovka

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.

   contacts:
              http://secu-3.org
              email: shabelnikov@secu-3.org
*/

#include "stdafx.h"
#include "Resources/resource.h"
#include "TablesPageDlg.h"

#include "TablDesk/ButtonsPanel.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

using namespace fastdelegate;

const UINT CTablesPageDlg::IDD = IDD_TD_TABLES_PAGE;

BEGIN_MESSAGE_MAP(CTablesPageDlg, Super)
 ON_EN_CHANGE(IDC_TD_TABLESSET_NAME_EDIT, OnChangeTablesSetName)
 ON_UPDATE_COMMAND_UI(IDC_TD_TABLESSET_NAME_EDIT, OnUpdateControls)
 ON_UPDATE_COMMAND_UI(IDC_TD_TABLESSET_NAME_TITLE, OnUpdateControls)
 ON_EN_KILLFOCUS(IDC_TD_TABLESSET_NAME_EDIT, OnEditKillFocus)
END_MESSAGE_MAP()

CTablesPageDlg::CTablesPageDlg(CWnd* pParent /*=NULL*/)
: Super(CTablesPageDlg::IDD, pParent)
, m_enabled(false)
, m_tsneb_readonly(false)
, m_lock_enchange(false)
, m_lock_killfocus(true)
, mp_ButtonsPanel(new CButtonsPanel(0, NULL))
{
 mp_ButtonsPanel->setIsAllowed(MakeDelegate(this, &CTablesPageDlg::IsAllowed));
}

LPCTSTR CTablesPageDlg::GetDialogID(void) const
{
 return (LPCTSTR)IDD;
}

void CTablesPageDlg::DoDataExchange(CDataExchange* pDX)
{
 Super::DoDataExchange(pDX);
 DDX_Control(pDX, IDC_TD_TABLESSET_NAME_EDIT, m_names_edit);
 DDX_Control(pDX, IDC_TD_MODIFICATION_FLAG, m_midification_flag);
}

//���� ���� ��������� ��������� ���������, �� ���� ����� ������� �������
void CTablesPageDlg::OnUpdateControls(CCmdUI* pCmdUI)
{
 pCmdUI->Enable(m_enabled);
}

/////////////////////////////////////////////////////////////////////////////
// CTablesPageDlg message handlers

BOOL CTablesPageDlg::OnInitDialog()
{
 Super::OnInitDialog();
 m_lock_killfocus = true;

 CRect rect;
 GetDlgItem(IDC_TD_BUTTONS_PANEL_HOLDER)->GetWindowRect(rect);
 ScreenToClient(rect);

 mp_ButtonsPanel->Create(mp_ButtonsPanel->IDD, this);
 mp_ButtonsPanel->SetPosition(rect.left, rect.top, &m_names_edit);
 mp_ButtonsPanel->ShowWindow(SW_SHOW);

 m_names_edit.SetReadOnly(m_tsneb_readonly);
 m_names_edit.SetLimitText(16);

 UpdateData(FALSE);
 UpdateDialogControls(this, TRUE);
 return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTablesPageDlg::OnEditKillFocus()
{
 if (m_lock_killfocus)
  return; //we need to prevent wrong behaviour when window is recreated
 if (0==m_names_edit.GetWindowTextLength())
 {
  m_names_edit.SetWindowText(_T("<no name>"));
  //allow controller process latest changes
  if (m_OnChangeTablesSetName && false==m_lock_enchange)
   m_OnChangeTablesSetName();
 }

 m_lock_killfocus = true;
}

//����������/���������� ���������� (���� ���������)
void CTablesPageDlg::Enable(bool enable)
{
 if (m_enabled == enable)
  return; //already has needed state
 m_enabled = enable;
 if (::IsWindow(m_hWnd))
  UpdateDialogControls(this,TRUE);
}

void CTablesPageDlg::SetReadOnlyTablesSetName(bool readonly)
{
 m_tsneb_readonly = readonly;
 m_names_edit.SetReadOnly(readonly);
}

//��� � �����������?
bool CTablesPageDlg::IsEnabled(void)
{
 return m_enabled;
}

//from CButtonsPanel
bool CTablesPageDlg::IsAllowed(void)
{
 return m_enabled;
}

//from edit box
void CTablesPageDlg::OnChangeTablesSetName()
{
 if (m_OnChangeTablesSetName && false==m_lock_enchange)
 {
  m_lock_killfocus = false;
  m_OnChangeTablesSetName();
 }
}

void CTablesPageDlg::SetTablesSetName(const _TSTRING& name)
{
 m_lock_enchange = true;
 m_names_edit.SetWindowText(name.c_str());
 m_lock_enchange = false;
}

_TSTRING CTablesPageDlg::GetTablesSetName(void) const
{
 CString str;
 m_names_edit.GetWindowText(str);
 return str.GetBuffer(128);
}

void CTablesPageDlg::SetModificationFlag(bool value)
{
 m_midification_flag.SetWindowText(value ? _T("*") : _T(" "));
}

void CTablesPageDlg::setOnChangeTablesSetName(EventHandler OnFunction)
{ m_OnChangeTablesSetName = OnFunction; }
