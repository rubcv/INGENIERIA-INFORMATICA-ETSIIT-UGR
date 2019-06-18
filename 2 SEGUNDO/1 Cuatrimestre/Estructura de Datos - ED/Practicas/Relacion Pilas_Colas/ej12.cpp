//
// Ejercicio 12 - Relacion Pilas_Colas
//
// 12. Implementa una cola con prioridad que contenga strings y
// de la que salgan primero las cadenas de caracteres más largas
// y que en caso de igualdad salgan por orden alfabético.

#include <queue>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* USAR FUNCTOR */

struct alfabetico{
  bool operator()(string a, string b){ // Definicion de operator()
      if(a.size() < b.size()){ // Comparamos tamaño
        return true;
      }
      if(a.size() > b.size()){ // Comparamos tamaño
        return false;
      }

      if(a.size() == b.size()){ // Si es el mismo, comparamos letras por orden alfabetico
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

string un = "holaaa";
string dos = "aa";
string tres = "bb";

cola.push(un);
cola.push(dos);
cola.push(tres);
cola.push(dos);
cola.push(un);

// cola = holaa aa bb aa holaa
// final(por longitud/orden alfabetico) -> holaa holaa aa aa bb


cout<< "Cola: " << endl;
while (!cola.empty()){
   cout << cola.top() << " ";
   cola.pop();
}

}
