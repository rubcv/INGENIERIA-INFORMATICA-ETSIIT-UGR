///////////////////////////////////////////////////////
//
// Fundamentos de Programaci�n
// ETS Inform�tica y Telecomunicaciones
// Universidad de Granada
// Autor: Juan Carlos Cubero
//
///////////////////////////////////////////////////////

// Horas, minutos, segundos

/*
	Leed desde teclado tres variables correspondientes a un n�mero de horas, minutos
	y segundos, respectivamente. Dise�ar un algoritmo que calcule las horas, minutos
	y segundos dentro de su rango correspondiente. Por ejemplo, dadas 10 horas, 119
	minutos y 280 segundos, deber�a dar como resultado 12 horas, 3 minutos y 40 se-
	gundos. En el caso de que nos salgan m�s de 24 horas, daremos tambi�n los d�as
	correspondientes (pero ya no pasamos a ver los meses, a�os, etc)
	Como consejo, utilizad el operador / que cuando trabaja sobre datos enteros, repre-
	senta la divisi�n entera. Para calcular el resto de la divisi�n entera, usad el operador %.
*/
/*
   450 seg, 700 minutos, 43h -->  30 segundos, 47 minutos, 6 horas, 2 d�as.
   Nos quedaremos en los d�as. Es decir, si aparecen m�s de 365 d�as, lo dejaremos tal cual,
   sin pasarlo a a�os.
*/

#include <iostream>
using namespace std;

int main(){
   int segundos_enteros, minutos_enteros, horas_enteras, dias_enteros;  // <- No usad nombres como aux1, aux2, aux3 !!
   int minutos_totales, horas_totales, dias_totales;
   int segundos, minutos, horas, dias;
   const int SEGUNDOS_POR_MINUTO = 60, MINUTOS_POR_HORA = 60, HORAS_POR_DIA = 24;
   
   cout << "\nIntroduzca segundos --> ";
   cin >> segundos;
   cout << "\nIntroduzca minutos --> ";
   cin >> minutos;
   cout << "\nIntroduzca horas --> ";
   cin >> horas;

   /////////////////////////////////////////////////////////////////////
   /* 
   La siguiente soluci�n repite muchos c�mputos.
   
   segundos_enteros  = segundos % 60;
   minutos_enteros	= (segundos / 60 + minutos) % 60;
   horas_enteras		= ((segundos / 60 + minutos) / 60 + horas ) % 24;
   dias_enteros		= ((segundos / 60 + minutos) / 60 + horas ) / 24;
   
   Repetir c�digo tiene los siguientes problemas:
   
   1. Es ineficiente pues se pierde tiempo en evaluar expresiones repetidas
   
   2. Mucho peor: Es propenso a errores ya que hay que teclear varias veces
   una misma expresi�n y debe ser igual siempre
   
   3. Es dif�cil de modificar ya que cada cambio habr� que hacerlo
   en cada una de las expresiones repetidas.
	*/

   /////////////////////////////////////////////////////////////////////
   
	/* 
   El siguiente c�digo no repite c�mputos pero estamos modificando las variables originales
   segundos, minutos, horas lo cual no es recomendable.
	*/

	/*
   segundos_enteros  = segundos % 60;

   minutos				= segundos / 60 + minutos;
   minutos_enteros   = minutos % 60;

   horas					= minutos / 60 + horas;
   horas_enteras     = horas % 24;

   dias_totales      = horas / 24;
   */

   /////////////////////////////////////////////////////////////////////

   /*
   El siguiente algoritmo no repite c�digo. 
	Hemos usado tres variables adicionales con los totales de los minutos, horas, etc. 
	
		Calculad los minutos totales como los minutos introducidos m�s los que hay en los segundos introducidos.
		Haced lo mismo con las horas (usad los minutos totales) y los d�as (usad las horas totales)
		Calculad los segundos, minutos y horas enteras que hay en los totales anteriores.
		
		450 seg -> 7 minutos  y 30 segundos
		700 min -> 700 + 7 = 707 -> 11 horas y 47 minutos
		43 h    -> 43 + 11 = 54  -> 2 d�as   y 6 horas		
   */

   minutos_totales  = segundos / SEGUNDOS_POR_MINUTO  +  minutos;
   horas_totales    = minutos_totales / MINUTOS_POR_HORA  +  horas;
   dias_totales     = horas_totales / HORAS_POR_DIA;  // + dias en su caso  

	segundos_enteros = segundos % SEGUNDOS_POR_MINUTO;
   minutos_enteros  = minutos_totales % MINUTOS_POR_HORA;
   horas_enteras    = horas_totales % HORAS_POR_DIA;  		

   cout << "\nSegundos enteros: " << segundos_enteros;
   cout << "\nMinutos enteros:  " << minutos_enteros;
   cout << "\nHoras enteras:    " << horas_enteras;
   cout << "\nD�as restantes:   " << dias_totales;
   
   
   /*
   Observad que las variables totales podr�an sustituirse
   por las propias variables enteras, ya que su valor se modifica al principio,
   se usa para calcular las divisiones enteras y no se vuelve a usar hasta 
   asignarles el valor definitivo.
   Por tanto, el anterior c�digo podr�a quedar como aparece abajo.
   En cualquier caso, puede que sea m�s dif�cil de entender, por lo que
   ser�a recomendable seguir usando las variables totales.
	*/

	/*
   minutos_enteros  = segundos / 60 + minutos;
   horas_enteras    = minutos_enteros / 60 + horas;
   dias_enteros     = horas_enteras / 24;  // + dias en su caso

	segundos_enteros = segundos % 60;
   minutos_enteros  = minutos_enteros % 60;
   horas_enteras    = horas_enteras % 24;   
	*/


   /*
   ***********************************************************************************
   ***********************************************************************************
   Recomendaciones:

   - El uso de variables intermedias ayuda a realizar las operaciones intermedias, 
	  facilitando la comprensi�n del c�digo

   - No debemos modificar los valores de las variables importantes de nuestro programa,
	  ya que posiblemente se usen en varios sitios y querremos recuperar el valor original.

   ***********************************************************************************
   ***********************************************************************************
   */


   cout << "\n\n";
   system("pause");
}
