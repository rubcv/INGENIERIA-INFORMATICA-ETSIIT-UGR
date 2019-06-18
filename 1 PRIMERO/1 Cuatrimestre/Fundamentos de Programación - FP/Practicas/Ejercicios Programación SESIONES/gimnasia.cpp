/*

Progrma que calcula el campeon de una competicion de gimnasia. Donde cada gimnasta viene identificado por un dorsal y 3 notas 0 ..10
la puntuacion de un gimnasta es la media de las 3 notas. Mostrar  máxima nota de las obtenidas por los gimnastas.
*/

#include <iostream>

using namespace std;
const int FIN = 0;


float leeNota(string msg){
float nota;
      cout << msg;
      do {			//Filtro de lectura de notas 0..10
            cin >> nota;
      }
      while(nota < 0 || nota > 10.0);
return nota;
}
int leeDorsal(string msg){
int dorsal;
       cout << msg;
       do {
          cin >> dorsal;
       } while(dorsal< FIN);
}
float media(float notaacumulada, int num){
return notaacumulada/(float) num;
}

float media(float n1, float n2, float n3){
return (n1+n2+n3) / 3.0;
}

float max(float v1, float v2){
     float maximo = v1;
     if (v2 > v1)
         maximo = v2;
     return maximo;
}

int main() {
    const string MSGNOTA = "Introduce nota [0..10] :";
    const string MSGDORSAL = "Introduce numero de dorsal  (0 para salir del programa): ";
    const string SALIDA = "\n\nLa puntuacion maxima obtenida ha sido : ";
    const string NODATOS = "No se ha introducido ningun dato.";
    const string MSGMEDIA = "Puntuacion obtenida: ";
    const int NNOTAS = 3;
    			//Declaración de variables
    int i,dorsal;
    float sumNotas, puntuacionMedia, puntuacionMax;

    // //Lectura adelantada y filtro de dorsal de jugador

    puntuacionMax=-1;
    dorsal= leeDorsal(MSGDORSAL);

    while(dorsal != FIN) { 		//Bucle para controlar fin de entrada de datos
            sumNotas = 0;
            for(i=1; i<= NNOTAS;i++)
                sumNotas +=leeNota(MSGNOTA);

            puntuacionMedia=media(sumNotas, NNOTAS);
            cout << MSGMEDIA<< puntuacionMedia << endl;
            puntuacionMax = max(puntuacionMax,puntuacionMedia);
            dorsal= leeDorsal(MSGDORSAL);

     } // fin while

     if (puntuacionMax != -1)      // han habido gimnastas
        cout << SALIDA << puntuacionMax << endl;
     else
        cout << NODATOS << endl;

}
 
