/******************************************************************************
*
* Inteligencia Artificial
* Grado en Ingeniería Informática
*
* 2014 - Ernesto Serrano <erseco@correo.ugr.es>
* -----------------------------------------------------
*
* Cabecera del agente
*
******************************************************************************/
#ifndef PLAYER_H
#define PLAYER_H

#include "environment.h"

class Player{
public:
	Player(int jug);
	Environment::ActionType Think();
	void Perceive(const Environment &env);
private:
	int jugador_;
	Environment actual_;

	// Atributos					   
	const double INF_TOP =   9999999999.0; // +infinito
	const double INF_DOWN = -9999999999.0; // -infinito

	double contador;

	// Métodos
	double MiniMax(const Environment & tablero, int jugador, int profundidad, int profundidad_maxima, Environment::ActionType & accion);
	double AlfaBeta(const Environment & tablero, int jugador, int profundidad, int profundidad_maxima, Environment::ActionType & accion, double alfa, double beta);
	double NegaMax(const Environment & tablero, int jugador, int profundidad, int profundidad_maxima, Environment::ActionType & accion);
	double NegaMaxAlfaBeta(const Environment & tablero, int jugador, int profundidad, int profundidad_maxima, Environment::ActionType & accion, double alfa, double beta);
	double NegaScout(const Environment & tablero, int jugador, int profundidad, int profundidad_maxima, Environment::ActionType & accion, double alfa, double beta);


};
#endif
