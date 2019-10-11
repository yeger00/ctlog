cmake_minimum_required (VERSION 3.5)
project (CTLog)

add_library(CTLog INTERFACE)
target_include_directories(CTLog
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

add_subdirectory(examples)

if(BUILD_TESTING)
enable_testing()
add_subdirectory(tests)
endif()
