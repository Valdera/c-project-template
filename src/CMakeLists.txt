############
# Warnings #
############

if(ENABLE_WARNINGS)
  include(Warnings)
endif()

################
# Subdirectory #
################

add_subdirectory(libs)
add_subdirectory(apps)
