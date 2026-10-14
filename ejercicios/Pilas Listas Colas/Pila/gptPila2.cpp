// Dada una pila de enteros, generar otra pila solamente con los valores pares.

#include <iostream>
using namespace std;

struct Nodo {
    int info;
    Nodo *sgte;
};

void push(Nodo* &pila, int valor);
int pop(Nodo* &pila);

int main(){

    Nodo *pila1 = NULL;
    Nodo *pila2 = NULL;

    int valor;

    while(pila1 != NULL){

        valor = pop(pila1);

        if(valor%2==0){
            push(pila2,valor);
        }

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