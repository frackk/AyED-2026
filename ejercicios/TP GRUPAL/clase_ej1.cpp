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


#include<iostream>
#include<stdio.h>
#include <cstdio>

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

int main(){
    


    return 0;
}

//Al pasar reg como referencia, se puede modificarr el registro que se pasa como argumente, y se puede actualizar el archivo.

bool buscarRegistro(FILE *archStock, int codProd, Stock &reg){
    fseek(archStock, 0, SEEK_SET); //Nos aseguramos de que el puntero del archivo esté al inicio
    while(fread(&reg, sizeof(Stock), 1, archStock)){
        if(reg.codigo == codProd){
            return true;
        }
    }
    return false;
}

void actualizarArchivo(char rutaArchStock[], NodoLista *&lista){
    FILE *archstock = fopen(rutaArchStock, "rb+");

    if(archstock == NULL){
        cout<<"Error al abrir el archivo"<<endl;
        return;
    }

    NodoLista *aux = lista;
    while(aux!=NULL){
        if(aux->info.cantVentas > 0){
            Stock reg;
            if(buscarRegistro(archstock, aux->info.codigo, reg)){
                reg.stockDisponible -= aux->info.cantVentas;
                reg.ventas += aux->info.cantVentas;
                fseek(archstock, -sizeof(Stock), SEEK_CUR);
                fwrite(&reg, sizeof(Stock), 1, archstock);
            }
        }
        aux = aux->sgte;
    }
    fclose(archstock);
}

const int MAX_PRODUCTOS = 100;
typedef Stock t_vectorStock[MAX_PRODUCTOS];

void generarVectorStock(char rutaArchStock[], t_vectorStock vec, int &tamVec){
      FILE *archstock = fopen(rutaArchStock, "rb");

    if(archstock == NULL){
        cout<<"Error al abrir el archivo"<<endl;
        return;
    }

    Stock reg;
    tamVec = 0;
    while(fread(&reg, sizeof(Stock), 1, archstock)){
        if(reg.stockDisponible < reg.stockMinimo && tamVec < MAX_PRODUCTOS){ //Si supero 100 productos, no se cargan más porque supera la capacidad del vector
            vec[tamVec] = reg;
            tamVec++;
        }
    }
    fclose(archstock);
}

void mostrarGananciaTotal(NodoLista *&lista){
    NodoLista *aux = lista;
    float gananciaTotal = 0;
    while(aux!=NULL){
        gananciaTotal += aux->info.cantVentas * aux->info.precio;
        aux = aux->sgte;
    }
    cout << " Ganancia Total: $" << gananciaTotal <<endl;
}

int unqueue(NodoCola*&, NodoCola*&);

int contarProductosReposicion(NodoCola *&frente, NodoCola *&fin){
    int contador = 0;
    NodoCola *aux = frente;
    while(aux != NULL){
        unqueue(frente, fin);
        contador++;
        aux = aux->sgte;
    }
    return contador;
}