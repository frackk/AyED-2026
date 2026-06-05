/*Dado un vector acerca de la producción de semillas, que contiene el código de la semilla y la cantidad de kilos disponibles para la venta (Se sabe que máximo hay 1500 tipos de semillas), determinar:

a-     ¿Cuál es la semilla que más kilos tiene producidos?
b-     ¿Cuál es la semilla que menos kilos tiene?
c-     Calcular el promedio de kilos generados.*/

#include <iostream>
using namespace std;

int buscarMax (int vec[], int len);
int buscarMin (int vec[], int len);
int promedio (int vec[], int len);

int main (){

    int semillasVec[1500];
    int len;

    buscarMax(semillasVec,len);

    buscarMin(semillasVec,len);

    promedio(semillasVec,len);

    return 0;
}

void inicializar  (int vec[], int cantPos,  int valIni) {       // vector[], cantidad de posiciones, valor inicial.
    for(int i=0;i<cantPos;i++) {                                // para indice 0; i menor que la cantidad de popsiciones, suma 1 al indice.
        vec[i] = vec[cantPos];                                  // vector en la posicion del indice = cantidad de posiciones ( vec[0] = vec[cantPos] son 0 )
    }                                                           // i++
}


int buscarMax (int vec[], int len) {
    int posMax = 0;

    for(int i=2;i<len;i++) {
        if(vec[i] > vec[posMax]) {
            posMax = i;
        }
    }
    return posMax;
}

int buscarMin (int vec[], int len) {
    int posMin = 0;

    for (int i=1;i<len;i++) {
        if(vec[i] < vec[posMin]) {
            posMin = i;
        }
    }
    return posMin;
}

int promedio (int vec[], int len) {
    int prom;
    int suma = 0;

    for(int i=0;i<len;i++) {
        suma = suma + vec[i];  
    }
    prom = suma/len;

    return prom;
}