/******************************************************************************
*
* Inteligencia Artificial
* Grado en Ingeniería Informática
*
* 2014 - Ernesto Serrano <erseco@correo.ugr.es>
* -----------------------------------------------------
*
* Codigo fuente del agente
*
******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include "player.h"
#include "environment.h"

using namespace std;

const double masinf=9999999999.0, menosinf=-9999999999.0;


// Constructor
Player::Player(int jug){
	jugador_=jug;
}

// Actualiza el estado del juego para el jugador
void Player::Perceive(const Environment & env){
	actual_=env;
}

double Puntuacion(int jugador, const Environment &estado){
	double suma=0;

	for (int i=0; i<7; i++)
	  for (int j=0; j<7; j++){
		 if (estado.See_Casilla(i,j)==jugador){
			if (j<3)
			   suma += j;
			else
			   suma += (6-j);
		 }
	  }

	return suma;
}




// ------------------- Los tres metodos anteriores no se pueden modificar



int AdyacenteVertical(const Environment &estado, int row, int col, int jugador, int nivel) {
 
	int consecutivas = 0;

	for (int i=row; i<7; i++) {
		if (estado.See_Casilla(i,col) == jugador)
			consecutivas += 1;
		else
			break;
	}

	if (consecutivas >= nivel)
		return 1;
	else
		return 0;

}

int AdyacenteHorizontal(const Environment &estado, int row, int col, int jugador, int nivel) {
 
	int consecutivas = 0;

	for (int j=col; j<7; j++) {
		if (estado.See_Casilla(row,j) == jugador)
			consecutivas += 1;
		else
			break;
	}

	if (consecutivas >= nivel)
		return 1;
	else
		return 0;

}

int AdyacenteDiagonal(const Environment &estado, int row, int col, int jugador, int nivel) {

	int total = 0;

	// Comprobamos los diagonales ascendentes
	double consecutivas = 0;

	int j = col;

	for (int i=row; i<7;i++) {
		if (j > 6) // Control para no pasarnos del maximo de columnas
			break;
		else if (estado.See_Casilla(i,j) == jugador)
			consecutivas += 1;
		else
			break;
		j+=1; // Incrementamos la columna cuando se incrementa la fila
		
	}

	if (consecutivas >= nivel)
		total += 1;

	// Comprobamos los diagonales descendentes
	consecutivas = 0;
	j = col;
	for (int i=row; i>=0; i--) {
		if (j > 6) // Control para no pasarnos del maximo de columnas
			break;
		else if (estado.See_Casilla(i,j) == jugador)
			consecutivas += 1;
		else
			break;
		j+=1; // Incrementamos la columna cuando se decrementa la fila

	}

	if (consecutivas >= nivel)
		total += 1;

	return total;

}


int ComprobarAdyacentes(const Environment &estado, int jugador, int nivel) {

	int count = 0;

	// Para cada ficha del tablero...
	for (int i=0; i<7;i++) { 
		for (int j=0; j<7;j++) { 

			// ...si es del color del jugador...
			if (estado.See_Casilla(i,j) == jugador) {
				// Comprueba los verticales de la columna
				count += AdyacenteVertical(estado, i, j, jugador, nivel);
				
				// Comprueba los horizontales de la fila
				count += AdyacenteHorizontal(estado, i, j, jugador, nivel);
				
				// Comprueba los diagonales (los dos tipos)
				count += AdyacenteDiagonal(estado, i, j, jugador, nivel);
			}
		}
	}

	// Devolvemos la suma de los adyacentes encontrados para el "nivel"
	return count;

}


// Funcion heuristica (ESTA ES LA QUE TENEIS QUE MODIFICAR)
double Valoracion(const Environment &estado, int jugador){

	// La valoracion es un número resultante de la suma de:
	// total de 4 en raya * 1000000) + total de 3 en raya * 100 + total de 2 en raya * 10
	// al que le restamos:
	// total de 4 en raya del opuesto * 10000000, el total de 3 en raya del opuesto * 100 y el total de 2 en raya del opuesto * 10

	// Obtenemos el judador opuesto
	int jugador_opuesto = 1;
	if (jugador == 1) 
		jugador_opuesto = 2;

	// Comprobamos los adyacentes del jugador actual
	int cuatros = ComprobarAdyacentes(estado, jugador, 4);
	int treses =  ComprobarAdyacentes(estado, jugador, 3);
	int doses =   ComprobarAdyacentes(estado, jugador, 2);
	
	// Comprobamos los adyacentes del jugador opuesto
	int cuatros_opuesto = ComprobarAdyacentes(estado, jugador_opuesto, 4);
	int treses_opuesto =  ComprobarAdyacentes(estado, jugador_opuesto, 3);
	int doses_opuesto =   ComprobarAdyacentes(estado, jugador_opuesto, 2);

	// Calculamos el valor heurístico del tablero
	//return (cuatros*100000 + treses*100 + doses*10);
	//return (cuatros*100000 + treses*100 + doses*10 + unos);
	return (((cuatros*1000000 + treses*100 + doses*10) - cuatros_opuesto*10000000) - treses_opuesto*100) - doses_opuesto*10;

}


// Funcion de valoracion para testear Poda Alfabeta
double ValoracionTest(const Environment &estado, int jugador){

	// Devolvemos la valoración de nuestra heurística
	return Valoracion(estado, jugador);

	// AQUI NO ENTRA PORQUE ME LO SALTO CON MI HEURISTICA!!!

	int ganador = estado.RevisarTablero();

	if (ganador==jugador)
	   return 99999999.0; // Gana el jugador que pide la valoracion
	else if (ganador!=0)
		return -99999999.0; // Pierde el jugador que pide la valoracion
	else if (estado.Get_Casillas_Libres()==0)
		return 0;  // Hay un empate global y se ha rellenado completamente el tablero
	else
		return Puntuacion(jugador,estado);
}


// Esta funcion no se puede usar en la version entregable
// Aparece aqui solo para ILUSTRAR el comportamiento del juego
// ESTO NO IMPLEMENTA NI MINIMAX, NI PODA ALFABETA
void JuegoAleatorio(bool aplicables[], int opciones[], int &j){
	j=0;
	for (int i=0; i<7; i++){
		if (aplicables[i]){
		   opciones[j]=i;
		   j++;
		}
	}
}






// Invoca el siguiente movimiento del jugador
Environment::ActionType Player::Think(){
	const int PROFUNDIDAD_MINIMAX = 6;  // Umbral maximo de profundidad para el metodo MiniMax
	const int PROFUNDIDAD_ALFABETA = 8; // Umbral maximo de profundidad para la poda Alfa_Beta

	Environment::ActionType accion; // acción que se va a devolver
	bool aplicables[7]; // Vector bool usado para obtener las acciones que son aplicables en el estado actual. La interpretacion es
						// aplicables[0]==true si PUT1 es aplicable
						// aplicables[1]==true si PUT2 es aplicable
						// aplicables[2]==true si PUT3 es aplicable
						// aplicables[3]==true si PUT4 es aplicable
						// aplicables[4]==true si PUT5 es aplicable
						// aplicables[5]==true si PUT6 es aplicable
						// aplicables[6]==true si PUT7 es aplicable



	double valor; // Almacena el valor con el que se etiqueta el estado tras el proceso de busqueda.
	double alpha, beta; // Cotas de la poda AlfaBeta

	int n_act; //Acciones posibles en el estado actual


	n_act = actual_.possible_actions(aplicables); // Obtengo las acciones aplicables al estado actual en "aplicables"
	int opciones[10];

	// Muestra por la consola las acciones aplicable para el jugador activo
	cout << " Acciones aplicables ";
	(jugador_==1) ? cout << "Verde: " : cout << "Azul: ";
	for (int t=0; t<7; t++)
	  if (aplicables[t])
		 cout << " " << actual_.ActionStr( static_cast< Environment::ActionType > (t)  );
	cout << endl;


	//--------------------- COMENTAR Desde aqui
	// cout << "\n\t";
	// int n_opciones=0;
	// JuegoAleatorio(aplicables, opciones, n_opciones);

	// if (n_act==0){
	//   (jugador_==1) ? cout << "Verde: " : cout << "Azul: ";
	//   cout << " No puede realizar ninguna accion!!!\n";
	//   //accion = Environment::actIDLE;
	// }
	// else if (n_act==1){
	//        (jugador_==1) ? cout << "Verde: " : cout << "Azul: ";
	//         cout << " Solo se puede realizar la accion "
	//              << actual_.ActionStr( static_cast< Environment::ActionType > (opciones[0])  ) << endl;
	//         accion = static_cast< Environment::ActionType > (opciones[0]);
	//      }
	//      else { // Hay que elegir entre varias posibles acciones
	//         int aleatorio = rand()%n_opciones;
	//         cout << " -> " << actual_.ActionStr( static_cast< Environment::ActionType > (opciones[aleatorio])  ) << endl;
	//         accion = static_cast< Environment::ActionType > (opciones[aleatorio]);
	//      }
	//--------------------- COMENTAR Hasta aqui


	//--------------------- AQUI EMPIEZA LA PARTE A REALIZAR POR EL ALUMNO ------------------------------------------------

	// Truquillo para que si somos los primeros en tirar (esta todo a 0)
	// nos coloque la ficha en el medio
	if (actual_.See_Casilla(0,0) == 0 &&
	  actual_.See_Casilla(0,1) == 0 &&
	  actual_.See_Casilla(0,2) == 0 &&
	  actual_.See_Casilla(0,3) == 0 &&
	  actual_.See_Casilla(0,4) == 0 &&
	  actual_.See_Casilla(0,5) == 0 &&
	  actual_.See_Casilla(0,6) == 0) 
	{
	  cout << "ES LA PRIMERA TIRADA" << endl;
	  return Environment::PUT4;

	}

	contador = 0;

	// Pruebas de algoritmos (con la misma profundidad)
	//valor = MiniMax(actual_, jugador_, 0, PROFUNDIDAD_MINIMAX, accion);
	//valor = AlfaBeta(actual_, jugador_, 0, PROFUNDIDAD_MINIMAX, accion, INF_DOWN, INF_TOP);
	//valor = NegaMax(actual_, jugador_, 0, PROFUNDIDAD_MINIMAX, accion);
	//valor = NegaMaxAlfaBeta(actual_, jugador_, 0, PROFUNDIDAD_MINIMAX, accion, INF_DOWN, INF_TOP);
	//valor = NegaScout(actual_, jugador_, 0, PROFUNDIDAD_MINIMAX, accion, INF_DOWN, INF_TOP);

	// Algoritmos con poda y la profundidad máxima permitida
	valor = AlfaBeta(actual_, jugador_, 0, PROFUNDIDAD_ALFABETA, accion, INF_DOWN, INF_TOP);
	//valor = NegaMaxAlfaBeta(actual_, jugador_, 0, PROFUNDIDAD_ALFABETA, accion, INF_DOWN, INF_TOP);
	//valor = NegaScout(actual_, jugador_, 0, PROFUNDIDAD_ALFABETA, accion, INF_DOWN, INF_TOP);

	cout << "Numero nodos evaluados: " << contador << endl;


	// Opcion: Poda AlfaBeta
	// NOTA: La parametrizacion es solo orientativa
	// valor = Poda_AlfaBeta(actual_, jugador_, 0, PROFUNDIDAD_ALFABETA, accion, alpha, beta);
	// cout << "Valor MiniMax: " << valor << "  Accion: " << actual_.ActionStr(accion) << endl;

	return accion;
}


/******************************************************************************/
//  ------     AQUI EMPIEZAN MIS ALGORITMOS   -----------

/******************************************************************************/
// Implementación del algoritmo Minimax
double Player::MiniMax(const Environment & tablero, int jugador, int profundidad, int profundidad_maxima, Environment::ActionType & accion) {

	contador++; // Contador para comprobar el numero de nodos comprobados


  // Atributos
  Environment::ActionType accion_anterior;
  double mejor, aux;

  bool opciones[7];
  int n_act = tablero.possible_actions(opciones); // Determino cuantas acciones se pueden realizar
  
  if (profundidad==profundidad_maxima || n_act==0){ // Hemos llegado al nodo final o no hay mas acciones

	  return ValoracionTest(tablero, jugador);

  } else { // Vamos a recorrer los hijos

	int ult_act=-1;
	Environment hijo = tablero.GenerateNextMove(ult_act); // Genero el siguiente tablero hijo

	if (profundidad%2==0) { //Nodo MAX

	  mejor = INF_DOWN; // Inicializar al minimo

	  while (!(hijo==tablero)){ // Recorro los hijos (cuando sea igual al parametro es que ha terminado)

		aux = MiniMax(hijo, jugador, profundidad+1, profundidad_maxima, accion_anterior); 

		if (aux>mejor){
		  mejor=aux;
		  accion = static_cast <Environment::ActionType > (ult_act); // Este es el movimiento que hay que arrastrar
		}


		hijo = tablero.GenerateNextMove(ult_act); // Genero el siguiente tablero hijo
	  }

	  return mejor;

	} else { //Nodo MIN

	  mejor = INF_TOP;  // Inicializar al maximo

	  while (!(hijo==tablero)){ // Recorro los hijos (cuando sea igual al parametro es que ha terminado)

		aux = MiniMax(hijo, jugador, profundidad+1, profundidad_maxima, accion_anterior); 

		if (aux<mejor){
		  mejor=aux;
		  accion = static_cast <Environment::ActionType > (ult_act); // Este es el movimiento que hay que arrastrar
		}

		hijo = tablero.GenerateNextMove(ult_act); // Genero el siguiente tablero hijo
	  }

	  return mejor;

	}

  }

}

/******************************************************************************/
// Implementación de la poda alfa-beta (la que se pide en la práctica)
double Player::AlfaBeta(const Environment & tablero, int jugador, int profundidad, int profundidad_maxima, Environment::ActionType & accion, double alfa, double beta) {


	contador++; // Contador para comprobar el numero de nodos comprobados


	// Atributos
	Environment::ActionType accion_anterior;
	double aux;

	bool opciones[7];
	int n_act = tablero.possible_actions(opciones); // Determino cuantas acciones se pueden realizar

	if (profundidad==profundidad_maxima || n_act==0){ // Hemos llegado al nodo final o no hay mas acciones

		return ValoracionTest(tablero, jugador);

	} else { // Vamos a recorrer los hijos

		int ult_act=-1;
		Environment hijo = tablero.GenerateNextMove(ult_act); // Genero el siguiente tablero hijo

		if (profundidad%2==0) { //Nodo MAX

				while (!(hijo==tablero)){ // Recorro los hijos (cuando sea igual al parametro es que ha terminado)

				aux = AlfaBeta(hijo, jugador, profundidad+1, profundidad_maxima, accion_anterior, alfa, beta); 

				if (aux>alfa){
					alfa=aux;
					accion = static_cast <Environment::ActionType > (ult_act); // Este es el movimiento que hay que arrastrar
				}

				if (beta<=alfa) {
					break; // Poda beta

				}


				hijo = tablero.GenerateNextMove(ult_act); // Genero el siguiente tablero hijo
			}

		  return alfa;

		} else { //Nodo MIN

			while (!(hijo==tablero)){ // Recorro los hijos (cuando sea igual al parametro es que ha terminado)

				aux = AlfaBeta(hijo, jugador, profundidad+1, profundidad_maxima, accion_anterior, alfa, beta); 

				if (aux<beta){
				  beta=aux;
				  accion = static_cast <Environment::ActionType > (ult_act); // Este es el movimiento que hay que arrastrar
				}

				if (beta<=alfa) {
				  break; // Poda alfa

				}

				hijo = tablero.GenerateNextMove(ult_act); // Genero el siguiente tablero hijo
			}

		  return beta;

		}

	}

}

/******************************************************************************/
// Implementación del algoritmo Negamax
double Player::NegaMax(const Environment & tablero, int jugador, int profundidad, int profundidad_maxima, Environment::ActionType & accion) {

	contador++; // Contador para comprobar el numero de nodos comprobados


  // Atributos
  Environment::ActionType accion_anterior;
  double mejor, aux;
  bool opciones[7];
  int n_act = tablero.possible_actions(opciones); // Determino cuantas acciones se pueden realizar
  
  if (profundidad==profundidad_maxima || n_act==0){ // Hemos llegado al nodo final o no hay mas acciones

	  return ValoracionTest(tablero, jugador);

  } else { // Vamos a recorrer los hijos

	int ult_act=-1;
	Environment hijo = tablero.GenerateNextMove(ult_act); // Genero el siguiente tablero hijo

	mejor = INF_DOWN; // Inicializar al minimo

	while (!(hijo==tablero)){ // Recorro los hijos (cuando sea igual al parametro es que ha terminado)

	  aux = -NegaMax(hijo, jugador, profundidad+1, profundidad_maxima, accion_anterior); 

	  if (aux>mejor){
		mejor=aux;
		accion = static_cast <Environment::ActionType > (ult_act); // Este es el movimiento que hay que arrastrar
	  }

	  hijo = tablero.GenerateNextMove(ult_act); // Genero el siguiente tablero hijo
	}

	return mejor;

  }

}

/******************************************************************************/
// Implementación del algoritmo Negamax con poda alfa-beta
double Player::NegaMaxAlfaBeta(const Environment & tablero, int jugador, int profundidad, int profundidad_maxima, Environment::ActionType & accion, double alfa, double beta) {

	contador++; // Contador para comprobar el numero de nodos comprobados


  // Atributos
  Environment::ActionType accion_anterior;
  double aux;
  bool opciones[7];
  int n_act = tablero.possible_actions(opciones); // Determino cuantas acciones se pueden realizar
  
  if (profundidad==profundidad_maxima || n_act==0){ // Hemos llegado al nodo final o no hay mas acciones

	  return ValoracionTest(tablero, jugador);

  } else { // Vamos a recorrer los hijos

	int ult_act=-1;
	Environment hijo = tablero.GenerateNextMove(ult_act); // Genero el siguiente tablero hijo

	double mejor = INF_DOWN;

	while (!(hijo==tablero)){ // Recorro los hijos (cuando sea igual al parametro es que ha terminado)

	  aux = -NegaMaxAlfaBeta(hijo, jugador, profundidad+1, profundidad_maxima, accion_anterior, -beta, -alfa); 
		
	  if (aux > mejor) {
		mejor = aux;
		accion = static_cast <Environment::ActionType > (ult_act); // Este es el movimiento que hay que arrastrar

	  }

	  if (aux > alfa) {
		alfa = aux;
	  }
	

	  if( alfa >= beta ) {
		break; // Poda beta

	  }

	  hijo = tablero.GenerateNextMove(ult_act); // Genero el siguiente tablero hijo
	}

	return mejor;

  }

}

/******************************************************************************/
// Implementación del algoritmo Negascout
double Player::NegaScout(const Environment & tablero, int jugador, int profundidad, int profundidad_maxima, Environment::ActionType & accion, double alfa, double beta) {

	contador++; // Contador para comprobar el numero de nodos comprobados


  // Atributos
  Environment::ActionType accion_anterior;
  double mejor, aux;
  bool opciones[7];
  int n_act = tablero.possible_actions(opciones); // Determino cuantas acciones se pueden realizar
  
  if (profundidad==profundidad_maxima || n_act==0){ // Hemos llegado al nodo final o no hay mas acciones

	  return ValoracionTest(tablero, jugador);

  } else { // Vamos a recorrer los hijos

	int ult_act=-1;
	Environment hijo = tablero.GenerateNextMove(ult_act); // Genero el siguiente tablero hijo

	bool primero = true;

	while (!(hijo==tablero)) { // Recorro los hijos (cuando sea igual al parametro es que ha terminado)

		if (primero) {
			primero = false;
		
			aux = -NegaScout(hijo, jugador, profundidad+1, profundidad_maxima, accion_anterior, -beta, -alfa); 

		} else {

			aux = -NegaScout(hijo, jugador, profundidad+1, profundidad_maxima, accion_anterior, -alfa-1, -alfa); //* search with a null window *)

			if (alfa < aux && aux < beta) {// (* if it failed high, do a full re-search
				aux = -NegaScout(hijo, jugador, profundidad+1, profundidad_maxima, accion_anterior, -beta, -aux); 
			}
		}

		if (aux > alfa) {
			alfa = aux;
			accion = static_cast <Environment::ActionType > (ult_act); // Este es el movimiento que hay que arrastrar
		}

		if (alfa >= beta){
			break; // Poda beta
		}

		hijo = tablero.GenerateNextMove(ult_act); // Genero el siguiente tablero hijo
	}

	return alfa;

  }

}
