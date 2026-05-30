#ifndef MMATRIX
#define MATRIX


#include <stdio.h> // fprint
#include <stdint.h> // Tipos exactos (uint32_t, etc.)
#include <stdbool.h> // Booleanos (true/false)
#include <stddef.h> // NULL, size_t
#include <string.h> // memcpy, memset
#include <stdlib.h> //malloc
#include "math.h"

#define MAX_MATRIX 8
#define MIN_MATRIX 0
#define MAX_BRIGHTNESS 15
#define MIN_BRIGHTNESS 0
#define NUM_ROW 8


typedef struct matrix_config_s{
    uint8_t brightness;
    uint8_t decode_mode ;
    uint8_t shutdown;
    uint8_t data[NUM_ROW];    
}matrix_config;


bool created_matrix(uint8_t num_matrix);

#endif
