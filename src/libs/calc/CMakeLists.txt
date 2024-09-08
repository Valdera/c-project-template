set(LIBRARY_OBJECT "calc_obj")
set(LIBRARY_SHARED "calc_shared")
set(LIBRARY_STATIC "calc_static")

# Define source files for the library
set(LIBRARY_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/calc.cpp"
)

# Define header files for the library
set(LIBRARY_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/include/calc/calc.hpp"
)

# Specify include directories for the object library
set(LIBRARY_INCLUDES
    "./"
    include
    "${CMAKE_BINARY_DIR}/configured_files/include"
)

# Specify include directories for the object library
add_library(${LIBRARY_OBJECT} OBJECT ${LIBRARY_SOURCES} ${LIBRARY_HEADERS})
target_include_directories(${LIBRARY_OBJECT} PUBLIC ${LIBRARY_INCLUDES})
target_include_directories(${LIBRARY_OBJECT} INTERFACE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
)

set_target_properties(${LIBRARY_OBJECT} PROPERTIES
    PUBLIC_HEADER ${LIBRARY_HEADERS}
    POSITION_INDEPENDENT_CODE 1
)

# Create a shared library target
add_library(${LIBRARY_SHARED} SHARED)
target_link_libraries(${LIBRARY_SHARED} ${LIBRARY_OBJECT})

# Create a static library target
add_library(${LIBRARY_STATIC} STATIC)
target_link_libraries(${LIBRARY_STATIC} ${LIBRARY_OBJECT})

target_set_warnings(
    TARGET
    ${LIBRARY_OBJECT}
    ENABLE
    ${ENABLE_WARNINGS}
    AS_ERRORS
    ${ENABLE_WARNINGS_AS_ERRORS})

if(${ENABLE_LTO})
  target_enable_lto(${LIBRARY_OBJECT} optimized)
endif()

if(${ENABLE_CLANG_TIDY})
  add_clang_tidy_to_target(${LIBRARY_OBJECT})
endif()
