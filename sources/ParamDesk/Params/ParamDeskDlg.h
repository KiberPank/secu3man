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

#pragma once

#include <map>
#include <vector>

#include "common/unicodesupport.h"
#include "IParamDeskView.h"
#include "ui-core/ITabControllerEvent.h"
#include "ui-core/TabController.h"
#include "ui-core/UpdatableDialog.h"

class CHotKeysToCmdRouter;

/////////////////////////////////////////////////////////////////////////////
// CParamDeskDlg dialog

class AFX_EXT_CLASS CParamDeskDlg : public CModelessUpdatableDialog, public IParamDeskView, private ITabControllerEvent
{
 typedef CModelessUpdatableDialog Super;

 public:
  CParamDeskDlg(CWnd* pParent = NULL, bool i_show_knock_page = false);
  virtual ~CParamDeskDlg();
  static const UINT IDD;
  static const UINT IDD_F;

  //note: wnd_insert_after parameter may be used to fix tab order!
  void SetPosition(int x_pos, int y_pos, CWnd* wnd_insert_after = NULL);
  void SetTitle(const CString& i_str);
  void GetTitle(CString& o_str);

  //----------interface implementation---------------------------
  virtual bool IsEnabled(void);
  virtual void Enable(bool enable);
  virtual void Show(bool show);
  virtual void ShowSaveButton(bool i_show);

  virtual bool SetValues(BYTE i_descriptor, const void* i_values);
  virtual bool GetValues(BYTE i_descriptor, void* o_values);

  virtual void SetFunctionsNames(const std::vector<_TSTRING>& i_names);
  virtual const std::vector<_TSTRING>& GetFunctionsNames(void);

  virtual void EnableIgnitionCogs(bool enable);
  virtual void EnableUseVentPwm(bool enable);
  virtual void SetCrankType(int type);
  virtual void SetMaxCylinders(int number);

  virtual BYTE GetCurrentDescriptor(void);

  virtual void SetOnTabActivate(EventHandler OnTabActivate);
  virtual void SetOnChangeInTab(EventHandler OnChangeInTab);
  virtual void SetOnSaveButton(EventHandler OnSaveButton);

  //Get/Set current selection
  virtual bool SetCurSel(int sel);
  virtual int GetCurSel(void);
  //-------------------------------------------------------------

 // Implementation
 protected:
  virtual void DoDataExchange(CDataExchange* pDX);// DDX/DDV support
  virtual BOOL OnInitDialog();
  afx_msg void OnDestroy();
  afx_msg void OnUpdateControls(CCmdUI* pCmdUI);
  afx_msg void OnSaveButton();
  afx_msg void OnSysCommand(UINT, LONG);
  afx_msg void OnHK_STARTR_PAR();
  afx_msg void OnHK_ANGLES_PAR();
  afx_msg void OnHK_IDLREG_PAR();
  afx_msg void OnHK_FUNSET_PAR();
  afx_msg void OnHK_TEMPER_PAR();
  afx_msg void OnHK_CARBUR_PAR();
  afx_msg void OnHK_ADCCOR_PAR();
  afx_msg void OnHK_CKPS_PAR();
  afx_msg void OnHK_KNOCK_PAR(); // <--optional
  afx_msg void OnHK_MISCEL_PAR();
  DECLARE_MESSAGE_MAP()

 private:
  // ITabControllerEvent
  virtual void OnSelchangeTabctl(void);
  virtual void OnSelchangingTabctl(void);

  void OnChangeInTab(void);
  int  _GetTabIndex(unsigned i_descriptor);
  void _RegisterHotKeys(void);

  std::auto_ptr<CHotKeysToCmdRouter> m_hot_keys_supplier;

  //��������� �� ������� ���� �������
  class CStarterPageDlg*   m_pStarterPageDlg;
  class CAnglesPageDlg*    m_pAnglesPageDlg;
  class CIdlRegPageDlg*    m_pIdlRegPageDlg;
  class CFunSetPageDlg*    m_pFunSetPageDlg;
  class CTemperPageDlg*    m_pTemperPageDlg;
  class CCarburPageDlg*    m_pCarburPageDlg;
  class CADCCompenPageDlg* m_pADCCompenPageDlg;
  class CCKPSPageDlg*      m_pCKPSPageDlg;
  class CKnockPageDlg*     m_pKnockPageDlg; //<--optional
  class CMiscPageDlg*      m_pMiscPageDlg;

  CStatic m_pd_title;
  CButton m_save_button;
  CTabController m_tab_control;
  CImageList* m_pImgList;

  bool m_enabled;
  const bool m_show_knock_page;
  typedef std::map<int,unsigned> TabDescriptor;
  TabDescriptor m_tab_descriptors;

  //����������� ������� (��������)
  EventHandler m_OnTabActivate;
  EventHandler m_OnChangeInTab;
  EventHandler m_OnSaveButton;
};

/////////////////////////////////////////////////////////////////////////////
