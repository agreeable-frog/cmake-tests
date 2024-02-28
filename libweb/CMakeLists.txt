cmake_minimum_required(VERSION 3.7)
project(libweb VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(CURLPP REQUIRED curlpp)

add_library(${PROJECT_NAME} STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/contact.cc)
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
add_library(Project::libweb ALIAS libweb)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/)
target_include_directories(${PROJECT_NAME} PRIVATE ${CURLPP_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME}
                      PRIVATE
                      ${CURLPP_LDFLAGS})