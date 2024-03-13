cmake_minimum_required(	VERSION 3.14 )
project(
	GIS
	VERSION 1.0.0
	DESCRIPTION "GIS Algorithms"
	LANGUAGES CXX
)

set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )

set( CMAKE_CURRENT_BINARY_DIR       ${CMAKE_SOURCE_DIR}/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib )
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR} )

include_directories( ${CMAKE_SOURCE_DIR}/src/objects )

enable_testing()
add_subdirectory( ${CMAKE_SOURCE_DIR}/test )
