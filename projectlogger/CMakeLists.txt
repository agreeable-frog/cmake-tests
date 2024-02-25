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

target_link_libraries(${PROJECT_NAME} PUBLIC log4cplus::log4cplus)
# The target log4cplus::log4cplus is an imported target meaning cmake will check the cmake files of the lib
# and look for other dependencies needed!
# Sadly in this case log4cplus fucked up and links directly against /usr/lib/x86_64-linux-gnu/librt.so which doesn't exist on my system.
# If you have this problem create the link manually or replace log4cplus::log4cplus by just log4cplus.
# This means that cmake will simply pass to the compiler -llog4cplus which actually works alone.
# Why are we linking publicly? We are using a logger library so we don't have to call log4cplus ourselves!
# Well yes but our library headers do refer to log4cplus so we need the targets above to be aware of it