#ifndef _O3DS
#define _O3DS

#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>
#include <vector>
#include "vertex.h"

using namespace std;

class O3ds{

  protected:

    vector<_vertex3f> vertices; //Este vector almacena las coordenadas x,y,z(floats) de cada vertice que forma el modelo


  public:

    O3ds();

    void drawPoints();



};



#endif
