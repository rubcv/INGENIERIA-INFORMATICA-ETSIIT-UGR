/*
* Practicas de IG
* Domingo Martin Perandres© 2014-2018
* dmartin@ugr.es
*
* GPL 3
*/

#include "basic_object3d.h"

_basic_object3D::_basic_object3D(){} //incluyo yo
/**************************************************************************/

void _basic_object3D::draw_point()
{
  glPointSize(4);
  glColor3f(0,0,0);
  glBegin(GL_POINTS);
  for (unsigned int i=0;i<Vertices.size();i++){
    glVertex3f(Vertices[i].x,Vertices[i].y,Vertices[i].z);
  }
  glEnd();
}

// void _basic_object3D::draw_point()
// {
//   glBegin(GL_POINTS);
//   for (unsigned int i=0;i<Vertices.size();i++){
//     glVertex3fv((GLfloat *) &Vertices[i]);
//   }
//   glEnd();
// }

