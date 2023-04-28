# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONSTANTS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ENGINE_WIN_DIR "${ENGINE_SRC_DIR}/windows" )
set( ENGINE_WIN_PUBLIC_DIR "${ENGINE_WIN_DIR}/public/orbit/windows/" )
set( ENGINE_WIN_PRIVATE_DIR "${ENGINE_WIN_DIR}/private/orbit/windows/" )
set( ENGINE_WIN_PUBLIC_INCLUDE_DIR "${ENGINE_WIN_DIR}/public" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# HEADERS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ENGINE_HEADERS
    # GRAPHICS
    "${ENGINE_WIN_PUBLIC_DIR}graphics/WinGraphics.hpp"
    ${ENGINE_HEADERS}
)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ENGINE_SOURCES
    # GRAPHICS
    "${ENGINE_WIN_PRIVATE_DIR}graphics/WinGraphics.cpp"
    ${ENGINE_SOURCES}
)

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
