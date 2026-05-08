/*
 6) Dado un lote valores provistos por el usuario, que finalizan con 0,
 definir y cargar un vector de 15 posiciones (de manera ordenada)
 y calcular:
   a. La sumatoria de todos los valores luego de ingresarlos al vector
   b. El valor m�ximo
   c. El valor m�nimo
   d. Generar un segundo vector que contenga s�lo la mitad de cada
      valor cargado en el vector original
   e. Genere un tercer vector con el doble de cada valor cargado en
      el vector original

 * */

#include <iostream>
using namespace std;

void inicializar(int vec[],int cantPos, int valorIni);
void insertarOrdenado (int vec[], int &len, int valor);
void carga (int vec[],int &len, int cantPos);
void mostrar(int vec[],int len);
int sumatoria (int vec[], int len);
int buscarMaximo (int vec[], int len);
int buscarMinimo (int vec[], int len);
void insertar (int vec[], int &len, int valor, int pos);
void mitadVec (int vec[], int len);
void dobleVec (int vec[], int len);

int main() {

   int vector[15];
   int len=0;
   int suma;
   int pMax;
   int pMin;
   int vectorMitad[15];
   int lenMitad;
   int vectorDoble[15];
   int lenDoble;

   // inicializo
   inicializar(vector,15,0);

   // carga
   cout << "ingresar un valor: ";
   carga(vector,len,15);

   cout << "vector ingresado: " << endl;
   mostrar(vector,len);

   // sumatoria
   suma=sumatoria(vector,len);
   cout << "la suma de todos los valores ingresados es: " << suma << endl;

   // maximo y minimo
   pMax=buscarMaximo(vector,len);
   cout << "maximo de los valores ingresados: " << vector[pMax]<< endl;

   pMin=buscarMinimo(vector,len);
   cout << "minimo de los valores ingresados: " << vector[pMin]<< endl;

   // segundo vector mitad de cada valor cargado del original
   inicializar(vectorMitad,15,0);
   lenMitad = len;

   cout << "la mitad de cada valor ingresado es: " << endl;

   for (int i=0;i<len;i++) {
      vectorMitad[i] = (vector[i])/2;
   }
   mostrar(vectorMitad,lenMitad);

   // tercer vector doble de cada valor cargado del original
   inicializar(vectorDoble,15,0);
   lenDoble = len;

   cout << "el doble de cada valor ingresado es: " << endl;

   for(int i=0;i<len;i++){
      vectorDoble[i] = (vector[i])*2;
   }
   mostrar(vectorDoble,lenDoble);

   return 0;
}

void inicializar(int vec[],int cantPos, int valorIni) {
   for (int i=0;i<cantPos;i++) {
      vec[i] = valorIni;
   }
}

void insertarOrdenado (int vec[], int &len, int valor) {

}

void carga (int vec[],int &len, int cantPos) {
   int valor;

   cout << "ingresar un valor, ingresar 0 para terminar: ";
   cin >> valor;

   while (valor!=0 && len<cantPos) {
      vec[len] = valor;
      len++;

      cout << "ingresar un valor, ingresar 0 para terminar: ";
      cin >> valor;
   }
}

void mostrar(int vec[],int len) {
   for (int i=0;i<len;i++) {
      cout << "valor ingresado: " << vec[i] << endl;
   }
}

int sumatoria (int vec[], int len) {
   int suma=0;

   for (int i=0;i<len;i++){
      suma = suma + vec[i];
   }
   return suma;
}

// posiciones
// 0 1  2  3  4  5  6  7  8  9  10 11 12 13 14
// valores en el vector
// 2 4  14 3  5  15 8  9  10 23  2 12  1  7 99

int buscarMaximo (int vec[], int len) {
   int posMax=0;

   for (int i=1;i<len;i++){      // i ahora vale 
      if (vec[i]>vec[posMax]){   // vec[6] > vec[5] {
         posMax = i;             // posMax = 5  
      }                          // }
   }
   return posMax;
}

// posiciones
// 0 1 2  3 4 5  6
// valores en el vector
// 2 4 14 3 5 15 1

int buscarMinimo (int vec[], int len) {
   int posMin=0;

   for (int i=1;i<len;i++) {
      if (vec[i]<vec[posMin]) {
         posMin = i;
      }
   }
   return posMin;
}

void insertar (int vec[], int &len, int valor, int pos) {
   for (int i=len;i>pos;i--){
      vec[i] = vec[i-1];
   }
   vec[pos] = valor;
   len++;
}

// posiciones
// 0 1 2  3 4 5  6
// valores en el vector
// 2 4 14 3 5 15 8


void mitadVec (int vec[], int len) {
   int mitad;

   for (int i=0;i<len;i++) {
      mitad = (vec[i]) / 2;
      vec[i] = mitad;
   }
}

void dobleVec (int vec[], int len) {
   int doble;

   for (int i=0;i<len;i++) {
      doble = (vec[i]) * 2;
      vec[i] = doble;
   }
}
