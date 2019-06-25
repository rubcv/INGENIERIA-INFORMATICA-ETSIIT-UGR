#include <iostream>
#include <vector>
#include <chrono>
#include <queue>
#include <utility>

using namespace std;
using namespace std::chrono;


int Pivote(vector<int> &v, int primero, int ultimo){
 int intercambia;
 int izda, dcha;
 int valor_pivote = v[primero];

 izda = primero + 1;
 dcha = ultimo;

 while(izda <= dcha){
   while(izda <= dcha && v[izda] <= valor_pivote)
    izda++;

  while(izda <= dcha && v[dcha] >= valor_pivote)
    dcha--;

  if(izda < dcha){
    intercambia = v[izda];
    v[izda] = v[dcha];
    v[dcha] = intercambia;
    dcha--;
    izda++;
  }
 }

 intercambia = v[primero];
 v[primero] = v[dcha];
 v[dcha] = intercambia;


 return dcha;
}

void Unir(vector<int> &v1, vector<int> &v2, int ini, int fin){
  if(fin - ini != 0){
    int piv = Pivote(v1, ini, fin);
    // Guardar pivote, buscar v1[piv] y swap con v2[ini] buscandolo en v2
    int elem, pos;
    bool enc = false;
    for(int i = 0; i < v2.size() && !enc; i++)
      if(v2[i] == v1[piv]){
        pos = i;
        enc = true;
      }

    elem = v2[pos];
    v2[pos] = v2[ini];
    v2[ini] = elem;

    Pivote(v2, ini, fin);
  
    int mitad = (ini + fin)/2;
    Unir(v1, v2, ini, mitad);
    Unir(v1, v2, mitad + 1, fin);
  }
}


int main(int argc, char** argv){

    vector<int> v1, v2;

    if(argc != 3){
      //cerr<< "Escribe " << argv[0] << " [secuencia 1] [secuencia 2]" << endl;
      exit(1);
    }

    string cad = argv[1];
    string cad2 = argv[2];
    int tam = cad.size();
    int tam2 = cad2.size();
    
    for(int i = 0; i < tam; i++){
      v1.push_back((int)cad[i] - '0');
    }
    for(int i = 0; i < tam2; i++){
      v2.push_back((int)cad2[i] - '0');
    }

    high_resolution_clock::time_point start, end;


    duration<double> tiempo_transcurrido;

    start = high_resolution_clock::now();

    Unir(v1, v2, 0, v1.size() - 1);

    end =  high_resolution_clock::now();

    //el tiempo transcurrido es
    tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

    // Mostramos resultados
    cout << tam << "\t" <<tiempo_transcurrido.count() << endl;



}
