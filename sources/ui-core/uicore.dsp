# Microsoft Developer Studio Project File - Name="uicore" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102

CFG=uicore - Win32 UnicodeDebug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "uicore.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "uicore.mak" CFG="uicore - Win32 UnicodeDebug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "uicore - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "uicore - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "uicore - Win32 UnicodeDebug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "uicore - Win32 UnicodeRelease" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "uicore - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../../libraries"
# PROP Intermediate_Dir "../../intermediate/uicore/Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /G4 /MD /W3 /GX /O2 /I "../" /D "NDEBUG" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D "DDX_HELPERS_EXPORTS" /D "WIN32" /D "_WINDOWS" /D "XBROWSEFORFOLDER_EXPORTS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x419 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386 /out:"../../binaries/uicore.dll" /libpath:"../../libraries"

!ELSEIF  "$(CFG)" == "uicore - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../../libraries"
# PROP Intermediate_Dir "../../intermediate/uicore/Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_WINDLL" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /G4 /MDd /W3 /Gm /GX /ZI /Od /I "../" /D "_DEBUG" /D "_MBCS" /D "_AFXEXT" /D "DDX_HELPERS_EXPORTS" /D "WIN32" /D "_WINDOWS" /D "XBROWSEFORFOLDER_EXPORTS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /out:"../../binaries/uicore.dll" /pdbtype:sept /libpath:"../../libraries"

!ELSEIF  "$(CFG)" == "uicore - Win32 UnicodeDebug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "uicore___Win32_UnicodeDebug"
# PROP BASE Intermediate_Dir "uicore___Win32_UnicodeDebug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "../../libraries"
# PROP Intermediate_Dir "../../intermediate/uicore/UnicodeDebug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /G4 /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "_MBCS" /D "_AFXEXT" /D "DDX_HELPERS_EXPORTS" /D "WIN32" /D "_WINDOWS" /D "XBROWSEFORFOLDER_EXPORTS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /G4 /MDd /W3 /Gm /GX /ZI /Od /I "../" /D "_AFXEXT" /D "DDX_HELPERS_EXPORTS" /D "XBROWSEFORFOLDER_EXPORTS" /D "_DEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /out:"../../binaries/uicore.dll" /pdbtype:sept /libpath:"../../libraries"
# ADD LINK32 /nologo /subsystem:windows /dll /debug /machine:I386 /out:"../../binaries/uicore.dll" /pdbtype:sept /libpath:"../../libraries"

!ELSEIF  "$(CFG)" == "uicore - Win32 UnicodeRelease"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "uicore___Win32_UnicodeRelease"
# PROP BASE Intermediate_Dir "uicore___Win32_UnicodeRelease"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "../../libraries"
# PROP Intermediate_Dir "../../intermediate/uicore/UnicodeRelease"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /G4 /MD /W3 /GX /O2 /D "NDEBUG" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D "DDX_HELPERS_EXPORTS" /D "WIN32" /D "_WINDOWS" /D "XBROWSEFORFOLDER_EXPORTS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /G4 /MD /W3 /GX /O2 /I "../" /D "_WINDLL" /D "_AFXDLL" /D "_MBCS" /D "_AFXEXT" /D "DDX_HELPERS_EXPORTS" /D "XBROWSEFORFOLDER_EXPORTS" /D "NDEBUG" /D "_UNICODE" /D "WIN32" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x419 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x419 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /dll /machine:I386 /out:"../../binaries/uicore.dll" /libpath:"../../libraries"
# ADD LINK32 /nologo /subsystem:windows /dll /machine:I386 /out:"../../binaries/uicore.dll" /libpath:"../../libraries"

!ENDIF 

# Begin Target

# Name "uicore - Win32 Release"
# Name "uicore - Win32 Debug"
# Name "uicore - Win32 UnicodeDebug"
# Name "uicore - Win32 UnicodeRelease"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AnalogMeter.cpp
# End Source File
# Begin Source File

SOURCE=.\AnalogMeterCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\ddx_helpers.cpp
# End Source File
# Begin Source File

SOURCE=.\DialogWithAccelerators.cpp
# End Source File
# Begin Source File

SOURCE=.\EditEx.cpp
# End Source File
# Begin Source File

SOURCE=.\HeaderCtrlEx.cpp
# End Source File
# Begin Source File

SOURCE=.\HotKeysManager.cpp
# End Source File
# Begin Source File

SOURCE=.\HotKeysToCmdRouter.cpp
# End Source File
# Begin Source File

SOURCE=.\LEDIndicator.cpp
# End Source File
# Begin Source File

SOURCE=.\MPCLogoPane.cpp
# End Source File
# Begin Source File

SOURCE=.\MPCStatusBar.cpp
# End Source File
# Begin Source File

SOURCE=.\OScopeCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\ProgressCtrlEx.cpp
# End Source File
# Begin Source File

SOURCE=.\SpinButtonCtrlEx.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\TabController.cpp
# End Source File
# Begin Source File

SOURCE=.\TabDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\uicore.cpp
# End Source File
# Begin Source File

SOURCE=.\uicore.def
# End Source File
# Begin Source File

SOURCE=.\uicore.rc
# End Source File
# Begin Source File

SOURCE=.\UpdatableDialog.cpp
# End Source File
# Begin Source File

SOURCE=.\WndSubclasser.cpp
# End Source File
# Begin Source File

SOURCE=.\WndSubclasser.h
# End Source File
# Begin Source File

SOURCE=.\XBrowseForFolder.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AnalogMeter.h
# End Source File
# Begin Source File

SOURCE=.\AnalogMeterCtrl.h
# End Source File
# Begin Source File

SOURCE=.\ddx_helpers.h
# End Source File
# Begin Source File

SOURCE=.\DialogWithAccelerators.h
# End Source File
# Begin Source File

SOURCE=.\EditEx.h
# End Source File
# Begin Source File

SOURCE=.\HeaderCtrlEx.h
# End Source File
# Begin Source File

SOURCE=.\HotKeysManager.h
# End Source File
# Begin Source File

SOURCE=.\HotKeysToCmdRouter.h
# End Source File
# Begin Source File

SOURCE=.\ITabControllerEvent.h
# End Source File
# Begin Source File

SOURCE=.\LEDIndicator.h
# End Source File
# Begin Source File

SOURCE=.\MPCLogoPane.h
# End Source File
# Begin Source File

SOURCE=.\MPCStatusBar.h
# End Source File
# Begin Source File

SOURCE=.\OScopeCtrl.h
# End Source File
# Begin Source File

SOURCE=.\ProgressCtrlEx.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\SpinButtonCtrlEx.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\TabController.h
# End Source File
# Begin Source File

SOURCE=.\TabDialog.h
# End Source File
# Begin Source File

SOURCE=.\UpdatableDialog.h
# End Source File
# Begin Source File

SOURCE=.\XBrowseForFolder.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\uicore.rc2
# End Source File
# End Group
# End Target
# End Project
