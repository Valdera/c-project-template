set(UNIT_TEST_NAME "calc_console_test")

add_executable(${UNIT_TEST_NAME} tui_test.cpp)

target_link_libraries(${UNIT_TEST_NAME} PRIVATE
    ${GoogleTest_FRAMEWORK_LIBRARY}
    ftxui::screen
    calc_console_static
)

gtest_discover_tests(${UNIT_TEST_NAME})
add_test(NAME ${UNIT_TEST_NAME} COMMAND ${UNIT_TEST_NAME})

target_set_warnings(
    TARGET
    ${UNIT_TEST_NAME}
    ENABLE
    ${ENABLE_WARNINGS}
    AS_ERRORS
    ${ENABLE_WARNINGS_AS_ERRORS})
