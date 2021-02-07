cmake_minimum_required(VERSION 3.10)


project(hello_world)

set(CMAKE_CXX_STANDARD 14)

find_package(Boost 1.66.0 REQUIRED COMPONENTS unit_test_framework)

#=========================================================
# utils library
#=========================================================
add_library(utils src/utils/greetings.cpp)
set(UTILS_INCLUDE_DIR src/)
target_include_directories(utils PUBLIC "${UTILS_INCLUDE_DIR}")

#=========================================================
# hello executable
#=========================================================
add_executable(hello src/hello.cpp)
target_link_libraries(hello utils)
target_include_directories(hello PUBLIC "${UTILS_INCLUDE_DIR}")

#=========================================================
# good_bye executable
#=========================================================
add_executable(good_bye src/good_bye.cpp)
target_link_libraries(good_bye utils)

#=========================================================
# utils library tests
#=========================================================
add_executable(utils_test test/utils/test.cpp)
target_link_libraries(utils_test utils ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
target_include_directories(hello PUBLIC "${UTILS_INCLUDE_DIR}" "${Boost_INCLUDE_DIRS}")
