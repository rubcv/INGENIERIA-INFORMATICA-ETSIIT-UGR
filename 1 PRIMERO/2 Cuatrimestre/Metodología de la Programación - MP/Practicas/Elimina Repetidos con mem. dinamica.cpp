// ELIMINA REPETIDOS CON MEMORIA DINAMICA

//Hecho de clases, forma correcta en otro ejercicio
#include <iostream>
using namespace std;

void elimina_repes(int v[util]){
	float* aux;
	
	for(int i = 0; i < util; i++){
		for(int j = i + 1; j < util; j++){
			if(datos[i] == datos[j]){
				for(int k = j; k < util; k++){
					datos[k] = datos[k + 1];
				}
				util--;
			}else{
				j++;
			}
		}
		aux = new float[util];
			for(int i = 0; i < util; i++){
				aux[i] = datos[i];
			}
			delete[] datos;
			datos = aux;
	}
}

void MostrarVector(int v[TAM], int util){
	for(int i = 0; i < util; i++){
		cout<< v[i] << " ";
	}
}


int main (){
	int i = 0, elemento, util;
	do{
		cin>>elemento;
		v[i] = elemento;
		i++;
		util = i;
	
	}while(elemento != -1);
	
	elimina_repes(v);
	MostrarVector(v);
}
