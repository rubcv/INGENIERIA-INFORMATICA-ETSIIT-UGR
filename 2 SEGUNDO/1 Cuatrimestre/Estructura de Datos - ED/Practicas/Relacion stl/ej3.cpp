// 3. Un método de encriptación basado en un código consiste en
// transformar cada letra del alfabeto por otra. Implementa una
// función encripta la que se le pasa una cadena de caracteres y
// un map < char, char > con el código y que devuelva la cadena
// encriptada.
#include <iostream>
#include <map>
#include <iterator>

using namespace std;
typedef map<char, char> codigo;

char* Encriptar(char* &cadena, codigo uno){

  int tam = 0;
  while(cadena[tam] != '\0'){
    cadena[tam] = uno[cadena[tam]];
    tam++;
  }
  return cadena;
}

int main(){

  const int TAM = 10;
  char cadena[TAM];
  codigo encrip;


  for(int i = 'a'; i != 'z'; i++){
    encrip[(char)i] = (char)(i + 1);
  }

  cout<< "CODIFICACION: " << endl;
  codigo::iterator i;
  for(i = encrip.begin(); i != encrip.end(); i++){
    cout<< "LETRA: " << i->first << " SUSTITUYE: " << i->second << endl;
  }

  cout<< endl;
  cout<< "Introduce la cadena de caracteres sin encriptar:(10 max):"<< endl;
  cin>> cadena;
  cout<< endl;

  char* cad = cadena;
  cout<< "Antes: " << cad << endl;
  cout<< "Despues: " << Encriptar(cad, encrip) << endl;
}
