#ifndef _LETRA_H_
#define _LETRA_H_

#include <map>
#include <istream>

struct Letra{
    int puntos;
    int apariciones;

};

class ConjuntoLetras{
    private:
        map<char,Letra> conjunto;
    public:
        ConjuntoLetras();
        ~ConjuntoLetras();
        pair<char,Letra> getLetra(char clave);
        int getPuntosLetra(char clave);
        int getApariciones(char clave);

        friend istream& operator>>(istream &is, ConjuntoLetras &CL);
        friend ostream& operator<<(ostream &os, const ConjuntoLetras &CL);
};
