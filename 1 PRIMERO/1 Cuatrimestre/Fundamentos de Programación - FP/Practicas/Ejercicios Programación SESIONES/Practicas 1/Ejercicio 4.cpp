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
	
	cout<< "\nLa conversi�n en pulgadas equivale a: "<<pulgada;
	cout<< "\nLa conversi�n a pies equivale a: " <<pies;
	cout<< "\nLa conversi�n en millas equivale a: " <<millas;
	cout<< "\nLa conversi�n a millas marinas equivale a: " <<millas_marinas;

return 0;	
}
