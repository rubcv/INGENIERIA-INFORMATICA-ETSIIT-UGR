//
// Ejercicio 1 - Relacion Pilas_Colas
//
// 1. Construye una función a la que se se le pase una pila P de tipo T y
// dos elementos x,y de tipo T y que modifique la pila de forma que todas
// las veces que aparezca x se substituya por y
// (quedando la pila en el mismo estado en el que estaba anteriormente).
// Para este ejercicio no se podrán utilizar iteradores.

#include <stack> // Funciones de pila
#include <iostream>

using namespace std;

template <typename T> // Template T de tipo


T Intercambiar(stack <T> &pila, T x, T y){
  stack <T> copia; // Pila copia
  while(!pila.empty()){
    T var = pila.top(); // Se comprueba el tope
    if(var == x){ // Si coincide con el valor a intercambiar, se guarda el contrario
      copia.push(y);
    }else{
      copia.push(pila.top()); // Si no coincide se guarda el que se saca
    }
    pila.pop(); // Se va avanzando la pila
  }
  while(!copia.empty()){
    pila.push(copia.top()); // La pila se vuelca en la copia, al final se vuelve a volcar en la pila con el orden correspondiente
    copia.pop();
  }
}

int main(){


  stack <int> pila; // Template de tipo entero
  pila.push(1);
  pila.push(1);
  pila.push(1);
  pila.push(1);

  Intercambiar(pila, 1, 2);

  while(!pila.empty()){
  cout<< pila.top() << endl;
    pila.pop();
  }

}
