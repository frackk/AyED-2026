/*Defina un vector de 20 posiciones y cárguelo con los valores indicados por el usuario. Se sabe que el usuario sólo compartirá valores positivos (controlar cuándo finaliza la carga)*/

#include <iostream>
using namespace std;

void inicializar(int vec[],int len);
void cargaMasiva(int vec[], int len, int cantPos);
void mostrar(int vec[], int len);

int main(){

    //definir
    int vector[20];
    int len=0;

    //inicializar
    inicializar(vector,len);

    //cargar
    cargaMasiva(vector,len,20);

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
        cout << "ingrese un valor positivo: ";
        cin >> vec[i];
        if(vec[i] > 0) {
            cout << "ingrese un valor positivo: ";
            cin >> vec[i];
            len++;
        } else {
            cout << "se ingreso un valor negativo. " << endl;
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