/* 4) Dadas 1 Pila de enteros y 1 Cola de enteros, se pide cargar la UNION ambos en una Lista Ordenada y mostrarla por pantalla.*/

#include <iostream>
using namespace std;

struct Nodo{
    int info;
    Nodo *sgte;
};

int pop(Nodo* &pila);
int suprimir(Nodo*&colafte, Nodo*&colafin);
Nodo* insertarOrdenado(Nodo*& lista, int v);
void mostrar(Nodo* lista);

int main(){

    Nodo *pila;
    int valorPila;

    Nodo *colaFte;
    Nodo *colaFin;
    int valorCola;

    Nodo *lista = NULL;
    Nodo *listAux = NULL;

    while(pila != NULL){
        valorPila = pop(pila);
        insertarOrdenado(listAux,valorPila);
    }

    while(colaFte != NULL){
        valorCola = suprimir(colaFte,colaFin);
        insertarOrdenado(listAux,valorCola);
    }

    while(listAux != NULL){
        insertarOrdenado(lista,listAux->info);
    }

    mostrar(lista);

    return 0;
}

int pop(Nodo* &pila){
	int ret = pila -> info; // aseguro guardar la variable de retorno
	Nodo* aux = pila;
	pila = aux -> sgte; 	// pila = pila -> sgte
	delete(aux);
	return ret;
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

void mostrar(Nodo* lista){
	Nodo* aux = lista;
	
	while(aux != NULL){
		cout << aux->info << endl;
		aux = aux->sgte;
	}
}