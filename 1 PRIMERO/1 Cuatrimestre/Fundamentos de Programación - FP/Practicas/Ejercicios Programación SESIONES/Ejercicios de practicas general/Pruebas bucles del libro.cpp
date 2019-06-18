/* Escribir un programa que ofrezca un menu con tres opciones,
solicita una y escribe la opcion hasta poner la 3 de finalizacion */

//							DO WHILE   (Switch Case)

#include <iostream>
using namespace std;
int main () {
	
	int opcion;
	
	do {
		cin>> opcion;
		switch (opcion) {
				case 1:
					cout<< "Opcion 1"<<endl;
					break;
				case 2:
					cout<< "Opcion 2"<<endl;
					break;
				case 3:
					cout<< "Fin"<<endl;
					break;
				default:
					cout<<"Solo 1-3"<<endl;
		}
	}while (opcion!=3);
	
	system ("pause");
	return 0;
}
