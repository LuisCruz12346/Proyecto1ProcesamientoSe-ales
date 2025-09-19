// Definimos nuestras variables constantes para nuestros programa y bibliotecas

#include<stdio.h>
#define Fo (10.0f)
#define Po (1/Fo)
#define A 1

float Sumatoria(int veces, float valort) {
    float resultado = 0.0f;
    float epsilon = 1e-6f;
    float inicio, fin;
    for (int i = 0; i < veces; i++) {
        inicio = i * Po;
        fin = i * Po + Po/4;
        if (valort + epsilon >= inicio && valort - epsilon <= fin) {
            resultado += A - (4 * A / Po) * (valort - inicio);
        }
    }

    return resultado;
}

int main(){
    // Definimos nuestras variables importantes
    // Definimos nuestras variables de muestreo, 20 muestras por periodo    
    float Fs = 20 * Fo, Ps=  1 / Fs; 
    float imprimir[10];
    for(int i = 0; i< 40; i++) // Aqui se ajusta el numero de muestras que queremos dentro del for
        //Sumatoria(2,i*Ps);
        printf("Resultado: %f \n" , Sumatoria(2,i*Ps));

}
