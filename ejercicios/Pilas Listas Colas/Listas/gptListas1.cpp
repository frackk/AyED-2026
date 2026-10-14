//Dados un vector de 10 enteros y una lista de enteros, generar una segunda lista ordenada únicamente con los valores del vector que también se encuentren en la lista original.

#include <iostream>
using namespace std;

struct Nodo{
    int info;
    Nodo*sgte;
};

Nodo* insertarOrdenado(Nodo*& lista, int v);
Nodo* buscar(Nodo* lista, int v);
int main (){

    Nodo* listaini; //como esta dada, no inicia en NULL
    Nodo* listafin = NULL;
    int vec[10];
    int len =10;

    for(int i=0; i<len; i++){
       if(buscar(listaini, vec[i]) != NULL){  //buscar compara los valores de la lista con los del vector, si estos son iguales, los inserta en la nueva lista
        insertarOrdenado(listafin, vec[i]);
       }
    }


    return 0;
}

Nodo* buscar(Nodo* lista, int v){
    Nodo* aux = lista;
    
    while(aux != NULL && aux->info != v){
        aux = aux->sgte;
    }
    
    return aux;
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