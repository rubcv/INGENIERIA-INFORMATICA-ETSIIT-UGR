#ifndef LUZ_H
#define LUZ_H

#endif // LUZ_H
#include "obj3dlib/objeto3d.h"
#include<GL/gl.h>

class Luz : public Objeto3D{
private:
  GLenum nLuz;
  bool encendida = false;

public:
    Luz(GLenum numero) : Objeto3D(), nLuz(numero){}
    ~Luz(){};
    void encender(){encendida = true;}
    void apagar(){encendida = false;}
    void draw();

};
