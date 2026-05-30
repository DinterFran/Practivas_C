cmake_minimum_required(VERSION 3.10)
project(PracticasC C)

set(CMAKE_C_STANDARD 11)
# Indicar dónde buscar los archivos .h (en la carpeta actual)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
# Definir el ejecutable y TODOS los archivos .c que lo componen
add_executable(main 
    main.c 
    matrix.c    
)