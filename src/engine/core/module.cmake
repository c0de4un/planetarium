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
    "${ENGINE_CORE_PUBLIC_DIR}cfg/orbit_debug.hpp"
    # LOG
    "${ENGINE_CORE_PUBLIC_DIR}log/Log.hpp"
    "${ENGINE_CORE_PUBLIC_DIR}log/ILogger.hxx"
    "${ENGINE_CORE_PUBLIC_DIR}log/ConsoleLogger.hpp"
    # ECS
    "${ENGINE_CORE_PUBLIC_DIR}ecs/IEntity.hxx"
    "${ENGINE_CORE_PUBLIC_DIR}ecs/Entity.hpp"
    "${ENGINE_CORE_PUBLIC_DIR}ecs/ISystem.hxx"
    "${ENGINE_CORE_PUBLIC_DIR}ecs/System.hpp"
    # GRAPHICS
    "${ENGINE_CORE_PUBLIC_DIR}graphics/Graphics.hpp"
    # RENDER
    "${ENGINE_CORE_PUBLIC_DIR}render/IRenderer.hxx"
    "${ENGINE_CORE_PUBLIC_DIR}render/RenderSystem.hpp"
    "${ENGINE_CORE_PUBLIC_DIR}render/RenderSystemProvider.hpp"
    # GAME
    "${ENGINE_CORE_PUBLIC_DIR}game/IGame.hxx"
    "${ENGINE_CORE_PUBLIC_DIR}game/Game.hpp"
    ${ENGINE_HEADERS} )

# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
# SOURCES
# - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

set( ENGINE_SOURCES
    # LOG
    "${ENGINE_CORE_PRIVATE_DIR}log/Log.cpp"
    "${ENGINE_CORE_PRIVATE_DIR}log/ConsoleLogger.cpp"
    # ECS
    "${ENGINE_CORE_PRIVATE_DIR}ecs/Entity.cpp"
    "${ENGINE_CORE_PRIVATE_DIR}ecs/System.cpp"
    # GRAPHICS
    "${ENGINE_CORE_PRIVATE_DIR}graphics/Graphics.cpp"
    # RENDER
    "${ENGINE_CORE_PRIVATE_DIR}render/RenderSystem.cpp"
    "${ENGINE_CORE_PRIVATE_DIR}render/RenderSystemProvider.cpp"
    # GAME
    "${ENGINE_CORE_PRIVATE_DIR}game/Game.cpp"
    ${ENGINE_SOURCES} )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
