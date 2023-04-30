# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONSTANTS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ENGINE_GL_DIR "${ENGINE_SRC_DIR}/gl" )
set( ENGINE_GL_PUBLIC_DIR "${ENGINE_GL_DIR}/public/orbit/gl/" )
set( ENGINE_GL_PRIVATE_DIR "${ENGINE_GL_DIR}/private/orbit/gl/" )
set( ENGINE_GL_PUBLIC_INCLUDE_DIR "${ENGINE_GL_DIR}/public" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONFIGS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

add_definitions( -DORBIT_GL_ENABLED=1 )
add_definitions( -DORBIT_GL_MAJOR=3 )
add_definitions( -DORBIT_GL_MINOR=0 )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# HEADERS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ENGINE_HEADERS
    # CONFIG
    "${ENGINE_GL_PUBLIC_DIR}/config/orbit_gl.hpp"
    # RENDER
    "${ENGINE_GL_PUBLIC_DIR}/render/GLRenderer.hpp"
    ${ENGINE_HEADERS}
)

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ENGINE_SOURCES
    # RENDER
    "${ENGINE_GL_PRIVATE_DIR}/render/GLRenderer.cpp"
    ${ENGINE_SOURCES}
)

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
