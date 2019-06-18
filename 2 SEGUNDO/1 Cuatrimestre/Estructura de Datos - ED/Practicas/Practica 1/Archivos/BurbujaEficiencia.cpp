#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <cstdlib>


using namespace std;
using namespace std::chrono;


void generar_aleatorio(vector<int> & V){
  int i;
  for ( i=0; i<V.size();i++){
    V[i]=i;
  }
   random_shuffle(V.begin(),V.end()); //Desordenamos el vector
}

void burbuja(vector<int> & T, int inicial, int final)
{
 int i, j;
 int aux;
 for (i = inicial; i < final - 1; i++)
   for (j = final - 1; j > i; j--)
       if (T[j] < T[j-1])
         {
           aux = T[j];
           T[j] = T[j-1];
           T[j-1] = aux;
         }
}
int main(int argc, char * argv[]){
  int tama;
  // Llamada ejecutable N  (por defecto N es 10000)

  if (argc >= 2)
     tama = std::atoi(argv[1]);
  else tama = 10000;

  high_resolution_clock::time_point tantes,tdespues;
  duration<double> tiempo_transcurrido;

  vector<int> V(tama);
  //generar_aleatorio(V);

  int var = 0;
  const int tam = 10;

  while(var < tam){
    generar_aleatorio(V);

    tantes = high_resolution_clock::now();
    burbuja(V,0,V.size());
    tdespues = high_resolution_clock::now();


    tiempo_transcurrido  = duration_cast<duration<double> >(tdespues - tantes);
    cout << tama << " " << tiempo_transcurrido.count() << endl;

    V.clear();
    var++;
  }

  //
  // tiempo_transcurrido  = duration_cast<duration<double> >(tdespues - tantes);
  // cout << tama << " " << tiempo_transcurrido.count() << endl;

  // cout << std::chrono::duration_cast<std::chrono::seconds>(tdespues-tantes).count() << "" << endl;
  // cout << std::chrono::duration_cast<std::chrono::nanoseconds>(tdespues-tantes).count() << "" << endl;



  return 0;

}
