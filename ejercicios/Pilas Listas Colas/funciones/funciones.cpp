#include <iostream>
#include <string>
#include "funciones.hpp"
using namespace std;

//Vectores
void agregar(int arr[], int n, int& len, int v){
	if(len < n){
		arr[len] = v;
		len++;
	} else {
		cout << "El vector esta lleno" << endl;
	}
}

void mostrar(int arr[], int len){
	
	for(int i=0; i < len; i++){
		cout << arr[i] << endl;
	}
	
}

void inicializar(int arr[],int n){
	for(int i=0; i < n; i++){
		arr[i] = 0;
	}
}

int buscar(int arr[], int len, int v){
	int pos;
	int i =0;
	
	while(i < len && arr[i] != v){
		i++;
	}
	
	if(i != len){ // i != len condición alternativa
		pos = i;
	} else {
		pos = -1;
	}
	
	return pos;	
}

void eliminar(int arr[], int& len, int pos){
	
	for(int i=pos; i < len-1; i++){
		arr[i] = arr[i+1];
	}
	
	arr[len-1] = 0;
	
	len--;
}


void insertar(int arr[], int& len, int v, int pos){
	
	//for(int i = len-1; i >= pos; i--){
	//	arr[i+1] = arr[i];
	//}
	
	//Opción 2
	for(int i = len; i > pos; i--){
		arr[i]=arr[i-1];
	}
	
	arr[pos] = v;
	len++;
}

int insertarOrdenado(int arr[], int& len, int v){
	int i = 0;
	
	while(i < len && arr[i] < v ){
		i++;
	} 
	
	insertar(arr,len,v,i);
	
	return i;
}

int buscaEInserta(int arr[], int& len, int v, bool& enc){
	int pos = buscar(arr,len,v);
	
	if(pos == -1){
		enc = false;
		pos = insertarOrdenado(arr,len,v);
	} else {
		enc = true;
	}
	
	return pos;
}

//Burbuja
void burbuja(int vec[],int len){
	int temp;
	
	for(int i=0; i < len-1; i++){
		for(int j=0; j < len-1-i ; j++){
			if(vec[j] > vec[j+1]){
				temp = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = temp;
			}
			
		}
	}
}

//Búqueda Binaria
int busquedaBinaria(int vec[],int len, int valor){
	int inicio = 0;
	int fin = len-1;
	int medio = (inicio + fin) / 2;
	int pos = -1;
	
	while(inicio <= fin){
		if(vec[medio] == valor){
			pos = medio;
			break;
		} else if (valor > vec[medio]){
			inicio = medio + 1;
		} else {
			fin = medio - 1;
		}
		
		medio = (inicio + fin) / 2;		
	}
	
	return pos;
	
}

//listas
void agregarNodo(Nodo*& lista, int x){
	
	Nodo* nuevo = new Nodo();
	nuevo->info = x;
	nuevo->sgte = NULL;
	
	if(lista == NULL){
		lista = nuevo;
	} else {
		Nodo* aux = lista;
		while(aux->sgte != NULL){ // me posiciono en el último nodo
			aux = aux->sgte;
		}
		aux->sgte = nuevo;
	}	
}

void mostrar(Nodo* lista){
	Nodo* aux = lista;
	
	while(aux != NULL){
		cout << aux->info << endl;
		aux = aux->sgte;
	}
}

void liberar(Nodo*& lista){
	Nodo* aux;
	while(lista != NULL){
		aux = lista;
		lista = lista->sgte;
		delete aux;
	}
	
}

Nodo* buscar(Nodo* lista, int v){
	Nodo* aux = lista;
	
	while(aux != NULL && aux->info != v){
		aux = aux->sgte;
	}
	
	return aux;
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

int eliminarPrimerNodo(Nodo*& lista){
	int retorno = lista->info;
	Nodo* aux = lista;
	lista = aux->sgte;
	
	delete aux;
	
	return retorno;
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

void ordenar(Nodo*& lista){
	Nodo* listaAux = NULL;
	int v;
	
	while(lista != NULL){
		v = eliminarPrimerNodo(lista);
		insertarOrdenado(listaAux,v);
	}
	
	lista = listaAux;
}

Nodo* buscaEInsertaOrdenado(Nodo*& lista, int v, bool& enc){
	Nodo* nodoBuscado = buscar(lista,v);
	if(nodoBuscado != NULL){
		enc = true;
	} else {
		enc = false;
		nodoBuscado = insertarOrdenado(lista,v);
	}
	
	return nodoBuscado;
}

// Pilas
Nodo* pila = NULL; // definio el puntero e inicializo

//subprogramas
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

// la pila se carga con un WHILE. pero no se (sofi :3)

// COLAS

// defino la cola -> creo 2 punteros
Nodo* colaFte = NULL; // defino puntero 1
Nodo* colaFin = NULL; // defino puntero 2

void agregar(Nodo* &cFte, Nodo* &cFin, int valor){
	// crear el nodo y cargarlo
	Nodo* nuevo = new Nodo();
	nuevo -> info = valor;
	nuevo -> sgte = NULL;
	
	if(cFte == NULL){
		cFte = nuevo;
	} else {
		cFin -> sgte = nuevo;
	}
	cFin = nuevo;
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