#ifndef __FILTER__
#define __FILTER__


#include <stdint.h>
// poner orden de los filtros
#define     FILTER_ORDER                
#define     FILTER_NOTCH_ORDER                
#define     FIR_ORDER                   


double iir_filter(double input, const double *num, const double *den, int num_order, int den_order, double *x, double *y);
double fir_filter(int16_t input, const double *coef,int order,double *x);
#endif