/*Desarrolle un procedimiento que, dadas las calificaciones de calidad, presentacion y funcionamiento de un producto, indique si el producto es "Aprobado","En Revision" o "Rechazado" segun el promedio obtenido.
Nota: Se considera Aprobado si el promedio es 8 o mator; En revision si el promedio es mayor o igual a 6 y menor que 8; y rechazado si el promedio es menor a 6.*/

#include <iostream>
using namespace std;

void estadoProducto(int calidad, int presentacion, int funcionamiento);

int main(){}

void estadoProducto(int calidad, int presentacion, int funcionamiento){
    int sumatoria=0;
    int prom;

    sumatoria = calidad + presentacion + funcionamiento;
    prom = sumatoria/3;

    if(prom > 7){
        cout << "Aprobado" << endl;
    } else if(prom > 5 && prom < 8) {
        cout << "En Revision" << endl;
    } else if(prom < 6) {
        cout << "Rechazado" << endl;
    }
}