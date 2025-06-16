include(GoogleTest)

add_executable(apriltag_tests
    apriltag_tests.cpp
)

set_target_properties(apriltag_tests PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/tests
)

target_link_libraries(apriltag_tests
    PRIVATE
        TagFinder::apriltag
        GTest::gtest_main
        GTest::gmock
)

set_project_warnings(apriltag_tests)
enable_sanitizers(apriltag_tests)

gtest_discover_tests(apriltag_tests
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin/tests
    PROPERTIES LABELS "unit"
)