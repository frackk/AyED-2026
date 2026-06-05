/*Se tiene un vector y su len, con las notas de los estudiantes. Se pide que muestre: a. La menor nota b. La mejor nota c. El promedio d. La cantidad de notas cargadas*/

#include <iostream>
using namespace std;

void notaMaxima(int vec[], int len);
void notaMinima(int vec[], int len);
void promedio(int vec[], int len);
void cantNotas(int vec[], int len);

int main (){

    int vecNotas[10];
    int len;

    notaMaxima(vecNotas,len);
    notaMinima(vecNotas,len);
    promedio(vecNotas,len);
    cantNotas(vecNotas,len);

    return 0;
}

void notaMaxima(int vec[], int len){
    int posMax = 0;

    for(int i=1;i<len;i++){
        if(vec[i]>vec[posMax]){
            posMax = i;
        }
    }
    cout << "la nota maxima es: " << vec[posMax] << endl;
}



void notaMinima(int vec[], int len){
    int posMin = 0;

    for(int i=1;i<len;i++){
        if(vec[i]>vec[posMin]){
            posMin = i;
        }
    }
    cout << "la nota minma es: " << vec[posMin] << endl;

}


void promedio(int vec[], int len){
    int sumatoria = 0;
    int prom;

    for(int i=0; i<len;i++){
        sumatoria += vec[i];
    }
    
    prom = sumatoria/len;
    cout << "el promedio de notas ingresadas es: " << prom << endl;
}


void cantNotas(int vec[], int len){
    cout << "la cantidad de notas cargadas es: " << len << endl;
}