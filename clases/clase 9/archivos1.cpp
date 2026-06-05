/*promedio notas 1er parcial*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct Alumno {
    int legajo;
    int dni;
    int nota1;
    int nota2;
};

int main () {

    // Paso 1
    FILE* K1151;

    // Pensar las variables que voy a necesitar
    Alumno raux;
    int prom;
    int sumatoria = 0;
    int contador = 0;

    // Paso 2
    K1151 = fopen("K1151.dar","rb");

    // Paso 3 y 4
    fread(&raux,sizeof(struct Alumno),1,K1151);
    while(!feof(K1151)){
        
        // Proceso
        sumatoria = sumatoria + raux.nota1;
        contador++;

        // Esto lo hago para ver el contenido, no lo pide el ejercicio
        cout << "El legajo es: " << raux.legajo << endl;
        cout << "El DNI es: " << raux.dni << endl;
        cout << "La nota 1 es: " << raux.nota1 << endl;
        cout << "La nota 2 es: " << raux.nota2 << endl;
        
        fread(&raux,sizeof(struct Alumno),1,K1151);
    }

    // Paso 5
    fclose(K1151);

    if(contador>0) {
        prom = sumatoria/contador;
        cout << "El promedio es:" << prom << endl;
    } else {
        cout << "No se pudo calcular el promedio." << endl;
    }

    return 0;
}