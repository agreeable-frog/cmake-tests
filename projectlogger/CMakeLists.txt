# A logger for the entire project
# It makes more sense to have it as a shared library

# https://github.com/ttroy50/cmake-examples/blob/master/01-basic/H-third-party-library/CMakeLists.txt

cmake_minimum_required(VERSION 3.7)
project(projectlogger VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(log4cplus REQUIRED)

add_library(${PROJECT_NAME} SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/logger.cc)
add_library(Project::logger ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PRIVATE log4cplus) # normally you would link agains log4cplus::log4cplus but for some reason it doesn't work on my machine