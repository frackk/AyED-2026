#include <iostream>
#include <stdio.h>
using namespace std;

struct Alumno {
    int legajo;
    int dni;
    int nota1;
    int nota2;
};

int main (){

    // Paso 1
    FILE* Alum;
    
    Alumno rcarga;

    // Paso 2
    Alum = fopen("K1151b.dat","wb");

    // Paso 3
    cout << "Ingrese un legajo o 0 para terminar: " << endl;
    cin >> rcarga.legajo;

    while(rcarga.legajo != 0){
        cout << "Ingrese un DNI: " << endl;
        cin >> rcarga.dni;
        cout << "Ingrese Nota 1: " << endl;
        cin >> rcarga.nota1;
        cout << "Ingrese Nota 2: " << endl;
        cin >> rcarga.nota2;

        fwrite(&rcarga,sizeof(struct Alumno),1,Alum);

        cout << "Ingrese un legajo o 0 para terminar: " << endl;
        cin >> rcarga.legajo;
    }

    fclose(Alum);
    

    return 0;
}