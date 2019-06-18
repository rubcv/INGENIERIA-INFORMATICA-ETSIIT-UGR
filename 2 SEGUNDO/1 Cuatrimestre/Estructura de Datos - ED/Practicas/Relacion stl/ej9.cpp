// 9. Implementa una función list<T> mezclar(const list<T> &l1, const list<T> &l2)
// que dadas dos listas ordenadas l1 y l2 devuelva una lista ordenada
// mezclando las dos listas.
#include <iostream>
#include <list>

using namespace std;


template <typename T>
list<T> ordenar(list<T> &una, list<T> &otra){
  list<T> res;

typename  list<T>::iterator i = una.begin();
  typename list<T>::iterator j = otra.begin();
   T ele;

   if(*i < *j){
     ele = *j;
   }else{
     ele = *i;
   }

  for(i, j; i != una.end(), j != otra.end(); i++, j++){

    if(*i < ele){
      ele = *j;
      res.push_back(*i);
      una.pop_back();
    }else{
      res.push_back(*j);
      ele = *i;
      otra.pop_back();
    }
  }

  if(una.back()){
    typename  list<T>::iterator aux = i;
    for(aux; aux != una.end(); aux++){
      res.push_back(*aux);
    }
  }

  if(otra.back()){
    typename  list<T>::iterator aux = j;
    for(aux; aux != otra.end(); aux++){
      res.push_back(*aux);
    }
  }


}


int main(){
  list<int> lista;
  list<int> lista2;

  lista.push_back(1);
  lista.push_back(2);
  lista.push_back(3);
  lista.push_back(4);
  lista.push_back(7);

  lista2.push_back(3);
  lista2.push_back(5);
  lista2.push_back(7);
  lista2.push_back(8);
  lista2.push_back(9);
  lista2.push_back(9);

  cout<< "Lista 1: ";
  list<int>::iterator i;
  for(i = lista.begin(); i != lista.end(); i++){
    cout<< *i << " ";
  }
  cout<< endl;
  cout<< "Lista 2: ";
  list<int>::iterator j;
  for(j = lista2.begin(); j != lista2.end(); j++){
    cout<< *j << " ";
  }

  cout<< endl;
  list<int> final = ordenar(lista, lista2);
  cout<< endl;

  cout<< "Lista final ordenada: ";
  for(i = final.begin(); i != final.end(); i++){
    cout<< *i << " ";
  }
  cout<< endl<< endl;

}
