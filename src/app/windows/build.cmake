# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

# Add Executable Object
add_executable(orbit ${APP_HEADERS} ${APP_SOURCES} ${APP_RESOURCES})
set( BUILD_TARGET orbit )

# Configure Executable-Object
set_target_properties ( orbit PROPERTIES
    VERSION ${PROJECT_VERSION}
    RUNTIME_OUTPUT_DIRECTORY "${APP_BIN_OUTPUT_DIR}" )

# Link with App.Core Headers
target_include_directories( orbit PUBLIC "${APP_CORE_PUBLIC_INCLUDE_DIR}" )

# Link with App.Windows Headers
target_include_directories( orbit PUBLIC "${APP_WIN_PUBLIC_INCLUDE_DIR}" )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
