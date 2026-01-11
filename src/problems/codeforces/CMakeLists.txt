set(SUB_TYPE "codeforces")
subdirlist(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR})

foreach (subdir ${SUBDIRS})
    add_subdirectory(${subdir})
endforeach ()