# ----------------------------------------- #
# Summary:      Local, generic plugin setup #
# Copyright (c) 2026 Kupofty                #
# License:      GPLv3+                      #
# ----------------------------------------- #

# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.


# -------- Options ----------
set(OCPN_TEST_REPO
    "opencpn/nmeagenerator-alpha"
    CACHE STRING "Default repository for untagged builds"
)
set(OCPN_BETA_REPO
    "opencpn/nmeagenerator-beta"
    CACHE STRING
    "Default repository for tagged builds matching 'beta'"
)
set(OCPN_RELEASE_REPO
    "opencpn/nmeagenerator-prod"
    CACHE STRING
    "Default repository for tagged builds not matching 'beta'"
)


# ------- Plugin setup --------
set(PKG_NAME nmeagenerator_pi)
set(PKG_VERSION  1.0.0)
set(PKG_PRERELEASE "") # Empty, or a tag like 'beta'

set(DISPLAY_NAME NmeaGenerator)    # Dialogs, installer artifacts, ...
set(PLUGIN_API_NAME NmeaGenerator) # As of GetCommonName() in plugin API
set(PKG_SUMMARY "NMEA generator plugin for OpenCPN")
set(PKG_DESCRIPTION "Generate and send custom NMEA sentences for testing and debugging")
set(PKG_AUTHOR "Kupofty")
set(PKG_IS_OPEN_SOURCE "yes")
set(PKG_HOMEPAGE https://github.com/Kupofty/NmeaGenerator_pi)
set(PKG_INFO_URL https://github.com/Kupofty/NmeaGenerator_pi)



# ------- Code sources --------
set(SRC
    # OCPN plugin
    ${CMAKE_SOURCE_DIR}/src/nmeagenerator_plugin.h
    ${CMAKE_SOURCE_DIR}/src/nmeagenerator_plugin.cpp

    # Shared variables
    ${CMAKE_SOURCE_DIR}/src/globals.h
    ${CMAKE_SOURCE_DIR}/src/globals.cpp

    # Main UI
    ${CMAKE_SOURCE_DIR}/src/main_ui_base.h
    ${CMAKE_SOURCE_DIR}/src/main_ui_base.cpp

    ${CMAKE_SOURCE_DIR}/src/main_ui_derived.h
    ${CMAKE_SOURCE_DIR}/src/main_ui_derived.cpp

    # Settings UI
    ${CMAKE_SOURCE_DIR}/src/settings_ui_base.h
    ${CMAKE_SOURCE_DIR}/src/settings_ui_base.cpp

    ${CMAKE_SOURCE_DIR}/src/settings_ui_derived.h
    ${CMAKE_SOURCE_DIR}/src/settings_ui_derived.cpp
)
set (SOURCE_FILES ${SRC})



# ------- Settings --------

# Set API version
set(PKG_API_LIB api-20)  

# Late initialization
macro(late_init)
  if (APPLE)
    target_compile_definitions(${PACKAGE_NAME} PUBLIC OCPN_GHC_FILESYSTEM)
  endif ()
endmacro ()

# Add plugin libraries
macro(add_plugin_libraries)
    add_subdirectory(opencpn-libs/nmea0183)
    target_link_libraries(${PACKAGE_NAME} ocpn::nmea0183)
endmacro ()
