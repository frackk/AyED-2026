/*
desarroye un PROCEIMIENTO que dados 4 numeros muestre el mayor, los numeros se pasan por parametro.
*/

#include <iostream>
using namespace std;

void mayor(int A, int B, int C, int D);

int main(){

    return 0;
}

void mayor(int A, int B, int C, int D){

    
    if(A>=B){
        if(A>=C){
            if(A>=D) {
                cout << "el numero mayor es: " << A << endl;
            } else {
                cout << "el numero mayor es: " << D << endl;
            }
        } else if(C>=B) {
            if (C>=D){
                cout << "el numero mayor es: " << C << endl;
            } else {
                cout << "el numero mayor es: " << D << endl;
            }
        }
    } else if(B>=C){
        if(B>=D){
            cout << "el numero mayor es: " << B << endl;
        } else {
            cout << "el numero mayor es: " << D << endl;
        }
    } else if(D>=C){
            cout << "el numero mayor es: " << D << endl;
        } else {
            cout << "el numero mayor es: " << C << endl;
        }
    }

}