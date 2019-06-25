#ifndef TETRAEDRO_OBJ3D_H
#define  TETRAEDRO_OBJ3D_H

#include "obj3dlib/objeto3d.h"

class TetraedroObj3D : public Objeto3D {

  private:
    void drawSolido();
    void drawSuave();

  public:
    TetraedroObj3D():Objeto3D(){tieneMalla = true;}
    TetraedroObj3D(const TetraedroObj3D& obj):Objeto3D(obj){}
    ~TetraedroObj3D(){}

    TetraedroObj3D * clone(){return new TetraedroObj3D(*this);}

};

#endif
