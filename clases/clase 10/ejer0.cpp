/*Ejercicio 1 – Crear dos vectores a partir de un archivo Se tiene un archivo de registros de tamaño fijo llamado ALUMNOS.DAT con el siguiente formato: 
• LEGAJO: Número de legajo / Numérico de hasta 6 cifras. 
• NOTA: Nota final / Numérico de 0 a 10. Se pide realizar un programa que lea el archivo y genere dos vectores: 
• VEC_APROBADOS: con los legajos de los alumnos que tengan nota mayor o igual a 6. 
• VEC_DESAPROBADOS: con los legajos de los alumnos que tengan nota menor a 6.*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct Alumnos{
    int legajo;
    int nota;
};

int main(){

    FILE* Alum;
    Alumnos rcarga;

    Alum = fopen("ALUMNOS.dat","wb");

    cout << "ingrese un legajo o 0 para terminar" << endl;
    cin >> rcarga.legajo;

    while(rcarga.legajo!=0){

        cout << "ingrese la nota" << endl;
        cin >> rcarga.nota;

        fwrite(&rcarga,sizeof(struct Alumnos),1,Alum);
        
        cout << "ingrese un legajo o 0 para terminar" << endl;
        cin >> rcarga.legajo;
    };

    fclose(Alum);

    return 0;
}