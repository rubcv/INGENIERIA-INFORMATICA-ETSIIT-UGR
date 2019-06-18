/*******************************************/
/* IMPLEMENTACION***************************/
/*******************************************/

/*
  Funcion de Abstraccion

   Dado el objeto del tipo rep r, r = {raiz}, el objeto
  abstracto al que representa es:                       
  a) Arbol nulo, si r.raiz == 0.                      
  b) Arbol con un unico nodo de etiqueta r.raiz->et,
     si r.raiz->hizq == 0 y r.raiz->hder == 0.         

  c)                r.raiz->et
                         /       \
                        /         \
      Arbol(r.raiz->hizq)    Arbol(r.raiz->hder)


  Invariante de Representacion:
  
  Si r.raiz != 0,
  -  r.raiz->padre == 0.
  - Para todo nodo n en el arbol con raiz r.raiz n->hizq<>n->hder y
  - Para todo par de nodos n y m en el arbol con raiz r.raiz si n->hizq=m o n->hder=m 
    entonces m->padre=n
  - Para todo par de nodos n y m si n está en el subarbo izquierdo que cuelga de m n->et<m->et o si
    n está en el subarbol derecho n->et>m->et
  

*/

#include <cassert>

//FUNCIONES ASOCIADAS a info_nodo

template <class T>
void ABB<T>::CopiarInfo(ABB<T>::info_nodo * &dest, const ABB<T>::info_nodo*const &source){
	 if (source!=0){
	  dest=new info_nodo(source->et);
	  CopiarInfo(dest->hizq,source->hizq);
	  if (dest->hizq!=0){
	    dest->hizq->padre= dest;
	  }
	  CopiarInfo(dest->hder,source->hder);
	  if (dest->hder!=0) dest->hder->padre=dest;
	  }
	  else dest=0;
}


template <class T>
void ABB<T>::BorrarInfo(ABB<T>::info_nodo *&d){
	  if (d!=0){
	   BorrarInfo(d->hizq);
	   BorrarInfo(d->hder);
	   delete d;
	  } 
  
}	  


template <class T>
unsigned int  ABB<T>::numero_nodos(const ABB<T>::info_nodo*d)const{
	  if (d==0) return 0;
	  else return 1+numero_nodos(d->hizq)+numero_nodos(d->hder);
}

template <class T>
bool  ABB<T>::iguales(const ABB<T>::info_nodo *s1,const ABB<T>::info_nodo *s2)const {
	  if (s1==0 && s2==0) return true;
	  else
	  if (s1==0 || s2==0) return false;
	  if (s1->et!=s2->et) return false;
	  else return iguales(s1->hizq,s2->hizq) && iguales(s1->hder,s2->hder);
}	  


template <class T>
typename  ABB<T>::info_nodo* ABB<T>::Buscar( ABB<T>::info_nodo * n,const T &e){
	  if (n==0) return n;
	  else {
		if (n->et==e) return n;
		else
		 if (n->et>e) return Buscar(n->hizq,e);
		 else 
		    return Buscar(n->hder,e);
	  }
	 
}	

template <class T>
bool ABB<T>::Insertar(ABB<T>::info_nodo * &n,const T & e){
	  
	  bool res =false;
	  if (n==0){
	    n = new info_nodo(e);
	    return true;
	  }
	  else if (n->et<e){
		    res =Insertar(n->hder,e);
		    if (res){
			n->hder->padre=n;
		    }
		    return res;	      
	  }
	  else if (n->et>e){
		    res =Insertar(n->hizq,e);
		    if (res){
			n->hizq->padre=n;
		    }
		    return res;
	  }
	  return false;
}

template <class T>
void ABB<T>::PutHijo_Padre(ABB<T>::info_nodo *n,ABB<T>::info_nodo *nuevo){
		  if (n->padre!=0){
			    if (nuevo!=0)
				      nuevo->padre = n->padre;  
			    if (n->padre->hder==n){
					n->padre->hder = nuevo;
			    }
			    else n->padre->hizq=nuevo;
			    
		  }
}		  
template <class T>
void ABB<T>::EliminarRaiz(ABB<T>::info_nodo *&n){
		if (n->hizq==0 && n->hder==0){
			      PutHijo_Padre(n,0);
			      delete n;
		}
		else if (n->hizq==0){
			      ABB<T>::info_nodo *aux=n;
			      PutHijo_Padre(n,n->hder);
			      if (n==raiz)
			       n= n->hder;
			      delete aux;
			  
		}
		else if (n->hder==0){
			      ABB<T>::info_nodo *aux=n;
			      PutHijo_Padre(n,n->hizq);
			      if (n==raiz) n = n->hizq;
			      delete aux;
			  
		}
		else{
			 //buscamos el siguiente 
			ABB<T>::info_nodo *aux=n->hder;
			while (aux->hizq!=0){
				  aux=aux->hizq;
			}
			n->et=aux->et;
			Borrar(n->hder,aux->et);
		}
	  
}	  
template <class T>
void ABB<T>::Borrar(ABB<T>::info_nodo * &n,const T &e){
	  if (n!=0){
		if (n->et==e) EliminarRaiz(n);
		else if (n->et<e) Borrar(n->hder,e);
		else Borrar(n->hizq,e);
	  }
}


/********************************************************/
/* 	FUNCIONES DE ABB                     */
/********************************************************/
template <class T>
ABB<T>::ABB(typename ABB<T>::nodo n){
	  raiz=n.p;
}	  



template <class T>
ABB<T>::ABB(const T &e){
	  raiz=new info_nodo(e);
}	  

template <class T>
ABB<T>::ABB(const ABB<T> & ab){
	  if (ab.raiz==0) raiz=0;
	  else
		    CopiarInfo(raiz,ab.raiz);
}		    

template <class T>
ABB<T> & ABB<T>::operator=(const ABB<T> & ab){
	  if (this!=&ab){
		    BorrarInfo(raiz);
		    CopiarInfo(raiz,ab.raiz);
	  }
}	  
	  
template <class T>	  
typename ABB<T>::nodo ABB<T>::getRaiz()const{
	 if (raiz!=0)
	   return typename ABB<T>::nodo(raiz);
	 else 
	 return typename ABB<T>::nodo();
}	 
template <class T>	 
bool ABB<T>::Insertar( const T &e){
	  
	  return Insertar(raiz,e);
}	  
template <class T>
void ABB<T>::Borrar(const T &e){
	  Borrar(raiz,e);
         
	  
	  
}	  


template <class T>
void ABB<T>::clear(){
	  BorrarInfo(raiz);
	  raiz=0;
}	  
template <class T>
bool ABB<T>::empty()const {
	  return raiz==0;
}	  
template <class T>
unsigned int ABB<T>::size()const {
	  return numero_nodos(raiz);
}	  
template <class T>
bool ABB<T>::operator==(const ABB<T> &a)const {
	  return iguales(raiz,a.raiz);
}	  
	  
template <class T>
bool ABB<T>::operator!=(const ABB<T> &a)const{
	  return !(*this==a);
}	  




/***************************INORDEN_ITERDOR operator++**********************/
template <class T>
typename ABB<T>::nodo & ABB<T>::nodo::operator++(){
          if (p==0)
	    return *this;
          if (p->hder!=0) {
	       p= p->hder;
               while (p->hizq!=0)
                  p = p->hizq;
	  }
	  else {
	      while (p->padre!=0 &&
	         p->padre->hder == p)
	        p = p->padre;
	       // Si (padre de p es nulo), hemos terminado En caso contrario, 
		        //el siguiente a p es el padre
	      p  = p->padre;

           }
      return *this;
	  
}

/**FUNCIONES BEGIN y END */
template <class T>
typename ABB<T>::nodo ABB<T>::begin()const {
	   typename ABB<T>::info_nodo * n = raiz;

	  if (n!=0)
		 while (n->hizq!=0)
		    n = n->hizq;
 
	  typename ABB<T>::nodo nuevo(n);
	  return nuevo;
}	  
template <class T>
typename ABB<T>::nodo ABB<T>::end()const {
	 
	  typename ABB<T>::nodo nuevo(0);
	  return nuevo;
}












