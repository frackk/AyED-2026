//Dadas una pila de enteros PilaA y una cola de enteros ColaB, generar una lista ordenada ListaC que contenga todos los valores pares de ambas estructuras, sin repetir valores.

#include <iostream>
using namespace std;

struct Nodo {
    int info;
    Nodo *sgte;
};

int pop(Nodo* &pila);
int suprimir(Nodo*&colafte, Nodo*&colafin);
Nodo* insertarOrdenado(Nodo*& lista, int v);
void eliminar(Nodo*& lista, int v);
Nodo* buscar(Nodo* lista, int v);

int main(){

    Nodo *pilaA; // 1 2 3 4 5 6 7 
    int valorPila;

    Nodo *colaBfte; // 7 6 5 4 3 2 1 
    Nodo *colaBfin;
    int valorCola;

    Nodo *listaC = NULL;
    Nodo *listaAux = NULL; // 2 3 6 8 10 12
    Nodo *valorLista;

    while(pilaA != NULL || colaBfte != NULL){
        
        valorPila = pop(pilaA);
        if(valorPila%2==0){
            insertarOrdenado(listaAux,valorPila);
        }

        valorCola = suprimir(colaBfte, colaBfin);
        if(valorCola%2==0){
            insertarOrdenado(listaAux, valorCola);
        }

    }

    while(listaAux != NULL){
        valorLista = buscar(listaC,listaAux->info);
    }



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

void eliminar(Nodo*& lista, int v){
	Nodo* aux = lista;
	Nodo* ant = NULL;
	
	while(aux != NULL && aux->info != v){
		ant = aux;
		aux = aux->sgte;
	}
	
	if(ant != NULL){
		ant->sgte = aux->sgte;
	} else {
		lista = aux->sgte;
	}
	
	delete aux;
}

Nodo* buscar(Nodo* lista, int v){
	Nodo* aux = lista;
	
	while(aux != NULL && aux->info != v){
		aux = aux->sgte;
	}
	
	return aux;
}