#ifndef HORA_H
#define HORA_H

class Hora {
private:
    int hora;
    int minuto;
    int segundo;
public:
    Hora() : hora(0), minuto(0), segundo(0) {}
    Hora(int hora, int minuto, int segundo) : hora(hora), minuto(minuto), segundo(segundo) { }

    inline int getHora() const {
        return hora;
    }

    inline int getMinuto() const {
        return minuto;
    }

    inline int getSegundo() const {
        return segundo;
    }
};


#endif //HORA_H
