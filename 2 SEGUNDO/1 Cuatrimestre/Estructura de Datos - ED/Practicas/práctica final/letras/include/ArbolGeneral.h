#ifndef __ArbolGeneral_h__
#define __ArbolGeneral_h__

#include <cassert>
#include <iostream>
using namespace std;

/**
   @brief T.D.A. ArbolGeneral
   
   \b Definición:
   Una instancia \e a del tipo de dato abstracto ArbolGeneral sobre un dominio 
   \e Tbase se puede construir como
   
   - Un objeto vacío (árbol vacío) si no contiene ningún elemento. 
   Lo denotamos {}.
   - Un árbol que contiene un elemento destacado, el nodo raíz, con un valor 
   \e e en el dominio \e Tbase (denominado \e etiqueta), y \e k subárboles 
   \f$(T_1, \ldots, T_k)\f$ del T.D.A. ArbolGeneral sobre \e Tbase.
    
   Se establece una relación \e padre-hijomasalaizquierda-hermanoaladerecha 
   entre cada nodo y los nodos raíz  de los subárboles (si los hubiera) que 
   cuelgan de él.  
   
   Para poder usar el tipo de dato ArbolGeneral se debe incluir el fichero
   
   <tt>\#include ArbolGeneral.h</tt>
   
   El espacio requerido para el almacenamiento es O(n), donde n es el número de
   nodos del árbol.
   
   @author 
   @date
*/

template <class Tbase>
class ArbolGeneral{
/**
  * @page repConjunto Rep del TDA Arbol General
  *
  * @section invConjunto Invariante de la representación
  *
  * Añadir el invariante de la representación
  *
  * @section faConjunto Función de abstracción
  *
  * Añadir la función de abstracción
  */

  private:
    /**
      *@brief nodo
      *
      * En cada  estructura \e nodo se almacena una etiqueta del árbol, que se 
      * implementa como un conjunto de nodos enlazados según la relación 
      * padre-hijo más a la izquierda-hermano derecha.
      */
    struct nodo {
      /**
        *@brief Elemento almacenado
        *
        * En este campo se almacena la etiqueta que corresponde a este nodo.
        */
      Tbase etiqueta;
      
      /**
        * @brief Puntero al hijo más a la izquierda
        *
        * En este campo se almacena un puntero al nodo raíz del subárbol más a 
        * la izquierda, o el valor 0 si no tiene.
        */
      nodo *izqda;
      
      /**
        * @brief Puntero al hermano derecho
        *
        * En este campo se almacena un puntero al nodo raíz del subárbol 
        * hermano derecho, o el valor 0 si no tiene.
        */
      nodo *drcha;

      /**
        * @brief Puntero al padre
        *
        * En este campo se almacena un puntero al nodo padre, o el valor 0 si 
        * es la raíz.
        */
       nodo *padre;
    };
    
    /**
      * @brief Puntero a la raíz.
      *
      * Este miembro es un puntero al primer nodo, que corresponde a la raíz 
      * del árbol. Vale 0 sin el árbol es vacío.
      */
    struct nodo *laraiz;
    
    /**
      * @brief Destruye el subárbol
      * @param n Nodo a destruir, junto con sus descendientes
      *
      * Libera los recursos que ocupan \e n y sus descendientes.
      */
    void destruir(nodo * n);
    
    /**
      * @brief Copia un subárbol
      * @param dest Referencia al puntero del que cuelga la copia
      * @param orig Puntero a la raíz del subárbol a copiar
      *
      * Hace una copia de todo el subárbol que cuelga de \e orig en el puntero
      * \e dest. Es importante ver que en \e dest->padre (si existe) no se 
      * asigna ningún valor, pues no se conoce.
      */
    void copiar(nodo *& dest, nodo * orig);
      
    /**
      * @brief Cuenta el número de nodos
      * @param n Nodo del que cuelga el subárbol de nodos a contabilizar.
      *
      * Cuenta cuántos nodos cuelgan de \e n, incluido éste.
      */
    int contar(const nodo * n) const;
    
    /**
      * @brief Comprueba igualdad de dos subárboles
      * @param n1 Primer subárbol a comparar
      * @param n2 Segundo subárbol a comparar
      *
      * Comprueba si son iguales los subárboles que cuelgan de \e n1 y \e n2. 
      * Para ello deberán tener los mismos nodos en las mismas posiciones y 
      * con las mismas etiquetas.
      */
    bool soniguales(const nodo * n1, const nodo * n2) const;
    
    /**
      * @brief Escribe un subárbol
      * @param out Stream de salida donde escribir
      * @param nod Nodo del que cuelga el subárbol a escribir
      *
      * Escribe en el flujo de salida todos los nodos del subárbol que cuelga 
      * del nodo \e nod siguiendo un recorrido en preorden. La forma de 
      * impresión de cada nodo es:
      *
      * - Si el nodo es nulo, imprime el carácter 'x'.
      * - Si el nodo no es nulo, imprime el carácter 'n' seguido de un 
      * espacio, al que sigue la impresión de la etiqueta
      */
    void escribe_arbol(std::ostream& out, nodo * nod) const;
    
    /**
      * @brief Lee un subárbol
      * @param in Stream de entrada desde el que leer
      * @param nod Referencia al nodo que contendrá el subárbol leído
      *
      * Lee del flujo de entrada \e in los elementos de un árbol según el 
      * formato que se presenta en la función de escritura.
      *
      * @see escribe_arbol
      */
    void lee_arbol(std::istream& in, nodo *& nod);
      
  public:
    /**
      * @brief Tipo Nodo
      * 
      * Este tipo nos permite manejar cada uno de los nodos del árbol. Los 
      * valores que tomará serán tantos como nodos en el árbol (para poder 
      * referirse a cada uno de ellos) y además un valor destacado
      * \e nulo (0), que indica que no se refiere a ninguno de ellos.
      *
      * Una variable \e n de este tipo se declara
      *
      * <tt>ArbolGeneral::Nodo n;</tt>
      *
      * Las operaciones válidas sobre el tipo nodo son:
      *
      * - Operador de Asignación (=).
      * - Operador de comprobación de igualdad (==).
      * - Operador de comprobación de desigualdad (!=).
      */
    typedef struct nodo * Nodo;


    /**
      * @brief Constructor por defecto
      *
      * Reserva los recursos e inicializa el árbol a vacío {}. La operación se
      * realiza en tiempo O(1).
      */
    ArbolGeneral();
    
    /**
      * @brief Constructor de raíz
      * @param e Etiqueta de la raíz
      *
      * Reserva los recursos e inicializa el árbol con un único nodo raíz que 
      * tiene la etiqueta \e e, es decir, el árbol {e, {}, {}}. La operación 
      * se realiza en tiempo O(1).
      */
    ArbolGeneral(const Tbase& e);
    
    /**
      * @brief Constructor de copias
      * @param v ArbolGeneral a copiar
      *
      * Construye el árbol duplicando el contenido de \e v en el árbol 
      * receptor.
      * La operación se realiza en tiempo O(n), donde \e n es el número
      * de elementos de \e v.
      */
    ArbolGeneral (const ArbolGeneral<Tbase>& v);

    /**
      * @brief Destructor
      *
      * Libera los recursos ocupados por el árbol receptor. La operación se 
      * realiza en tiempo O(n), donde n es el número de elementos del árbol 
      * receptor.
      */
    ~ArbolGeneral();
    
    /**
      * @brief Operador de asignación
      * @param v ArbolGeneral a copiar
      * @return Referencia al árbol receptor.
      *
      * Asigna el valor del árbol duplicando el contenido de \e v en el árbol 
      * receptor.
      * La operación se realiza en tiempo O(n), donde \e n es el número de 
      * elementos de \e v.
      */
    ArbolGeneral<Tbase>& operator = (const ArbolGeneral<Tbase> &v);
    
    /**
      * @brief Asignar nodo raíz
      * @param e Etiqueta a asignar al nodo raíz
      *
      * Vacía el árbol receptor y le asigna como valor el árbol de un único 
      * nodo cuya etiqueta es \e e.
      */
    void AsignaRaiz(const Tbase& e);
    
    /**
      * @brief Raíz del árbol
      * @return Nodo raíz del árbol receptor
      *
      * Devuelve el nodo raíz, que es 0 (nulo) si el árbol está vacío.
      * La operación se realiza en tiempo O(1).
      */
    Nodo raiz() const;
    
    /**
      * @brief Hijo más a la izquierda
      * @param n Nodo del que se quiere obtener el hijo más a la izquierda.
      * @pre \e n no es nulo
      * @return Nodo hijo más a la izquierda
      *
      * Devuelve el nodo hijo más a la izquierda de \e n, que valdrá 0 (nulo) 
      * si no tiene hijo más a la izquierda.
      * La operación se realiza en tiempo O(1).
      */
    Nodo hijomasizquierda(const Nodo n) const;
    
    /**
      * @brief Hermano derecha
      * @param n Nodo del que se quiere obtener el hermano a la derecha.
      * @pre \e n no es nulo
      * @return Nodo hermano a la derecha
      *
      * Devuelve el nodo hermano a la derecha de \e n, que valdrá 0 (nulo) 
      * si no tiene hermano a la derecha.
      * La operación se realiza en tiempo O(1).
      */
    Nodo hermanoderecha(const Nodo n) const;
    
    /**
      * @brief Nodo padre
      * @param n Nodo del que se quiere obtener el padre.
      * @pre \e n no es nulo
      * @return Nodo padre
      *
      * Devuelve el nodo padre de \e n, que valdrá 0 (nulo) si es la raíz.
      * La operación se realiza en tiempo O(1).
      */
    Nodo padre(const Nodo n) const;
    
    /**
      * @brief Etiqueta de un nodo
      * @param n Nodo en el que se encuentra el elemento.
      * @pre \e n no es nulo
      * @return Referencia al elemento del nodo \e n
      *
      * Devuelve una referencia al elemento del nodo \e n y por tanto se puede 
      * modificiar o usar el valor.
      * La operación se realiza en tiempo O(1).
      */
    Tbase& etiqueta(const Nodo n);
    
    /**
      * @brief Etiqueta de un nodo
      * @param n Nodo en el que se encuentra el elemento.
      * @pre \e n no es nulo
      * @return Referencia constante al elemento del nodo \e n.
      *
      * Devuelve una referencia al elemento del nodo \e n. Es constante y por 
      * tanto no se puede modificiar el valor.
      * La operación se realiza en tiempo O(1).
      */
    const Tbase& etiqueta(const Nodo n) const;
    
    /**
      * @brief Copia subárbol
      * @param orig Árbol desde el que se va a copiar una rama
      * @param nod Nodo raíz del subárbol que se copia. 
      * @pre \e nod es un nodo del árbol \e orig y no es nulo
      *
      * El árbol receptor acaba con un valor copia del subárbol que cuelga del 
      * nodo \e nod en el árbol \e orig. La operación se realiza en tiempo
      * O(n), donde \e n es el número de nodos del subárbol copiado.
      */
    void asignar_subarbol(const ArbolGeneral<Tbase>& orig, const Nodo nod);
    
    /**
      * @brief Podar subárbol hijo más a la izquierda
      * @param n Nodo al que se le podará la rama hijo más a la izquierda. 
      * @param dest Árbol que recibe la rama cortada
      * @pre \e n no es nulo y es un nodo válido del árbol receptor.
      *
      * Asigna un nuevo valor al árbol \e dest, con todos los elementos del 
      * subárbol izquierdo del nodo \e n en el árbol receptor. Éste se queda 
      * sin dichos nodos.
      *  La operación se realiza en tiempo O(1).
      */
    void podar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& dest);
    
    /**
      * @brief Podar subárbol hermano derecha
      * @param n Nodo al que se le podará la rama hermano derecha. 
      * @param dest Árbol que recibe la rama cortada
      * @pre \e n no es nulo y es un nodo válido del árbol receptor.
      *
      * Asigna un nuevo valor al árbol \e dest, con todos los elementos del 
      * subárbol hermano derecho del nodo \e n en el árbol receptor. Éste se 
      * queda sin dichos nodos.
      * La operación se realiza en tiempo O(1).
      */
    void podar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& dest);
    
    /**
      * @brief Insertar subárbol hijo más a la izquierda
      * @param n: Nodo al que se insertará el árbol \e rama como hijo más a la 
      * izquierda.
      * @param rama Árbol que se insertará como hijo más a la izquierda.
      * @pre \e n no es nulo y es un nodo válido del árbol receptor
      *
      * El árbol \e rama se inserta como hijo más a la izquierda del nodo \e n
      * del árbol receptor. El árbol \e rama queda vacío y los nodos que 
      * estaban en el subárbol hijo más a la izquierda de \e n se desplazan a 
      * la derecha, de forma que el anterior hijo más a la izquierda pasa a ser
      * el hermano a la derecha del nuevo hijo más a la izquierda.
      */
    void insertar_hijomasizquierda(Nodo n, ArbolGeneral<Tbase>& rama);

    /**
      * @brief Insertar subárbol hermano derecha
      * @param n Nodo al que se insertará el árbol \e rama como hermano a la 
      * derecha. 
      * @param rama Árbol que se insertará como hermano derecho.
      * @pre \e n no es nulo y es un nodo válido del árbol receptor
      *
      * El árbol \e rama se inserta como hermano derecho del nodo \e n del 
      * árbol receptor. El árbol \e rama queda vacío y los nodos que estaban a 
      * la derecha del nodo \e n pasan a la derecha del nuevo nodo.
      */
    void insertar_hermanoderecha(Nodo n, ArbolGeneral<Tbase>& rama);
    
    /**
      * @brief Borra todos los elementos
      *
      * Borra todos los elementos del árbol receptor. Cuando termina, el árbol
      * está vacía. La operación se realiza en tiempo O(n), donde \e n es el 
      * número de elementos del árbol receptor.
      */
    void clear();
    
    /**
      * @brief Número de elementos
      * @return El número de elementos del árbol receptor.
      *
      * La operación se realiza en tiempo O(n).
      * @see contar
      */
    int size() const;
    
    /**
      * @brief Vacío
      * @return Devuelve \e true si el número de elementos del árbol receptor 
      * es cero, \e false en caso contrario.
      *
      * La operación se realiza en tiempo O(1).
      */
    bool empty() const;
    
    /**
      * @brief Operador de comparación (igualdad)
      * @param v ArbolGeneral con el que se desea comparar.
      * @return Devuelve \e true si el árbol receptor tiene los mismos
      * elementos y en el mismo orden, \e false en caso contrario.
      *
      * La operación se realiza en tiempo O(n).
      * @see soniguales
      */
    bool operator == (const ArbolGeneral<Tbase>& v) const;
    
    /**
      * @brief Operador de comparación (diferencia)
      * @param v ArbolGeneral con el que se desea comparar.
      * @return Devuelve \e true si el árbol receptor no tiene los mismos 
      * elementos y en el mismo orden, \e false en caso contrario.
      *
      * La operación se realiza en tiempo O(n).
      */
    bool operator != (const ArbolGeneral<Tbase>& v) const;
      
    /**
      * @brief Operador de extracción de flujo
      * @param in Stream de entrada
      * @param v Árbol que leer
      * @return Referencia al stream de entrada
      *
      * Lee de \e in un árbol y lo almacena en \e v. El formato aceptado para
      * la lectura se puede consultar en la función de salida.
      * @see lee_arbol
      */
    template<class T> 
    friend std::istream& operator>>(std::istream& in, ArbolGeneral<T>& v);
    /**
      * @brief Operador de inserción en flujo
      * @param out Stream de salida
      * @param v Árbol que escribir
      * @return Referencia al stream de salida
      *
      * Escribe en la salida todos los nodos del árbol \e v siguiendo un 
      * recorrido en preorden. La forma de impresión de cada nodo es:
      *
      * - Si el nodo es nulo, imprime el carácter 'x'.
      * - Si el nodo no es nulo, imprime el carácter 'n' seguido de un 
      * espacio, al que sigue la impresión de la etiqueta.
      *
      * @see escribe_arbol
      */
    template<class T>
    friend std::ostream& operator<< (std::ostream& out, const ArbolGeneral<T>& v);
    
    
    
    /** 
     * @brief TDA. Iterador del ArbolGeneral  en preorden
     * */
    class iter_preorden{
       private:
	 Nodo it; ///<Puntero al nodo 
	 Nodo raiz; ///<Puntero a la raiz del arbol donde esta it
	 int level; ///< altura del nodo
       public:
	 
	 /**
	  * @brief Constructor por defecto
	  * 
	  * */
	 iter_preorden();
	 
	 /**
	  * @brief Obtiene la etiqueta del nodo
	  * 
	  * */
	 
	 Tbase & operator*();
	 
	 
	 /**
	  * @brief Obtiene el nivel del nodo
	  * 
	  * */
	 
	 
	 int getlevel()const;
	   
	 /**
	  * @brief Obtiene un iterador al siguiente nodo segun el recorrido en preorden
	  * 
	  * */
	 iter_preorden & operator ++();
	    
	 /**
	  * @brief Compara dos iteradores
	  * @param i: iterador con el  que se compara
	  * @return true si los dos iteradores son iguales (la raiz y el nodo son iguales). False en caso contrario
	  * */
	 bool operator == (const iter_preorden &i);
	 	    
	 /**
	  * @brief Compara dos iteradores
	  * @param i: iterador con el  que se compara
	  * @return true si los dos iteradores son diferentes (la raiz o  el nodo son diferentes). False en caso contrario
	  * */
	 
	 
	 bool operator != (const iter_preorden &i);
	 
	 
	 friend class ArbolGeneral;
    };
    class const_iter_preorden{
       private:
	  const nodo * it;
	  const nodo * raiz;
	 int level;
       public:
	 /**
	  * @brief Constructor por defecto
	  * 
	  * */
	 const_iter_preorden();
	 
	 /**
	  * @brief Obtiene la etiqueta del nodo
	  * 
	  * */
	 
	 const Tbase & operator*();
	 
	 
	 /**
	  * @brief Obtiene el nivel del nodo
	  * 
	  * */
	 
	 
	 int getlevel()const;
	   
	 /**
	  * @brief Obtiene un iterador al siguiente nodo segun el recorrido en preorden
	  * 
	  * */
	 const_iter_preorden & operator ++();
	    
	 /**
	  * @brief Compara dos iteradores
	  * @param i: iterador con el con que se comparación
	  * @return true si los dos iteradores son iguales (la raiz y el nodo son iguales). False en caso contrario
	  * */
	 bool operator == (const const_iter_preorden &i);
	 	    
	 /**
	  * @brief Compara dos iteradores
	  * @param i: iterador con el con que se comparación
	  * @return true si los dos iteradores son diferentes (la raiz o  el nodo son diferentes). False en caso contrario
	  * */
	 
	 
	 bool operator != (const const_iter_preorden &i);
	 
	 
	 friend class ArbolGeneral;
    };
    
    /**
     * @brief Inicializa un iterador a la raiz del arbol. Nivel -1
     */
    
     iter_preorden begin();
     const_iter_preorden begin()const 	
     
     
    /**
     * @brief Inicializa un iterador al nodo nulo con la raiz del arbol. Nivel -1
     */
     iter_preorden end();
     const_iter_preorden end()const 
    
};

#include "ArbolGeneral.cpp"



#endif
