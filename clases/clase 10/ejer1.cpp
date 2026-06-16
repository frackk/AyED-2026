/*Ejercicio 1 – Crear dos vectores a partir de un archivo Se tiene un archivo de registros de tamaño fijo llamado ALUMNOS.DAT con el siguiente formato: • LEGAJO: Número de legajo / Numérico de hasta 6 cifras. • NOTA: Nota final / Numérico de 0 a 10. Se pide realizar un programa que lea el archivo y genere dos vectores: • VEC_APROBADOS: con los legajos de los alumnos que tengan nota mayor o igual a 6. • VEC_DESAPROBADOS: con los legajos de los alumnos que tengan nota menor a 6.*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct Alumnos{
    int legajo;
    int nota;
};

void inicializar (Alumnos vec[], int cantPos, Alumnos valorIni);
void mostrar (Alumnos vec[], int len);
void insertar (Alumnos vec[], int &len, Alumnos valor, int pos);
void insertarOrdenado (Alumnos vec[], int &len, Alumnos valor);

int main(){

    Alumnos Vec_a[50];
    int lenA = 0;

    Alumnos Vec_desaprobados[50];
    int lenD = 0;

    Alumnos valorInicial;
    valorInicial.legajo = 0;
    valorInicial.nota = 0;

    inicializar(Vec_a,50,valorInicial);
    inicializar(Vec_desaprobados,50,valorInicial);

    Alumnos raux;

    FILE* Alum;

    Alum = fopen("ALUMNOS.dar","rb");

    fread(&raux,sizeof(struct Alumnos),1,Alum);
    while(!feof(Alum)){
        if(raux.nota>=6){
            insertarOrdenado(Vec_a,lenA,raux);
        } else {
            insertarOrdenado(Vec_desaprobados,lenD,raux);
        }

        fread(&raux,sizeof(struct Alumnos),1,Alum);
    }

    fclose(Alum);

    mostrar(Vec_a,lenA);
    mostrar(Vec_desaprobados,lenD);

    return 0;
}

    // el ejerc no funciona porque habría que ajustar los procedimientos..

void inicializar (int vec[], int cantPos, int valorIni) {
   for(int i=0;i<cantPos;i++){
      vec[i] = valorIni;
   }
}

void mostrar (int vec[], int len){
   for(int i=0;i<len;i++){
      cout << "nota ingresada: " << vec[i] << endl;
   }
}

void insertar (int vec[], int &len, int valor, int pos) {
   for (int i=len; i>pos; i--) {
      vec[i] = vec[i-1];
   }
   vec[pos]=valor;
   len++;
}

void insertarOrdenado (int vec[], int &len, int valor) {
   int i = 0;
   while (i<len && vec[i]<=valor) {
      i++;
   }

   if (i==len) {
      vec[len]=valor;
      len++;
   } else {
      insertar (vec, len, valor, i);
   }

}