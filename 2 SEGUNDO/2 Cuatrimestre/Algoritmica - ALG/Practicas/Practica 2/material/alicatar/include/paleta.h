/**
 * @file paleta.h
 * @brief Define el TDA Paleta y COlor
 */
#ifndef __PALETA__
#define __PALETA__
#include <map>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

/**@brief TDA color es una terna formada por el nivel de rojo, verde y azul del color*/


struct color{
  unsigned char r,g,b;
  unsigned char transp; //0 si no es tranparente  255 si si lo es
  color(){ r=g=b=0; transp=0;}
  
  friend ostream & operator <<(ostream &os,const color &c){
  os<<(int)c.r<<" "<<(int)c.g<<" "<<(int)c.b<<endl;
  return os;
  }  
  friend istream & operator >>(istream &is,color &c){
    int vr,vb,vg;
    is>>vr>>vg>>vb;
    c.r=vr; c.g=vg; c.b=vb;
  
  return is;
  }  
};  

/**
 * @brief Paleta. Es un conjunto de pares formados por un indice (entero) y color asociado
 * */

class Paleta{
private:
  map<int,color> datos;
public:
  /** @brief Constructor por defecto
   */
  Paleta(){}
  
  /**
   * @brief Obtiene el color asociado a un indice
   * @param  pos: el indice sobre el que queremos saber el color
   * @return el color asociado al indice. Si el indice no existe devuelve el primer color
   * */
  const color & Get(int pos)const{
      map<int,color>::const_iterator  r;
      r=datos.find(pos);
      if (r!=datos.end())
        return r->second;
      else 
	return datos.begin()->second;
   }
   
   color & Get(int pos){
      return datos[pos];
   }
  
   /**
    * @brief Devuelve el numero de colores que tenemos
    * 
    * */
   int Size()const{
     return datos.size();
   }
   /**
    * @brief Carga de un flujo de entrada la paleta
    * @param is: flujo de entrada
    * @param P : la paleta. Es modificado
    */
   
   friend istream & operator>>(istream &is, Paleta & P){
    string linea;
    int cnt=0;
    while (getline(is,linea)){
      istringstream ss(linea);
      color aux;
      
      ss>>aux;
      pair<int,color> a(cnt,aux);
      P.datos.insert(a);
      cnt++;
    }
    return is;
  }
};
#endif
    