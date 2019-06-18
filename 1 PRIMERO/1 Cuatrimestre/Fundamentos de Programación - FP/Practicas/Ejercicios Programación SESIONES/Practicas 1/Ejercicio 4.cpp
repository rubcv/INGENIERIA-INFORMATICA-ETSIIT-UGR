#include <iostream>

 using namespace std;
int main () {
	
	double yarda, pulgada, pies, millas, millas_marinas;
	
	cout << "Introduzca una longitud cualquiera dada en yarda(s)\n";
	cin >> yarda;
	pulgada= yarda*36;
	pies= yarda*3;
	millas= yarda*0.000568182;
	millas_marinas= yarda*0.000493737;
	
	cout<< "\nLa conversión en pulgadas equivale a: "<<pulgada;
	cout<< "\nLa conversión a pies equivale a: " <<pies;
	cout<< "\nLa conversión en millas equivale a: " <<millas;
	cout<< "\nLa conversión a millas marinas equivale a: " <<millas_marinas;

return 0;	
}
