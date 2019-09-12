#include "modelosPLY.h"

modelosPLY::modelosPLY(){}

modelosPLY::modelosPLY(string ruta){

	_file_ply ply;

	ply.open(ruta);

	ply.read(vertices,caras);

	ply.close();

}
