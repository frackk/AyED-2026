/*Ejercicio 2: (3 puntos)
Se tiene un vector de los alumnos del curso K1151, que contiene todos los alumnos que se inscribieron en curso de verano con los siguientes campos: Número de Legajo, Materia, Nota de Aprobación.Además, se cuenta con una lista ordenada que contiene las notas de los que rindieron recuperatorio del Segundo Parcial; cada nodo de la lista contiene el Número de Legajo, Nota del primer parcial y la nota del recuperatorio.

Se pide, actualizar el vector K1151 con la información que hay en la lista, SOLO para el campo Nota de Aprobación si es que aprobó el recuperatorio y promediarla con la nota del Primer parcial (si es que era 6 o más) que también se encuentra en el nodo; sino no hacer nada.

Ej: Si un alumno obtuvo 6 o más en su recuperatorio y tiene 6 o más en el primer parcial; en el vector en el campo Nota de Aprobación, tendrá que aparecer la nueva nota (que es el promedio de las dos).

Se sabe que como Máximo hay 50 alumnos.*/

#include <iostream>
using namespace std;

struct cursoK1151 {
    int legajo;
    char materia[32];
    int notaAprobacion;
};

struct Tinfo {
    int legajo;
    int nota1;
    int nota2Recu;
};

struct Nodo {
    Tinfo info;
    Nodo *sgte;
};

int buscar(cursoK1151 vec[], int len, int v);
void ejercicio(cursoK1151 vec[], int len, Nodo* lista);
void liberar(Nodo*& lista);

int main(){

    cursoK1151 vector[50];
    int len;

    Nodo *listaRecu2doParcial;

    ejercicio(vector,len,listaRecu2doParcial);

    liberar(listaRecu2doParcial);

    return 0;
}

int buscar(int vec[], int len, int v){
	int pos;
	int i =0;
	
	while(i < len && vec[i] != v){
		i++;
	}
	
	if(i != len){ // i != len condición alternativa
		pos = i;
	} else {
		pos = -1;
	}
	
	return pos;	
}

void ejercicio(cursoK1151 vec[], int len, Nodo* lista){

    Nodo *auxLista = lista;

    int pos=0;

    while(auxLista != NULL){
        pos = buscar(vec,len,auxLista->info.legajo);
        if(pos != -1){
            if(auxLista->info.nota2Recu >= 6 && auxLista->info.nota1 >= 6){
                vec[pos].notaAprobacion = (auxLista->info.nota1 + auxLista->info.nota2Recu)/2;
            }
        }
        auxLista = auxLista->sgte;
    }

}

void liberar(Nodo*& lista){
	Nodo* aux;
	while(lista != NULL){
		aux = lista;
		lista = lista->sgte;
		delete aux;
	}
	
}