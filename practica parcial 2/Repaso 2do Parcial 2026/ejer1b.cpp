// una funcion que retorne una lista ordenada a partir de la interseccion de 1 lista y una pila.

#include <iostream>
using namespace std;

struct Nodo {
    int info;
    Nodo *sgte;
};

Nodo listaOrdenada(Nodo lista, Nodo pila);
int pop(Nodo* &pila);
Nodo* insertarOrdenado(Nodo*& lista, int v);
Nodo* buscar(Nodo* lista, int v);

int main(){

    return 0;
}

int pop(Nodo* &pila){
	int ret = pila -> info; // aseguro guardar la variable de retorno
	Nodo* aux = pila;
	pila = aux -> sgte; 	// pila = pila -> sgte
	delete(aux);
	return ret;
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


Nodo listaOrdenada(Nodo *lista, Nodo *pila){

    Nodo *listaOrden = NULL;

    int aux;

    while(pila != NULL){
        aux = pop(pila);

        if(buscar(lista,aux) != NULL){
            insertarOrdenado(listaOrden,aux);
        }
    }

    //return listaOrden;
}

Nodo* listaOrd(Nodo* lista, Nodo* pila){

    Nodo* listaf = NULL;

    int valorP;

    while(pila != NULL){
        valorP = pop(pila);
        
        if(buscar(lista,valorP) != NULL){
            insertarOrdenado(listaf,valorP);
        }
    }

    return listaf;
}


