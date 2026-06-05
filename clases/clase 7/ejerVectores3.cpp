/*Ejercicio 3: Dado el vector del ejercicio 1, y considerando que un nuevo usuario nos dará valores adicionales,  cargar los mismos de manera ordenada.*/

#include <iostream>
using namespace std;

void inicializar(int vec[],int cantPos, int valorIni);
void insertar (int vec[], int &len, int valor, int pos);
void insertarOrdenado (int vec[], int &len, int valor);
void mostrar (int vec[], int len);

int main(){

    int vector[20];
    int len=0;      // hay q inicializar el len (?) !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    int val;

    // 1 inicializo
    inicializar(vector,20,0);

    //

    cout << "ingrese un valor o termine con negativo" << endl;
    cin >> val;

    while(val>=0 && len<20){
        insertarOrdenado(vector,len,val);

        cout << "ingrese un valor o termine con negativo" << endl;
        cin >> val;
    }

    mostrar(vector,len);

    if (len<20) {
        
        cout << "siga ingrensando valores, hasta completar el len del vector: " << endl;
        cin >> val;
        
        while(val>=0 && len<20){
        insertarOrdenado(vector,len,val);

        cout << "ingrese un valor o termine con negativo" << endl;
        cin >> val;
        }
    }

    mostrar(vector,len);
    
    return 0;
}

void inicializar(int vec[],int cantPos, int valorIni) {
   for (int i=0;i<cantPos;i++) {
      vec[i] = valorIni;
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

void mostrar (int vec[], int len){
    for(int i=0;i<len;i++){
        cout << "valor ingresado: " << vec[i] << endl;
    }
}