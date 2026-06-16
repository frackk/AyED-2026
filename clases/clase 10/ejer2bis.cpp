/*Ejercicio 2 – Calcular información de un archivo Se tiene un archivo de registros de tamaño fijo llamado EMPLEADOS.DAT con el siguiente formato: • LEGAJO: Número de empleado / Numérico de hasta 6 cifras. • CODEMP: Código del empleado / 8 cifras. • SUELDO: Importe del sueldo / Numérico con 2 decimales. Se pide realizar un programa que determine: 1. Cantidad total de empleados. 2. Sueldo promedio. 3. Cantidad de empleados con sueldo superior a $1.500.000.*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct Empleados{
    int legajo;
    int codEmp;
    int sueldo;
};

int main (){

    FILE*Empl;

    Empleados raux;

    Empl = fopen("EMPLEADOS.DAT","rb");

    int cantidadEmpl=0;
    int cantidadEmplSuperior=0;
    int sumatoria=0;
    int promedio;

    fread(&raux,sizeof(struct Empleados),1,Empl);

    while(!feof(Empl)){
        cantidadEmpl++;

        if(raux.sueldo>1500000){
            cantidadEmplSuperior++;
        }

        sumatoria = sumatoria + raux.sueldo;

        fread(&raux,sizeof(struct Empleados),1,Empl);
    }

    fclose(Empl);


    if(cantidadEmpl!=0){
        promedio = sumatoria/cantidadEmpl;
    } else {
        promedio = 0;
    }
    
    cout << "Cantidad de empleados: " << cantidadEmpl << endl;
    cout << "sueldo promedio: " << promedio << endl;
    cout << "Cantidad de empleados con sueldo superior a 1500000: " << endl;

    return 0;
}