cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)

if (NOT UNIX)
    message(FATAL_ERROR "Not Unix!")
endif()


option(BUILD_EXAMPLES "Build examples" OFF)
option(BUILD_TESTS "Build tests " OFF)

project(BSTree)
set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
set(EXAMPLES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../examples)
set(TESTS_DIR ${${CMAKE_CURRENT_SOURCE_DIR}/../tests})

add_library(TUI STATIC ${CMAKE_CURRENT_SOURCE_DIR}/TUI.cpp)
add_library(Tree STATIC ${CMAKE_CURRENT_SOURCE_DIR}/BSTree.cpp)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include/)

# main program
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} TUI Tree)

#examples
if(BUILD_EXAMPLES)
    file(GLOB EXAMPLE_SOURCES ${EXAMPLES_DIR}/*.cpp)
    foreach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
        get_filename_component(EXAMPLE_NAME ${EXAMPLE_SOURCE} NAME_WE)
        add_executable(${EXAMPLE_NAME} ${EXAMPLE_SOURCE})
        target_link_libraries(${EXAMPLE_NAME} TUI Tree)
    endforeach(EXAMPLE_SOURCE ${EXAMPLE_SOURCES})
endif()

#tests
if(BUILD_TESTS)
	enable_testing()
	file(GLOB TESTS_SOURCES ${TESTS_DIR}/*.cpp)
	add_executable(check ${TESTS_SOURCES})
	target_link_libraries(check ${PROJECT_NAME} ${DEPENDS_LIBRARIES})
	add_test(NAME check COMMAND check "-s" "-r" "compact" "--use-colour" "yes") 
endif()