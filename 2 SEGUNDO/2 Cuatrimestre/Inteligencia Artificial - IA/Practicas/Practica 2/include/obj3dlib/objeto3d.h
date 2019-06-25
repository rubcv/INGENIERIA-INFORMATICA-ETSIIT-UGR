#ifndef OBJETO3D_H
#define OBJETO3D_H

#include "obj3dlib/vertex.h"
#include <vector>
#include <GL/gl.h>
#include <string.h>

#define Translacion_ 1
#define Escalado_ 2
#define Rotacion_ 3

class Objeto3D {

protected:
    _vertex3<float> posicion;
    _vertex3<float> colores;
    bool tieneMalla = false;

    vector <_vertex3<float> > vertices; //Vector para almacenar los vertices. Un vertice tiene (X,Y,Z)
    vector <_vertex3<unsigned int> > caras; //Vector para almacenar las caras. Una cara tiene (Vertice1, Vertices2, Vertice3)

    vector <_vertex3<float> > normalCaras; //Vector para almacenar la componente normal de cada cara, tiene igual tamaño que el vector de caras
                                           //Cada normal tiene (X,Y,Z) coordenadas cartesianas
    vector <_vertex3<float> > normalVertices; //Vector para almacenar la componente normal de cada vertice, tiene igual tamaño que el vector
                                              // de vertices. Cada normal tiene (X,Y,Z) coordenadas cartesianas

    vector <_vertex4<float> > transformaciones; //Primer elemento es el tipo de transformacion, y el resto los parametros de la misma
                                                //En el caso de una rotacion solo se usa el 2º elemento que indica sobre que eje se rota
                                                // Y el tercero para indicar los grados
    vector <Objeto3D *> hijos; //Vector jerarquico con los hijos del objeto mayor

    //Vectores de Materiales
    _vertex4<float>matAmb;
    _vertex4<float>matSpec;
    _vertex4<float>matDiff;

    void calcularNormales(); //Funcion para calcular los 2 vectores de normales

    //Funciones DRAW varias

    virtual void drawSolido();
    virtual void drawSuave();

    void transformar();

public:

    Objeto3D(){} //Constructor por defecto
    Objeto3D(std::string archivo); //Constructor por parametros
    Objeto3D(const Objeto3D& objeto); //Constructor por copia
    ~Objeto3D(){} //Destructor por defecto

    virtual void draw(int modo);
    void setTranformacion(_vertex4 <float> trans){transformaciones.push_back(trans);}
    void setHijo(Objeto3D * hijo){hijos.push_back(hijo);}
    void setColor( _vertex3<float> color){colores=color;}
    void setPosicion(_vertex3<float> pos){posicion = pos;}
    void setAmb(_vertex4<float> ambien){matAmb = ambien;}
    void setDiff(_vertex4<float> diffus){matDiff = diffus;}
    void setSpec(_vertex4<float> specul){matSpec = specul;}


    virtual Objeto3D * clone(){return new Objeto3D(*this);}








};


#endif // OBJETO3D_H
