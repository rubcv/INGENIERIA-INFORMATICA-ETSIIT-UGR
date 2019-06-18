
/**
 * @file ktree.h
 * @brief TDA ktree<T,K>
 *   Representa un árbol general con nodos etiquetados con datos del tipo T. Cada nodo puede tener entre 0 y K hijos como máximo, numerados de 0 a K-1
 * @author Juan F. Huete
 * @bug Por espeficicar

 El ktree<T,K> exporta los siguientes tipos:
 \li ktree<T,K> árbol general
 \li ktree<T,K>::node -> Hace referencia a un nodo del árbol
 \li ktree<T,K>::const_node -> Hace referencia a un nodo constante (no se puede modificar su contenido) del árbol
 \li ktree<T,k>::node::iterator -> Iteradores sobre los descendientes directos de un nodo
 \li ktree<T,K>::node::iterator -> Iterador constante sobre los descendientes directos de un nodo
 \li ktree<T,K>::size_type -> Hace referencia al tamaño del árbol (unsigned int)

   T debe tener definidas las operaciones:

   - T & operator=(const T & e);
   - bool operator!=(const T & e);
   - bool opertaor==(const T & e);

   Son mutables.
   Residen en memoria dinámica.

   Un ejemplo de su uso:
   @include ejemploKtree.cpp
*/

#ifndef __ktree_H__
#define __ktree_H__




#include <queue>
#include <string>
#include <iostream>

using namespace std;

template <typename T,  int K=2>
class ktree {
public:
  class node;
  class const_node;

  typedef unsigned int  size_type;


private:
  class celdaArbol;

public:
  /** @brief Valor del número de descendientes.
   * Es constante, tomando el  valor por defecto de 2, árbol binario
   *
   * \code
     ktree<char,5>::kvalue
   * \endcode
   */
  static const int kvalue = K;


  /** @brief Constructor primitivo por defecto.
      Crea un árbol nulo.
  */
  ktree();

  /** @brief Constructor primitivo.
      @param e Etiqueta para la raíz.
      Crea un árbol con un único nodo etiquetado con e y sus k hijos todos nulos
  */
  ktree(const T & e);

  /**
     @brief Constructor de copia.
     @param a árbol que se copia.
     Crea un árbol duplicado exacto de a.
  */
  ktree (const ktree<T,K> & a);

  /**
     @brief Destructor.
     Destruye el receptor liberando los recursos que ocupaba.
  */
  ~ktree();

  /**
     @brief Operador de asignación.

     @param a: árbol que se asigna.

     Destruye el contenido previo del receptor y le asigna un
     duplicado de a.
  */
  ktree<T,K> & operator=(const ktree<T,K> & a);

  /**
     @brief Obtener la raíz como nodo constante.Obtener el nodo raíz.

     @return nodo raíz del receptor.
  */
  const_node root() const;

   /**
     @brief Obtener el nodo raíz.

     @return nodo raíz del receptor.
  */
  node root();


  /**
     @brief Podar el subárbol localizado en el hijo k-ésimo de un nodo.

     @param n: nodo del receptor. !n.null()
     @param k: número de hijo de n
     @param dest: árbol destino donde se mueve el subárbol. Es MODIFICADO.

     Desconecta el subárbol localizado en el hijo k-ésimo de n, que pasa a
     ser un árbol nulo en el receptor. El subárbol anterior se devuelve sobre
     dest.
  */
  void prune_k_child(node n, int k, ktree<T,K> & dest);


  /**
     @brief Insertar un nodo como hijo k-ésimo  de un nodo n.

     @param n: nodo del receptor. !n.null().
     @param k: número de hijo de n
     @param e: etiqueta del nuevo nodo.

     Inserta un nuevo nodo con etiqueta e como hijo k-ésimo de n. Si n tuviese al menos un descendiente en dicha posición
     lo desconecta y destruye el subárbol.
  */
  void insert_k_child( ktree<T,K>::node & n, int k, const T & e);

  /**
     @brief Insertar un árbol como hijo k-ésimo  de un nodo.

     @param n: nodo del receptor. n != nodo_nulo.
     @param k: número de hijo de n
     @param rama: subárbol que se inserta. Es MODIFICADO quedando como árbol vacío tras la inserción-

     Inserta la rama como subárbol en la posición k-ésima del nodo n. Si hubiese un subárbol en esa posición lo destruye. Además, rama se hace árbol nulo.
  */
  void insert_k_child(node n, int k, ktree<T,K> & rama);

   /**
     @brief asignar subarbol. Hace del receptor una copia del subarbol de org con raíz en n
     @param n: nodo  de org a partir del que se copia. n != nodo_nulo.
     @param org: Arbol original (no se modifica).

     Si el arbol receptor contiene elementos, estos son eliminados.
  */
  void assing(const ktree<T,K> & org, node n);

  /**
     @brief asignar un nodo. Hace que el receptor sea un árbol con un único nodo con etiqueta e
     @param e: Etiqueta a asignar

     Si el arbol receptor contiene elementos préviamente, éstos son eliminados.
  */
  void assing(const T & e);

  /**
     @brief Hace nulo un árbol.
     Destruye todos los nodos del árbol receptor y lo hace
     un árbol nulo.
  */
  void clear();

  /**
     @brief Obtiene el número de nodos.
     @return número de nodos del receptor.
  */
  size_type size() const;

  /**
     @brief Comprueba si un árbol está vacío (es nulo).

     @return true, si el receptor está vacío (es nulo).
             false, en otro caso.
  */
  bool empty() const;


  /**
     @brief Operador de comparación de igualdad.

     @param a: árbol con que se compara el receptor.

     @return  true, si el receptor es igual, en estructura y
                 etiquetas a a.
              false, en otro caso.
  */
  bool operator==(const ktree<T,K> & a) const;

  /**
     @brief Operador de comparación de desigualdad.

     @param a: árbol con que se compara el receptor.

     @return  true, si el receptor no es igual, en estructura o
                    etiquetas a a.
              false, en otro caso.
  */

  bool operator!=(const ktree<T,K> & a) const;

   /**
     @brief Serializa el arbol.

     @param valor_nulo valor nulo para el parámetro de tipo T
     @param delim delimitar utilizado para separar valores en el árbol
     @param T2Str functor que recibe un valor de tipo T y lo convierte en string
     @return  cadena que representa el árbol serializado, obtenido al realizar un recorrido por
     niveles del mismo (donde los nodos nulos se representan con valor_nulo
  */

  template<class toString>
  string serialize(const T & valor_nulo, char delim, toString T2Str ) const;

   /**
     @brief Reconstruye el árbol a partir de una serialización válida.

     @param ser cadena que representa la serialización
     @param valor_nulo valor nulo para el parámetro de tipo T
     @param delim delimitar utilizado para separar valores en el árbol
     @param St2T functor que recibe un string, s, y lo convierte en un valor de tipo T correcto.
     @pre el string ser ha sido obtenido mediante el proceso serialize(valor_nulo,delim,T2Str)
     @pre Str2T es el proceso inverso de T2Str

     Genera el ktree<T,K> que dió origen al la serialización  representada por ser.
  */
  template<class String2T>
  void deserialize(const string & ser, const T & valor_nulo, char delim, String2T Str2T);

private:

  // Funciones auxiliares
  /**
     @brief Destruir subárbol.

     @param n: nodo raíz del subárbol que se destruye.
     @doc:
     Destruye el subárbol cuya raíz es n.
  */
  void destroy(ktree<T,K>::node n);


  /**
     @brief Copia subárbol.

     @param dest: nodo sobre el que se copia. dest.null().
            Es MODIFICADO.
     @param orig: raíz del subárbol que se copia.

     @doc
     Destruye el subárbol con raíz en dest. Sobre éste realiza
     un duplicado del subárbol con raíz en orig.
  */
  void copy(node & dest, const node &orig);


  /**
     @brief Cuenta el número de nodos.

     @param n: raíz del subárbol a contar.

     @return devuelve el número de nodos del subárbol que
             tiene n como raíz.

     Cuenta el número de nodos en el subárbol cuuya raíz es n.
  */
  int count(node n) const;

  /**
     @brief Comparación de igualdad.

     @param n1: raiz del primer subárbol.
     @param n2: raiz del segundo subárbol.

     @return true, si los dos subárboles son iguales, en
                   estructura y etiquetas.
             false, en otro caso.
  */
  bool equals(node n1, node n2) const;


  // Representación
  node laraiz;
  // size_type num_nodos;


  class celdaArbol {
    public:
    celdaArbol();
    celdaArbol(const T & e);

    T etiqueta;
    node pad;
    node hijos[K];

  };




public:

  /**
      TDA nodo.
      Modela los nodos del árbol binario.
  */

  class node {
    public:
      /**
         @brief Constructor primitivo
      */
      node();

      /**
         @brief Constructor de copia
         @param n: Nodo que se copia
      */
      node(const node & n);

      /**
         @brief Determina si el nodo es nulo
      */
      bool null() const;

      /**
         @brief Devuelve el padre del nodo receptor
         @pre !null()
      */
      node parent() const;

      /**
         @brief Devuelve el hijo k-ésimo  del nodo receptor
         @pre !null()
      */
      node k_child(int k) const;
      /**
         @brief Devuelve el hijo k-ésimo  del nodo receptor
         @pre !null()
      */
      node operator[](int k) const;


      /**
         @brief Devuelve una referencia a la etiqueta del nodo
         @pre Si se usa como consultor, !null()
      */
      T & operator*();

      /**
         @brief Devuelve la referecia constante a la etiqueta del nodo
         @pre !null()
        */
      const T & operator*() const;

      /**
        @brief Devuelve el numero de descendiente de un hijo con respecto a su padre
        @return un valor entre 0 y k-1 correspondiente a la posicion, o -1 si es el nodo raiz
      */
      int child_number( ) const;


      /**
         @brief Operador de asignación
         @param n: el nodo a asignar
      */
      node & operator=(const node & n);

      /**
         @brief Operador de comparación de igualdad
         @param n: el nodo con el que se compara
      */
      bool operator==(const node & n) const;

      /**
         @brief Operador de comparación de desigualdad
         @param n: el nodo con el que se compara
      */
      bool operator!=(const node & n) const;

    private:
      // Las siguientes funciones son privadas para uso exclusivo en ktree
      friend class ktree<T,K>;
      friend class child_iterator;

       /**
         @brief Constructor primitivo
         @param e: Etiqueta del nodo
      */
      node(const T & e);

      /**
         @brief Coloca el nodo padre de un nodo
         @param n El nodo que será padre del receptor. No nulo.
      */
      inline void parent(node n);

      /**
         @brief Coloca el nodo hijo k-ésimo de un nodo
         @param n El nodo que será hijo k-esimo del receptor. No nulo
      */
      inline void k_child(int k,node n);

       /**
         @brief Elimina el nodo actual
         @pre !null()
      */
      void remove();

      typename ktree <T,K>::celdaArbol * elnodo;

    public:
      class child_iterator {
        private:
            friend class node;
            celdaArbol * n_padre;
            unsigned int pos_actual;
        public:
          child_iterator();
          child_iterator(const child_iterator & x);
          node & operator*( );
          child_iterator & operator++();
          child_iterator  operator++(int );

          child_iterator & operator=(const child_iterator & x);
          bool operator==(const child_iterator & x);
          bool operator!=(const child_iterator & x);
      }; // Fin child_iterator

      /* primer hijo no nulo
       *
       * @return child_iterator que apunta al primer descendiente no nulo de un nodo
       *
       */
      child_iterator begin();
      /* end de los hijos
       *
       * @return child_iterator que apunta a la posición end de los  descendientes de un nodo
       *
       */
       child_iterator end();
  };



  class const_node {
    public:
      /**
         @brief Constructor primitivo
      */
      const_node();

      /**
         @brief Constructor para convertir node a const_node
         @param n: Nodo que se copia
      */
      const_node(const typename ktree<T,K>::node & n);

      /**
         @brief Constructor de copia
         @param n: Nodo que se copia
      */
      const_node(const const_node & n);

      /**
         @brief Determina si el nodo es nulo
      */
      bool null() const;

      /**
         @brief Devuelve el padre del nodo receptor
         @pre !null()
      */
      const_node parent() const;

      /**
         @brief Devuelve el hijo k-ésimo  del nodo receptor
         @pre !null()
      */
      const_node k_child(int k) const;
      /**
         @brief Devuelve el hijo k-ésimo  del nodo receptor
         @pre !null()
      */
      const_node operator[](int k) const;

      /**
         @brief Devuelve la referecia constante a la etiqueta del nodo
         @pre !null()
        */
      const T & operator*() const;

      /**
        @brief Devuelve el numero de descendiente de un hijo con respecto a su padre
        @return un valor entre 0 y k-1 correspondiente a la posicion, o -1 si es el nodo raiz
      */
      int child_number( ) const;


      /**
         @brief Operador de asignación
         @param n: el nodo a asignar
      */
      const_node & operator=(const const_node & n);

      /**
         @brief Operador de comparación de igualdad
         @param n: el nodo con el que se compara
      */
      bool operator==(const const_node & n) const;

      /**
         @brief Operador de comparación de desigualdad
         @param n: el nodo con el que se compara
      */
      bool operator!=(const const_node & n) const;

    private:
      // Las siguientes funciones son privadas para uso exclusivo en const_node

      friend class child_iterator;
      celdaArbol * elnodo;

    public:

      class child_iterator {
        private:
          friend class const_node;

          const celdaArbol * n_padre;
          unsigned int pos_actual;
        public:
          child_iterator();
          child_iterator(const child_iterator & it);
          child_iterator(const typename ktree<T,K>::node::child_iterator & x);

          const_node   operator*( ) const;
          child_iterator & operator++();
          child_iterator   operator++(int);

          child_iterator & operator=(const child_iterator & x);
          bool operator==(const child_iterator & x);
           bool operator!=(const child_iterator & x);
      }; // Fin child_iterator

      /* primer hijo no nulo
       *
       * @return child_iterator que apunta al primer descendiente no nulo de un nodo
       *
       */
      child_iterator begin() const;
      /* primer hijo no nulo
       *
       * @return child_iterator que apunta al primer descendiente no nulo de un nodo
       *
       */
      child_iterator cbegin() const;
      /* end de los hijos
       *
       * @return child_iterator que apunta a la posición end de los  descendientes de un nodo
       *
       */
      child_iterator end() const ;
      /* end de los hijos
       *
       * @return child_iterator que apunta a la posición end de los  descendientes de un nodo
       *
       */
      child_iterator cend() const ;
  };


};

#include "../src/ktree.hpp"
#include "../src/ktreeNode.hpp"


#endif
