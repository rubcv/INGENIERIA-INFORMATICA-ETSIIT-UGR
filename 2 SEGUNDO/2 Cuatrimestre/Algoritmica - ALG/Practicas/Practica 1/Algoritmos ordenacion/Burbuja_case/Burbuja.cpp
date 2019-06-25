#include <iostream>
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <chrono>// Recursos para medir tiempos
using namespace std;
using namespace std::chrono;

void Burbuja (int * v, int tam){

	int temp;

	for (int i = 1 ; i < tam ; i++)
		for(int j = 0; j < tam-1; j++)
			if(v[j] > v[j+1]){
				temp = v[j];
				v[j] = v[j+1];
				v[j+1] = temp;
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

	Burbuja(v, tam);

	end = high_resolution_clock::now();//FINAL

	tiempo_transcurrido  = duration_cast<duration<double> >(end - start);//FINAL - INICIO
	cout << tam << " "<< tiempo_transcurrido.count() << endl;

	delete [] v ;//Liberamos memoria
	return 0;
}
