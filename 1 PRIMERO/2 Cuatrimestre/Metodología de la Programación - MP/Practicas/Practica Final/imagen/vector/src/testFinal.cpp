// guarda degradado.pgm y trozo.pgm en formato texto. Lee lena.pgm en texto
#include<iostream>
#include<imagen.h>

using namespace std;

int main(){
    Imagen A,B,C;
	
	// Leer la imagen lena.pgm (formato texto)
	if (!A.leerImagen("imagenes/lena.pgm")){
		cerr << "error leyendo imagenes/lena.pgm\n";
		return 1;
	}
	
	// Leer la imagen gato.pgm (formato texto)
	if (!B.leerImagen("imagenes/gato.pgm")){
		cerr << "error leyendo imagenes/gato.pgm\n";
		return 1;
	}
	
	C = A + B;
	// Guardar la imagen destino en el fichero trozo.pgm (formato texto)
	if (C.escribirImagen("composicionAB.pgm", false)){
		// si todo va bien
		cout << "composicionAB.pgm guardado correctamente \n";
	} else { // si error
		cerr << "Error guardando la imagen composicionAB.pgm\n";
		return 1;
	}

	// Sobrecargas, destructor y constructor de copia
	Imagen D(A);	// Constructor de copia
	D = C + D;		// Sobrecarga del operador suma y asignacion

	// Guardar la imagen suma.pgm (formato texto)
	if(D.escribirImagen("composicionDC.pgm",false)){
		// si todo va bien
		cout << "composicionDC.pgm guardado correctamente \n";
	} else { // si error
		cerr << "Error guardando la imagen composicionDC.pgm\n";
		return 1;
	}
		
	return 0;
}
