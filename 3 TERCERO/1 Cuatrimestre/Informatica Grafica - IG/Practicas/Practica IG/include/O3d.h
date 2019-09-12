#ifndef _O3D
#define _O3D

#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>
#include <vector>
#include "vertex.h"
#include "O3ds.h"

using namespace std;

class O3d : public O3ds{

  protected:

      vector<_vertex3i> caras;//Este vector almacena 3 posiciones del vector de vertices en cada casilla, para formar triangulos

  public:

    O3d();

    void drawLines();
    void drawFill(bool ajedrez);


};



#endif
