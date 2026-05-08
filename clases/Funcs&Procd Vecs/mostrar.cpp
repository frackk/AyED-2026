#include <iostream>
using namespace std;

void mostrar (int vec[], int len);

int main () {

    int vector[10];     // 10 num random.
    int len;

    // muestro
    cout << "vector ingresado: " << endl;
    mostrar(vector,len);

    return 0;
}

void mostrar (int vec[], int len) {
    for(int i=0;i<len;i++) {
        cout << "valor ingresado: " << vec[i] << endl;
    }
}