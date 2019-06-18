//
// Ejercicio 10 - Relacion Pilas_Colas
//
//
// 10. Usando una pila y una cola,
// implementa una función que compruebe si un string es un palindromo.
//

#include <stack>
#include <queue>
#include <iostream>
#include <string>

using namespace std;



bool Palindromo(string str){ // Comprueba si el string es palindromo
  stack<char> pila; // Usa una pila
  queue<char> cola; // Una cola
  int tam = str.size();

  for(int i = 0; i < tam; i++){
    char dato = str[i];
    pila.push(dato); // Se guarda el dato en la pila y en la cola
    cola.push(dato);
  }

  bool palindromo = true;

  while(palindromo && (!pila.empty()) && (!cola.empty())){ // Se compara el principio de la palabra (front de la cola),\
                                                              con el final (top de la pila)
    char a = pila.top();
    char b = cola.front();

    if(a != b ){ // Si son distintos, no es palindromo
      palindromo = false;
    }

    pila.pop(); // Se va avanzando
    cola.pop();
  }

return palindromo;

}

int main(){

  string pal = "baab";

  if(Palindromo(pal)){
    cout<< "\nEs palindromo" << endl << endl;
  }else{
    cout<< "\nNo es palindromo" << endl << endl;
  }

}
