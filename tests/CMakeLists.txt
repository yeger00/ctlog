set(CMAKE_CXX_FLAGS "-Wall -Wextra -O3")

add_executable (tests tests.cc)
target_link_libraries (tests CTLog)

find_package(Catch2 REQUIRED)
target_link_libraries(tests Catch2::Catch2)
