// Definimos nuestras variables constantes para nuestros programa y bibliotecas

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

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

    return resultado + 1;
}

int main(){
    // Definimos nuestras variables importantes
    // Definimos nuestras variables de muestreo, 500 muestras por periodo    
    float Fs = 500 * Fo, Ps=  1 / Fs; 
    float imprimir[5000];
    for(int i = 0; i< 5000; i++) // Aqui se ajusta el numero de muestras que queremos dentro del for
        //Sumatoria(2,i*Ps);
        imprimir[i]= Sumatoria(10,i*Ps); // Le mandamos el numero de ciclos que queremos
    
    FILE *archivo;  // puntero al archivo

    // Abrir archivo en modo escritura ("w")
    archivo = fopen("ft.dat", "w");

    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    } 
    for(int i =0; i< 5000; i++)
        fprintf(archivo,"%f\n" ,imprimir[i]);
    fclose(archivo);  // cerrar el archivo
    
    system("gnuplot -p grafi.gp");

    return 0;


}
