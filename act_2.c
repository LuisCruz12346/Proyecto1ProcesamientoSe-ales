#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define fo  10
#define A   12.5
#define Ar  1.25
#define M   1000
#define pi 3.14159

void quantize(float f_array[], int L_bits,char file_name[]);

void main(){
    FILE *signal_file;
    float xs[M];
    srand((unsigned int)time(NULL));

    signal_file = fopen("signal.dat", "w");

    for(int n = 0; n < M; ++n){
        xs[n] = A*sin(2*pi*fo*n/M) + Ar *((float)rand()/(float)RAND_MAX);
        fprintf(signal_file, "%f \n", xs[n]);
    }

    fclose(signal_file);

    quantize(xs, 4, "q4_signal.dat");
    quantize(xs, 6, "q6_signal.dat");
    quantize(xs, 8, "q8_signal.dat");

    system("gnuplot -p graf2.gp");

}

void quantize(float f_array[], int L_bits, char file_name[]){
    if(strlen(file_name) <= 0) {printf("Longitud de nombre insuficiente"); return;}
    if(strlen(file_name) > 40) {printf("Longitud de nombre muy grande"); return;}
    int q_array[M] = {};
    int q_max_val = (int)pow(2,L_bits-1)-1;
    FILE *file;
    file = fopen(file_name, "w");

    for(int n = 0; n < M; ++n){
        if(f_array[n] > (float)q_max_val){
            q_array[n] = q_max_val;
            
        }
        else if(f_array[n] < -(float)q_max_val){
            q_array[n] = -q_max_val;
        }
        else{
            q_array[n] = (int)f_array[n];
        }
        fprintf(file, "%d \n", q_array[n]);
    }
    fclose(file);

}
