include(GoogleTest)

file(GLOB ALL_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
)

add_executable(camera_task_test
    ${ALL_SOURCES}
)

target_link_libraries(camera_task_test
    GTest::gtest_main
    GTest::gmock_main
    camera_task
)

target_include_directories(camera_task_test PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/mock
)

gtest_discover_tests(camera_task_test)