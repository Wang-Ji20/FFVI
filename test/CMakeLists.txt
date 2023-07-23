include_directories(${PROJECT_SOURCE_DIR}/third_party/googletest/googletest/include)

include(GoogleTest)

add_custom_target(build-tests COMMAND ${CMAKE_CTEST_COMMAND} --show-only)
add_custom_target(check-tests COMMAND ${CMAKE_CTEST_COMMAND} --verbose)

file(GLOB_RECURSE FFVI_TEST_SOURCES "${PROJECT_SOURCE_DIR}/test/*/*test.cc")

message(STATUS "Found ${FFVI_TEST_SOURCES} test sources: ${PROJECT_SOURCE_DIR}/test/")

foreach (FFVI_test_source ${FFVI_TEST_SOURCES})
    # Create a human readable name.
    get_filename_component(FFVI_test_filename ${FFVI_test_source} NAME)
    string(REPLACE ".cc" "" FFVI_test_name ${FFVI_test_filename})

    # Add the test target separately and as part of "make check-tests".
    add_executable(${FFVI_test_name} EXCLUDE_FROM_ALL ${FFVI_test_source})
    add_dependencies(build-tests ${FFVI_test_name})
    add_dependencies(check-tests ${FFVI_test_name})

    gtest_discover_tests(${FFVI_test_name}
            EXTRA_ARGS
            --gtest_color=auto
            --gtest_output=xml:${CMAKE_BINARY_DIR}/test/${FFVI_test_name}.xml
            --gtest_catch_exceptions=0
            DISCOVERY_TIMEOUT 120
            PROPERTIES
            TIMEOUT 120
            )

    target_link_libraries(${FFVI_test_name} FFVI gtest gmock_main)

    # Set test target properties and dependencies.
    set_target_properties(${FFVI_test_name}
            PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test"
            COMMAND ${FFVI_test_name}
            )
endforeach ()
