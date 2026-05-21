/*5- Dado 10 números ingresados por teclado, almacenelos en un array y muestre la suma, resta, multiplicación y división de todos.*/

#include <iostream>
using namespace std;

int main (){

    int vec[10];

    for(int i=0;i<10;i++){
        cout << "ingrese un numero: ";
        cin >> vec[i];
    }
    
    cout << "vector ingresado: " << endl;
    for(int i=0;i<10;i++){
        cout << vec[i] << " ";
    }
    cout << endl;

    int suma = 0;
    int resta;
    int producto = 1;
    int div;

    for(int i=0;i<10;i++){      // mal el prod y div.
        suma += vec[i];
        resta -= vec[i];
//        producto = producto + vec[i] * vec[i+1];
        div = div + (vec[i] / vec[i+1]);
    }

    for(int i=0;i<9;i++){
        producto += vec[i] * vec[i+1];
    }

    cout << "suma :" << suma << endl;
    cout << "rest :" << resta << endl;
    cout << "multiplicacion :" << producto << endl;
    cout << "division :" << div << endl;

    return 0;
}