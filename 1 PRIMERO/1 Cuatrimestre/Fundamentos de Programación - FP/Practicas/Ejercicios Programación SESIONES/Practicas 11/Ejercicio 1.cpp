/*Tenga en cuenta la observaci�n al inicio de esta relaci�n de problemas sobre la lectura
de los caracteres. Para poder leer caracteres, incluyendo los espacios en blanco, hay
que usar caracter = cin.get(), en vez de cin >> caracter.
En este ejercicio trabajaremos con un vector directamente en el main, sin utilizar
clases.
Declare un vector de caracteres de tama�o 100. Lea las componentes considerando
como terminador el car�cter # (�ste no forma parte de la secuencia) y que no se
introduzcan m�s de 100 caracteres. Las componentes le�das ocupar�n las primeras
posiciones contiguas del vector. El resto de las posiciones se quedar�n con el valor
indeterminado (basura) que el compilador le asignase al principio. Para conocer cu�ntas
componentes se est�n utilizando, utilice una variable total_utilizados (que,
obviamente, deber� ser menor de 100 en todo momento)
Implemente algoritmos para realizar las siguientes tareas:

a) Comprobar si el vector es un pal�ndromo, es decir, que se lee igual de izquierda a
derecha que de derecha a izquierda. Por ejemplo, {'a','b','b','a'} ser�a
un pal�ndromo, pero {'a','c','b','a'} no lo ser�a. Si la secuencia tiene un
n�mero impar de componentes, la que ocupa la posici�n central es descartada,
por lo que {'a','b','j','b','a'} ser�a un pal�ndromo.

b) Invertir el vector. Si �ste conten�a, por ejemplo, los caracteres
{'m','u','n','d','o'}, despu�s de llamar al m�todo se quedar� con
{'o','d','n','u','m'}.

c) Contar el n�mero de may�sculas que contiene. */


#include <iostream>
using namespace std;


 
 /* int es_palindromo(char cadena){

 
 
 
 } */


// Primero todo en el main

int main(){
	char cadena;
	cout<<"Este programa lee una serie de caracteres y comprueba si son un pal�ndromo "<<endl;
	
do{
	cin>> cadena;


}while(cadena!='#');


 		int cadenad;
 		int cadenai;
 		
 			cadenad=cadena;
 		while(cadenai<cadenad){
			cadenai=cadenad%10;
				cadenad=cadenad/10;		 
		 }
 	/*
 		if (cadenad=cadenai)
		 	cout<<"Es palindromo "<<endl;
		 else
		 	cout<<"No es palindromo "<<endl;
		 
 */
cout<<cadenai<<endl;
cout<<cadenad<<endl;




system ("pause");
return 0;
}
