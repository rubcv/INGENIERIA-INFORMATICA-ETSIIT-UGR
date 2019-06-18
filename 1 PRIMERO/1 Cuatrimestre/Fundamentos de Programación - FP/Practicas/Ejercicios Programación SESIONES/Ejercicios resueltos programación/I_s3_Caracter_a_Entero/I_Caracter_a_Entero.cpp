////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

/*
   Pasar un carácter que represente un dígito entre '0' y '9'
   a su correspondiente valor numérico
*/

#include <iostream>
#include <cstdlib>
using namespace std;


int main(){
	/*
	En primer lugar, ejecutamos y entendemos el siguiente código:
	*/
   /*
	int orden_caracter_cero;
	char caracter_cero;

	caracter_cero = '0';                  // Almacena 48
	orden_caracter_cero = caracter_cero;  // Almacena 48
													  // o lo que es lo mismo: orden_caracter_cero = '0';

	cout << "\nEl orden del carácter " << caracter_cero << " es: " << orden_caracter_cero;
	*/

	// El orden del carácter 0 es 48
	// Internamente ambas variables orden_caracter_cero y caracter_cero contienen 48
	// Sin embargo, cout imprime un pantalla un carácter o un entero dependiendo del tipo de dato de la variable

   /////////////////////////////////////////////////////////////////////////

	/*
	Queremos obtener el entero correspondiente a un carácter que representa un dígito numérico:
	'7' --> 7
	'3' --> 3
	Sabemos que sumar(restar) dos caracteres suma(resta) los órdenes correspondientes.
	Así pues:
	'7' - '3' es el entero resultante de hacer 55 - 51 = 4  (el resultado de restar dos char es un int)
	Lo mismo ocurre si hacemos lo siguiente:
	'7' - 51 es el entero 55 - 51 = 4

	'7' tiene un número de orden en la tabla ASCII siete veces superior al orden del carácter '0'.
	Por lo tanto:
	'7' - '0' es el entero 55 - 48 = 7

	También podríamos haber hecho lo siguiente:
	'7' - 48 que da como resultado el entero 55 - 48 = 7
	Sin embargo, este código no es elegante.
	A un programador le resultará difícil entender la expresión '7' - 48
	El entero 48 parece "un número mágico sacado de la manga"
	Mucho más intuitiva es la expresión '7' - '0'
	*/

   const char CARACTER_DIGITO_CERO = '0';
   char caracter;
   int caracter_a_entero;

   cout << "\nIntroduzca un carácter numérico  --> ";
   cin >> caracter;

   caracter_a_entero = caracter - CARACTER_DIGITO_CERO;

   cout << "\nEl entero correspondiente es " << caracter_a_entero;
   cout << "\n\n";
	system("pause");
}

