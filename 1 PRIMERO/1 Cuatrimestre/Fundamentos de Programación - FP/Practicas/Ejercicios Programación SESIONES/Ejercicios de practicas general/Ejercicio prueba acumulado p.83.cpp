// Ejemplo de Bucle for y variable "acumulado"

// Ejercicio del libro de c++, p.83


#include <iostream>
#include <cmath>

using namespace std;

int main (){

double valor;
double acumulado;
int i,n;

for (i=0;i<100;i++)	{
		acumulado=0;
	for (n=0;n<=i;n++) {
		valor= 1.0/( (2*n+1)*(2*n+1)*(2*n+1));
		acumulado+= (n%2==0) ?valor:-valor;
	}
	acumulado*=32;
	cout<<"Valor con "<<i<<"sumandos: "<<pow(acumulado,1.0/3)<<endl;
}
	
	system("pause");
	return 0;
	
}
