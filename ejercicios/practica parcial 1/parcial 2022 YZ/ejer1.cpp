/*
desarrolle una FUNCION que determine si en un año se jugaran las olimpiadas.
NOTA: las olimpiadas se juegan cada 4 años y coincden que son en un año divisible por 4.
*/

#include <iostream>
using namespace std;

bool anioOlimpico(int anio);

int main(){

    int anioOlim;
    bool esOlim;

    cout << "anio: ";
    cin >> anioOlim;

    esOlim = anioOlimpico(anioOlim);

    if(esOlim){
        cout << "hay olimpiada." << endl;
    } else {
        cout << "no hay olimpiada." << endl;
    }

    return 0;
}

bool anioOlimpico(int anio){
    if(anio%2==0){
        if(anio%4==0){
            return true;
        }
        return false;
    } else {
        return false;
    }
}