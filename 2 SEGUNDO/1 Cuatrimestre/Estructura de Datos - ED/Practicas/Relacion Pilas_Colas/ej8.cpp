//
// Ejercicio 8 - Relacion Pilas_Colas
//
// 8. Implementa una función insertar(Q, pos, x)
// que inserte un elemento en una cola Q en la posición pos.
// La cola debe quedar como estaba antes de insertar el elemento
// (salvo por el nuevo elemento)

#include <queue>
#include <iostream>

using namespace std;


void Insertar(queue<int> &cola, int pos, int ele){
  int cont = cola.size() - pos;
  queue<int> copia; // Cola copia auxiliar

  while(cont > 0){ // Copiamos los primeros elementos antes de la posicion
    copia.push(cola.front());
    cola.pop();
    cont--;
  }

  copia.push(ele); // Copiamos el elemento en la posicion

  while(!cola.empty()){ // Copiamos el resto
    copia.push(cola.front());
    cola.pop();
  }

  cola = copia; // Devolvemos los datos a la cola original


}

int main(){
  queue<int> cola;

  cola.push(1);
  cola.push(1);
  cola.push(1);
  cola.push(1);
  cola.push(1);
  cola.push(1);

  Insertar(cola, 2, 5);
  cout<< "Cola:" << endl;
  while(!cola.empty()){
    cout<< cola.front();
    cola.pop();
  }
  cout<< endl;
}
