#include "../Comportamientos_Jugador/aldeano.hpp"
#include "motorlib/util.h"

Action ComportamientoAldeano::think(Sensores sensores) {
  Action accion = actIDLE;

/*  // Aldeano basico
  switch (paso){
      case 0: accion = actFORWARD;
              break;
      case 1: accion = actTURN_R;
	      break;
  }
  paso = (paso+1)%2;*/

  // Aldeano comun
  int cual = aleatorio(8);
  switch (cual) {
	case 0: accion = actIDLE; break;
	case 1: accion = actTURN_L; break;
	case 2: accion = actTURN_R; break;
	case 3: case 4: case 5: case 6: case 7: 
		if (sensores.terreno[2] != 'j') accion = actFORWARD;
		break;
  }

  return accion;
}

int ComportamientoAldeano::interact(Action accion, int valor) {
    return 0;
}
