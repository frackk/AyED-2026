#include <iostream>
using namespace std;

void agregar(int arr[], int n, int &len, int val);

int main (){



    return 0;
}

void agregar(int arr[], int n, int &len, int val) {

    if (n == len) {
        cout << "no se puede agregar. vector lleno";
    } else {
        arr[len] = val;
        len++;
    }
}