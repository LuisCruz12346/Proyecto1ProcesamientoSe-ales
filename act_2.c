#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define fo  10
#define A   12.5
#define Ar  15.2f
#define M   1000
#define pi 3.14159

void quantize(float f_array[], int L_bits,char file_name[]);

void main(){
    FILE *signal_file;
    float sin_x[M];
    float pot_sin = 0.f;
    float noise[M];
    float pot_noise = 0.f;
    float sin_x_noise[M];
    float pot_sin_soise = 0.f;

    srand((unsigned int)time(NULL));

    signal_file = fopen("signal.dat", "w");

    for(int n = 0; n < M; ++n){
        sin_x[n] = A*sin(2*pi*fo*n/M);
        pot_sin += sin_x[n] * sin_x[n];
        noise[n] = Ar *((float)rand()/(float)RAND_MAX);
        pot_noise += noise[n] * noise[n];
        sin_x_noise[n] = sin_x[n] + noise[n];
        pot_sin_soise += sin_x_noise[n] * sin_x_noise[n];
        fprintf(signal_file, "%f \n", sin_x_noise[n]);
    }

    pot_sin = (1/(float)M)*pot_sin;
    pot_noise = (1/(float)M)*pot_noise;
    pot_sin_soise = (1/(float)M)*pot_sin_soise;

    printf("Potencia de señal sinusoidal: %f\n", pot_sin);
    printf("Potencia del ruido: %f\n", pot_noise);
    printf("Potencia de señal sinusoidal con ruido: %f\n", pot_sin_soise);

    fclose(signal_file);

    quantize(sin_x, 5, "q5_signal.dat");
    quantize(sin_x, 9, "q9_signal.dat");
    quantize(sin_x, 11, "q11_signal.dat");

    system("gnuplot -p graf_quant.gp");

}

void quantize(float f_array[], int L_bits, char file_name[]){
    if(strlen(file_name) <= 0) {printf("Longitud de nombre insuficiente"); return;}
    if(strlen(file_name) > 40) {printf("Longitud de nombre muy grande"); return;}
    int q_array[M] = {};
    int q_max_val = (int)pow(2,L_bits-1)-1;
    float ECM = 0.f;
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
            q_array[n] = (int)(f_array[n]+0.5);
        }
        ECM += (f_array[n] - (float)q_array[n])*(f_array[n] - (float)q_array[n]);
        fprintf(file, "%d \n", q_array[n]);
    }
    fclose(file);
    ECM = (1/(float)M)*ECM;
    printf("El error cuadratico medio a %d bits es: %f\n", L_bits, ECM);
}
