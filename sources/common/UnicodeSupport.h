/* Common utilities - UNICODE-transparent typedefs
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
             ICQ: 405-791-931. e-mail: shabelnikov-stc@mail.ru
             Microprocessors systems - design & programming.
*/

//IF You use _UNICODE:
//In the Output category of the Link tab in the Project Settings dialog box,
//set the Entry Point Symbol to wWinMainCRTStartup.

#include <string>

#ifdef _UNICODE
 typedef std::wstring _TSTRING;
#else
 typedef std::string  _TSTRING;
#endif
