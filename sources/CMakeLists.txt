cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (NOT UNIX)
    message(FATAL_ERROR "Not Unix!")
endif()


option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTS "Build tests " OFF)
option(BUILD_BENCHS "Build benchmarks" OFF)

project(BSTree)
set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
set(EXAMPLES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../examples)
set(TESTS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../tests)
set(BENCHS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../bench)

add_library(TUI STATIC ${CMAKE_CURRENT_SOURCE_DIR}/TUI.cpp)
#add_library(Tree STATIC ${CMAKE_CURRENT_SOURCE_DIR}/../include/BSTree.hpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include/)

# main program
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} TUI)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../include/ DESTINATION include)
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
#install(EXPORT Tree-config DESTINATION cmake)
#install(EXPORT TUI-config DESTINATION cmake)
#install(TARGETS TUI Tree EXPORT TUI-config Tree-config ARCHIVE DESTINATION lib LIBRARY DESTINATION lib)
install(TARGETS TUI ARCHIVE DESTINATION lib LIBRARY DESTINATION lib)


# examples
if(BUILD_EXAMPLES)
    file(GLOB EXAMPLE_SOURCES ${EXAMPLES_DIR}/*.cpp)
    foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
        get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
        add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
        target_link_libraries(${EXAMPLE_NAME} TUI)
        install(TARGETS ${EXAMPLE_NAME} DESTINATION bin)
    endforeach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
endif()

# tests
if(BUILD_TESTS)
    enable_testing()
    file(GLOB TEST_SOURCES ${TESTS_DIR}/*.cpp)
    add_executable(check ${TEST_SOURCES})
    target_link_libraries(check TUI)
    add_test(NAME check COMMAND check "-s" "-r" "compact" "--use-colour" "yes") 
endif()

# benchmark
if(BUILD_BENCHS)
    enable_testing()
    file(GLOB BENCH_SOURCES ${BENCHS_DIR}/*.cpp)
    add_executable(bench ${BENCH_SOURCES})
    target_link_libraries(bench TUI ${DEPENDS_LIBRARIES})
    add_test(NAME bench COMMAND bench "-s" "-r" "compact" "--use-colour" "yes" "--durations" "yes") 
endif()