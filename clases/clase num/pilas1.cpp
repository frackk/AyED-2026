#include <iostream>
using namespace std;

struct Nodo{
    int info;
    Nodo* sgte;
};

// encabezados de los subprogramas para las pilas

// agregar elementos a la pila
void push(Nodo* &pila, int valor);

// saca los elementos de la pila; devuelve el tipo de dato del INFO
int pop(Nodo*&pila);

int main(){

    Nodo*pila=NULL; // definidiento la pila y la estoy inicializando

    int result;
    int carga;
 
    cout << "ingrese los valores para la pila o termine con 0" << endl;
    cin >> carga;

    while(carga!=0){
        push(pila,carga);
        cout << "ingrese los valores para la pila o termine con 0" << endl;
        cin >> carga;
    }

    while(pila!=NULL){
        result = pop(pila);
        cout << result << endl;
    }

    return 0;
}

void push(Nodo* &pila, int valor){
    // pedir memoria para crear el nodo
    Nodo*nuevo=new Nodo();

    // cargar el nodo y que este nodo sea parte de la pila
    nuevo -> info = valor;
    nuevo -> sgte = pila;
    pila = nuevo;
}

int pop(Nodo*&pila){
    int ret = pila -> info; // aseguro guardar la variable de retorno

    Nodo*aux=pila;
    pila = aux -> sgte; // pila = pila -> sgte;
    delete(aux);

    return ret;
}

