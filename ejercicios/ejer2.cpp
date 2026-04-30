 /*Dada una terna de números naturales que representan el día, el mes y el año
de una determinada fecha informarla como un solo número natural de 8 dígitos
(aaaammdd).*/

#include <iostream>
using namespace std;

int main () {

    int dia,mes,anio,fecha;

    cout << "ingresar una fecha con el formato aaaammdd: " << endl;
    cin >> fecha;

    anio = fecha / 10000;
    
    mes = fecha % 10000;
    mes = mes / 100;

    dia = fecha % 100;

    cout << anio << "/" << mes << "/" << dia << endl;

    return 0;
}