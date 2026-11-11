/*Una empresa posee un archivo binario de EMPLEADOS.dat que contiene registros con la siguiene informacion, Legajo, que es el numero que identifica al empleado, Sueldo mensual.
se pide realizar un programa que ordene por numero de legajo el archivo.*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct Tinfo {
    int legajo;
    int sueldo;
};

struct Nodo {
    Tinfo info;
    Nodo *sgte;
};

Nodo* insertarOrdenado(Nodo*& lista, Tinfo v);
void liberar(Nodo*& lista);

int main(){

    Nodo *listaEmpl = NULL;

    FILE* Empl;
    Tinfo raux;

    Empl = fopen("EMPLEADOS.dat","rb");

    fread(&raux,sizeof(struct Tinfo),1,Empl);

    while(!feof(Empl)){
        insertarOrdenado(listaEmpl,raux);
        fread(&raux,sizeof(struct Tinfo),1,Empl);
    }

    fclose(Empl);

    Empl = fopen("EMPLEADOS.dat","wb");
    Nodo *auxLista = listaEmpl;

    while(auxLista != NULL){
        fwrite(&auxLista->info,sizeof(struct Tinfo),1,Empl);
        auxLista = auxLista->sgte;
    }

    fclose(Empl);
    liberar(listaEmpl);

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