/*Se tiene un vector de los alumnos del curso K1151, que contiene todos los alumnos que se inscribieron al seminario de ingreso con los siguientes campos: Numero de Legajo, Nota del Primer Parcial y Nota del Segundo Parcial.
Además, se cuenta con una lista ordenada que contiene las notas de los que rindieron recuperatorio del Segundo Parcial; cada nodo de la lista contiene el Número de Legajo y la nota del recuperatorio.
Se pide, actualizar el vector K1151 con la informacion que hay en la lista, SOLO para el campo Nota Segundo Parcial si es que aprobó el recuperatorio, sino no hacer nada.
Se sabe que como maximo hay 50 alumnos.*/

#include <iostream>
using namespace std;

struct cursoK1151 {
    int legajo;
    int nota1;
    int nota2;
};

struct Tinfo {
    int legajo;
    int nota2Recu;
};

struct Nodo {
    Tinfo info;
    Nodo *sgte;
};

int buscar(cursoK1151 vec[], int len, int v);
void ejercicio(cursoK1151 vec[], int len, Nodo* lista);
void liberar(Nodo *&lista);

int main(){

    cursoK1151 vector[50];
    int len;

    Nodo *listaRecus;

    ejercicio(vector,len,listaRecus);

    liberar(listaRecus);

    return 0;
}

int buscar(cursoK1151 vec[], int len, int v){
    // buscar
}


void ejercicio(cursoK1151 vec[], int len, Nodo* lista){

    Nodo *auxLista = lista;

    int pos = 0;

    while(auxLista != NULL){
        pos = buscar(vec,len,auxLista->info.legajo);
        if(pos != -1){
            if(auxLista->info.nota2Recu >= 6){
                vec[pos].nota2 = auxLista->info.nota2Recu;
            }
        }
        auxLista = auxLista->sgte;
    }

}


void liberar(Nodo *&lista){
    // liberar
}