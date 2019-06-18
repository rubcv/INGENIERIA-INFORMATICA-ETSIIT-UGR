#ifndef FECHA_H
#define FECHA_H

class Fecha {
private:
    int dia;
    int mes;
    int anio;
public:
    Fecha() : dia(1), mes(1), anio(2000) {}
    Fecha(int dia, int mes, int anio) : dia(dia), mes(mes), anio(anio) {}

    inline int getDia() const {
        return dia;
    }

    inline int getMes() const {
        return mes;
    }

    inline int getAnio() const {
        return anio;
    }
};

#endif //FECHA_H
