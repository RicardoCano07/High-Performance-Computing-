// gslroot.cpp
#include <iostream> 
#include <gsl/gsl_roots.h>

struct Params {
 double a,v,w,b,c;
};

double examplefunction(double x, void* param){
 Params* p = (Params*)param;
 return p->a*sin(cos(p->v-p->w*x))+p->b*x-p->c*x*x;
}

int main() {

 double x_lo = -4.0;
 double x_hi = 5.0;
 Params args = {0.3, 2/3.0, 2.0, 1/1.3, 1/30.0};
 gsl_root_fsolver* solver;
 gsl_function      fwrapper;
 solver = gsl_root_fsolver_alloc(
              gsl_root_fsolver_brent);
 fwrapper.function = examplefunction;
 fwrapper.params = &args;
 gsl_root_fsolver_set(solver,&fwrapper,x_lo,x_hi);
 std::cout << "Iter lower upper root Error\n";
 
 int status = 1;
 
 for (int iter=0; status and iter < 100; ++iter) 
   {
 
   gsl_root_fsolver_iterate(solver);
   
   double x_rt = gsl_root_fsolver_root(solver);
   double x_lo = gsl_root_fsolver_x_lower(solver);
   double x_hi = gsl_root_fsolver_x_upper(solver);
   std::cout << iter <<" "<< x_lo <<" "<< x_hi
             <<" "<< x_rt <<" "<<x_hi-x_lo<<"\n";
   status=gsl_root_test_interval(x_lo,x_hi,0,1e-6);
   }
   
 gsl_root_fsolver_free(solver);
 
 return status;
 
}
// g++ gslroot.cpp -lgsl -o root
// ./root

/* brew install gsl
// g++ gslroot.cpp -lgsl -o root


sudo apt-get update
sudo apt-get install g++
sudo apt-get make


wget ftp://ftp.gnu.org/gnu/gsl/gsl-2.5.tar.gz
tar -zxvf gsl-2.5.tar.gz
cd gsl-2.5
mkdir /home/yourname/gsl
./configure --prefix=/home/yourname/gsl
make
make check
make install
*/

