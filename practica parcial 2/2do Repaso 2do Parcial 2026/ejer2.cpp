/*Una empresa dedicada a la comercialización de artículos tecnológicos cuenta con un vector de productos que almacena la información de todos los artículos registrados. Cada elemento del vector contiene los siguientes campos: Código de Producto, Precio Unitario, Stock Disponible y Stock Mínimo. 
Además, se dispone de una lista simplemente enlazada, ordenada por Código de Producto, que contiene los movimientos de ventas realizados durante el día. Cada nodo de la lista almacena: Código de Producto y Cantidad Vendida.
Se pide:
1) Actualizar el vector de productos utilizando la información contenida en la lista, descontando del Stock Disponible las cantidades vendidas de cada producto. Si el stock disponible no alcanza para cubrir la cantidad vendida, no se deberá modificar el stock y se deberá registrar el código del producto en una nueva lista de productos con faltante de stock.
2) Generar una nueva lista simplemente enlazada con los productos cuyo stock disponible, luego de procesar las ventas, haya quedado por debajo del Stock Mínimo. Cada nodo deberá contener el Código de Producto y el Stock Disponible actualizado.
3) Informar la cantidad total de ventas que no pudieron concretarse por falta de stock y el importe total correspondiente a dichas ventas. Se sabe que como máximo hay 150 productos registrados en el vector.*/

 // UNF!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!1

#include <iostream>
using namespace std;

struct articulos {
    int codProd;
    int precio;
    int stock;
    int stockMinimo;
};

struct listaInfo {
    int codProd;
    int cantVentas;
};

struct listaStockDisp {
    int codProd;
    int stockDisp;
};

struct Nodo {
    listaInfo info;
    Nodo *sgte;
};

struct NodoStockDisp {
    listaStockDisp info;
    NodoStockDisp *sgte;
};

int buscar(articulos vec[], int len, int v);
Nodo* insertarOrdenado(Nodo*& lista, int v);
Nodo* insertarOrdenado2(NodoStockDisp*& lista, int v);
void ejercicio(articulos vec[], int len, Nodo *lista);

int main(){



    return 0;
}

int buscar(articulos vec[], int len, int v){
    // buscar
}

Nodo* insertarOrdenado(Nodo*& lista, int v){
	// insertarOrdenado
}

Nodo* insertarOrdenado2(NodoStockDisp*& lista, int v){
    // asd
}

void ejercicio(articulos vec[], int len, Nodo *lista){

    Nodo *listaSinStock = NULL;
    NodoStockDisp *listaStockMinimo = NULL;
    Nodo *auxLista = lista;

    int pos=0;

    while(auxLista != NULL){
        pos = buscar(vec,len,auxLista->info.codProd);

        if(pos != -1){
            if(vec[pos].stock >= auxLista->info.cantVentas){
                vec[pos].stock -= auxLista->info.cantVentas;
            } else {
                vec[pos].stock - auxLista->info.cantVentas;
                insertarOrdenado(listaSinStock,auxLista->info.cantVentas);
            }

            if(vec[pos].stockMinimo < vec[pos].stock){
                insertarOrdenado2(listaStockMinimo,auxLista->info.codProd);

                //insertarOrdenado2(listaStockMinimo,);
            }

        }

        auxLista = auxLista->sgte;
    }

}




































































































/*#include <iostream>
using namespace std;

struct articulos {
    int codProd;
    int precio;
    int stock;
    int stockMinimo;
};

struct infoLista {
    int codProd;
    int cantVendida;
};

struct Nodo {
    infoLista info;
    Nodo *sgte;
};

int buscar(Nodo* lista, int v);
int insertarOrdenado(articulos vec[], int& len, int v);
int insertarOrdenadoLista(Nodo* lista, int v);
void ejercicio(articulos vec[], int len, Nodo *lista);

int main(){

    articulos vector[150];
    int len;

    Nodo *lista;

    ejercicio(vector,len,lista);

    return 0;
}

void ejercicio(articulos vec[], int len, Nodo *lista){

    Nodo *auxLista = lista;

    Nodo *listaFaltaStock = NULL;
    
    int ventas = 0;

    ventas = buscar(auxLista,auxLista->info.cantVendida);
    
    for(int i=0;i<len;i++){
        if(vec[i].stockMinimo>=ventas){
            vec[i].stockMinimo = vec[i].stockMinimo - auxLista->info.cantVendida;
            insertarOrdenado(vec,len,vec[i].stockMinimo);
        } else {
            insertarOrdenadoLista(listaFaltaStock,auxLista->info.codProd);
        }
    }
}*/