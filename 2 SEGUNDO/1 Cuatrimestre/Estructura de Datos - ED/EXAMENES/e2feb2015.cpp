#include <iostream>
#include <list>
#include <stack>

using namespace std;



void Borrar(list<stack<int> > &L, int ele){

}

int main(){

  list<stack<int> > lista;

  stack<int> pila1;
  pila1.push(1);
  pila1.push(9);
  pila1.push(2);

  stack<int> pila2;
  pila2.push(0);
  pila2.push(1);
  pila2.push(2);

  stack<int> pila3;
  pila3.push(2);

  stack<int> pila4;
  pila4.push(7);
  pila4.push(10);
  pila4.push(9);
  pila4.push(3);

  stack<int> pila5;
  pila5.push(2);
  pila5.push(4);

  stack<int> pila6;
  pila6.push(2);
  pila6.push(8);

  lista.push_front(pila6);
  lista.push_front(pila5);
  lista.push_front(pila4);
  lista.push_front(pila3);
  lista.push_front(pila2);
  lista.push_front(pila1);

  list<stack<int> > copia = lista;

  list<stack<int> >::iterator i;

  while(!copia.empty()){
    while(!(copia.front()).empty()){
      cout<< (copia.front()).top() << endl;
      (copia.front()).pop();
    }
    copia.pop_front();
    cout<< " ";
  }
}
