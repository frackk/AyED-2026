/*Se tiene un archivo de stock "Stock.dat" ordenado por codigo de producto. Cada registro contiene los siguientes campos: 
- codigo de produccion
- descripcion
- cantidad disponible (stock)
- stock minimo
- precio
- ventas
Se cuenta tambien con una lista que contiene los códigos, la cantidad de los productos vendidos durante el día y su precio, y una cola con los codigos de los productos solicitados para reposición
Se pide:
1) Actualizar el stock de los productos vendidos.
2) Cargar en un vector (capacidad maxima 100) los productos cuyo stock sea inferior al mínimo
3) Mostrar la ganancia total del dia por pantalla.
4) Mostrar  cuantos productos necesitan reponer.*/

/*Estrategia de resolucion:
Armamos la estructura del archivo "Stock.dat"
Armamos la estructura del nodo 
Definimos funciones y procedimientos a utilizar: "buscar(lista), insertar(vector), suprimir(cola), "*/

/*
1) recorro la lista y buscamos dentro de la lista que codigos tienen ventas en el dia mayores a 0, restamos la cantidad disponible de dicho codigo con las ventas realizadas, y aumentamos las ventas de dicho codigo.

2) creamos el vector, con la misma estructura que el archivo, leemos el archivo, y comparamos la cantidad disponible con el stock minimo. de ser menor, lo cargamos en el vector.

3) recorremos la lista, mostramos en pantalla por cada código de producto su ganancia total, que sería igual a la cantidad vendida durante el día multiplicada por el precio de dicho producto.

4) creamos un contador que sume la cantidad de codigos que hay en la cola, ya que si dichos codigos pertenecen a la cola, si o si necesitan reposicion, luego mostramos el resultado de dicho contador. (la cola está compuesta por una estructura distinta, que tiene un solo campo que es el int codProd, y el puntero al siguiente Nodo*).
*/


#include <iostream>
#include <stdio.h>
using namespace std;

struct Producto {
    int codigo;
    int cantVentas;
    float precio;
};

struct Stock {
    int codigo;
    char descrip[31];
    int stockDisponible;
    int stockMinimo;
    float precio;
    int ventas;
};

struct NodoLista {
    Producto info;
    NodoLista* sgte;
};

struct NodoStock {
    Stock info;
    NodoStock* sgte;
};

struct NodoCola {
    int cod;
    NodoCola* sgte;
};

void insertarOrdenado(NodoStock*& lista, Stock valor);
NodoStock* buscar(NodoStock* lista, int codigo);
void agregar(Stock vec[], int n, int& len, Stock valor);
int suprimir(NodoCola*& cfte, NodoCola*& cfin);
void liberar(NodoStock*& lista);

int main() {
    FILE* arch;
    Stock raux;
    Stock vec[100];

    NodoLista* lista = NULL;
    NodoStock* listaStock = NULL;
    NodoCola* colaFte = NULL;
    NodoCola* colaFin = NULL;

    int len = 0;
    int cantReponer = 0;
    float gananciaTotal = 0;

    // lectura del archivo
    arch = fopen("Stock.dat", "rb");
    if(arch == NULL) {
        return 1;
    }

    fread(&raux, sizeof(Stock), 1, arch);
    while(!feof(arch)) {
        insertarOrdenado(listaStock, raux);
        fread(&raux, sizeof(Stock), 1, arch);
    }
    fclose(arch);

    // actualizacion de las ventas
    NodoLista* aux = lista;
    NodoStock* encontrado;

    while(aux != NULL) {
        encontrado = buscar(listaStock, aux->info.codigo);

        if(encontrado != NULL && aux->info.cantVentas > 0) {
            encontrado->info.stockDisponible = encontrado->info.stockDisponible - aux->info.cantVentas;
            encontrado->info.ventas = encontrado->info.ventas + aux->info.cantVentas;
            gananciaTotal = gananciaTotal + aux->info.cantVentas * aux->info.precio;
        }

        aux = aux->sgte;
    }

    // productos con stock bajo el minimo
    NodoStock* auxStock = listaStock;

    while(auxStock != NULL) {
        if(auxStock->info.stockDisponible < auxStock->info.stockMinimo) {
            agregar(vec, 100, len, auxStock->info);
        }
        auxStock = auxStock->sgte;
    }

    // actualizacion del archivo
    arch = fopen("Stock.dat", "wb");
    if(arch == NULL) {
        liberar(listaStock);
        return 1;
    }

    auxStock = listaStock;
    while(auxStock != NULL) {
        fwrite(&auxStock->info, sizeof(Stock), 1, arch);
        auxStock = auxStock->sgte;
    }
    fclose(arch);

    // reposiciones solicitadasd
    while(colaFte != NULL) {
        suprimir(colaFte, colaFin);
        cantReponer++;
    }

    liberar(listaStock);
    return 0;
}

void insertarOrdenado(NodoStock*& lista, Stock valor) {
    NodoStock* nuevo = new NodoStock();
    nuevo->info = valor;
    nuevo->sgte = NULL;

    NodoStock* aux = lista;
    NodoStock* ant = NULL;

    while(aux != NULL && aux->info.codigo < valor.codigo) {
        ant = aux;
        aux = aux->sgte;
    }

    if(ant == NULL) {
        lista = nuevo;
    } else {
        ant->sgte = nuevo;
    }

    nuevo->sgte = aux;
}

NodoStock* buscar(NodoStock* lista, int codigo) {
    NodoStock* aux = lista;

    while(aux != NULL && aux->info.codigo != codigo) {
        aux = aux->sgte;
    }

    return aux;
}

void agregar(Stock vec[], int n, int& len, Stock valor) {
    if(len < n) {
        vec[len] = valor;
        len++;
    }
}

int suprimir(NodoCola*& cfte, NodoCola*& cfin) {
    int ret = cfte->cod;
    NodoCola* aux = cfte;
    cfte = cfte->sgte;

    if(cfte == NULL) {
        cfin = NULL;
    }

    delete aux;
    return ret;
}

void liberar(NodoStock*& lista) {
    NodoStock* aux;

    while(lista != NULL) {
        aux = lista;
        lista = lista->sgte;
        delete aux;
    }
}

