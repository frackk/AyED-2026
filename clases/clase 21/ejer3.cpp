/*La universidad tiene un archivo binario de ALUMNOS.dat que contiene los registros de Legajo, y el Promedio general de la carrera, se pide generar un programa que ordene fiscamente el archivo segun el promedio de los alumnos de mayo a menor*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct Tinfo {
    int legajo;
    int promedio;
};

struct Nodo {
    Tinfo info;
    Nodo *sgte;
};

Nodo* insertarOrdenado(Nodo*& lista, Tinfo v);
void liberar(Nodo*& lista);

int main(){

    Nodo *listaAlum = NULL;
    FILE* Alum;
    Tinfo raux;

    Alum = fopen("ALUMNOS.dat","rb");

    fread(&raux,sizeof(struct Tinfo),1,Alum);

    while(!feof(Alum)){
        insertarOrdenado(listaAlum,raux);
        fread(&raux,sizeof(struct Tinfo),1,Alum);
    }

    fclose(Alum);

    Alum = fopen("ALUMNOS.dat","wb");

    Nodo *auxLista = listaAlum;

    while(auxLista != NULL){
        fwrite(&auxLista->info,sizeof(struct Tinfo),1,Alum);
        auxLista = auxLista->sgte;
    }

    fclose(Alum);
    liberar(listaAlum);

    return 0;
}

Nodo* insertarOrdenado(Nodo*& lista, Tinfo v){
    // insertarOrdenado
}

void liberar(Nodo*& lista){
	Nodo* aux;
	while(lista != NULL){
		aux = lista;
		lista = lista->sgte;
		delete aux;
	}
	
}