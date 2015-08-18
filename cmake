string(REGEX REPLACE "cmake$" "" ct_path ${CMAKE_CURRENT_LIST_FILE})

if (NOT TARGET ct)
  add_subdirectory(${ct_path} ct_build)
endif()
