#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <vector> 
#include <string>
#include <chrono>
#include <algorithm>
#include <map>

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

/* algoritmo de ordenacion por burbuja
 T: vector sobre el que se lee el fichero
 inicial: primera posicion desde la que buscar
 final : posicion siguiente a la ultima para buscar (desde V[0] hasta V[fin-1])
 */
void burbuja(vector<string> & T, int inicial, int final) {
int i, j;
string aux;
for (i = inicial; i < final - 1; i++)
for (j = final - 1; j > i; j--)
if (T[j] < T[j-1]) {
  aux = T[j];
T[j]= T[j-1];
T[j-1] = aux;
}

}


int main() {

 vector<string> Dicc;
 vector<string> Q;
 int pos;
 high_resolution_clock::time_point tantes,tdespues;
 duration<double> tiempo_transcurrido;

  
vector<int> frecuencia;
vector<string> palabra;

 int contador =0;
 
 lee_fichero("lema.txt", Dicc); // Ojo, el vector no esta ordenado!!!
 //cout << Dicc.size() << " " << Dicc.capacity() << endl;
 
 lee_fichero("quijote.txt", Q);
 //cout << Q.size() << " " << Q.capacity() << endl;
 
 
 
 

////////////////////////////////////////////////////
 // ORDENACION POR BURBUJA
 ////////////////////////////////////////////////////

vector<string> aux;
//cout << "Ordenacion Burbuja"<< endl;
for (int tama = 100; tama < Dicc.size() ; tama+= 5000){
  aux =Dicc;
  tantes = high_resolution_clock::now();
  //burbuja(aux, 0,tama );
  sort(aux.begin(), aux.begin()+tama);
  tdespues = high_resolution_clock::now();
  tiempo_transcurrido  = duration_cast<duration<double> >(tdespues - tantes);

  cout << tama << " " << tiempo_transcurrido.count() << endl;

}



 




}
 
