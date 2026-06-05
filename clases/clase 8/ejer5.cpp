/*Defina un vector de 10 posiciones y cárguelo con los valores provistos por el usuario, se sabe que el mismo dará valores entre 1 – 100 (controlar cuando finaliza la carga)*/

#include <iostream>
using namespace std;

void inicializar(int vec[],int len);
void cargaMasiva(int vec[], int len, int cantPos);
void mostrar(int vec[], int len);

int main(){

    //definir
    int vector[10];
    int len=0;

    //inicializar
    inicializar(vector,len);

    //cargar
    cargaMasiva(vector,len,10);

    //procesar

    //mostrar
    mostrar(vector,len);


    return 0;
}

void inicializar(int vec[],int len){
	for(int i=0; i < len; i++){
		vec[i] = 0;
	}
}

void cargaMasiva(int vec[], int len, int cantPos){
   
   for(int i=0;i<cantPos;i++){
        cout << "ingrese un valor entre 1 y 100: ";
        cin >> vec[i];
        if(vec[i] >= 1 && vec[i] <= 100) {
            cout << "ingrese un valor entre 1 y 100: ";
            cin >> vec[i];
            len++;
        } else {
            cout << "se ingreso un valor fuera del rango. " << endl;
            break;
        }
   }
}

void mostrar(int vec[], int len){
	
	for(int i=0; i < len; i++){
		cout << vec[i] << endl;
	}
	
}

// sin terminar