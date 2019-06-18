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
    Escribid una expresi�n l�gica que sea verdadera si 
    una variable de tipo car�cter llamada letra 
    es una letra min�scula y falso en otro caso.
       
    Escribid una expresi�n l�gica que sea verdadera si 
    una variable de tipo entero llamada edad 
    es menor de 18 o mayor de 65.
    
    IMPORTANTE: Cuando se imprime por pantalla (con cout) una expresi�n
    l�gica que es true, se imprime 1. Si es false, se imprime un 0.
    En el tema 2 veremos la raz�n.
*/

#include <iostream>
using namespace std;

int main(){
   char letra;
   int edad, anio;
   bool es_minuscula, es_no_activo, es_bisiesto;
   
   cout << "\nIntroduzca una letra  --> ";
   cin >> letra;
   
   es_minuscula = (letra >= 'a') && (letra <= 'z');  // Usamos directamente los operadores 
                                                     // relacionales sobre los literales de tipo char
   
   cout << "\n" << es_minuscula << "\n";
   
   cout << "\nIntroduzca la edad  --> ";
   cin >> edad;   
   
   es_no_activo = (edad > 65) || (edad < 18);
   cout << "\n" << es_no_activo << "\n";

	cout << "\nIntroduzca un a�o --> ";
	cin >> anio;
	es_bisiesto = ( anio % 4 == 0  &&  anio % 100 != 0 )   ||  anio % 400 == 0 ;
	
	cout << "\n" << es_bisiesto << "\n";

   cout << "\n\n";
	system("pause");
}
