#ifndef INSTANTE_H
#define INSTANTE_H

#include <ctime>
#include "Fecha.h"
#include "Hora.h"

class Instante {
private:
    Fecha fecha;
    Hora  hora;
public:
    Instante() : fecha(), hora() { }
    Instante(const Fecha &fecha, const Hora &hora) : fecha(fecha), hora(hora) { }

    inline const Fecha &getFecha() const {
        return fecha;
    }

    inline const Hora &getHora() const {
        return hora;
    }

    // Intervalo de tiempo (otro - this)
    inline double IntervaloTiempo (const Instante & otro) const {
        tm t1, t2;
        t1.tm_sec = this->hora.getSegundo();
        t1.tm_min = this->hora.getMinuto();
        t1.tm_hour = this->hora.getHora();
        t1.tm_mday = this->getFecha().getDia();
        t1.tm_mon = this->getFecha().getMes();
        t1.tm_year = this->getFecha().getAnio();

        t2.tm_sec = otro.hora.getSegundo();
        t2.tm_min = otro.hora.getMinuto();
        t2.tm_hour = otro.hora.getHora();
        t2.tm_mday = otro.getFecha().getDia();
        t2.tm_mon = otro.getFecha().getMes();
        t2.tm_year = otro.getFecha().getAnio();

        return difftime(mktime(&t2), mktime(&t1)) + 1;  // +1 segundo para incrementar la diferencia
    }
};

#endif //INSTANTE_H
