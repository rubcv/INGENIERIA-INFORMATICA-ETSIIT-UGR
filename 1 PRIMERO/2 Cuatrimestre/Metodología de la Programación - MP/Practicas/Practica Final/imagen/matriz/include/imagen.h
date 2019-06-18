/**
 * @file 
 * @brief Clase imagen blanco y negro.
 *
 */

#ifndef _IMAGEN_H_
#define _IMAGEN_H_

#include <cstring>
#include <byte.h>
#include <pgm.h>
#include <fstream>
#include <lista.h>

typedef unsigned char byte; ///< byte = 8bits almacenado en un unsigned char

using namespace std;

/**
 * @brief Una imagen en blanco y negro. Cada píxel es un byte
 *
 */
 
class Imagen{
	
private:

   	int MAXPIXELS = 0; ///< numero maximo de pixeles que podemos almacenar 
   	byte **datos; ///< datos de la imagen
	int nfilas; ///< numero de filas de la imagen
   	int ncolumnas; ///< numero de columnsa de la imagen

/**
 * @brief Borra la imagen y sus dependencias
 * 
 */
   
	void destruir();

/**
 * @brief copia la imagen en un objeto auxiliar
 * @param orig Imagen a copiar
 *
 */
 
	void copiar(const Imagen& orig);

public:

	Imagen(); ///< Construye una imagen vacia (0 filas, 0 columnas)
   

/**
 * @brief Construye una imagen negra de tamaño @a filas x @a columnas
 * @param filas Numero de filas de la imagen
 * @param columnas Numero de columnas de la imagen

 * Construye una imagen de tamaño @a filas x @a columnas y pone todos 
 * sus elementos a 0.
 */

	Imagen(int filas, int columnas);
   
   
/**
 * @brief Constructor de copia
 * @param orig Objeto Imagen
 *
 * Copia los valores de @a orig en un nuevo objeto Imagen
 */
 
   	Imagen(const Imagen& orig);


/**
 * @brief Sobrecarga del operador de asignacion
 * @param orig Objeto Imagen
 *
 * Sobrecarga el operador = para los objetos Imagen
 */

	Imagen& operator =(const Imagen& orig);


/**
 * @brief Sobrecarga del operador de suma
 * @param orig Objeto Imagen
 * @return Objeto Imagen
 *
 * Concatena el objeto actual con @a orig
 */

	Imagen operator +(const Imagen& orig);


/**
 * @brief Sobrecarga del destructor
 *
 * Borra la imagen y sus dependencias
 */

	~Imagen();  

      
/**
 * @brief Crea una imagen negra de tamaño @a filas x @a columnas
 * @param filas Numero de filas de la imagen
 * @param columnas Numero de columnas de la imagen
 *
 * Dimensiona la imagen a tamaño @a filas x @a columnas y pone todos 
 * sus elementos a 0.
 */
 
   	void crear(int filas, int columnas);
   
   
/**
 * @brief Devuelve el numero de filas de las imagen
 * @return el numero de filas de la imagen
 *
 */
 
   	int filas() const; 

   
/**
 * @brief Devuelve el numero de columnas de las imagen
 * @return el numero de columnas de la imagen
 *
 */
 
   	int columnas() const; 
   

/**
 * @brief Asigna el valor @a v a la posicion (@a x,@a y) de la imagen
 * @param y Fila de la imagen
 * @param x Columna de la imagen 
 * @param v Valor a asignar
 * 
 * Asigna el valor @a v a la posicion (@a x,@a y) de la imagen. Dado que la imagen se guarda
 * como un vector, la posicion (@a x,@a y) corresponde a la posicion @a y * @c ncolumnas + @a x 
 * del vector.    
 */
  
   	void set(int y, int x, byte v); 
   
   
/**
 * @brief Devuelve el valor de la posicion (@a x,@a y) de la imagen
 * @param y Fila de la imagen
 * @param x Columna de la imagen 
 * @return el valor de la posicion (@a x,@a y) de la imagen
 *
 * Devuelve el valor de la posicion (@a x,@a y) de la imagen. Dado que la imagen se guarda
 * como un vector, la posicion (@a x,@a y) corresponde a la posicion @a y * @c ncolumnas + @a x 
 * del vector.    
 */
  
   	byte get(int y, int x)const; 
   
   
/**
 * @brief Asigna el valor @a v a la posicion @a i de la imagen considerada como vector
 * @param i Posicion de la imagen considerada como vector
 * @param v Valor a asignar
 * 
 * Asigna el valor @a v a la posicion @a i de la imagen considerada como vector. La posicion @a i 
 * corresponde con la posicion @c y * @c ncolumnas + @c x de la imagen donde @c y representa la 
 * fila y @c x representa la columna.    
 */
  
   	void setPos(int i, byte v); 
   
 
/**
 * @brief Devuelve el valor de la posicion @a i de la imagen considerada como vector
 * @param i Posicion de la imagen considerada como vector
 * 
 * Devuelve el valor de la posicion @a i de la imagen considerada como vector. La posicion @a i 
 * corresponde con la posicion @c y * @c ncolumnas + @c x de la imagen donde @c y representa la 
 * fila y @c x representa la columna.    
 */
  
   	byte getPos(int i) const;

   
/**
 * @brief Carga una imagen desde un fichero 
 * @param nombreFichero Nombre del fichero que contiene la imagen
 * @retval true Si ha tenido exito en la lectura
 * @retval false Si se ha producido algún error en la lectura
 *
 * Lee desde disco los datos de la imagen llamada @a nombreFichero y la guarda en la memoria. 
 * La funcion debe asegurarse de que la imagen es de un tipo de imagen conocido y de que su tamaño 
 * es menor del tamaño maximo permitido (@c MAXDATOS).
 */
  
   	bool leerImagen(const char nombreFichero[]);
   

/**
 * @brief Guarda una imagen desde un fichero 
 * @param nombreFichero Nombre del fichero que contiene la imagen
 * @param esBinario Toma el valor @c true si el fichero se escribe en formato binario o @c false en caso contrario.
 * @retval true Si ha tenido exito en la escritura
 * @retval false Si se ha producido algun error en la escritura
 *
 */
   
	bool escribirImagen(const char nombreFichero[], bool esBinario);


/**
 * @brief Dado un numero k, extrae el plano de bits k-esimo de la imagen actual y lo devuelva como una nueva imagen
 * @param k Valor entero
 * @return Objeto imagen
 * 
 * Definimos el plano k-esimo de una imagen como una nueva imagen con un tamaño identico, en la que 
 * el valor de cada pixel se obtiene colocando en el bit mas significativo (posicion 7) el bit k-esimo
 * del pixel correspondiente en la imagen original y el resto de bits a cero.
 */
  
	Imagen plano(int k);


/**
 * @brief Sustituye los pixeles de la imagen por caracteres ASCII
 * @param grises Cadena de caracteres con los caracteres ASCII que se usaran para dibujar
 * @param arteASCII Vector de caracteres que guardara la imagen en ASCII
 * @param maxlong Tamaño maximo de @a arteASCII
 * @retval true Si ha tenido exito en la conversion
 * @retval false Si se ha producido algún error en la conversion
 * 
 */
 
   	bool aArteASCII(const char grises[], char arteASCII[], int maxlong);


/**
 * @brief Dada una Lista, se convierte la Imagen en ASCII con las cadenas de caracteres de la Lista
 * @param celdas Lista que contiene las cadenas de caracteres
 * @retval true Si ha tenido exito en la conversion
 * @retval false Si se ha producido algún error en la conversion
 * 
 */
 
   	bool listaAArteASCII(const Lista celdas);
};

#endif
