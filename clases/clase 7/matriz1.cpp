/*le pido al ususario datos para ingresar a la matriz*/

#include <iostream>
using namespace std;

void inicializarMatriz(int matriz[][3], int cantFilas, int cantColum, int valorIni);
void cargarMatriz(int matriz[][3], int cantFilas, int cantColum);
void mostrarMatriz(int matriz[][3], int cantFilas, int cantColum);
int sumatoria(int matriz[][3], int cantFilas, int cantColum);

int main(){

    // Paso 1: definir variable
    int miMatriz[3][3];     // [filas] - [columnas]
    int rdo;
        

    // Paso 2: Inizializar
    inicializarMatriz(miMatriz,3,3,0);

    // Paso 3: Cargar la Matriz
    cargarMatriz(miMatriz,3,3);

    // Paso 4: Procesar
    rdo=sumatoria(miMatriz,3,3);
    // Paso 5: Mostrar la matriz

    return 0;
}

void inicializarMatriz(int matriz[][3], int cantFilas, int cantColum, int valorIni) {
    for(int i=0;i<cantFilas;i++){
        for(int j=0;j<cantColum;j++){
            matriz[i][j]=valorIni;
        }
    }
}

void cargarMatriz(int matriz[][3], int cantFilas, int cantColum) {
    for (int i=0;i<cantFilas;i++){
        for (int j=0;j<cantColum;j++){
            cout << "ingrese un valor para la fila " << i << " y la columa " << j << endl;
            cin >> matriz[i][j];
        }
    }

}

void mostrarMatriz(int matriz[][3], int cantFilas, int cantColum) {
    for (int i=0;i<cantFilas;i++){
        for (int j=0;j<cantColum;j++){
            cout << "es valor para la fila " << i << " y la columa " << j << " es: " << matriz[i][j] << endl;
        }
    }

}

int sumatoria(int matriz[][3], int cantFilas, int cantColum) {
    int suma=0;
    for (int i=0;i<cantFilas;i++){
        for (int j=0;j<cantColum;j++){
             suma=suma+matriz[i][j];
        }
    }

    return suma;
}