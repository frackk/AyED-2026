/*
defina los siguientes registros, defina una variable para la implementacion de cada uno y cargarle valores a eleccion en un programa principal.
Socio: DNI, Nombre y Apellido, N. Afiliado, Anio Afilacion
Alumno: Legajo, Nombre y apellido, Materia, Nota1 Nota2, promocion si o no.
*/

#include <iostream>
using namespace std;

struct Socio{
    int dni;
    char nomb[32];
    char apellido[32];
    int numAfi;
    int anioAfi;
};

struct Alumno {
    int legajo;
    char nomb[32];
    char apellido[32];
    char materia[32];
    int nota1;
    int nota2;
};

int main (){

    Socio sos1;
    Alumno alum1;

    cout << "Ingrese el DNI del socio: ";
    cin >> sos1.dni;
    cout << "Ingrese el nombre del socio: ";
    cin >> sos1.nomb;
    cout << "Ingrese el apellido del socio: ";
    cin >> sos1.apellido;
    cout << "Ingrese el numero de afiliado del socio: ";
    cin >> sos1.numAfi;
    cout << "Ingrese el anio de afilacion del socio: ";
    cin >> sos1.anioAfi;

    cout << "Ingrese el legajo del alumno: ";
    cin >> alum1.legajo;
    cout << "Ingrese el nombre del alumno: ";
    cin >> alum1.nomb;
    cout << "Ingrese el apellido del alumno: ";
    cin >> alum1.apellido;
    cout << "Ingrese la materia: ";
    cin >> alum1.materia;
    cout << "Ingrese la primer nota del alumno: ";
    cin >> alum1.nota1;
    cout << "Ingrese la segunda nota del alumno: ";
    cin >> alum1.nota2;
    
    // muestro results
    cout << "Datos del socio: " << endl;
    cout << "DNI: " << sos1.dni << ", Nombre y Apellido: " << sos1.nomb  << " " << sos1.apellido<< ", Numero de afiliado: " << sos1.numAfi << ", Anio de afiliacion: " << sos1.anioAfi << endl;

    cout << endl;

    cout << "Datos del Alumno: " << endl;
    cout << "Legajo: " << alum1.legajo << ", nombre y apellido: " << alum1.nomb << " " << alum1.apellido << ", Materia: " << alum1.materia << ", Nota 1: " << alum1.nota1 << ", Nota 2" << alum1.nota2;
    if(alum1.nota1 > 7 && alum1.nota2 > 7){
        cout << ", El alumno promociona.";
    } else {
        cout << ",El alumno no promociona.";
    }

    return 0;
}