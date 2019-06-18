/**
 * @file
 * @brief Clase Enfermedad
 *
 */


/*
 * enfermedad.h
 *
 * Copyright  (C) Juan F. Huete y Carlos Cano
*/

#ifndef __ENFERMEDAD_H
#define __ENFERMEDAD_H

#include <string>
#include <iostream>

using namespace std;

//! Clase enfermedad, asociada al TDA enfermedad
/*! enfermedad::enfermedad,  .....
 * Descripción contiene toda la información asociada a una enfermedad almacenada en la BD ClinVar-dbSNP (nombre de la enfermedad, id, BD que provee el id)

 @todo Implementa esta clase, junto con su documentación asociada

*/


/**
 * @brief Clase enfermedad con los atributos propios de la enfermedad
 *
 */

class enfermedad {
private:
  string  name;       // nombre de la enfermedad. Almacenar completo en minúscula.
  string  ID;         // ID único para la enfermedad
  string  database;   // Base de datos que provee el ID

public:


  /**
  * @brief Construye una enfermedad vacia
  *
  */

  enfermedad (); //Constructor de enfermedad por defecto

  /**
  * @brief Constructor por parametros
  * @param name nombre de la enfermedad
  * @param ID de la enfermedad
  * @param database de la enfermedad
  *
  */

  enfermedad (const string & name, const string & ID, const string & database);


  /**
  * @brief Asignar nuevo nombre a la enfermedad
  * @param name Nuevo nombre
  *
  */

  void setName(const string & name);

  /**
  * @brief Asignar nuevo ID a la enfermedad
  * @param ID Nuevo ID
  */

  void setID(const string & ID);

  /**
  * @brief Asignar nuevo database a la enfermedad
  * @param database Nuevo database
  *
  */

  void setDatabase(const string & database);


  /**
  * @brief Devuelve el nombre de la enfermedad
  * @return name
  *
  */

  string getName( ) const;

  /**
  * @brief Devuelve el ID de la enfermedad
  * @return ID
  */

  string getID( ) const;


  /**
  * @brief Devuelve la database de la enfermedad
  * @return database
  */

  string getDatabase( ) const;


  /**
  * @brief Operator =
  * @param e enfermedad origen para hacer la asignacion
  *
  *  Hace una asignacion de la enfermedad origen a this, realizando las comprobaciones necesarias
  */

  enfermedad & operator=(const enfermedad & e);


  /**
  * @brief Devuelve un string con los datos de la enfermedad
  *
  * @return string con los datos de la enfermedad separados por espacios
  */

  string toString() const;


  // Operadores relacionales

  /**
  * @brief Operator ==
  * @param e Enfermedad orig para comparar
  * @return true o false
  *
  * Compara enfermedad this con la de origen para ver si son iguales
  *
  */

  bool operator==(const enfermedad & e) const;

  /**
  * @brief Operator !=
  * @param e Enfermedad orig para comparar
  * @return true o false
  *
  * Compara enfermedad this con la de origen para ver si son distintas
  *
  */

  bool operator!=(const enfermedad & e) const;


  /**
  * @brief Operator <
  * @param e Enfermedad orig para comparar
  * @return true o false
  *
  * Compara enfermedad this con la de origen para ver si this es menor que orig,
  * orden alfabetico por campo name
  *
  */

  bool operator<(const enfermedad & e) const;	//Orden alfabético por campo name.


  /**
  * @brief Comprueba si el nombre de la enfermedad contiene el string
  * @param str string para buscar
  * @return true o false
  *
  * Busca el string dentro del string de campo name
  */

  bool nameContains(const string & str) const;   //Devuelve True si str está incluido en el nombre de la enfermedad, aunque no se trate del nombre completo. No debe ser sensible a mayúsculas/minúsculas.



  /**
  * @brief Operator <<
  * @param os Ostream
  * @param e Enfermedad this para imprimir
  *
  * Permite imprimir por pantalla una enfermedad
  *
  */

  friend ostream& operator<< ( ostream& os, const enfermedad & e); //imprime enfermedad (con TODOS sus campos)

};




#include "enfermedad.hxx" // Incluimos la implementacion.


#endif
