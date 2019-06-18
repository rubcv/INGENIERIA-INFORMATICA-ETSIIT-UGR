// 1. Construye una función a la que se le pase el nobmre de un fichero
// y devuelva un map que contenga las palabras que aparecen
// y el número de veces que aparece cada una.

#include <iostream>
#include <map>
#include <fstream>
#include <iterator>

using namespace std;

int main(int argc, char** argv){
  if(argc != 2){
    cout<< "Escribe " << argv[0] << " [nombre-archivo]" << endl;
    exit(-1);
  }

  typedef map<string,int> apariciones;
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
