#include "../Comportamientos_Jugador/jugador.hpp"
#include "motorlib/util.h"
#include <iostream>
#include <cmath>
#include<set>
#include<queue>


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

estado ComportamientoJugador::avanzar(estado pos){
	estado sig;
	if(pos.orientacion==0){	//Norte
		sig.fila=pos.fila - 1;
		sig.columna=pos.columna;
	}
	else if(pos.orientacion==1){ //Este
		sig.fila=pos.fila;
		sig.columna=pos.columna +1;
	}
	else if(pos.orientacion==2){	//sur
		sig.fila=pos.fila+1;
		sig.columna=pos.columna;
	}
	else if(pos.orientacion==3){	//Oeste
		sig.fila=pos.fila;
		sig.columna=pos.columna-1;

	}
	sig.orientacion=pos.orientacion; ///la orientacion no cambia
	return sig;

}



bool ComportamientoJugador::puedoAvanzar(estado pos){
	bool puedo=false;				/////comprobar el tamaño del mapa

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
}

estado ComportamientoJugador::girarIzq(estado pos){
	estado sig;
	if(pos.orientacion==0){	//Norte
		sig.orientacion=3; //ahora miro para el oeste
	}
	else if(pos.orientacion==1){ //Este
		sig.orientacion=0;///ahora miro al norte
	}
	else if(pos.orientacion==2){	//sur
		sig.orientacion=1; //ahora miro al este
	}
	else if(pos.orientacion==3){	//Oeste
		sig.orientacion=2; //ahora miro al Sur
	}

	sig.fila=pos.fila;       //no nos movemos,solo cambiamos la orientacion
	sig.columna=pos.columna;

	return sig;

}

estado ComportamientoJugador::girarDch(estado pos){

	estado sig;

	if(pos.orientacion==0){	//Norte
		sig.orientacion=1; //ahora miro al este
	}
	else if(pos.orientacion==1){ //Este
		sig.orientacion=2;	//ahora miro al sur
	}
	else if(pos.orientacion==2){	//sur
		sig.orientacion=3;	//ahora miro al oeste
	}
	else if(pos.orientacion==3){	//Oeste
		sig.orientacion=0;	//ahora miro al Norte
	}
	sig.fila=pos.fila;				//no nos movemos,solo cambiamos la orientacion
	sig.columna=pos.columna;

	return sig;

}

int ComportamientoJugador::PlanManhatan(estado posActual,estado posFinal){
	int filas=abs(posFinal.fila - posActual.fila);
	int columnas=abs(posFinal.columna -posActual.columna);
	return filas+columnas;
}

bool ComportamientoJugador::esNuestroDestino(estado posActual,estado destino){
	bool esDestino=false;
	if((posActual.fila == destino.fila) || (posActual.columna==destino.columna)){
		esDestino=true;
	}
	return esDestino;
}

bool operator<(const Movimiento &m1,const Movimiento &m2){
	return m1.f>m2.f;
}
 bool operator<(const estado &e1, const estado &e2){
	 if(e1.fila < e2.fila) return true;
	 if(e1.fila == e2.fila && e1.columna < e2.columna) return true;
	 if((e1.fila == e2.fila) && e1.columna == e2.columna && e1.orientacion < e2.orientacion) return true;
	 return false;
}


bool ComportamientoJugador::pathFinding(const estado &origen, const estado &destino, list<Action> &plan) {
	Movimiento actual,sigMovimiento;

	priority_queue<Movimiento> abiertos;//Se puede usar una priority_queue
	set<estado>cerrados;
	actual.posActual = origen;

	plan.clear();

	cout << "Preparando plan" << endl;

	//ABIERTOS Contiene el nodo inicial
	abiertos.push(actual);

	//Comenzamos ciclo
	while(!abiertos.empty() ){
		actual = abiertos.top();
		abiertos.pop();
			//Avanzar
			sigMovimiento = actual;
			sigMovimiento.posActual = avanzar(sigMovimiento.posActual);

			if(cerrados.find(sigMovimiento.posActual) == cerrados.end()){  //miramos si está en cerrados

					if(puedoAvanzar(sigMovimiento.posActual)){

						sigMovimiento.plan.push_back(actFORWARD);
						sigMovimiento.h = PlanManhatan(sigMovimiento.posActual,destino);
						sigMovimiento.g = sigMovimiento.plan.size();
						sigMovimiento.f = sigMovimiento.h + sigMovimiento.g;
						if((sigMovimiento.posActual.fila == destino.fila) && (sigMovimiento.posActual.columna == destino.columna)){
							cout<<"He encontrado un plan"<<endl;
							plan=sigMovimiento.plan;
							return true;//Si hemos llegado al destino, hemos encontrado un camino o plan
						}
						abiertos.push(sigMovimiento);


					}

				}

				//Izquierda
				sigMovimiento = actual;//Hacemos una copia
				sigMovimiento.posActual = girarIzq(sigMovimiento.posActual);

				if(cerrados.find(sigMovimiento.posActual)==cerrados.end()){    //miramos si está en cerrados


						sigMovimiento.h = PlanManhatan(sigMovimiento.posActual,destino);
						sigMovimiento.g = sigMovimiento.plan.size();
						sigMovimiento.f = sigMovimiento.h + sigMovimiento.g;
						sigMovimiento.plan.push_back(actTURN_L);

						abiertos.push(sigMovimiento);

				}
				//Derecha
				sigMovimiento = actual;
				sigMovimiento.posActual = girarDch(sigMovimiento.posActual);
				if(cerrados.find(sigMovimiento.posActual) == cerrados.end()){

						sigMovimiento.h = PlanManhatan(sigMovimiento.posActual,destino);
						sigMovimiento.g = sigMovimiento.plan.size();
						sigMovimiento.f = sigMovimiento.h + sigMovimiento.g;
						sigMovimiento.plan.push_back(actTURN_R);

						abiertos.push(sigMovimiento);

				}
				cerrados.insert(actual.posActual);

		}

	cout<<"Me salgo del bucle"<<endl;
	return false;
}


Action ComportamientoJugador::think(Sensores sensores) {
  if (sensores.mensajeF != -1){
		fil = sensores.mensajeF;
		col = sensores.mensajeC;
	}

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
			cout << "fil: " << fil << "  col: " << col << " Or: " << brujula << endl;
	}

	// Determinar si ha cambiado el destino desde la ultima planificacion
	if (hayPlan and (sensores.destinoF != destino.fila or sensores.destinoC != destino.columna)){
		cout << "El destino ha cambiado\n";
		hayPlan = false;
	}

	// Determinar si tengo que construir un plan
	if (!hayPlan){
		estado origen;
		origen.fila = fil;
		origen.columna = col;
		origen.orientacion = brujula;

		destino.fila = sensores.destinoF;
		destino.columna = sensores.destinoC;

    		hayPlan = pathFinding(origen,destino,plan);
			VisualizaPlan(origen,plan);
	}


	// Ejecutar el plan
	Action sigAccion;
	if (hayPlan and plan.size()>0){
		sigAccion = plan.front();
		if(sigAccion==actFORWARD && sensores.superficie[2]=='a'){
			sigAccion=actIDLE;
		}
		else{
				plan.erase(plan.begin());
		}
	}
	else {
		sigAccion = actIDLE;
	}

	ultimaAccion = sigAccion;
	return sigAccion;
}


void AnularMatriz(vector<vector<unsigned char> > &m){
	for (int i=0; i<m[0].size(); i++){
		for (int j=0; j<m.size(); j++){
			m[i][j]=0;
		}
	}
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

int ComportamientoJugador::interact(Action accion, int valor){
  return false;
}
