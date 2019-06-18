#include "diccionario.h"
#include <iostream>

using namespace std;

/**
    @brief Construye un diccionario vacío.
**/
Diccionario::Diccionario(){
    datos.laraiz = 0;

    // datos.ArbolGeneral();    // inicializa un arbol con padre = null
}

/* ******************************************************************************* */

/**
    @brief Devuelve el numero de palabras en el diccionario
**/
int Diccionario::size() const{
    return contar(datos.laraiz);
}

/* ******************************************************************************* */

/**
    @brief Obtiene todas las palabras en el diccionario de un longitud dada
    @param longitud: la longitud de las palabras de salida
    @return un vector con las palabras de longitud especifica en el parametro de entrada
**/
vector<string> Diccionario::PalabrasLongitud(int longitud){

    vector<string> palabras;    // se almacenaran las palabras con esa longitud
    ArbolGeneral<info>::iter_preorden it;
    int cnt = 0;

    while( *(it) != NULL && cnt != longitud){
        palabras[cnt] = *it;
    }
}

/* ******************************************************************************* */

/**
    @brief Indica si una palabra está en el diccionario o no
    @param palabra: la palabra que se quiere buscar
    @return true si la palabra esta en el diccionario. False en caso contrario
**/
bool Diccionario::Esta(string palabra){
    bool esta = false;
    ArbolGeneral<info>::iter_preorden it;

    // ¿como sacar caracteres de un string para comparar con cada etiqueta?

    for(it = datos.begin(); it != datos.end(); it++){
        if( (*it).etiqueta != caracter ){
            return false;
        }
    }
    return true;    // si lo ha recorrido todo y no devuelve false, es que está
}

/* ******************************************************************************* */


/**
    @brief Lee de un flujo de entrada un diccionario
    @param is:flujo de entrada
    @param D: el objeto donde se realiza la lectura.
    @return el flujo de entrada
**/
friend istream& operator>>(istream &is, Diccionario &D){

}

/* ******************************************************************************* */

/**
    @brief Escribe en un flujo de salida un diccionario
    @param os:flujo de salida
    @param D: el objeto diccionario que se escribe
    @return el flujo de salida
**/
friend ostream& operator<<(ostream &os, const Diccionario &D){

}

/* ******************************************************************************* */

//////////////////// CLASE ITERADOR ////////////////////

string Diccionario::iterator::operator*(){
    return *it;
}

iterator& Diccionario::iterator::operator++(){
    it++;
    return *this;
}

bool Diccionario::iterator::operator==(){
    return datos.it == it;
}

bool Diccionario::iterator::operator!=(){
    return datos.it != it;

}
