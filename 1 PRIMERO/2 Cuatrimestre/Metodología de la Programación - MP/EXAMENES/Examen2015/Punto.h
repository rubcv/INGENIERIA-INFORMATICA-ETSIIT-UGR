#ifndef PUNTO_H
#define PUNTO_H

#include <cmath>

class Punto {
private:
    double latitud;
    double longitud;
    double altura;
public:
    Punto() : latitud(0), longitud(0), altura(0) { }
    Punto(double latitud, double longitud, double altura) : latitud(latitud), longitud(longitud), altura(altura) { }

    inline double getLatitud() const {
        return latitud;
    }

    inline double getLongitud() const {
        return longitud;
    }

    inline double getAltura() const {
        return altura;
    }

    inline double DistanciaAPunto (const Punto & otro) const {
        return sqrt(pow(latitud-otro.latitud, 2)+pow(longitud-otro.longitud, 2));

    };
};

#endif //PUNTO_H
