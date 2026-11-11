/*Ejercicio 3 (1,5 puntos)
Defina los siguientes registros, defina 1 variable para la implementación de cada uno y cargarle valores a elección en
un programa principal.
o Laboratorio: Fecha; DNI; Nombre y Apellido; Número de Orden; Cantidad de estudios
o Depósito: ID; Tipo; Descripción; Unidades en stock; Peso
*/

#include <iostream>
using namespace std;

struct Laboratorio {
    int fecha;
    int dni;
    char nombre[32];
    char apellido[32];
    int numOrden;
    int cantEstudios;
};

struct Deposito {
    int id;
    char tipo;
    char descripcion[32];
    int uniStock;
    float peso;
};

int main(){

    Laboratorio lab;
    Deposito dep;

    cout << "Ingrese los siguientes datos de Laboratorio en el siguiente orden: fecha, DNI, nombre, apellido, numero de orden, cantidad de estudios." << endl;
    cin >> lab.fecha >> lab.dni >> lab.nombre >> lab.apellido >> lab.numOrden >> lab.cantEstudios;

    cout << "Ingresar los siguientes datos de Deposito en el siguiente orden: ID, tipo (una letra), descripcion, unidades en stock, peso." << endl;
    cin >> dep.id >> dep.tipo >> dep.descripcion >> dep.uniStock >> dep.peso;

    return 0;
}