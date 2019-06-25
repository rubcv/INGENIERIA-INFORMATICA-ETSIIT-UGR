#ifndef RETRATO_HPP
#define RETRATO_HPP


#include "obj3dlib.hpp"
#include <string.h>


class Retrato3D : public Objeto3D{
private:
  jpg::Imagen img;
  vector <_vertex2<float> > coordenadasText;
public:
  Retrato3D(const std::string & filename);
  ~Retrato3D(){}

  void draw(int modo);

};

#endif
