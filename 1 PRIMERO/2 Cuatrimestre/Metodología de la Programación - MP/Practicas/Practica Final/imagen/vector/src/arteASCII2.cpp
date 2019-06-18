/**
 * lee cualquier imagen indicada por el usuario y un fichero con cadenas 
 * de caracteres y crea ficheros de imagen transformadas, una por cadena
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include "imagen.h"
#include "lista.h"

using namespace std;

int main(int argc, char *argv[]){
	Imagen origen;
	Lista celdas;

	if(argc != 3){
		cout << "Debes ingresar: imagen texto" << endl;
		return -1;
	}

	char *ficheroGrises = argv[2];
	char *ficheroImagen = argv[1];

	// Leer la imagen desde fichero
	if (!origen.leerImagen(ficheroImagen)){
		cerr << "Error leyendo imagen " << ficheroImagen << endl;
		return -1;
	}

	// Leer cadenas desde fichero
	if (celdas.leerLista(ficheroGrises)){	
		// realizar las conversiones
		if (origen.listaAArteASCII(celdas)){
			cout << "Exito en la conversion." << endl;
			cout << "Chequee los ficheros asciiX.txt" << endl;
			cout << endl;
		}else{
			cerr << "La conversion no ha sido posible" << endl;
			cerr << endl;
		}
	}else{
		cerr << "Error lista de grises " << ficheroGrises << endl;
		return -1;
	}

	return 0;
	
}
