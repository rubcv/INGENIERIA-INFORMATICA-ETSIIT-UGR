/* Un número entero n se dice que es desgarrable (torn) si al dividirlo en dos partes
cualesquiera izda y dcha, el cuadrado de la suma de ambas partes es igual a n.
Por ejemplo, 88209 es desgarrable ya que (88 + 209)2 = 88209; 81 también lo es
ya que 81 = (8 + 1)2. Cread un programa que lea un entero n e indique si es o no
desgarrable. */


#include <iostream>
#include <cmath>

using namespace std;


int desgarrable(int num_a,int num_b){
	return pow((num_a+num_b),2);
}

int exponencial(int num, int exponente){
	return pow(num,exponente);
}

//__

int main(){

	int numero_introducido, aux, contador=0, divisor=1, cifra_izq, cifra_der, total;
	string texto= "";

	do{
		cout<<"Introduce un numero entero positivo: ";
		cin>> numero_introducido;
	}while (numero_introducido<0);
	
	
	do{
		divisor*=10;
		aux=numero_introducido/divisor;
		contador++;
	}while(aux!=0);
	
	
	if(contador%2 == 0){
		cifra_izq=cifra_der=contador/2;
	}else{
		cifra_izq= contador/2;
		cifra_der=(contador/2)+1;
	}
	
	cifra_izq=numero_introducido/exponencial(10, cifra_der);
	cifra_der= abs(numero_introducido -(cifra_izq * exponencial(10,cifra_der)));
	
	
	total= exponencial(cifra_izq+cifra_der, 2);
	
	if(total == numero_introducido){
		texto = "El numero es desgarrable ";
	}else{
		texto = "El numero no es desgarrable ";
	}
	
	
	cout<<endl<<texto<<endl;
	
	
	system ("pause");
	return 0;
	
	
}

