#include <iostream>
#include <list>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

/**
 * @brief Imprime una lista de tipo T sobre el flujo de salida
 * @param s: flujo de salida. Es MODIFICADO
 * @param l: la lista con los elementos a imprimir
 * */

template <class T>
ostream & operator<<(ostream & s, const list<T> & l){

  typename list<T>::const_iterator i;

  for (i=l.begin(); i != l.end(); i++)
      s << (*i) << " ";

  return s;
}

/**
 * @brief Inicializar el generador de numero aleatorios
 *        Esta funcion debe ser llamada antes de usar rand
**/

void InicializarSemilla(){
  srand(time(0));
}

/**
 * @brief Genera numero enteros positivos aleatorios en el rango [min,max]
**/

int generaEntero(int min, int max){
    int tam = max - min+1;

    return ((rand()%tam)+min);
}

////////////////////////////////// INICIO EXAMEN ///////////////////////////////////
void InicializaValor(pair<char,int> par, list<pair<char,int> &miLista){
    char letra = 'A';
    list<pair<char,int>::iterator it;
    int apariciones = 0;

    while(letra <= 'Z'){
        par.first = letra;
        apariciones += generaEntero(1,27);
        par.second = apariciones;

        for(it = miLista.begin(); it != miLista.end(); it++){
            miLista.insert(it,par);
        }
    }
}

void SustituyeAparicion(list<pair<char,int> &miLista){
    double frecuencia;
    double totalApariciones = 0;

    for(it = miLista.begin(); it != miLista.end(); it++){
            totalApariciones += *it.second;
    }

    for(it = miLista.begin(); it != miLista.end(); it++){
            frecuencia = ( (*it.second)*100 ) / totalApariciones;
            miLista.insert(it.second,frecuencia);
    }
}

void OrdenaLista(list<pair<char,int> &miLista){

    list<pair<char,int>::iterator it;

    miLista.sort(*it.second);
}

list<pair<char,int> > nuevaLista(list<pair<char,int> &miLista){

}
////////////////////////////////// FIN EXAMEN ///////////////////////////////////

int main(){

  list<int> l;

  InicializarSemilla();

  for (int i=0;i<10;i++)
    l.push_back(generaEntero(1,100)); //inserta un entero generado aleatoriamente en el rango 1-100
  cout<<endl<<l;
}
