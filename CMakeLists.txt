cmake_minimum_required(VERSION 3.9)
project(CaveStoryRemake)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

file(GLOB SRC
    "src/*.h"
    "src/*.cpp"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

add_executable(CaveStoryRemake ${SRC})
target_link_libraries(CaveStoryRemake ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})