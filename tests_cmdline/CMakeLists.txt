cmake_minimum_required( VERSION 2.6 )
project( Test )

# Additional compiler flags
add_definitions( -Wall -g -O0 )

#'Other' documentation files
#set( DOC_FILES AUTHORS NEWS README )
#set( DOC_PATH "share/doc/board_control-0.1" )
#install( FILES ${DOC_FILES}
#		DESTINATION ${DOC_PATH} )


# The version number
#set( Tutorial_VERSION_MAJOR 1 )
#set( Tutorial_VERSION_MINOR 0 )

# Configure a header file to pass some of the CMake settings to the source code
#configure_file(
#	"${PROJECT_SOURCE_DIR}/board_control.h"
#	"${PROJECT_BINARY_DIR}/board_control.h"
#)

# Add the binary tree to the search path for include files so that we will find BoardControl_Config.h
#include_directories( "${PROJECT_BINARY_DIR}" )

#Generate a list with source files
#file( GLOB_RECURSE
#     source_files
#     src/*
#)

# Add the executable
add_executable( Test 
				board_control.h
				board_control_test.c
				check_arguments.h
				check_arguments.c
				parse_command_line.h
				parse_command_line.c
				open_port.c
		 )

# Add the install targets
#install ( TARGETS Test 
#		 DESTINATION bin )
#install( FILES "${PROJECT_BINARY_DIR}/board_control.h" 
#		 DESTINATION include )


# tests 
# Does the application run ?


# Does the usage message work ?

	
	

# Build a CPack driven installer package
#include(InstallRequiredSystemLibrairies)
#set (CPACK_RESOURCE_FILE_LICENSE
#	"${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
#set (CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
#set (CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
#include (CPAck)	
	
# Automatically create manpages/documentation with Doxygen
# check if doxygen is even installed
#find_package( Doxygen )
#if ( DOXYGEN_FOUND STREQUAL "NO" )
#    message( FATAL_ERROR "Doxygen not found. Please get a copy http://www.doxygen.org" )
#endif ( DOXYGEN_FOUND STREQUAL "NO" )

# prepare doxygen configuration file
#configure_file( ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile )

# add doxygen as target
#add_custom_target(d oxygen ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile )

# cleanup $build/api-doc on "make clean"
#set_property( DIRECTORY APPEND PROPERTY
#	          ADDITIONAL_MAKE_CLEAN_FILES api-doc )

# add doxygen as dependency to doc-target
#get_target_property( DOC_TARGET doc TYPE )
#if( NOT DOC_TARGET  )
#	add_custom_target( doc )
#endif()
#add_dependencies( doc doxygen )

# install HTML API documentation and manual pages
#set( DOC_PATH "share/doc/${CPACK_PACKAGE_NAME}-${VERSION}" )

#install( DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/api-doc/html
 #        DESTINATION ${DOC_PATH} )

# install man pages into packages, scope is now project root..
#install( DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/api-doc/man/man3
#         DESTINATION share/man/man3/ ) 
