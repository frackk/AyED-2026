/*desarrolle una funcion que determine si una persona es mayor de edad a partir de su edad.
Nota: se considera mayor de edad cuando su edad es igual o mator a 18 años.*/

#include <iostream>
using namespace std;

bool esMayor(int edad);

int main(){}

bool esMayor(int edad){
    if(edad>17){
        return true;
    } else {
        return false;
    }
}