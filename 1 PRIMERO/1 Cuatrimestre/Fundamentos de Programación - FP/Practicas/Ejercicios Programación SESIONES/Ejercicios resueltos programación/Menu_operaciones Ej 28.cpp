///////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Autor: Sylvia Acid y Juan Carlos Cubero
//
///////////////////////////////////////////////////////



/* UTILIZANDO FUNCIONES
Escribir un programa que lea dos números enteros, escriba en pantalla el menú que
se muestra a continuación, lea la opción seleccionada y muestre el resultado de la
operación indicada.
----------------
I. Introducir números
S. Suma
P. Producto
M. Máximo
R. SaliR
----------------
Introduzca opción:
Observe que se permite realizar distintas operaciones (opciones S,P,M) con los mis-
mos valores numéricos (los introducidos en la opción I)
*/

#include <iostream>
#include <cctype>
using namespace std;


/* Muestra el menu y la entrada de la opcion */
void mostrarMenu(){
	   cout << 
      "\nI. Introducir números \nS. Suma \nP. Producto\nM. Máximo\nR. SaliR\n\nIntroduzca la opción elegida: ";
}
/* Filtro de entrada I,P,S,R */
char leeOpcion(){
  char caracter;
   do{
	 cin >> caracter;
         caracter = toupper(caracter);
   }while(caracter !='S' && caracter !='P' && caracter !='I' && caracter !='R');
   return caracter;
}
double leeNumero(){
	double n;
	cin >> n;
	return n;
}
double suma(double num1, double num2){
	return (num1+num2);
}
double producto(double num1, double num2){
	return (num1*num2);
}
double max( double num1, double num2){
	double maximo = num1;
	if (num2 > num1)
	    maximo = num2;
	return maximo;
}

int main(){
   double dato1, dato2, resultado;
   char opcion_caracter;

   const char FIN = 'R';
   const string TEXTO_INTRO_VALORES = "\nIntroduzca dos valores enteros\n";
   
   const string TEXTO_RESULTADO = "\nResultado de la operación: ";
   const string TEXTO_DATOS_NO_INTRODUCIDOS = "\nPrimero debe introducir datos\n";
   
 /* considera el caso de que no hay datos */
   
   bool datos_introducidos=false;
   
   do{
   	mostrarMenu();
   	opcion_caracter = leeOpcion();
      
     if (opcion_caracter == 'I'){
            datos_introducidos = true;
	    cout << TEXTO_INTRO_VALORES;
            dato1 = leeNumero();
	    cout << TEXTO_INTRO_VALORES;
            dato2 = leeNumero();   
         }
     else if ((opcion_caracter == 'P') || (opcion_caracter == 'S') ||   (opcion_caracter == 'M'))
             if (!datos_introducidos )
	              cout << TEXTO_DATOS_NO_INTRODUCIDOS;
	          else { // else 1
		  	if (opcion_caracter == 'P')
		      		resultado = producto(dato1,dato2);
		  	else if (opcion_caracter == 'S')
				resultado = suma(dato1,dato2);
			     else if (opcion_caracter == 'M')
            	      			resultado = max(dato1,dato2);
		        cout << TEXTO_RESULTADO << resultado << endl;
	     	  }//else 1
            	            		
   }while(opcion_caracter != FIN);   
   cout  << endl;
}
 
