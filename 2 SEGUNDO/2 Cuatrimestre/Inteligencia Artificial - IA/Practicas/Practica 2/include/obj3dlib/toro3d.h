#ifndef TORO_OBJ3D_H
#define  TORO_OBJ3D_H

#include "obj3dlib/objeto3d.h"

class ToroObj3D : public Objeto3D {

  private:
    void drawSolido();
    void drawSuave();

  public:
    ToroObj3D():Objeto3D(){tieneMalla = true;}
    ToroObj3D(const ToroObj3D& obj):Objeto3D(obj){}
    ~ToroObj3D(){}

    ToroObj3D * clone(){return new ToroObj3D(*this);}

};

#endif
