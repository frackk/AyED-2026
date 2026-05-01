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

    cout << "el numero de legajo ingresado es: " << x.legajo << endl;
    cout << "el numero de curso es: " << x.curso << endl;
    cout << "la nota es " << x.nota << endl;

    return 0;
}