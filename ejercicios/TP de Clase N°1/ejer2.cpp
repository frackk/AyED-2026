/*Desarrolle un procedimiento que dadas 3 notas muestre el promedio. 

Nota: Las notas deben ser pasadas por parámetro. Sólo se pide el procedimiento.*/

#include <iostream>
using namespace std;

void promedio(int n1, int n2, int n3);

int main () {

    int nota1,nota2,nota3;

    cout << "ingrese 3 notas para calcular su promedio " << endl;
    cin >> nota1 >> nota2 >> nota3;


    promedio(nota1, nota2, nota3);


    return 0;
}

void promedio(int n1, int n2, int n3){
    int prom;
    prom = (n1+n2+n3)/3;

    cout << "el promedio de notas es: " << prom << endl;
}