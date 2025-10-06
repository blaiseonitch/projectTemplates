cmake_minimum_required(VERSION 3.10...4.0)
project(square VERSION 1.2)

set(CMAKE_EXPORT_COMPILE_COMMANDS
    ON
    CACHE BOOL "Export compile commands" FORCE)

add_subdirectory(libs/blazelib)
# main exe
add_executable(${PROJECT_NAME} src/main.cpp src/test.cpp)
target_include_directories(${PROJECT_NAME}
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PRIVATE blazelib)
