/**
 * @file
 * @brief Clase Mutacion
 *
 */

/*
 * mutacion.h
 *
*/

#ifndef __MUTACION_H
#define __MUTACION_H

#include <string>
#include <iostream>
#include <vector>
#include <cctype> // para isdigit
#include "enfermedad.h"

using namespace std;
//! Clase mutacion, asociada a la definición de una mutación/SNP
/*! mutacion::mutacion,  .....
 *
 @todo Implementa esta clase, junto con su documentación asociada

*/

/**
 * @brief Crea una mutacion con todos los datos identificadores de dicha mutacion
 *
 */


class mutacion {
 private:
  string ID; //3º rsXXXXXXX
  string chr; //1º Num cromosoma, 1º numero de la linea
  unsigned int pos; //2º posicion, 2º numero de linea (largo) empieza en 1
  vector<string> ref_alt; //4º bases,
  //desde que acaba num de rs hasta RS mayus

  vector<string> genes; //5º GENEINFO hasta el final (;)
  bool common; //6º Buscar 0 o 1 o poner a false
  vector<float> caf; //8º CAF=num buscar hasta (;) sino poner a 0
  vector<enfermedad> enfermedades; //9º name CLNDBN
  // ID CLNDSDBID dbase CLNDSDB
  vector<int> clnsig; //7º CLNSIG num hasta ;

 public:


   /**
   * @brief Crea una mutacion vacia inicializando los atributos
   *
   */

   mutacion();

   /**
   * @brief Construye una mutacion como una copia de otra
   * @param m Mutacion a copiar
   */

   mutacion(const mutacion& m);

   /**
   * @brief Construye una mutacion a partir de un string
   * @param str String del que se extrae la informacion para construir la mutacion
   *
   * Se van extrayendo los valores avanzando un indice de lectura sobre el string, y leyendo en orden cada valor
   *
   *  ORDEN DE APARICION:
   *  1º: chr - numero de cromosoma (1-23)
   *  2º: pos - posicion, numero largo, empieza en 1
   *  3º: ID - rsXXXX, X numeros
   *  4º: ref_alt - Bases, desde que acaba ID hasta RS mayus
   *  5º: genes - Genes, GENEINFO (buscar) hasta el final (;)
   *  6º: common - COMMON, buscar, valores 0 o 1 o no aparecer (poner a 0)
   *  7º: clnsig - CLNSIG, buscar (num) y hasta final (;)
   *  8º: caf - CAF, buscar num y hasta (;), sino poner a 0
   *  9º: enfermedades - Buscar NOMBRE: name CLNDBN, ID: ID CLNDSDBID, DATABASE database CLNDSDB Con las 3 se tiene una enfermedad
   *
   */

   mutacion(const string & str);   //para crear objeto mutacion a partir de la cadena que contiene una línea completa del fichero de entrada


   /**
   * @brief Funcion auxiliar para eliminar espacios
   * @param input String del que se van a eliminar los espacios
   *
   *
   */

   string delSpaces(string &input);

   /**
   * @brief Establecer un ID a la mutacion
   * @param id String con el nuevo ID a establecer
   *
   *
   */

   void setID(const string & id);

   /**
   * @brief Establecer un chr (Numero de cromosoma) a la mutacion
   * @param chr Nuevo numero de cromosoma a establecer
   *
   *
   */

   void setChr(const string & chr);

   /**
   * @brief Establecer una nueva posicion
   * @param pos Posicion a establecer
   *
   *
   */

   void setPos(const unsigned int & pos);

   /**
   * @brief Establecer nuevas bases (ref_alt)
   * @param ref_alt Nuevas bases a establecer
   *
   *
   */

   void setRef_alt(const std::vector<string> & ref_alt);

   /**
   * @brief Establecer nuevos genes
   * @param genes Vector string con los nuevos genes a establecer
   *
   *
   */

   void setGenes (const std::vector<string> & genes);

   /**
   * @brief Dar nuevo valor a common
   * @param common Con el nuevo valor true o false para common de la clase
   *
   *
   */

   void setCommon (const bool & common);

   /**
   * @brief Nuevo caf a establecer
   * @param caf Vector de float con el nuevo caf
   *
   *
   */

   void setCaf(const std::vector<float> & caf);

   /**
   * @brief Nuevas enfermedades a establecer
   * @param enfermedades Vector de enfermedades con las nnuevas enfermedades
   *
   *
   */

   void setEnfermedades(const std::vector<enfermedad> & enfermedades);


   /**
   * @brief Establecer un nuevo setClnsig
   * @param clnsig Vector de enteros con los clnsig a establecer
   *
   *
   */

   void setClnsig (const std::vector<int> & clnsig);

   /**
   * @brief Devuelve el ID
   * @return el ID
   *
   *
   */


   string getID( ) const;

   /**
   * @brief Devuelve los cromosomas
   * @return chr
   *
   *
   */

   string getChr( ) const;

   /**
   * @brief Devuelve la posicion
   * @return posicion
   *
   *
   */

   unsigned int getPos( ) const;


   /**
   * @brief Devuelve las bases
   * @return bases (ref_alt)
   *
   *
   */

   const std::vector<string> & getRef_alt () const;

   /**
   * @brief Devuelve los genes
   * @return genes
   *
   *
   */

   const std::vector<string> & getGenes () const;

   /**
   * @brief Devuelve Common
   * @return common
   *
   *
   */

   bool getCommon () const;

   /**
   * @brief Devuelve caf
   * @return caf
   *
   *
   */

   const std::vector<float> & getCaf () const;

   /**
   * @brief Devuelve las enfermedades
   * @return enfermedades
   *
   *
   */

   const std::vector<enfermedad> & getEnfermedades () const;


   /**
   * @brief Devuelve Clnsig
   * @return Clnsig
   *
   *
   */

   const std::vector<int> & getClnsig () const;



   /**
   * @brief Operator =
   * @param m mutacion para asignar a this
   * @return *this
   *
   * Asigna la mutacion origen a this, haciendo las comprobaciones necesarias
   */

   mutacion & operator=(const mutacion & m);

   /**
   * @brief Operator ==
   * @param m mutacion para comparar con this
   * @return bool true o false
   *
   * Compara this con la mutacion origen (m) para determinar si son iguales o no
   */

   bool operator==(const mutacion & m) const;

   /**
   * @brief Operator !=
   * @param m mutacion para comparar con this
   * @return bool true o false
   *
   * Compara this con la mutacion origen (m) para determinar si son distintas o no
   */

   bool operator!=(const mutacion & m) const;

   /**
   * @brief Operator <
   * @param m mutacion origen para comparar con this
   * @return bool true o false
   *
   * Compara por numero de cromosoma que la mutacion orig sea mayor que this, en caso de igual numero de cromosoma comprueba la posicion
   */

   bool operator<(const mutacion & m) const;      //El orden viene determinado por Chr y pos. El primer criterio es el número de cromosoma. El orden para el número de cromosoma se rige por "1"<"2"<"3"<...<"22"<"X"<"Y"<"MT". Dos mutaciones del mismo cromosoma deben ordenarse según su posición, de menor posición a mayor (orden natural de enteros).


   /**
   * @brief Operator <<
   * @param os argumento ostream
   * @param m mutacion this
   * @return os
   *
   * Permite imprimir por pantalla una mutacion
   */

   friend ostream& operator<< ( ostream& os, const mutacion& m);   //Imprimir TODOS los campos del objeto mutación.
};

#include "mutacion.hxx"
#endif
