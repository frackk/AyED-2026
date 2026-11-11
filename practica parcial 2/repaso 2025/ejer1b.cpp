/*una funcion que retorne una lista ordenada a partir de la interseccion de 1 lista y una pila.*/
#include <iostream>

struct Nodo{
    int info;
    Nodo *sgte;
};

int pop(Nodo* &pila);
Nodo* buscar(Nodo* lista, int v);
Nodo* insertarOrdenado(Nodo*& lista, int v);

Nodo *listaOrdenada(Nodo *lista,Nodo *pila){
    
    Nodo *listaOrden = NULL;

    Nodo *auxLista = lista;

    int aux;

    while(pila != NULL){
        aux = pop(pila);
        if((buscar(auxLista,aux)) != NULL){
            insertarOrdenado(listaOrden,aux);
        }
        auxLista = auxLista->sgte;
    }

    return listaOrden;
}