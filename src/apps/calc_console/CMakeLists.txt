set(APP_NAME "calc_console")
set(APP_STATIC "calc_console_static")

# Define the source files for the static app
set(APP_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/tui.cpp"
)

# Define header files for the static app
set(APP_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/tui/tui.hpp"
)

# Specify include directories for the static app
set(APP_INCLUDES
    "./"
    include
    "${CMAKE_BINARY_DIR}/configured_files/include"
)

# Create a static app with the specified sources
add_library(${APP_STATIC} STATIC ${APP_SOURCES} ${APP_HEADERS})

# Specify include directories for the static app
target_include_directories(${APP_STATIC} PUBLIC ${APP_INCLUDES})

# Precompile headers for the static app
target_precompile_headers(${APP_STATIC} PUBLIC <string>)

# Link the static app with other required libraries for the application
target_link_libraries(${APP_STATIC} PUBLIC
    calc_shared
    ftxui::screen
    ftxui::dom
    ftxui::component
)

# Add the executable target with its source file
add_executable(${APP_NAME} main.cpp)
target_link_libraries(${APP_NAME} ${APP_STATIC})

target_set_warnings(
    TARGET
    ${APP_STATIC}
    ENABLE
    ${ENABLE_WARNINGS}
    AS_ERRORS
    ${ENABLE_WARNINGS_AS_ERRORS})

target_set_warnings(
    TARGET
    ${APP_NAME}
    ENABLE
    ${ENABLE_WARNINGS}
    AS_ERRORS
    ${ENABLE_WARNINGS_AS_ERRORS})

if(${ENABLE_LTO})
  target_enable_lto(${APP_STATIC} optimized)
  target_enable_lto(${APP_NAME} optimized)
endif()

if(${ENABLE_CLANG_TIDY})
  add_clang_tidy_to_target(${APP_NAME})
endif()
