// 2. Construye una función que dado el map del ejercicio anterior
// devuelva un multimap que nos permita consultar las palabras que
// aparecen un número determinado de veces.
#include <iostream>
#include <map>
#include <fstream>
#include <iterator>

using namespace std;


class Comparacion{
public:
  bool operator()(int i, int j){
    return (i < j);
  }
};

int main(int argc, char** argv){
  if(argc != 2){
    cout<< "Escribe " << argv[0] << " [nombre-archivo]" << endl;
    exit(-1);
  }

  typedef map<string,int, Comparacion> apariciones;
  apariciones palabras;

  ifstream fin(argv[1]);
  if(!fin){
    cout<< "Error en apertura" << endl;
    exit(-1);
  }

  string entrada;
  while(fin>> entrada){
    palabras[entrada]++;
  }

  fin.close();

  apariciones::iterator i;
  for(i = palabras.begin(); i != palabras.end(); i++){
    cout<< "Palabra: " << i->first << " apariciones: " << i->second << endl;
  }


}
