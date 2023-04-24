# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONSTANTS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( APP_WIN_DIR "${APP_SRC_DIR}/windows" )
set( APP_WIN_PUBLIC_DIR "${APP_WIN_DIR}/public/orbit/windows/" )
set( APP_WIN_PRIVATE_DIR "${APP_WIN_DIR}/private/orbit/windows/" )
set( APP_WIN_PUBLIC_INCLUDE_DIR "${APP_WIN_DIR}/public" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# HEADERS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( APP_HEADERS
    "${APP_WIN_PUBLIC_DIR}main.hpp"
    ${APP_HEADERS}
)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( APP_SOURCES
    "${APP_WIN_PRIVATE_DIR}main.cpp"
    ${APP_SOURCES}
)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# RESOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( APP_RESOURCES "${APP_RES_DIR}/win/win_res.rc" )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
