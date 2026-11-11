/*Un procedimiento que genere una lista ordenada a partir de la union de dos colas y un vector.*/
#include <iostream>;

struct Nodo {
    int info;
    Nodo *sgte;
};

int suprimir(Nodo *&ColaFte, Nodo *&ColaFin);
Nodo* insertarOrdenado(Nodo*& lista, int v);

void listaOrdenada(Nodo *colaAFte, Nodo *colaAFin, Nodo *colaBFte, Nodo *colaBFin, int vec[], int len){

    Nodo *listaOrden = NULL;

    int aux;

    while(colaAFte != NULL){
        aux = suprimir(colaAFte,colaAFin);
        insertarOrdenado(listaOrden,aux);
    }

    while(colaBFte != NULL){
        aux = suprimir(colaBFte,colaBFin);
        insertarOrdenado(listaOrden,aux);
    }

    for(int i=0;i<len;i++){
        insertarOrdenado(listaOrden,vec[i]);
    }

}