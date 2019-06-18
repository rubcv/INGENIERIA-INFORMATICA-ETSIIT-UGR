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
   Pasar un carácter de mayúscula a minúscula.
*/

#include <iostream>
using namespace std;

int main(){
   /*
   Las mayúsculas están antes que las minúsculas en la tabla ASCII.
   Además, sabemos que hay el mismo número de mayúsculas que de
   minúsculas y obviamente se encuentran en el mismo orden. Por
   tanto, sólo necesitamos saber cuántos caracteres hay entre
   'A' y 'a'.

   El orden de 'A' es 65 y el de 'a' 97.
   Por tanto, hay 97-65 = 32 caracteres entre ellos.
   Así pues, bastaría hacer letra_minuscula = letra_mayuscula + 32

   Problema: Debo conocer el número "mágico" 32. 
	Muy posiblemente se me olvide cuando lo necesite en otro programa.	
	*/

	/*
	char letra_minuscula, letra_mayuscula;

   cout << "\nIntroduzca una letra mayúscula  --> ";
   cin >> letra_mayuscula;

   letra_minuscula = letra_mayuscula + 32;      // :-(

   cout << "\nEl carácter " << letra_mayuscula
        << " pasado a minúscula es: " << letra_minuscula;

	*/

	/*
	Sólo necesitamos saber cuantos caracteres hay entre 'A' y 'a'.
   Dicho valor me lo da la operación 'a'-'A', que devuelve 32.
   Obviamente también valdría 'b'-'B' o 'c'-'C' ....

   Observad que este método también funcionaría si las mayúsculas
   estuviesen después de las minúsculas en la tabla ASCII
	*/

   char letra_minuscula, letra_mayuscula;
   const int DISTANCIA_MAY_MIN = 'a'-'A';             // :-)

   cout << "\nIntroduzca una letra mayúscula  --> ";
   cin >> letra_mayuscula;

   letra_minuscula = letra_mayuscula + DISTANCIA_MAY_MIN;      // :-)

   cout << "\nEl carácter " << letra_mayuscula
        << " pasado a minúscula es: " << letra_minuscula;

   cout << "\n\n";
	system("pause");
}
