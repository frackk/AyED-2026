// Un procedimiento que genere una lista ordenada a partir de la union de dos colas y un vector.

#include <iostream>
using namespace std;

struct Nodo {
    int info;
    Nodo *sgte;
};

int suprimir(Nodo*&colafte, Nodo*&colafin);
void listOrdenada(Nodo *colaAFte, Nodo *colaAFin, Nodo *colaBFte, Nodo *colaBFin, Nodo vec[], int len);
Nodo* insertarOrdenado(Nodo*& lista, int v);

int main(){

    Nodo *Lista = NULL;

    return 0;
}

int suprimir(Nodo*&colafte, Nodo*&colafin){
    int ret;
    ret = colafte -> info;
    Nodo*aux = colafte;
    colafte = aux -> sgte; // colafte = colafte -> sgte;
    
    if(colafte==NULL){
        colafin = NULL;
    }
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

void listOrdenada(Nodo *colaAFte, Nodo *colaAFin, Nodo *colaBFte, Nodo *colaBFin, int vec[], int len){

    Nodo *lista = NULL;
    
    int aux;

    while(colaAFte != NULL){
        aux = suprimir(colaAFte,colaAFin);
        insertarOrdenado(lista,aux);
    }

    while(colaBFte != NULL){
        aux = suprimir(colaBFte,colaBFin);
        insertarOrdenado(lista,aux);
    }

    for(int i=0;i<len;i++){
        insertarOrdenado(lista,vec[i]);
    }

}

