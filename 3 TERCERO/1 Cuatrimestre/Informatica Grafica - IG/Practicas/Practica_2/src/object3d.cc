/*
* Practicas de IG
* Domingo Martin Perandres© 2014-2018
* dmartin@ugr.es
*
* GPL 3
*/

#include "object3d.h"

using namespace _colors_ne;

_object3D::_object3D(){}; //si no lo pongo no hace referencia object3d
                          //creo que es como un objeto, para poder instanciar las funciones
/***************************************************************************/

/**
*
*@param
*@returns
*/
// void _object3D::draw_line()
// {
//   glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
//   glBegin(GL_TRIANGLES);
//   for (unsigned int i=0;i<Triangles.size();i++){
//     glVertex3fv((GLfloat *) &Vertices[Triangles[i]._0]);
//     glVertex3fv((GLfloat *) &Vertices[Triangles[i]._1]);
//     glVertex3fv((GLfloat *) &Vertices[Triangles[i]._2]);
//   }
//   glEnd();
// }
void _object3D::draw_line()
{
  int Vertice1,Vertice2,Vertice3;

  glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);//Interpreto los triangulos como lineas
  glBegin(GL_TRIANGLES);

  glColor3f(0, 0, 1);
  for (unsigned int i=0;i<Triangles.size();i++){
    Vertice1= Triangles[i]._0;
    glVertex3f(Vertices[Vertice1].x, Vertices[Vertice1].y, Vertices[Vertice1].z);
    Vertice2=Triangles[i]._1;
    glVertex3f(Vertices[Vertice2].x, Vertices[Vertice2].y, Vertices[Vertice2].z);
    Vertice3=Triangles[i]._2;
     glVertex3f(Vertices[Vertice3].x, Vertices[Vertice3].y, Vertices[Vertice3].z);
  }
  glEnd();
}



/**
*
*@param
*@returns
*/
/*************************************DIBUJAR RELLENO**************************************/

void _object3D::draw_fill(bool ajedrez) 
{
    glPointSize(2);
    
     int Vert1,Vert2,Verti3;
    glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);//Interpreto los triangulos como lineas
    glBegin(GL_TRIANGLES);
        for(int i=0;i< Triangles.size();i++)
        {   //Cambio de color para el ajedrez
            if(ajedrez && i %2 == 0)
            { 
              glColor3f(1, 0, 0);//rojo
            }
            else
            {
              glColor3f(0,0,0);//
            }
          Vert1=Triangles[i]._0;//triangulo i, cojo el vertice 0 
          glVertex3f(Vertices[Vert1].x, Vertices[Vert1].y, Vertices[Vert1].z);
          Vert2=Triangles[i]._1;//triangulo i, cojo el vertice 1 
          glVertex3f(Vertices[Vert2].x, Vertices[Vert2].y, Vertices[Vert2].z);
          Verti3=Triangles[i]._2;
          glVertex3f(Vertices[Verti3].x, Vertices[Verti3].y, Vertices[Verti3].z);
        }
    glEnd();

/***************************************************************************/



}
/**
*
*@param
*@returns
*/

// void _object3D::draw_chess()
// {
  
// }
