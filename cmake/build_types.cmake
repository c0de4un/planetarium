# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

if ( NOT DEFINED APP_BUILD_TYPES )
    if ( ${CMAKE_BUILD_TYPE} STREQUAL "Debug" )
        message ( STATUS "${PROJECT_NAME} - DEBUG-Mode enabled" )

        set ( APP_BUILD_TYPE "debug" )
        set ( APP_DEBUG ON )
        add_definitions ( -DAPP_DEBUG=1 )
    else ( ${CMAKE_BUILD_TYPE} STREQUAL "Debug" )
        message ( STATUS "${PROJECT_NAME} - DEBUG-Mode disabled" )

        set ( APP_BUILD_TYPE "release" )
        set ( APP_DEBUG OFF )
        add_definitions ( -DAPP_DEBUG=0 )
    endif ( ${CMAKE_BUILD_TYPE} STREQUAL "Debug" )

    set( NOT DEFINED APP_BUILD_TYPES TRUE )
endif ( NOT DEFINED APP_BUILD_TYPES )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
