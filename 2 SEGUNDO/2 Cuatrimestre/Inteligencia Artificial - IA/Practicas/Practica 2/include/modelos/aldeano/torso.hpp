#ifndef TORSOALDEANO3D_HPP
#define TORSOALDEANO3D_HPP

#include "obj3dlib.hpp"
#include "modelos/aldeano/cabeza.hpp"
#include "modelos/aldeano/brazo.hpp"
#include "modelos/aldeano/cintura.hpp"
#include <string.h>


class TorsoAldeano3D : public Objeto3D{
private:

public:
  TorsoAldeano3D(const std::string & filename);
  ~TorsoAldeano3D();

};

#endif
