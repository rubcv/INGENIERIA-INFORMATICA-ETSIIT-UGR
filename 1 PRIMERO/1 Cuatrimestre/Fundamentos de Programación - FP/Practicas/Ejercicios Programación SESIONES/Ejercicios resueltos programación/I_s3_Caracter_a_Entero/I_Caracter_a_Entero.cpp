////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computaci�n e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

/*
   Pasar un car�cter que represente un d�gito entre '0' y '9'
   a su correspondiente valor num�rico
*/

#include <iostream>
#include <cstdlib>
using namespace std;


int main(){
	/*
	En primer lugar, ejecutamos y entendemos el siguiente c�digo:
	*/
   /*
	int orden_caracter_cero;
	char caracter_cero;

	caracter_cero = '0';                  // Almacena 48
	orden_caracter_cero = caracter_cero;  // Almacena 48
													  // o lo que es lo mismo: orden_caracter_cero = '0';

	cout << "\nEl orden del car�cter " << caracter_cero << " es: " << orden_caracter_cero;
	*/

	// El orden del car�cter 0 es 48
	// Internamente ambas variables orden_caracter_cero y caracter_cero contienen 48
	// Sin embargo, cout imprime un pantalla un car�cter o un entero dependiendo del tipo de dato de la variable

   /////////////////////////////////////////////////////////////////////////

	/*
	Queremos obtener el entero correspondiente a un car�cter que representa un d�gito num�rico:
	'7' --> 7
	'3' --> 3
	Sabemos que sumar(restar) dos caracteres suma(resta) los �rdenes correspondientes.
	As� pues:
	'7' - '3' es el entero resultante de hacer 55 - 51 = 4  (el resultado de restar dos char es un int)
	Lo mismo ocurre si hacemos lo siguiente:
	'7' - 51 es el entero 55 - 51 = 4

	'7' tiene un n�mero de orden en la tabla ASCII siete veces superior al orden del car�cter '0'.
	Por lo tanto:
	'7' - '0' es el entero 55 - 48 = 7

	Tambi�n podr�amos haber hecho lo siguiente:
	'7' - 48 que da como resultado el entero 55 - 48 = 7
	Sin embargo, este c�digo no es elegante.
	A un programador le resultar� dif�cil entender la expresi�n '7' - 48
	El entero 48 parece "un n�mero m�gico sacado de la manga"
	Mucho m�s intuitiva es la expresi�n '7' - '0'
	*/

   const char CARACTER_DIGITO_CERO = '0';
   char caracter;
   int caracter_a_entero;

   cout << "\nIntroduzca un car�cter num�rico  --> ";
   cin >> caracter;

   caracter_a_entero = caracter - CARACTER_DIGITO_CERO;

   cout << "\nEl entero correspondiente es " << caracter_a_entero;
   cout << "\n\n";
	system("pause");
}

