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
  	int heuristica, f;

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


bool operator< (const Accion & una, const Accion & otra ){
	return (una.f > otra.f);
}

bool operator< (const estado & uno, const estado & otro){

	if(uno.fila < otro.fila ) return true;

	if(uno.fila == otro.fila && uno.columna < otro.columna) return true;

	if(uno.fila == otro.fila && uno.columna == otro.columna && uno.orientacion < otro.orientacion) return true;

	return false;
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
	bool dentro = false;
	bool suelo = false;

	if(( pos.columna > 0 && pos.columna < 100) && ( pos.fila > 0 && pos.fila < 100) ){

		dentro = true;
	}	

	if(dentro){
		suelo = (mapaResultado[pos.fila][pos.columna] == 'K' ||
				mapaResultado[pos.fila][pos.columna] == 'T' ||
				mapaResultado[pos.fila][pos.columna] == 'S');
	}

	return (suelo && dentro);

}

bool ComportamientoJugador::esDestino(estado uno, estado destino){

	return (uno.fila == destino.fila && uno.columna == destino.columna);
}


bool ComportamientoJugador::pathFinding(const estado &origen, const estado &destino, list<Action> &plan) {
	
	plan.clear();

  Accion accionActual, sigmov;

  accionActual.posActual = origen;
  priority_queue<Accion> abiertos;
  abiertos.push(accionActual);
  set <estado> cerrados;

  while(!abiertos.empty()){

	  accionActual = abiertos.top();
	  abiertos.pop();

	  // Avanzar

	  sigmov = accionActual; // Hacemos una copia
	  sigmov.posActual = avanzar(sigmov.posActual);

	  	if(cerrados.find(sigmov.posActual) == cerrados.end()){

			if(puedoIrACasilla(sigmov.posActual)){
				
				sigmov.plan.push_back(actFORWARD);
				sigmov.heuristica = abs(sigmov.posActual.fila - destino.fila) + abs(sigmov.posActual.columna - destino.columna);
				sigmov.f = sigmov.heuristica + sigmov.plan.size();
				

				if(esDestino(sigmov.posActual, destino)){
					plan = sigmov.plan;
					return true;
				}
			
				abiertos.push(sigmov);
			}
		
	  	}
		
		//cout << "PASA" << endl;

		//Izq

		sigmov = accionActual;
		sigmov.posActual = girarIzq(sigmov.posActual);

		if(cerrados.find(sigmov.posActual) == cerrados.end()){
			sigmov.plan.push_back(actTURN_L);
			sigmov.heuristica = abs(sigmov.posActual.fila - destino.fila) + abs(sigmov.posActual.columna - destino.columna);
			sigmov.f = sigmov.heuristica + sigmov.plan.size();
			abiertos.push(sigmov);
		} 

		//Dch

		sigmov = accionActual;
		sigmov.posActual = girarDch(sigmov.posActual);

		if(cerrados.find(sigmov.posActual) == cerrados.end()){
			sigmov.plan.push_back(actTURN_R);
			sigmov.heuristica = abs(sigmov.posActual.fila - destino.fila) + abs(sigmov.posActual.columna - destino.columna);
			sigmov.f = sigmov.heuristica + sigmov.plan.size();
			abiertos.push(sigmov);
		} 

			cerrados.insert(accionActual.posActual);
		
	}

	
	
	return false;
}
	

void ComportamientoJugador::actualizarMapa(Sensores sensores, estado actual){
	estado siguienteAUX;
	
	mapaTMP[siguienteAUX.fila][siguienteAUX.columna] = 
	siguienteAUX = avanzar(actual);
	mapaTMP[siguienteAUX.fila][siguienteAUX.columna] = sensores[2];

	siguienteAUX = avanzar(girarIzq(avanzar(actual)));

	siguienteAUX = avanzar(girarDch(avanzar(actual)));

}


Action ComportamientoJugador::think(Sensores sensores) {

	//cout << "sensores F antes: " << sensores.mensajeF << endl;
	if (sensores.mensajeF != -1 && fil == 99){
		int aux1 = fil, aux2 = col;
		fil = sensores.mensajeF;
		col = sensores.mensajeC;
		if(aux1 != fil || aux2 != col) cout << "TU PUTA M.... " << endl;
		cout << "De fila " << aux1 << " a fila " << fil << endl;
		cout << "De col " << aux2 << " a fila " << col << endl;
	}

	//cout << "fil y col despues: " << fil << " " << col << endl;


	// Actualizar el efecto de la ultima accion
	switch (ultimaAccion){
		case actTURN_R: brujula = (brujula+1)%4; break;
		case actTURN_L: brujula = (brujula+3)%4; break;
		case actFORWARD:
			switch (brujula){
				case 0: fil--; break;
				case 1: col++; break;
				case 2: fil++; break;
				case 3: col--; break;
			}
			//cout << "fil: " << fil << "  col: " << col << " Or: " << brujula << endl;
	}

	// Actualizar mapa con la info de sensores
	

	
	// -> No tiene  en cuenta la orientacion en cada ocasion 
	actualizarMapa(sensores, actual);


	// mapaResultado[]



	// Pintar el mapa 


	// return actFORWARD;

	actual.fila = fil;
	actual.columna = col;
	actual.orientacion = brujula;
	VisualizaPlan(actual, plan);

	//cout << "THINK" << endl;

	// Determinar si ha cambiado el destino desde la ultima planificacion
	if (hayPlan and (sensores.destinoF != destino.fila or sensores.destinoC != destino.columna)){
		cout << "El destino ha cambiado\n";
		hayPlan = false;
	}

	// Determinar si tengo que construir un plan
	if (!hayPlan){


		destino.fila = sensores.destinoF;
		destino.columna = sensores.destinoC;

		hayPlan = pathFinding(actual,destino,plan);
		
		VisualizaPlan(actual, plan);
	}


	// Ejecutar el plan
	Action sigAccion;
	if (hayPlan and plan.size()>0){
		sigAccion = plan.front();
		if(sigAccion == actFORWARD && sensores.superficie.size() && sensores.superficie[2] == 'a'){
			sigAccion = actIDLE;
		}else{
			plan.erase(plan.begin());
		}
	}
	else {
		sigAccion = actIDLE;
	}



	ultimaAccion = sigAccion;
	return sigAccion;

}





int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}
