//-*-Mode: C++;-*-

/*
  $Id: node.template,v 1.2 2006/05/18 10:22:10 jmbs Exp $
*/
/*
  $Log: node.template,v $
  Revision 1.2  2006/05/18 10:22:10  jmbs
  Corregida funci� ktree<T,K>::copy

  Revision 1.1.1.1  2006/05/17 12:25:32  jmbs
  Versi� Inicial

*/

using namespace std;
#include <cassert>

//
// Operaciones de celdaArbol
//
template <typename T, int K>
inline
ktree<T,K>::celdaArbol::celdaArbol()
{
 pad.elnodo = 0;
 for (int i = 0; i<K; i++){
	hijos[i].elnodo=0;
     }
}

 template <typename T, int K>
inline
ktree<T,K>::celdaArbol::celdaArbol(const T & e)
{
 pad.elnodo = 0;
 etiqueta = e;
 for (int i = 0; i<K; i++){
	hijos[i].elnodo=0;
     }
}


//
// Operaciones de node
//

template <typename T, int K>
inline
ktree<T,K>::node::node()
{
  elnodo = 0;
};


template <typename T, int K>
inline
ktree<T,K>::node::node(const T & e)
{
  elnodo = new celdaArbol(e);


}


template <typename T, int K>
inline
ktree<T,K>::node::node(const typename ktree<T,K>::node & n)
  : elnodo(n.elnodo)
{
}

/*
template <typename T, int K>
inline
ktree<T,K>::node::node(typename ktree<T,K>::node *n)
{
  if (n != 0)
    elnodo = n->elnodo;
  else
    elnodo = 0;
};
*/

template <typename T, int K>
inline
typename ktree<T,K>::node &
ktree<T,K>::node::operator=(const typename ktree<T,K>::node & n)
{
  if (&n != this){
    if (n.null())
      elnodo = 0;
    else
      elnodo = n.elnodo;
  }
  return *this;
};

template <typename T, int K>
inline
bool ktree<T,K>::node::null() const
{
  return elnodo == 0;
};

template <typename T, int K>
inline
void ktree<T,K>::node::parent(typename ktree<T,K>::node n)
{
  elnodo->pad = n;
};

template <typename T, int K>
inline
void ktree<T,K>::node::k_child(int k, typename ktree<T,K>::node n)
{
  elnodo->hijos[k] = n;
};



template <typename T, int K>
inline
typename ktree<T,K>::node ktree<T,K>::node::parent() const
{
  return (elnodo->pad);
};

template <typename T, int K>
inline
typename ktree<T,K>::node ktree<T,K>::node::k_child(int k) const
{
  return (elnodo->hijos[k]);
};


template <typename T, int K>
inline
typename ktree<T,K>::node ktree<T,K>::node::operator[](int k) const
{
  return (elnodo->hijos[k]);
};

template <typename T, int K>
inline
T & ktree<T,K>::node::operator*()
{
  return elnodo->etiqueta;
};

template <typename T, int K>
inline
const T & ktree<T,K>::node::operator*() const
{
  return elnodo->etiqueta;
};

template <typename T, int K>
void ktree<T,K>::node::remove()
{
  delete elnodo;
  elnodo = 0;
};

template <typename T, int K>
inline
bool ktree<T,K>::node::operator==(const node & n) const
{
  return elnodo == n.elnodo;
};

template <typename T, int K>
inline
bool ktree<T,K>::node::operator!=(const node & n) const
{
  return elnodo != n.elnodo;
};

/*____________________________________________________________ */

template <typename T, int K >
inline
  int ktree<T,K>::node::child_number( ) const{

if (elnodo->pad.null())
  return -1;
else {
  int pos;
  for (pos=0; pos <K; pos++){
   typename ktree<T,K>::node p,h;
   p = elnodo->pad;
   h = p.elnodo->hijos[pos];
   if (h.elnodo==elnodo)
     return pos;
  }
}
cout << "Error n no es hijo de su supuesto padre" << endl;
}



 /// ITERADOR SOBRE NODO


template <typename T, int K >
inline   ktree<T,K>::node::child_iterator::child_iterator()
{

}


template <typename T, int K >
inline    ktree<T,K>::node::child_iterator::child_iterator(const child_iterator & x)
{n_padre = x.n_padre;pos_actual = x.pos_actual;};



template <typename T, int K >
inline typename  ktree<T,K>::node &  ktree<T,K>::node::child_iterator::operator*( ){
        return (*n_padre).hijos[pos_actual];
    }


template <typename T, int K >
inline typename  ktree<T,K>::node::child_iterator & ktree<T,K>::node::child_iterator::operator++(){

        do{

         pos_actual++;
        } while ((pos_actual <K) && ((*n_padre).hijos[pos_actual].null()));

        return *this;
    }


template <typename T, int K >
inline typename  ktree<T,K>::node::child_iterator  ktree<T,K>::node::child_iterator::operator++(int x){
typename ktree<T,K>::node::child_iterator aux(*this);
++(*this);
return aux;
    }


template <typename T, int K >
inline typename  ktree<T,K>::node::child_iterator & ktree<T,K>::node::child_iterator::operator=(const child_iterator & x){
        n_padre = x.n_padre;
        pos_actual = x.pos_actual;
        return *this;
        };



template <typename T, int K >
inline    bool ktree<T,K>::node::child_iterator::operator==(const child_iterator & x){
        return ((n_padre==x.n_padre) && (pos_actual==x.pos_actual));
    }


template <typename T, int K >
inline    bool ktree<T,K>::node::child_iterator::operator!=(const child_iterator & x){
        if (n_padre!=x.n_padre) return true;
        else return pos_actual!=x.pos_actual;
    }

// ==============================
// CONST_NODE




template <typename T, int K>
inline
ktree<T,K>::const_node::const_node()
{
  elnodo = 0;
};





template <typename T, int K>
inline
ktree<T,K>::const_node::const_node(const typename ktree<T,K>::const_node & n)
  : elnodo(n.elnodo)
{

}




template <typename T, int K>
inline
ktree<T,K>::const_node::const_node(const typename ktree<T,K>::node & n)
  : elnodo(n.elnodo)
{
}


template <typename T, int K>
inline
typename ktree<T,K>::const_node &
ktree<T,K>::const_node::operator=(const typename ktree<T,K>::const_node & n)
{
  if (&n != this){
    if (n.null())
      elnodo = 0;
    else
      elnodo = n.elnodo;
  }
  return *this;
};

template <typename T, int K>
inline
bool ktree<T,K>::const_node::null() const
{
  return elnodo == 0;
};



template <typename T, int K>
inline
typename ktree<T,K>::const_node ktree<T,K>::const_node::parent() const
{
  return (elnodo->pad);
};

template <typename T, int K>
inline
typename ktree<T,K>::const_node ktree<T,K>::const_node::k_child(int k) const
{
  return (elnodo->hijos[k]);
};


template <typename T, int K>
inline
typename ktree<T,K>::const_node ktree<T,K>::const_node::operator[](int k) const
{
  return (elnodo->hijos[k]);
};

template <typename T, int K>
inline
const T & ktree<T,K>::const_node::operator*() const
{
  return elnodo->etiqueta;
};


template <typename T, int K>
inline
bool ktree<T,K>::const_node::operator==(const const_node & n) const
{
  return elnodo == n.elnodo;
};

template <typename T, int K>
inline
bool ktree<T,K>::const_node::operator!=(const const_node & n) const
{
  return elnodo != n.elnodo;
};

/*____________________________________________________________ */

template <typename T, int K >
inline
  int ktree<T,K>::const_node::child_number( ) const{

if (elnodo->pad.null())
  return -1;
else {
  int pos;
  for (pos=0; pos <K; pos++){
   typename ktree<T,K>::node p,h;
   p = elnodo->pad;
   h = p.elnodo->hijos[pos];
   if (h.elnodo==elnodo)
     return pos;
  }
}
cout << "Error n no es hijo de su supuesto padre" << endl;
}



  /// ITERADOR SOBRE const_NODO


template <typename T, int K >
inline   ktree<T,K>::const_node::child_iterator::child_iterator()
{

}


template <typename T, int K >
inline    ktree<T,K>::const_node::child_iterator::child_iterator(const child_iterator & x)
{n_padre = x.n_padre;pos_actual = x.pos_actual;};


template <typename T, int K >
inline    ktree<T,K>::const_node::child_iterator::child_iterator(const  typename ktree<T,K>::node::child_iterator & x)
{n_padre = x.n_padre;pos_actual = x.pos_actual;};


template <typename T, int K >
inline typename  ktree<T,K>::const_node    ktree<T,K>::const_node::child_iterator::operator*( ) const{
        return (*n_padre).hijos[pos_actual];
    }


template <typename T, int K >
inline typename  ktree<T,K>::const_node::child_iterator & ktree<T,K>::const_node::child_iterator::operator++(){

        do{

         pos_actual++;
        } while ((pos_actual <K) && ((*n_padre).hijos[pos_actual].null()));

        return *this;
    }


template <typename T, int K >
inline typename  ktree<T,K>::const_node::child_iterator  ktree<T,K>::const_node::child_iterator::operator++(int x){
typename ktree<T,K>::const_node::child_iterator aux(*this);
++(*this);
return aux;
    }



template <typename T, int K >
inline typename  ktree<T,K>::const_node::child_iterator & ktree<T,K>::const_node::child_iterator::operator=(const child_iterator & x){
        n_padre = x.n_padre;
        pos_actual = x.pos_actual;
        return *this;
        };



template <typename T, int K >
inline    bool ktree<T,K>::const_node::child_iterator::operator==(const child_iterator & x){
        return ((n_padre==x.n_padre) && (pos_actual==x.pos_actual));
    }


template <typename T, int K >
inline    bool ktree<T,K>::const_node::child_iterator::operator!=(const child_iterator & x){
        if (n_padre!=x.n_padre) return true;
        else return pos_actual!=x.pos_actual;
    }

//IMPLEMENTAR
