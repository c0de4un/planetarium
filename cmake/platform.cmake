# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

if ( NOT DEFINED APP_PLATFORM_DETECTED )

    if ( WIN32 OR WIN64 OR MINGW OR MING32 OR MINGW64 OR CYGWIN OR CYGWIN64 OR MSYS OR CMAKE_SYSTEM_NAME STREQUAL "Windows" )
        # Windows
        set( PLATFORM "windows" )
        set( APP_WINDOWS ON )
        add_definitions( -DAPP_WINDOWS=1 )
    elseif ( ANDROID OR $CMAKE_SYSTEM_NAME STREQUAL "Android" )
        # Android
        set( PLATFORM "android" )
        set( APP_ANDROID ON )
        add_definitions( -DAPP_ANDROID=1 )
    elseif ( APPLE OR CMAKE_SYSTEM_NAME STREQUAL "Darwin" )
        # Mac
        set( PLATFORM "mac" )
        set( APP_MAC ON )
        add_definitions( -DAPP_MAC=1 )
    elseif ( LINUX OR UNIX OR CMAKE_SYSTEM_NAME STREQUAL "Linux" OR CMAKE_SYSTEM_NAME STREQUAL "FreeBSD" OR CMAKE_SYSTEM_NAME STREQUAL "CrayLinuxEnvironment" )
        # Linux
        set( PLATFORM "linux" )
        set( APP_LINUX ON )
        add_definitions( -DAPP_LINUX=1 )
    elseif ( IOS )
        set( PLATFORM "ios" )
        set( APP_IOS ON )
        add_definitions( -DAPP_IOS=1 )
    else ( WIN32 OR WIN64 OR MINGW OR MING32 OR MINGW64 OR CYGWIN OR CYGWIN64 OR MSYS OR CMAKE_SYSTEM_NAME STREQUAL "Windows" ) # WINDOWS
        message( FATAL_ERROR "${PROJECT_NAME} - failed to detect target-platform, configuration required" )
    endif ( WIN32 OR WIN64 OR MINGW OR MING32 OR MINGW64 OR CYGWIN OR CYGWIN64 OR MSYS OR CMAKE_SYSTEM_NAME STREQUAL "Windows" ) # WINDOWS

    message ( STATUS "${PROJECT_NAME} - platform is ${PLATFORM}" )

    set( APP_PLATFORM_DETECTED ON )
    add_definitions( -DAPP_PLATFORM_DEFINED=1 )

endif ( NOT DEFINED APP_PLATFORM_DETECTED )

if ( NOT DEFINED CPU_ARCHITECTURE_BIT )
    set( CPU_ARCHITECTURE_BIT "x64" )
    add_definitions( -DCPU_ARCHITECTURE_BIT=x64 )
    message( STATUS "${PROJECT_NAME} - CPU_ARCHITECTURE_BIT set to ${CPU_ARCHITECTURE_BIT} as default" )
endif ( NOT DEFINED CPU_ARCHITECTURE_BIT )

if ( NOT DEFINED CPU_ARCHITECTURE )
    set( CPU_ARCHITECTURE "amd" )
    add_definitions( -DCPU_ARCHITECTURE=amd )
    message( STATUS "${PROJECT_NAME} - CPU_ARCHITECTURE set to ${CPU_ARCHITECTURE} as default" )
endif ( NOT DEFINED CPU_ARCHITECTURE )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
