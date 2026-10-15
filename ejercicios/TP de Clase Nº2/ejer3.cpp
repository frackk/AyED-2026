/* 3) Un procedimiento que genere una lista sin orden a partir de la intersección de una lista y un vector.*/

#include <iostream>
using namespace std;

struct Nodo{
    int info;
    Nodo *sgte;
};
Nodo* insertarOrdenado(Nodo*& lista, int v);
Nodo* buscar(Nodo* lista, int v);
void genLista(Nodo *lista, int vec[], int len);

int main (){

    int vector[10];
    int len;

    Nodo *lista1;

    genLista(lista1,vector,len);

    return 0;
}

Nodo* insertarOrdenado(Nodo*& lista, int v){
	
	Nodo* nuevo = new Nodo();
	nuevo->info = v;
	nuevo->sgte = NULL;
	
	Nodo* aux = lista;
	Nodo* ant = NULL;
	
	while(aux != NULL && aux->info <= v){
		ant = aux;
		aux = aux->sgte;
	}
	
	if(ant != NULL){
		ant->sgte = nuevo;
	} else {
		lista = nuevo;
	}
	
	nuevo->sgte = aux;
	
	return nuevo;
}

Nodo* buscar(Nodo* lista, int v){
	Nodo* aux = lista;
	
	while(aux != NULL && aux->info != v){
		aux = aux->sgte;
	}
	
	return aux;
}

void genLista(Nodo *lista, int vec[], int len){
    Nodo *listaNueva = NULL;

    for (int i=0;i<len;i++){
        if(buscar(lista,vec[i]) != NULL){
            insertarOrdenado(listaNueva,vec[i]);
        }
    }
}