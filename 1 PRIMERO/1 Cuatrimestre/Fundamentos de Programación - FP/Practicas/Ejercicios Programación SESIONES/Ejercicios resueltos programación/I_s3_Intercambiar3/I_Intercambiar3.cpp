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
Programa que intercambia los valores de tres variables
Entradas: los tres valores (x, y, z) 
Salidas:  Los mismos datos, pero con los valores intercambiados 
y <-- x <-- z 
|___________^
*/
/*********************************************************************/

#include <iostream>
using namespace std;

int main()
{

   int x, y, z; // Datos de entrada y salida

   // Entrada
   cout << "Valor del primer dato: "; 
   cin >> x;
   cout << "Valor del segundo dato: "; 
   cin >> y;
   cout << "Valor del tercer dato: "; 
   cin >> z;

   /*	
   //	Primera forma (Orden de ejecuci�n de las asignaciones: de derecha a izda)
   //	 y <- x <- z <- y
   //            ------
   //       ------
   //  -------

   int copia_z, copia_x; 

   copia_z = z;
   z       = y;
   copia_x = x;
   x       = copia_z;
   y       = copia_x;
   */


   //	Segunda forma (Orden de ejecuci�n de las asignaciones: de izda a derecha)
   //	 y <- x <- z <- y
   //  -------
   //       -------
   //            -------

   int copia_y; 

   copia_y = y;
   y       = x;
   x       = z;
   z       = copia_y;

   // Mucho m�s f�cil de entender y generalizable a varias variables
   // Moraleja: No implementad la primera soluci�n que se nos ocurra.


   // Salida

   cout << "\nValor del primer dato:  " << x; 
   cout << "\nValor del segundo dato: " << y; 
   cout << "\nValor del tercer dato:  " << z;
   cout << "\n\n";

   system("pause");
}
