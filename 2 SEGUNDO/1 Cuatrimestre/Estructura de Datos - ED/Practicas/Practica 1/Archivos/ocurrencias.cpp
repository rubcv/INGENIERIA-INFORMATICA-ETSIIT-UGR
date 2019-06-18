#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <vector> 
#include <string>
#include <chrono>
#include <algorithm>


#define POS_NULA -1 

// practica 1
// ANALISIS DE EFICIENCIA DE ALGORITMOS
//

/* El objetivo de la practica es doble, por una lado ilustrar de forma empirica cómo se puede computar el tiempo de ejecución de un algoritmo
y, por otro, ilustrar como el uso de distintas estructuras de datos nos permite mejorar la eficiencia de los algoritmos
*/



using namespace std;
using namespace std::chrono;


/* Lee un fichero  sobre un vector de string
 nf: nombre del fichero
 V: vector sobre el que se lee el fichero
 */
void lee_fichero( const char * nf, vector<string> & V) {
 ifstream fe;
  string s;
 fe.open(nf, ifstream::in);
 while ( !fe.eof() )
   { fe >> s;
     if (!fe.eof())
       V.push_back(s);
   }
 fe.close();
}

/* Busqueda lineal de un string en el vector V
 V: vector sobre el que queremos buscar
 s: palabra a buscar
 return la posicion en la que se encuentra la palabra, POS_NULA en caso contrario
 */

int buscar( vector<string> & V, string & s) {
  bool enc= false;
  int pos = POS_NULA;
  for (int i=0; i< V.size() && !enc; i++)
    if (V[i]==s) {
      enc = true;
      pos = i;
    }
  return pos;  
}

/* Contar ocurrencias de un string en el vector V
 V: vector sobre el que queremos buscar
 ini: primera posicion desde la que buscar
 fin: posicion siguiente a la ultima para buscar (desde V[0] hasta V[fin-1])
 s: palabra a buscar
 return la posicion en la que se encuentra la palabra, POS_NULA en caso contrario
 */

int contar_hasta( vector<string> & V, int ini, int fin, string & s) {
  int cuantos = 0;
  for (int i=ini; i< fin ; i++)
    if (V[i]==s) {
      cuantos ++;
    }
  return cuantos;  
}



int main() {

 vector<string> Dicc;
 vector<string> Q;
 int pos;
 
high_resolution_clock::time_point start,end;
duration<double> tiempo_transcurrido;

 int contador =0;
 
 lee_fichero("lema.txt", Dicc); // Ojo, el vector no esta ordenado!!!
 cout << Dicc.size() << " " << Dicc.capacity() << endl;
 
 lee_fichero("quijote.txt", Q);
 cout << Q.size() << " " << Q.capacity() << endl;
 
 
 
 
 ////////////////////////////////////////////////////
 // CONTAR OCURRENCIAS PALABRA
 ////////////////////////////////////////////////////
 cout << "Contar ocurrencias" << endl;
 for (int fin = 10; fin < 100000 ; fin+= 1000){
 string b="hidalgo";
 start = high_resolution_clock::now();
 pos = contar_hasta(Q, 0,fin, b); 
 end= high_resolution_clock::now(); 
 
tiempo_transcurrido  = duration_cast<duration<double> >(end - start);
cout << fin << " " << tiempo_transcurrido.count() << endl;
 
 }
 
 
 
 ////////////////////////////////////////////////////
 // CONTAR OCURRENCIAS PALABRA
 // Si los tiempos son muy grandes se itera sobre un numero elevado de iteraciones y se 
 // calcula en tiempo realizado en media para una de ellas (en el ejemplo son 2000)
 ////////////////////////////////////////////////////
 cout << "Contar ocurrencias (con toma de tiempos promedio) " << endl;
 
 int max_iteraciones = 2000;
 for (int fin = 10; fin < 100000 ; fin+= 1000){
 string b="hidalgo";
 
 start = high_resolution_clock::now();
 for (int iteraciones = 0; iteraciones < max_iteraciones; iteraciones++)  // Numero de iteraciones se debe ajustar a cada caso
      pos = contar_hasta(Q, 0,fin, b); 
 end= high_resolution_clock::now(); 

tiempo_transcurrido  = duration_cast<duration<double> >(end - start);
cout << fin << " " << tiempo_transcurrido.count() /( (double) max_iteraciones )<< endl; 
}
 

 




}
 
 
 
 
