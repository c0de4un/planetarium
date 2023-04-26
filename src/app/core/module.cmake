# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONSTANTS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( APP_CORE_DIR "${APP_SRC_DIR}/core" )
set( APP_CORE_PUBLIC_DIR "${APP_CORE_DIR}/public/orbit/core/" )
set( APP_CORE_PRIVATE_DIR "${APP_CORE_DIR}/private/orbit/core/" )
set( APP_CORE_PUBLIC_INCLUDE_DIR "${APP_CORE_DIR}/public" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# HEADERS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( APP_HEADERS
    # CONFIGS
    "${APP_CORE_PUBLIC_DIR}cfg/orbit_gl.hpp"
    # GRAPHICS
    "${APP_CORE_PUBLIC_DIR}graphics/Graphics.hpp"
    ${APP_HEADERS} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( APP_SOURCES
    # GRAPHICS
    "${APP_CORE_PRIVATE_DIR}graphics/Graphics.cpp"
    ${APP_SOURCES} )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
