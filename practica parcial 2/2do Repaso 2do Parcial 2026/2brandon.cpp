#include <iostream>
#include <stdio.h>
using namespace std;

//pila
void push(Nodo*&pila, int valor);
int pop(Nodo*&pila);

//cola
void agregar(Nodo*&cfte,Nodo*&cfin,int valor);
int suprimir (Nodo*&cfte,Nodo*&cfin);

//lista
void agregarNodo (Nodo*&L,int valor); //agrega al final de la lista
void agregarPrimero(Nodo*&L, int valor);//agrega al principio de la lista
void mostrar (Nodo*L);
void liberar (Nodo*&L); //libera y elimina todos los nodos
Nodo* buscar (Nodo*L, int valor);
int eliminarPrimerNodo (Nodo*&L);
void insertarOrdenado (Nodo*&L,int valor);
void eliminar(Nodo*&L, int valor); //elimina el nodo con el valor a eliminar

/*
Una empresa dedicada a la comercialización de artículos tecnológicos cuenta con un vector de productos que almacena la información de todos los artículos registrados. Cada elemento del vector contiene los siguientes campos: Código de Producto, Precio Unitario, Stock Disponible y Stock Mínimo.
Además, se dispone de una lista simplemente enlazada, ordenada por Código de Producto, que contiene
los movimientos de ventas realizados durante el día. Cada nodo de la lista almacena: Código de
Producto y Cantidad Vendida.
Se pide:
    1) Actualizar el vector de productos utilizando la información contenida en la lista, descontando del
    Stock Disponible las cantidades vendidas de cada producto. Si el stock disponible no alcanza para
    cubrir la cantidad vendida, no se deberá modificar el stock y se deberá registrar el código del
    producto en una nueva lista de productos con faltante de stock.
    2) Generar una nueva lista simplemente enlazada con los productos cuyo stock disponible, luego de
    procesar las ventas, haya quedado por debajo del Stock Mínimo. Cada nodo deberá contener el Código de
    Producto y el Stock Disponible actualizado.
    3) Informar la cantidad total de ventas que no pudieron concretarse por falta de stock y el importe
    total correspondiente a dichas ventas.
    Se sabe que como máximo hay 150 productos registrados en el vector.
*/

struct Productos
{
    int codigo;
    int precioU;
    int stock;
    int stockM;
};
struct Tinfo
{
    int codigo;
    int ventas;
};
struct Nodo
{
    Tinfo info;
    Nodo*sgte;
};

struct Tinfo2
{
    int codigo;
    int Stock;
};
struct Nodo2
{
    Tinfo2 info;
    Nodo2*sgte;
};


int buscar(Productos vec[],int len,int valor);


int main()
{
    Productos vec[150];
    int len;

    Nodo*Lista;

    Nodo*ListaF=NULL;
    int pos=0;

    Nodo2*ListaStockD=NULL;
    Tinfo2 raux;

    int cont=0;
    int totalI=0;

    Nodo*AuxLista=Lista;
    while(AuxLista!=NULL)
    {
        pos=buscar(vec,len,AuxLista->info.codigo);

        if(pos!=-1)
        {
            if(vec[pos].stock > AuxLista->info.ventas)
            {
                vec[pos].stock-=AuxLista->info.ventas;

                if(vec[pos].stock < vec[pos].stockM)
                {
                    raux.codigo=vec[pos].codigo;
                    raux.Stock=vec[pos].stock;
                    agregarNodo(ListaStockD,raux);
                }
            }
            else
            {
                agregarNodo(ListaF,AuxLista->info);

                totalI += vec[pos].precioU * AuxLista->info.ventas;
                cont++;
            }
        }

        AuxLista=AuxLista->sgte;
    }

    cout<<"el importe total es: "<<totalI<<endl;
    cout<<"ventas no concretadas: "<<cont<<endl;

    liberar(Lista);
    liberar(ListaF);
    liberar(ListaStockD);

    return 0;
}
