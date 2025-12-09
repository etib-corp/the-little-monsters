cmake_minimum_required(VERSION 3.10)

project(the-little-monsters
    VERSION 0.1.0
    DESCRIPTION "The Little Monsters"
    HOMEPAGE_URL "https://etib-corp.github.io/the-little-monsters"
    LANGUAGES C
)

include(FetchContent)

set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
    SDL
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG release-3.2.28
)
FetchContent_MakeAvailable(SDL)

FetchContent_Declare(
    SDL_image
    GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
    GIT_TAG release-3.2.4
)
FetchContent_MakeAvailable(SDL_image)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(HEADERS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/headers)
set(SOURCES_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/sources)

file(GLOB_RECURSE SOURCES ${SOURCES_DIRECTORY}/*.c)

add_executable(${PROJECT_NAME}
    ${SOURCES}
)

target_include_directories(${PROJECT_NAME}
    PRIVATE ${HEADERS_DIRECTORY}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE SDL3::SDL3 SDL3_image::SDL3_image
)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE SDL_MAIN_USE_CALLBACKS
)