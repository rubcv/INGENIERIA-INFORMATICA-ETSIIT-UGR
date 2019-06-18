#include <iostream>
#include <map>



struct datos_piloto{
  string nombre;
  string apellido;
  int posicion;
  string escuderia
}

int main(){

  // Forma mas eficiente:
    map<string, datos_piloto> apellidos; // Un map con todos los datos
    map<string, map<string, datos_piloto>::iterator > datos; // Otro con el dato y map con iterator al map de arriba

}
