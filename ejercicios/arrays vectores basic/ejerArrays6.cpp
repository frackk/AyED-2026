/*6- Leer 10 números por teclado, 5 para un array (A) y 5 para otro array (B). Mostrar los 10 números en pantalla mediante un solo array (C)*/

#include <iostream>
using namespace std;

int main (){

    int vecA[5];
    int vecB[5];
    int vecC[10];

    for(int i=0;i<5;i++){
        cout << "ingrese un valor en A: ";
        cin >> vecA[i];
    };

    for(int i=0;i<5;i++){
        cout << "ingrese un valor en B: ";
        cin >> vecB[i];
    };

    for(int i=0;i<10;i++){
        if(i<5){
            vecC[i] = vecA[i];
        } else {
            vecC[i] = vecB[i-5];
        }
    }

    cout << "vector C final: ";
    for(int i=0;i<10;i++){
        cout << vecC[i] << " ";
    }

    return 0;
}