#include <iostream>
#include <fstream>
#include <cstring>
#include "imagen.h"
#include "lista.h"

using namespace std;

int main(int argc, char *argv[]){
	Imagen imgA, imgB;
	Lista celdas;
	if(argc != 5){
		cout << "Debes ingresar: img1 img2 imgFinal flag" << endl;
		return -1;
	}
	string imagenA(argv[1]);
	string imagenB(argv[2]);
	if (!imgA.leerImagen(imagenA.c_str()) || !imgB.leerImagen(imagenB.c_str())){
		cerr << "Error leyendo imagenes " << endl;
		return -1;
   	} 
	imgA = imgA + imgB;
	string valor(argv[4]);
	string nombre(argv[3]);
	if(valor == "t"){
		if(imgA.escribirImagen(nombre.c_str(), false)){
			cout << "Imagen creada en texto con exito" << endl;
		}else{
			cerr << "Error al crear la imagen en texto" << endl;
			return -1;
		}
	}else if(valor == "b"){
		if(imgA.escribirImagen(nombre.c_str(), true)){
			cout << "Imagen creada en binario con exito" << endl;
		}else{
			cerr << "Error al crear la imagen en binario" << endl;
			return -1;
		}
	}else{
		cout << "Tienes que elegir b (binario) o t (texto)" << endl;
		return -1;
	}
	return 0;
}
