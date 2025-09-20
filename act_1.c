#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


#define fo  10
#define A   5
#define M   1000
#define T 1.f
#define a_0_div_2 1.125f
#define n_max 50
#define pi 3.14159

void compute_a_n_terms(float a_n[]);
void compute_b_n_terms(float b_n[]);

int main(){
    float f_x = 0.f;
    FILE *func;
    func = fopen("func_fourier.dat", "w");
    float a_n[n_max] = {};
    float b_n[n_max] = {};
    compute_a_n_terms(a_n);
    compute_b_n_terms(b_n);
    for(int n = 1; n <= n_max; ++n){
        f_x = a_0_div_2 + a_n[n-1]*cos((2*pi*fo*n/M)/T) + b_n[n-1]*sin((2*pi*fo*n/M)/T);
        fprintf(func, "%f \n", f_x);
        //printf("%d: %.10f\n", n, b_n[n]);
    }




    return 0;
}

void compute_a_n_terms(float a_n[]){
    for(int n = 1; n <= n_max; ++n){
        a_n[n-1] = (1.f/(pi*n))*sin(2.f*pi*n) 
                    - (1.f/(n*n*pi*pi))*cos(n*pi/2.f) 
                    - (2.f/(n*n*pi*pi));
    }
}

void compute_b_n_terms(float b_n[])
{
    for(int n = 1; n <= n_max; ++n){
        b_n[n-1] = (2.f/(pi*n))
                    - (2.f/(n*n*pi*pi))*sin(n*pi/2.f) 
                    - (1.f/(n*pi))*cos(2*pi*n);
    }
}
