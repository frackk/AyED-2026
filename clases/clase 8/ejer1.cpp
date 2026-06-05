/*Dado un vector Prueba 1 y su len, busque el valor mínimo e imprímalo por pantalla*/

#include <iostream>
using namespace std;

// void inicializar  (int vec[], int cantPos,  int valIni);
void buscarMin(int vec[],int len);

int main () {

    int prueba1[10];
    int len;

    buscarMin(prueba1,len);

    return 0;
}

void buscarMin(int vec[],int len) {
    int posMin = 0;

    for(int i=1;i<len;i++){
        if (vec[i]<vec[posMin]) {
            posMin = i;
        }
    }
    cout << "el valor minimo dentro del vector es: " << vec[posMin] << endl;
}
