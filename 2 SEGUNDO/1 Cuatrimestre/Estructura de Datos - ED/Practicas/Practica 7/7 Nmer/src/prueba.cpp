#include <iostream>
#include "Nmer.h"
#include <set>

using namespace std;

int main(){
  cout<< "\n\n******* Prueba de metodos, clase Nmer *******" << endl << endl;

  Nmer uno;

  uno.loadSerialized("datos/cadenaSimple.srl");
  // string cad = "AABCD";
  // cout << "Insertamos la cadena: " << cad << endl;
  // uno.sequenceADN(4, cad);

    string bus = "BC";
    cout << "Buscamos la subcadena: " << bus << endl;
    if(uno.containString(bus)){
      cout<< "Contine la cadena" << endl;
    }else{
      cout<< "No la contiene" << endl;
    }

    cout<< "\nrareNmer:" << endl;
    cout<< "por niveles, nivel 2 "<< endl;

    set<pair<string, int> >::iterator it = (uno.level(2)).begin();
    for(it; it != (uno.level(2)).end(); it++){
      cout << (*it).first << " ";
      cout << (*it).second << endl;
    }
    cout<< endl;
    cout << "size: " << uno.size() << endl;
    cout << "length: " << uno.length() << endl << endl;
    cout << "list_Nmer: " << endl;

    uno.list_Nmer();





}
