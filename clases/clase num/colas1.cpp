#include <iostream>
using namespace std;

struct Nodo{
    int info;
    Nodo* sgte;
};

void agregar(Nodo*&colafte, Nodo*&colafin, int valor);
int suprimir(Nodo*&colafte, Nodo*&colafin);

int main(){

    Nodo*colafte = NULL;
    Nodo*colafin = NULL;
    int result;
    int carga;
 
    cout << "ingrese los valores para la cola o termine con 0" << endl;
    cin >> carga;

    while(carga!=0){
        agregar(colafte,colafin,carga);
        cout << "ingrese los valores para la cola o termine con 0" << endl;
        cin >> carga;
    }

    while(colafte!=NULL){
        result=suprimir(colafte,colafin);
        cout << result << endl;
    }

    return 0;
}

void agregar(Nodo*&colafte, Nodo*&colafin, int valor){
    // crear el nodo y cargarlo
    Nodo*nuevo = new Nodo();
    nuevo -> info = valor;
    nuevo -> sgte = NULL;

    if(colafte == NULL) {
        colafte = nuevo;
    } else {
        colafin -> sgte = nuevo;
    }
    colafin = nuevo;

}

int suprimir(Nodo*&colafte, Nodo*&colafin){
    int ret;
    ret = colafte -> info;
    Nodo*aux = colafte;
    colafte = aux -> sgte; // colafte = colafte -> sgte;
    
    if(colafte==NULL){
        colafin == NULL;
    }
    delete(aux);
    return ret;
}