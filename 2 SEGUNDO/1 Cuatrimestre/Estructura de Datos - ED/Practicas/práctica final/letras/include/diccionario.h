#ifndef _diccionario_h_
#define _diccionario_h_

#include "ArbolGeneral.h"

struct info{
    char c;     // Caracter que se almacena en un nodo
    bool final; // nos indica si es final o no de palabra

    info(){     // Constructor por defecto de la estructura
        c = '\0';
        final = false;
    }

    info(char car, bool f){     // Constructor con parámetros
        c = car;
        final = f;
    }
};  // Fin struct

class Diccionario{
    private:
        ArbolGeneral<info> datos;
    public:
        /**
            @brief Construye un diccionario vacío.
        **/
        Diccionario();

        /**
            @brief Devuelve el numero de palabras en el diccionario
        **/
        int size() const;

        /**
            @brief Obtiene todas las palabras en el diccionario de un longitud dada
            @param longitud: la longitud de las palabras de salida
            @return un vector con las palabras de longitud especifica en el parametro de entrada
        **/
        vector<string> PalabrasLongitud(int longitud);

        /**
            @brief Indica si una palabra está en el diccionario o no
            @param palabra: la palabra que se quiere buscar
            @return true si la palabra esta en el diccionario. False en caso contrario
        **/
        bool Esta(string palabra);

        /**
            @brief Lee de un flujo de entrada un diccionario
            @param is:flujo de entrada
            @param D: el objeto donde se realiza la lectura.
            @return el flujo de entrada
        **/
        friend istream& operator>>(istream &is, Diccionario &D);

        /**
            @brief Escribe en un flujo de salida un diccionario
            @param os:flujo de salida
            @param D: el objeto diccionario que se escribe
            @return el flujo de salida
        **/
        friend ostream& operator<<(ostream &os, const Diccionario &D);

        //////////////////*************************////////////////////////

        iterator begin(){
            iterator it;
            it.it = datos.begin();
            return it;
        }

        iterator end(){
            iterator it;
            it.it = datos.end();
            return it;
        }

        class iterator{
            private:
                ArbolGeneral<info>::iter_preorden it;
                string cad; // mantiene caracteres desde nivel 1 hasta donde está it
            public:
                iterator(); // Constructor por defecto
                string operator*();
                iterator& operator++();
                bool operator==(const iterator &it);
                bool operator!=(const iterator &it);

                friend class Diccionario;
        };
};

#endif
