#include "O3d.h"

O3d::O3d(){}

/***************************************************************************/


void O3d::drawLines(){

  int Vertice1,Vertice2,Vertice3;

 glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);//Interpreto los triangulos como lineas

 glBegin(GL_TRIANGLES);

         glColor3f(0, 0, 1);

         for (int i= 0; i < caras.size(); i++){

          Vertice1 = caras[i]._0;
          glVertex3f(vertices[Vertice1].x, vertices[Vertice1].y, vertices[Vertice1].z);
          Vertice2 = caras[i]._1;
          glVertex3f(vertices[Vertice2].x, vertices[Vertice2].y, vertices[Vertice2].z);
          Vertice3 = caras[i]._2;
          glVertex3f(vertices[Vertice3].x, vertices[Vertice3].y, vertices[Vertice3].z);

         }

  glEnd();

}

/***************************************************************************/

void O3d::drawFill(bool ajedrez){

  glPointSize(2);
  glPolygonMode(GL_FRONT_AND_BACK,GL_FILL); //Ahora cambio la interpretacion a relleno

 int Vertice1,Vertice2,Vertice3;

  glBegin(GL_TRIANGLES);

        for (int i= 0; i < caras.size(); i++){
         // Cambio de color para el ajedrez
         if(ajedrez && i %2 == 0){
             glColor3f(1, 0, 0);
           }
         else{
             glColor3f(0, 1, 0);
           }

         Vertice1 = caras[i]._0;
         glVertex3f(vertices[Vertice1].x, vertices[Vertice1].y, vertices[Vertice1].z);
         Vertice2 = caras[i]._1;
         glVertex3f(vertices[Vertice2].x, vertices[Vertice2].y, vertices[Vertice2].z);
         Vertice3 = caras[i]._2;
         glVertex3f(vertices[Vertice3].x, vertices[Vertice3].y, vertices[Vertice3].z);

        }

    glEnd();
}
/***************************************************************************/
