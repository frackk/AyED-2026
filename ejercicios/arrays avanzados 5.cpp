//============================================================================
// Name        : arrays.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void inicializar (int vec[], int cantPos, int valorIni);
void mostrar (int vec[], int len);
void insertar (int vec[], int &len, int valor, int pos);
void insertarOrdenado (int vec[], int &len, int valor);
int buscar (int vec[], int len,int valor); //devuelve -1 si no lo encontro o me devuelve la pos en la que lo encontró

int main() {

   // buscar un determinado valor en mi vector

   int pos;

   int vector[5];
   int len=0;
   int valor;

   inicializar(vector,5,0);

   for (int i=0; i<5;i++){
      cout << "Ingrese un valor: " << endl;
      cin >> valor;
      insertarOrdenado(vector,len,valor);
   }

   // buscar un numero X (4)

   pos = buscar(vector,len,4);

   if (pos!=-1) {
      cout << "el 4 esta en el vector en la pos " << pos << endl;
   } else {
      cout << "no encontró el valor 4" << endl;
   }

   mostrar (vector,len);

   return 0;
}

void inicializar (int vec[], int cantPos, int valorIni) {
   for(int i=0;i<cantPos;i++){
      vec[i] = valorIni;
   }
}

void mostrar (int vec[], int len){
   for(int i=0;i<len;i++){
      cout << "nota ingresada: " << vec[i] << endl;
   }
}

void insertar (int vec[], int &len, int valor, int pos) {
   for (int i=len; i>pos; i--) {
      vec[i] = vec[i-1];
   }
   vec[pos]=valor;
   len++;
}

void insertarOrdenado (int vec[], int &len, int valor) {
   int i = 0;
   while (i<len && vec[i]<=valor) {
      i++;
   }

   if (i==len) {
      vec[len]=valor;
      len++;
   } else {
      insertar (vec, len, valor, i);
   }

}

int buscar (int vec[], int len,int valor) {
   int i = 0;
   while(i<len && vec[i]!=valor) {
      i++;
   }

   if (i==len) { //no lo encontré
      return -1;
   } else { // lo encontré
      return i;
   }
}
