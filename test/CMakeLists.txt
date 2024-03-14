find_package(
	Boost 
	COMPONENTS unit_test_framework 
	REQUIRED
)

include_directories(
	${CMAKE_SOURCE_DIR}/src/objects
	${Boost_INCLUDE_DIRS}
)

#--- point ---------------------------------

add_executable(
	test_point 
	test_point.cpp
)

target_link_libraries(
	test_point 
	${Boost_LIBRARIES}
)

add_test(
	NAME object_point 
	COMMAND test_point
)

#--- line ----------------------------------

add_executable(
        test_line
        test_line.cpp
)

target_link_libraries(
        test_line
        ${Boost_LIBRARIES}
)

add_test(
        NAME object_line
        COMMAND test_line
)

#--- polygon -------------------------------

add_executable(
        test_polygon
        test_polygon.cpp
)

target_link_libraries(
        test_polygon
        ${Boost_LIBRARIES}
)

add_test(
        NAME object_polygon
        COMMAND test_polygon
)
