#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <utility>
#include <random>
#include <chrono>
#include <cmath>
#include "ktree.h"
#include "Nmer.h"

using namespace std;
using namespace std::chrono;


std::ostream&   operator<<(ostream & s, const pair<char,int> & par){
  s << par.first << " " << par.second;
  return s;
}

template<typename T, int K>
vector<T> calcula_padres(typename ktree<T,K>::const_node  n){
vector<T> salida;
while (!n.null()){
 salida.push_back(*n);
 n = n.parent();
}
 return salida;
}


template<typename T, int K>
void recorrido_por_niveles_ej(const ktree<T,K> & a){
recorrido_por_niveles_ej<T,K>(a.root());
}



template<typename T, int K>
void recorrido_por_niveles_ej(typename ktree<T,K>::const_node  n){
typename ktree<T,K>::const_node aux;
queue<typename ktree<T,K>::const_node > cola;

if (!n.null())
  cola.push(n);

while (!cola.empty()){
  aux = cola.front();
  cola.pop();
  cout << "(" <<  (*aux)  <<"); ";
  for (auto hijo : aux)
    cola.push(hijo);
 }
cout << endl;
}


template<typename T, int K>
int Altura(const ktree<T,K> & arbol){
 return Altura<T,K>(arbol.root());

}

template<typename T, int K>
int Altura(typename ktree<T,K>::const_node   n){
int hmax=-1;
if (!n.null()){
  for (auto hijo:n) {
    int hact = Altura<T,K>(hijo);
    if (hact > hmax)
      hmax = hact;
  }
  return hmax+1;
 }
 else return -1;
}



template<typename T, int K>
void recorrido_preorden(const ktree<T,K> & arbol){
 recorrido_preorden<T,K>(arbol.root());

}

template<typename T, int K>
void recorrido_preorden(typename ktree<T,K>::const_node   n){

if (!n.null()){
  cout << "( " << (*n) <<"); " <<endl;
  typename ktree<T,K>::const_node::child_iterator ini = n.begin();
  typename ktree<T,K>::const_node::child_iterator fin = n.end();
  while (ini!=fin){
     recorrido_preorden<T,K>(*ini);
     ++ini;
   }
 }
}


template<typename T, int K>
void recorrido_inorden(const ktree<T,K> & arbol){
 recorrido_inorden<T,K>(arbol.root());

}

template<typename T, int = 2>
void recorrido_inorden(typename ktree<T,2>::const_node   n){

if (!n.null()){
   recorrido_inorden<T,2>(n.k_child(0));
   cout << *n <<"..";
   recorrido_inorden<T,2>(n.k_child(1));
   }
}


template<typename T, int K>
void listar_hijos(typename ktree<T,K>::node  n){

if (!n.null()){

  for (int i=0; i<K;i++){
   if (!n.k_child(i).null())
     cout <<"uso kchild" << *(n.k_child(i)) << endl;
  }

  typename ktree<T,K>::node::child_iterator ini = n.begin();
  typename ktree<T,K>::node::child_iterator fin = n.end();
  while (ini!=fin){
    typename ktree<T,K>::node aux = *ini;
     cout <<"uso iterador " << (*aux)  << ".." << endl;
     ++ini;
   }

  for ( typename ktree<T,K>::node hijo : n)
    cout <<  "uso for en rango  " << *hijo<< endl;
  cout <<"sss"<<endl;
 }
}




template <typename T>
void insertar_valorABB(ktree<T,2> & arbol, const T &valor){

  if (arbol.empty())
    arbol.assing(valor);
  else {
    typename ktree<T,2>::node n = arbol.root();
    bool insertado = false;
    int hijo;
    while (!insertado){
      if ( valor <*n) hijo =0;
      else  hijo = 1;

      if (n.k_child(hijo).null()){
	  arbol.insert_k_child(n, hijo,valor);
	  insertado = true;
      }
      else n=n.k_child(hijo);
    }
  }

}




template<typename T, int K>
void CambiaEtiquetas(typename ktree<T,K>::node  n, const T & antigua, const T & nueva){
if (!n.null()){
  if (*n==antigua)
     *n=nueva;
  for (int i=0; i<K;i++){
   if (!n.k_child(i).null())
    CambiaEtiquetas<T,K>(n.k_child(i),antigua, nueva);
  }
 }
}

//
// template<typename T, int K>
// void CambiaEtiquetas2(typename ktree<T,K>::const_node  n, const T & antigua, const T & nueva){
// cout <<"Modificamos etiquetas, lo que puede ser error "<< endl;
// if (!n.null()){
//
//   cout << "(c" << (*n) <<") ";
//   if (*n==antigua)
//      *n = nueva; //<---- NO compila, es const_node y no se puede cambiar su valor
//   for (int i=0; i<K;i++){
//    if (!n.k_child(i).null())
//     CambiaEtiquetas2<T,K>(n.k_child(i),antigua, nueva);
//   }
//  }
// }





void TiempoComparativo(  int tama){

ktree<int,2> abb;
multiset<int> cjto;
vector<int> datos;
datos.reserve(tama);
cout<< "\n Analisis comparativo de tiempos para abb (con ktree) y multiset para "<< tama << " datos"<<endl;
std::default_random_engine generator;
std::uniform_int_distribution<int> distribution(1,5000);

for (int i=0;i<tama;i++)
  datos.push_back(distribution(generator));


high_resolution_clock::time_point tantes,tdespues;
duration<double> tiempo_transcurrido;

tantes =  high_resolution_clock::now();
for (int i = 0; i< tama; i++){
  insertar_valorABB<int>(abb,datos[i]);
 }
tdespues = high_resolution_clock::now();
tiempo_transcurrido  = duration_cast<duration<double> >(tdespues - tantes);
cout << "arbol (size "<<abb.size() << ") t= " << tiempo_transcurrido.count() << endl;




tantes = high_resolution_clock::now();
for (int i = 0; i< tama; i++){
    cjto.insert(datos[i]);

}
tdespues =  high_resolution_clock::now();
tiempo_transcurrido  = duration_cast<duration<double> >(tdespues - tantes);
cout << "multiset  size( "<< cjto.size() << ") t= " << tiempo_transcurrido.count() << endl;


cout << "Altura: abb " << Altura(abb) << " multiset (cota superior) " << 2.0*log2(tama+1.0)<<endl;
}

int main(){


ktree<int,2> abb;

for (int i=3; i<10; i+=2)
  insertar_valorABB<int>(abb,i);


for (int i=1; i<15; i+=3)
  insertar_valorABB<int>(abb,i);


cout << "\n Listado hijos de la raiz" <<endl;
listar_hijos<int,2>(abb.root());

cout << "\n Listado en Inorden" <<endl;
recorrido_inorden<int,2>(abb);


cout << "\n Listado en Preorden" <<endl;
recorrido_preorden<int,2>(abb);

cout << "\n Listado por Niveles" << endl;
recorrido_por_niveles_ej<int,2>(abb);
int org = 5;
int nv = 0;
cout << "Modifico etiquetas "<< org << "->" << nv<< endl;
cout <<"(Si es arbol binario de busqueda puede violar el invariante)" <<endl;
CambiaEtiquetas<int,2>(abb.root(), org, nv);

cout << "\n Listado en Inorden" <<endl;
recorrido_inorden<int,2>(abb);

TiempoComparativo(1000000);

ktree<pair<char,int>,4> X;
recorrido_preorden(X);

Nmer prueba;
prueba.loadSerialized("../datos/cadenaSimple.srl");
prueba.list_Nmer();
cout << prueba.size() << " " << prueba.length() << endl;

return 0;

}
