#include <iostream>
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <chrono>// Recursos para medir tiempos
using namespace std;
using namespace std::chrono;

void Seleccion (int * v, int tam){

	for(int i = 0; i < tam-1; i++){

		int pmin = i;
		int aux;
	
		for(int j = i+1; j < tam; j++)
			if(v[pmin] > v[j])
				pmin = j;

	
		aux = v[i];
		v[i] = v[pmin];
		v[pmin] = aux;     
	}
}

int main ( int argc, char * argv[] ){

	if(argc != 2)//Salir si no se dice el tamaño
		exit(EXIT_FAILURE);

	int tam = atoi(argv[1]);
	int *v = new int[tam];
	
	srand(time(0)); 

	for (int i = 0; i < tam; i++)//Generacion del vector aleatorio.
		v[i]= rand() % tam;	

	high_resolution_clock::time_point start, end;
	duration<double> tiempo_transcurrido;

	start = high_resolution_clock::now();//INICIO
	
	Seleccion(v, tam);

	end = high_resolution_clock::now();//FINAL

	tiempo_transcurrido  = duration_cast<duration<double> >(end - start);//FINAL - INICIO
	cout << tam << " "<< tiempo_transcurrido.count() << endl;

	delete [] v ;//Liberamos memoria	
	return 0;
}
