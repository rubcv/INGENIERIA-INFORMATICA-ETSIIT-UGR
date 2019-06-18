//
// Ejercicio 13 - Relacion Pilas_Colas
//
// 13. Implementa una cola con prioridad que contenga strings y
// de la que salgan primero las cadenas de caracteres que tengan más vocales
// y que en caso de igualdad salgan por orden alfabético.
//

#include <queue>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

/* USAR FUNCTOR */

struct alfabetico{
  bool operator()(string a, string b){ // Definicion de operator()
    char vocales[5] = {'a', 'e', 'i', 'o', 'u'};
    int contA = 0, contB = 0;

    // Contar vocales de a

    for(int i = 0; i < 5; i++){
      for(int j = 0; j < a.size(); j++){
        if(vocales[i] == a[j]){
          contA++;
        }
      }
    }


    // Contar vocales de b

    for(int i = 0; i < 5; i++){
      for(int j = 0; j < b.size(); j++){
        if(vocales[i] == b[j]){
          contB++;
        }
      }
    }


      if(contA < contB){ // Comparamos tamaño
        return true;
      }
      if(contA > contB){ // Comparamos tamaño
        return false;
      }

      if(contA == contB){ // Si es el mismo, comparamos letras por orden alfabetico
          for(int i = 0; i < a.size(); i++){
            if(a[i] < b[i]){
              return false;
            }
          }
          return true;
      }
  }

};


int main(){

priority_queue<string, vector<string>, alfabetico > cola;

string un = "aba";
string dos = "aqa";
string tres = "aaaa";

cola.push(un);
cola.push(dos);
cola.push(tres);
cola.push(dos);
cola.push(un);

// cola = holaaa aa bb aa holaaa
// final(por vocales/orden alfabetico) -> holaaa holaaa aa aa bb


cout<< "Cola: " << endl;
while (!cola.empty()){
   cout << cola.top() << " ";
   cola.pop();
}

}
