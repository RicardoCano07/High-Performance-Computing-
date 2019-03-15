#include <iostream> 
#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>

/// here I'm stablishing the function f, with each parameter that it will have in there.
double f (double x, void* param);


/// Here I'm defining the order in that the Params will be used by the function f.
struct Params {
 double a,v,w,b,c;
};
