/*Dado valor numérico entero que se ingresa por teclado, se pide informar:
 La quinta parte de dicho valor,
 el resto de la división por 5 y
 la séptima parte de la quinta parte. 
*/

#include <iostream>
using namespace std;

int main () {

    int num,quinta,rest,septQuin;
    
    cout << "ingresar un valor numerico entero: " << endl;
    cin >> num;

    quinta = num/5;
    rest = num%5;
    septQuin = quinta/7;

    cout << "quinta parte: " << quinta <<", resto div x 5: " << rest << ", sept de la quint: " << septQuin << endl;

    return 0;
}