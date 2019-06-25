#include <iostream>
#include <vector>
#include <chrono>
#include <utility>

using namespace std;
using namespace std::chrono;

void Intercambiar(int & a, int & b){
  int aux = a;
  a = b;
  b = aux;
}


pair<int, int> Pivote(vector<int> v, int i, int j){
  pair<int, int> res;
  int piv, k, l;
  k = i;
  piv = v[i];
  l = j + 1;

  do{
    k = k + 1;
  }while(v[k] <= piv && k < j);

  do{
    l = l - 1;
  }while(v[l] > piv);

  while(k < l){
    Intercambiar(v[k], v[l]);

    do{
      k = k + 1;
    }while(v[k] <= piv);

    do{
      l = l - 1;
    }while(v[l] > piv);
  }
  Intercambiar(piv, v[l]);

  int cont = l;
  for(int j = i; j < cont; j++){
    if(v[j] == v[cont])
      Intercambiar(v[cont - 1], v[j]);
      cont--;
  }

  res.first = abs(cont - l); // Apariciones
  res.second = v[l]; // Elemento
}

int Moda(vector<int> &v, int ini, int fin){
  int moda;
  if(ini - fin == 0){
    moda = Pivote(v, 0, v.size() - 1).second;
  }else{
    int mitad = (ini + fin)/2;
    int mayor = Pivote(v, 0, v.size() - 1).first;
    int moda1 = Moda(v, ini, mitad);
    int moda2 = Moda(v, mitad + 1, fin);
    
    if(moda1 > moda2)
      return moda1;
    if(moda2 > moda1)
      return moda2;
  }

  return moda;
}


int main(int argc, char** argv){

    vector<int> v;

    if(argc != 2){
    cerr<< "Escribe " << argv[0] << " [secuencia]" << endl;
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

    int moda = Moda(v, 0, v.size() - 1);


    end =  high_resolution_clock::now();


    //el tiempo transcurrido es
    tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

    // Mostramos resultados
    cout << tam << "\t" <<tiempo_transcurrido.count() << endl;
    cout<< "Moda: " << moda << endl;
}
