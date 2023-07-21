#ifndef MIGRATIONUTILS_HPP
#define MIGRATIONUTILS_HPP

#include "ACAPinc.h"

#if defined (ServerMainVers_2700)
	const auto& Register_Menu = ACAPI_MenuItem_RegisterMenu;
	const auto& Install_MenuHandler = ACAPI_MenuItem_InstallMenuHandler;
#else
	const auto& Register_Menu = ACAPI_Register_Menu;
	const auto& Install_MenuHandler = ACAPI_Install_MenuHandler;
#endif

#endif
