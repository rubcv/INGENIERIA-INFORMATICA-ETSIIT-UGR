#include "bintree/bintree.h"
#include <iostream>
#include <cassert>

using namespace std;

void recorrido(bintree<int>::node n){
  if(!n.null()){
    cout<< *n;
    recorrido(n.left());
    recorrido(n.right());
  }
}

int main(){
  bintree<int> arbol;
  arbol.insert_left(arbol.root(), 1);
  arbol.insert_right(arbol.root(), 2);


}
