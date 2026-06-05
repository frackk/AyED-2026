/*Genere el siguiente tipo de dato:

Código de Producto: 9999
Cantidad de unidades en depósito: 99999
Tipo de producto: ‘H’, ‘N’ ó ‘P’ (Hamburguesas, Nuggets o Pan)
Vencimiento: MMAAAA
Y responda con la generación en código y defina una variable.*/

#include <iostream>
using namespace std;

struct Producto {
    int codProd;
    int cantUni;
    char tipoProd;
    int vencimiento;
};

int main () {

    Producto prod;

//    int codProductM, cantUnidM, vencimM;
//    char tipoProductM 

    cout << "ingrese el codigo del producto " << endl;
    cin >> prod.codProd;

    cout << "ingrese la cantidad de unidades en deposito del producto " << endl;
    cin >> prod.cantUni;

    cout << "ingrese el tipo de producto ('H', 'N' o 'P') " << endl;
    cin >> prod.tipoProd;

    while (prod.tipoProd != 'H' && prod.tipoProd != 'N' && prod.tipoProd != 'P') {
        cout << "ingrese un tipo de prodcuto valido ('H', 'N' o 'P')" << endl;
        cin >> prod.tipoProd;
    };

    cout << "ingrese la fecha de vencimiento en formato MMAAAA " << endl;
    cin >> prod.vencimiento;

    int mes,anio;
    
    mes = prod.vencimiento / 10000;
    anio = prod.vencimiento % 10000;

    cout << "codigo de producto: " << prod.codProd << endl;
    cout << "cantidad de unidades en deposito: " << prod.cantUni << endl;
    cout << "tipo: " << prod.tipoProd << endl;
    cout << "vencimiento: " << mes << "/" << anio << endl;

    
    return 0;
}