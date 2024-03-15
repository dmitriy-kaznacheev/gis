find_package(
	Boost 
	COMPONENTS unit_test_framework 
	REQUIRED
)

include_directories(
	${CMAKE_SOURCE_DIR}/src/objects
	${Boost_INCLUDE_DIRS}
)

#--- geometry distance ---------------------

add_executable(
        test_geom_distance
        test_geom_distance.cpp
)

target_link_libraries(
        test_geom_distance
        ${Boost_LIBRARIES}
)

add_test(
        NAME geometry_distance
        COMMAND test_geom_distance
)

#--- geometry area -------------------------

add_executable(
        test_geom_area
        test_geom_area.cpp
)

target_link_libraries(
        test_geom_area
        ${Boost_LIBRARIES}
)

add_test(
        NAME geometry_area
        COMMAND test_geom_area
)

#--- geometry position ---------------------

add_executable(
        test_geom_position
        test_geom_position.cpp
)

target_link_libraries(
        test_geom_position
        ${Boost_LIBRARIES}
)

add_test(
        NAME geometry_position
        COMMAND test_geom_position
)
