#include <iostream>

using namespace std;

int main(){
	const int TAM = 100;
	char caracteres[TAM], auxiliar[TAM];
	char caracter;
	int contador = 0, total_utilizados, mayusculas = 0;
	bool palindromo = true;
	
	cout << "Introduce un caracter (# para salir): " << endl;
	caracter = cin.get();
	
	while(caracter != '#'){
		caracteres[contador] = caracter;
		cin.get();
		contador++;
		cout << "Introduce un caracter (# para salir): " << endl;
		caracter = cin.get();
	}

	total_utilizados = contador;
	contador--;
	
	for(int i = 0; i <= total_utilizados/2; i++){
		if(caracteres[i] != caracteres[contador-i])
			palindromo = false;
	}
	
	if(palindromo)
		cout << "\nLos datos introducidos forman un palindromo" << endl;
	else
		cout << "\nLos datos introducidos no forman un palindromo" << endl;

	for(int i = 0; i <= total_utilizados; i++){
		auxiliar[i]=caracteres[contador-i];
	}
	
	cout << endl << "Del Derecho: " << caracteres << endl;
	cout << endl << "Del Reves: " << auxiliar << endl;
	
	for(int i = 0; i <= total_utilizados; i++){
		if(caracteres[i] >= 'A' && caracteres[i] <= 'Z')
			mayusculas++;
	}
	
	cout << endl << "Se han introducido " << mayusculas << " mayusculas" << endl;

	system("pause");
	return 0;
}
