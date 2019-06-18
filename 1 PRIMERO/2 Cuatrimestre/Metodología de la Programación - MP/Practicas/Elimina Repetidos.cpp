#include <iostream>
using namespace std;

const int TAM = 50;

void EliminaRepetidos(int v[TAM], int util){
/* Con el vector y el auxiliar, coje cada elemento uno por uno de v1 y lo pasa a v2, cada vez que lo coje y lo mete lo compara con todo v2
Si está no lo guarda y pasa al siguiente, si no está lo mete. El tamaño del segundo bucle se va adaptando a los elementos que tienes en v2, 
con un contador que se incrementa cada vez que no está el elemento en la vuelta.
Si no está el elemento, se copia en v2 de la última posicion, la que estás (NoRepetidos) la posición de i que es el elemento que has elegido para comparar
*/
	bool Esta = false; // Booleana para que si lo encuentra en el segundo vector corte la búsqueda
	int NoRepetidos = 0; // Contador
	int v2[util]; //Vector donde se va guardando cada elemento 
	
	for(int i = 0; i < util; i++){
		for(int j = 0; j < NoRepetidos && !Esta; j++){
			if(v[i] == v2[j]){
				Esta = true;
			}
		}
		
		if(!Esta){ //Si no está, v2 del ultimo elemento (NoRepetidos(que va de 0 hasta total de no repetidos)) toma el valor de i
			v2[NoRepetidos] = v[i];
			NoRepetidos++; //Se incrementa el contador y el tamaño de búsqueda del segundo for
		}
	}
		Esta = false; //Se pone a false para que pueda volver a entrar al segundo bucle y dar otra vuelta
}

void MostrarVector(int v[TAM], int util){
	for(int i = 0; i < util; i++){
		cout<< v[i] << " ";
	}
}


int main(){
int v[TAM];
int elemento, util, i = 0; 

cout<<"Este programa elimina repetidos, inserte los elementos del vector (-1 para salir)"<<endl;

do{
		cin>> elemento;
		v[i] = elemento;
		util = i;
		i++;
	}while(elemento != -1 && i < TAM);
	
	EliminaRepetidos(v, util);

	MostrarVector(v, util);
}
