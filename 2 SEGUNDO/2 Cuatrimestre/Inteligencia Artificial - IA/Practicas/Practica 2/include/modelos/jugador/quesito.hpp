#ifndef QUESITO_HPP
#define QUESITO_HPP


#include "obj3dlib.hpp"
#include <string.h>


class Quesito3D : public RevolucionObj3D{
private:

public:
  Quesito3D() : RevolucionObj3D("include/modelos/jugador/linea.ply", 3){}
  ~Quesito3D(){}

};

#endif
