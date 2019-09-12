#include "Cubo.h"

Cubo::Cubo(){

  //Creacion de los VERTICES
  vertices.push_back(_vertex3f(-0.5,0.5,0.5));//v0
  vertices.push_back(_vertex3f(0.5,0.5,0.5));//v1
  vertices.push_back(_vertex3f(-0.5,-0.5,0.5));//v2
  vertices.push_back(_vertex3f(0.5,-0.5,0.5));//v3
  vertices.push_back(_vertex3f(-0.5,0.5,-0.5));//v4
  vertices.push_back(_vertex3f(0.5,0.5,-0.5));//v5
  vertices.push_back(_vertex3f(-0.5,-0.5,-0.5));//v6
  vertices.push_back(_vertex3f(0.5,-0.5,-0.5));//v7

/*
             frente         derecha      trasera
            0------1       1------5     5------4
            |  \   |       |  \   |     |  \   |
            |    \ |       |   \  |     |   \  |
            2------3       3------7     7------6

             techo         izquierda     suelo
            4------5       4------0     2------3
            |  \   |       |  \   |     |  \   |
            |   \  |       |    \ |     |   \  |
            0------1       6------2     6------7

*/
  //Creacion de las CARAS --> Respecto al esquema anterior

  caras.push_back(_vertex3i(7,3,2));//Suelo
  caras.push_back(_vertex3i(2,6,7));

  caras.push_back(_vertex3i(1,3,7));//Lado derecho
  caras.push_back(_vertex3i(7,5,1));

  caras.push_back(_vertex3i(1,5,4));//Techo
  caras.push_back(_vertex3i(4,0,1));

  caras.push_back(_vertex3i(2,0,4));//Lado izquierdo
  caras.push_back(_vertex3i(4,6,2));

  caras.push_back(_vertex3i(6,4,5)); //Trasera
  caras.push_back(_vertex3i(5,7,6));

  caras.push_back(_vertex3i(3,1,0));//frente
  caras.push_back(_vertex3i(0,2,3));


}
