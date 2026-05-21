/*4- Generar y completar un array con los números impares comprendidos entre 1 y 100 y los muestre en pantalla en orden ascendente*/

#include <iostream>
using namespace std;

int main (){

    int vec[100];
    int impar = 1;

    for (int i=0;i<50;i++){
        
        vec[i] = i + impar;
        impar++;
        cout << vec[i] << " ";
    }
    
    return 0;
}