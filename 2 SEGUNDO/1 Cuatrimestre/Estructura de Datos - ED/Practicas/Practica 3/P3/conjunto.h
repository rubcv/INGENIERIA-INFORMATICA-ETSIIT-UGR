/*
 * conjunto.h
 *
 * Copyright  (C) Juan F. Huete y Carlos Cano
*/

#ifndef __CONJUNTO_H
#define __CONJUNTO_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

#include "mutacion.h"

using namespace std;

//! Clase conjunto
 /*! conjunto::conjunto, find, size,
 * Tipos conjunto::value_type, conjunto::size_type
 * Descripción

* Un conjunto es un contenedor que permite almacenar en orden creciente un conjunto de elementos no repetidos.  En nuestro caso el conjunto va a tener un subconjunto restringido de métodos (inserción de elementos, consulta de un elemento, etc). Este conjunto "simulará" un conjunto de la stl, con algunas claras diferencias pues, entre otros,  no estará dotado de la capacidad de iterar (recorrer) a través de sus elementos.

* Asociado al conjunto, tendremos el tipo  \code conjunto::value_type \endcode que permite hacer referencia al elemento  almacenados en cada una de las posiciones del conjunto, en nuestro caso mutaciones (SNPs). Es requisito que el tipo conjunto::value_type tenga definidos los operadores operator< y operator= .

* El número de elementos en el conjunto puede variar dinámicamente; la gestión de la memoria es automática.

 @todo Implementa esta clase siguiendo la especificación asociada
 */





class conjunto
{
public:
	typedef mutacion value_type;
	typedef unsigned int size_type;
	typedef vector<mutacion>::iterator iterator;
	typedef vector<mutacion>::const_iterator const_iterator;


	/** @brief Cuenta mutaciones desde begin hasta iterator
	*	@param posicion
	*	@return numero de mutaciones desde begin hasta iterador
	*/

	int getMutaciones(conjunto::const_iterator uno, bool cond);


	/** @brief constructor primitivo.
	*/
	conjunto( );


	/** @brief constructor de copia
	@param[in] d conjunto a copiar
	*/
	conjunto (const conjunto & d);


	/** @brief busca una entrada en el conjunto
	@param[in] chr: cromosoma de la mutación a buscar.
	@param[in] pos: posición en el cromosoma de la mutación.
	@param[in] ID: identificador de la mutación a buscar
	@param[in] e entrada. Utilizar e.getID() o la combinación e.getChr()/e.getPos() para buscar una mutación con igual ID o Chr/Pos, el resto de los valores de entrada pueden ser ignorados.
 	@return Si existe una mutación en el conjunto con ese chr/pos o ID, respectivamente, devuelve un par con una copia de la mutación en el conjunto y con el segundo valor a true. Si no se encuentra, devuelve la mutación con la definicion por defecto y false
	@post no modifica el conjunto.
	\verbatim Uso 1:
	if (C.find("1", 6433456).second ==true) cout << "Found." ;
	else cout << "Not found.";
	\endverbatim
	\verbatim Uso 2:
	if (C.findID("rs12345").second ==true) cout << "Found." ;
	else cout << "Not found.";
	\endverbatim

	*/
	pair<conjunto::value_type,bool>  find(const string & chr, const unsigned int & pos) const;
	pair<conjunto::value_type,bool>  find(const string & ID) const;
	pair<conjunto::value_type,bool>  find(const conjunto::value_type & e) const;


	/** @brief Cuenta las mutaciones con el Chr indicado como parametro
	* @param chr Chr de la mutacion a contar
	*/
	conjunto::size_type countChr (const string & chr) const;

	/** @brief cuenta cuantas entradas coinciden con los parámetros dados.
	@param[in] chr de la mutación.
	@param[in] pos de la mutación.
	@param[in] ID de la mutación.
	@param[in] e entrada. Utilizar e.getID() para buscar cuántas mutaciones tienen el mismo ID, el resto de los valores de entrada no son tenidos en cuenta
	@return Como el conjunto de mutaciones no puede tener entradas repetidas, devuelve 1 (si se encuentra la entrada) o 0 (si no se encuentra).
	@post no modifica el conjunto.
	*/
	conjunto::size_type count (const string & chr, const unsigned int & pos) const;
	conjunto::size_type count (const string & ID) const;
	conjunto::size_type count (const conjunto::value_type & e) const;



	/** @brief Inserta una entrada en el conjunto
	@param e entrada a insertar
	@return true si la entrada se ha podido insertar con éxito, esto es, no existe una mutación con igual par chr/pos ni igual ID en el conjunto. False en caso contrario.
	@post Si e no esta en el conjunto, el size() sera incrementado en 1.
	*/
	bool insert( const conjunto::value_type & e);



	/** @brief Borra una entrada en el conjunto .
	Busca la entrada con chr/pos o id en el conjunto (utiliza e.getID() en el tercer caso) y si la encuentra la borra.
	@param[in] chr de la mutación a borrar.
	@param[in] pos de la mutación a borrar.
	@param[in] ID de la mutación a borrar.
	@param[in] e entrada con e.getID() que geremos borrar, el resto de los valores no son tenidos en cuenta
	@post Si esta en el conjunto su tamaño se decrementa en 1.
	*/
	bool erase(const string & chr, const unsigned int & pos);
	bool erase(const string & ID);
  bool erase(const conjunto::value_type & e);
  bool eraseChr(const string & Chr); // Metodo para calcular la eficiencia de erase

	/** @brief Borra todas las entradas del conjunto, dejandolo vacio.
	@post El conjunto se modifica, quedando vacio.
	*/
	void clear();

	/** @brief numero de entradas en el conjunto
	@post  No se modifica el conjunto.
	@return numero de entradas en el conjunto
	*/
	conjunto::size_type size() const ;


	/** @brief Chequea si el conjunto esta vacio (size()==0)
	@post  No se modifica el conjunto.
	*/

  	bool empty() const;


	/** @brief operador de asignación
	@param[in] org conjunto a copiar.
	@return Crea y devuelve un conjunto duplicado exacto de org.
	*/
	conjunto & operator=( const conjunto & org);


	/** @brief cuenta cuantas entradas hay en el conjunto por debajo ('antes', '<') de los parámetros dados.
	@param[in] chr de la mutación.
	@param[in] pos de la mutación.
	@param[in] e entrada.
	@return Devuelve un iterador al primer elemento que cumple que "elemento<e" es falso, esto es, el primer elemento que  es mayor o igual que e
	@post no modifica el conjunto.
	*/
	conjunto::const_iterator lower_bound (const string & chr, const unsigned int & pos) const;
	conjunto::const_iterator lower_bound (const string & ID) const;
	conjunto::const_iterator lower_bound (const conjunto::value_type & e) const;



	/** @brief cuenta cuantas entradas hay en el conjunto por encima ('después', '>') de los parámetros dados.
	@param[in] chr de la mutación.
	@param[in] pos de la mutación.
	@param[in] e entrada. Devuelve un iterador al primer elemento que cumple que "elemento>e", esto es, el primer elemento ESTRICTAMENTE mayor que e
	@post no modifica el conjunto.
	*/
	conjunto::const_iterator upper_bound (const string & chr, const unsigned int & pos) const;
	conjunto::const_iterator upper_bound (const conjunto::value_type & e) const;



private:
	vector<mutacion> vm; // vector que almacena los elementos del conjunto

	/** \invariant

	IR: rep ==> bool

	\li Para todo i, 0 <= i < vm.size() se cumple
		- vm[i].chr está en ("1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "X", "Y", "MT")
		- vm[i].pos > 0;
	\li Para todo i, 0 <= i < C.vm.size()-1 se cumple:
	  	a) si vm[i].chr == vm[i+1].chr, entonces: vm[i].pos < vm[i+1].pos
	  	b) si vm[i].chr != vm[i+1].chr, entonces  vm[i].chr < vm[i+1].chr (donde el orden para el número de cromosoma se rige por "1"<"2"<"3"<...<"22"<"X"<"Y"<"MT")
	*/

	/** @brief Chequea el Invariante de la representacion
	    @return true si el invariante es correcto, falso en caso contrario
	*/
	bool cheq_rep( ) const;


//------------------------------------------------------------

	/** @brief imprime todas las entradas del conjunto
	@post No se modifica el conjunto.
	Implementar tambien esta funcion
		*/

	friend ostream &  operator << ( ostream & sal, const conjunto & C);


};




#include "conjunto.hxx"
#endif
