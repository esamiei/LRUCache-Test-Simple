cmake_minimum_required(VERSION 3.2)

project(lrucache_project)

find_package(GTest REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include
                    ${GTEST_INCLUDE_DIRS})

add_executable(utest src/main)

target_link_libraries(utest ${GTEST_LIBRARIES} pthread)

