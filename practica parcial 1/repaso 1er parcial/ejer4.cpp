/*Ejercicio 4 (3 puntos)
Dado un vector de respuestas de una encuesta (se sabe que participaron como máximo 2500 personas), que contiene:
• Código del participante
• Ciudad
• Respuesta ('S' = Sí, 'N' = No, 'I' = Indeciso)
Determinar:
1. ¿Cuál fue el resultado de la encuesta (gana Sí o No)?
2. ¿Cuál es la cantidad de respuestas Sí y No?
3. ¿Cuántos participantes quedaron indecisos?
*/

#include <iostream>
using namespace std;

struct Encuesta{
    int codPar;
    char ciudad[32];
    char respuesta;
};

void encuestaResult(Encuesta vec[],int len);

int main(){

    Encuesta vector[2500];
    int len;

    encuestaResult(vector,len);

    return 0;
}

void encuestaResult(Encuesta vec[],int len){
    
    int afirmativo=0;
    int negativo=0;
    int indeciso=0;

    for(int i=0;i<len;i++){
        if(vec[i].respuesta != 'S'){
            if(vec[i].respuesta != 'N'){
                indeciso++;
            } else {
                negativo++;
            }
        } else {
            afirmativo++;
        }
    }

    //1)
    if(afirmativo>negativo){
        cout << "El resultado de la encuesta es positivo." << endl;
    } else {
        cout << "El resultado de la encuesta es negativo." << endl;
    }

    cout << "la cantidad de respuestas afirmativas es: " << afirmativo << endl;
    cout << "la cantidad de respuestas negativas es: " << negativo << endl;
    cout << "la cantidad de respuestas indecisas fueron: " << indeciso << endl;

}



