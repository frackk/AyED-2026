/*Dado un vector Prueba 2 y su len, busque el valor máximo e imprímalo por pantalla*/

#include <iostream>
using namespace std;

void buscarMax(int vec[],int len);

int main () {

    int prueba2[10];
    int len;

    buscarMax(prueba2,len);

    return 0;
}

void buscarMax(int vec[],int len) {
    int posMax = 0;

    for(int i=1;i<len;i++){
        if (vec[i]>vec[posMax]) {
            posMax = i;
        }
    }
    cout << "el valor minimo dentro del vector es: " << vec[posMax] << endl;
}
