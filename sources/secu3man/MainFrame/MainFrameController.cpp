/****************************************************************
 *       SECU-3  - An open source, free engine control unit
 *    Designed by Alexey A. Shabelnikov. Ukraine, Gorlovka 2009.
 *       Microprocessors systems - design & programming.
 *    contacts:
 *              http://secu-3.narod.ru
 *              ICQ: 405-791-931
 ****************************************************************/

#include "stdafx.h"
#include "Resources\resource.h"
#include "MainFrameController.h"

#include "about\secu-3about.h"
#include "Application\CommunicationManager.h"
#include "common\fastdelegate.h"
#include "io-core\logwriter.h"
#include "MainFrame.h"
#include "Settings\AppSettingsManager.h"
#include "Settings\ISettingsData.h"
#include "StatusBarManager.h"
#include "ui-core\HotKeysManager.h"

using namespace fastdelegate;

#define EHKEY _T("LogWriter")
#define MFKEY _T("MFCntr")


MainFrameController::MainFrameController(CCommunicationManager* i_pCommunicationManager, 
	                  CAppSettingsManager* i_pAppSettingsManager, CStatusBarManager* i_pStatusBarManager, 
					  LogWriter* i_pLogWriter, CMainFrame* ip_view /* = NULL*/)
: m_pCommunicationManager(i_pCommunicationManager)
, m_pAppSettingsManager(i_pAppSettingsManager)
, m_pStatusBarManager(i_pStatusBarManager)
, m_pLogWriter(i_pLogWriter)
, mp_view(ip_view)
, m_active(false)
, m_full_screen_mode(false)
{
 _ASSERTE(i_pCommunicationManager); 
 _ASSERTE(i_pAppSettingsManager); 
 _ASSERTE(i_pStatusBarManager); 
 _ASSERTE(i_pLogWriter);
 _ASSERTE(ip_view);
 _SetDelegates();
 m_pCommunicationManager->m_pAppAdapter->AddEventHandler(this, MFKEY);
}

void MainFrameController::_SetDelegates(void)
{
 if (NULL==mp_view)
  return;
 mp_view->setOnAppAbout(MakeDelegate(this,&MainFrameController::OnAppAbout));
 mp_view->setOnAppSettings(MakeDelegate(this,&MainFrameController::OnAppSettings));
 mp_view->setOnAppBeginLog(MakeDelegate(this,&MainFrameController::OnAppBeginLog));
 mp_view->setOnAppEndLog(MakeDelegate(this,&MainFrameController::OnAppEndLog));
 mp_view->setIsBeginLoggingAllowed(MakeDelegate(this,&MainFrameController::IsBeginLoggingAllowed));
 mp_view->setIsEndLoggingAllowed(MakeDelegate(this,&MainFrameController::IsEndLoggingAllowed));
 mp_view->setOnActivate(MakeDelegate(this,&MainFrameController::OnActivate));
 mp_view->setOnFullScreen(MakeDelegate(this,&MainFrameController::OnFullScreen));
}

MainFrameController::~MainFrameController()
{
 //na
}

void MainFrameController::OnAppAbout()
{
 DisplayAbout(mp_view);
}

void MainFrameController::OnAppSettings()
{
 int result = m_pAppSettingsManager->ShowDialog();

 if (result==IDOK)
 {
  //���������� ������ �� ���������� � ����������.
  ISettingsData* settings = m_pAppSettingsManager->GetSettings();
  m_pLogWriter->SetSeparatingSymbol(settings->GetCSVSepSymbol()); 

  mp_view->BeginWaitCursor();
  m_pCommunicationManager->Init();
  mp_view->EndWaitCursor();
 }
}

void MainFrameController::OnAppBeginLog()
{
 //���������� ������������ �������� � ������������ � ������ ������
 _TSTRING full_path_to_folder;

 ISettingsData* settings = m_pAppSettingsManager->GetSettings();

 //�������������� �������������� ������ ��� CSV-����� ��������� � ����������
 m_pLogWriter->SetSeparatingSymbol(settings->GetCSVSepSymbol()); 

 if (!settings->GetUseAppFolder())
  full_path_to_folder = settings->GetLogFilesFolder();
 else
  full_path_to_folder = settings->GetAppDirectory();
  
 _TSTRING full_file_name;

 bool result = m_pLogWriter->BeginLogging(full_path_to_folder, &full_file_name);
 if (false==result)
 {
  CString  string;
  string.Format(MLL::LoadString(IDS_CANT_START_LOG_WRITING), full_file_name.c_str());
  AfxMessageBox(string,MB_OK | MB_ICONSTOP);
  return;
 }

 m_pCommunicationManager->m_pAppAdapter->AddEventHandler(m_pLogWriter, EHKEY);
 m_pStatusBarManager->SetLoggerState(CStatusBarManager::LOG_STATE_WRITING);
}

void MainFrameController::OnAppEndLog()
{
 //����������� �� ������ ������ � ������������ ������������ ��������	 
 m_pCommunicationManager->m_pAppAdapter->RemoveEventHandler(EHKEY);
 m_pLogWriter->EndLogging();
 m_pStatusBarManager->SetLoggerState(CStatusBarManager::LOG_STATE_STOPPED);
}

bool MainFrameController::IsBeginLoggingAllowed(void)
{
 return !m_pLogWriter->IsLoggingInProcess() && m_pCommunicationManager->m_pControlApp->GetOnlineStatus();
}

bool MainFrameController::IsEndLoggingAllowed(void)
{
 return m_pLogWriter->IsLoggingInProcess() && m_pCommunicationManager->m_pControlApp->GetOnlineStatus();
}

void MainFrameController::SetView(CMainFrame* ip_view)
{
 _ASSERTE(ip_view);
 mp_view = ip_view;
 _SetDelegates();
}

void MainFrameController::OnPacketReceived(const BYTE i_descriptor, SECU3IO::SECU3Packet* ip_packet)
{
 //na
}

void MainFrameController::OnConnection(const bool i_online)
{
 if (false==i_online)
 {
  if (m_pLogWriter->IsLoggingInProcess())
   OnAppEndLog(); //���������� ������ ���� ��� ������ ��������
 }
}

bool MainFrameController::OnFullScreen()
{
 if (!m_full_screen_mode)
 {
  mp_view->GetWindowRect(m_last_wnd_rect);
  CRect rect = _GetScreenRect();
  mp_view->MoveWindow(rect.left,rect.top,rect.Width(), rect.Height());     
  m_full_screen_mode = true;
 }
 else
 {
  mp_view->MoveWindow(m_last_wnd_rect.left,m_last_wnd_rect.top,
      m_last_wnd_rect.Width(), m_last_wnd_rect.Height()); 
  m_full_screen_mode = false;
 }
 return m_full_screen_mode;
}

void MainFrameController::OnActivate(bool i_state)
{
 if (i_state && m_active)
 {
  HotKeysManager::GetInstance()->DeactivateAllHotKeys();
  m_active = false; 
 }
 else
 {
  HotKeysManager::GetInstance()->ActivateAllHotKeys();
  m_active = true;
 }
}

CRect MainFrameController::_GetScreenRect(void) const
{
 CDC* pDC = mp_view->GetDC();
 int x_resolution = pDC->GetDeviceCaps(HORZRES);
 int y_resolution = pDC->GetDeviceCaps(VERTRES);
 return CRect(0, 0, x_resolution, y_resolution);
}