#include <iostream>
#include <string>
#include <string.h>
using namespace std;

struct Nodo {
	int info;
    Nodo* sgte;
};

#ifndef funciones
#define funciones
//Vectores
void agregar(int arr[], int n, int& len, int v);
void mostrar(int arr[], int len); 
void inicializar(int arr[],int n);
int buscar(int arr[], int len, int v);  
void eliminar(int arr[], int& len, int pos);  
void insertar(int arr[], int& len, int v, int pos);
int insertarOrdenado(int arr[], int& len, int v); 
int buscaEInserta(int arr[], int& len, int v, bool& enc);

//Burbuja
void burbuja(int vec[],int len);
//Búqueda Binaria
int busquedaBinaria(int vec[],int len, int valor);
//listas
void agregarNodo(Nodo*& lista, int x);
void mostrar(Nodo* lista);
void liberar(Nodo*& lista);
Nodo* buscar(Nodo* lista, int v);
void eliminar(Nodo*& lista, int v);
int eliminarPrimerNodo(Nodo*& lista);
Nodo* insertarOrdenado(Nodo*& lista, int v);
void ordenar(Nodo*& lista);
Nodo* buscaEInsertaOrdenado(Nodo*& lista, int v, bool& enc);
#endif

//