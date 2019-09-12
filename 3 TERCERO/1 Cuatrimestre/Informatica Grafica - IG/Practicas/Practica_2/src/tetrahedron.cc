/*
* Practicas de IG
* Domingo Martin Perandres© 2014-2018
* dmartin@ugr.es
*
* GPL 3
*/

#include "tetrahedron.h"

/**
*
*@param
*@returns
*/
_tetrahedron::_tetrahedron(){

 //VERTICES
  Vertices.push_back(_vertex3f(-0.5,-0.5,0.5));//v0
  Vertices.push_back(_vertex3f(0.5,-0.5,0.5));//v1
  Vertices.push_back(_vertex3f(0,-0.5,-0.5));//v2
  Vertices.push_back(_vertex3f(0,0.5,0));//ver. "cuspide"

  /*
            v3
          /    \
         /      \
        v0------v1
  */



  //CARAS
  Triangles.push_back(_vertex3i(0, 1, 3));
  Triangles.push_back(_vertex3i(1, 2, 3));
  Triangles.push_back(_vertex3i(2, 0, 3));
  Triangles.push_back(_vertex3i(0, 2, 1));

}
// Tetraedro::Tetraedro(float Size)
// {
//   //VERTICES
//   Vertices.resize(4);

//   Vertices[0]=_vertex3f(-Size/2,-Size/2,-Size/2);
//   Vertices[1]=_vertex3f(0,-Size/2,Size/2);
//   Vertices[2]=_vertex3f(Size/2,-Size/2,-Size/2);
//   Vertices[3]=_vertex3f(0,Size/2,0);

// // CARAS
//   Triangles.resize(4);

//   Triangles[0]=_vertex3ui(0,1,3);
//   Triangles[1]=_vertex3ui(1,2,3);
//   Triangles[2]=_vertex3ui(2,0,3);
//   Triangles[3]=_vertex3ui(0,2,1);
// }

