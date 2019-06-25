/**
 * @file imagen.h
 */
#ifndef __IMAGEN_H
#define __IMAGEN_H
#include "imagenES.h"
#include "paleta.h"
#include <cassert>
#include <iostream>
#include <string>
enum Tipo_Pegado {OPACO, BLENDING};
using namespace std;
typedef color Pixel;
/** @brief TDA Imagen. Es una matriz de nxm filas, columnas de pixeles.
 * 
 * */

class Imagen{
  private:
    Pixel ** data;//< espacio para almacenar los pixeles de la imagen
    int nf,nc; //< numero de filas y columnas
    /** 
     * @brief Elimina la memoria asignada a la matriz
     */
    void Borrar();
    /**
     * @brief Copia una imagen en otra.
     */
    void Copiar(const Imagen &I);
  public:
    /**
     * @brief Constructor por defecto
     */
   Imagen();
    /**
     * @brief Constructor por parametros. Reserva espacio para una imageen con un determinado nuemro de filas 
     * y columnas. Todos los pixeles se inician a blanco.
     * @param f: numero de filas
     * @param c: numero de columnas
     */
   Imagen(int f,int c);
   /**
     * @brief Constructor de copia
     * @param I: imagen a ser copiada
    */
   Imagen(const Imagen & I);
    /**
     * @brief Asignacion
     * @param I: imagen que se asigna
    */
   Imagen & operator=(const Imagen & I);
    /**
     * @brief Destructor
    */
   ~Imagen();
   
   //set y get
   /** @brief Permite acceder al pixel en la fila i columna j
    *  @param i: fila
    *  @param j: columna
    *  @return el pixel en la posicion i,j
    */
   Pixel & operator ()(int i,int j);
   
   const Pixel & operator ()(int i,int j)const;
   
   
   
   void EscribirImagen(const char * nombre);
   
   void LeerImagen (const char *nombre,const string &nombremascara="");
   void LimpiarTransp();
   int num_filas()const{return nf;}
   int num_cols()const{return nc;}
   void PutImagen(int posi,int posj, const Imagen &I,Tipo_Pegado tippegado=OPACO);
   Imagen ExtraeImagen(int posi,int posj,int dimi,int dimj);
};   
   
#endif