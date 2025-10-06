cmake_minimum_required(VERSION 3.25.1)

project(main)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS
    ON
    CACHE BOOL "Export compile commands" FORCE)
add_executable(
  ${PROJECT_NAME}
  src/main.cpp
  external/imgui/imgui.cpp
  external/imgui/imgui_draw.cpp
  external/imgui/imgui_demo.cpp
  external/imgui/imgui_tables.cpp
  external/imgui/imgui_widgets.cpp
  external/imgui/rlImGui.cpp)

target_link_libraries(
  ${PROJECT_NAME}
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external/raylib/libraylib.a)

target_include_directories(${PROJECT_NAME} PRIVATE include external/imgui
                                                   external/raylib)
