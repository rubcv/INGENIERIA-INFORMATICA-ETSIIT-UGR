#include "cubo.h"

Cubo::Cubo()
{
//Creacion de VERTICES

Vertices.push_back(_vertex3f(-0.5,0.5,0.5));//v0
Vertices.push_back(_vertex3f(0.5,0.5,0.5));//v1
Vertices.push_back(_vertex3f(-0.5,-0.5,0.5));//v2
Vertices.push_back(_vertex3f(0.5,-0.5,0.5));//v3
Vertices.push_back(_vertex3f(-0.5,0.5,-0.5));//v4
Vertices.push_back(_vertex3f(0.5,0.5,-0.5));//v5
Vertices.push_back(_vertex3f(-0.5,-0.5,-0.5));//v6
Vertices.push_back(_vertex3f(0.5,-0.5,-0.5));//v7

/*
             frente         derecha               trasera
            0------1       1------5   //arriba   5------4
            |  \   |       |  \   |              |  \   |
            |    \ |       |   \  |              |   \  |
            2------3       3------7   //abajo    7------6  

             techo         izquierda              suelo
            4------5       4------0  //arriba    2------3   //delante +z
            |  \   |       |  \   |              |  \   |
            |   \  |       |    \ |              |   \  |
            0------1       6------2  //abajo     6------7  //detras  -z
            ___________
           / |        /|
          /  |       / |
         /   |______/__|
        /          /    
        -----------
*/
//Creacion de TRIANGULOS o Caras

  Triangles.push_back(_vertex3i(7,3,2));//Suelo
  Triangles.push_back(_vertex3i(2,6,7));

  Triangles.push_back(_vertex3i(1,3,7));//Lado derecho
  Triangles.push_back(_vertex3i(7,5,1));

  Triangles.push_back(_vertex3i(1,5,4));//Techo
  Triangles.push_back(_vertex3i(4,0,1));

  Triangles.push_back(_vertex3i(2,0,4));//Lado izquierdo
  Triangles.push_back(_vertex3i(4,6,2));

  Triangles.push_back(_vertex3i(6,4,5)); //Trasera
  Triangles.push_back(_vertex3i(5,7,6));

  Triangles.push_back(_vertex3i(3,1,0));//frente
  Triangles.push_back(_vertex3i(0,2,3));
}