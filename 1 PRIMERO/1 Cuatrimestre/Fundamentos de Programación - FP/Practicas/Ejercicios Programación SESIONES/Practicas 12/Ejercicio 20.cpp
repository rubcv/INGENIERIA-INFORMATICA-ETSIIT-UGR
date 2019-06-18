#include <iostream>
#include <cctype>
using namespace std;

class SecuenciaEnteros{
	private:
		static const int TAMANIO = 50;
		int vector_privado[TAMANIO];
		int total_utilizados;
	public:
		SecuenciaEnteros()
			:total_utilizados(0){
		}
		
		int TotalUtilizados(){
			return total_utilizados;
		}
		
		int Capacidad(){
			return TAMANIO;
		}
		
		void Aniade(int nuevo){
			if (total_utilizados < TAMANIO){
				vector_privado[total_utilizados] = nuevo;
				total_utilizados++;
			}
		}
		
		int Elemento(int indice){
			return vector_privado[indice];
		}
		
		void Elimina (int posicion){
			if (posicion >= 0 && posicion < total_utilizados){
				int tope = total_utilizados-1;
				for (int i = posicion ; i < tope ; i++){
					vector_privado[i] = vector_privado[i+1];
				}
				total_utilizados--;
			}
		}
		string ToString(){
			string cadena;
			for (int i=0; i<total_utilizados; i++){
				char numero=vector_privado[i];
				cadena = cadena + numero;
			}
			return cadena;
		}
		
		void EliminaRepetidos(){
			for(int i=0; i<total_utilizados; i++){
				for(int j=i+1; j<total_utilizados; j++){
					if(vector_privado[i]==vector_privado[j]){
						Elimina(j);
						j--;
					}
				}
			}
		}
		
		int SecuenciasAscendentes(){
			
			int secuencias=0;
			
			for(int i=0; i<total_utilizados; i++){
				if(vector_privado[i]<=i-1){
					
					secuencias++;
			
			}
		}
			return secuencias;
		}
};


int main (){
	char caracter;
	int contador =0;
	SecuenciaEnteros secuencia=SecuenciaEnteros();

	do{
		cout<<"Secuencia caracteres: "<<endl;
		caracter=cin.get();
		secuencia.Aniade(caracter);
		contador++;
		cin.get();
	}while( caracter != '.' && contador<=50);
	
	cout<<endl<<"Numero de secuencias ascendentes: " <<secuencia.SecuenciasAscendentes();

system("pause");
return 0;
}
