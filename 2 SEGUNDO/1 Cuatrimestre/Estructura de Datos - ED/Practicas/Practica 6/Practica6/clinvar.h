/**
 * @file
 * @brief Clase ClinVar
 *
 */

/*
 * clinvar.h
 *
*/
#ifndef __CLINVAR_H
#define __CLINVAR_H

#include <string>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <unordered_map>
#include "enfermedad.h"
#include "mutacion.h"

using namespace std;

typedef string                                                     IDgen; // Definimos los strings necesarios
typedef string                                                     IDmut;
typedef string                                                     IDenf;
typedef set<mutacion>::iterator                                    iterator_mut; // Definimos los iteradores necesarios
typedef list<iterator_mut>::iterator                               listit;
typedef unordered_map<IDmut, iterator_mut>::iterator               unordered_iterator;
typedef map<IDenf, enfermedad>::iterator                           enfermedad_iterator;

class ClinVar{

  public:


    /**
    * @brief Clase iterator (mut_iterator) para iterar sobre las mutaciones de ClinVar
    *
    */
    class mut_iterator{ // Iterador sobre mutacion
      private:
        iterator_mut it;

      public:
        /**
        * @brief operator() para ordenar segun el criterio establecidos de cromosoma/posicion
        *
        */
        bool operator()(iterator_mut uno, iterator_mut otro) {
          return ((uno->getChr() < otro->getChr()) && (uno->getPos() < otro->getPos()));
        }

        /**
        * @brief Para ver el contenido al que apunta mut_iterator
        *
        */
        const mutacion & operator*() {
          return *it;
        }

        /**
        * @brief Avanza mut_iterator una posicion, notacion posfija
        *
        */
        iterator_mut& operator++(int){
          it++;
          return it;
        }

        /**
        * @brief Asigna a un mut_iterator el valor de otro mut_iterator
        *
        */
        mut_iterator& operator=(const mut_iterator &orig){
          if(this != &orig){
            it = orig.it;
          }
          return *this;
        }


        /**
        * @brief Compara un mut_iterator con otro
        * @return true si son distintos
        */
        bool operator!=(const mut_iterator &orig) {
          return (it != orig.it);
        }

        /**
        * @brief Inicializa el valor de it atributo de mut_iterator
        *
        */
        void setit(iterator_mut otro){
          it = otro;
        }

        /**
        * @brief Devuelve el valor de it, atributo de mut_iterator
        *
        */
        iterator_mut getit() {
          return it;
        }


      /*
        Estos metodos no son necesarios, son para ahorrar codigo y hacer mas entendible la implementacion de
        la clase clinvar
      */


        /**
        * @brief Devuelve el valor del ID del elemento al que apunta mut_iterator
        *
        */
        IDmut getID() {
          return it->getID();
        }

        /**
        * @brief Devuelve un vector con el ID de las enfermedades del elemento al que apunta mut_iterator
        *
        */
        vector<IDenf> getEnfID() {
          vector<IDenf> uno;
          int tam = it->getEnfermedades().size();
          for(int i = 0; i < tam; i++){
            uno.push_back(it->getEnfermedades()[i].getID());
          }
          return uno;
        }

    };

    /**
    * @brief Clase gen_iterator para iterar sobre los genes de la clase clinvar
    *
    */
    class gen_iterator{
      private:
        map<IDgen, list< mut_iterator> >::iterator itmap;
        listit itlist;
        ClinVar* ptrclinvar;

      public:
        /**
        * @brief operator() para ordenar segun los criterios establecidos de IDgen
        *
        */
        bool operator()(map<IDgen, list< mut_iterator> >::iterator a, map<IDgen, list< mut_iterator> >::iterator b){
          return (a->first < b->first);
        }

        /**
        * @brief Para ver el contenido de donde apunta gen_iterator
        *
        */
        const mutacion & operator*(){
          return **itlist;
        }

        /**
        * @brief Avanza gen_iterator una posicion, notacion posfija
        *
        */
        listit& operator++(int){
          itlist++;
          return itlist;
        }

        /**
        * @brief Para inicializar el map de gen_iterator
        *
        */
        void setitmap(map<IDgen, list< mut_iterator> >::iterator otro){
          itmap = otro;
        }
    };


    /**
    * @brief functor para ordenar topKMutaciones segun el caf
    *
    */
    struct ProbMutaciones{
      bool operator()(const mutacion caf1, const mutacion caf2) {
        return (caf1.getCaf()[0] < caf2.getCaf()[0]);
      }
    };

    /**
    * @brief Carga el fichero de mutaciones en todas las estructuras de la clase clinvar
    * @param nombreDB Nombre del fichero de mutaciones
    *
    *
    */
    mutacion load(string nombreDB);

    /**
    * @brief Inserta una mutacion en la clase clinvar, insertandola segun el orden predeterminado en todas las estructuras
    * @param x Mutacion a ser insertada
    *
    *
    */
    void insert(const mutacion &x);

    /**
    * @brief Elimina una mutacion de todas las estructuras de clinvar
    * @param ID ID de la mutacion a ser borrada
    * @return true si tiene exito borrando, false en caso contrario
    *
    */
    bool erase( IDmut ID);

    /**
    * @brief Busca una mutacion en la clase clinvar
    * @param ID ID de la mutacion a buscar
    * @return Iterador a la mutacion si la encuentra
    *
    */
    mut_iterator find_mut(IDmut ID);

    /**
    * @brief Busca una enfermedad en la clase clinvar
    * @param ID ID de la enfermedad a buscar
    * @return Iterador a la enfermedad si la encuentra
    *
    */
    enfermedad_iterator find_Enf(IDenf ID);

    /**
    * @brief Devuelve las enfermedades de una mutacion
    * @param mut mutacion sobre la que buscar las enfermedades
    * @return vector de enfermedades de la mutacion
    *
    */
    vector<enfermedad> getEnfermedades(mutacion &mut);

    /**
    * @brief Devuelve las enfermedades que contienen una palabra clave en el nombre
    * @param keyword Palabra clave a buscar en el nombre de las enfermedades
    * @return lista de ID de enfermedades que contienen la palabra clave
    *
    */
    list<IDenf> getEnfermedades(string keyword);

    /**
    * @brief Busca las mutaciones que tienen un determinado ID en sus enfermedades
    * @param ID ID de las enfermedades a buscar en el conjunto de mutaciones
    * @return set con el conjunto de ID de las mutaciones que tienen enfermedades con el ID pasado como parametro
    *
    */
    set<IDmut> getMutacionesEnf (IDenf ID);

    /**
    * @brief Busca las mutaciones que tienen un determinado ID en sus genes
    * @param ID ID de los genes a buscar en el conjunto de mutaciones
    * @return set con el conjunto de ID de las mutaciones que tienen genes con el ID pasado como parametro
    *
    */
    set<IDmut> getMutacionesGen (IDgen ID);

    /**
    * @brief Busca las mutaciones que tienen una palabra clave en el nombre y devuelve las k más probables
    * @param keyword palabra clave en el nombre de las mutaciones
    * @param k numero de mutaciones máximo de las más probables para devolver
    * @return set con el conjunto de mutaciones más probables con la determinada palabra clave en el nombre
    *
    */
    set<mutacion, ProbMutaciones> topKMutaciones(int k, string keyword);


    /**
    * @brief Tamaño del conjunto clinvar
    * @return int con el valor de mutaciones cargadas en clinvar
    *
    */
    int size();

    /**
    * @brief Imprime el tamaño de todos los conjuntos que hay en clinvar
    * Para comprobar la correcta lectura del fichero
    *
    */
    void LecturaFichero();

    /* Metodos relacionados con los iteradores */

    /**
    * @brief Busca una mutacion con chr mayor o igual que cromosoma y pos mayor o igual que posicion
    * @param cromosoma cromosoma de la mutacion a buscar
    * @param posicion posicion de la mutacion a buscar
    * @return mut_iterator iterador apuntando a la mutacion encontrada
    *
    */
    mut_iterator lower_bound(string cromosoma, unsigned int posicion);

    /**
    * @brief Busca una mutacion con chr mayor que cromosoma y pos mayor que posicion
    * @param cromosoma cromosoma de la mutacion a buscar
    * @param posicion posicion de la mutacion a buscar
    * @return mut_iterator iterador apuntando a la mutacion encontrada
    *
    */
    mut_iterator upper_bound(string cromosoma, unsigned int posicion);

    /**
    * @brief Devuelve un objeto mut_iterator apuntando al principio de las mutaciones de clinvar
    * @return mut_iterator apuntando al principio de las mutaciones de clinvar
    *
    */
    mut_iterator begin();

    /**
    * @brief Devuelve un objeto mut_iterator apuntando al final de las mutaciones de clinvar
    * @return mut_iterator apuntando al final de las mutaciones de clinvar
    *
    */
    mut_iterator end();

    /**
    * @brief Devuelve un enfermedad_iterator apuntando al principio de las enfermedades de clinvar
    * @return enfermedad_iterator apuntando al principio de las enfermedades de clinvar
    *
    */
    enfermedad_iterator ebegin();

    /**
    * @brief Devuelve un enfermedad_iterator apuntando al final de las enfermedades de clinvar
    * @return enfermedad_iterator apuntando al final de las enfermedades de clinvar
    *
    */
    enfermedad_iterator eend();


    /**
    * @brief Devuelve un objeto gen_iterator apuntando al principio de los genes de clinvar
    * @return enfermedad_iterator apuntando al principio de los genes de clinvar
    *
    */
    gen_iterator gbegin();

    /**
    * @brief Devuelve un objeto gen_iterator apuntando al final de los genes de clinvar
    * @return enfermedad_iterator apuntando al final de los genes de clinvar
    *
    */
    gen_iterator gend();

  private:
    set<mutacion> mutDB; // Base de datos que contiene toda la informacion asociada a una mutacion
    unordered_map<IDmut, mut_iterator> IDm_map; // Asocia IDmutacion con mutacion
    map<IDgen, list< mut_iterator> > gen_map; // Asocia genes con mutacion
    map<IDenf, enfermedad> enfDB; // Base de datos de enfermedades
    multimap<IDenf, mut_iterator > IDenf_map; // Asocia enfermedad con mutaciones

};




#include "clinvar.hxx"
#endif
