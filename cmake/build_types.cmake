# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

if ( NOT DEFINED ORBIT_BUILD_TYPES )
    if ( ${CMAKE_BUILD_TYPE} STREQUAL "Debug" )
        message ( STATUS "${PROJECT_NAME} - DEBUG-Mode enabled" )

        set ( ORBIT_BUILD_TYPE "debug" )
        set ( ORBIT_DEBUG ON )
        add_definitions ( -DORBIT_DEBUG=1 )
    else ( ${CMAKE_BUILD_TYPE} STREQUAL "Debug" )
        message ( STATUS "${PROJECT_NAME} - DEBUG-Mode disabled" )

        set ( ORBIT_BUILD_TYPE "release" )
        set ( ORBIT_DEBUG OFF )
        add_definitions ( -DORBIT_DEBUG=0 )
    endif ( ${CMAKE_BUILD_TYPE} STREQUAL "Debug" )

    set( NOT DEFINED ORBIT_BUILD_TYPES TRUE )
endif ( NOT DEFINED ORBIT_BUILD_TYPES )

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
