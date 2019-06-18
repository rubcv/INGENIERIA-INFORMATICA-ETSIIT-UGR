
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
* @param e Mutacion a buscar
* @return resul Par de datos con la mutacion y bool de si esta o no
*/
template <typename T, typename CMP>
typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::find (const value_type & e) const{

  iterator i = std::lower_bound(vm.begin(), vm.end(), e, comp);
    if (i == vm.end() || !(!comp(*i,e) && !comp(e, *i))){
            i = vm.end();
    }
    return i;
}

template <typename T, typename CMP>
typename conjunto<T,CMP>::iterator conjunto<T,CMP>::find (const value_type & e) {

  const_iterator i = std::lower_bound(vm.begin(), vm.end(), e, comp);
    if (i == vm.end() || !(!comp(*i,e) && !comp(e, *i))){
            i = vm.end();
    }
    return i;
}

/* ----- COUNT ------ */

/** @brief Cuenta el numero de apariciones en vm de la mutacion e
* @param e Mutacion a buscar
* @return total contador con numero de apariciones
*/
template <typename T, typename CMP>
typename conjunto<T,CMP>::size_type conjunto<T,CMP>::count (const conjunto<T,CMP>::value_type & e) const{
  conjunto<T,CMP>::size_type total = 0;

  for(conjunto<T,CMP>::const_iterator i = this->vm.begin(); i < this->vm.end(); i++){
    if(*i == e){
      total++;
    }
  }
  return total;
}

// ------------- INSERT -------------------

	/** @brief Inserta una entrada en el conjunto
	@param e entrada a insertar
	@return pair con true si la entrada se ha podido insertar con éxito, \
   esto es, no existe una mutación con igual par chr/pos ni igual ID en el conjunto. False en caso contrario.
	@post Si e no esta en el conjunto, el size() sera incrementado en 1.
	*/
  template <typename T, typename CMP>
	pair<typename conjunto<T,CMP>::iterator,bool> conjunto<T,CMP>::insert( const conjunto<T,CMP>::value_type & e){

    pair<typename conjunto<T,CMP>::iterator,bool> resul;
    conjunto<T,CMP>::iterator i = std::lower_bound(vm.begin(), vm.end(), e, comp);

    if((i == vm.end()) || !( !comp(*i, e) && !(comp(e, *i)))){
      resul.second = false;
      resul.first = vm.end();
    }else{
      resul.second = true;
      resul.first = i;
      vm.insert(i, e);
    }
    return resul;
  }



  /** @brief Borra una entrada en el conjunto .
	Busca la entrada y si la encuentra la borra.
	@param[in] position iterador donde esta la entrada a borrar
	@post Si esta en el conjunto su tamaño se decrementa en 1.
	*/

template <typename T, typename CMP>
  typename conjunto<T,CMP>::iterator  conjunto<T,CMP>::erase (const conjunto<T,CMP>::iterator position){
        return vm.erase(position);
}

/** @brief Borra una entrada en el conjunto .
Busca la entrada y si la encuentra la borra.
@param[in] e entrada a borrar
@post Si esta en el conjunto su tamaño se decrementa en 1.
*/

template <typename T, typename CMP>
  typename conjunto<T,CMP>::size_type conjunto<T,CMP>::erase (const typename conjunto<T,CMP>::value_type & e){

    bool esta = false;

    for(conjunto<T,CMP>::iterator i = this->vm.begin(); i < this->vm.end(); i++){
      if(*i == e){
        esta = true;
      }
      if(esta){
        this->vm.erase(i);
        return 1;
      }
    }
    return 0;
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


    /** @brief Devuelve begin del conjunto
    */

    template <typename T, typename CMP>
      typename conjunto<T,CMP>::iterator conjunto<T,CMP>::begin (){
          return vm.begin();
      }

    /** @brief Devuelve end del conjunto
    */

    template <typename T, typename CMP>
      typename conjunto<T,CMP>::iterator conjunto<T,CMP>::end (){
          return vm.end();
      }

    /** @brief Devuelve const begin del conjunto
    */
    template <typename T, typename CMP>
      typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::cbegin() const{
          return vm.cbegin();
      }

    /** @brief Devuelve const end del conjunto
    */
    template <typename T, typename CMP>
      typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::cend() const{
          return vm.cend();
      }

  /* ------------------ LOWER BOUND --------------------- */

  /** @brief cuenta cuantas entradas hay en el conjunto por debajo ('antes', '<') de los parámetros dados.
  @param[in] e entrada.
  @return Devuelve un iterador al primer elemento que cumple que "elemento<e" es falso, esto es, el primer elemento que  es mayor o igual que e
  @post no modifica el conjunto.
  */


  template <typename T, typename CMP>
  typename conjunto<T,CMP>::iterator conjunto<T,CMP>::lower_bound (const value_type& e) {
        return std::lower_bound(vm.begin(), vm.end(), e);
  }


  template <typename T, typename CMP>
  typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::lower_bound (const value_type& e) const{
      typename conjunto<T,CMP>::const_iterator it = std::lower_bound(vm.begin(), vm.end(), e);
        return it;
  }

	/** @brief cuenta cuantas entradas hay en el conjunto por encima ('después', '>') de los parámetros dados.
	@param[in] e entrada. Devuelve un iterador al primer elemento que cumple que "elemento>e", esto es, el primer elemento ESTRICTAMENTE mayor que e
	@post no modifica el conjunto.
	*/
  template <typename T, typename CMP>
  typename conjunto<T,CMP>::iterator conjunto<T,CMP>::upper_bound (const value_type& e){
    typename conjunto<T,CMP>::iterator it = std::upper_bound(vm.begin(), vm.end(), e);
    return it;
  }

template <typename T, typename CMP>
  typename conjunto<T,CMP>::const_iterator conjunto<T,CMP>::upper_bound (const value_type& e) const{
      typename conjunto<T,CMP>::const_iterator it = std::upper_bound(vm.begin(),vm.end(),e);
      return it;
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
    bool cromosomas = false;
    bool posic = true;
    int tam = vm.size();
    int tamCrom = 25;
    string crom[tamCrom] = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","X","Y","MT"};
    //String con los  cromosomas posibles
    for(int i = 0; i < tam && posic && !cromosomas; i++){
      if(vm[i].getPos() <= 0){ // Comparamos la posicion
        posic = false; // Si no se cumple se pone a false y sale
      }

      string subcrom = (vm[i].getChr()); // Sub-string con el cromosoma de la mutacion[i]

      for(int j = 0; j < tamCrom; j++){
        if(crom[j] == subcrom){
          cromosomas = true; // Si es igual a alguno, esta encontrado por lo tanto es valido
        }
      }
    }

    bool posic2 = true;
    bool cromosomas2 = true;

    if(posic && cromosomas){ // Si las dos primeras comprobaciones se cumplen
      for(int i = 0; i < tam - 1 && posic2 && cromosomas2; i++){
        if(vm[i].getChr() == vm[i + 1].getChr()){ // Se comprueba la pos
          posic2 = (vm[i].getPos() < vm[i + 1].getPos());
        }else{
          cromosomas2 = (vm[i].getChr() < vm[i + 1].getChr()); // Se comprueba el chr
        }
      }
    }

    bool resultado = cromosomas && cromosomas2 && posic && posic2;
    return resultado; // Se devuelve el resultado de todas las comprobaciones
  }


// -------------------------------------------------------

  /** @brief imprime todas las entradas del conjunto
  @post No se modifica el conjunto.
  Implementar tambien esta funcion
  	*/
    template <typename T, typename CMP>
  ostream &  operator << ( ostream & sal, const conjunto<T,CMP> & C){
    sal<< endl;
    int contador = 1;
    for(typename conjunto<T,CMP>::const_iterator i = C.cbegin(); i < C.cend(); i++){
      sal<< "--------------------- MUTACION: " << contador << " ---------------------" << endl;
      sal<< *i << endl << endl; // Operator << de mutacion
      contador++;
    }
    return sal;
  }
