#include <iostream> 
#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>
#include "header.h"



/// Here I'm defining the function f, and his content, where I stablish a pointer p that calls each parameter of the header.

double f (double x, void* param){
 Params* p = (Params*)param;
 return p->a*sin(cos(p->v-p->w*x))+p->b*x-p->c*x*x;
}
