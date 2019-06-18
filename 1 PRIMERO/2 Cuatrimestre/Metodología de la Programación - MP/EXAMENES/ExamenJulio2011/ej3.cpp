#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]){
  if(argc >=3){
    string buscar(argv[1]);
    ifstream fin;
    for(int i = 2; i < argc; i++){
      int linea = 1;
      string fichero(argv[i]);
      fin.open(fichero.c_str());
      if(fin){
        string cadena;
        while(fin){
          getline(fin, cadena, '\n');
          if(strstr(cadena.c_str(), buscar.c_str())){
            cout<< fichero << " (linea " << linea << "): " << cadena << endl;
          }
          linea++;
        }
        fin.close();
      }
    }
  }else{
    cerr<< "Escribe ./ej3 [palabra para buscar] [lista de archivos...] " << endl;
    return 1;
  }



}
