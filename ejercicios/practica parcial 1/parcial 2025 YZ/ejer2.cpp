/*desarrolle un PROCEDIMIENTO que, dados 3 valores de los lados de un triangulo, muestre el tipo de triangulo que es,
nota: indicar si es equilatero, isoseles o escaleno*/

#include <iostream>
using namespace std;

void triangulo (int A, int B, int C);

int main (){

    int lado1,lado2,lado3;

    cout << "ingrese los 3 lados de un triangulo para ver que tipo de triangulo es: ";
    cin >> lado1 >> lado2 >> lado3;

    triangulo(lado1,lado2,lado3);

    return 0;
}

/*
A = 1
B = 2
C = 1
*/

void triangulo (int A, int B, int C){

    if (A==B){
        if(B==C) {
            cout << "el triangulo es equilatero." << endl;
        } else {
            cout << " el triangulo es isoseles." << endl;
        }
    } else {
        if (B==C){
            cout << "el triangulo es isoseles" << endl;
        } else if (A==C){
            cout << "el triangulo es isoseles" << endl;
        } else {
            cout << "el triangulo es escaleno" << endl;
        }
    }
}