#ifndef ICOSAEDRO_OBJ3D_H
#define  ICOSAEDRO_OBJ3D_H

#include "obj3dlib/objeto3d.h"

class IcosaedroObj3D : public Objeto3D {

  private:
    void drawSolido();
    void drawSuave();

  public:
    IcosaedroObj3D():Objeto3D(){tieneMalla = true;}
    IcosaedroObj3D(const IcosaedroObj3D& obj):Objeto3D(obj){}
    ~IcosaedroObj3D(){}

    IcosaedroObj3D * clone(){return new IcosaedroObj3D(*this);}

};

#endif
