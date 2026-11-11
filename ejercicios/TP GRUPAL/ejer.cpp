/*
Grupo 1:
Albertario, Franco Ezequiel
Alvarado, Brandon
Lavenia, Micaela
Maldonado, Sofía
Yfran, Genesis 

CONSIGNA CREADA POR NOSOTROS: 
Un parque de atracciones almacena información de sus juegos en un vector (maximo 20 juegos) de estructuras hasta Diciembre 2026 con los datos del código del juego, cantidad de tickets vendidos y contador de usos del juego. 
Por otro lado, tenemos una lista ordenada (por codigo de juego) que contiene las ventas registradas durante el mes de enero de 2027, donde contiene el código de juego y cantidad de tickets vendidos en el mes.
Se pide:
1- Actualizar el vector del parque de atracciones con la lista de enero 2027
2- Generar un archivo de enero 2027 "Juegos Populares.dat" con los juegos con mas de 250 tickets vendidos, con la misma estructura de la lista.
3- Mostrar por pantalla cual fue el juego con la mayor cantidad de tickets vendidos en total.

CONSIGNA DADA:
Se tiene un archivo de stock "Stock.dat" ordenado por codigo de producto. Cada registro contiene los siguientes campos: 
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
4) Mostrar  cuantos productos necesitan reponer.

Estrategia de resolucion:
Armamos la estructura del archivo "Stock.dat"
Armamos la estructura del nodo 
Definimos funciones y procedimientos a utilizar: "buscar(lista), insertar(vector), y suprimir(cola).

1) recorremos la lista y buscamos dentro de la lista que codigos tienen ventas en el dia mayores a 0, restamos la cantidad disponible de dicho codigo con las ventas realizadas, y aumentamos las ventas de dicho codigo.

2) creamos el vector, con la misma estructura que el archivo, leemos el archivo, y comparamos la cantidad disponible con el stock minimo. de ser menor, lo cargamos en el vector.

3) recorremos la lista, mostramos en pantalla por cada código de producto su ganancia total, que sería igual a la cantidad vendida durante el día multiplicada por el precio de dicho producto.

4) creamos un contador que sume la cantidad de codigos que hay en la cola, ya que si dichos codigos pertenecen a la cola, si o si necesitan reposicion, luego mostramos el resultado de dicho contador. (la cola está compuesta por una estructura distinta, que tiene un solo campo que es el int codProd, y el puntero al siguiente Nodo*).
*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct Producto{
    int codigo;
    int cantVentas;
    float precio;
};

struct Stock{
    int codigo;
    char descrip [31];
    int stockDisponible;
    int stockMinimo;
    float precio;
    int ventas; 
};

struct NodoLista{
    Producto info;
    NodoLista* sgte;
};

struct NodoCola{
    int cod;
    NodoCola *sgte;
};

NodoLista* buscar(NodoLista* lista, int v);
int suprimir(NodoCola*&colafte, NodoCola*&colafin);
void insertar(Stock arr[], int& len, Stock v, int pos);

int main(){
    
    FILE* Stk;
    Stk = fopen("Stock.dat","rb+");
    Stock raux;

    NodoLista* lista;
    NodoLista* prodX;

    NodoCola* colaFte;
    NodoCola* colaFin;

    Stock vec[100];
    int len=0;

    float gananciaTot = 0;
    float gananProd;
    int contRepos = 0;

    fread(&raux,sizeof(struct Stock),1,Stk);
    while(!feof(Stk)){
        prodX = buscar(lista,raux.codigo);
        if(prodX != NULL){
   
            raux.stockDisponible = raux.stockDisponible - prodX->info.cantVentas; //descontamos del stock la cant vendida

            raux.ventas = raux.ventas + prodX->info.cantVentas; // actualizamos la cant de ventas

            fseek(Stk,-sizeof(Stock),SEEK_CUR); //volvemos a la posicion del registro leido

            fwrite(&raux,sizeof(Stock),1,Stk);

            fseek(Stk,0,SEEK_CUR); 
        }

        fread(&raux, sizeof(Stock), 1, Stk);
    }

    // ej 2
    fseek(Stk, 0, SEEK_SET); // se vuelve al inicio del archivo 
    fread(&raux, sizeof(Stock), 1, Stk);

    while(!feof(Stk)){

        if(raux.stockDisponible < raux.stockMinimo){

            if(len < 100){
                insertar(vec, len, raux, len);
            }
        }

        fread(&raux, sizeof(Stock), 1, Stk);
    }


    // ej 3
    NodoLista* aux = lista; //auxiliar para recorrer la lista 

    while(aux != NULL){

        gananProd = aux->info.cantVentas * aux->info.precio; //calculo de ganancia por producto

        gananciaTot = gananciaTot + gananProd; //calculo de ganancia total

        aux = aux->sgte;
    }

    cout << "La ganancia total del dia es de: " << gananciaTot << " pesos." <<endl;


    // ej 4

    while(colaFte != NULL){
        suprimir(colaFte, colaFin);
        contRepos++;
    }

    cout << "La cantidad de productos que necesitan reposicion son: " << contRepos  <<endl;

    fclose(Stk);

    return 0;
}