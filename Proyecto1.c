// Definimos nuestras variables constantes para nuestros programa y bibliotecas

#include<stdio.h>
#include <stdlib.h>
#include <math.h>

#define Fo (10.0f)
#define Po (1/Fo)
#define A 1
#define PI 3.1415926535897932384

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

float SumatoriaSFT(int veces, float valort) {
    float resultado = 0.0;
    float Pcos, Psen, n2,an,bn;
    for (int n = 1; n <= veces; n++) {  // n arranca en 1 para evitar división entre 0
        an = -(2.0 * A * (cos((PI * n) / 2.0) - 1.0)) / (PI * PI * n * n);
        bn = -(A * (2.0 * sin((PI * n) / 2.0) - PI * n)) / (PI * PI * n * n);

        Pcos = an * cos((2.0 * PI * n * valort) /Po);
        Psen = bn * sin((2.0 * PI * n * valort) /Po);

        resultado += Pcos + Psen;
    }
    return resultado + (1.125f);  // término a0/2 si corresponde
}

int main(){
    // Definimos nuestras variables importantes
    // Definimos nuestras variables de muestreo, 500 muestras por periodo    
    float Fs = 500 * Fo, Ps=  1 / Fs; 
    float imprimir[5000];
    for(int i = 0; i< 5000; i++) // Aqui se ajusta el numero de muestras que queremos dentro del for
        //Sumatoria(2,i*Ps);
        imprimir[i]= Sumatoria(10,i*Ps); // Le mandamos el numero de ciclos que queremos
    
    float Fs2 = 500 * Fo, Ps2=  1 / Fs2;
    float imprimirFST[5000];
    for(int i=0; i<5000; i++)
        //printf("Resultado aproximado: %f \n", SumatoriaSFT(100, i*Ps2));
        imprimirFST[i] = SumatoriaSFT(100, i*Ps2);
    
        FILE *archivoSFT = fopen("ftSFT.dat", "w");;  // puntero al archivo
        for(int i =0; i< 5000; i++)
            fprintf(archivoSFT,"%f\n" ,imprimirFST[i]);
        fclose(archivoSFT);  // cerrar el archivo

              
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
// (2/T)(2-4/Tx)cos((2 pi n x)/T)

//(2/T)(2-4/Tx)sen((2 pi n x)/T)