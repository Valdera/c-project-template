#############
# Unit Test #
#############

include(CTest)
enable_testing()

include(GoogleTest)
set(GoogleTest_FRAMEWORK_LIBRARY gtest_main gmock)

################
# Subdirectory #
################

add_subdirectory(libs)
add_subdirectory(apps)

#################
# Code Coverage #
#################

set(COVERAGE_EXCLUDES
        "${PROJECT_SOURCE_DIR}/cmake/*"
        "${PROJECT_SOURCE_DIR}/docs/*"
        "${PROJECT_SOURCE_DIR}/external/*"
        "${PROJECT_SOURCE_DIR}/test/*"
        "${PROJECT_SOURCE_DIR}/build/*"
        "${PROJECT_SOURCE_DIR}/config/*"
        "${PROJECT_SOURCE_DIR}/cmake-build-*/*"
        "/*/include/*"
        "/home/*/.conan2"
)

if (ENABLE_COVERAGE)
    setup_target_for_coverage_lcov(
            NAME coverage
            EXECUTABLE ctest -j 4 --test-dir test
            DEPENDENCIES
            calc_test
            calc_console_test
    )
endif ()
