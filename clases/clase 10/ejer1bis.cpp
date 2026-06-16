/*Ejercicio 1 – Crear dos vectores a partir de un archivo Se tiene un archivo de registros de tamaño fijo llamado ALUMNOS.DAT con el siguiente formato: 
• LEGAJO: Número de legajo / Numérico de hasta 6 cifras. 
• NOTA: Nota final / Numérico de 0 a 10. Se pide realizar un programa que lea el archivo y genere dos vectores: 
• VEC_APROBADOS: con los legajos de los alumnos que tengan nota mayor o igual a 6. 
• VEC_DESAPROBADOS: con los legajos de los alumnos que tengan nota menor a 6.*/

#include <iostream>
#include <stdio.h>
using namespace std;

void incicializar(Alumnos vec[], int cantPos, Alumnos valorIni);
void insertar(Alumnos vec[], int &len, Alumnos valor, int pos);
void insertarOrdendo(Alumnos vec[],int &len,Alumnos valor);

struct Alumnos {
    int legajo;
    int nota;
};

int main(){

    Alumnos vec_Aprobados[10];
    int lenA;

    Alumnos vec_Desaprobados[10];
    int lenD;

    // inicializo los vecs.
    incicializar(vec_Aprobados,lenA,0);
    incicializar(vec_Desaprobados,lenD,0);

    FILE* Alumn;

    Alumnos raux;

    Alumn = fopen("ALUMNOS.dat","rb");

    fread(&raux,sizeof(struct Alumnos),1,Alumn);

    while(!feof(Alumn)){
        
        if(raux.nota > 5) {
            insertarOrdendo(vec_Aprobados,lenA,raux.legajo);
        } else {
            insertarOrdendo(vec_Desaprobados,lenD,raux.legajo);
        }

        fread(&raux,sizeof(struct Alumnos),1,Alumn);
    }

    fclose(Alumn);

    return 0;
}

void incicializar(Alumnos vec[], int cantPos, Alumnos valorIni){
    for (int i=0;i<cantPos;i++){
        vec[i] = valorIni;
    }
}

void insertar(Alumnos vec[], int &len, Alumnos valor, int pos){
    for(int i=len;i>pos;i--){
        vec[i] = vec[i-1];
    }
    vec[pos] = valor;
    len++;
}

void insertarOrdendo(Alumnos vec[],int &len,Alumnos valor){
    int i=0;
    while(i<len && vec[i] < valor) {
        i++;
    }
    if(i==len){
        vec[len] = valor;
        len++;
    } else {
        insertar(vec,len,valor,i);
    }
}