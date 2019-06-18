#include "bintree.h"

#include <iostream>

using namespace std;

template <typename T>
void recorridos(const bintree<T> &arb)
{
  cout << endl << "Tamaño: " << arb.size() << endl;
  cout << "preorden: ";
  for (bintree<int>::const_preorder_iterator it= arb.begin_preorder(); it!=arb.end_preorder(); ++it)
	  cout << *it << " ";
  cout << endl;

  cout << "postorden: ";
  for (bintree<int>::const_postorder_iterator it= arb.begin_postorder(); it!=arb.end_postorder(); ++it)
	  cout << *it << " ";
  cout << endl;

  cout << "inorden: ";
  for (bintree<int>::const_inorder_iterator it= arb.begin_inorder(); it!=arb.end_inorder(); ++it)
	  cout << *it << " ";
  cout << endl;

  cout << "niveles: ";
  for (bintree<int>::const_level_iterator it= arb.begin_level(); it!=arb.end_level(); ++it)
	  cout << *it << " ";
  cout << endl;
}

int main()
{
  bintree<int> arb(5);
  arb.insert_left(arb.root(), 22);
  bintree<int>::node n = arb.root().left();

  arb.insert_left(n, 25);
  arb.insert_right(n, 125);
  
  recorridos(arb);

  bintree<int> arb2 = arb, aux;
  if (arb2 == arb)
    cout << "Iguales" << endl;
  else
    cout << "Distintos" << endl;

  arb2.prune_right(arb2.root().left(), aux);
  // *(arb.root().left().right()) = 131;
  recorridos(arb2);

  if (arb2 == arb)
    cout << "Iguales" << endl;
  else
    cout << "Distintos" << endl;

  recorridos(aux);

  arb.insert_right(arb.root(), arb2);

  recorridos(arb);
  //arb.clear();
  aux.assign_subtree(arb, arb.root().left());
  recorridos(aux);
  aux.replace_subtree(aux.root().right(), arb, arb.root());

  recorridos(aux);
  recorridos(arb);


  return 0;
}
