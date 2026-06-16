/*Ejercicio 3 – Generar dos archivos nuevos Se tiene un archivo de registros de tamaño fijo llamado VENTAS.DAT con el siguiente formato: • NRO_VENTA: Número de venta / Numérico de hasta 8 cifras. • COD_VEND: Código de vendedor / Numérico de hasta 5 cifras. • IMPORTE: Importe de la venta / Entero. Se pide generar dos archivos: VENTAS_ALTAS.DAT • NRO_VENTA • COD_VEND • IMPORTE Contendrá las ventas con importe superior a $100.000. VENTAS_BAJAS.DAT • NRO_VENTA • COD_VEND • IMPORTE Contendrá las ventas con importe menor o igual a $100.000.*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct Venta {
    int numVent;
    int codVendedor;
    int importe;
};

int main (){

    FILE* Vent;
    Vent = fopen("VENTAS.dat","rb");

    Venta rcarga;

    fread(&rcarga,sizeof(struct Venta),1,Vent);

    while(rcarga.importe > 100000){
        
    }

    return 0;
}