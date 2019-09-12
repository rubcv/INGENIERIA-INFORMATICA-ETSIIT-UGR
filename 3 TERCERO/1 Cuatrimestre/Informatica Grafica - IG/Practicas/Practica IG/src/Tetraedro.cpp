#include "Tetraedro.h"

Tetraedro::Tetraedro(){

  //VERTICES
  vertices.push_back(_vertex3f(-0.5,-0.5,0.5));//v0
  vertices.push_back(_vertex3f(0.5,-0.5,0.5));//v1
  vertices.push_back(_vertex3f(0,-0.5,-0.5));//v2
  vertices.push_back(_vertex3f(0,0.5,0));//ver. "cuspide"

  /*
            v3
          /    \
         /      \
        v0------v1
  */



  //CARAS
  caras.push_back(_vertex3i(0, 1, 3));
  caras.push_back(_vertex3i(1, 2, 3));
  caras.push_back(_vertex3i(2, 0, 3));
  caras.push_back(_vertex3i(0, 2, 1));

}
