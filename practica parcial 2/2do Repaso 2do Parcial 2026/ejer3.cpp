/*Se tiene un archivo de registros de inscripciones a cursos de capacitación denominado Inscripciones.dat
(sin orden).
• Número de Legajo: 999999
• Código de Curso: 9999
• Nota del examen final: 99
• Cantidad de inasistencias: 99
• Año de cursada: 9999
Se pide:
a) Ordenar el archivo Inscripciones.dat por Número de Legajo.
b) Armar una lista simplemente enlazada, ordenada por Nota del Examen Final, SOLO con aquellos
alumnos que hayan aprobado el curso (nota mayor o igual a 6), que tengan como máximo 2 inasistencias
y que hayan cursado durante el año 2026. Cada nodo de la lista deberá contener Número de Legajo,
Código de Curso y Nota obtenida. Imprimir la lista por pantalla.
c) Informar la cantidad de alumnos que no cumplen con alguna de las condiciones establecidas para
formar parte de la lista.*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct Tinfo {
    int legajo;
    int codCurso;
    int nota;
    int inasistencias;
    int anio;
};

struct Nodo {
    Tinfo info;
    Nodo *sgte;
};

struct TinfoAprobados {
    int legajo;
    int codCurso;
    int nota;
};

struct NodoListaNota {
    TinfoAprobados info;
    NodoListaNota *sgte;
};

Nodo* insertarOrdenadoLegajo(Nodo*& lista, Tinfo v);
Nodo* insertarOrdenadoNota(NodoListaNota*& lista, TinfoAprobados v);
void mostrar(NodoListaNota* lista);
void liberar(Nodo*& lista);
void liberarListaNota(NodoListaNota*& lista);

int main(){

    Nodo *listaInscrip = NULL;
    NodoListaNota *listaAprobados = NULL;

    FILE* Inscrip;
    Tinfo raux;
    TinfoAprobados rauxAprobados;

    int noCumplen = 0;

    Inscrip = fopen("Inscripciones.dat","rb");

    fread(&raux,sizeof(struct Tinfo),1,Inscrip);

    while(!feof(Inscrip)){

        insertarOrdenadoLegajo(listaInscrip,raux);

        if(raux.nota >= 6 && raux.inasistencias <= 2 && raux.anio == 2026){
            rauxAprobados.legajo = raux.legajo;
            rauxAprobados.codCurso = raux.codCurso;
            rauxAprobados.nota = raux.nota;

            insertarOrdenadoNota(listaAprobados,rauxAprobados);
        } else {
            noCumplen++;
        }

        fread(&raux,sizeof(struct Tinfo),1,Inscrip);
    }

    fclose(Inscrip);

    Inscrip = fopen("Inscripciones.dat","wb");

    Nodo* auxLista = listaInscrip;

    while(auxLista != NULL){
        fwrite(&auxLista->info,sizeof(struct Tinfo),1,Inscrip);
        auxLista = auxLista ->sgte;
    }

    fclose(Inscrip);

    mostrar(listaAprobados);

    liberar(listaInscrip);
    liberarListaNota(listaAprobados);

    cout << "cantidad de alumnos que no cumplen con alguna de las condiciones establecidas para formar parte de la lista: " << noCumplen << endl;

    return 0;
}

Nodo* insertarOrdenadoLegajo(Nodo*& lista, Tinfo v){

}

Nodo* insertarOrdenadoNota(NodoListaNota*& lista, TinfoAprobados v){

}

void mostrar(NodoListaNota* lista){

}

void liberar(Nodo*& lista){

}

void liberarListaNota(NodoListaNota*& lista){

}