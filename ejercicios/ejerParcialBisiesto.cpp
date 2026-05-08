/*desarrolle una funcion que determine si un año es bisiesto.
(Nota: es bisiesto cuando es divisible entre 4, excepto si tambien es divisible entre 100, a menos que tambien sea divisible entre 400)*/

#include <iostream>
using namespace std;

int esBisiesto(int anio);

int main () {

    int anioBis;
    
    cout << "ingrese un anio para analizar si es bisiesto: ";
    cin >> anioBis; 

    esBisiesto(anioBis);

    return 0;
}

int esBisiesto(int anio) {
    if(anio % 4 == 0) {
        if(anio % 100 == 0) {
            if (anio % 400 == 0) {

                cout << "el anio " << anio << " es bisiesto.";
                return 0;
            }

            cout << "el anio " << anio << " no es bisiesto.";
            return 1;
        }

        cout << "el anio " << anio << " es bisiesto.";
        return 0;
    }

    cout << "el anio " << anio << " no es bisiesto.";
    return 1;
};