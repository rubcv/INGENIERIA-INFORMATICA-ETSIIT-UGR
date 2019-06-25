#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;


pair<int, int> Max_Min(const vector<int> & v, int inicio, int fin){
  int menor, mayor;
  if(fin - inicio == 0){
    return make_pair(v[inicio], v[inicio]);
  }else{
    int mitad = (fin + inicio)/2;
    pair<int, int> p1 = Max_Min(v, inicio, mitad);
    pair<int, int> p2 = Max_Min(v, mitad + 1, fin);

     menor = p1.first;
     mayor = p1.second;
    if(menor > p2.first)
      menor = p2.first;

    if(mayor < p2.second)
      mayor = p2.second;

  }
  return make_pair(menor, mayor);
}

int main(int argc, char** argv){

  vector<int> v;

  if(argc != 2){
    //cerr<< "Escribe " << argv[0] << " [secuencia]" << endl;
    exit(1);
  }

  string cad = argv[1];
  int tam = cad.size();
  for(int i = 0; i < tam; i++){
    v.push_back((int)cad[i] - '0');
  }

  high_resolution_clock::time_point start, end;


  duration<double> tiempo_transcurrido;

  start = high_resolution_clock::now();

  pair<int, int> res = Max_Min(v, 0, v.size() - 1);


  end =  high_resolution_clock::now();


  //el tiempo transcurrido es
  tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

  // Mostramos resultados
  cout << tam << "\t" <<tiempo_transcurrido.count() << endl;

  //cout<< "Menor: " << res.first << endl;
  //cout<< "Mayor: " << res.second << endl;

}
