#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
  if(argc != 4){
    cerr<< "Escribe ./Ej3 fich1(entrada) fich2(entrada) fich3(salida)"<<endl;
    return 1;
  }

  ifstream fent1(argv[1]);
  ifstream fent2(argv[2]);

  if(!fent1 || !fent2){
    cerr<< "Fallo en la apertura de los ficheros"<< endl;
    return 1;
  }

  ofstream fsal(argv[3]);
  if(!fsal){
    cerr<<"Fallo en el fichero de salida"<< endl;
    return 1;
  }


  int n1, n2;

  fent1>> n1;
  fent2>> n2;

  while(!fent1.eof() && !fent2.eof()){
    if(n1 < n2){
      fsal<< n1 << " ";
      fent1>> n1;
    }else{
      fsal<< n2 << " ";
      fent2>> n2;
    }
  }


  if(!fent1.eof()){
    while(!fent1.eof()){
      fsal<< n1 << " ";
      fent1>> n1;
    }
  }

  if(!fent2.eof()){
    while(!fent2.eof()){
      fsal<< n2 << " ";
      fent2>> n2;
    }
  }

  fent1.close();
  fent2.close();
  fsal.close();
}
