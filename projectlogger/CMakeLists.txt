# A logger for the entire project
# It makes more sense to have it as a shared library so we don't copy it everywhere

cmake_minimum_required(VERSION 3.7)
project(projectlogger VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/res/log4cplus.properties)
set(LOG_CONFIG_FILE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/res/log4cplus.properties)

find_package(log4cplus REQUIRED)

add_library(${PROJECT_NAME} SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/logger.cc)
add_library(Project::logger ALIAS ${PROJECT_NAME})

target_compile_definitions(${PROJECT_NAME} PRIVATE LOG_CONFIG_FILE_PATH="${LOG_CONFIG_FILE_PATH}")

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PUBLIC log4cplus)
# linking against log4cplus::log4cplus would be prefered but creates link errors 
# to unfound shared libraries on my machine (weird)
# why are we linking publicly? we are using a logger library so we don't have to call log4cplus ourselves!
# well yes but our library headers do refer to log4cplus so we need the targets above to be aware of it