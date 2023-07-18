cmake_minimum_required(VERSION 3.23)
project(Snake1976)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD 17)
IF(CMAKE_BUILD_TYPE MATCHES Debug)
    add_compile_definitions(NDEBUG)
    message("debug mode")
ENDIF(CMAKE_BUILD_TYPE MATCHES Debug)


# Set the paths to the SDL and SDL_ttf include directories
set(SDL_INCLUDE_DIR "C:/Users/Wake/API/SDL2/include/SDL2")
set(SDL_TTF_INCLUDE_DIR "C:/Users/Wake/API/SDL2_TTF/include/SDL2")
set(SDL_IMAGE_INCLUDE_DIR "C:/Users/Wake/API/SDL2_IMAGE/include/SDL2")

# Set the paths to the SDL and SDL_ttf library directories
set(SDL_LIBRARY_DIR "C:/Users/Wake/API/SDL2/lib")
set(SDL_TTF_LIBRARY_DIR "C:/Users/Wake/API/SDL2_TTF/lib")
set(SDL_IMAGE_LIBRARY_DIR "C:/Users/Wake/API/SDL2_IMAGE/lib")
set(MINGW_LIBRARY_DIR "C:/Users/Wake/API/mingw64/lib")

# Find the SDL and SDL_ttf libraries
find_library(SDL_LIBRARY NAMES SDL2 PATHS ${SDL_LIBRARY_DIR})
find_library(SDL_TTF_LIBRARY NAMES SDL2_ttf PATHS ${SDL_TTF_LIBRARY_DIR})
find_library(SDL_IMAGE_LIBRARY NAMES SDL2_image PATHS ${SDL_IMAGE_LIBRARY_DIR})

link_directories(${SDL_INCLUDE_DIR} ${SDL_TTF_INCLUDE_DIR} ${SDL_IMAGE_INCLUDE_DIR})


include_directories(${SDL_INCLUDE_DIR} ${SDL_TTF_INCLUDE_DIR} ${SDL_IMAGE_INCLUDE_DIR} include src)

file(GLOB SOURCES "src/*.cpp" "include/*.h")
add_executable(Snake1976 ${SOURCES})
add_custom_target(copy_resources ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/resources
        ${PROJECT_BINARY_DIR}/resources
        COMMENT "Copying resources into binary directory")

add_dependencies(Snake1976 copy_resources)

target_link_libraries(Snake1976 -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf)
