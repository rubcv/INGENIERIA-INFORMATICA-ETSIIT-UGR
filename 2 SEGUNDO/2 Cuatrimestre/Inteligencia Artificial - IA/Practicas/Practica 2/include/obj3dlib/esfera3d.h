#ifndef ESFERA_OBJ3D_H
#define  ESFERA_OBJ3D_H

#include "obj3dlib/objeto3d.h"

class EsferaObj3D : public Objeto3D {

  private:
    void drawSolido();
    void drawSuave();

  public:
    EsferaObj3D():Objeto3D(){tieneMalla = true;}
    EsferaObj3D(const EsferaObj3D& obj):Objeto3D(obj){}
    ~EsferaObj3D(){}

    EsferaObj3D * clone(){return new EsferaObj3D(*this);}

};

#endif
