/*Desarrolle una función que determine si un año es Bisiesto.
Nota: Es bisiesto cuando es divisible entre 4, excepto si también es divisible entre 100, a menos que también sea divisible entre 400.*/

#include <iostream>
using namespace std;

bool esBiciesto(int anio);

int main (){

    int anioBis;
    int result;

    cout << "ingresar anio: ";
    cin >> anioBis;

    result=esBiciesto(anioBis);

    if(result){
        cout << "anio biciesto." << endl;
    } else {
        cout << "anio no biciesto." << endl;
    }

    return 0;
}

bool esBiciesto(int anio){
    if(anio%4==0){
        if(anio%100==0){
            if(anio%400==0){
                return true;
            } else {
                return false;
            }
        } else {
            return true;
        }
    } else {
        return false;
    }
}