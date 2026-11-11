/*
Dado un un vector de votos de la camara de diputados (se sabe que maximo votaron 257 diputados), sobre el tratamiento de una ley, que contiene el codigo del diputado, partido politico, voto ('P' positivo, 'N' negativo o 'A' abstencion), determinar:
¿Cual es el resultado de la votacion? (a favor o en contra)?
¿Cual es la cantidad de votos positivos y negativos?
¿Cuantas abtenciones hubo?
*/

#include <iostream>
using namespace std;



struct Votacion{
    int codDiputado;
    char partidoPoli[32];
    char voto;
};

void resultVotacion(Votacion vec[], int len);

int main(){

    Votacion vectorDip[257];
    int len;

    resultVotacion(vectorDip,len);

    return 0;
}

void resultVotacion(Votacion vec[], int len){
    int positivo=0;
    int negativo=0;
    int abstencion=0;

    for(int i=0;i<len;i++){
        if(vec[i].voto == 'P'){
            positivo++;
        } else if(vec[i].voto == 'N'){
            negativo++;
        } else {
            abstencion++;
        }
    }

    if(positivo>negativo){
        cout << "El resultado de la votacion es positivo." << endl;
    } else if (negativo>positivo) {
        cout << "El resultado de la votacion es negativo." << endl;
    } else {
        cout << "La votacion fue un empate." << endl;
    }

    cout << "Hubo un total de " << positivo << " votos positivos." << endl;
    cout << "Hubo un total de " << negativo << " votos negativos." << endl;
    cout << "Hubo un total de " << abstencion << " abtenciones." << endl;

}