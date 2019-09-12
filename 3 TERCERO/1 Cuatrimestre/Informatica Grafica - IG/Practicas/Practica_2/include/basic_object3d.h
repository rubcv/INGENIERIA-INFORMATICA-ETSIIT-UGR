/*
* Practicas de IG
* Domingo Martin Perandres© 2014-2018
* dmartin@ugr.es
*
* GPL 3
*/

#ifndef BASIC_OBJECT3D_H
#define BASIC_OBJECT3D_H

#include <vector>
#include <GL/gl.h>
#include "colors.h"
#include <GL/glut.h> //incluyo yo
#include "vertex.h"

using namespace std;

class _basic_object3D
{
  public:
  vector<_vertex3f> Vertices;

  _basic_object3D();//incluyo yo constructor

  void draw_point();
};

#endif
