/*Ejercicio 3 (1,5 puntos)
Defina los siguientes registros, defina 1 variable para la implementación de cada uno y cargarle valores a elección en
un programa principal.
o Vehículo: Patente; Marca; Modelo; Año de fabricación
o Empleado: Legajo; Nombre y Apellido; Sector; Sueldo Básico; Antigüedad; Planta Permanente (Y o N)
*/

#include <iostream>
using namespace std;

struct Vehiculo{
    char patente[42];
    char marca[42];
    int modelo;
    int anioFab;
};

struct Empleado{
    int legajo;
    char nombre[42];
    char apellido[42];
    char sector[42];
    int sueldoBasico;
    int antiguedad;
    char plantaPerm;
};

int main(){

    Vehiculo vehi;
    Empleado empl;

    cout << "ingrese la patente del vehiculo: ";
    cin >> vehi.patente;

    cout << "ingrese la marca del vehiculo ";
    cin >> vehi.marca;

    cout << "ingrese el modelo del vehiculo: ";
    cin >> vehi.modelo;

    cout << "ingrese el anio de fabricacion del vehiculo: ";
    cin >> vehi.anioFab;


    cout << "ingrese el legajo del empleado: ";
    cin >> empl.legajo;

    cout << "ingrese el nombre del empleado: ";
    cin >> empl.nombre;

    cout << "ingrese el apellido del empleado: ";
    cin >> empl.apellido;

    cout << "ingrese el sector del empleado: ";
    cin >> empl.sector;

    cout << "ingrese el sueldo basico del empleado: ";
    cin >> empl.sueldoBasico;

    cout << "ingrese la antiguedad del empleado: ";
    cin >> empl.antiguedad;

    cout << "ingrese la planta permanente del empleado: ";
    cin >> empl.plantaPerm;

    while(empl.plantaPerm != 'Y' && empl.plantaPerm != 'N'){
        cout << "error, ingrese la planta permanente del empleado ( Y / N ): ";
        cin >> empl.plantaPerm;
    }

    cout << "la patente del vehiculo ingresado es: " << vehi.patente << endl;
    cout << "la marca del vehiculo ingresado es: " << vehi.marca << endl;
    cout << "el modelo del vehiculo ingresado es: " << vehi.modelo << endl;
    cout << "el anio de fabricacion del vehiculo ingresado es: " << vehi.anioFab << endl;

    cout << endl;

    cout << "el legajo ingresado del empleado es: " << empl.legajo << endl;
    cout << "el nombre y apellido ingresado del empleado es: " << empl.nombre << " " << empl.apellido << endl;
    cout << "el legajo ingresado del empleado es: " << empl.sector << endl;
    cout << "el legajo ingresado del empleado es: " << empl.sueldoBasico << endl;
    cout << "el legajo ingresado del empleado es: " << empl.antiguedad << endl;
    cout << "el legajo ingresado del empleado es: " << empl.plantaPerm << endl;

    return 0;
}