// Dados dos vectores de numeros ordenados, devuelve un tercero con los dos anteriores ordenados consecutivamente

#include <iostream>
using namespace std;

//De la clase Vector

Vector MezclarOrdenadamente(Vector otro){
	
	Vector resultado; // 1º Crea vector resultado

	resultado.util = util + otro.util; // 2º Util final = util de v1 + util de v2
	
	resultado.v = new float[resultado.util]; // 3º Espacio para resultado = el util total

	int i = 0, j = 0;
	for(int k = 0; k < resultado.util; k++){
		if(i >= util || j < otro.util && v[i] > otro.v[j]){
			resultado.v[k] = otro.v[j];
			j++;
		}else{
			resultado.v[k] = v[i];
			i++;		
		
		}
	}
}

// CONDICIONES DEL IF

// i >= util -> Si i > util, si le queda vector por copiar

// j < otro.util -> Si j < util de v2, para que no se salga del vector

// v[i] > otro.v[j] -> Si se sigue el orden, si j es menor entra en el if y copia v[j]







int main(){}
