#include <iostream>
using namespace std;

void inicializar  (int vec[], int cantPos,  int valIni);

int main () {

    int vector[10]; // 10 num random.
    int len;

    // inicializo
    inicializar(vector,len,0);

    return 0;
}

void inicializar  (int vec[], int cantPos,  int valIni) {       // vector[], cantidad de posiciones, valor inicial.
    for(int i=0;i<cantPos;i++) {                                // para indice 0; i menor que la cantidad de popsiciones, suma 1 al indice.
        vec[i] = vec[cantPos];                                  // vector en la posicion del indice = cantidad de posiciones ( vec[0] = vec[cantPos] son 0 )
    }                                                           // i++
}