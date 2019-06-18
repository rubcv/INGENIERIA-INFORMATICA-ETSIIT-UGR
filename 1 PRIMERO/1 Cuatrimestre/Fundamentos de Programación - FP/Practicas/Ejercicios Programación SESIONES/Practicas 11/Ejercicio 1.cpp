/*Tenga en cuenta la observación al inicio de esta relación de problemas sobre la lectura
de los caracteres. Para poder leer caracteres, incluyendo los espacios en blanco, hay
que usar caracter = cin.get(), en vez de cin >> caracter.
En este ejercicio trabajaremos con un vector directamente en el main, sin utilizar
clases.
Declare un vector de caracteres de tamaño 100. Lea las componentes considerando
como terminador el carácter # (éste no forma parte de la secuencia) y que no se
introduzcan más de 100 caracteres. Las componentes leídas ocuparán las primeras
posiciones contiguas del vector. El resto de las posiciones se quedarán con el valor
indeterminado (basura) que el compilador le asignase al principio. Para conocer cuántas
componentes se están utilizando, utilice una variable total_utilizados (que,
obviamente, deberá ser menor de 100 en todo momento)
Implemente algoritmos para realizar las siguientes tareas:

a) Comprobar si el vector es un palíndromo, es decir, que se lee igual de izquierda a
derecha que de derecha a izquierda. Por ejemplo, {'a','b','b','a'} sería
un palíndromo, pero {'a','c','b','a'} no lo sería. Si la secuencia tiene un
número impar de componentes, la que ocupa la posición central es descartada,
por lo que {'a','b','j','b','a'} sería un palíndromo.

b) Invertir el vector. Si éste contenía, por ejemplo, los caracteres
{'m','u','n','d','o'}, después de llamar al método se quedará con
{'o','d','n','u','m'}.

c) Contar el número de mayúsculas que contiene. */


#include <iostream>
using namespace std;


 
 /* int es_palindromo(char cadena){

 
 
 
 } */


// Primero todo en el main

int main(){
	char cadena;
	cout<<"Este programa lee una serie de caracteres y comprueba si son un palíndromo "<<endl;
	
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
