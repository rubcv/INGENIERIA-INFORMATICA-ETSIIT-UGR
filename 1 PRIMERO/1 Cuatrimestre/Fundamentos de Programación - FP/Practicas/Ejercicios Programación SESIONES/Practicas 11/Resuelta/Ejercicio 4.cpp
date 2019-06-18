#include <iostream>

using namespace std;

class SecuenciaCaracteres{
	private:
		static const int TAM = 100;
		char caracteres[TAM];
		char auxiliar [TAM];
		int contador = 0;
		SetAuxiliar(){
			int tamanho = contador, posiciones = contador-1;
			for(int i = 0; i <= tamanho; i++){
				auxiliar[i]=caracteres[posiciones-i];
			}
		}
	public:
		//Prec: caracter != #
		void SetCaracter(char caracter){
			if(contador <= TAM){
				if(caracter != '#'){
					caracteres[contador] = caracter;
					contador++;
				}
			}
		}
		bool EsPalindromo(){
			bool palindromo = true;
			int tamanho = contador;
			for(int i = 0; i <= tamanho/2; i++){
				if(caracteres[i] != caracteres[tamanho-i-1])
					palindromo = false;
			}
			return palindromo;
		}
		string Invierte(){
			int tamanho = contador, posiciones = contador-1;
			for(int i = 0; i <= tamanho; i++){
				auxiliar[i]=caracteres[posiciones-i];
			}
			return ToString(auxiliar);
		}
		string Correcto(){
			return ToString(caracteres);
		}
		int NumeroMayusculas(){
			int tamanho = contador;
			int mayusculas = 0;
			for(int i = 0; i <= tamanho/2; i++){
				if(caracteres[i] >= 'A' && caracteres[i] <= 'Z')
					mayusculas++;
			}
			return mayusculas;
		}
		string ToString(char arrayCaracteres[]){
			string cadena(arrayCaracteres);
			return "{"+cadena+"}";
		}
};

int main(){
	SecuenciaCaracteres caracteres;
	char caracter;
	
	cout << "Introduce un caracter (# para salir): " << endl;
	caracter = cin.get();
	
	while(caracter != '#'){
		caracteres.SetCaracter(caracter);
		cin.get();
		cout << "Introduce un caracter (# para salir): " << endl;
		caracter = cin.get();
	}
	
	if(caracteres.EsPalindromo())
		cout << "\nLos datos introducidos forman un palindromo" << endl;
	else
		cout << "\nLos datos introducidos no forman un palindromo" << endl;
		
	cout << endl << "Del Derecho: " << caracteres.Correcto() << endl;
	cout << endl << "Del Reves: " << caracteres.Invierte() << endl;
	
	cout << endl << "Se han introducido " << caracteres.NumeroMayusculas() << " mayusculas" << endl;
	
	system("pause");
	return 0;
}
