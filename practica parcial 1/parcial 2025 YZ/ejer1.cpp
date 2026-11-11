/*Desarrolle una FUNCION que determine si un año es bisiesto
Nota: es biciesto cuando es difivible entre 4, excepto si tambien es divisible entre 100, a menos que tambien sea divisible entre 400.*/

#include <iostream>
using namespace std;

bool esBiciesto(int anioBis);

int main (){

    int anio;

    cout << "ingrese un anio para ver si es biciesto: " << endl;
    cin >> anio;

    esBiciesto(anio);

    if (anio = true) {
        cout << "el anio " << anio << " ingresado es biciesto." << endl;
    } else {
        cout << "el anio " << anio << " ingresado es biciesto." << endl;
    }

    return 0;
}

bool esBiciesto(int anioBis){
    if(anioBis%4==0){ // es
        if(anioBis%100==0){ // no es
            if(anioBis%400==0){ // es
                return true;
            }
            return false;
        } return true;
        return true;
    } else {
        return false;
    }
}