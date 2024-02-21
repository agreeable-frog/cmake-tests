cmake_minimum_required(VERSION 3.7)
project(mainapp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(RESOURCES ${CMAKE_CURRENT_SOURCE_DIR}/res/configuration.json)

set(RESOURCES_PATH ${CMAKE_CURRENT_SOURCE_DIR}/res)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/compile_defs.hh.in ${CMAKE_CURRENT_BINARY_DIR}/compile_defs.hh)

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/main.cc)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(${PROJECT_NAME}
                      PUBLIC
                      Project::libweb
                      Project::logger)