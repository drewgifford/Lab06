cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library (applibrary Tree.cpp Node.cpp)
 
# Link runTests with what we want to test and the GTest and pthread library
target_link_libraries(applibrary) 

add_executable(runMain main.cpp)
target_link_libraries(runMain applibrary)