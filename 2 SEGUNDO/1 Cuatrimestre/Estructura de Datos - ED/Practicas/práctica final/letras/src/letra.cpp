#include <letra.h>
#include <iostream>

using namespace std;

ConjuntoLetras::ConjuntoLetras(){
}

ConjuntoLetras::~ConjuntoLetras(){}

pair<char,Letra> ConjuntoLetras::getLetra(char clave){
    pair<char,Letra> infoLetra;
    map<char,Letra>::iterator it;

    for(it = conjunto.begin(); it != conjunto.end(); it++){
        if(clave == *it.first){
            infoLetra.first = *it.first;
            infoLetra.second = *it.second;
        }

    }

    return infoLetra;

}

int ConjuntoLetra::getPuntosLetra(char clave){
    map<char,Letra>::iterator it;
    int puntos;

    for(it = conjunto.begin(); it != conjunto.end(); it++){
        if(clave == *it.first){
            return puntos = *it.second.puntos;
        }
    }
}

int ConjuntoLetra::getApariciones(char letra){
    map<char,Letra>::iterator it;
    int apariciones;

    for(it = conjunto.begin(); it != conjunto.end(); it++){
        if(clave == *it.first){
            return apariciones = *it.second.apariciones;
        }
    }
}

istream& operator>>(istream &is, ConjuntoLetras &CL){

    char letra;
    int puntos, apariciones;

    map<char,Letra>::iterator it;

    for(it = conjunto.begin(); it != conjunto.end(); it++){
        is >> CL.first;
        is >> CL.second.puntos;
        is >> CL.second.apariciones;
    }

    return is;
}

ostream& operator<<(ostream &os, const ConjuntoLetras &CL){

    map<char,Letra>::iterator it;

    for(it = conjunto.begin(); it != conjunto.end(); it++){
        os << CL.first;
        os << CL.second.puntos;
        os << CL.second.apariciones;
    }

    return os;
}
