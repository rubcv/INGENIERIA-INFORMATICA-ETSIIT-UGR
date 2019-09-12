#ifndef _ESFERA
#define _ESFERA


#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>
#include <vector>
#include "vertex.h"
#include "O3ds.h"
#include "O3d.h"
#include "ORev.h"

using namespace std;

class Esfera : public ORev{

  public:

    Esfera();

  private:

    _vertex3f RotarZ(_vertex3f p, float angulo);
    vector<_vertex3f> GeneraPerfil(vector<_vertex3f> perfil, int n);



};

#endif
