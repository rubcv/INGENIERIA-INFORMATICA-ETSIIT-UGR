// 5. Implementa una función que, dada una lista l de tipo T
// y un elemento x de tipo T, elimine el elemento x de todas las
// posiciones en las que aparezca en l.
// Por ejemplo: si x = 1 y l = (2, 1, 1, 1, 1, 5, 3)
// el resultado deberı́a ser (2, 5, 3)

#include <iostream>
#include <list>

using namespace std;

list <int> Borrar(int ele, list<int> lista){
  list<int> res;
  list<int>::iterator i;

  for(i = lista.begin(); i != lista.end(); i++){
    if(*i != ele){
      res.push_back(*i);
    }
  }
  return res;
}


int main(){

  int ele;
  list<int> lista;
  lista.push_back(1);
  lista.push_back(2);
  lista.push_back(2);
  lista.push_back(3);
  lista.push_back(4);
  lista.push_back(4);
  lista.push_back(5);

  cout<< "Lista: ";
  list<int>::iterator i;
  for(i = lista.begin(); i != lista.end(); i++){
    cout<< *i << " ";
  }
  cout<< endl;

  cout<< "Elije un elemento para borrar de la lista:" << endl;
  cin >> ele;

  cout<< "Lista: ";
  list<int> nueva = Borrar(ele, lista);
  for(i = nueva.begin(); i != nueva.end(); i++){
    cout<< *i << " ";
  }
}
