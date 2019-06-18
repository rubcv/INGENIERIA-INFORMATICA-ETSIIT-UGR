#include "byte.h"
#include <iostream>

using namespace std;

void on(byte & b, int pos){
   	byte mask;
   	if((pos>= 0) && (pos < 8)){
      		mask = 0x1 << pos; // genero la mascara
      		b = b | mask;
   	}
}


void off(byte & b, int pos){
   	byte mask;
   	if((pos>= 0) && (pos < 8)){
      		mask = 0x1 << pos; // genero la mascara
      		mask = ~mask; // invierto todos los bits
      		b = b & mask; // hago un AND para dejar todo igual salvo el cero
   	}
}


bool getbit(byte b, int pos){
	byte mask;
	bool status;
	mask = 0x1 << pos; // genero la mascara
	status = (b & mask) > 0; // hago un AND y compruebo si el resultado es mayor que cero
	return(status);
}


string byteToString(byte b){
	int i;
	bool valor;
	char c;
	string s;
	for(i=7; i >= 0; i--){
      		valor = getbit(b,i);
      		c = valor + '0';
      		s = s + c;
   	}
   	return s;
}


void encender(byte & b){
   	b = 0xFF; // es el 1111 1111
}


void apagar(byte & b){
   	b = 0x0; // es el 0000 0000
}


void asignar(byte & b, const bool v[]){
   	apagar(b);// los apago todos
   	for(int i=7; i >=0; i--){ // y enciendo algunos
      		if (v[i]){
         		on(b,7-i);
		}
   	}
}


void volcar(byte b, bool v[]){
   	for(int i = 0; i<8; i++){
      		v[i] = getbit(b,i);
   	}
}


void encendidos(byte b, int posic[], int & cuantos){
   	cuantos = 0;
   	bool valor;
   	for(int i = 0; i<8; i++){
		valor = getbit(b,i);
      		if(valor){
        		posic[cuantos] = i;
      			cuantos++;
      		}
   	}
}
