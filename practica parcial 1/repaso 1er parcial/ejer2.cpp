/*Desarrolle un procedimiento que, dados los 3 puntajes obtenidos por un participante en distintas pruebas, indique
qué clasificación obtiene.
Nota: Si los 3 puntajes son iguales → Categoría A. Si exactamente 2 puntajes son iguales → Categoría B. Si los 3 puntajes son
distintos → Categoría C.*/

#include <iostream>
using namespace std;

void clasificacion(int p1, int p2, int p3);

int main(){

    int puntaje1,puntaje2,puntaje3;
    
    cout << "ingresar 3 puntajes: " << endl;
    cin >> puntaje1 >> puntaje2 >> puntaje3;

    clasificacion(puntaje1,puntaje2,puntaje3);

    return 0;
}

void clasificacion(int p1, int p2, int p3){
    if(p1==p2){
        if(p2==p3){
            cout << "categoria A";
        } else {
            cout << "categoria B";
        }
    } else if(p2==p3){
        cout << "categoria B";
    } else if (p1==p3){
        cout << "categoria B";
    } else {
        cout << "categoria C";
    }
}