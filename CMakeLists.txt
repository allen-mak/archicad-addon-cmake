cmake_minimum_required (VERSION 3.16)

include (Tools/CMakeCommon.cmake)

function (LinkACAP_STATLibraries target ac_version)
	if (${ac_version} GREATER_EQUAL "27")
		if (WIN32)
			target_link_libraries (AddOn
				"$<$<CONFIG:Debug>:${AC_API_DEVKIT_DIR}/Lib/ACAP_STATD.lib>"
				"$<$<CONFIG:Release>:${AC_API_DEVKIT_DIR}/Lib/ACAP_STAT.lib>"
				"$<$<CONFIG:RelWithDebInfo>:${AC_API_DEVKIT_DIR}/Lib/ACAP_STAT.lib>"
			)
		else ()
			target_link_libraries (AddOn
				"${AC_API_DEVKIT_DIR}/Lib/libACAP_STAT.a"
			)
		endif ()
	else ()
		if (WIN32)
			target_link_libraries (AddOn
				"$<$<CONFIG:Debug>:${AC_API_DEVKIT_DIR}/Lib/Win/ACAP_STATD.lib>"
				"$<$<CONFIG:Release>:${AC_API_DEVKIT_DIR}/Lib/Win/ACAP_STAT.lib>"
				"$<$<CONFIG:RelWithDebInfo>:${AC_API_DEVKIT_DIR}/Lib/Win/ACAP_STAT.lib>"
			)
		else ()
			target_link_libraries (AddOn
				"${AC_API_DEVKIT_DIR}/Lib/Mactel/libACAP_STAT.a"
			)
		endif ()
	endif ()
endfunction ()

set (API_DEVKIT_DIR $ENV{AC_API_DEVKIT_DIR})

if (GITHUB_BUILD)
	include(${CMAKE_BINARY_DIR}/conan_paths.cmake)
	set (API_DEVKIT_DIR ${CONAN_ARCHICAD-APIDEVKIT_ROOT}/bin)
endif ()

set_property (GLOBAL PROPERTY USE_FOLDERS ON)

set (CMAKE_CONFIGURATION_TYPES Debug;Release;RelWithDebInfo)
set (AC_API_DEVKIT_DIR ${API_DEVKIT_DIR} CACHE PATH "API DevKit directory.")
set (AC_ADDON_NAME "ExampleAddOn" CACHE STRING "Add-On name.")
set (AC_ADDON_LANGUAGE "INT" CACHE STRING "Add-On language code.")
set (AC_MDID_DEV "1" CACHE STRING "Your Developer ID.")
set (AC_MDID_LOC "1" CACHE STRING "Add-On Local ID.")

project (${AC_ADDON_NAME})

DetectACVersion (${AC_API_DEVKIT_DIR} ACVersion)
message (STATUS "Archicad Version: ${ACVersion}")

set (AddOnFolder .)
SetGlobalCompilerDefinitions ()
GenerateAddOnProject (${ACVersion} ${AC_API_DEVKIT_DIR} ${AC_ADDON_NAME} ${AddOnFolder} ${AC_ADDON_LANGUAGE})
