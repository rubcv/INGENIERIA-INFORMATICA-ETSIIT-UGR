#ifndef CUBO_OBJ3D_H
#define  CUBO_OBJ3D_H

#include "obj3dlib/objeto3d.h"

class CuboObj3D : public Objeto3D {

  private:
    void drawSolido();
    void drawSuave();

  public:
    CuboObj3D():Objeto3D(){tieneMalla = true;}
    CuboObj3D(const CuboObj3D& obj):Objeto3D(obj){}
    ~CuboObj3D(){}

    CuboObj3D * clone(){return new CuboObj3D(*this);}

};

#endif
