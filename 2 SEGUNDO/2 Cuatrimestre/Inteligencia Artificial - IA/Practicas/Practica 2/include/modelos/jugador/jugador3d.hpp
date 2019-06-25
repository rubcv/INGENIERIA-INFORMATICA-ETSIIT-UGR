#ifndef JUGADOR3D_HPP
#define JUGADOR3D_HPP

#include "modelos/jugador/quesito.hpp"
#include "modelos/retrato.hpp"
#include "obj3dlib.hpp"
#include <string.h>


class Jugador3D : public Objeto3D {
private:

public:
  Jugador3D(const std::string & filename);
  ~Jugador3D();

};

#endif
