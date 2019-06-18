// 6. Implementa una función elimina_duplicados(list<T> &l)
// que elimine los elementos duplicados
// (sin ordenar previamente la lista).

#include <iostream>
#include <list>

using namespace std;

template <typename T>

void elimina_duplicados(list<T> &lista){

  list<T> otra;
  typename list<T>::iterator i = lista.begin();
  typename list<T>::iterator cont = otra.begin();


  for(i; i != lista.end(); i++){
    bool esta = false;
    for(typename list<T>::iterator j = cont; j != otra.end() && !esta; j++){
      if(*i == *j){
        esta = true;
      }
    }
    if(!esta){
      otra.push_back(*i);
      cont++;
    }
  }

  lista = otra;
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
  elimina_duplicados(lista);
  cout<< endl;

  cout<< "Lista sin repetidos: ";
  for(i = lista.begin(); i != lista.end(); i++){
    cout<< *i << " ";
  }
  cout<< endl<< endl;
}
