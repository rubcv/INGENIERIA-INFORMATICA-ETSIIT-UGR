//-*-Mode: C++;-*-


/*
************************************************************
* Implementaci��n
************************************************************
*/

/*
  Funci��n de Abstracci��n:
  ----------------------
  Dado el objeto del tipo rep r, r = {laraiz}, el objeto
  abstracto al que representa es:
  a) Arbol nulo, si r.laraiz.null().
  b) Arbol con un ��nico nodo de etiqueta *(r.laraiz)
     si r.laraiz.left().null() y r.laraiz.dcha().null()

  c)                    *(r.laraiz)
                         /       \
                        /         \
      Arbol(r.laraiz.left())    Arbol(r.laraiz.right())


  Invariante de Representaci��n:
  ----------------------------
  Si !r.laraiz.null(),
  -   r.laraiz.parent().null().

  Para cualquier nodo n del ��rbol:
  Si !n.left().null()
      n.left().parent() == n;
  Si !n.right().null()
      n.right().parent() == n;

*/


#include <cassert>

using namespace std;
/*____________________________________________________________ */
/*____________________________________________________________ */
//               FUNCIONES PUBLICAS
/*____________________________________________________________ */
/*____________________________________________________________ */


template <typename T,int K>
inline
ktree<T,K>::ktree()
{
}

/*____________________________________________________________ */

template <typename T,int K>
inline
ktree<T,K>::ktree(const T & e)
{
 laraiz.elnodo = new celdaArbol(e);
}


template<typename T, int K>
void recorrido_por_niveles(typename ktree<T,K>::const_node n){
  typename ktree<T,K>::const_node aux;
  queue<typename ktree<T,K>::const_node > cola;

  if (!n.null())
    cola.push(n);

  while (!cola.empty()){
    aux = cola.front();
    cola.pop();
    cout << "(" << (*aux) << "); ";

    for (auto hijo : aux)
    cola.push(hijo);
  }
  cout << endl;
}


/*____________________________________________________________ */

template <typename T,int K>
int ktree<T,K>::count(ktree<T,K>::node n) const
{
  if (n.null())
    return 0;
  else {
    int cuantos = 0;
    for (int i = 0; i< K; i++)
      cuantos+= count(n.k_child(i));
    return 1 + cuantos;
  }
}



/*____________________________________________________________ */


template <typename T,int K>
void ktree<T,K>::destroy(typename ktree<T,K>::node n)
{
  if (!n.null()) {
    for (int i=0; i<K; i++)
      destroy(n.k_child(i));
    n.remove();
  }
}

template <typename T,int K>
inline
ktree<T,K>::~ktree()
{

 destroy(laraiz);
}


/*____________________________________________________________ */

template <typename T, int K >
void ktree<T,K>::clear()
{
  destroy(laraiz);
  laraiz = typename ktree<T,K>::node();
}

/*____________________________________________________________ */

template <typename T, int K >
inline
typename ktree<T,K>::size_type ktree<T,K>::size() const
{
  return count(laraiz);
}

/*____________________________________________________________ */

template <typename T, int K >
inline
bool ktree<T,K>::empty() const
{
  return laraiz == ktree<T,K>::node();
}

/*____________________________________________________________ */

template <typename T, int K >
inline
typename ktree<T,K>::node ktree<T,K>::root()
{
  return laraiz;
}


template <typename T, int K >
inline
typename ktree<T,K>::const_node ktree<T,K>::root() const
{
  return laraiz;
}


/*____________________________________________________________ */
template <typename T, int K >
void ktree<T,K>::insert_k_child( typename ktree<T,K>::node & n, int k, const T & e){
  //cout << K << endl;
  ktree<T,K> aux(e);
  insert_k_child(n,k, aux);
}

/*____________________________________________________________ */
template <typename T, int K >
void ktree<T,K>::insert_k_child(  typename ktree<T,K>::node   n, int k,   ktree<T,K> & rama)
{
  assert(!n.null());

  typename ktree<T,K>::node aux(n.k_child(k));
  destroy(aux);
 //cout << "destruyo hijo "<< k<< endl;
  n.k_child(k,rama.laraiz);
  //cout << *n.k_child(k)<<endl;
  if (!n.k_child(k).null())
    n.k_child(k).parent(n);
  rama.laraiz = typename ktree<T,K>::node();
  //cout << "Salgo"<< endl;
}


template <typename T, int K >
inline
void ktree<T,K>::assing(const ktree<T,K> & a, typename ktree<T,K>::node n)
{
    destroy(laraiz);
    if (n.null()) return;
    else {
    copy(laraiz, n);
    if (!laraiz.null())
      laraiz.parent(typename ktree<T,K>::node());
  }
}

/*____________________________________________________________ */


template <typename T, int K >
inline
void ktree<T,K>::assing(const T & e)
{
   destroy(laraiz);
   laraiz.elnodo = new celdaArbol(e);
}

/*____________________________________________________________ */


/*____________________________________________________________ */


template <typename T, int K >
template <class T2S>
inline
string  ktree<T,K>::serialize(const T & nulo, char delim, T2S toStr) const
{
typename ktree<T,K>::const_node aux= root();
queue<typename ktree<T,K>::const_node > cola;
string cadena;
string dl(1,delim);

if (!aux.null()){
  cola.push(aux);
  cadena= toStr(*aux)+dl;
}
while (!cola.empty()){
  aux = cola.front();
  cola.pop();
  // < Accion sobre el nodo, imprimir sus descencientes ->
  for (int i=0; i<K;i++){
   if (!aux.k_child(i).null()){
       cadena+=toStr(*(aux.k_child(i)))+dl;
       cola.push(aux.k_child(i));
   } else cadena+=toStr(nulo)+dl;
  }
}
return cadena;
}




template <typename T, int K >
template <class S2T>
inline
void  ktree<T,K>::deserialize(const string & cadena, const T & nulo, char delim,  S2T Str2T) {

  queue<typename ktree<T,K>::node > cola;
  typename ktree<T,K>::node nact;
  T tval;
  size_type pos = 0,pos_act=0;

  // procesamos la raiz
     pos_act = cadena.find_first_of(';',pos);
     string val = cadena.substr(pos,pos_act-pos);
     tval  = Str2T(val);
     pos = pos_act+1;
     (*this).assing(tval);
     cola.push( (*this).root() );

  while ( pos < cadena.size() ) {
     nact = cola.front();
     cola.pop();
     for (int i=0;i<K;i++) {
       pos_act =cadena.find_first_of(delim,pos);
       string val = cadena.substr(pos,pos_act-pos);
       tval  = Str2T(val);
       if (tval!=nulo){
  	 (*this).insert_k_child(nact,i,tval);
  	 cola.push(nact[i]);
       }
       pos = pos_act+1;
     }
   } // del while

}

/*____________________________________________________________ */


template <typename T, int K >
inline
ktree<T,K> &
ktree<T,K>::operator=(const ktree<T,K> & a)
{
  if (&a != this) {
    destroy(laraiz);
    copy(laraiz, a.laraiz);
    if (!laraiz.null())
      laraiz.parent(typename ktree<T,K>::node());
  }
  return *this;
}

template <typename T, int K >
void ktree<T,K>::copy(ktree<T,K>::node & dest, const ktree<T,K>::node & orig)
{
  if (orig.null())
    dest = typename ktree<T,K>::node();
  else {
      dest = node(*orig);
      for (int i=0;i<K;i++) {
         typename ktree<T,K>::node aux(dest.k_child(i));
         copy (aux, orig.k_child(i));
         dest.k_child(i,aux);
         if (!dest.k_child(i).null())
           dest.k_child(i).parent(dest);
      }
    }
}
/*____________________________________________________________ */

template <typename T, int K >
bool ktree<T,K>::equals(ktree<T,K>::node n1, ktree<T,K>::node n2) const
{
  if (n1.null() && n2.null())
    return true;
  if (n1.null() || n2.null())
    return false;
  if (*n1 != *n2)
    return false;
  for (int i=0; i<K;i++)
	if (!equals(n1.k_child(i),n2.k_child(i)))
    return false;
  return true;
}

/*____________________________________________________________ */

template <typename T, int K >
inline
bool ktree<T,K>::operator==(const ktree<T,K> & a) const
{
  return equals(laraiz, a.laraiz);
}

/*____________________________________________________________ */

template <typename T, int K >
inline bool ktree<T,K>::operator!=(const ktree<T,K> & a) const
{
  return !(*this == a);
}


/*____________________________________________________________ */

template <typename T, int K >
inline
void ktree<T,K>::prune_k_child(typename ktree<T,K>::node n, int i,
			    ktree<T,K> & orig)
{
  assert(!n.null());

  destroy(orig.laraiz);
  orig.laraiz = n.k_child(i);
  if (!orig.laraiz.null())
    orig.laraiz.parent(typename ktree<T,K>::node());
  n.k_child(i,typename ktree<T,K>::node());
}



/*____________________________________________________________ */

template <typename T, int K >
inline typename  ktree<T,K>::node::child_iterator  ktree<T,K>::node::begin(){
     child_iterator sal;
     sal.n_padre=elnodo;
     int i=0;
     while ((i<K ) && ( (*elnodo).hijos[i].null())){
            i++;
     }
     sal.pos_actual = i;
     return sal;

 }


/*____________________________________________________________ */


template <typename T, int K >
inline typename  ktree<T,K>::node::child_iterator  ktree<T,K>::node::end(){
     child_iterator sal;
     sal.n_padre=elnodo;
     sal.pos_actual=K;
     return sal;
 }




/*____________________________________________________________ */


template <typename T, int K >
inline typename ktree<T,K>::const_node::child_iterator ktree<T,K>::const_node::begin() const{
    child_iterator sal;

     sal.n_padre=elnodo;
     int i=0;

     while ((i<K ) && ( (*elnodo).hijos[i].null())){
            i++;
     }

     sal.pos_actual = i;
     return sal;

 }
/*____________________________________________________________ */


template <typename T, int K >
inline typename ktree<T,K>::const_node::child_iterator ktree<T,K>::const_node::cbegin() const{
    child_iterator sal;
     sal.n_padre=elnodo;
     int i=0;
     while ((i<K ) && ( (*elnodo).hijos[i].null())){
            i++;
     }
     sal.pos_actual = i;
     return sal;

 }
/*____________________________________________________________ */


template <typename T, int K >
inline typename ktree<T,K>::const_node::child_iterator ktree<T,K>::const_node::end() const {
     child_iterator sal;
     sal.n_padre=elnodo;
     sal.pos_actual=K;
     return sal;
 }
/*____________________________________________________________ */


template <typename T, int K >
inline typename ktree<T,K>::const_node::child_iterator ktree<T,K>::const_node::cend() const
{
  child_iterator sal;
     sal.n_padre=elnodo;
     sal.pos_actual=K;
     return sal;
 }


/*____________________________________________________________ */
