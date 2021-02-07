cmake_minimum_required(VERSION 3.10)

project(hello_world)

add_library(utils src/utils/greetings.cpp)
set(UTILS_INCLUDE_DIR src/)
target_include_directories(utils PUBLIC "${UTILS_INCLUDE_DIR}")

add_executable(hello src/hello.cpp)
target_link_libraries(hello utils)
target_include_directories(hello PUBLIC "${UTILS_INCLUDE_DIR}")

add_executable(good_bye src/good_bye.cpp)
target_link_libraries(good_bye utils)
