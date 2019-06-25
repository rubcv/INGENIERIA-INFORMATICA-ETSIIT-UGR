#ifndef CONO_OBJ3D_H
#define  CONO_OBJ3D_H

#include "obj3dlib/objeto3d.h"

class ConoObj3D : public Objeto3D {

  private:
    void drawSolido();
    void drawSuave();

  public:
    ConoObj3D():Objeto3D(){tieneMalla = true;}
    ConoObj3D(const ConoObj3D& obj):Objeto3D(obj){}
    ~ConoObj3D(){}

    ConoObj3D * clone(){return new ConoObj3D(*this);}

};

#endif
