#include "abb.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
using namespace std;

void ListarAbb(ABB<int> &ab_bus){
    ABB<int>::nodo n;
    cout<<endl<<"Elementos ordenados: ";

    for (n=ab_bus.begin();n!=ab_bus.end();++n){
        cout<<*n<<" ";
    }
}

template <class T>
istream& operator>>(istream &is, ABB<T> &arbol){

    T elem;
    ABB<T>::iterator it = arbol.begin();

    is >> elem;

    while(it != arbol.end()){
        arbol.Insertar(elem);
        is >> elem;
    }

    return is;
}

template <class T>
ABB<T> NuevoArbol(const ABB<T> &A, const ABB<T> &B, const ABB<T> &C){
    ABB<T> R;
    ABB<T>::iterator it1 = A.begin();
    ABB<T>::iterator it2 = B.begin();
    ABB<T>::iterator it3 = C.begin();

    ABB<T>::iterator result = R.begin();

    while(it1 != A.end() && it2 != B.end() && it3 != C.end()){
        if(*it1 == *it2 && *it1 != *it3)
            R.Insertar(*it1);
    }

    return R;
}

int main(){

    ABB<T> arbol1;
    ABB<T> arbol2;
    ABB<T> arbol3;

    ABB<T> arbolResultante;

    cout << "\nIntroduzca los elementos del primer árbol: ";
    cin >> arbol1;

    cout << "\nIntroduzca los elementos del primer árbol: ";
    cin >> arbol2;

    cout << "\nIntroduzca los elementos del primer árbol: ";
    cin >> arbol3;

    cout << "\nLos árboles listados son: ";

    cout << "\nArbol 1 : " << endl;
    ListarAbb(arbol1);

    cout << "\nArbol 2 : " << endl;
    ListarAbb(arbol2);

    cout << "\nArbol 3 : " << endl;
    ListarAbb(arbol3);

    arbolResultante = NuevoArbol(arbol1,arbol2,arbol3);

    cout << "\nEl árbol resultante de la operación es: " << endl;
    ListarAbb(arbolResultante);

    return 0;
}
