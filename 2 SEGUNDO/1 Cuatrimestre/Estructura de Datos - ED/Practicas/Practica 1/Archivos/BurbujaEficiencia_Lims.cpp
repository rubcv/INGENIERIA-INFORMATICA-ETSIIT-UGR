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


void calcula_tiempo(int tama){

  high_resolution_clock::time_point tantes,tdespues;
  duration<double> tiempo_transcurrido;

  vector<int> V(tama);
  generar_aleatorio(V);

   
  tantes = high_resolution_clock::now();
  burbuja(V,0,V.size()); // Solo queremos evaluar este algoritmo
  tdespues = high_resolution_clock::now();

  V.clear();


  tiempo_transcurrido  = duration_cast<duration<double> >(tdespues - tantes);
  cout << tama << " " << tiempo_transcurrido.count() << endl;
   
}

int main(int argc, char * argv[]){
  int tmin,tmax,inc; // tamaño minimo, maximo e incremento
  // Llamada ejecutable minimo maximo inc   

  if (argc < 4) {
     cout << "Llamada ejecutable tminimo tmaximo inc" <<endl;
     return(0);
  }
  else {
     tmin = std::atoi(argv[1]);
     tmax = std::atoi(argv[2]);
     inc = std::atoi(argv[3]);
  }

  for (int i = tmin; i<=tmax; i+=inc)
     calcula_tiempo(i);



    
  return 0;

}
 
