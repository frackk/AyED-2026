/*Ejercicio Nro. 1:
Dado un vector de velocidades contiene el país y su velocidad máxima y su velocidad mínima en autopistas (Se sabe que hay 150 países listados), determinar:
a- ¿Qué país tiene la velocidad máxima más alta permitida y cuál es la misma?
b- ¿Cuál es el promedio de velocidades máximas para la lista de países?
c- ¿Qué país tiene la velocidad mínima más baja permitida y cuál es la misma?*/

#include <iostream>
using namespace std;

struct VelPais{
    string pais;
    int velMax;
    int velMin;
};


int calcularMaxVelocidad(vec,len);

int main () {

    VelPais vec[150] = {{"Argentina",180,50},{"Chile",220,60},{"Uruguay",100,40}};

    int n = 150;
    int len = 3;


    cout << "El pais con la vel max es " << vec[posMax].pais <<  " con " << vec[posMax].velMax << "Kmh" << endl;

    string paisVelocidadMaxima;

    int velMax = calcularMaxVelocidad(vec,len,paisVelocidadMaxima);
    int posMax = calcularMaxVelocidad(vec,len);

    cout << "El pais con la vel max es " << paisVelocidadMaxima <<  " con " << velMax << "Kmh" << endl;


    return 0;
};


int posMax = calcularMaxVelocidad(vec,len) {
    int vMax = -100;
    int pos;

    for(int i=0; i < len; i++) {
        if(vec[i].velMax > vMax) {
            vMax = vec[i].velMax;
            pos = i;
        } 
    }

    return pos;
}

