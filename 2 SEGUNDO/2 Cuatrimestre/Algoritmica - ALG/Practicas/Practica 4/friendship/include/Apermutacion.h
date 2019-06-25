#ifndef __APERMUTA__
#define __APERMUTA__
#include <vector>
#include <iostream>
using namespace std;
/**
   @brief T.D.A. APermutacion
   
   \b Definición:
   Una instancia \e a del tipo de dato abstracto APermutacion sobre un dominio de enteros
   genera secuencias (x1,x2,x3,...,xk) 1<=k<=n donde cada xi toma valores 1,,,.k, y ademas xi<>xj para i<>j.
   
   Para poder usar el tipo de dato APermutacion se debe incluir el fichero
   
   <tt>\#include APermutacion.h</tt>
   
   El espacio requerido para el almacenamiento es O(n), donde n es la longitud maxima de cada secuencia
   
   @author Rosa Mª Rodríguez Sánchez
   @date 12 de Mayo de 2015
*/


class Apermutacion{
  private:
   vector<int>datos;
   int level;
public:

  Apermutacion(){

  }


  /**
   * @brief Constructor por parametros. Inicia la permutacion
   * con n valores a 0.
   * 
   * */
  Apermutacion(int n):datos(vector<int>(n,0)),level(-1){
  //  GeneraSiguienteProfundidad();
  }
   
   
  Apermutacion(vector<int> &v ,int l):datos(v),level(l){
   
  } 
   
  /** 
   *@brief Establece si la permutacion tiene valores repetidos
   * @return true si hay  valores repetidos y false en caso contrario
   **/
  bool Repetidos(); 
  
  
  /** 
   *@brief La restriccion propia del problema. En este caso que no se asigne i a i 
   *     y si se asigna i a j tambien debe asignarse j ai.
   * @return true si se cumple la condicion del problema, false en caso contrario
   **/
  bool CondicionProblem();
  
  
  /** 
   * 
   * 
   * @brief Avance al siguiente valor por el nivel por el que va
   * */
  
  void Next(int l){
    datos[l]++;
  }  
     
  /** 
   * @brief Analiza  si es una permutacion valida 
   * @param l: el nivel hasta el que se quiere analizar si es secuencia valida
   * @return devuelve true si es permutacion valida false en caso contrario
   * */
  bool EsSecuencia(int l);
  
  /** 
   * @brief Analiza  si es una secuencia que puede dar lugar a una  permutacion valida (potencia   permutacion valida)
   * @param l: el nivel hasta el que se quiere analizar si es secuencia valida
   * @return devuelve true si es potencial permutacion valida false en caso contrario
   * */
  bool PosibleSecuencia(int l);
  
  /** 
   * @brief Analiza  si existen mas valores posibles para el nivel dado
   * @param l: el nivel 
   * @return devuelve true si existen mas posibles valores false en caso contrario
   * */
  bool MasHermanos (int l);
  
  /** 
   * @brief Obtiene la siguiente permutacion en profundidad
   * @return devuelve true si se ha generado una permutacion, false si no se puede generar porque ya se 
   * han generado todas
   * */
  
  bool GeneraSiguienteProfundidad();
  
  /** 
   * @brief Obtiene la siguiente permutacion en anchura
   * @return devuelve true si se ha generado una permutacion, false si no se puede generar porque ya se 
   * han generado todas
   * */
  bool GeneraSiguienteAnchura();
  /** 
   * @brief Obtiene la siguiente permutacion valida por la siguiente rama.
   * @return devuelve true si se ha generado una permutacion, false si no se puede generar porque ya se 
   * han generado todas
   * */
  bool Backtracking();
    
  
  /** 
   * @brief Devuelve  el nivel de la secuencia hasta el momento
   */
  
   int GetLevel()const{ 
      return level;
    }
  
  
  /** 
   * @brief Devuelve  la secuencia de la permutacion
   */
  
   vector<int> GetSecuencia()const{ 
      return datos;
    }
  
   
   /**
    * @brief devuelve el numero posible de secuencias
    * 
    */
   int NumeroSecuenciasPosibles();
   
   /**
    * @brief Comprueba si la permutacion es padre de la permutacion de entrada
    * @param v: permutacion de entrada
    * @return true si es padre y false si no lo es.
    * 
    */
   
   bool Espadre(const Apermutacion &v)const;
  
   /**
    * @brief Escribe la permutacion en el flujo de salida
    * 
    */
   
   /**
    * @brief Devuelve todas las secuencias hijas de la actual
    * @return un vector en el que cada elemento tiene una secuencia hija.
    * 
    */
   vector<vector<int> > GeneraHijos();
   
   /**
    * @brief Operadores de consulta
    */
   int operator[](int i){
      return datos[i];
   }
   
   int operator[](int i)const{
      return datos[i];
   }
   
   friend ostream & operator<<(ostream & os, const Apermutacion &V);
   
  /****************************************/
  /*Iteradores*/
    class iterator{
    private:
       vector< int> ::iterator it;
       vector< int> ::iterator final;
       
    public:
        iterator (){ }
        iterator & operator++(){
	     ++it;
	    return *this;
	}
	
	iterator & operator --(){
	   --it;
	  return *this;
	}
	
	bool operator ==(const iterator & i)const{
	   return (i.it==it);
	}
	bool operator !=(const iterator & i)const{
	   return (i.it!=it);
	}  
	
	int & operator*()const {
	   return *it;
	}
	friend class Apermutacion;
    };
    
    
    
    class const_iterator{
    private:
       vector<int>::const_iterator it;
       vector< int> ::const_iterator final;
    public:
        const_iterator (){ }
        
        const_iterator & operator++(){
	   ++it;
	    return *this;
	}
	
	const_iterator & operator --(){
	   --it;
	  return *this;
	}
	
	bool operator ==(const const_iterator & i)const{
	   return (i.it==it);
	}
	bool operator !=(const const_iterator & i)const {
	   return (i.it!=it);
	}  
	
	const  int & operator*()const {
	   return *it;
	}
	friend class Apermutacion;
    };
    
    
    
    
    
    
    
    iterator begin(){
	iterator i;
	i.it=datos.begin();
	if (level>=0)
	 i.final=datos.begin()+level+1;
	else i.final=datos.end();
	return i;
    }
    iterator end(){
        iterator i;
	if (level>=0){
         if (level ==(int)datos.size()-1 && datos[level]>0)
	   i.it=datos.end();
	 else
	   i.it = datos.begin()+level+1;
	}
	else i.it=datos.end();
	i.final = i.it;
	
	return i;
    }
    
    
    const_iterator begin()const{
	const_iterator i;
	i.it=datos.begin();
	if (level>=0)
	 i.final=datos.begin()+level+1;
	else i.final=datos.end();
	return i;
    }
    const_iterator end()const{
        const_iterator i;
	
	if (level>=0){
         if (level ==(int)datos.size()-1 && datos[level]>0)
	   i.it=datos.end();
	 else
	   i.it = datos.begin()+level+1;
	}
	else i.it=datos.end();
	   
	i.final = i.it;
	
	
	return i;
    }
};
#endif