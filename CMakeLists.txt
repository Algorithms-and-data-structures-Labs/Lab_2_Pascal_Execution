cmake_minimum_required(VERSION 3.20)

project(Lab_2)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

include_directories("include")

add_subdirectory(3rdparty)
add_subdirectory(app)
add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(test)
