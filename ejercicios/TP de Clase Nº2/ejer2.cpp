/* 2) Dadas 2 Pilas de enteros (PilaA y PilaB) genere la UNION en la PilaC */

#include <iostream>
using namespace std;

struct Nodo{
    int info;
    Nodo *sgte;
};

void push(Nodo* &pila, int valor);
int pop(Nodo* &pila);

int main(){

    Nodo *pilaA;
    int valorPilaA;

    Nodo *pilaB;
    int valorPilaB;

    Nodo *pilaC = NULL;

    while(pilaA != NULL){

        valorPilaA = pop(pilaA);
        push(pilaC,valorPilaA);

    }

    while(pilaB != NULL){

        valorPilaA = pop(pilaB);
        push(pilaC,valorPilaB);

    }

    return 0;
}

void push(Nodo* &pila, int valor){
	
	// pedir memoria para crear el nodo
	Nodo* nuevo = new Nodo();

	// cargar el nodo y este nodo sea parte de la pila
	nuevo -> info = valor;
	nuevo -> sgte = pila;
	pila = nuevo; 
}

int pop(Nodo* &pila){
	int ret = pila -> info; // aseguro guardar la variable de retorno
	Nodo* aux = pila;
	pila = aux -> sgte; 	// pila = pila -> sgte
	delete(aux);
	return ret;
}