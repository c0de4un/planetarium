# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMAKE
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# CMake Version
include( "cmake/constants.cmake" )
cmake_minimum_required( VERSION ${PROJECT_CMAKE_VERSION} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONFIGS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

include( "${APP_CMAKE_DIR}/globals.cmake" )
include( "${APP_CMAKE_DIR}/platform.cmake" )
include( "${APP_CMAKE_DIR}/build_types.cmake" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# PROJECT
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

project( "Orbit" VERSION ${APP_VERSION} LANGUAGES C CXX )

# Enable Position Independent Code
set( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON )
set( CMAKE_POSITION_INDEPENDENT_CODE ON )

# C++ Version
set ( CMAKE_CXX_STANDARD ${CXX_VERSION} )
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# MODULES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# App.Core
include( "${APP_SRC_DIR}/core/module.cmake" )

# App.Platform
include( "${APP_SRC_DIR}/${PLATFORM}/module.cmake" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# BUILD
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

include( "${APP_SRC_DIR}/${PLATFORM}/build.cmake" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# LIBRARIES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Import and Link with libraries
include( "${APP_CMAKE_DIR}/${PLATFORM}_libs.cmake" )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
