/**
 * @file 
 * @brief Clase para la estructura de datos de lista de strings
 *
 * Permite el manejo de cadenas (strings) en una lista enlazada
 *
 */
  
#ifndef _LISTA_H_
#define _LISTA_H_

#include <string>

using namespace std;
 
struct Celda{
	string datos; ///valor de la celda actual
	Celda * siguiente; ///puntero al siguiente elemento de la lista
};
  
class Lista{
	
private:
   
	Celda * cabecera;	

/**
 * @brief Libera la memoria reservada en la lista de cadenas
 * 
 * Libera la memoria reservada en el vetor de imagen y actualiza el numero 
 * de elementos de la misma a 0.
 */
 
	void destruir();   


/**
 * @brief inserta una nueva cadena al final de la lista
 * @param cadena Elemento a insertar en la lista
 * 
 * Añade un nuevo elemento ( @a cadena ) a la lista
 */
 
	void insertar(const string cadena);


/**
 * @brief copia la lista en un objeto auxiliar
 * @param orig Lista a copiar
 *
 */
 
	void copiar(const Lista& orig);

		    			
public:
	
/**
 * @brief Construye una lista vacia
 * 
 * Construye una lista vacia (0 elementos) 
 */
 
	Lista(); 
	 
  
/**
 * @brief Constructor de copia
 * @param orig Objeto Lista
 * 
 * Construye un nuevo objeto Lista a partir de @a orig
 */
 
	Lista(const Lista& orig);

	
/**
 * @brief Sobrecarga del operador =
 * @param orig Objeto Lista
 * @return Puntero a Lista
 * 
 * Sobrecarga el operador = para los objetos Lista
 */
 
	Lista& operator=(const Lista& orig);
 
   
/**
 * @brief Sobrecarga del operador +
 * @param orig Cadena de tipo string
 * @return Objeto Lista
 * 
 * Concatena @a orig a un objeto Lista
 */
 
	Lista operator+(const string&);
 
   
/**
 * @brief Sobrecarga del destructor
 * 
 * Borra la lista y sus dependencias
 */
 
	~Lista();


/**
 * @brief Construye una lista a partir de un elemento
 * @param cadena El elemento a insertar en la lista
 * 
 * Construye una lista de tamaño 1 e inserta la cadena @a cadena 
 */
 
	Lista(string cadena);


/**
 * @brief devuelve la celda de la posicion i-esima de la lista o una celda 
 * vacia en caso de que el valor de i sea erroneo.
 * @param i Indice del elemento dentro de la lista
 * @return la celda que se encuentra en el indice @a i si este valor esta 
 * en los margenes de la lista, o una celda vacia en caso contrario
 * 
 */
 
	string getCelda(int i) const;


/**
 * @brief devuelve el numero de celdas que contiene la lista
 * @return el tamaño de la lista
 * 
 */
 
	int longitud() const;


/**
 * @brief Construye una lista de celdas enlazadas a partir de la informacion 
 * contenida en un fichero.
 * @param nombreFichero Ruta del fichero de texto con el contenido de las cadenas
 * a insertar en la lista
 * @retval true Si ha tenido exito en la lectura y el formato es el correcto
 * @retval false Si se ha producido algún error en la lectura 
 * 
 * Lee desde disco los elementos almacenados en @a nombreFichero y los guarda 
 * en la lista. La función debe asegurarse de que la estructura sigue un patron 
 * determinado, y se ha de crear la lista con el numero de elementos que contenga. 
 */

	bool leerLista(const char nombrefichero[]);


/**
 * @brief devuelve la direccion de memoria de la celda
 * @return puntero a celda
 * 
 */
 
	Celda* getCabecera() const;
};

#endif
