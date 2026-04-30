/*Dados dos valores numéricos diferentes entre si, informar cual es el mayor. */

#include <iostream>
using namespace std;

int main () {

    int a,b;
    
    cout << "ingresar 2 valores numeros: " << endl;
    cin >> a >> b;

    if(a>b) {
        cout << "el valor ingresado mayor es: " << a << endl;
    } else {
        cout << "el valor ingresado mayor es: " << b << endl;
    }


    return 0;
}