/*Se tiene un archivo de resultados academicos Finales.dat (sin orden).
Numero de Legajo: 999999
Codigo de Materia: 9999
Nota Obtenida: 99
cantidad de intentos: 99

Se pide: 
a) Ordenar el archivo Finales.dat por Numero de legajo.
b) Armar una lista ordenada por Nota Obtenida, SOLO si la nota obtenida es mayor o igual a 6 y la cantidad de intentos no supera los 2, e imprimir la lista por pantalla.

Nota: Solo se puede lere 1 vez el archivo.*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct resultAcademicos {
    int legajo;
    int codMateria;
    int nota;
    int cantIntentos;
};

struct Nodo {
    resultAcademicos info;
    Nodo *sgte;
};

Nodo* insertarOrdenadoPorNota(Nodo*& lista, resultAcademicos v);
Nodo* insertarOrdenadoPorLegajo(Nodo*& lista, resultAcademicos v);
void liberar(Nodo*& lista);
void mostrar(Nodo* lista);

int main(){

    Nodo* listaResult = NULL;
    Nodo* listaOrdenadaNotas = NULL;

    FILE* Resul;
    resultAcademicos raux;

    Resul = fopen("Finales.dat","rb");

    fread(&raux,sizeof(struct resultAcademicos),1,Resul);

    while(!feof(Resul)){
        insertarOrdenadoPorLegajo(listaResult,raux);

        if(raux.nota >= 6 && raux.cantIntentos <= 2){
            insertarOrdenadoPorNota(listaOrdenadaNotas,raux);        } 
        
        fread(&raux,sizeof(struct resultAcademicos),1,Resul);
    }

    fclose(Resul);
    
    Resul = fopen("Finales.dat","wb");

    Nodo* auxLista = listaResult;

    while(auxLista != NULL){
        fwrite(&auxLista->info,sizeof(struct resultAcademicos),1,Resul);
        auxLista = auxLista->sgte;
    }

    fclose(Resul);

    mostrar(listaOrdenadaNotas);

    liberar(listaResult);
    liberar(listaOrdenadaNotas);

    return 0;
}

Nodo* insertarOrdenadoPorNota(Nodo*& lista, resultAcademicos v){
    //ordenado x nota
}

Nodo* insertarOrdenadoPorLegajo(Nodo*& lista, resultAcademicos v){
    //ordenado x Legajo
}

void liberar(Nodo*& lista){
    // liberar
}

void mostrar(Nodo* lista){
    //mostrar
}