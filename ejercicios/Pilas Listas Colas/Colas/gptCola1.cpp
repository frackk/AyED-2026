//Dada una ColaA de enteros, generar un vector con todos los valores positivos de la cola. Al terminar, ColaA debe quedar exactamente como estaba originalmente.

#include <iostream>
using namespace std;

struct Nodo {
    int info;
    Nodo *sgte;
};

void inicializar  (int vec[], int cantPos,  int valIni);
void insertar (int vec[], int &len, int valor, int pos);
void insertarOrdenado(int vec[], int &len, int valor);
void agregarVec(int vec[], int capacidad, int& len, int valor);

void agregar(Nodo* &cFte, Nodo* &cFin, int valor);
int suprimir(Nodo*&colafte, Nodo*&colafin);

int main(){

    Nodo *colaAFte = NULL;
    Nodo *colaAFin = NULL;

    Nodo *cAuxFte = NULL;
    Nodo *cAuxFin = NULL;

    int vector[15];
    int len = 0;
    inicializar(vector,15,0);

    int valor;
    int valorAux;

    while(colaAFte != NULL){
        
        valor = suprimir(colaAFte,colaAFin);

        if(valor > 0){
            agregarVec(vector,15,len,valor);
        }
        agregar(cAuxFte,cAuxFin,valor);
    }

    while(cAuxFte != NULL){
        
        valorAux = suprimir(cAuxFte,cAuxFin);
        agregar(colaAFte,colaAFin,valorAux);

    }

    return 0;
}

void agregarVec(int vec[], int capacidad, int& len, int valor){
	if(len < capacidad){
		vec[len] = valor;
		len++;
	} else {
		cout << "El vector esta lleno" << endl;
	}
}

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