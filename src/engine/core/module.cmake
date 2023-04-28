# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# CONSTANTS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ENGINE_CORE_DIR "${ENGINE_SRC_DIR}/core" )
set( ENGINE_CORE_PUBLIC_DIR "${ENGINE_CORE_DIR}/public/orbit/core/" )
set( ENGINE_CORE_PRIVATE_DIR "${ENGINE_CORE_DIR}/private/orbit/core/" )
set( ENGINE_CORE_PUBLIC_INCLUDE_DIR "${ENGINE_CORE_DIR}/public" )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# HEADERS
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ENGINE_HEADERS
    # CONFIGS
    # ECS
    "${ENGINE_CORE_PUBLIC_DIR}ecs/ISystem.hxx"
    # GRAPHICS
    "${ENGINE_CORE_PUBLIC_DIR}graphics/Graphics.hpp"
    ${ENGINE_HEADERS} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ENGINE_SOURCES
    # GRAPHICS
    "${ENGINE_CORE_PRIVATE_DIR}graphics/Graphics.cpp"
    ${ENGINE_SOURCES} )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
