// Numeros primos menores que uno dado


// 			FOR, bool



//Que recorra todos los valores desde el 2 hasta el num de entrada

#include <iostream>
#include<cmath>
using namespace std;
int main (){
	
int n;
int numero, raiz, i;
bool esprimo;

cout<< "Introduce un numero: ";
cin>> n;

for (numero=2; numero<=n; numero++)
{
	raiz=sqrt(numero); //Vemos si es primo
	esprimo=true;
	
	for (i=2; i<=raiz; i++)
		if (numero%i==0)	//Es divisible
			esprimo= false;
			
	if (esprimo) cout<<numero<<endl;

}

	
	system ("pause");
	return 0;
}
