/*Ejercicio 3 – Generar dos archivos nuevos Se tiene un archivo de registros de tamaño fijo llamado VENTAS.DAT con el siguiente formato:
• NRO_VENTA: Número de venta / Numérico de hasta 8 cifras.
• COD_VEND: Código de vendedor / Numérico de hasta 5 cifras.
• IMPORTE: Importe de la venta / Entero.
Se pide generar dos archivos: VENTAS_ALTAS.DAT
• NRO_VENTA
• COD_VEND
• IMPORTE Contendrá las ventas con importe superior a $100.000. VENTAS_BAJAS.DAT
• NRO_VENTA
• COD_VEND
• IMPORTE Contendrá las ventas con importe menor o igual a $100.000.*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct Ventas{
    int nroVenta;
    int codVend;
    int importe;
};

struct VentasAltas {
    int nroVenta;
    int codVend;
    int importe;
};

struct VentasBajas {
    int nroVenta;
    int codVend;
    int importe;
};

int main(){

    FILE* Vent;
    Ventas raux;
    Vent = fopen("VENTAS.dat","rb");

    FILE* VentAltas;
    VentasAltas rcargaA;
    VentAltas = fopen("VENTAS_ALTAS.dat","wb");

    FILE* VentBajas;
    VentasBajas rcargaB;
    VentBajas = fopen("VENTAS_BAJAS.dat","wb");

    

    fread(&raux,sizeof(struct Ventas),1,Vent);

    while(!feof(Vent)){
        
        if(raux.importe>100000){
            rcargaA.nroVenta = raux.nroVenta;
            rcargaA.codVend = raux.codVend;
            rcargaA.importe = raux.importe;
            fwrite(&rcargaA,sizeof(struct VentasAltas),1,VentAltas);
        } else {
            rcargaB.nroVenta = raux.nroVenta;
            rcargaB.codVend = raux.codVend;
            rcargaB.importe = raux.importe;
            fwrite(&rcargaB,sizeof(struct VentasBajas),1,VentBajas);
        }

        fread(&raux,sizeof(struct Ventas),1,Vent);
    }

    fclose(Vent);
    fclose(VentAltas);
    fclose(VentBajas);

    return 0;
}