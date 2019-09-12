#ifndef _OREV
#define _OREV

#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>
#include <vector>
#include "vertex.h"
#include "O3ds.h"
#include "O3d.h"

using namespace std;

class ORev : public O3d{

public:

	ORev();

	ORev(vector<_vertex3f> perfil, int n); //llama a la funcion rotar


protected:

	void Rotar(vector<_vertex3f> perfil, int n);
	float GradosARadianes(float Grados);

private:

	_vertex3f RotarY(_vertex3f p, float angulo);

};

#endif
