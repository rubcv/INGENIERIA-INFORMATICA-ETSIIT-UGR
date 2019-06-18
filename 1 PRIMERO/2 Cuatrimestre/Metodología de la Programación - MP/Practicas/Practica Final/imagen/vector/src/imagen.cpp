#include <cstring>
#include <byte.h>
#include <imagen.h>
#include <pgm.h>
#include <fstream>
#include <iostream>
#include <lista.h>

using namespace std;

Imagen::Imagen(){
	nfilas = 0;
	ncolumnas = 0;
	datos = 0;
}

   
Imagen::Imagen(int filas, int columnas){
	datos = 0;
	crear(filas, columnas);
}


Imagen::Imagen(const Imagen& orig){ //Constructor de Copia
	datos = 0;
	copiar(orig);
}


Imagen& Imagen::operator =(const Imagen& orig){ //Sobrecarga Operador Asignacion
	if(this != &orig){	
		copiar(orig);
	}
	return *this;
}


Imagen Imagen::operator +(const Imagen& orig){ //Sobrecarga Operador Concatenacion
	int maxFilas;
	if(nfilas > orig.filas()){
		maxFilas = nfilas;
	}else{
		maxFilas = orig.filas();
	}
	int maxColumnas = ncolumnas+orig.columnas();
	Imagen auxiliar(maxFilas, maxColumnas);
	for(int i = 0; i < nfilas; i++){
		for(int j = 0; j < ncolumnas; j++){
			auxiliar.set(i, j, get(i, j));
		}
	}
	for(int i = 0; i < orig.filas(); i++){
		for(int j = 0; j < orig.columnas(); j++){
			auxiliar.set(i, j+ncolumnas, orig.get(i, j));
		}
	}
	return auxiliar;
}


Imagen::~Imagen(){ //Destructor 
	destruir();
}

   
void Imagen::crear(int filas, int columnas){
	destruir();
	if(filas > 0 && columnas >0){
		nfilas = filas;
		ncolumnas = columnas;
		MAXPIXELS = nfilas * ncolumnas;
		datos = new byte [MAXPIXELS];
		for(int i = 0; i < MAXPIXELS; i++){
			datos[i] = 0;
		}
	}
}

   
int Imagen::filas()const{
	return nfilas;
}


int Imagen::columnas()const{
	return ncolumnas;
}
   
   
void Imagen::set(int y, int x, byte v){
	if(0 <= x && x < ncolumnas && 0 <= y && y < nfilas){
		datos[y*ncolumnas+x] = v;
	}
}
   
   
byte Imagen::get(int y, int x)const{
	if(0 <= x && x < ncolumnas && 0 <= y && y < nfilas){
		return datos[y*ncolumnas+x];
	}else{
		byte aux = 0;
		return aux;
	}
}
   
   
void Imagen::setPos(int i, byte v){
	if(i <= MAXPIXELS && i >= 0){
		datos[i] = v;
	}
}
   
   
byte Imagen::getPos(int i)const{
	if(i <= MAXPIXELS && i >= 0){
		return datos[i];
	}else{
		byte aux = 0;
		return aux;
	}
}


bool Imagen::leerImagen(const char nombreFichero[]){
	bool flag = false;
	TipoImagen tipo = infoPGM(nombreFichero, nfilas, ncolumnas);
	if((tipo == IMG_PGM_BINARIO)){
		Imagen::crear(nfilas, ncolumnas);
		flag = leerPGMBinario(nombreFichero, datos, nfilas, ncolumnas);
	}else if((tipo == IMG_PGM_TEXTO)){
		Imagen::crear(nfilas, ncolumnas);
		flag = leerPGMTexto(nombreFichero, datos, nfilas, ncolumnas);
	}	
	return flag;
}
   
   
bool Imagen::escribirImagen(const char nombreFichero[], bool esBinario){
	bool flag = false;	
	if(esBinario){
		flag = escribirPGMBinario(nombreFichero, datos, nfilas, ncolumnas);
	}else{
		flag = escribirPGMTexto(nombreFichero, datos, nfilas, ncolumnas);
	}
	return flag;
}


Imagen Imagen::plano(int k){
	Imagen img(nfilas, ncolumnas);
	byte aux;	
	for(int i = 0; i < MAXPIXELS; i++){
		aux = img.getPos(i);
		if(getbit(datos[i], k)){
			on(aux, 7);
		}else{
			off(aux, 7);
		}
		img.setPos(i, aux);
	}
	return img;
}


bool Imagen::aArteASCII(const char grises[], char arteASCII[], int maxlong){
	int cardinal = 0, auxiliar = 0, cols = ncolumnas+1;
	bool flag = (nfilas*(ncolumnas+1)+1) <= maxlong;	
	if(flag){
		cardinal = strlen(grises);	
		for(int i = 0; i < nfilas; i++){
			for(int j = 0; j < ncolumnas; j++){
				auxiliar = i*cols+j;
				arteASCII[auxiliar]=grises[get(i, j)*cardinal/256];
			}
			auxiliar = i*cols+ncolumnas;
			arteASCII[auxiliar]='\n';
		}	
		arteASCII[auxiliar+1]='\0';
	}
	return flag;
}


bool Imagen::listaAArteASCII(const Lista celdas){
	bool resultado = true;
	string nombre = "ascii0";
	ofstream fsalida;
	const int MAXLONG = (nfilas*(ncolumnas+1)+1);
	char *arteASCII = new char[MAXLONG];
	int longCeldas = celdas.longitud();
	for(int i = 0; i < longCeldas; i++){
		fsalida.open((nombre+to_string(i+1)).c_str());
		fsalida << "\nLa imagen en arte ASCII es:\n";
		if(aArteASCII(celdas.getCelda(i).c_str(), arteASCII, MAXLONG)){
			fsalida << arteASCII;
		}else{
			fsalida << "La Conversion no ha sido Posible" << endl;
			resultado = false;
		}
		fsalida.close();		
	}
	delete [] arteASCII;
	arteASCII = 0;
	return resultado;
}


void Imagen::destruir(){
	if(datos != 0){
		delete [] datos;
		datos = 0;
	}
	nfilas = 0;
	ncolumnas = 0;
}

void Imagen::copiar(const Imagen& orig){
	crear(orig.filas(), orig.columnas());
	for(int i = 0; i < MAXPIXELS; i++){
		setPos(i, orig.getPos(i));
	}
}
