#include "Esfera.h"

Esfera::Esfera()
{
    vector<_vertex3f> perfil;
    perfil.push_back(_vertex3f(3.0,0.0,0.0));

    perfil = GeneraPerfil(perfil,10);

  Rotar(perfil,10);

}
//EXPLIQUE
vertex3f Esfera::RotarZ(_vertex3f p, float angulo){
	_vertex3f rotado;
	rotado.x = -sin(angulo)*p.x + cos(angulo)*p.y;
	rotado.y = cos(angulo)*p.x + sin(angulo)*p.y;
	rotado.z = p.z;

	return rotado;
}

vector<_vertex3f> Esfera::GeneraPerfil(vector<_vertex3f> perfil, int n)
{
    
}




