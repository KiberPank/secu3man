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

#include "common/FastDelegate.h"

/////////////////////////////////////////////////////////////////////////////
// CButtonsPanel dialog

class AFX_EXT_CLASS CButtonsPanel : public CDialog
{
  typedef CDialog Super;

 public:
  typedef fastdelegate::FastDelegate1<int> EventWithCode;
  typedef fastdelegate::FastDelegate0<bool> EventResult;
  typedef fastdelegate::FastDelegate2<HWND, int> EventWithHWND;
  typedef fastdelegate::FastDelegate2<HWND, long> EventWithHWNDLong;

  CButtonsPanel(UINT dialog_id, CWnd* pParent = NULL);   // standard constructor
  /*static*/ const UINT IDD;

  //note: use wnd_insert_after parameter to fix tab order!
  void SetPosition(int x_pos, int y_pos, CWnd* wnd_insert_after = NULL);

  //returns NULL if corresponding window wasn't opened
  virtual HWND GetMapWindow(int wndType);
  
  //Read/Write access
  float* GetStartMap(bool i_original);
  float* GetIdleMap(bool i_original);
  float* GetWorkMap(bool i_original);
  float* GetTempMap(bool i_original);
  
  //updates all opened charts
  virtual void UpdateOpenedCharts(void);

 public: //��������� ������������ �������
  void setOnMapChanged(EventWithCode OnFunction);
  void setOnCloseMapWnd(EventWithHWND OnFunction);
  void setOnOpenMapWnd(EventWithHWND OnFunction); 
  void setIsAllowed(EventResult IsFunction);
  void setOnWndActivation(EventWithHWNDLong OnFunction); 

// Implementation
 protected:
  virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
  virtual BOOL OnInitDialog();
  afx_msg void OnViewStartMap();
  afx_msg void OnViewIdleMap();
  afx_msg void OnViewWorkMap();
  afx_msg void OnViewTempMap();
  afx_msg void OnUpdateViewStartMap(CCmdUI* pCmdUI);
  afx_msg void OnUpdateViewIdleMap(CCmdUI* pCmdUI);
  afx_msg void OnUpdateViewWorkMap(CCmdUI* pCmdUI);
  afx_msg void OnUpdateViewTempMap(CCmdUI* pCmdUI);
  afx_msg void OnTimer(UINT nIDEvent);
  afx_msg void OnDestroy();
  DECLARE_MESSAGE_MAP()

  void _EnableCharts(bool enable);

  //may be overloaded to change behaviour
  virtual bool IsAllowed(void);

  EventWithCode m_OnMapChanged;
  EventWithHWND m_OnCloseMapWnd;
  EventWithHWND m_OnOpenMapWnd;
  EventResult   m_IsAllowed;
  EventWithHWNDLong m_OnWndActivation;

 private:
  CButton m_view_work_map_btn;
  CButton m_view_temp_map_btn;
  CButton m_view_start_map_btn;
  CButton m_view_idle_map_btn;

  static void __cdecl OnChangeStartMap(void* i_param);
  static void __cdecl OnCloseStartMap(void* i_param);
  static void __cdecl OnChangeIdleMap(void* i_param);
  static void __cdecl OnCloseIdleMap(void* i_param);
  static void __cdecl OnChangeWorkMap(void* i_param);
  static void __cdecl OnCloseWorkMap(void* i_param);
  static void __cdecl OnChangeTempMap(void* i_param);
  static void __cdecl OnCloseTempMap(void* i_param);
  static void __cdecl OnGetYAxisLabel(LPTSTR io_label_string, void* i_param);
  static void __cdecl OnWndActivationStartMap(void* i_param, long cmd);
  static void __cdecl OnWndActivationIdleMap(void* i_param, long cmd);
  static void __cdecl OnWndActivationWorkMap(void* i_param, long cmd);
  static void __cdecl OnWndActivationTempMap(void* i_param, long cmd);

  int m_charts_enabled;
  ///////////////////////////////////////////////////////
  int m_work_map_chart_state;
  int m_temp_map_chart_state;
  int m_start_map_chart_state;
  int m_idle_map_chart_state;

  HWND m_start_map_wnd_handle;
  HWND m_idle_map_wnd_handle;
  HWND m_work_map_wnd_handle;
  HWND m_temp_map_wnd_handle;

  float m_start_map_active[16];
  float m_start_map_original[16];
  float m_idle_map_active[16];
  float m_idle_map_original[16];
  float m_work_map_active[16][16];
  float m_work_map_original[16][16];
  float m_temp_map_active[16];
  float m_temp_map_original[16];
  ///////////////////////////////////////////////////////
};
