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

if ( NOT DEFINED ABI_ARCH )
    set( ABI_ARCH "x64" )
    add_definitions( -DABI_ARCH=x64 )
    message( STATUS "${PROJECT_NAME} - ABI-Architecture set to ${ABI_ARCH} as default" )
endif ( NOT DEFINED ABI_ARCH )

if ( NOT DEFINED ABI_FAMILY )
    set( ABI_FAMILY "amd" )
    add_definitions( -DABI_FAMILY=amd )
    message( STATUS "${PROJECT_NAME} - ABI-Family set to ${ABI_FAMILY} as default" )
endif ( NOT DEFINED ABI_FAMILY )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
