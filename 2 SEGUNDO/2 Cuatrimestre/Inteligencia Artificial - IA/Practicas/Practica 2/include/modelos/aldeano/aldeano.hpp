#ifndef ALDEANO3D_HPP
#define ALDEANO3D_HPP

#include "modelos/aldeano/torso.hpp"
#include "obj3dlib.hpp"
#include <string.h>


class Aldeano3D : public Objeto3D{
private:

public:
  Aldeano3D(const std::string & filename);
  ~Aldeano3D();

};

#endif
