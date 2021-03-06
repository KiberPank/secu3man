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

#ifndef _CE_ERRORS_H_
#define _CE_ERRORS_H_

//���������� ���� ������ (Check Engine)
#define ECUERROR_CKPS_MALFUNCTION     0
#define ECUERROR_EEPROM_PARAM_BROKEN  1
#define ECUERROR_PROGRAM_CODE_BROKEN  2
#define ECUERROR_KSP_CHIP_FAILED      3
#define ECUERROR_KNOCK_DETECTED       4
#define ECUERROR_MAP_SENSOR_FAIL      5
#define ECUERROR_TEMP_SENSOR_FAIL     6
#define ECUERROR_VOLT_SENSOR_FAIL     7
#define ECUERROR_DWELL_CONTROL        8
#define ECUERROR_CAMS_MALFUNCTION     9


#endif //_CE_ERRORS_H_
