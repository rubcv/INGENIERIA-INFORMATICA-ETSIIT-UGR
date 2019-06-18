#ifndef _ARBOLBINARIO__
#define _ARBOLBINARIO__
#include <cassert>
#include <iostream>
#include <queue>
using namespace std;
/**
  TDA ArbolBinario de Busqueda
  @doc Definición : Una instancia \a a del tipo de dato abstracto ArbolBinario sobre un
  dominio T se puede construir como:
	  - Un objeto vacío si no contiene ningun elemento
	  - Un arbol que contiene un elemento destacad la raíz con un valor e en el dominio T
	     denominado etiqueta y dos subarboles (Ti:subarbol izquierdo, y Td:subarbol derecho) del
	     T.D.A Arbolbinario sobre T. Se establece una relación padre-hijo entre cada nodo y los
	     nodos raíz de los subarboles ( si existen) que cuelgan de el. Lo denotamos como
	     {e,{Ti},{Td}}. Además todas las etiquetas en {Ti} son menores o iguales a e y todas
	     las etiquetas {Td} son mayores que e.
	  Para poder usar el TDA ABB se debe incluir ABB.h
	  Son mutables. El espacio requerido para el almacenamiento es O(n) siendo n el numero de nodos.
*/

template <class T>
class ABB{
	  private:
	  struct info_nodo{
		    T et;
		    info_nodo * padre;
		    info_nodo * hizq;
		    info_nodo * hder;
		    info_nodo(){ padre=hizq=hder=0; }
		    info_nodo(const T & e){ et = e; padre=hizq=hder=0;}
	 };
	  //Funciones asociadas a info_nodo
	  /**
	    @brief Copiar un subarbol en otro
	    @param dest: objeto donde queda la copia. ES MODIFICADO
	    @param source: objeto desde el que se copia.
	  */

	  void CopiarInfo(info_nodo * &dest,const info_nodo*const &source);
	  /**
	    @brief Borra toda la información asociada a un subarbol
	    @param d: raiz del subarbol a borrar. ES MODIFICADO
	  */

	  void BorrarInfo(info_nodo *&d);

	  /**
	    @brief Devuelve el numero de nodos del subarbol
	    @param d: raiz del subarbol
	  */
	  unsigned int numero_nodos(const info_nodo*d)const ;


	  /**
	    @brief Devuelve true si los dos subarboles son iguales
	    @param s1: raiz del primer subarbol
	    @param s2: raiz del segundo subarbol
	    @note : el tipo T debe tener definido el operador ==
	  */
	  bool iguales(const info_nodo*s1,const info_nodo*s2)const ;
	  /**
	    @brief BUsca un elemento en el ABB
	    @param n: subarbol desde el que se empieza la búsqueda
	    @param x: elemento a buscar
	    @return devuelve la posicion donde está
	   */
	    info_nodo* Buscar(info_nodo *n,const T&e);



	  /**
	    @brief. Inserta un subarbol como hijo a la derecha de uno dado que consta de un solo nodo
	    @param n: subarbol al que se le inserta un nuevo subarbol como hijo a la derecha.
            @param e: etiqueta de la raiz del subarbol que se inserta
            @return true si es insertado false en caso contrario
           */

	  bool Insertar(info_nodo * &n,const T & e);

	  /**
	   @brief Modifica el hijo del padre de n
	   @param n: nodo hijo
	   @param nuevo: nodo que pone como hijo

	  */
	  void PutHijo_Padre(info_nodo *n,info_nodo*nuevo);

	  /**
	   @brief Elimina el elemento que está en n
	   @param n: nodo donde está la etiqueta a eliminar

	  */
	  void EliminarRaiz(info_nodo *&n);


	  /**
	    @brief Elimina la etique e buscandola a partir de n
	    @param n: subarbol sobre el que se busca la etiqueta
	    @param e : etiqueta a eliminar
	  */
	  void Borrar(info_nodo *& n,const T &e);
	   /**
	    @brief Lee un subarbol del flujo
	    @param is: flujo de entrada.
	    @param n: subarbol que se lee. ES MODIFICADO
	    @note si no existe el nodo aparece una x si existe una n
	   */



	  info_nodo * raiz;
 	  public:

		    //declaración adelantada del tipo nodo (posicionamiento en un arbolbinario)
		    class nodo;

		    /**
			 @brief Constructor por defecto
		    */
		    ABB():raiz(0){}

		    /**
		      @brief Constructor con parametros
		    */


		    ABB(const T &e);
		    ABB(typename ABB<T>::nodo n);
		    /**
		      @brief Constructor por copia
		    */
		    ABB(const ABB<T> & ab);

		    /**
		      @brief Destructor
		     */
		    ~ABB(){ clear();}
		    /**
		      @brief Operador de asignacion
		      @param ab: arbol binario del que se copia
		    */
		    ABB<T> & operator=(const ABB<T> & ab);

		    /**
		      @brief Obtiene un nodo apuntando a la raiz del arbol
		     */

		    typename ABB<T>::nodo getRaiz()const;

		    /**
			@brief Busca un elemento en el abb
			@param e:elemento a buscar
			@return true si el elemento esta false en caso contrario

		    */
		    bool Buscar(const T &e){
			      if (raiz==0) return false;
			      else
			      return !(Buscar(raiz,e)==0);
		    }
		    /**
		      @brief Inserta una nueva etiqueta en el arbol
		      @param e: etiqueta de la raiz del subarbol que se inserta
		      @return devuelve un nodo con la posicion insertada
		    */
		    bool Insertar( const T &e);

		    /**
		      @brief Borra una etiqueta en el arbol
		      @param e: etiqueta de la raiz del subarbol que se inserta

		    */
		    void Borrar(const T &e);
		   /**
		     @brief Borra todo arbol, dejandolo como un arbol vacio
		    */
		    void clear();

		    /**
		      @brief Arbol vacio
		      @return Devuelve si el arbol es vacio (true), y falso en caso contrario
		    */
		    bool empty()const ;

		    /**
		      @brief Tamaño de un arbol
		      @return Devuelve  el numero de nodos que tiene el arbol

		    */
		    unsigned int size()const ;

		    /**
		      @brief Igualdad entre dos arboles
		      @param a: arbo binario con el que se compara
		      @return true si los dos arboles son iguales false en caso contrario
		    */
		    bool operator==(const ABB<T> &a)const;

		    /**
		      @brief Desigualdad entre dos arboles
		      @param a: arbo binario con el que se compara
		      @return true si los dos arboles son distintos false en caso contrario
		    */
		    bool operator!=(const ABB<T> &a)const;



		    /******************************************************/
		    /*                   CLASE NODO			  */
		    /******************************************************/
		    class nodo{
			      private:
			         info_nodo *p;
				  /**
				  @brief Constructo con parametros
				  @param i: nodo que se copia
				  */
			         nodo (info_nodo * i):p(i){}
			      public:
				 /**
				  @brief Contructor por defecto
				 */
			         nodo ():p(0){}

			         /**
				   @brief Constructo de copia
				   @param n: nodo fuente
				 */
			         nodo (const nodo &n):p(n.p){}
			         /**
				   @brief acceso a la informacion del nodo
			         */
			         const T& operator*()const {
					   assert(p!=0);
					   return p->et;
				 }
			        T& operator*() {
					   assert(p!=0);
					   return p->et;
				 }
			        /**
				   @brief operacion de igualdad entre dos posiciones
				   @param n: nodo con el que se compara
				   @return true si son iguales false en caso contrario
				  */
				 bool operator==(const nodo &n){
					   return p==n.p;
				 }
				 /**
				   @brief operacion de desigualdad entre dos posiciones
				   @param n: nodo con el que se compara
				   @return true si son desiguales false en caso contrario
				  */
				 bool operator!=(const nodo &n){
					   return p!=n.p;
				 }
				 /**
				    @brief Nodo del padre
				    @return devuelve un nodo apuntando padre
				 */
				 nodo padre(){
					   if (p->padre!=0)
					    return nodo(p->padre);
					   else return nodo();
				 }
				 /**
				    @brief Nodo del padre
				    @return devuelve un nodo apuntando al hijo a la izquierda
				 */
				 nodo hi(){
					   if (p->hizq!=0)
					    return nodo(p->hizq);
					   else return nodo();
				 }
				 /**
				    @brief Nodo del padre
				    @return devuelve un nodo apuntando al hijo a la derecha
				 */
				 nodo hd(){
					   if (p->hder!=0)
					    return nodo(p->hder);
					   else return nodo();
				 }
				 /**
				    @brief dice si un nodo es nulo
				    @return true si es nulo false en caso contrario
				 */
				 bool nulo(){
					   return p==0;
				 }
				 /**
				    @brief Obtiene el siguiente nodo segun el orden inorden

				 */
				  nodo &operator++();

				 friend class ABB;


		    };

		    /***FUNCIONES BEGIN y EN PARA NODO***/
		    /**
		     @brief Comienzo de nodo en orden inorden
		     @return un nodo apuntando al comienzo según el orden inorden
		    */
		    nodo  begin()const ;
		    /**
		     @brief Fin de nodo en orden inorden
		     @return un nodo apuntando al comienzo según el orden inorden
		    */
		    nodo end()const;







};
#include "abb.cpp"
#endif
