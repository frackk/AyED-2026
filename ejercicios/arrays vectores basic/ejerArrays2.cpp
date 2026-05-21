//2- Generar y completar un array con los 100 primeros números enteros y mostrarlos en forma descendente.

#include <iostream>
using namespace std;

int main (){

    int vec[100];

    for(int i=100;i>0;i--) {
        vec[i] = i;
        cout << vec[i] << " ";
    }

    return 0;
}