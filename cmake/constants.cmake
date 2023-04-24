# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CMake
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( PROJECT_CMAKE_VERSION 3.22.1 )
set( APP_VERSION 0.1.2 )
set(CXX_VERSION 17)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# DIRS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

# Project root
if (NOT DEFINED ROOT_DIR)
    set( ROOT_DIR ${CMAKE_SOURCE_DIR} )
endif (NOT DEFINED ROOT_DIR)

set(APP_SRC_DIR "${ROOT_DIR}/src")
set(APP_CMAKE_DIR "${ROOT_DIR}/cmake")

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
