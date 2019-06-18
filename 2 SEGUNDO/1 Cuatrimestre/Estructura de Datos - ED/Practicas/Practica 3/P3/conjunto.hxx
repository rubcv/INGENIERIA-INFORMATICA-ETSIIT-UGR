
/* ------ GET MUTACION ------ */

/** @brief Cuenta mutaciones desde begin hasta iterator
*	@param posicion
*	@return numero de mutaciones desde begin hasta iterador
*/

int conjunto::getMutaciones(conjunto::const_iterator uno, bool cond){ // Condicion para contar por arriba o por abajo
  int contador = 0;
  if(uno != this->vm.end()){
    if(cond){ // Si cond = true, cuenta desde begin hasta iterator
        for(conjunto::const_iterator i = this->vm.begin(); i < uno; i++){
        //  cout<< *i << endl; // Descomentar para imprimir todas las mutaciones
          contador++; // Cuenta las mutaciones hasta iterador "uno"
        }
        //cout<< "Hay: " << contador << " mutaciones" << endl;

    }else{ // Si cond = false, cuenta desde iterator hasta el final
          for(conjunto::const_iterator i = uno; i < this->vm.end(); i++){
            contador++;
          }
    }
  }
  return contador;
}




/* ----- CONSTRUCTORES ------ */

/** @brief Constructor por defecto
*/

conjunto::conjunto(){
  vm = vector<mutacion>(); // Constructor por defecto, vector vacio
}

/** @brief Constructor de copia
* @param d conjunto para hacer la copia
*/
conjunto::conjunto(const conjunto &d){
  vm = d.vm;
}


/* ----- FIND ------ */


/** @brief Busca mutacion con el string chr y la posicion pos
* @param chr string de la mutacion a buscar
* @param pos posicion de la mutacion a buscar
* @return resul Par de datos con la mutacion y bool de si esta o no
*/

pair<conjunto::value_type, bool> conjunto::find (const string & chr, const unsigned int & pos) const{
  pair<conjunto::value_type,bool> resul; // Pareja resultado
  conjunto::value_type nueva; // Mutacion auxiliar
  bool encontrado = false;

  for(conjunto::const_iterator i = this->vm.begin(); i < this->vm.end() && !encontrado; i++){
    if(chr == i->getChr() && pos == i->getPos()){ // Se recorre vm y si hay uno con el mismo ID, nueva = esa
      nueva = *i;
      encontrado = true;
    }
  }

  if(encontrado){
    resul.first = nueva; // Si encontrado, se guardan los datos en la pareja
    resul.second = true;
  }else{
      resul.second = false;
  }
  return resul; // Se devuelve la pareja con la mutacion con el ID buscado y true si encontrado
}


/** @brief Buscador de mutacion con ID por parametro
* @param ID  string ID de la mutacion a buscar
* @return resul Par de datos con la mutacion y bool de si esta o no
*/

pair<conjunto::value_type,bool> conjunto::find(const string & ID) const{
  pair<conjunto::value_type,bool> resul; // Pareja resultado
  conjunto::value_type nueva; // Mutacion auxiliar
  bool encontrado = false;

  for(conjunto::const_iterator i = this->vm.begin(); i < this->vm.end() && !encontrado; i++){
    if(ID == i->getID()){ // Se recorre vm y si hay uno con el mismo ID, nueva = esa
      nueva = *i;
      encontrado = true;
    }
  }

  if(encontrado){
    resul.first = nueva; // Si encontrado, se guardan los datos en la pareja
    resul.second = true;
  }else{
      resul.second = false;
  }
  return resul; // Se devuelve la pareja con la mutacion con el ID buscado y true si encontrado
}

/** @brief Buscador de mutacion en vector de mutaciones
* @param e Mutacion a buscar
* @return resul Par de datos con la mutacion y bool de si esta o no
*/

pair<conjunto::value_type,bool>  conjunto::find (const conjunto::value_type & e) const{ // Buscador de mutacion
  pair<conjunto::value_type, bool> resul;

  vector<mutacion> copia = vm;

  //copia.sort();
  conjunto::value_type uno = e;
  conjunto:: iterator m;
  /* Busca posicion de la mutacion, devuelve el iterador, si no esta devuelve la final o la mas cercana por eso comprobar si es o no \
  m  la que se busca */
  m = std::lower_bound(copia.begin(), copia.end(), e); // Busca posicion de la mutacion

  if(*m == e){ // Si es igual al que se busca
    resul.first = uno;
    resul.second = true;
  }else{
    resul.second = false; // False = no esta
  }
return resul;
}


/* ----- COUNT ------ */

/** @brief Cuenta las veces que hay una mutacion en vm con el chr y pos indicados
* @param chr chr parametro string
* @param pos parametro posicion
* @return total contador de numero de apariciones
*/

conjunto::size_type conjunto::count (const string & chr, const unsigned int & pos) const{
  conjunto::size_type total = 0;

  for(conjunto::const_iterator i = this->vm.begin(); i < this->vm.end(); i++){
    if(chr == i->getChr() && pos == i->getPos())
    total++;
  }
  return total;
}

/** @brief Cuenta las mutaciones con el Chr indicado como parametro
* @param chr Chr de la mutacion a contar
*/
conjunto::size_type conjunto::countChr (const string & chr) const{
  conjunto::size_type total = 0;

  for(conjunto::const_iterator i = this->vm.begin(); i < this->vm.end(); i++){
    if(chr == i->getChr()){
      total++;
    }
  }
  return total;
}

/** @brief Cuenta las veces que hay una mutacion en vm con el ID indicado
* @param ID parametro ID
* @return total contador de numero de apariciones
*/

conjunto::size_type conjunto::count (const string & ID) const{
  conjunto::size_type total = 0;

    for(conjunto::const_iterator i = this->vm.begin(); i < this->vm.end(); i++){
      if(ID == i->getID()){
        total++;
      }
    }

  return total;
}


/** @brief Cuenta el numero de apariciones en vm de la mutacion e
* @param e Mutacion a buscar
* @return total contador con numero de apariciones
*/

conjunto::size_type conjunto::count (const conjunto::value_type & e) const{
  conjunto::size_type total = 0;

  for(conjunto::const_iterator i = this->vm.begin(); i < this->vm.end(); i++){
    if(*i == e){
      total++;
    }
  }
  return total;
}

// ------------- INSERT -------------------

	/** @brief Inserta una entrada en el conjunto
	@param e entrada a insertar
	@return true si la entrada se ha podido insertar con éxito, \
   esto es, no existe una mutación con igual par chr/pos ni igual ID en el conjunto. False en caso contrario.
	@post Si e no esta en el conjunto, el size() sera incrementado en 1.
	*/
	bool conjunto::insert( const conjunto::value_type & e){
    bool esta = false;

    if((find(e.getChr(), e.getPos()).second == true) && (find(e.getID()).second == true)){
      esta = true;
    }

    if(!esta){
     vm.insert(vm.end(), e);
     return true;
    }else{
      return false;
    }
  }



  /** @brief Borra una entrada en el conjunto .
	Busca la entrada con chr/pos o id en el conjunto (utiliza e.getID() en el tercer caso) y si la encuentra la borra.
	@param[in] chr de la mutación a borrar.
	@param[in] pos de la mutación a borrar.
	@param[in] ID de la mutación a borrar.
	@param[in] e entrada con e.getID() que geremos borrar, el resto de los valores no son tenidos en cuenta
	@post Si esta en el conjunto su tamaño se decrementa en 1.
	*/
	bool conjunto::erase(const string & chr, const unsigned int & pos){
    bool borrado = false;
    bool esta = false;

    for(conjunto::iterator i = this->vm.begin(); i < this->vm.end() && !borrado; i++){
      if(i->getChr() == chr && i->getPos() == pos){
        esta = true;
      }
      if(esta){
        this->vm.erase(i);
        borrado = true;
      }
    }
    return borrado;
  }

	bool conjunto::erase(const string & ID){
    bool borrado = false;
    bool esta = false;

    for(conjunto::iterator i = this->vm.begin(); i < this->vm.end() && !borrado; i++){
      if(i->getID() == ID){
        esta = true;
      }
      if(esta){
        this->vm.erase(i);
        borrado = true;
      }
    }
    return borrado;
  }

  bool conjunto::eraseChr(const string & Chr){ // Metodo para calcular la eficiencia de erase
    bool borrado = false;
    bool esta = false;

    for(conjunto::iterator i = this->vm.begin(); i < this->vm.end() && !borrado; i++){
      if(i->getChr() == Chr){
        esta = true;
      }
      if(esta){
        this->vm.erase(i);
        borrado = true;
      }
    }
    return borrado;
  }


  bool conjunto::erase(const conjunto::value_type & e){
    bool borrado = false;
    bool esta = false;

    for(conjunto::iterator i = this->vm.begin(); i < this->vm.end() && !borrado; i++){
      if(*i == e){
        esta = true;
      }
      if(esta){
        this->vm.erase(i);
        borrado = true;
      }
    }
    return borrado;
  }



  /** @brief Borra todas las entradas del conjunto, dejandolo vacio.
  @post El conjunto se modifica, quedando vacio.
  */
  void conjunto::clear(){
    if(!vm.empty()){
      vm.clear();
    }
  }

  /** @brief numero de entradas en el conjunto
  @post  No se modifica el conjunto.
  @return numero de entradas en el conjunto
  * Devolver size_type
  */
  conjunto::size_type conjunto::size() const{
    conjunto::size_type res = this->vm.size();
    return res;
  }

  /** @brief Chequea si el conjunto esta vacio (size()==0)
  @post  No se modifica el conjunto.
  */

  bool conjunto::empty() const{
    return vm.empty();
  }



  /** @brief operador de asignación
  @param[in] org conjunto a copiar.
  @return Crea y devuelve un conjunto duplicado exacto de org.
  */
  	conjunto & conjunto:: operator=( const conjunto & org){
      if(this != &org){
        vm = org.vm;
      }
      return *this;
    }

    /* ------------------ LOWER BOUND --------------------- */

      /** @brief cuenta cuantas entradas hay en el conjunto por debajo ('antes', '<') de los parámetros dados.
      @param[in] chr de la mutación.
      @param[in] pos de la mutación.
      @param[in] e entrada.
      @return Devuelve un iterador al primer elemento que cumple que "elemento<e" es falso, esto es, el primer elemento que  es mayor o igual que e
      @post no modifica el conjunto.
      */

  conjunto::const_iterator conjunto::lower_bound (const string & chr, const unsigned int & pos) const{
        conjunto::const_iterator res; // Iterador a devolver
        bool enc = false;
      for(conjunto::const_iterator i = this->vm.begin(); i < this->vm.end() && !enc; i++){ // Recorremos conjunto
        if((i->getChr() == chr && i->getPos() == pos) || (i->getChr() > chr && i->getPos() > pos)){ // Si se encuentra una que es igual o mayor
          res = i; // Se devuelve iterador a su posicion
          enc = true;
        }
      }

      if(enc){
        return res; // Si se encuentra se devuelve res
      }else{
        return this->vm.end(); // Si no se encuentra se devuelve iterador apuntando al final
      }
  }


      /** @brief cuenta cuantas entradas hay en el conjunto por debajo ('antes', '<') de los parámetros dados.
      @param[in] chr de la mutación.
      @param[in] pos de la mutación.
      @param[in] e entrada.
      @return Devuelve un iterador al primer elemento que cumple que "elemento<e" es falso, esto es, el primer elemento que  es mayor o igual que e
      @post no modifica el conjunto.
      */

      conjunto::const_iterator conjunto::lower_bound (const string & ID) const{
          conjunto::const_iterator res; // Iterador a devolver
          bool enc = false;
        for(conjunto::const_iterator i = this->vm.begin(); i < this->vm.end() && !enc; i++){ // Recorremos conjunto
          if((i->getID() == ID) || (i->getID() > ID)){ // Si se encuentra una que es igual o mayor
            res = i; // Se devuelve iterador a su posicion
            enc = true;
          }
        }

        if(enc){
          return res; // Si se encuentra se devuelve res
        }else{
          return this->vm.end(); // Si no se encuentra se devuelve iterador apuntando al final
        }
    }


    conjunto::const_iterator conjunto::lower_bound (const conjunto::value_type & e) const{
      conjunto::const_iterator res; // Iterador a devolver
      bool enc = false;
      for(conjunto::const_iterator i = this->vm.begin(); i < this->vm.end() && !enc; i++){ // Recorremos conjunto
        if(*i == e || *i > e){ // Si se encuentra una que es igual o mayor
          res = i; // Se devuelve iterador a su posicion
          enc = true;
        }
      }

      if(enc){
        return res; // Si se encuentra se devuelve res
      }else{
        return this->vm.end(); // Si no se encuentra se devuelve iterador apuntando al final
      }
    }



	/** @brief cuenta cuantas entradas hay en el conjunto por encima ('después', '>') de los parámetros dados.
	@param[in] chr de la mutación.
	@param[in] pos de la mutación.
	@param[in] e entrada. Devuelve un iterador al primer elemento que cumple que "elemento>e", esto es, el primer elemento ESTRICTAMENTE mayor que e
	@post no modifica el conjunto.
	*/

	conjunto::const_iterator conjunto::upper_bound (const string & chr, const unsigned int & pos) const{
      conjunto::const_iterator res; // Iterador a devolver
      bool enc = false;
    for(conjunto::const_iterator i = this->vm.begin(); i < this->vm.end() && !enc; i++){ // Recorremos conjunto
      if(i->getChr() > chr && i->getPos() > pos){ // Si se encuentra una que es mayor
        res = i; // Se devuelve iterador a su posicion
        enc = true;
      }
    }

    if(enc){
      return res; // Si se encuentra se devuelve res
    }else{
      return this->vm.end(); // Si no se encuentra se devuelve iterador apuntando al final
    }
  }



	conjunto::const_iterator conjunto::upper_bound (const conjunto::value_type & e) const{
    conjunto::const_iterator res; // Iterador a devolver
      bool enc = false;
    for(conjunto::const_iterator i = this->vm.begin(); i < this->vm.end() && !enc; i++){ // Recorremos conjunto
      if(*i > e){ // Si se encuentra una que es mayor
        res = i; // Se devuelve iterador a su posicion
        enc = true;
      }
    }

    if(enc){
      return res; // Si se encuentra se devuelve res
    }else{
      return this->vm.end(); // Si no se encuentra se devuelve iterador apuntando al final
    }
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

  bool conjunto::cheq_rep() const{
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
  ostream &  operator << ( ostream & sal, const conjunto & C){
    sal<< endl;
    int contador = 1;
    for(conjunto::const_iterator i = C.vm.begin(); i < C.vm.end(); i++){
      sal<< "--------------------- MUTACION: " << contador << " ---------------------" << endl;
      sal<< *i << endl << endl; // Operator << de mutacion
      contador++;
    }
    return sal;
  }
