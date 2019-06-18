// 7. Implementa una función que dada una lista l
// devuelva una lista que tenga los elementos de l pero en orden inverso.
#include <iostream>
#include <list>

using namespace std;

template <typename T>
void invertir(list<T> &lista){
  list<T> aux;

  while(lista.back()){
    aux.push_back(lista.back());
    lista.pop_back();
  }
  lista = aux;
}


int main(){
  list<int> lista;

  lista.push_back(1);
  lista.push_back(2);
  lista.push_back(2);
  lista.push_back(2);
  lista.push_back(2);
  lista.push_back(3);
  lista.push_back(4);
  lista.push_back(4);
  lista.push_back(4);
  lista.push_back(4);
  lista.push_back(5);

  cout<< "Lista: ";
  list<int>::iterator i;
  for(i = lista.begin(); i != lista.end(); i++){
    cout<< *i << " ";
  }

  cout<< endl;
  invertir(lista);
  cout<< endl;

  cout<< "Lista invertida: ";
  for(i = lista.begin(); i != lista.end(); i++){
    cout<< *i << " ";
  }
  cout<< endl<< endl;
}
