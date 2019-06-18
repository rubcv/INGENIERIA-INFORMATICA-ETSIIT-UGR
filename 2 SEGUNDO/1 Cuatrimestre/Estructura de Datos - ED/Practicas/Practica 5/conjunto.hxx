
/* ----- CONSTRUCTORES ------ */

/** @brief Constructor por defecto
*/

template <typename T, typename CMP>
conjunto<T,CMP>::conjunto(){
  vm = vector<mutacion>(); // Constructor por defecto, vector vacio
}

/** @brief Constructor de copia
* @param d conjunto para hacer la copia
*/
template <typename T, typename CMP>
conjunto<T,CMP>::conjunto(const conjunto<T,CMP> &d){
  vm = d.vm;
  comp = d.comp;
}


/* ----- FIND ------ */


/** @brief Buscador de mutacion en vector de mutaciones
* @param s Mutacion a buscar
* @return resul Par de datos con la mutacion y bool de si esta o no
*/
template <typename T,typename CMP>
typename conjunto<T, CMP>::iterator conjunto<T,CMP>::find (const value_type & s){
  conjunto<T,CMP>::iterator sal;
  sal.it = std::lower_bound(vm.begin(),vm.end(),s,comp);
  sal.elvector= & vm;
  if(sal.it == vm.end() || !(!comp((*sal.it),s) && !comp(s,(*sal.it))))
    sal.it = vm.end();

  return sal;
}

template <typename T,typename CMP>
typename conjunto<T, CMP>::const_iterator conjunto<T,CMP>::find (const value_type & s) const{
  conjunto<T,CMP>::const_iterator sal;
  sal.it = std::lower_bound(vm.begin(),vm.end(),s,comp);
  sal.elvector=& vm;
  if(sal.it == vm.end() || !(!comp((*sal.it),s) && !comp(s,(*sal.it))))
    sal.it = vm.end();

  return sal;
}

/* ----- COUNT ------ */

/** @brief Cuenta el numero de apariciones en vm de la mutacion e
* @param e Mutacion a buscar
* @return total contador con numero de apariciones
*/
template <typename T,typename CMP>
typename conjunto<T,CMP>::size_type conjunto<T,CMP>::count (const value_type & e) const{
    conjunto<T,CMP>::const_iterator sal;
    sal.it= std::lower_bound(vm.cbegin(),vm.cend(),e,comp);
    sal.elvector=& vm;
     if ((sal.it==vm.end()) || !( !comp(*sal.it,e) && !(comp(e,*sal.it))))
        return 0;
     else
        return 1;
  }

// ------------- INSERT -------------------

	/** @brief Inserta una entrada en el conjunto
	@param e entrada a insertar
	@return pair con true si la entrada se ha podido insertar con éxito, \
   esto es, no existe una mutación con igual par chr/pos ni igual ID en el conjunto. False en caso contrario.
	@post Si e no esta en el conjunto, el size() sera incrementado en 1.
	*/
  template<typename T, typename CMP>
  pair<typename conjunto<T, CMP>::iterator,bool> conjunto<T,CMP>::insert(const value_type & e){
      pair<typename conjunto<T,CMP>::iterator,bool> salida;
      salida.first.it = std::lower_bound(vm.begin(),vm.end(),e,comp);
      salida.first.elvector=& vm;
      salida.second = false;

      if(salida.first.it == vm.end()){
        vm.insert(salida.first.it,e);
        salida.second = true;
      }else if (!(!comp(*salida.first.it,e) && !comp(e,(*salida.first.it)))){
        vm.insert(salida.first.it,e);
        salida.second = true;
      }

      return salida;
  }


  /** @brief Borra una entrada en el conjunto .
	Busca la entrada y si la encuentra la borra.
	@param[in] position iterador donde esta la entrada a borrar
	@post Si esta en el conjunto su tamaño se decrementa en 1.
	*/

  template<typename T, typename CMP>
  typename conjunto<T, CMP>::iterator conjunto<T,CMP>::erase(const iterator posicion){
    conjunto<T,CMP>::iterator sal;
    sal.it= vm.erase(posicion.it);
    return sal;
  }

/** @brief Borra una entrada en el conjunto .
Busca la entrada y si la encuentra la borra.
@param[in] e entrada a borrar
@post Si esta en el conjunto su tamaño se decrementa en 1.
*/

template<typename T, typename CMP>
typename conjunto<T,CMP>::size_type conjunto<T,CMP>::erase(const value_type & val){
  size_type cont=0;
  conjunto<T,CMP>::iterator it;
  it.it = std::lower_bound(vm.begin(),vm.end(),val,comp);
  it.elvector = & vm;
  if((!comp(*it.it,val) && !comp(val,*it.it))){
    vm.erase(it.it);
      cont=1;
}
  return cont;
}



  /** @brief Borra todas las entradas del conjunto, dejandolo vacio.
  @post El conjunto se modifica, quedando vacio.
  */
  template <typename T, typename CMP>
  void conjunto<T,CMP>::clear(){
    if(!vm.empty()){
      vm.clear();
    }
  }

  /** @brief numero de entradas en el conjunto
  @post  No se modifica el conjunto.
  @return numero de entradas en el conjunto
  * Devolver size_type
  */
  template <typename T, typename CMP>
  typename conjunto<T,CMP>::size_type conjunto<T,CMP>::size() const{
    conjunto<T,CMP>::size_type res = this->vm.size();
    return res;
  }

  /** @brief Chequea si el conjunto esta vacio (size()==0)
  @post  No se modifica el conjunto.
  */
template <typename T, typename CMP>
  bool conjunto<T,CMP>::empty() const{
    return vm.empty();
  }



  /** @brief operador de asignación
  @param[in] org conjunto a copiar.
  @return Crea y devuelve un conjunto duplicado exacto de org.
  */
  template <typename T, typename CMP>
  	conjunto<T,CMP> & conjunto<T,CMP>:: operator=( const conjunto & org){
      if(this != &org){
        vm = org.vm;
        comp = org.comp;
      }
      return *this;
    }


    /* ------------------ ITERADORES --------------------- */


    /** @brief Devuelve begin del conjunto
    */

    template<typename T, typename CMP>
    typename conjunto<T, CMP>::iterator conjunto< T, CMP >::begin (){
      conjunto<T,CMP>::iterator sal;
      sal.it=vm.begin();
      sal.elvector=& vm;
      return sal;
    }

    /** @brief Devuelve end del conjunto
    */

    template<typename T, typename CMP>
    typename conjunto<T, CMP>::iterator conjunto< T, CMP >::end (){
      conjunto<T,CMP>::iterator sal;
      sal.it=vm.end();
      sal.elvector=& vm;
      return sal;
    }
    /** @brief Devuelve const begin del conjunto
    */
    template<typename T, typename CMP>
    typename conjunto<T, CMP>::const_iterator conjunto< T, CMP >::cbegin () const {
      conjunto<T,CMP>::const_iterator sal;
      sal.it=vm.cbegin();
      sal.elvector=& vm;
      return sal;
    }

    /** @brief Devuelve const end del conjunto
    */
    template<typename T, typename CMP>
    typename conjunto<T, CMP>::const_iterator conjunto< T, CMP >::cend () const {
      conjunto<T,CMP>::const_iterator sal;
      sal.it=vm.cend();
      sal.elvector=& vm;
      return sal;
    }


  /* ------------------ SECURE ITERATOR --------------------- */
  template<typename T, typename CMP>
  typename conjunto<T, CMP>::secure_iterator conjunto< T, CMP >::sbegin (){
    conjunto<T,CMP>::secure_iterator sal;
    sal.it=vm.begin();
    sal.elvector=& vm;
    return sal;
  }


  template<typename T, typename CMP>
  typename conjunto<T, CMP>::secure_iterator conjunto< T, CMP >::send (){
    conjunto<T,CMP>::secure_iterator sal;
    sal.it=vm.end();
    sal.elvector=& vm;
    return sal;
  }


  template<typename T, typename CMP>
  typename conjunto<T, CMP>::const_secure_iterator conjunto< T, CMP >::csbegin () const {
    conjunto<T,CMP>::const_secure_iterator sal;
    sal.it=vm.cbegin();
    sal.elvector=& vm;
    return sal;
  }


  template<typename T, typename CMP>
  typename conjunto<T, CMP>::const_secure_iterator conjunto< T, CMP >::csend () const {
    conjunto<T,CMP>::const_secure_iterator sal;
    sal.it=vm.cend();
    sal.elvector=& vm;
    return sal;
  }



  /* ------------------ ITEARTOR IMPAR --------------------- */
  template<typename T, typename CMP>
  typename conjunto<T, CMP>::impar_iterator conjunto< T, CMP >::ibegin (){
    conjunto<T,CMP>::impar_iterator sal;
    sal.it=vm.begin();
    sal.elvector=& vm;
    while ((*sal.it).getPos()%2 == 0 && sal.it != vm.end())
      ++(sal.it);
    return sal;
  }

  template<typename T, typename CMP>
  typename conjunto<T, CMP>::impar_iterator conjunto< T, CMP >::iend (){
    conjunto<T,CMP>::impar_iterator sal;
    sal.it=vm.end();
    sal.elvector=& vm;
    return sal;
  }

  template<typename T, typename CMP>
  typename conjunto<T, CMP>::const_impar_iterator conjunto< T, CMP >::cibegin () const {
    conjunto<T,CMP>::const_impar_iterator sal;
    sal.it=vm.cbegin();
    sal.elvector=& vm;
    while ((*sal.it).getPos() % 2 == 0 && sal.it != vm.cend())
      ++(sal.it);
    return sal;
  }


  template<typename T, typename CMP>
  typename conjunto<T, CMP>::const_impar_iterator conjunto< T, CMP >::ciend () const {
    conjunto<T,CMP>::const_impar_iterator sal;
    sal.it=vm.cend();
    sal.elvector=& vm;
    return sal;
  }


  /* ------------------ LOWER BOUND --------------------- */

  /** @brief cuenta cuantas entradas hay en el conjunto por debajo ('antes', '<') de los parámetros dados.
  @param[in] e entrada.
  @return Devuelve un iterador al primer elemento que cumple que "elemento<e" es falso, esto es, el primer elemento que  es mayor o igual que e
  @post no modifica el conjunto.
  */


  template<typename T, typename CMP>
  typename conjunto<T, CMP>::iterator conjunto< T, CMP >::lower_bound (const value_type & val){
    conjunto<T,CMP>::iterator sal;
    sal.it = std::lower_bound(vm.begin(),vm.end(),val,comp);
    sal.elvector=& vm;
    return sal;
  }


  template<typename T, typename CMP>
  typename conjunto<T, CMP>::const_iterator conjunto< T, CMP >::lower_bound (const value_type & val) const {
    conjunto<T,CMP>::const_iterator sal;
    sal.it = std::lower_bound(vm.begin(),vm.end(),val,comp);
    sal.elvector=& vm;
    return sal;
  }

	/** @brief cuenta cuantas entradas hay en el conjunto por encima ('después', '>') de los parámetros dados.
	@param[in] e entrada. Devuelve un iterador al primer elemento que cumple que "elemento>e", esto es, el primer elemento ESTRICTAMENTE mayor que e
	@post no modifica el conjunto.
	*/
  template<typename T, typename CMP>
  typename conjunto<T, CMP>::iterator conjunto< T, CMP >::upper_bound (const value_type & val){
    conjunto<T,CMP>::iterator sal;
    sal.it = std::upper_bound(vm.begin(),vm.end(),val,comp);
    sal.elvector=& vm;
    return sal;
  }

  template<typename T, typename CMP>
  typename conjunto<T, CMP>::const_iterator conjunto< T, CMP >::upper_bound (const value_type & val) const {
    conjunto<T,CMP>::const_iterator sal;
    sal.it = std::upper_bound(vm.begin(),vm.end(),val,comp);
    sal.elvector=& vm;
    return sal;
  }



// ----------------------------------------------------------

  /** \invariant

  	IR: rep ==> bool

  	\li Para todo i, 0 <= i < vm.size() se cumple
  		- vm[i].chr está en ("1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "X", "Y", "MT")
  		- vm[i].pos > 0;
  	\li Para todo i, 0 <= i < C.vm.size()-1 se cumple:
  	  	a) si vm[i].chr == vm[i+1].chr, entonces: vm[i].pos < vm[i+1].pos
  	  	b) si vm[i].chr != vm[i+1].chr, entonces  vm[i].chr < vm[i+1].chr (donde el orden para el número de cromosoma se rige por "1"<"2"<"3"<...<"22"<"X"<"Y"<"MT")
  	*/


  	/** @brief Chequea el Invariante de la representacion
  	    @return true si el invariante es correcto, falso en caso contrario
  	*/
template <typename T, typename CMP>
  bool conjunto<T,CMP>::cheq_rep() const{
    conjunto<T,CMP>::iterator sal;
  	sal.it = vm.cbegin();
    while(sal.it!=vm.end()){
      if((sal.it->getChr())!="1"||"2"||"3"||"4"||"5"||"6"||"7"||"8"||"9"||"10"||"11"||"12"||"13"||"14"||"15"||"16"||"17"||"18"||"19"||"20"||"21"||"22"||"X"||"Y"||"MT"){ // Para ver si esta dentro de los cromosomas posibles
        return false;
      };
      if(sal.it!=(vm.end()-1)){
        if(!((*sal.it)<(*(sal.it++))))
            return false;
      }
    }
    return true;
  }


// -------------------------------------------------------

  /** @brief imprime todas las entradas del conjunto
  @post No se modifica el conjunto.
  Implementar tambien esta funcion
  	*/
    template <typename T, typename CMP>
    ostream &  operator<<( ostream & sal, const conjunto<T,CMP> & C){
      typename conjunto<T,CMP>::const_iterator it = C.cbegin();
      int contador = 1;
      while(it != C.cend()){
        sal<< "--------------------- MUTACION: " << contador << " ---------------------" << endl;
        sal<< *it;
        ++it;
        contador++;
      }
      return sal;
    }



// ------------------------ CLASES ITERATOR ------------------------ */

// ------------------------ ITERATOR ------------------------ */

template<typename T, typename CMP>
conjunto<T,CMP>::iterator::iterator(){
 elvector=0;
}

template<typename T, typename CMP>
conjunto<T,CMP>::iterator::iterator(const conjunto<T,CMP>::iterator & x){
  elvector = x.elvector ;
  it = x.it;
}

template<typename T, typename CMP>
const T & conjunto<T,CMP>::iterator::operator*(){
  return *it;
}

template<typename T, typename CMP>
typename conjunto<T,CMP>::iterator & conjunto<T,CMP>::iterator::operator++(){
  it++;
    return *this;
}

template<typename T, typename CMP>
typename conjunto<T,CMP>::iterator  conjunto<T,CMP>::iterator::operator++(int i){
	conjunto<T,CMP>::iterator itpos=*this;
  it++;
  return itpos;
}

template<typename T, typename CMP>
typename conjunto<T,CMP>::iterator & conjunto<T,CMP>::iterator::operator--(){
  it--;
    return *this;
}

template<typename T, typename CMP>
typename conjunto<T,CMP>::iterator  conjunto<T,CMP>::iterator::operator--(int i){
	conjunto<T,CMP>::iterator itpos = *this;
  it--;
  return itpos;
}

template<typename T, typename CMP>
bool conjunto<T,CMP>::iterator::operator==(const conjunto<T,CMP>::iterator & x) const {
  if(elvector == x.elvector && it == x.it){
    return true;
  }
  return false;
}

template<typename T, typename CMP>
bool conjunto<T,CMP>::iterator::operator!=(const conjunto<T,CMP>::iterator & x) const {
  if(!(elvector==x.elvector && it==x.it)){
    return true;
  }
  return false;
}

template<typename T, typename CMP>
typename conjunto<T,CMP>::iterator & conjunto<T,CMP>::iterator::operator=(const iterator & x){
  it=x.it;
  elvector=x.elvector;
    return (*this);
}

// ------------------------ CONST ITERATOR ------------------------ */


template<typename T, typename CMP>
conjunto<T,CMP>::const_iterator::const_iterator(){
 this->elvector=0;
}

template<typename T, typename CMP>
conjunto<T,CMP>::const_iterator::const_iterator(const conjunto<T,CMP>::const_iterator & x){
  this->elvector = x.elvector ;
  this->it = x.it;
}

template<typename T, typename CMP>
const T & conjunto<T,CMP>::const_iterator::operator*(){
  return *it;
}

template<typename T, typename CMP>
typename conjunto<T,CMP>::const_iterator & conjunto<T,CMP>::const_iterator::operator++(){
  this->it++;
    return *this;
}

template<typename T, typename CMP>
typename conjunto<T,CMP>::const_iterator  conjunto<T,CMP>::const_iterator::operator++(int i){
	conjunto<T,CMP>::const_iterator itpos = *this;
  this->it++;
  return itpos;
}

template<typename T, typename CMP>
typename conjunto<T,CMP>::const_iterator & conjunto<T,CMP>::const_iterator::operator--(){
  this->it--;
    return *this;
}

template<typename T, typename CMP>
typename conjunto<T,CMP>::const_iterator  conjunto<T,CMP>::const_iterator::operator--(int i){
	conjunto<T,CMP>::const_iterator itpos = *this;
  this->it--;
  return itpos;
}

template<typename T, typename CMP>
bool conjunto<T,CMP>::const_iterator::operator==(const conjunto<T,CMP>::const_iterator & x) const {
  if(this->elvector==x.elvector && this->it==x.it){
    return true;
  }
  return false;
}

template<typename T, typename CMP>
bool conjunto<T,CMP>::const_iterator::operator!=(const conjunto<T,CMP>::const_iterator & x) const {
  if(!(this->elvector==x.elvector && this->it==x.it)){
    return true;
  }
  return false;
}

template<typename T, typename CMP>
typename conjunto<T,CMP>::const_iterator & conjunto<T,CMP>::const_iterator::operator=(const const_iterator & x){
  this->it=x.it;
  this->elvector=x.elvector;
    return (*this);
}


// ------------------------ SECURE ITERATOR ------------------------ */

template<typename T,typename CMP>
conjunto<T,CMP>::secure_iterator::secure_iterator(){

}

template<typename T,typename CMP>
conjunto<T,CMP>::secure_iterator::secure_iterator(const secure_iterator &  x){
  this->it = x.it;
  this->elvector = x.elvector;
}

template<typename T,typename CMP>
const T & conjunto<T,CMP>::secure_iterator::operator*(){
  assert ((this->it) >= elvector->begin() && (this->it) < elvector->end());
  return *(this->it);
}

template<typename T,typename CMP>
typename conjunto<T,CMP>::secure_iterator & conjunto<T,CMP>::secure_iterator::operator++(){
  assert ((this->it) >= elvector->begin() && (this->it) < elvector->end());
  (this->it)++;
  return (*this);
}

template<typename T,typename CMP>
typename conjunto<T,CMP>::secure_iterator conjunto<T,CMP>::secure_iterator::operator++(int i){
  assert ((this->it) >= elvector->begin() && (this->it) < elvector->end());
  conjunto<T,CMP>::secure_iterator sal;
  sal.it = this->it;
  (this->it)++;
  return sal;
}

template<typename T,typename CMP>
typename conjunto<T,CMP>::secure_iterator & conjunto<T,CMP>::secure_iterator::operator--(){
  assert ((this->it) >= elvector->begin() && (this->it) < elvector->end());
  (this->it)--;
  return (*this);
}

template<typename T,typename CMP>
typename conjunto<T,CMP>::secure_iterator conjunto<T,CMP>::secure_iterator::operator--(int i){
  assert ((this->it) >= elvector->begin() && (this->it) < elvector->end());
  conjunto<T,CMP>::secure_iterator sal;
  sal.it = this->it;
  (this->it)--;
  return sal;
}

template<typename T,typename CMP>
bool conjunto<T,CMP>::secure_iterator::operator==(const secure_iterator & x) const {
  assert ((this->it) >= elvector->begin() && (this->it) < elvector->end());
  assert ((x.it) >= elvector->begin() && (x.it) < elvector->end());
  return (this->it == x.it);
}

template<typename T,typename CMP>
bool conjunto<T,CMP>::secure_iterator::operator!=(const secure_iterator & x) const {
  assert ((this->it) >= elvector->begin() && (this->it) < elvector->end());
  assert ((x.it) >= elvector->begin() && (x.it) < elvector->end());
  return (this->it != x.it);
}

template<typename T,typename CMP>
typename conjunto<T,CMP>::secure_iterator & conjunto<T,CMP>::secure_iterator::operator=(const secure_iterator & x){
  assert ((this->it) >= elvector->begin() && (this->it) < elvector->end());
  assert ((x.it) >= elvector->begin() && (x.it) < elvector->end());
  this->it = x.it;
  this->elvector = x.elvector;

  return (*this);
}

// ------------------------ CONST-SECURE ITERATOR ------------------------ */
template<typename T,typename CMP>
conjunto<T,CMP>::const_secure_iterator::const_secure_iterator(){

}

template<typename T,typename CMP>
conjunto<T,CMP>::const_secure_iterator::const_secure_iterator(const const_secure_iterator &  x){
  this->it = x.it;
  this->elvector = x.elvector;
}

template<typename T,typename CMP>
const T & conjunto<T,CMP>::const_secure_iterator::operator*(){
  assert ((this->it) >= elvector->cbegin() && (this->it) < elvector->cend());
  return *(this->it);
}

template<typename T,typename CMP>
typename conjunto<T,CMP>::const_secure_iterator & conjunto<T,CMP>::const_secure_iterator::operator++(){
  assert ((this->it) >= elvector->cbegin() && (this->it) < elvector->cend());
  (this->it)++;
  return (*this);
}

template<typename T,typename CMP>
typename conjunto<T,CMP>::const_secure_iterator conjunto<T,CMP>::const_secure_iterator::operator++(int i){
  assert ((this->it) >= elvector->cbegin() && (this->it) < elvector->cend());
  conjunto<T,CMP>::const_secure_iterator sal;
  sal.it = this->it;
  (this->it)++;
  return sal;
}

template<typename T,typename CMP>
typename conjunto<T,CMP>::const_secure_iterator & conjunto<T,CMP>::const_secure_iterator::operator--(){
  assert ((this->it) >= elvector->cbegin() && (this->it) < elvector->cend());
  (this->it)--;
  return (*this);
}

template<typename T,typename CMP>
typename conjunto<T,CMP>::const_secure_iterator conjunto<T,CMP>::const_secure_iterator::operator--(int i){
  assert ((this->it) >= elvector->cbegin() && (this->it) < elvector->cend());
  conjunto<T,CMP>::const_secure_iterator sal;
  sal.it = this->it;
  (this->it)--;
  return sal;
}

template<typename T,typename CMP>
bool conjunto<T,CMP>::const_secure_iterator::operator==(const const_secure_iterator & x) const {
  assert ((this->it) >= elvector->cbegin() && (this->it) < elvector->cend());
  assert ((x.it) >= x.it.cbegin() && (x.it) < x.it.cend());
  return (this->it == x.it);
}

template<typename T,typename CMP>
bool conjunto<T,CMP>::const_secure_iterator::operator!=(const const_secure_iterator & x) const {
  assert ((this->it) >= elvector->cbegin() && (this->it) < elvector->cend());
  assert ((x.it) >= x.it.cbegin() && (x.it) < x.it.cend());
  return (this->it != x.it);
}

template<typename T,typename CMP>
typename conjunto<T,CMP>::const_secure_iterator & conjunto<T,CMP>::const_secure_iterator::operator=(const const_secure_iterator & x){
  assert ((this->it) >= elvector->cbegin() && (this->it) < elvector->cend());
  assert ((x.it) >= x.it.cbegin() && (x.it) < x.it.cend());
  this->it = x.it;
  this->elvector = x.elvector;

  return (*this);
}

// ------------------------ IMPAR ITERATOR ------------------------ */

template<typename T, typename CMP>
conjunto<T,CMP>::impar_iterator::impar_iterator(){
 this->elvector=0;
}

template<typename T, typename CMP>
conjunto<T,CMP>::impar_iterator::impar_iterator(const conjunto<T,CMP>::impar_iterator & x){
  this->elvector = x.elvector ;
  this->it = x.it;
}

template<typename T, typename CMP>
const T & conjunto<T,CMP>::impar_iterator::operator*(){

    return *it;
}

template<typename T, typename CMP>
typename conjunto<T,CMP>::impar_iterator & conjunto<T,CMP>::impar_iterator::operator++(){
  while((*(this->it)).getPos()%2==0 && (*this).it != elvector->end())
{
  this->it++;
  }
  return *this;
}

template<typename T, typename CMP>
typename conjunto<T,CMP>::impar_iterator  conjunto<T,CMP>::impar_iterator::operator++(int i){
conjunto<T,CMP>::iterator itpos;
  while((*(this->it)).getPos()%2==0 && (*this).it != elvector->end()){
  itpos=*this;
  this->it++;
}
return itpos;
}

template<typename T, typename CMP>
bool conjunto<T,CMP>::impar_iterator::operator==(const conjunto<T,CMP>::impar_iterator & x) const {
  if(this->elvector==x.elvector && this->it==x.it){
    return true;
  }
  return false;
}


template<typename T, typename CMP>
bool conjunto<T,CMP>::impar_iterator::operator!=(const conjunto<T,CMP>::impar_iterator & x) const {
  if(!(this->elvector==x.elvector && this->it==x.it)){
    return true;
  }
  return false;
}


template<typename T, typename CMP>
typename conjunto<T,CMP>::impar_iterator & conjunto<T,CMP>::impar_iterator::operator=(const impar_iterator & x){
  this->it=x.it;
  this->elvector=x.elvector;
    return (*this);
}

// ------------------------ CONST IMPAR ITERATOR ------------------------ */

template<typename T, typename CMP>
conjunto<T,CMP>::const_impar_iterator::const_impar_iterator(){
 this->elvector=0;
}

template<typename T, typename CMP>
conjunto<T,CMP>::const_impar_iterator::const_impar_iterator(const conjunto<T,CMP>::const_impar_iterator & x){
  this->elvector = x.elvector ;
  this->it = x.it;
}

template<typename T, typename CMP>
const T & conjunto<T,CMP>::const_impar_iterator::operator*(){

    return *it;
}

template<typename T, typename CMP>
typename conjunto<T,CMP>::const_impar_iterator & conjunto<T,CMP>::const_impar_iterator::operator++(){
  while((*(this->it)).getPos()%2==0 && (*this).it != elvector->end())
{
  this->it++;
  }
  return *this;
}

template<typename T, typename CMP>
typename conjunto<T,CMP>::const_impar_iterator  conjunto<T,CMP>::const_impar_iterator::operator++(int i){
conjunto<T,CMP>::iterator itpos;
  while((*(this->it)).getPos()%2==0 && (*this).it != elvector->end()){
  itpos=*this;
  this->it++;
}
return itpos;
}

template<typename T, typename CMP>
bool conjunto<T,CMP>::const_impar_iterator::operator==(const conjunto<T,CMP>::const_impar_iterator & x) const {
  if(this->elvector==x.elvector && this->it==x.it){
    return true;
  }
  return false;
}


template<typename T, typename CMP>
bool conjunto<T,CMP>::const_impar_iterator::operator!=(const conjunto<T,CMP>::const_impar_iterator & x) const {
  if(!(this->elvector==x.elvector && this->it==x.it)){
    return true;
  }
  return false;
}


template<typename T, typename CMP>
typename conjunto<T,CMP>::const_impar_iterator & conjunto<T,CMP>::const_impar_iterator::operator=(const const_impar_iterator & x){
  this->it=x.it;
  this->elvector=x.elvector;
    return (*this);
}
