#include <iostream>
using namespace std;

int main(){

    int x;

    cout << "ingresar 2 ";
    cin >> x;

    while(x==2){
        cout << "x vale 2, y como MIENTRAS x SEA 2, te voy a seguir preguntando infinitamente hasta que no sea 2......";
        cin >> x;
    }

    cout << "el numero vale " << x;
}