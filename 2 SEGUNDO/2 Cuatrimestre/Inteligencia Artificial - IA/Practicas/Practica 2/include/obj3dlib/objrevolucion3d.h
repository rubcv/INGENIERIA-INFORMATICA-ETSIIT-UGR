#ifndef REVOLUCION_OBJ3D_H
#define  REVOLUCION_OBJ3D_H

#include "obj3dlib/objeto3d.h"

class RevolucionObj3D : public Objeto3D {

  public:
    RevolucionObj3D(std::string archivo, unsigned nCortes);
    RevolucionObj3D(const RevolucionObj3D& obj):Objeto3D(obj){}
    ~RevolucionObj3D(){}

    RevolucionObj3D * clone(){return new RevolucionObj3D(*this);}

};

#endif
