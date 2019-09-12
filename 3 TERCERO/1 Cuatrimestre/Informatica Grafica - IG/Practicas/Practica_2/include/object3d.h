/*
* Practicas de IG
* Domingo Martin Perandres© 2014-2018
* dmartin@ugr.es
*
* GPL 3
*/

#ifndef OBJECT3D_H
#define OBJECT3D_H
#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>
#include <vector>
#include "vertex.h"
#include "basic_object3d.h"

using namespace std;

class _object3D : public _basic_object3D
{
  public:
                    // cara
  vector<_vertex3i> Triangles;//Este vector almacena 3 posiciones del vector de vertices en cada casilla, para formar triangulos

  _object3D();//incluyo yo constructor
  void draw_line();
  void draw_fill(bool ajedrez); //incluyo la de ajedrez en la misma
  //void draw_chess();

};

#endif // OBJECT3D_H
