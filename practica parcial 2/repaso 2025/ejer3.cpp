/*Ejercicio 3: (3 puntos)
Se tiene un archivo de resultados electorales Legislativas.dat (sin Orden).
- ID del Partido político: 999999
- ID de la Provincia: 99
- Votos obtenidos: 9999999
- Cantidad de Bancas ganadas: 99
Se pide:

a) Ordenar el archivo Elecciones.DAT por ID del Partido.

b) Armar una lista ordenada por Votos Obtenidos, SOLO si los votos obtenidos superaron 150.000 y al menos ganaron 1 banca e imprimir la lista por pantalla.

Nota: Sólo puede leer 1 vez el archivo.*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct Tinfo {
    int idPartido;
    int idProvincia;
    int votos;
    int cantBancas;
};

struct Nodo {
    Tinfo info;
    Nodo *sgte;
};

void mostrar(Nodo* lista);
void liberar(Nodo*& lista);
Nodo* insertarOrdenado(Nodo*& lista, Tinfo v);

int main(){

    Nodo *listaOrdenada = NULL;

    FILE* Legis;
    Tinfo raux;

    Legis = fopen("Legislativas.dat","rb");

    fread(&raux,sizeof(struct Tinfo),1,Legis);

    while(!feof(Legis)){

        if(raux.votos > 150000 && raux.cantBancas >= 1){
            insertarOrdenado(listaOrdenada,raux);
        }

        fread(&raux,sizeof(struct Tinfo),1,Legis);
    }

    fclose(Legis);

    Legis = fopen("Legislativas.dat","wb");

    Nodo *auxLista = listaOrdenada;

    while(auxLista != NULL){
        fwrite(&auxLista->info,sizeof(struct Tinfo),1,Legis);
        auxLista = auxLista->sgte;
    }

    fclose(Legis);

    mostrar(listaOrdenada);
    liberar(listaOrdenada);

    return 0;
}

Nodo* insertarOrdenado(Nodo*& lista, int v){
	// insertarOrdenado
}

void mostrar(Nodo* lista){
    // mostrar
}

void liberar(Nodo*& lista){
	Nodo* aux;
	while(lista != NULL){
		aux = lista;
		lista = lista->sgte;
		delete aux;
	}
	
}