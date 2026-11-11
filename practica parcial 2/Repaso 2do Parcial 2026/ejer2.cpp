// se tiene un vector de los productos de la empresa TecnoK, que contiene todos los productos registrados con los siguientes campos: Códogo de Producto, Precio, Stock Disponible, Además, se cuenta con una lista ordenada que contiene las ventas realizadas durante el día; cada nodo de la lista contiene el códogo de Producto, la Canditdad Vendida y el importe Total de la Venta.

// Se pide actualizar el vector de productos con la informacion que hay en la lista, SOLO para el campo Stock Disponible, descontando las unidades vendidas de cada producto, si el stock disponible no alcanza para cubrir la cantidad vendida, no se deberá modificar el stock de ese producto.

// se sabe que como maximo hay 100 productos registrados en el vector.

#include <iostream>
using namespace std;

struct productos {
    int codProd;
    int precio;
    int stock;
};

struct listaInfo {
    int codProd;
    int cantVentas;
    int importeTot;
};

struct Nodo {
    listaInfo info;
    Nodo *sgte;
};

int buscar(productos vec[],int len, int v);
// Nodo* buscar(Nodo* lista, int v);
void ejercicio(productos vec[], int len, Nodo *lista);
void liberar(Nodo*& lista);

int main(){

    productos vector[100];
    int len;

    Nodo *Lista;

    ejercicio(vector,len,Lista);

    liberar(Lista);

    return 0;
}


void ejercicio(productos vec[], int len, Nodo *lista){

    Nodo *auxLista = lista;
    
    int pos=0;

    while(auxLista != NULL){

        pos = buscar(vec,len,auxLista->info.codProd);

        if(pos != -1) {
            if(vec[pos].stock >= auxLista->info.cantVentas){
                vec[pos].stock -= auxLista->info.cantVentas;
            } else {
                cout << "No hay suficiente Stock, no se puede actualizar el vector." << endl;
            }
        }

        auxLista = auxLista->sgte;
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