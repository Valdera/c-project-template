cmake_minimum_required(VERSION 3.22)

# Code Inject: Conan
set(CMAKE_PROJECT_TOP_LEVEL_INCLUDES "${CMAKE_SOURCE_DIR}/cmake/ConanProvider.cmake")

# Setup Project
project("C++ Project Template" VERSION 1.0.0 LANGUAGES C CXX)

##########################
# Global CMake variables #
##########################

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

###########
# Options #
###########

option(ENABLE_CPM "Whether to enable CPM" ON)
option(ENABLE_CONAN "Whether to enable Conan" ON)
option(ENABLE_VCPKG "Whether to enable VCPKG" OFF)
option(ENABLE_FETCH_CONTENT "Whether to enable FetchContent" OFF)
option(ENABLE_GIT_SUBMODULE "Whether to enable Git Submodule" ON)

option(ENABLE_WARNINGS "Enable to add warnings to a target." ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable to treat warnings as errors." OFF)

option(ENABLE_TESTING "Enable unit testing build." ON)
option(ENABLE_COVERAGE "Enable code coverage build." OFF)

option(ENABLE_INCLUDE_WHAT_YOU_USE "Enable to add iwyu." ON)
option(ENABLE_CLANG_TIDY "Enable to add clang tidy." ON)
option(ENABLE_CPPCHECK "Enable to add cppcheck." ON)

option(ENABLE_SANITIZE_ADDR "Enable to sanitize address (Unix only)." OFF)
option(ENABLE_SANITIZE_UNDEF "Enable to sanitize undefined (Unix only)." OFF)
option(ENABLE_LTO "Enable to add Link Time Optimization." ON)

option(ENABLE_CLANG_FORMAT "Enable to add clang-format." ON)
option(ENABLE_CMAKE_FORMAT "Enable to add cmake-format." ON)

# Disable this on gcov <= 13
option(ENABLE_COV_IGNORE_ERRORS "Enable LCOV ignore errors arguments." ON)

#################
# CMake Modules #
#################

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")
include(SubDirList)
include(Docs)
include(Tools)
include(ConfigSafeGuards)

##########
# Python #
##########

find_package(Python REQUIRED COMPONENTS Interpreter)
find_package(Python3 REQUIRED COMPONENTS Interpreter)
if (Python_FOUND)
    set(Python_EXECUTABLE ${Python_EXECUTABLE})
    set(Python3_EXECUTABLE ${Python3_EXECUTABLE})
endif ()

message(STATUS "Python Executable: ${Python_EXECUTABLE}")
message(STATUS "Python3 Executable: ${Python_EXECUTABLE}")

#############
# Formatter #
#############

add_cmake_format_target()
add_clang_format_target()

#################
# Code Coverage #
#################

if (ENABLE_COVERAGE)
    include(CodeCoverage)
    append_coverage_compiler_flags()
endif ()


#######
# LTO #
#######

if (ENABLE_LTO)
    include(LTO)
endif ()

#############
# Sanitizer #
#############

if (ENABLE_SANITIZE_ADDR OR ENABLE_SANITIZE_UNDEF)
    include(Sanitizer)
    add_sanitizer_flags()
endif ()

###########################
# External Lib: Submodule #
###########################

# Example:
# add_git_submodule(external/<lib name>)

if (ENABLE_GIT_SUBMODULE)
    message(STATUS "Using Git Submodule")
    include(AddGitSubmodule)
endif ()

###############################
# External Lib: Fetch Content #
###############################

# Example:
# FetchContent_Declare(
#        <package name>
#        GIT_REPOSITORY <git repository url>
#        GIT_TAG <git tag version>
#        GIT_SHALLOW TRUE)
# FetchContent_MakeAvailable(<package name>)

if (ENABLE_FETCH_CONTENT)
    message(STATUS "Using Fetch Content")
    include(FetchContent)
endif ()

#####################
# External Lib: CPM #
#####################

# Example:
# cpmaddpackage("gh:<git username>:<git repo name>#<version number>")

if (ENABLE_CPM)
    message(STATUS "Using CPM")
    include(CPM)
endif ()

#######################
# External Lib: Conan #
#######################

if (ENABLE_CONAN)
    message(STATUS "Using Conan")
    include(${CMAKE_BINARY_DIR}/conan/conan_toolchain.cmake)
endif ()

#######################
# External Lib: VCPKG #
#######################

if (ENABLE_VCPKG)
    message(STATUS "Using VCPKG")
    include(${CMAKE_SOURCE_DIR}/external/vcpkg/scripts/buildsystems/vcpkg.cmake)
endif ()

###############################
# Lists all required packages #
###############################

find_package(nlohmann_json REQUIRED)
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)
find_package(cxxopts REQUIRED)
find_package(ftxui REQUIRED)

################
# Subdirectory #
################

add_subdirectory(config)
add_subdirectory(external)
add_subdirectory(src)


################
# Unit Testing #
################

if (ENABLE_TESTING)
    message(STATUS "Build unit tests for the project. Tests should always be found in the test folder\n")
    include(CPM)
    CPMAddPackage("gh:google/googletest#v1.15.2")
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

    add_subdirectory(test)
endif ()
