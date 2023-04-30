# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONSTANTS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( APP_CORE_DIR "${APP_SRC_DIR}/core" )
set( APP_CORE_PUBLIC_DIR "${APP_CORE_DIR}/public/core/" )
set( APP_CORE_PRIVATE_DIR "${APP_CORE_DIR}/private/core/" )
set( APP_CORE_PUBLIC_INCLUDE_DIR "${APP_CORE_DIR}/public" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# HEADERS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set(APP_HEADERS
    # GAME
    "${APP_CORE_PUBLIC_DIR}game/OrbitGame.hpp"
    ${APP_HEADERS}
)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set(APP_SOURCES
    # GAME
    "${APP_CORE_PRIVATE_DIR}game/OrbitGame.cpp"
    ${APP_SOURCES}
)

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
