
/**
 * @file Nmer.h
 * @brief TDA Nmer
 *   Representa un conjunto de Nmer subsecuencias de tamaño 1 hasta N que se pueden obtener a partir de una cadena de ADN
 * @author alumno
 * @bug Por espeficicar
 */


#ifndef __NMER_H
#define __NMER_H

#include <set>
#include "ktree.h"
#include <string>

using namespace std;

class Nmer {
public:
  typedef unsigned int size_type;


  /** @brief Constructor primitivo .
      Crea un Nmer de longitud maxima 0, con el valor ('-',0) en la raíz
  */
  Nmer();

  /** @brief Constructor de copia
  */
  Nmer(const Nmer &orig);


  /** @brief Imprime los Nmers
  * @todo Debemos de implementar este método de forma que nos garantizemos que se imprimen todos los Nmers.
  */
  void list_Nmer() const;


  /** @brief Máxima longitud de los Nmers almacenados
  */
  unsigned int length()const;



  /** @brief Número de Nmers almacenados
  */
  size_type size() const;

  /** @brief Asigna un Nmer a otro
  *   @orig Nmer para hacer la asignacion
  */
  Nmer & operator=(const Nmer &orig);

  /** @brief Devuelve el Nmer (subarbol) asociado a un prefijo.
  */
  Nmer Prefix(string adn);

  /** @brief Se devuelve un Nmer donde para cada nodo (representa una
  *    secuencia) se computa la suma de las frecuencias en *this y en referencia,
  *   @param reference Nmer de referencia para unir
  */
  Nmer Union(const Nmer reference) const;

  /** @brief Comprueba que el Nmer contiene la cadena dada por adn
  *   @param adn cadena a buscar
  */
  bool containString(const string adn) const;

  /** @brief Comprueba que el Nmer de referencia está incluido en el actual
  *   @param reference Nmer de referencia para ver si esta incluido en el Nmer actual
  */
  bool included(const Nmer reference) const;

  /** @brief Inserta la secuencia de ADN en el Nmer actual
  *   @param l tamaño de las subsecuencias a insertar
  *   @param adn secuencias para ir insertando
  */
  void sequenceADN(unsigned int l, const string &adn);

  /** @brief lectura fichero serializado
   * @param nombre_fichero fichero serializado con extension .srl
   *
   * Genera a partir del fichero el ktree que contiene todos los kmers asociados a una cadena de ADN
   *
   * La cadena original viene descrita en el fichero serializado
   */
  bool loadSerialized(const string & nombre_fichero);


  /** @brief Calcula la distancia entre 2 Nmer
  *   @param x Nmer origen para calcular la distancia
  */
  float Distance(const Nmer &x);


  /** @brief functor para ordenar de forma creciente
  *   @param a,b pair de string entero para comparar en funcion del segundo elemento
  *
  */
  struct ordenCrec{
    bool operator()(pair<string, int> a, pair<string, int> b){
      return (a.second < b.second);
    }
  };

  /** @brief functor para ordenar de forma decreciente
  *   @param a,b pair de string entero para comparar en funcion del segundo elemento
  *
  */
  struct ordenDecre{
    bool operator()(pair<string, int> a, pair<string, int> b){
      return (a.second > b.second);
    }
  };


  /** @brief Encuentra el Nmer de mayor longitud posible
  *   que aparezca un numero menor o igual que threshold
  *   @param threshold
  */
  set< pair<string, int> , Nmer::ordenCrec  > rareNmer(int threshold);


  /** @brief Encuentra el Nmer de mayor longitud posible
  *   que aparezca un numero mayor que threshold
  *   @param threshold
  */
  set< pair<string,int> ,  Nmer::ordenDecre > commonNmer(int threshold);


  /** @brief devuelve los Nmers de longitud l, ordenados en orden creciente de frecuencia.
  *   @param l entero longitud del Nmer
  */
  set< pair<string,int> ,  Nmer::ordenCrec  > level(int l);


  /** @brief Devuelve la raiz del Nmer
  */
  ktree<pair<char, int>, 4>::const_node root(){
    return el_Nmer.root();
  }


private:

  // Definicion de tipos
  typedef   ktree<pair<char,int>, 4>::node                                       node;
  typedef   ktree<pair<char,int>, 4>::const_node                                 cnode;
  typedef   typename ktree<pair<char,int>,  4>::node::child_iterator              cit;
  typedef   typename ktree<pair<char,int>,  4>::const_node::child_iterator        ccit;
  typedef   set< pair<string,int>, greater<pair<string,int> > >           distance_set;

  // Atributos
  ktree<pair<char,int>, 4> el_Nmer; // subsecuencias
  unsigned int max_long; // Mayor longitud de la cadena representada, esto es, el nivel máximo del árbol

  /** @brief Functor para convertir un string en un pair<char,int>
   * se utiliza en loadSerialized
   */
  class String2Base {
   public:
    pair<char,int> operator()( const string & cad) {
	    pair<char,int> salida;
	    salida.first = cad[0];
	    salida.second = std::stoi(cad.substr(1));
	    return salida;
    }
  };

   /** @brief Functor para convertir un pair<char,int> en un string
    * Necesario para serializar un Nmer.
   */
  class Base2String {
   public:
     string operator()( const pair<char,int> & x) {
       string salida = string(1,x.first) + " " + std::to_string(x.second);
       return salida;
     }
  };

  /** @brief inserta una cadena en el Nmer
  *   @param cadena Cadena que se inserta
  */
  void insertar_cadena(const string & cadena);


  /** @brief Recorre un Nmer en preorden
  *   @param n Nodo de partida, se muestra primero la raiz, luego hijo izquierda y luego hijo derecha
  */
  void recorrido_preorden(cnode n) const;


  /** @brief Convierte el Nmer en un string
      @param aux Nodo a partir del cual se va creando el string
  */
  string tree_toString(cnode aux, string & cadena) const;


};

#endif
