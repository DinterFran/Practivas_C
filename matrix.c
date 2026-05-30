#include "matrix.h"

static matrix_config g_matrix_led[MAX_MATRIX];
static uint8_t g_num_matrix = 0;

/*
    Crea la matriz dependiendo de la cantidad de matrices led que se dispongan
*/
bool created_matrix(uint8_t num_matrix){
    if(num_matrix > MAX_MATRIX){
        g_num_matrix = MAX_MATRIX;        
    }else{
        g_num_matrix = num_matrix;
    }
    for(uint8_t i = 0; i < g_num_matrix ; i++){
        g_matrix_led[i].brightness = 0;
        g_matrix_led[i].shutdown = 0;
        for(uint8_t j = 0; j< NUM_ROW;j++){
            g_matrix_led[i].data[j] = 0;
        }
        g_matrix_led[i].decode_mode = 0;        
    }
    return true;
}

bool brightness_set(uint8_t brightness){
    if(brightness > MAX_BRIGHTNESS){
        brightness = MAX_BRIGHTNESS;

    }else if (brightness < MIN_BRIGHTNESS){

        brightness = MIN_BRIGHTNESS;
    }

    for(uint8_t i = 0; i<g_num_matrix; i++){
        g_matrix_led[i].brightness = brightness;
    }
}
/*
    TODO: esta mal, estoy haciendo or con todos los valores 
    tengo solamente que hacer or con el ultimo valor, trabajar en estas funciones.
*/
bool set_matrix_left(uint8_t num_matrix){
    for(uint8_t row = 0; row < NUM_ROW ; row++){
        if(num_matrix > MIN_MATRIX){
            g_matrix_led[num_matrix-1].data[row] = (g_matrix_led[num_matrix].data[row] << 1) || g_matrix_led[num_matrix-1].data[row - 1];            
        }
        g_matrix_led[num_matrix].data[row] = g_matrix_led[num_matrix].data[row] << 1; 
    }
}
bool set_matrix_rigth(uint8_t num_matrix){
    for(uint8_t row = 0; row < NUM_ROW ; row++){
        if(num_matrix < g_num_matrix){
            g_matrix_led[num_matrix+1].data[row] = (g_matrix_led[num_matrix].data[row] >> 1) || g_matrix_led[num_matrix + 1].data[row];            
        }
        g_matrix_led[num_matrix].data[row] = g_matrix_led[num_matrix].data[row] >> 1; 
    }
    
}
bool set_all_rigth(){
    for(uint8_t matrix = 0; matrix < g_num_matrix ; matrix++){
        for(uint8_t row = 0; row < NUM_ROW ; row++){

        }
    }

}
bool set_all_left(uint8_t num,uint8_t num_matrix){
    
}