#ifndef DODECAEDRO_OBJ3D_H
#define  DODECAEDRO_OBJ3D_H

#include "obj3dlib/objeto3d.h"

class DodecaedroObj3D : public Objeto3D {

  private:
    void drawSolido();
    void drawSuave();

  public:
    DodecaedroObj3D():Objeto3D(){tieneMalla = true;}
    DodecaedroObj3D(const DodecaedroObj3D& obj):Objeto3D(obj){}
    ~DodecaedroObj3D(){}

    DodecaedroObj3D * clone(){return new DodecaedroObj3D(*this);}

};

#endif
