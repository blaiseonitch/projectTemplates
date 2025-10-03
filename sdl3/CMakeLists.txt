# cmake_minimum_required(VERSION 3.1...4.0) set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
#
# project( main VERSION 1.0 LANGUAGES CXX)
#
# find_package(fmt CONFIG REQUIRED) find_package(raylib CONFIG REQUIRED)
# find_package(glfw3 CONFIG REQUIRED)
#
# add_executable(main main.cpp)
#
# target_link_libraries( main PRIVATE fmt::fmt raylib m dl pthread GL X11)

cmake_minimum_required(VERSION 3.15)
project(
  test
  VERSION 1.0
  LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_TOOLCHAIN_FILE "/home/blaze/vcpkg/scripts/buildsystems/vcpkg.cmake")

# vcpkg packages
find_package(fmt CONFIG REQUIRED)
find_package(SDL3 CONFIG REQUIRED)

# Add executable
add_executable(main main.cpp)

# Include directories
target_include_directories(main
                           PRIVATE ${VCPKG_ROOT}/installed/x64-linux/include)

# Link libraries manually
target_link_libraries(main PRIVATE fmt::fmt SDL3::SDL3)
