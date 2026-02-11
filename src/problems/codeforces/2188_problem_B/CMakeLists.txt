get_filename_component(TITLE ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_definitions(-DSRC_PATH="${CMAKE_CURRENT_SOURCE_DIR}/data")

set(APP_NAME "${TYPE}-${SUB_TYPE}-${TITLE}")
set(APP_STATIC "${APP_NAME}_static")
set(APP_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/build")

add_library(${APP_STATIC} STATIC ${APP_SOURCES})

target_include_directories(${APP_STATIC} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
        ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(${APP_NAME} ${APP_SOURCES})

target_link_libraries(${APP_NAME} PRIVATE ${APP_STATIC})

add_custom_target(run_${APP_NAME}
        COMMAND ./${APP_NAME}
        DEPENDS ${APP_NAME})



