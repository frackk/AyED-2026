// Dada una pila de enteros, mostrar solamente los valores pares y vaciar la pila.

#include <iostream>
using namespace std;

struct Nodo {
    int info;
    Nodo *sgte;
};

int pop(Nodo* &pila);

int main(){

    Nodo *pila = NULL;
    int valor;

    while(pila != NULL) {

        valor = pop(pila);

        if(valor%2==0){
            cout << valor << endl;
        }

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