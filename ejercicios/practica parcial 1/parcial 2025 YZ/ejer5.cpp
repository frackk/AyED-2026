/*
se tiene un archivo de registros del curso K1151 con las notas finales de los alumnos (100 alumnos maximo). El formato del registro de este archivo es el siguiente:

Legajo; Nota; Estado ('P' Promociona, 'R' Regulariza, 'D' desaprobado).

se pide:
1) realizar un programa que genere un archivo nuevo con los alumnos promocionados unicamente. Con el siguiente formato: Legajo, Nota
2) indique por pantalla el promedio de las notas de todos los alumnos.
3) Indique por pantalla la cantidad de alumnos desaprobados.
*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct NotasK1151{
    int legajo;
    int nota;
    char estado;
};

struct Promocionados{
    int legajo;
    int nota;
};

int main(){

    FILE* NotasAlum;
    NotasK1151 raux;
    NotasAlum = fopen("NOTAS_CURSOK1151.dat","rb");

    FILE* PromoArch;
    Promocionados rcarga;
    PromoArch = fopen("PROMOCIONADOS.dat","wb");

    int sumatoria=0;
    int prom;
    int cantAlum=0;
    int cantDesaprobados=0;

    fread(&raux,sizeof(struct NotasK1151),1,NotasAlum);

    while(!feof(NotasAlum)){

        if(raux.estado == 'P'){
            rcarga.legajo = raux.legajo;
            rcarga.nota = raux.nota;
            fwrite(&rcarga,sizeof(struct Promocionados),1,PromoArch);
        } else if (raux.estado == 'D'){
            cantDesaprobados++;
        }

        sumatoria += raux.nota;
        cantAlum++;

        fread(&raux,sizeof(struct NotasK1151),1,NotasAlum);

    }

    fclose(NotasAlum);
    fclose(PromoArch);

    if(cantAlum!=0){
        prom = sumatoria/cantAlum;
        cout << "El promedio de todas las notas de los alumnos es: " << prom << endl;
    } else {
        cout << "Es imposible calcular el promedio." << endl;
    }

    cout << "La cantidad de alumnos desaprobados es: " << cantDesaprobados << endl;

    return 0;
}