/* Dadas 2 Colas de enteros (Cola A y Cola B) genere la UNION de ambos en Cola C. */

#include <iostream>
using namespace std;

struct Nodo{
    int info;
    Nodo *sgte;
};

void agregar(Nodo* &cFte, Nodo* &cFin, int valor);
int suprimir(Nodo*&colafte, Nodo*&colafin);

int main (){

    Nodo *colaAfte;
    Nodo *colaAfin;
    int valorColaA;

    Nodo *colaBfte;
    Nodo *colaBfin;
    int valorColaB;

    Nodo *colaCfte = NULL;
    Nodo *colaCfin = NULL;

    while(colaAfte != NULL || colaBfte != NULL){

        valorColaA = suprimir(colaAfte,colaAfin);
        agregar(colaCfte,colaCfin,valorColaA);

        valorColaB = suprimir(colaBfte,colaBfin);
        agregar(colaCfte,colaCfin,valorColaB);
    }

    return 0;
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