/*MI ENUNCIADO:
Un parque de atracciones almacena la información de sus juegos en un vector (maximo 20 juegos) de hasta Diciembre de 2026 con los datos del codigo de juego, cantidad de tickets vendidos y contador de usos del juego.
Por otro lado, tenemos una Lista Ordenada (por codigo de juego) que contiene las ventas registradas durante el mes de enero de 2027, donde contiene el Código de juego y Cantidad de tickets vendidos en el mes.
    1)Actualizar el vector del parque de atracciones con la Lista de enero de 2027.
    2)Generar un archivo de enero 2027  “JuegosPopulares.dat” con los juegos con mas 250 tickets vendidos con la misma estructura de la Lista.
    3)  Mostrar por pantalla cual fue el juego con la mayor cantidad de tickets vendidos en total.
*/

/*
MI ENUNCIADO RECIBIDO:
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
4) Mostrar cuantos productos necesitan reponer.*/

/*Estructuras a utilizar:
struct Producto{
    int codigo;
    int Ventas;
    int precio;
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

struct NodoCola{ o NodoRepo
    int cod;
    NodoCola *sgte;
};

*/
/*
Estrategia de resolucion:
Armamos la estructura del archivo "Stock.dat"
Armamos la estructura del nodo
Definimos funciones y procedimientos a utilizar: "buscar(lista), insertar(vector) o agreagar(vector), suprimir(cola), "*/

/*
1) recorro la lista y buscamos dentro de la lista que codigos tienen ventas en el dia mayores a 0, restamos la cantidad disponible de dicho codigo con las ventas realizadas, y aumentamos las ventas de dicho codigo.

2) creamos el vector, con la misma estructura que el archivo, leemos el archivo, y comparamos la cantidad disponible con el stock minimo. de ser menor, lo cargamos en el vector.

3) recorremos la lista, mostramos en pantalla por cada código de producto su ganancia total, que sería igual a la cantidad vendida durante el día multiplicada por el precio de dicho producto.

4) creamos un contador que sume la cantidad de codigos que hay en la cola, ya que si dichos codigos pertenecen a la cola, si o si necesitan reposicion, luego mostramos el resultado de dicho contador. (la cola está compuesta por una estructura distinta, que tiene un solo campo que es el int codProd, y el puntero al siguiente Nodo*).
*/
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Stock
{
    int codigo;
    char descripcion[31];
    int stockD;
    int stockM;
    int precio;
    int ventas;
};

struct Productos
{
    int codigo;
    int ventas;
    int precio;
};

struct NodoStock //lista stock
{
    Stock info;
    NodoStock*sgte;
};

struct NodoProductos //lista productos
{
    Productos info;
    NodoProductos*sgte;
};

struct NodoRepo //cola
{
    int info;
    NodoRepo*sgte;
};

//cola repo
int suprimir (NodoRepo*&cfte,NodoRepo*&cfin);
//lista stock
void liberarStock (NodoStock*&L); //libera y elimina todos los nodos
NodoStock* buscar (NodoStock*L, int valor);
void insertarOrdenado (NodoStock*&L,Stock valor);
//lista productos
void liberarProductos (NodoProductos*&L); //libera y elimina todos los nodos

//vectores Stock
void inicializar (Stock vec[], int cantPos, Stock valorIni);
void agregar(Stock arr[], int n, int&len, Stock v);
void cargaVector(Stock vec[],int&len,NodoStock*ListaStock);

int main()
{
    FILE*arch; //ordenado por codigo
    Stock raux;

    arch=fopen("Stock.dat","rb");

    NodoStock*ListaStock=NULL; //utilizado para cargar los valores del archivo

    NodoProductos*ListaProductos; //ya cargada, "ya que es dado"

    Stock vec[100]; //vector encaragado de guardar todos los datos de los productos si su stock es menor al minimo
    int len=0;
    Stock valorIni;
    valorIni.codigo=0;
    //valorIni.descripcion='0';
    strcpy(valorIni.descripcion,"0");
    valorIni.precio=0;
    valorIni.stockD=0;
    valorIni.stockM=0;
    valorIni.ventas=0;
    inicializar(vec,100,valorIni);

    int gananciaTotalDia=0; //encargado de sumar la ganancia total del dia Lista Productos.

    NodoRepo*ColaFrente; //la cola ya esta cargada con lo se tiene que reponer.
    NodoRepo*ColaFin;
    int aux; //a la hora de sacar el valor del codigo a reponer de la cola, es el encargado aux.
    int cant=0; //cuenta la cantidad de productos a reponer ejemplo: se debe reponer 5 productos diferntes.

    fread(&raux,sizeof(struct Stock),1,arch);
    while(!feof(arch))
    {
        insertarOrdenado(ListaStock,raux);//insertamos la lista stock ordenado por codigo.


        fread(&raux,sizeof(struct Stock),1,arch);
    }

    fclose(arch);

    NodoStock*AuxListaStock=NULL;// es el encargado de guardar si es que se encontra en la busqueda el codigo

    NodoProductos*AuxProductos=ListaProductos; //es el encargado de recorrer la lista de productos.

    while(AuxProductos!=NULL)
    {
        AuxListaStock = buscar(ListaStock,AuxProductos->info.codigo);

        if(AuxListaStock!=NULL) //aca preguntamos si existe el codigo en la lista stock y en la lista productos.
        {
            AuxListaStock->info.stockD = AuxListaStock->info.stockD - AuxProductos->info.ventas;
            AuxListaStock->info.ventas = AuxListaStock->info.ventas + AuxProductos->info.ventas;

            gananciaTotalDia = gananciaTotalDia + AuxProductos->info.precio * AuxProductos->info.ventas; //aqui sumuamos toda la ganancia del dia DE LA LISTA DE PRODUCTOS.

        }
        AuxProductos=AuxProductos->sgte;
    }

    cargaVector(vec,len,ListaStock);//aqui cargariamos toda los valores de la lista donde su stock es menor al stock minimo

    cout<<"la ganancia total del dia es: "<<gananciaTotalDia<<endl;


    while(ColaFrente!=NULL)
    {
        aux=suprimir(ColaFrente,ColaFin);
        cant++;
    }
    cout<<"Se deben reponer: "<<cant<<" productos diferentes."<<endl;

    arch=fopen("Stock.dat","wb");
    AuxListaStock = ListaStock; //aqui recargamos el archivo ya con todo modificado.

    while(AuxListaStock!=NULL)
    {

        fwrite(&AuxListaStock->info,sizeof(struct Stock),1,arch);


        AuxListaStock=AuxListaStock->sgte;
    }
    fclose(arch);

    liberarStock(ListaStock);
    liberarProductos(ListaProductos);

    return 0;
}

void cargaVector(Stock vec[],int&len,NodoStock*ListaStock)
{
    NodoStock*Auxiliar=ListaStock;

    while(Auxiliar!=NULL){
        if(Auxiliar->info.stockD < Auxiliar->info.stockM)
        {
            agregar(vec,100,len,Auxiliar->info);
        }


        Auxiliar=Auxiliar->sgte;
    }
}

void inicializar (Stock vec[], int cantPos, Stock valorIni)
//RECORDAR QUE LOS VECTORES SIEMPRE SON PASADOS X REFERENCIA
{
    for(int i=0; i<cantPos; i++)
    {
        vec[i].codigo = valorIni.codigo;
        strcpy(vec[i].descripcion,valorIni.descripcion);
        vec[i].precio = valorIni.precio;
        vec[i].stockD = valorIni.stockD;
        vec[i].stockM = valorIni.stockM;
        vec[i].ventas = valorIni.ventas;
    }
}

void insertarOrdenado (NodoStock*&L,Stock valor){
   //crear el nodo y cargarlo
   NodoStock * nuevo = new NodoStock();
   nuevo->info =valor;
   nuevo->sgte = NULL;

   NodoStock*aux=L;
   NodoStock*ant=NULL; //se quedará 1 nodo antes que aux

   while (aux!=NULL && aux->info.codigo <= valor.codigo){
      ant=aux;
      aux=aux->sgte;
   }
   if(ant==NULL){
      L=nuevo;
   } else {
      ant->sgte=nuevo;
   }
   nuevo->sgte=aux;
}

NodoStock* buscar (NodoStock*L, int valor)
{
    NodoStock*aux=L;
    while(aux!=NULL && aux->info.codigo!=valor)
    {
        aux=aux->sgte;
    }
    return aux;
}

void agregar(Stock arr[], int n, int& len, Stock v){
	if(len < n){
		arr[len].codigo = v.codigo;
		strcpy(arr[len].descripcion,v.descripcion);
		arr[len].stockD = v.stockD;
		arr[len].stockM = v.stockM;
		arr[len].precio = v.precio;
		arr[len].ventas = v.ventas;
		len++;
	} else {
		cout << "El vector esta lleno" << endl;
	}
}
int suprimir (NodoRepo*&cfte,NodoRepo*&cfin){
   int ret;
   ret=cfte->info;
   NodoRepo*aux=cfte;
   cfte=aux->sgte; //cfte=cfte->sgte;
   if(cfte==NULL){
      cfin=NULL;
   }
   delete(aux);
   return ret;
}

void liberarStock (NodoStock*&L){
   NodoStock*aux;
   while (L!=NULL){
      aux=L;
      L=L->sgte;
      delete (aux);
   }
}
void liberarProductos (NodoProductos*&L){
   NodoProductos*aux;
   while (L!=NULL){
      aux=L;
      L=L->sgte;
      delete (aux);
   }
}
