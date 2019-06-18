/**
 * @file 
 * @brief Clase byte.
 *
 */

#ifndef _byte_H_
#define	_byte_H_

#include <string>

using namespace std;

typedef unsigned char byte; 

/**
 * @brief Enciende un bit (Lo pone a 1)
 * @param b Dato byte en el que cambiar el bit
 * @param pos Posicion del bit a encender
 * 
 */
 
	void on(byte &b, int pos);


/**
 * @brief Apaga un bit (Lo pone a 0)
 * @param b Dato byte en el que cambiar el bit
 * @param pos Posicion del bit a apagar
 *
 */
 
	void off(byte &b, int pos);


/**
 * @brief Devuelve el bit de un byte en la posicion dada
 * @param b Byte del que extraer el bit
 * @param pos Posicion del bit a extraer
 * @return El bit en la posicion indicada
 * 
 */
 
	bool getbit(byte b, int pos);


/**
 * @brief Convierte un byte en string
 * @param b Byte a convertir en string
 * @return string con el contenido de @a byte
 * 
 */
 
	string byteToString(byte b);


/**
 * @brief Pone todos los bits de un byte a 1
 * @param b Byte a encender
 * 
 */
 
	void encender(byte &b);


/**
 * @brief Pone todos los bits de un byte a 0
 * @param b Byte a apagar
 * 
 */
 
	void apagar(byte &b);


/**
 * @brief Enciende los leds segun la configuracion de un vector de tamaño 8
 * @param b Byte con los bits a encender o apagar
 * @param v Vector de bool con la configuracion para encender o apagar bits
 * 
 */
 
	void asignar(byte &b, const bool v[]);


/**
 * @brief Asigna a un vector de bool el estado de cada bit
 * @param b Byte con los bits
 * @param v Vector de bool en el que volcar el estado de los bits
 * 
 */
 
	void volcar(byte b, bool v[]);


/**
 * @brief Crea un vector con todos los bits encendidos en un byte
 * @param b Byte que contiene los bits
 * @param posic Vector para guardar las posiciones de los bits encendidos
 * @param cuantos Entero con el tamaño de @a posic
 * 
 */
 
	void encendidos(byte b, int posic[], int &cuantos);

#endif
