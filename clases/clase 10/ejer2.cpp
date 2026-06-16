/*Ejercicio 2 – Calcular información de un archivo Se tiene un archivo de registros de tamaño fijo llamado EMPLEADOS.DAT con el siguiente formato: • LEGAJO: Número de empleado / Numérico de hasta 6 cifras. • CODEMP: Código del empleado / 8 cifras. • SUELDO: Importe del sueldo / Numérico con 2 decimales. Se pide realizar un programa que determine: 1. Cantidad total de empleados. 2. Sueldo promedio. 3. Cantidad de empleados con sueldo superior a $1.500.000.*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct Empleado{
    int legajo;
    int codEmp;
    int sueldo;
};

int main(){

    FILE* Empl;
    Empl = fopen("EMPLEADOS.dat","rb");

    Empleado raux;

    int cont=0;
    int suma=0;
    int cont2=0;

    fread(&raux,sizeof(struct Empleado),1,Empl);
    
    while(!feof(Empl)){

        cont++;
        suma=suma+raux.sueldo;
        if(raux.sueldo > 1500000) {
            cont2++;
        }

        fread(&raux,sizeof(struct Empleado),1,Empl);
    }

    fclose(Empl);

    if(cont>0) {
        cout << "El promedio salarial es: " << suma/cont << endl;
    }

    cout << "La cantidad de empleados con sueldo superior a 1500000 es " << cont2 << endl;
    return 0;
}