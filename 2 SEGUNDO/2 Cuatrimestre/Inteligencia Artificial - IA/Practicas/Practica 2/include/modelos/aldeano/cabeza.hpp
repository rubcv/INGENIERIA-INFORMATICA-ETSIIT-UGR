#ifndef CABEZAAldeano3D_HPP
#define CABEZAAldeano3D_HPP

#include "obj3dlib.hpp"
#include "modelos/retrato.hpp"
#include <string.h>


class CabezaAldeano3D : public Objeto3D{
private:

public:
  CabezaAldeano3D(const std::string & filename);
  ~CabezaAldeano3D();

};

#endif
