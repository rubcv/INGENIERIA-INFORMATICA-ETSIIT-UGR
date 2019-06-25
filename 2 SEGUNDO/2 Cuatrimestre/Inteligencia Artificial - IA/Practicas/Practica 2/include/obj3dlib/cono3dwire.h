#ifndef CONO_OBJ3DWIRE_H
#define  CONO_OBJ3DWIRE_H

#include "obj3dlib/objeto3d.h"

class ConoObj3DWire : public Objeto3D {

  private:
    void drawSolido();
    void drawSuave();

  public:
    ConoObj3DWire():Objeto3D(){tieneMalla = true;}
    ConoObj3DWire(const ConoObj3DWire& obj):Objeto3D(obj){}
    ~ConoObj3DWire(){}

    ConoObj3DWire * clone(){return new ConoObj3DWire(*this);}

};

#endif
