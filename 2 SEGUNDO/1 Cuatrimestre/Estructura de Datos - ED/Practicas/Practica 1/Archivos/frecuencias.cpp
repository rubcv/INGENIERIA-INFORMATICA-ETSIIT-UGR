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


/* Metodo que permite contar las frecuencia de aparicion cada palabra en un libro

  libro : vector de palabras sobre el que queremos contar las frecuencias
  ini: posicion inicio del libro
  fin: limite superior del libro hasta la que queremos contar (libro[ini] hasta libro[fin-1])
  pal: vector de palabras ya leidas  
  frec: numero de veces que ocurre la palabra pal[i] en el libro (desde libro[ini] hasta libro[fin-1])
 
  Pregunta: Proporciona la salida correcta?
*/

void contar_frecuencias_V1( vector<string> & libro, int ini, int fin, 
                         vector<string> &pal, vector<int> & frec ){
  int cuantas;   
  for (int i = ini; i<fin; i++){
     
     cuantas = contar_hasta(libro,ini,fin,libro[i]);
     pal.push_back(libro[i]);
     frec.push_back(cuantas);    
     }
}

     

/* Metodo que permite contar las frecuencia de aparicion de una palabra en un libro

  libro : vector de palabras sobre el que queremos contar las frecuencias
  ini: posicion inicio del libro
  fin: limite superior del libro hasta la que queremos contar (libro[ini] hasta libro[fin-1])
  pal: vector de palabras ya leidas  
  frec: numero de veces que ocurre la palabra pal[i] en el libro (desde libro[ini] hasta libro[fin-1])
 
*/

void contar_frecuencias_V2( vector<string> & libro, int ini, int fin,
                         vector<string> &pal, vector<int> & frec ){
  int pos;   
  for (int i = ini; i<fin; i++){
     
     pos = buscar(pal, libro[i]);
     if (pos==POS_NULA) {
         pal.push_back(libro[i]);    // Analisis amortizado O(1)
         frec.push_back(1);    // Analisis amortizado O(1)
         }
     else {
         frec[pos]++;
         }
        
     }
}

/* Metodo que permite contar las frecuencia de aparicion de una palabra en un libro

  libro : vector de palabras sobre el que queremos contar las frecuencias
  ini: posicion inicio del libro
  fin: limite superior del libro hasta la que queremos contar (libro[ini] hasta libro[fin-1])
  pal: vector de palabras ya leidas  
  frec: numero de veces que ocurre la palabra pal[i] en el libro (desde libro[ini] hasta libro[fin-1])
 
*/

void contar_frecuencias_V3( vector<string> & libro, int ini, int fin,
                         vector<string> &pal, vector<int> & frec ){
  vector<string>::iterator pos;   
  for (int i = ini; i<fin; i++){
     
     pos = lower_bound(pal.begin(), pal.end(), libro[i]);  // O(log (n) ), n tama del vector  Busqueda Binaria
     if ((pos==pal.end()) || (*pos!=libro[i])) {
         frec.insert(frec.begin() + (pos-pal.begin()), 1);   //O(n)
         pal.insert(pos, libro[i]);            //O (n) 
         }
     else {
         frec[pos-pal.begin()]++; // O(1)
         }
        
     }
} 

/* Metodo que permite contar las frecuencia de aparicion de una palabra en un libro

  libro : vector de palabras sobre el que queremos contar las frecuencias
  ini: posicion inicio del libro
  fin: limite superior del libro hasta la que queremos contar (libro[ini] hasta libro[fin-1])
  pal: vector de palabras ya leidas  
  frec: numero de veces que ocurre la palabra pal[i] en el libro (desde libro[ini] hasta libro[fin-1])
 
*/

void contar_frecuencias_V4( vector<string> & libro, int ini, int fin,
                         vector<string> &pal, vector<int> & frec ){
 
  map<string,int> M;
  for (int i = ini; i<fin; i++)
     M[libro[i]]++;         // O( log(n) )
  
  map<string,int>::iterator it;
  for (it = M.begin(); it!= M.end(); ++ it){ // Bucle O(k log k) siendo k el numero de palabras distintas
    pal.push_back( (*it).first );        
    frec.push_back( (*it).second );
     }
} 

int main() {

 vector<string> Dicc;
 vector<string> Q;
 int pos;
 high_resolution_clock::time_point start,end;
 duration<double> tiempo_transcurrido;

  
vector<int> frecuencia;
vector<string> palabra;

 int contador =0;
 
 lee_fichero("lema.txt", Dicc); // Ojo, el vector no esta ordenado!!!
 cout << Dicc.size() << " " << Dicc.capacity() << endl;
 
 lee_fichero("quijote.txt", Q);
 cout << Q.size() << " " << Q.capacity() << endl;
 
 
 
 

////////////////////////////////////////////////////
 // CONTAR FRECUENCIAS V1
 ////////////////////////////////////////////////////
 cout << "contar frecuencias V1" << endl;
 for (int tama = 10; tama < 4000 ; tama+= 100){
 
 start = high_resolution_clock::now();
 
 contar_frecuencias_V1(Q, 0,tama, palabra, frecuencia);  
 
 end= high_resolution_clock::now();

 frecuencia.clear();
 palabra.clear();
tiempo_transcurrido  = duration_cast<duration<double> >(end-start);
cout << tama << " " << tiempo_transcurrido.count() << endl;
 
 }
 
 
 ////////////////////////////////////////////////////
 // CONTAR FRECUENCIAS V2
 ////////////////////////////////////////////////////
 frecuencia.clear();
 palabra.clear();
 cout << "contar frecuencias V2" << endl;
 for (int tama = 0; tama < 4000 ; tama+= 100){
 
 start =  high_resolution_clock::now();;
 
 contar_frecuencias_V2(Q, 0,tama, palabra, frecuencia);  
 
 end=  high_resolution_clock::now();; 
 frecuencia.clear();
 palabra.clear();
tiempo_transcurrido  = duration_cast<duration<double> >(end-start);;
cout << tama << " " << tiempo_transcurrido.count() << endl;
 }
 
 
 
 ////////////////////////////////////////////////////
 // CONTAR FRECUENCIAS V3
 ////////////////////////////////////////////////////
 frecuencia.clear();
 palabra.clear();
 cout << "contar frecuencias V3" << endl;
 for (int tama = 0; tama < 4000 ; tama+= 100){
 
 start =  high_resolution_clock::now();;
 
 contar_frecuencias_V3(Q, 0,tama, palabra, frecuencia);  
 
 end=  high_resolution_clock::now();; 
 
 frecuencia.clear();
 palabra.clear();

tiempo_transcurrido  = duration_cast<duration<double> >(end-start);
cout << tama << " " << tiempo_transcurrido.count() << endl;
 
 }
 
 ////////////////////////////////////////////////////
 // CONTAR FRECUENCIAS V4
 ////////////////////////////////////////////////////
 frecuencia.clear();
 palabra.clear();
 cout << "contar frecuencias V4" << endl;
 for (int tama = 0; tama < 4000 ; tama+= 100){
 
 start =  high_resolution_clock::now();;
 
 contar_frecuencias_V4(Q, 0,tama, palabra, frecuencia);  
 
 end=  high_resolution_clock::now();; 
 
 frecuencia.clear();
 palabra.clear();
 tiempo_transcurrido  = duration_cast<duration<double> >(end-start);
cout << tama << " " << tiempo_transcurrido.count() << endl;
 
 }
 
 




}
 
