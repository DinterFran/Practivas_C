#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <inttypes.h>
#include "filter.h"


// ejemplo filtro fir
//static const double fir_coef[] = {0.0007, -0.0000, -0.0009, -0.0016, -0.0015, 0.0000, 0.0024, 0.0044, 0.0039, -0.0000, -0.0060, -0.0103, -0.0089, 0.0000, 0.0128, 0.0217, 0.0184, -0.0000, -0.0268, -0.0465, -0.0411, 0.0000, 0.0727, 0.1570, 0.2244, 0.2502, 0.2244, 0.1570, 0.0727, 0.0000, -0.0411, -0.0465, -0.0268, -0.0000, 0.0184, 0.0217, 0.0128, 0.0000, -0.0089, -0.0103, -0.0060, -0.0000, 0.0039, 0.0044, 0.0024, 0.0000, -0.0015, -0.0016, -0.0009, -0.0000, 0.0007};
//double x_fir[FIR_ORDER+1] = {0};

// filtro iir
// ejemplo de como poner coeficientes que le pasas al filtro
// static const double num_notch[] = {0.9976, -1.9931, 0.9976};
// static const double den_notch[] = {1.0000, -1.9931, 0.9953};
// donde se guardan los coeficientes
double x_notch[FILTER_NOTCH + 1] = {0};
double y_notch[FILTER_NOTCH + 1] = {0};

// parametros:
// input: muestra
// *num : coeficientes del numerador
// *den coeficientes de denominador
// orden del numerador
//orden del nenominador
//donde se guardan los x calculados
// donde se guardan los y calculados

double iir_filter(double input, const double *num, const double *den, int num_order, int den_order, double *x, double *y) {
    
    for (uint8_t i = num_order; i > 0; i--) {
        x[i] = x[i-1];
    }
    x[0] = input;

    
    double output = 0.0;

    for (uint8_t i = 0; i <= num_order; i++) {
        output += num[i] * x[i];
    }
    
    for (int i = 1; i <= den_order; i++) { 
        if(den[i] != 0.0){
            output -= den[i] * y[i - 1];
        }      
    }
    output /= den[0];

    
    for (uint8_t i = den_order; i > 0; i--) {
        y[i] = y[i-1];
    }
    y[0] = output;

    return output;
}


double fir_filter(int16_t input, const double *coef,int order,double *x){
    
    for(uint8_t i= order-1 ; i>0 ; i--){
        x[i]=x[i-1];
    }
    x[0]=(double)input;
    double out = 0.0;
    for(uint8_t i=0; i< order;i++){
        out+=x[i]*coef[i];
    }
    return out;
}

double filter = fir_filter(sampple, fir_coef, FIR_ORDER , x_fir);
double filter_2 = iir_filter(sampple, num_notch, den_notch,FILTER_NOTCH_ORDER, FILTER_NOTCH_ORDER,x_notch,y_notch );