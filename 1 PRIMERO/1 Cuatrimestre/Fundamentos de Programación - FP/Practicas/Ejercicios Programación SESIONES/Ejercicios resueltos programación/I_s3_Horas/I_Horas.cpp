///////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Juan Carlos Cubero
//
///////////////////////////////////////////////////////

// Horas, minutos, segundos

/*
	Leed desde teclado tres variables correspondientes a un número de horas, minutos
	y segundos, respectivamente. Diseñar un algoritmo que calcule las horas, minutos
	y segundos dentro de su rango correspondiente. Por ejemplo, dadas 10 horas, 119
	minutos y 280 segundos, debería dar como resultado 12 horas, 3 minutos y 40 se-
	gundos. En el caso de que nos salgan más de 24 horas, daremos también los días
	correspondientes (pero ya no pasamos a ver los meses, años, etc)
	Como consejo, utilizad el operador / que cuando trabaja sobre datos enteros, repre-
	senta la división entera. Para calcular el resto de la división entera, usad el operador %.
*/
/*
   450 seg, 700 minutos, 43h -->  30 segundos, 47 minutos, 6 horas, 2 días.
   Nos quedaremos en los días. Es decir, si aparecen más de 365 días, lo dejaremos tal cual,
   sin pasarlo a años.
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
   La siguiente solución repite muchos cómputos.
   
   segundos_enteros  = segundos % 60;
   minutos_enteros	= (segundos / 60 + minutos) % 60;
   horas_enteras		= ((segundos / 60 + minutos) / 60 + horas ) % 24;
   dias_enteros		= ((segundos / 60 + minutos) / 60 + horas ) / 24;
   
   Repetir código tiene los siguientes problemas:
   
   1. Es ineficiente pues se pierde tiempo en evaluar expresiones repetidas
   
   2. Mucho peor: Es propenso a errores ya que hay que teclear varias veces
   una misma expresión y debe ser igual siempre
   
   3. Es difícil de modificar ya que cada cambio habrá que hacerlo
   en cada una de las expresiones repetidas.
	*/

   /////////////////////////////////////////////////////////////////////
   
	/* 
   El siguiente código no repite cómputos pero estamos modificando las variables originales
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
   El siguiente algoritmo no repite código. 
	Hemos usado tres variables adicionales con los totales de los minutos, horas, etc. 
	
		Calculad los minutos totales como los minutos introducidos más los que hay en los segundos introducidos.
		Haced lo mismo con las horas (usad los minutos totales) y los días (usad las horas totales)
		Calculad los segundos, minutos y horas enteras que hay en los totales anteriores.
		
		450 seg -> 7 minutos  y 30 segundos
		700 min -> 700 + 7 = 707 -> 11 horas y 47 minutos
		43 h    -> 43 + 11 = 54  -> 2 días   y 6 horas		
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
   cout << "\nDías restantes:   " << dias_totales;
   
   
   /*
   Observad que las variables totales podrían sustituirse
   por las propias variables enteras, ya que su valor se modifica al principio,
   se usa para calcular las divisiones enteras y no se vuelve a usar hasta 
   asignarles el valor definitivo.
   Por tanto, el anterior código podría quedar como aparece abajo.
   En cualquier caso, puede que sea más difícil de entender, por lo que
   sería recomendable seguir usando las variables totales.
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
	  facilitando la comprensión del código

   - No debemos modificar los valores de las variables importantes de nuestro programa,
	  ya que posiblemente se usen en varios sitios y querremos recuperar el valor original.

   ***********************************************************************************
   ***********************************************************************************
   */


   cout << "\n\n";
   system("pause");
}
