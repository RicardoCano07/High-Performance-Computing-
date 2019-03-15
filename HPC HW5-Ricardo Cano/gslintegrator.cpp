// gslintegrator.cpp
#include <iostream> 
#include <stdio.h>
#include <math.h>
#include <gsl/gsl_integration.h>
#include "header.h" // Here I'm linking the header with the main function.





int main() 
{
  gsl_integration_workspace * w = gsl_integration_workspace_alloc (1000); //This function allocates a workspace sufficient to hold n (1000) double precision intervals, their integration results and error estimates. One workspace may be used multiple times as all necessary reinitialization is performed automatically by the integration routines.
  double result, error;
  double x_low = 0.0; // lower limit of integration
  double x_hig = 5.0; // Upper limit of integraton
  Params args = {0.3, 2.0/3.0, 2.0, 1.0/1.3, 1.0/30.0}; // Values of each parameter stablished in structure.cpp
  gsl_function F; // Difinition of F that it will be the place where the integral will aprox the solution.
  F.function = &f; //Here we are applying the GSL to f function
  F.params = &args; //Here we are reading each parameter of the function f.
 
 
  gsl_integration_qag(&F, x_low, x_hig,1e-7,200.0, 100, 6,w, &result, &error); //This function applies an integration rule adaptively until an estimate of the integral of f over the interval (0,5) is achieved within the desired absolute and relative error limits, epsabs and epsrel. 
//The function returns the final approximation, result, and an estimate of the absolute error, abserr. The integration rule is determined by the value of key.
 ///prints the results
  printf ("result          = % .18f\n", result);
  printf ("estimated error = % .18f\n", error);
  printf ("intervals       = %zu\n", w->size);

  gsl_integration_workspace_free (w); ///This function frees the memory associated with the workspace w.

  return 0;
 
 }
