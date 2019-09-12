#include "ORev.h"
#include <cmath>


ORev::ORev(){}

ORev::ORev(vector<_vertex3f> perfil, int n){

	Rotar(perfil,n);

}

void ORev::Rotar(vector<_vertex3f> perfil,int n)
{

}

float ORev::GradosARadianes(float Grados)
{
    return (Grados*M_PI)/180.0;
}

