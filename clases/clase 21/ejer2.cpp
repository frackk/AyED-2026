/*Una tienda posee un archivo binario PRODUCTOS.dat cuyos registros contiene, el codigo de prodcuto, tipo de producto (CHAR) y el precio del producto, se pide realizar un programa que lea todos los productos almacenados en el archivo, y los ordene de menor a mayor.*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct Tinfo {
    int codProd;
    char tipoProd[32];
    int precio;
};

struct Nodo {
    Tinfo info;
    Nodo *sgte;
};

Nodo* insertarOrdenado(Nodo*& lista, Tinfo v);
void liberar(Nodo*& lista);

int main(){

    Nodo *listaProd = NULL;
    FILE* Prods;
    Tinfo raux;

    Prods = fopen("PRODUCTOS.dat","rb");

    fread(&raux,sizeof(struct Tinfo),1,Prods);

    while(!feof(Prods)){
        insertarOrdenado(listaProd,raux);
        fread(&raux,sizeof(struct Tinfo),1,Prods);
    }

    fclose(Prods);

    Prods = fopen("PRODUCTOS.dat","wb");

    Nodo *auxLista = listaProd;

    while(auxLista != NULL){
        fwrite(&auxLista->info,sizeof(struct Tinfo),1,Prods);
        auxLista = auxLista->sgte;
    }

    fclose(Prods);
    liberar(listaProd);

    return 0;
}

Nodo* insertarOrdenado(Nodo*& lista, Tinfo v){
    // insertarOrdenado
}

void liberar(Nodo*& lista){
	Nodo* aux;
	while(lista != NULL){
		aux = lista;
		lista = lista->sgte;
		delete aux;
	}
	
}