#ifndef OCTAEDRO_OBJ3D_H
#define  OCTAEDRO_OBJ3D_H

#include "obj3dlib/objeto3d.h"

class OctaedroObj3D : public Objeto3D {

  private:
    void drawSolido();
    void drawSuave();

  public:
    OctaedroObj3D():Objeto3D(){tieneMalla = true;}
    OctaedroObj3D(const OctaedroObj3D& obj):Objeto3D(obj){}
    ~OctaedroObj3D(){}

    OctaedroObj3D * clone(){return new OctaedroObj3D(*this);}

};

#endif
