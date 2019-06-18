// Ejemplo de uso del TDA ?bol binario

#include <iostream>
#include "bintree.h"

using namespace std;

template <typename T>
void recorridos(const bintree<T> &Arb)
{
  cout << "Usando iteradores const" << endl;

  cout << "Preorden:";
  for (bintree<int>::const_preorder_iterator i= Arb.begin_preorder(); i!=Arb.end_preorder(); ++i)
    cout << *i << " ";
  cout << endl;

  cout << "Postorden:";
  for (bintree<int>::const_postorder_iterator i= Arb.begin_postorder(); i!=Arb.end_postorder(); ++i)
    cout << *i << " ";
  cout << endl;

  cout << "Inorden:";
  for (bintree<int>::const_inorder_iterator i= Arb.begin_inorder(); i!=Arb.end_inorder(); ++i)
    cout << *i << " ";
  cout << endl;
  
  cout << "Por niveles:";
  for (bintree<int>::const_level_iterator i= Arb.begin_level(); i!=Arb.end_level(); ++i)
    cout << *i << " ";
  cout << endl;
}

template <typename T>
ostream& operator<<(ostream &os, const bintree<T> &arb);

int main()
{
  // Creamos el ?bol: 
  //        7
  //     /    \
  //   1        9
  //  /  \      /
  // 6    8    5
  //       \
  //       4
  bintree<int> Arb(7);
  
  Arb.insert_left(Arb.root(), 1);
  Arb.insert_right(Arb.root(), 9);
  Arb.insert_left(Arb.root().left(), 6);
  Arb.insert_right(Arb.root().left(), 8);
  Arb.insert_right(Arb.root().left().right(), 4);
  Arb.insert_left(Arb.root().right(), 5);


  cout << "Preorden:";
  for (bintree<int>::preorder_iterator i= Arb.begin_preorder(); i!=Arb.end_preorder(); ++i)
    cout << *i << " ";
  cout << endl;

  cout << "Postorden:";
  for (bintree<int>::postorder_iterator i= Arb.begin_postorder(); i!=Arb.end_postorder(); ++i)
    cout << *i << " ";
  cout << endl;

  cout << "Inorden:";
  for (bintree<int>::inorder_iterator i= Arb.begin_inorder(); i!=Arb.end_inorder(); ++i)
    cout << *i << " ";
  cout << endl;
  
  cout << "Por niveles:";
  for (bintree<int>::level_iterator i= Arb.begin_level(); i!=Arb.end_level(); ++i)
    cout << *i << " ";
  cout << endl;
  
  cout << "Preorden:";
  for (bintree<int>::preorder_iterator i= Arb.begin_preorder(); i!=Arb.end_preorder(); ++i)
    cout << *i << " ";
  cout << endl;

  cout << "Postorden:";
  for (bintree<int>::postorder_iterator i= Arb.begin_postorder(); i!=Arb.end_postorder(); ++i)
    cout << *i << " ";
  cout << endl;

  cout << "Inorden:";
  for (bintree<int>::inorder_iterator i= Arb.begin_inorder(); i!=Arb.end_inorder(); ++i)
    cout << *i << " ";
  cout << endl;
  
  cout << "Por niveles:";
  for (bintree<int>::level_iterator i= Arb.begin_level(); i!=Arb.end_level(); ++i)
    cout << *i << " ";
  cout << endl;
  
  
  recorridos(Arb);
  
  cout << Arb << endl;
}

template <typename T>
ostream& operator<<(ostream &os, const bintree<T> &arb)
{
  for (bintree<int>::const_level_iterator i= arb.begin_level(); i!=arb.end_level(); ++i)
    os << *i << " ";
  
  return os;
}
