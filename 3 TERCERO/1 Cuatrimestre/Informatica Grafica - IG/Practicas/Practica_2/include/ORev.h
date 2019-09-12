#ifndef _OREV
#define _OREV

#include "object3d.h"

using namespace std;

class ORev: public _object3D
{
    public:
        ORev();// _rotacion();
        ORev(vector<_vertex3f> perfil, int n); //llama a la funcion rotar
    //void  parametros(vector<_vertex3f> perfil1, int num1);
    // vector<_vertex3f> perfil; 
    // int num;

    protected:
        void Rotar(vector<_vertex3f> perfil, int n);
        float GradosARadianes(float Grados);
        
    private:
        _vertex3f RotarY(_vertex3f p,float angulo);

};


#endif