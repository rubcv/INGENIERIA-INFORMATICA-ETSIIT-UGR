#include <iostream>
#include <math.h>
using namespace std;


double leeEnteroPositivo(double numero){
	cin >> numero;
	while(numero<0){
		cout << "El numero tiene que ser positivo: ";
		cin >> numero;
	}
	return numero;
}


double sumaHasta(double numero, double constante, double veces){
	double suma=numero, siguiente;
	for(int i=1; i < veces; i++){
			siguiente=numero*constante;
			suma+=siguiente;
			numero=siguiente;
		}
	return suma;
}

double productoHasta(double numero, double constante, int veces){
	return sqrt(pow((numero*numero*pow(constante,veces-1)),veces));
}

int main(){
	
	double numero, constante, suma, multi;
	int veces;
	
	cout << "Escribe a1: ";
	cin >> numero;
	cout << "Escribe la constante de la progresion: ";
	cin >> constante;
	cout << "Escribe las veces que quieres calcular numeros de la progresion: ";
	veces=leeEnteroPositivo(numero);

	suma=sumaHasta(numero, constante, veces);
	multi=productoHasta(numero, constante, veces);
	
	cout << "La suma de los numeros de la progresion es: " << suma<<endl;
	cout << "El producto de los numeros de la progresion es: " << multi<<endl<<endl;
	
	system("pause");
}
