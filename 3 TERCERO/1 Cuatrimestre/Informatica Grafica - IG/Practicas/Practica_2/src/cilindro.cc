#include "cilindro.h"

Cilindro::Cilindro()
{
    vector<_vertex3f> perfil;
    perfil.push_back(_vertex3f(0.0,2.5,0.0));
    perfil.push_back(_vertex3f(2.5,2.5,0.0));
    perfil.push_back(_vertex3f(2.5,-2.5,0.0));
    perfil.push_back(_vertex3f(0.0,-2.5,0.0));

    Rotar(perfil,20);

    //TAMBIEN HAY QUE HACER LAS TAPAS

}