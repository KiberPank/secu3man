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
#include "LogWriter.h"
#include "ufcodes.h"
#include "SECU3IO.h"

using namespace SECU3IO;

const char cCSVTimeTemplateString[] = "%02d:%02d:%02d.%02d";
const char cCSVDataTemplateString[] = "%c%%04d%c%%6.2f%c%%6.2f%c%%5.2f%c%%6.2f%c%%4.2f%c%%5.2f%c%%02d%c%%01d%c%%01d%c%%01d%c%%01d\r\n";

LogWriter::LogWriter()
: m_is_busy(false)
, m_out_handle(NULL)
, m_csv_separating_symbol(',')
{
 SetSeparatingSymbol(m_csv_separating_symbol);
}

LogWriter::~LogWriter()
{
 //��������� ������� ������ ���� ���� �� ��� �� ��������
 if (IsLoggingInProcess())
  EndLogging();
}

void LogWriter::OnPacketReceived(const BYTE i_descriptor, SECU3IO::SECU3Packet* ip_packet)
{
 if (i_descriptor==SENSOR_DAT)
 {
  ASSERT(m_out_handle);
  SensorDat *p_sensors = reinterpret_cast<SensorDat*>(ip_packet);

  SYSTEMTIME time;
  ::GetLocalTime(&time);

  //���������� ASCII ������, ���� �� ������ ���� ���������
  //"hh:mm:ss.ms", ms - ����� ���� �������
  fprintf(m_out_handle, cCSVTimeTemplateString,time.wHour,time.wMinute,time.wSecond,time.wMilliseconds/10);

  fprintf(m_out_handle, m_csv_data_template,
                        p_sensors->frequen,
                        p_sensors->adv_angle,
                        p_sensors->pressure,
                        p_sensors->voltage,
                        p_sensors->temperat,
                        p_sensors->knock_k,
                        p_sensors->knock_retard,
                        (int)p_sensors->air_flow,
                        (int)p_sensors->carb,
                        (int)p_sensors->gas,
                        (int)p_sensors->ephh_valve,
                        (int)p_sensors->epm_valve);
 }
}

void LogWriter::OnConnection(const bool i_online)
{
 //na
}


bool LogWriter::BeginLogging(const _TSTRING& i_folder, _TSTRING* o_full_file_name /* = NULL*/)
{
 //���������� ��� ����� � ��������� ���
 SYSTEMTIME time;
 ::GetLocalTime(&time);

 _TSTRING full_file_name = i_folder;
 CString string;
 //yyyy.mm.dd_hh.mm.ss.csv
 string.Format(_T("%04d.%02d.%02d_%02d.%02d.%02d.csv"),time.wYear,time.wMonth,time.wDay,time.wHour,time.wMinute,time.wSecond);

 full_file_name += _T("\\");
 full_file_name += string;
 *o_full_file_name = full_file_name;

 m_out_handle = _tfopen(full_file_name.c_str(),_T("wb+"));
 if (NULL == m_out_handle)
  return false;

 m_is_busy = true;
 return true;
}

void LogWriter::EndLogging(void)
{
 //��������� ����
 if (m_out_handle)
 {
  fclose(m_out_handle);
 }
 else
  _ASSERTE(0);

 m_is_busy = false;
}


bool LogWriter::IsLoggingInProcess(void)
{
 return m_is_busy;
}

void LogWriter::SetSeparatingSymbol(char i_sep_symbol)
{
 int x = m_csv_separating_symbol = i_sep_symbol;
 sprintf (m_csv_data_template, cCSVDataTemplateString, x, x, x, x, x, x, x, x, x, x, x, x);
}
