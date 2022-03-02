
# Put all your sources here EXCEPT YOUR MAIN.CC
set(SRC
    "src/geometry/point3.cc"
    "src/geometry/point4.cc"
    "src/geometry/vector3.cc"
    "src/scene_objects/camera.cc"
    "src/scene_objects/sphere.cc"
    "src/textures/color.cc"
    "src/textures/uniform_texture.cc"
    "src/engine.cc"
    "src/image.cc"
)

# Directories containing headers must be specified in the include_directories()
include_directories(
    "src/geometry"
    "src/scene_objects"
    "src/textures"
    "src/"
)

# SETUP
cmake_minimum_required(VERSION 3.12)
project(Raytracer)

set(CMAKE_CXX_STANDARD 17)

if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${OPT_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -g3") # -fsanitize=address")

# LIBRARIES

# RAYTRACER
add_executable(raytracer)
target_sources(raytracer PRIVATE "src/main.cc" ${SRC})
target_link_libraries(raytracer PRIVATE ${LIBRARIES})

# STATIC TARGET
if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(raytracer-static)
    target_sources(raytracer-static PRIVATE "src/main.cc" ${SRC})
    target_link_libraries(raytracer-static PRIVATE ${LIBRARIES} -static)
endif()

