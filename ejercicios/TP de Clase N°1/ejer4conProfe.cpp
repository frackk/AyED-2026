/*Dado un vector acerca de la producción de semillas, que contiene el código de la semilla y la cantidad de kilos disponibles para la venta (Se sabe que máximo hay 1500 tipos de semillas), determinar:

a-     ¿Cuál es la semilla que más kilos tiene producidos?
b-     ¿Cuál es la semilla que menos kilos tiene?
c-     Calcular el promedio de kilos generados.*/

#include <iostream>
using namespace std;

int buscarMax (semillas vec[], int len);
int buscarMin (semillas vec[], int len);
int promedio (semillas vec[], int len);

struct semillas{
    int cod;
    int prod;
}

int main (){

    semillas semillasVec[1500];
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


int buscarMax (semillas vec[], int len) {
    int codMax = 0;
    int cantMax=vec[0];

    for(int i=2;i<len;i++) {
        if(vec[i] > vec[posMax]) {
            posMax = i;
        }
    }
    return posMax;
}

int buscarMin (semillas vec[], int len) {
    int posMin = 0;

    for (int i=1;i<len;i++) {
        if(vec[i] < vec[posMin]) {
            posMin = i;
        }
    }
    return posMin;
}

void menor(semillas vec[], int len) {
    int codMin = 0;
    int cantMin=vec[0];
}

int promedio (semillas vec[], int len) {
    int prom;
    int suma = 0;

    for(int i=0;i<len;i++) {
        suma = suma + vec[i];  
    }
    prom = suma/len;

    return prom;
}