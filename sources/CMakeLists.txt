cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 14)

if (NOT UNIX)
    message(FATAL_ERROR "Not Unix!")
endif()

project(BSTree)
set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/TUI.cpp ${CMAKE_CURRENT_SOURCE_DIR}/BSTree.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../include/)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME})