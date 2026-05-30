#include "main.h"


int main() {
    bool ret = created_matrix(8);
    if(ret){
        printf("\n Matriz creada");
    }
    uint8_t test = 1;
    printf("\n Numero iniciar %d",test);
    test = test >> 1;

    printf("\n Numero iniciar %d",test);
    test = test << 1;
    printf("\n Numero iniciar %d",test);

    return 0; // Indica que el programa terminó correctamente
}