cmake_minimum_required(VERSION 3.10)
project(SDL_Sprite)

# Establecer el estándar de compilación
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Añadir flags (como -Wall y -g)
add_compile_options(-Wall -g)

# Incluir directorios
include_directories(${PROJECT_SOURCE_DIR}/src)

# Buscar SDL2 y SDL2_image
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

# Archivos fuente
set(SOURCES
    src/main.c
)

add_executable(main ${SOURCES})
target_link_libraries(main ${SDL2_LIBRARIES} SDL2_image)

# Establecer la salida en output/
set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/output
)

add_custom_command(
    TARGET main
    POST_BUILD
    COMMAND ${PROJECT_SOURCE_DIR}/output/main
)