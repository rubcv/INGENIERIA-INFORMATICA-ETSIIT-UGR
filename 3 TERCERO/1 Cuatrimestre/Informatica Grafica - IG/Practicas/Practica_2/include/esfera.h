#ifndef _ESFERA
#define _ESFERA
#include "ORev.h"

using namespace std;

class Esfera : public ORev
{
    public:
        Esfera();

    private:
        _vertex3f RotarZ(_vertex3f p, float angulo);
        vector<_vertex3f> GeneraPerfil(vector<_vertex3f> perfil, int n);


};

#endif