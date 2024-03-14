find_package(
	Boost 
	COMPONENTS unit_test_framework 
	REQUIRED
)

include_directories(
	${CMAKE_SOURCE_DIR}/src/objects
	${Boost_INCLUDE_DIRS}
)

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

