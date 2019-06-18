// 4. Implementa una función desencripta que haga el
// proceso inverso al del ejercicio anterior.
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

char* Desencriptar(char* &cadena, codigo uno){
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
  codigo desencrip;



  for(int i = 'a'; i != 'z'; i++){
    encrip[(char)i] = (char)(i + 1);
  }

  for(int i = ('a' + 1); i != 'z'; i++){
    desencrip[(char)i] = (char)(i - 1);
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
  cout<< "Encriptada: " << Encriptar(cad, encrip) << endl;
  cout<< "Desencriptada: " << Desencriptar(cad, desencrip) << endl;
}
