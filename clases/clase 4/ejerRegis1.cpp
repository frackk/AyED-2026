// ver si promociono o no

#include <iostream>
using namespace std;

// declaro mi tipo de dato
struct Alumno {
    int legajo;
    int curso;
    int nota;
};

int main () {

    // declaro una variable x del tipo de dato que contrui
    Alumno x;

    // cargo campo a campo con lo que necesitaba

    cout << "Ingrese el numero de legajo " << endl;
    cin >> x.legajo;

    cout << "Ingrese el numero de curso " << endl;
    cin >> x.curso;

    cout << "Ingrese el numero de nota " << endl;
    cin >> x.nota;

    // ejercicio: analizar la nota ingresada y mostrar el estadío academico

    if(x.nota > 7){
        cout << "promocionó" << endl;
    } else {
        if(x.nota>5) {
            cout << "regularizó" << endl;
        } else {
            cout << "desaprobó" << endl;
        }
    }

    return 0;
}