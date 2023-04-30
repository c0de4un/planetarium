# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# Append Engine Headers & Sources
set( APP_HEADERS ${ENGINE_HEADERS} ${APP_HEADERS} )
set( APP_SOURCES ${ENGINE_SOURCES} ${APP_SOURCES} )

# Add Executable Object
add_executable(orbit ${APP_HEADERS} ${APP_SOURCES} ${APP_RESOURCES})
set( BUILD_TARGET orbit )

# Configure Executable-Object
set_target_properties ( orbit PROPERTIES
    VERSION ${PROJECT_VERSION}
    RUNTIME_OUTPUT_DIRECTORY "${APP_BIN_OUTPUT_DIR}" )

# Link with GLM
target_include_directories( orbit PUBLIC "${GLM_INCLUDE_DIR}" )

# Link with Engine.Core
target_include_directories( orbit PUBLIC "${ENGINE_CORE_PUBLIC_INCLUDE_DIR}" )

# Link with Engine.GL
target_include_directories( orbit PUBLIC "${ENGINE_GL_PUBLIC_INCLUDE_DIR}" )

# Link with Engine.Windows
target_include_directories( orbit PUBLIC "${ENGINE_WIN_PUBLIC_INCLUDE_DIR}" )

# Link with App.Core Headers
target_include_directories( orbit PUBLIC "${APP_CORE_PUBLIC_INCLUDE_DIR}" )

# Link with App.Windows Headers
target_include_directories( orbit PUBLIC "${APP_WIN_PUBLIC_INCLUDE_DIR}" )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
