/*	2. Construya la funci�n con cabecera:
string Digitos (int n)
para que extraiga en un string los d�gitos del n�mero n tal y como se indica en el
ejercicio 27 de la relaci�n de problemas II.*/



#include <iostream>
using namespace std;

string digitos(int numero){
	int cifra;
			int numerof=numero;
	while (numerof>0){
		 cifra=numerof%10;
		numerof=numerof/10;
		cout<<"   "<<cifra<<"   ";
	}

	return 0;
}


int main (){
	int numero;
	
	cout<<"Introduce un numero cuaquiera: "<<endl;
	cin>>numero;
	
 digitos(numero);

system ("pause");
return 0;
}
