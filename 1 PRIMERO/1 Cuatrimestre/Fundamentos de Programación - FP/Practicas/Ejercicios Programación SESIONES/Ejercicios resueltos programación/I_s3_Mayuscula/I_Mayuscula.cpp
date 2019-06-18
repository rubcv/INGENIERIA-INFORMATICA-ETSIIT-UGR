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
   Pasar un car�cter de may�scula a min�scula.
*/

#include <iostream>
using namespace std;

int main(){
   /*
   Las may�sculas est�n antes que las min�sculas en la tabla ASCII.
   Adem�s, sabemos que hay el mismo n�mero de may�sculas que de
   min�sculas y obviamente se encuentran en el mismo orden. Por
   tanto, s�lo necesitamos saber cu�ntos caracteres hay entre
   'A' y 'a'.

   El orden de 'A' es 65 y el de 'a' 97.
   Por tanto, hay 97-65 = 32 caracteres entre ellos.
   As� pues, bastar�a hacer letra_minuscula = letra_mayuscula + 32

   Problema: Debo conocer el n�mero "m�gico" 32. 
	Muy posiblemente se me olvide cuando lo necesite en otro programa.	
	*/

	/*
	char letra_minuscula, letra_mayuscula;

   cout << "\nIntroduzca una letra may�scula  --> ";
   cin >> letra_mayuscula;

   letra_minuscula = letra_mayuscula + 32;      // :-(

   cout << "\nEl car�cter " << letra_mayuscula
        << " pasado a min�scula es: " << letra_minuscula;

	*/

	/*
	S�lo necesitamos saber cuantos caracteres hay entre 'A' y 'a'.
   Dicho valor me lo da la operaci�n 'a'-'A', que devuelve 32.
   Obviamente tambi�n valdr�a 'b'-'B' o 'c'-'C' ....

   Observad que este m�todo tambi�n funcionar�a si las may�sculas
   estuviesen despu�s de las min�sculas en la tabla ASCII
	*/

   char letra_minuscula, letra_mayuscula;
   const int DISTANCIA_MAY_MIN = 'a'-'A';             // :-)

   cout << "\nIntroduzca una letra may�scula  --> ";
   cin >> letra_mayuscula;

   letra_minuscula = letra_mayuscula + DISTANCIA_MAY_MIN;      // :-)

   cout << "\nEl car�cter " << letra_mayuscula
        << " pasado a min�scula es: " << letra_minuscula;

   cout << "\n\n";
	system("pause");
}
