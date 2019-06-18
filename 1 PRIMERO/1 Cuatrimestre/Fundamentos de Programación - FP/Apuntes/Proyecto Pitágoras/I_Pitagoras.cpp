/* Programa para calcular la hipotenusa de un triángulo.
   Implementa el algoritmo de Pitágoras
   Necesita: los catetos de un triángulo rectángulo
                lado1, lado2.
   Calcula:  La hipotenusa, calculada como
                hip = RaizCuad(lado1^2 + lado2^2)
*/

#include <iostream>   // Inclusión de los recursos de E/S
#include <cmath>      // Inclusión de los recursos matemáticos

using namespace std; 

int main(){                    // Programa Principal
   double lado1;               // Declara variables para guardar
   double lado2;               // los dos lados y la hipotenusa
   double hip;   

   cout << "Introduzca la longitud del primer cateto: " ;
   cin >> lado1;
   cout << "Introduzca la longitud del segundo cateto: ";
   cin >> lado2;

   hip = sqrt(lado1*lado1 + lado2*lado2);

   cout << "\nLa hipotenusa vale " << hip << "\n\n" ;
}
