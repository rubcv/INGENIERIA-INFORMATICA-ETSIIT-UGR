/**
@file 
@author DP
@date 16 de febrero de 2015, 19:33
@brief Funciones de manejo de bloqueLeds

*/

#ifndef _BLOQUELED_H_
#define	_BLOQUELED_H_

#include <cstring>

using namespace std;

typedef unsigned char bloqueLed; ///< Un @c bloqueLed contiene el estado de 8 LEDs

/**
@brief enciende el LED @p pos del @c bloqueLed @p b 
@param b 	el @c bloqueLed cuyo LED se quiere activar
@param pos 	el LED dentro de @p b que se quiere activar (0 más a la derecha)
*/
void on(bloqueLed &b, int pos);

/**
@brief apaga el LED @p pos del  @c bloqueLed @p b  
@param b 	el @c bloqueLed cuyo LED se quiere desactivar
@param pos 	el LED dentro de @p b que se quiere desactivar (0 más a la derecha)
*/
void off(bloqueLed &b, int pos);

/**
@brief devuelve el estado del LED (encendido = true, apagado = false) en la posición @p pos 
@param b 	el @c bloqueLed que se quiere consultar
@param pos 	el LED dentro de @ b que se quiere consultar (0 más a la derecha)
@retval true 	si el LED en la posición @p pos está encendido
@retval false	si el LED en la posición @p pos está apagado
*/
bool get(bloqueLed b, int pos);

/**
@brief Muestra por la salida estándar una secuencia de 0s y 1s correspondiente  al estado de cada LED
@param b el @c bloqueLed que se quiere imprimir

Muestra por la salida estándar una secuencia de 0s y 1s correspondiente  al estado de cada LED del bloqueLed donde un cero representa que un LED está apagado y un uno que el LED está encendido. Se implementa utilizando la función "get".

Por ejemplo, si en el @c bloqueLed @c b están encendidos los LEDs en posiciones 1 y 3 (0 más a la derecha), @c print(b); mostrará @c 00001010

*/
void print(bloqueLed b);

/**
@brief enciende todos los LEDs
@param b el @c bloqueLed que se quiere encender completamente. 
*/
void encender(bloqueLed &b);

/**
@brief apaga todos los LEDs
@param b el @c bloqueLed que se quiere apagar completamente. 
*/
void apagar(bloqueLed &b);

/**
@brief enciende los LEDs según la configuración de @p v
@param b el @c bloqueLed sobre el que se quiere actuar 
@param v vector de 8 elementos que contiene la secuencia de LEDS que se quieren asignar

Asigna a @p b la configuración de LEDs contenida en @p v. @p v es un vector de 8 booleanos donde @c true significa encendido y @c false significa apagado.
*/
void asignar(bloqueLed &b, const bool v[]);

/**
@brief recupera la configuración de todos los LED
@param b el @c bloqueLed que se quiere consultar
@param v vector de 8 elementos que contendrá el estado de cada uno de los LEDs de @ b

Vuelca en @p v la configuración de LEDs contenida en @p b. @c true significa encendido y @c false significa apagado. El tamaño de @p v debe ser 8.
*/
void volcar(bloqueLed b, bool v[]);

/**
@brief devuelve las posiciones de los LEDs encendidos
@param b el @c bloqueLed que se quiere consultar
@param posic vector de enteros (valores entre 0 a 7) que indican la posición de los LEDs de @p b que están encendidos
@param cuantos número de LEDs encendidos en @p b (número de elementos usados en el vector @p posic)
*/
void encendidos(bloqueLed b, int posic[], int &cuantos);

/**
@brief devuelve un string con una secuencia de 0s y 1s correspondiente al estado de cada LED.
Se debe implementar utilizando la funcion get()
*/
string bloqueLedToString(bloqueLed b);

#endif	

