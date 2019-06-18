#include <iostream>
#include <stdio.h>
#include "bloqueLed.h"
#include <cstring>

using namespace std;

void on(bloqueLed &b, int pos){
   unsigned char mask = 1 << pos;
   b = mask | b;
}

void off(bloqueLed &b, int pos){
	unsigned char mask = 1 << pos;
	b = ~mask & b;
}

bool get(bloqueLed b, int pos){
	unsigned char mask = 1 << pos;
	return (b & mask);
}

void print(bloqueLed b){
	for(int i = 7; i >= 0; i--){
		printf("%d",((b & (1<<i))>>i));
	}
}

void encender(bloqueLed &b){
	b = 255;
}

void apagar(bloqueLed &b){
	b = 0;
}

void asignar(bloqueLed &b, const bool v[]){
	for(int i = 0; i < 8; i++){
		if(v[i]){
			on(b, i);
		}else{
			off(b, i);
		}
	}
}

void volcar(bloqueLed b, bool v[]){
	for(int i = 0; i < 8; i++){
		v[i] = get(b, i);
	}
}

void encendidos(bloqueLed b, int posic[], int &cuantos){
	cuantos = 0;
	for(int i = 0; i < 8; i++){
		if(get(b, i)){
			posic[cuantos] = i;
			cuantos++;
		}
	}
}

string bloqueLedToString(bloqueLed b){
	string cadena = "";
	for(int i = 7; i >= 0; i--){
		if(get(b, i)){
			cadena.push_back('1');
		}else{
			cadena.push_back('0');
		}
	}
	return cadena;
}
