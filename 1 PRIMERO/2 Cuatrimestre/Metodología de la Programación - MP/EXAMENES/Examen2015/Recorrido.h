#ifndef RECORRIDO_H
#define RECORRIDO_H

#include "Punto.h"
#include "Instante.h"
#include <iostream>

struct PuntoDeRecorrido {
    Punto    punto;
    Instante instante;
};

class Recorrido {
private:
    PuntoDeRecorrido *puntos;   // Puntero a un array de "num_puntos" datos "PuntoDeRecorrido"
    int num_puntos;             // Numero de puntos del recorrido
    bool activo;                // Indica si el recorrido est ́a activo
public:
    Recorrido(bool iniciar);    // Constructor
    ~Recorrido();               // Destructor
    Recorrido(const Recorrido &r);  // Constructor de copia

    void FinRecorrido();        // Terminar recorrido con situacion actual

    void anadirPunto(const PuntoDeRecorrido &punto);        // Metodo auxiliar para añadir puntos

    Recorrido & operator=(const Recorrido &r);  // Operador de asignacion
    PuntoDeRecorrido & operator[](int i);       // Operador de indexacion (no se puede utilizar con const Recorrido)
    const PuntoDeRecorrido & operator[](int i) const; // Operador de indexacion (se puede utilizar con const Recorrido)

    double DistanciaRecorrido() const;          // Distancia total del recorrido (metros)
    double TiempoRecorrido() const;             // Tiempo total del recorrido (segundos)
    double VelocidadMedia() const;              // Velocidad media del recorrido (km/h)

    bool lectura(const char *fichero);          // Lectura de fichero
    bool escritura(const char *fichero);        // Escritura en fichero

    friend std::ostream & operator<<(std::ostream &flujo, const Recorrido &r);  // operator<< con Recorrido puede acceder a la parte privada
    friend std::istream &operator>>(std::istream &flujo, Recorrido &r);         // operator>> con Recorrido puede acceder a la parte privada

    // Versiones alternativas de lectura, escritura
    bool lectura2(const char *fichero);
    bool escritura2(const char *fichero);

    bool lecturaBin(const char *fichero);
    bool escrituraBin(const char *fichero);
};

Punto GetPosicion(void);
Instante GetInstante(void);
Recorrido generarRecorridoAleatorio();

#endif //RECORRIDO_H
