#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"

#include <iostream>
#include <cmath>
#include <set>
#include <utility>
#include <list>

#include <queue>


using namespace std;




struct Accion {
	estado posActual, destino;

	list<Action> plan;
  	int heuristica;

};


void ComportamientoJugador::PintaPlan(list<Action> plan) {
	auto it = plan.begin();
	while (it!=plan.end()){
		if (*it == actFORWARD){
			cout << "A ";
		}
		else if (*it == actTURN_R){
			cout << "D ";
		}
		else if (*it == actTURN_L){
			cout << "I ";
		}
		else {
			cout << "- ";
		}
		it++;
	}
	cout << endl;
}

void ComportamientoJugador::AnularMatriz(vector<vector<unsigned char> > &m){
	for (int i=0; i<m[0].size(); i++){
		for (int j=0; j<m.size(); j++){
			m[i][j]=0;
		}
	}
}

int distanciaManhattan(estado inicial, estado fin){

	int res = abs(fin.fila - inicial.fila) + abs(fin.columna - inicial.columna);

	return res;

}

int distanciaCoste(estado inicial, estado fin, list<Action> plan ){

	int coste = distanciaManhattan(inicial, fin) + plan.size();

	return coste;

}

//Cambiar m1.f > m2.f

bool operator< (const Accion & una, const Accion & otra ){

	return (distanciaCoste(una.posActual, una.destino, una.plan) > distanciaCoste(otra.posActual, otra.destino, otra.plan));
}

bool operator< (const estado & uno, const estado & otro){

	if(uno.fila < otro.fila ) return true;

	if(uno.fila == otro.fila && uno.columna < otro.columna) return true;

	if(uno.fila == otro.fila && uno.columna == otro.columna && uno.orientacion < otro.orientacion) return true;

}


void ComportamientoJugador::VisualizaPlan(const estado &st, const list<Action> &plan){
  AnularMatriz(mapaConPlan);
	estado cst = st;

	auto it = plan.begin();
	while (it!=plan.end()){
		if (*it == actFORWARD){
			switch (cst.orientacion) {
				case 0: cst.fila--; break;
				case 1: cst.columna++; break;
				case 2: cst.fila++; break;
				case 3: cst.columna--; break;
			}
			mapaConPlan[cst.fila][cst.columna]=1;
		}
		else if (*it == actTURN_R){
			cst.orientacion = (cst.orientacion+1)%4;
		}
		else {
			cst.orientacion = (cst.orientacion+3)%4;
		}
		it++;
	}
}

estado ComportamientoJugador::avanzar(estado pos){
	estado sig(pos);
	
	if(pos.orientacion == 0){ //Norte
		sig.fila = pos.fila - 1;
		sig.columna = pos.columna;
	}else if(pos.orientacion == 1){ //Este
		sig.fila = pos.fila;
		sig.columna = pos.columna + 1;
	}else if(pos.orientacion == 2){ // Sur
		sig.fila = pos.fila + 1;
		sig.columna = pos.columna;
	}else if(pos.orientacion == 3){ //Oeste
		sig.fila = pos.fila;
		sig.columna = pos.columna - 1;	
	}
	
	sig.orientacion = pos.orientacion;
	
	return sig;
}

// Inicializar con pos para que filas/columnas no valgan 0

estado ComportamientoJugador::girarIzq(estado pos){ // Cambia orientacion
	estado sig(pos);
	
	sig.orientacion = (pos.orientacion + 3) % 4;
	
	return sig;
}

	/* LLAMADA
		Estado sig = avanzar(girarIzq(posAct));
	*/
	
estado ComportamientoJugador::girarDch(estado pos){ // + 1
	estado sig(pos);
	
	sig.orientacion = (pos.orientacion + 1) % 4;	
	
	return sig;
}


bool ComportamientoJugador::puedoIrACasilla(const estado & pos){

	//cout << "COMPRUEBA" << endl; 
	//cout << "MAPA_RES:" << mapaResultado[siguiente.fila][siguiente.columna] << endl;
	// Comprobar que no sean negativos y 100
	
	bool puedo=false; /////comprobar el tamaño del mapa

bool Tierraarenosa=(mapaResultado[pos.fila][pos.columna]=='T');
bool Suelopedreoso=(mapaResultado[pos.fila][pos.columna]=='S');
bool puntodereferencia=(mapaResultado[pos.fila][pos.columna]=='K');
bool puerta =(mapaResultado[pos.fila][pos.columna]=='D');
bool limitesFila=((pos.fila<mapaResultado.size())&&(pos.fila>0));
bool limitesColumna=((pos.columna<mapaResultado[0].size())&&(pos.columna>0));

bool puedocaminar=(Tierraarenosa||Suelopedreoso||puntodereferencia||puerta);
bool limites=(limitesFila || limitesColumna );

if (puedocaminar && limites) {
puedo=true;
}

return puedo;


/*
	if(( pos.columna > 0 && pos.columna < 100) &&  
			( pos.fila > 0 && pos.fila < 100) ){

				return true;
			}	

	bool suelo = (mapaResultado[pos.fila][pos.columna] == 'K' ||
	mapaResultado[pos.fila][pos.columna] == 'T' ||
	mapaResultado[pos.fila][pos.columna] == 'S');

	return suelo;
*/
}

bool ComportamientoJugador::esDestino(estado uno, estado destino){

	return (uno.fila == destino.fila && uno.columna == destino.columna);
}


bool ComportamientoJugador::pathFinding(const estado &origen, const estado &destino, list<Action> &plan) {
	

  Accion actual, sigmov;

  actual.posActual = origen;
  priority_queue<Accion> abiertos;
  abiertos.push(actual);
  set <estado> cerrados;

  while(!abiertos.empty()){

	  actual = abiertos.top();
	  abiertos.pop();

	  // Avanzar

	  sigmov = actual; // Hacemos una copia
	  sigmov.posActual = avanzar(sigmov.posActual);

	  	if(cerrados.find(sigmov.posActual) == cerrados.end()){

			if(puedoIrACasilla(sigmov.posActual)){
				
				sigmov.plan.push_back(actFORWARD);
				sigmov.heuristica  = distanciaCoste(sigmov.posActual, destino, sigmov.plan);

				if(esDestino(sigmov.posActual, destino)){
					plan = sigmov.plan;
					return true;
				}
			
				abiertos.push(sigmov);
			}
		
	  	}
		
		//Izq

		sigmov = actual;
		sigmov.posActual = girarIzq(sigmov.posActual);

		if(cerrados.find(sigmov.posActual) == cerrados.end()){
			sigmov.plan.push_back(actTURN_L);
			sigmov.heuristica = distanciaCoste(sigmov.posActual, destino, sigmov.plan);
			abiertos.push(sigmov);
		} 

		//Dch

		sigmov = actual;
		sigmov.posActual = girarDch(sigmov.posActual);

		if(cerrados.find(sigmov.posActual) == cerrados.end()){
			sigmov.plan.push_back(actTURN_R);
			sigmov.heuristica = distanciaCoste(sigmov.posActual, destino, sigmov.plan);
			abiertos.push(sigmov);
		} 

			cerrados.insert(actual.posActual);
		
	}

	
	
	return false;
}
	

Action ComportamientoJugador::think(Sensores sensores) {

	Action accion = actIDLE;

	cout<< "SE LLAMA A THINK" << endl;

	if((fin.fila != sensores.destinoF) || (fin.columna != sensores.destinoC)){
		cout << "DESTINO CAMBIADO" << endl;
			plan.clear();

	}

	
	if(plan.empty()){
		inicial.fila = sensores.mensajeF;
		inicial.columna = sensores.mensajeC;
		inicial.orientacion = 0;

		fin.fila = sensores.destinoF;
		fin.columna = sensores.destinoC;

		if(!pathFinding(inicial, fin, plan)){
			exit(0);
		}
		cout << "Nuevo plan" << endl;
		PintaPlan(plan);
		VisualizaPlan(inicial, plan);
	}

	if(!plan.empty()){
		PintaPlan(plan);
		accion = plan.front();
		plan.pop_front();
	}

	return accion;
}





int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}
