/*Ejercicio 5 (3,5 puntos)
Se tiene un archivo de registros con los resultados finales de los aspirantes a una beca (máximo 100 aspirantes).
Formato del registro:
• DNI
• Puntaje
• Resultado ('A' = Aprobado, 'E' = En espera, 'R' = Rechazado)
Se pide:
1. Realizar un programa que genere un nuevo archivo con los aspirantes aprobados únicamente, con el
siguiente formato:
a. DNI
b. Puntaje
2. Mostrar por pantalla el promedio de los puntajes de todos los aspirantes.
3. Mostrar por pantalla la cantidad de aspirantes rechazados.*/

#include <iostream>
#include <stdio.h>
using namespace std;

struct resultBeca{
    int dni;
    int puntaje;
    char result;
};

struct aprobadosBeca{
    int dni;
    int puntaje;
};

int main(){

    FILE* ResFinales;
    FILE* Aprob;

    int cantRechazados = 0;
    int cantAspirantes;
    int sumatoria = 0;
    int promedio;

    resultBeca raux;
    aprobadosBeca rcarga;

    ResFinales = fopen("RESULTADOS.dat","rb");

    Aprob = fopen("APROBADOS.dat","wb");

    fread(&raux, sizeof(struct resultBeca),1,ResFinales);

    while(!feof(ResFinales)){
        
        if(raux.result == 'A') {
            rcarga.dni = raux.dni;
            rcarga.puntaje = raux.puntaje;

            fwrite(&rcarga, sizeof(struct aprobadosBeca),1,Aprob);
        } else if(raux.result == 'R'){
            cantRechazados++;
        }

        sumatoria += raux.puntaje;
        cantAspirantes++;

        fread(&raux, sizeof(struct resultBeca),1,ResFinales);
    }

    fclose(ResFinales);
    fclose(Aprob);

    promedio = sumatoria/cantAspirantes;

    cout << "El promedio de los puntajes de todos los aspirantes es: " << promedio << endl;
    cout << "La cantidad de aspirantes rechazados es: " << cantRechazados << endl;

    return 0;
}