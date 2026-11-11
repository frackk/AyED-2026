/*Se tiene un vector de los alumnos del curso K1151, que contiene todos los alumnos que cursaron la materia con lo siguientes campos: Numero de Legajo, Nota Primer Parcial, Nota Segundo Parcial, Nota de Aprobacion.
Ademas, se cuenta con una lista ordenada, que contiene las notas de los que rindieron recuperatorio del Primer Parcial o Segundo Parcial; cada nodod e la lista contiene el Numero de Legajo, Nota Recuperatorio primer parcial o la nota del recuperatorio del segundo parcial (puede considerar que tiene 0 en el campo que no haya rendido).

Se pide: actualizar el vector k1151 con la informacion que hay en la lista, reemplazando el Primer o Segundo parcial por la nota del recuperatorio y actualizar el campo Nota de Aprobacion. En el caso que la nota de aprobacion sea 8 o mas, imprimir por pantalla que el alumno promociono.
Se sabe que como maximo hay 50 alumnos.*/

#include <iostream>
using namespace std;

struct cursoK1151 {
    int legajo;
    int nota1;
    int nota2;
    int notaAprobacion;
};

struct Tinfo {
    int legajo;
    int notaRecu1;
    int notaRecu2;
};

struct Nodo {
    Tinfo info;
    Nodo *sgte;
};

void ejercicio(cursoK1151 vec[],int len, Nodo *lista);
int buscar(cursoK1151 vec[],int len,int v);
void liberar(Nodo *&lista);

int main(){

    cursoK1151 vector[50];
    int len;

    Nodo *listaRecus;

    ejercicio(vector,len,listaRecus);

    liberar(listaRecus);

    return 0;
}

int buscar(cursoK1151 vec[],int len,int v){
    //buscar
}

void ejercicio(cursoK1151 vec[],int len, Nodo *lista){

    Nodo *auxLista = lista;

    int pos = 0;

    while(auxLista != NULL){
        
        pos = buscar(vec,len,auxLista->info.legajo);

        if(pos != -1){
            if(vec[pos].nota1 < auxLista->info.notaRecu1){
                vec[pos].nota1 = auxLista->info.notaRecu1;
            } else if(vec[pos].nota2 < auxLista->info.notaRecu2){
                vec[pos].nota2 = auxLista->info.notaRecu2;
            }

            vec[pos].notaAprobacion = (vec[pos].nota1 + vec[pos].nota2) / 2;
            
            if(vec[pos].notaAprobacion >= 8) {
                cout << "El alumno cuyo legajo es: " << vec[pos].legajo << " promocionó." << endl;
            }
        }

        auxLista = auxLista->sgte;
    }

}

void liberar(Nodo *&lista){
    // liberar
}