#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"

#include <iostream>
#include <cmath>
#include <set>
#include <utility>
#include <list>
#include <limits>

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
	

void ComportamientoJugador::PintarMapa( const vector< vector <unsigned char> > & mapa){

	for(int i = 0; i < mapa.size(); i++){
		//cout<< "HOLA";
		for(int j = 0; j < mapa[0].size(); j++){
		//	cout<< "ADIOS";
			if(mapa[i][j] == '?')
				cout<< " ";
			else
				cout << mapa[i][j];
		}
		cout << endl;
	}

}

void ComportamientoJugador::actualizarMapa(Sensores sensores, estado actual, vector< vector<unsigned char> > & mapaAUX, vector<vector<int> > & mapaPesos ){

	vector<estado> lista_estados(16);

		mapaPesos[actual.fila][actual.columna]++;
		lista_estados[0] = actual;
		if(lista_estados[0].fila > 0 && lista_estados[0].columna > 0 && 
			lista_estados[0].fila < mapaAUX.size() && lista_estados[0].columna < mapaAUX.size() ){
			mapaAUX[lista_estados[0].fila][lista_estados[0].columna] = sensores.terreno[0];
			
			if(mapaAUX[lista_estados[0].fila][lista_estados[0].columna] == 'B' || 
				mapaAUX[lista_estados[0].fila][lista_estados[0].columna] == 'A' || 
				mapaAUX[lista_estados[0].fila][lista_estados[0].columna] == 'P' ||
				mapaAUX[lista_estados[0].fila][lista_estados[0].columna] == 'M' ||
				mapaAUX[lista_estados[0].fila][lista_estados[0].columna] == 'D'
			 ){
				mapaPesos[lista_estados[0].fila][lista_estados[0].columna] = numeric_limits<int>::max();
			}
		}

		lista_estados[1] = avanzar(actual);
		if(lista_estados[1].fila > 0 && lista_estados[1].columna > 0 && 
			lista_estados[1].fila < mapaAUX.size() && lista_estados[1].columna < mapaAUX.size() ){
			mapaAUX[lista_estados[1].fila][lista_estados[1].columna] = sensores.terreno[2];
			
			if(mapaAUX[lista_estados[1].fila][lista_estados[1].columna] == 'B' || 
				mapaAUX[lista_estados[1].fila][lista_estados[1].columna] == 'A' || 
				mapaAUX[lista_estados[1].fila][lista_estados[1].columna] == 'P' ||
				mapaAUX[lista_estados[1].fila][lista_estados[1].columna] == 'M' ||
				mapaAUX[lista_estados[1].fila][lista_estados[1].columna] == 'D'
			 ){
				mapaPesos[lista_estados[0].fila][lista_estados[0].columna] = numeric_limits<int>::max();
			}	
		}

		lista_estados[2] = avanzar(girarIzq(lista_estados[1]));
		if(lista_estados[2].fila > 0 && lista_estados[2].columna > 0 && 
			lista_estados[2].fila < mapaAUX.size() && lista_estados[2].columna < mapaAUX.size() ){
			mapaAUX[lista_estados[2].fila][lista_estados[2].columna] = sensores.terreno[1];
			
			if(mapaAUX[lista_estados[2].fila][lista_estados[2].columna] == 'B' || 
				mapaAUX[lista_estados[2].fila][lista_estados[2].columna] == 'A' || 
				mapaAUX[lista_estados[2].fila][lista_estados[2].columna] == 'P' ||
				mapaAUX[lista_estados[2].fila][lista_estados[2].columna] == 'M' ||
				mapaAUX[lista_estados[2].fila][lista_estados[2].columna] == 'D'
			 ){
				mapaPesos[lista_estados[0].fila][lista_estados[0].columna] = numeric_limits<int>::max();
			}	
		}

		lista_estados[3] = avanzar(girarDch(lista_estados[1]));
		if(lista_estados[3].fila > 0 && lista_estados[3].columna > 0 && 
			lista_estados[3].fila < mapaAUX.size() && lista_estados[3].columna < mapaAUX.size() ){
			mapaAUX[lista_estados[3].fila][lista_estados[3].columna] = sensores.terreno[3];
			
			if(mapaAUX[lista_estados[3].fila][lista_estados[3].columna] == 'B' || 
				mapaAUX[lista_estados[3].fila][lista_estados[3].columna] == 'A' || 
				mapaAUX[lista_estados[3].fila][lista_estados[3].columna] == 'P' ||
				mapaAUX[lista_estados[3].fila][lista_estados[3].columna] == 'M' ||
				mapaAUX[lista_estados[3].fila][lista_estados[3].columna] == 'D'
			 ){
				mapaPesos[lista_estados[0].fila][lista_estados[0].columna] = numeric_limits<int>::max();
			}	
		}

		
		lista_estados[4] = avanzar(lista_estados[1]);
		if(lista_estados[4].fila > 0 && lista_estados[4].columna > 0 && 
			lista_estados[4].fila < mapaAUX.size() && lista_estados[4].columna < mapaAUX.size() ){
			mapaAUX[lista_estados[4].fila][lista_estados[4].columna] = sensores.terreno[6];
			
			if(mapaAUX[lista_estados[4].fila][lista_estados[4].columna] == 'B' || 
				mapaAUX[lista_estados[4].fila][lista_estados[4].columna] == 'A' || 
				mapaAUX[lista_estados[4].fila][lista_estados[4].columna] == 'P' ||
				mapaAUX[lista_estados[4].fila][lista_estados[4].columna] == 'M' ||
				mapaAUX[lista_estados[4].fila][lista_estados[4].columna] == 'D'
			 ){
				mapaPesos[lista_estados[0].fila][lista_estados[0].columna] = numeric_limits<int>::max();
			}
		}


		lista_estados[5] = avanzar(girarIzq(lista_estados[4]));
		if(lista_estados[5].fila > 0 && lista_estados[5].columna > 0 && 
			lista_estados[5].fila < mapaAUX.size() && lista_estados[5].columna < mapaAUX.size() ){
			mapaAUX[lista_estados[5].fila][lista_estados[5].columna] = sensores.terreno[5];
			
			if(mapaAUX[lista_estados[5].fila][lista_estados[5].columna] == 'B' || 
				mapaAUX[lista_estados[5].fila][lista_estados[5].columna] == 'A' || 
				mapaAUX[lista_estados[5].fila][lista_estados[5].columna] == 'P' ||
				mapaAUX[lista_estados[5].fila][lista_estados[5].columna] == 'M' ||
				mapaAUX[lista_estados[5].fila][lista_estados[5].columna] == 'D'
			 ){
				mapaPesos[lista_estados[0].fila][lista_estados[0].columna] = numeric_limits<int>::max();
			}
		}


		lista_estados[6]  = avanzar(lista_estados[5]);
		if(lista_estados[6].fila > 0 && lista_estados[6].columna > 0 && 
			lista_estados[6].fila < mapaAUX.size() && lista_estados[6].columna < mapaAUX.size() ){
			mapaAUX[lista_estados[6].fila][lista_estados[6].columna] = sensores.terreno[4];
			
			if(mapaAUX[lista_estados[6].fila][lista_estados[6].columna] == 'B' || 
				mapaAUX[lista_estados[6].fila][lista_estados[6].columna] == 'A' || 
				mapaAUX[lista_estados[6].fila][lista_estados[6].columna] == 'P' ||
				mapaAUX[lista_estados[6].fila][lista_estados[6].columna] == 'M' ||
				mapaAUX[lista_estados[6].fila][lista_estados[6].columna] == 'D'
			 ){
				mapaPesos[lista_estados[0].fila][lista_estados[0].columna] = numeric_limits<int>::max();
			}
		}


		lista_estados[7]  = avanzar(girarDch(lista_estados[4]));
		if(lista_estados[7].fila > 0 && lista_estados[7].columna > 0 && 
			lista_estados[7].fila < mapaAUX.size() && lista_estados[7].columna < mapaAUX.size() ){
			mapaAUX[lista_estados[7].fila][lista_estados[7].columna] = sensores.terreno[7];
			
			if(mapaAUX[lista_estados[7].fila][lista_estados[7].columna] == 'B' || 
				mapaAUX[lista_estados[7].fila][lista_estados[7].columna] == 'A' || 
				mapaAUX[lista_estados[7].fila][lista_estados[7].columna] == 'P' ||
				mapaAUX[lista_estados[7].fila][lista_estados[7].columna] == 'M' ||
				mapaAUX[lista_estados[7].fila][lista_estados[7].columna] == 'D'
			 ){
				mapaPesos[lista_estados[0].fila][lista_estados[0].columna] = numeric_limits<int>::max();
			}
		}


		lista_estados[8]  = avanzar(lista_estados[7]);
		if(lista_estados[8].fila > 0 && lista_estados[8].columna > 0 && 
			lista_estados[8].fila < mapaAUX.size() && lista_estados[8].columna < mapaAUX.size() ){
			mapaAUX[lista_estados[8].fila][lista_estados[8].columna] = sensores.terreno[8];
			
			if(mapaAUX[lista_estados[8].fila][lista_estados[8].columna] == 'B' || 
				mapaAUX[lista_estados[8].fila][lista_estados[8].columna] == 'A' || 
				mapaAUX[lista_estados[8].fila][lista_estados[8].columna] == 'P' ||
				mapaAUX[lista_estados[8].fila][lista_estados[8].columna] == 'M' ||
				mapaAUX[lista_estados[8].fila][lista_estados[8].columna] == 'D'
			 ){
				mapaPesos[lista_estados[0].fila][lista_estados[0].columna] = numeric_limits<int>::max();
			}
		}


		lista_estados[9]  = avanzar(girarIzq(avanzar(girarDch(lista_estados[6]))));
		if(lista_estados[9].fila > 0 && lista_estados[9].columna > 0 && 
			lista_estados[9].fila < mapaAUX.size() && lista_estados[9].columna < mapaAUX.size() ){
			mapaAUX[lista_estados[9].fila][lista_estados[9].columna] = sensores.terreno[9];
			
			if(mapaAUX[lista_estados[9].fila][lista_estados[9].columna] == 'B' || 
				mapaAUX[lista_estados[9].fila][lista_estados[9].columna] == 'A' || 
				mapaAUX[lista_estados[9].fila][lista_estados[9].columna] == 'P' ||
				mapaAUX[lista_estados[9].fila][lista_estados[9].columna] == 'M' ||
				mapaAUX[lista_estados[9].fila][lista_estados[9].columna] == 'D'
			 ){
				mapaPesos[lista_estados[0].fila][lista_estados[0].columna] = numeric_limits<int>::max();
			}
		}


		lista_estados[10]  = avanzar(girarDch(lista_estados[4]));
		if(lista_estados[10].fila > 0 && lista_estados[10].columna > 0 && 
			lista_estados[10].fila < mapaAUX.size() && lista_estados[10].columna < mapaAUX.size() ){
			mapaAUX[lista_estados[10].fila][lista_estados[10].columna] = sensores.terreno[10];
			
			if(mapaAUX[lista_estados[10].fila][lista_estados[10].columna] == 'B' || 
				mapaAUX[lista_estados[10].fila][lista_estados[10].columna] == 'A' || 
				mapaAUX[lista_estados[10].fila][lista_estados[10].columna] == 'P' ||
				mapaAUX[lista_estados[10].fila][lista_estados[10].columna] == 'M' ||
				mapaAUX[lista_estados[10].fila][lista_estados[10].columna] == 'D'
			 ){
				mapaPesos[lista_estados[0].fila][lista_estados[0].columna] = numeric_limits<int>::max();
			}
		}


		lista_estados[11]  = avanzar(girarDch(lista_estados[5]));
		if(lista_estados[11].fila > 0 && lista_estados[11].columna > 0 && 
			lista_estados[11].fila < mapaAUX.size() && lista_estados[11].columna < mapaAUX.size() ){
			mapaAUX[lista_estados[11].fila][lista_estados[11].columna] = sensores.terreno[11];
			
			if(mapaAUX[lista_estados[11].fila][lista_estados[11].columna] == 'B' || 
				mapaAUX[lista_estados[11].fila][lista_estados[11].columna] == 'A' || 
				mapaAUX[lista_estados[11].fila][lista_estados[11].columna] == 'P' ||
				mapaAUX[lista_estados[11].fila][lista_estados[11].columna] == 'M' ||
				mapaAUX[lista_estados[11].fila][lista_estados[11].columna] == 'D'
			 ){
				mapaPesos[lista_estados[0].fila][lista_estados[0].columna] = numeric_limits<int>::max();
			}
		}


		lista_estados[12]  = avanzar(lista_estados[4]);
		if(lista_estados[12].fila > 0 && lista_estados[12].columna > 0 && 
			lista_estados[12].fila < mapaAUX.size() && lista_estados[12].columna < mapaAUX.size() ){
			mapaAUX[lista_estados[12].fila][lista_estados[12].columna] = sensores.terreno[12];
			
			if(mapaAUX[lista_estados[12].fila][lista_estados[12].columna] == 'B' || 
				mapaAUX[lista_estados[12].fila][lista_estados[12].columna] == 'A' || 
				mapaAUX[lista_estados[12].fila][lista_estados[12].columna] == 'P' ||
				mapaAUX[lista_estados[12].fila][lista_estados[12].columna] == 'M' ||
				mapaAUX[lista_estados[12].fila][lista_estados[12].columna] == 'D'
			 ){
				mapaPesos[lista_estados[0].fila][lista_estados[0].columna] = numeric_limits<int>::max();
			}
		}


		lista_estados[13]  = avanzar(girarIzq(lista_estados[7]));
		if(lista_estados[13].fila > 0 && lista_estados[13].columna > 0 && 
			lista_estados[13].fila < mapaAUX.size() && lista_estados[13].columna < mapaAUX.size() ){
			mapaAUX[lista_estados[13].fila][lista_estados[13].columna] = sensores.terreno[13];
			
			if(mapaAUX[lista_estados[13].fila][lista_estados[13].columna] == 'B' || 
				mapaAUX[lista_estados[13].fila][lista_estados[13].columna] == 'A' || 
				mapaAUX[lista_estados[13].fila][lista_estados[13].columna] == 'P' ||
				mapaAUX[lista_estados[13].fila][lista_estados[13].columna] == 'M' ||
				mapaAUX[lista_estados[13].fila][lista_estados[13].columna] == 'D'
			 ){
				mapaPesos[lista_estados[0].fila][lista_estados[0].columna] = numeric_limits<int>::max();
			}
		}

		
		lista_estados[14]  = avanzar(girarIzq(lista_estados[8]));
		if(lista_estados[14].fila > 0 && lista_estados[14].columna > 0 && 
			lista_estados[14].fila < mapaAUX.size() && lista_estados[14].columna < mapaAUX.size() ){
			mapaAUX[lista_estados[14].fila][lista_estados[14].columna] = sensores.terreno[14];
			
			if(mapaAUX[lista_estados[14].fila][lista_estados[14].columna] == 'B' || 
				mapaAUX[lista_estados[14].fila][lista_estados[14].columna] == 'A' || 
				mapaAUX[lista_estados[14].fila][lista_estados[14].columna] == 'P' ||
				mapaAUX[lista_estados[14].fila][lista_estados[14].columna] == 'M' ||
				mapaAUX[lista_estados[14].fila][lista_estados[14].columna] == 'D'
			 ){
				mapaPesos[lista_estados[0].fila][lista_estados[0].columna] = numeric_limits<int>::max();
			}
		}


		lista_estados[15]  = avanzar(girarDch(avanzar(girarIzq(lista_estados[8]))));
		if(lista_estados[15].fila > 0 && lista_estados[15].columna > 0 && 
			lista_estados[15].fila < mapaAUX.size() && lista_estados[15].columna < mapaAUX.size() ){
			mapaAUX[lista_estados[15].fila][lista_estados[15].columna] = sensores.terreno[15];
			
			if(mapaAUX[lista_estados[15].fila][lista_estados[15].columna] == 'B' || 
				mapaAUX[lista_estados[15].fila][lista_estados[15].columna] == 'A' || 
				mapaAUX[lista_estados[15].fila][lista_estados[15].columna] == 'P' ||
				mapaAUX[lista_estados[15].fila][lista_estados[15].columna] == 'M' ||
				mapaAUX[lista_estados[15].fila][lista_estados[15].columna] == 'D'
			 ){
				mapaPesos[lista_estados[0].fila][lista_estados[0].columna] = numeric_limits<int>::max();
			}
		}
}



Action ComportamientoJugador::think(Sensores sensores) {

	Action sigAccion;

	//cout << "sensores F antes: " << sensores.mensajeF << endl;
	if (sensores.mensajeF != -1){
		fil_anterior = fil;
		col_anterior = col;
		// Reorientacion copiar mapaTMP en maparesultado
		
		fil = sensores.mensajeF;
		col = sensores.mensajeC;
		estoyOrientado = true;


		for(int i = 0; i < mapaResultado.size(); i++){
    		for(int j = 0; j < mapaResultado.size(); j++){
            	if(mapaTMP[i + fil_anterior - fil][j + col_anterior - col] != '?'){
					mapaResultado[i][j] = mapaTMP[i + fil_anterior - fil][j + col_anterior - col];
				}
			}
		}
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


	// mapaResultado[]


	// Pintar el mapa 


	actual.fila = fil;
	cout << "ACTUAL FIL " << actual.fila << endl;
	cout << "ACTUAL COL " << actual.columna << endl;
	actual.columna = col;
	actual.orientacion = brujula;
	
	
	if(estoyOrientado){
		actualizarMapa(sensores, actual, mapaResultado, mapaPesos);
		PintarMapa(mapaResultado);	
	}else{
		actualizarMapa(sensores, actual, mapaTMP, mapaPesos);
		PintarMapa(mapaTMP);
	}
	
	
	VisualizaPlan(actual, plan);

	//cout << "THINK" << endl;

	// Determinar si ha cambiado el destino desde la ultima planificacion
	if (hayPlan and (sensores.destinoF != destino.fila or sensores.destinoC != destino.columna)){
		cout << "El destino ha cambiado\n";
		hayPlan = false;
	}

	if(destino.fila == -1){
		// Explorar
		
		if(!planTMP){
			estado destino_tmp;
			// Destino es la casilla con menor numero de mapaPesos
			int menor = numeric_limits<int>::max();

			estado tmp;
			tmp.fila = actual.fila - 1;
			tmp.columna = actual.columna;
			if(tmp.fila > 0 && tmp.fila < mapaResultado.size() &&
				 tmp.columna > 0 && tmp.columna < mapaResultado.size()){
				if(menor > mapaPesos[actual.fila-1][actual.columna]){
					menor = mapaPesos[actual.fila-1][actual.columna];
					destino_tmp.fila = actual.fila-1;
					destino_tmp.columna = actual.columna;

					plan.push_back(actFORWARD);
				}
			}

			
			tmp.fila = actual.fila + 1;
			tmp.columna = actual.columna;
			if(tmp.fila > 0 && tmp.fila < mapaResultado.size() &&
				 tmp.columna > 0 && tmp.columna < mapaResultado.size()){
				if(menor > mapaPesos[actual.fila+1][actual.columna]){
					menor = mapaPesos[actual.fila+1][actual.columna];
					destino_tmp.fila = actual.fila+1;
					destino_tmp.columna = actual.columna;

					plan.push_back(actTURN_R);
					plan.push_back(actTURN_R);
					plan.push_back(actFORWARD);
				}
			}

			
			tmp.fila = actual.fila - 1;
			tmp.columna = actual.columna -1;
			if(tmp.fila > 0 && tmp.fila < mapaResultado.size() &&
				 tmp.columna > 0 && tmp.columna < mapaResultado.size()){
				if(menor > mapaPesos[actual.fila-1][actual.columna-1]){
					menor = mapaPesos[actual.fila-1][actual.columna-1];
					destino_tmp.fila = actual.fila-1;
					destino_tmp.columna = actual.columna-1;

					plan.push_back(actFORWARD);
					plan.push_back(actTURN_L);
					plan.push_back(actFORWARD);

				}
			}
			cout << "PETA AQUI" << endl;

			
			tmp.fila = actual.fila - 1;
			tmp.columna = actual.columna +1;
			if(tmp.fila > 0 && tmp.fila < mapaResultado.size() &&
				 tmp.columna > 0 && tmp.columna < mapaResultado.size()){	
				if(menor > mapaPesos[actual.fila-1][actual.columna+1]){
					menor = mapaPesos[actual.fila-1][actual.columna+1];
					destino_tmp.fila = actual.fila-1;
					destino_tmp.columna = actual.columna+1;

					plan.push_back(actFORWARD);
					plan.push_back(actTURN_R);
					plan.push_back(actFORWARD);
				}
			}

			
			tmp.fila = actual.fila;
			tmp.columna = actual.columna -1;
			if(tmp.fila > 0 && tmp.fila < mapaResultado.size() &&
				 tmp.columna > 0 && tmp.columna < mapaResultado.size()){
				if(menor > mapaPesos[actual.fila][actual.columna-1]){
					menor = mapaPesos[actual.fila][actual.columna-1];
					destino_tmp.fila = actual.fila;
					destino_tmp.columna = actual.columna-1;

					plan.push_back(actTURN_L);
					plan.push_back(actFORWARD);
			
				}
			}

			
			tmp.fila = actual.fila;
			tmp.columna = actual.columna +1;
			if(tmp.fila > 0 && tmp.fila < mapaResultado.size() &&
				 tmp.columna > 0 && tmp.columna < mapaResultado.size()){
				if(menor > mapaPesos[actual.fila][actual.columna+1]){
					menor = mapaPesos[actual.fila][actual.columna+1];
					destino_tmp.fila = actual.fila;
					destino_tmp.columna = actual.columna+1;

					plan.push_back(actTURN_R);
					plan.push_back(actFORWARD);
					
				}
			}

			
			tmp.fila = actual.fila + 1;
			tmp.columna = actual.columna +1;
			if(tmp.fila > 0 && tmp.fila < mapaResultado.size() &&
				 tmp.columna > 0 && tmp.columna < mapaResultado.size()){
				if(menor > mapaPesos[actual.fila+1][actual.columna+1]){
					menor = mapaPesos[actual.fila+1][actual.columna+1];
					destino_tmp.fila = actual.fila+1;
					destino_tmp.columna = actual.columna+1;

					plan.push_back(actTURN_R);
					plan.push_back(actFORWARD);
					plan.push_back(actTURN_R);
					plan.push_back(actFORWARD);
				}
			}

			
			tmp.fila = actual.fila + 1;
			tmp.columna = actual.columna -1;
			if(tmp.fila > 0 && tmp.fila < mapaResultado.size() &&
				 tmp.columna > 0 && tmp.columna < mapaResultado.size()){
				if(menor > mapaPesos[actual.fila+1][actual.columna-1]){
					menor = mapaPesos[actual.fila+1][actual.columna-1];
					destino_tmp.fila = actual.fila+1;
					destino_tmp.columna = actual.columna-1;

					plan.push_back(actTURN_L);
					plan.push_back(actFORWARD);
					plan.push_back(actTURN_L);
					plan.push_back(actFORWARD);
				}

			}

			//pathFinding(actual, destino_tmp, plan);
			cout<< "MAPA" << endl;

			planTMP = true;
		}

		if(plan.size()){

			sigAccion = plan.front();
			plan.erase(plan.begin());
		}

		if(!plan.size()){
			planTMP = false;
		}
		
	}else{

		cout << "AQUI NO DEBERIA ESTAR" << endl;
		// Determinar si tengo que construir un plan
		if (!hayPlan){


			destino.fila = sensores.destinoF;
			destino.columna = sensores.destinoC;

			hayPlan = pathFinding(actual,destino,plan);
			
			VisualizaPlan(actual, plan);
		}


		// Ejecutar el plan
		
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
	

	}

	ultimaAccion = sigAccion;
	return sigAccion;

}





int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}
