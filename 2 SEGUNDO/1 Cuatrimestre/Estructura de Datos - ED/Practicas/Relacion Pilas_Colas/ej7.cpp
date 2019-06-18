//
// Ejercicio 7 - Relacion Pilas_Colas
//
// 7. Implementa una función insertar(P, pos, x)
// que inserte un elemento en una pila P en la posición pos.
// La pila debe quedar como estaba antes de
// insertar el elemento (salvo por el nuevo elemento)

#include <stack> // Usar funciones de pila
#include <iostream>

using namespace std;


void Insertar(stack<int> &pila, int pos, int ele){
  int cont = pos;
  stack<int> copia;

  while(cont > 0){ // Primero vaciar la original hasta el punto donde se quiere insertar
    copia.push(pila.top());
    pila.pop();
    cont--;
  }

  pila.push(ele); // Insertar el nuevo elemento

  while(!copia.empty()){ // Volver a rellenar la pila original
    pila.push(copia.top());
    copia.pop();
  }
}


int main(){


stack<int> pila;

int ele = 5;

pila.push(1);
pila.push(1);
pila.push(1);
pila.push(1);

Insertar(pila, 2, ele);

cout<< "\nPila: " << endl;
while(!pila.empty()){
cout<< pila.top() << endl;
  pila.pop();
}


}
