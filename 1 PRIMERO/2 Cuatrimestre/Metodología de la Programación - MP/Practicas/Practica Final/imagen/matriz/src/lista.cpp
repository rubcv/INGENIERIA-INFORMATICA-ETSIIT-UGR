#include <string>
#include <fstream>
#include <lista.h>

using namespace std;

Lista::Lista(){
	cabecera = NULL;
}
  
   
Lista::Lista(string valor){
	cabecera = new Celda;
	cabecera->datos = valor;
	cabecera->siguiente = NULL;
}	


Lista::Lista(const Lista& orig) { //Constructor de Copia
	cabecera = NULL;
	copiar(orig);
}


Lista& Lista::operator =(const Lista& orig) { //Sobrecarga Operador Asignacion
	if(this != &orig){
		destruir();
	}
	copiar(orig);
	return *this;
}


Lista Lista::operator +(const string& orig) { //Sobrecarga Operador Concatenacion
	Lista aux;
	int longLista = longitud();
	for(int i = 0; i < longLista; i++){
		aux.insertar(getCelda(i));
	}
	aux.insertar(orig);
	return aux;
}


Lista::~Lista() { //Destructor
   destruir();
}


void Lista::destruir(){
	Celda* borra;
	while(cabecera != NULL){
		borra = cabecera;
		cabecera = cabecera->siguiente;
		delete borra;
	}
}  


void Lista::insertar(const string valor){
	Celda* nueva = new Celda;
	nueva->datos = valor;
	nueva->siguiente = NULL;
	if(!cabecera){
		cabecera = nueva;
	}else{
		Celda* aux = cabecera;
		while(aux->siguiente != NULL){
			aux = aux->siguiente;
		}
		aux->siguiente = nueva;
	}
		
}


string Lista::getCelda(int pos) const{
	string valor;
	int contador = 0;	
	Celda* aux = cabecera;	
	while(contador < pos && aux){
		aux = aux->siguiente;
		contador++;	
	}
	if(aux != NULL){
		valor = aux->datos;
	}
	return valor;
}


int Lista::longitud() const{
	int contador = 0;
	Celda* aux;
	aux = cabecera;
	while(aux != NULL){
		aux = aux->siguiente;
		contador++;
	}
	return contador;

}


bool Lista::leerLista(const char nombrefichero[]){
	ifstream fin;
	fin.open(nombrefichero);
	if(!fin){
		return false;
	}else{
		string grises;
		int lineas;
		getline(fin,grises);
		fin >> lineas;
		getline(fin,grises);
		if (!fin){
			return false;
		}else {
			int i = 0;
			getline(fin,grises);
			while ((i < lineas)&&(fin)){
				if (grises != ""){
					insertar(grises);
					i++;
				}
				getline(fin,grises);
			}
		}
		fin.close();
	}
	return true;
}


Celda* Lista::getCabecera() const{
	return cabecera;
}



void Lista::copiar(const Lista& orig){
	Celda * aux = orig.getCabecera();
	while(aux != NULL){
		insertar(aux->datos);
		aux = aux->siguiente;
	}	
}

