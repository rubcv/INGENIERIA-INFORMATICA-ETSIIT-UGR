  /** @brief fichero de implementacion de la clase clinvar
  *
  */

  /**
  * @brief Carga el fichero de mutaciones en todas las estructuras de la clase clinvar
  * @param nombreDB Nombre del fichero de mutaciones
  *
  *
  */

  void ClinVar::load(string nombreDB){
    mutacion mut;
    string cadena;
    ifstream fe(nombreDB);

     if (!fe){
       cout<< "Error abriendo el archivo " << nombreDB << endl;
      exit(1);
     }else {
        //leo la cabecera del fichero (líneas que comienzan con #)
        do{
          getline(fe,cadena,'\n');
        }while (cadena.find("#")==0 && !fe.eof());


        mut_iterator it;
        it.setit( mutDB.begin());
        //leo la tabla de mutaciones, una línea cada vez
        int cont = 0;
        int tope = 1;
        while ( !fe.eof() && cont < tope ){

            mut = mutacion(cadena);      // Invoco el constructor de mutación que recibe una cadena completa, la parsea y crea la mutación.
            mutDB.insert(mut);                   // Insertar mutación en el vector

            IDm_map.insert(pair<IDmut, mut_iterator>(mut.getID(), it));

            list<mut_iterator> aux;

            for(int i = 0; i < mut.getGenes().size(); i++){
              gen_map.insert(pair<IDgen, list< mut_iterator> >(mut.getGenes()[i], aux));
              gen_map[mut.getGenes()[i]].push_back(it);
            }
            for(int i = 0; i < mut.getEnfermedades().size(); i++){
              enfDB.insert(pair<IDenf, enfermedad>(mut.getEnfermedades()[i].getID(), mut.getEnfermedades()[i]));
              IDenf_map.insert(pair <IDenf, mut_iterator>(mut.getEnfermedades()[i].getID(), it));
            }


            // cont++;

            it++;
            getline(fe,cadena,'\n');            // Se lee la siguiente cadena
        }
      }
      fe.close();
  }


  /**
  * @brief Inserta una mutacion en la clase clinvar, insertandola segun el orden predeterminado en todas las estructuras
  * @param x Mutacion a ser insertada
  *
  *
  */
  void ClinVar::insert(const mutacion &mut){
    mut_iterator it;
    it.setit(mutDB.insert(mut).first);
    IDm_map.insert(pair<IDmut, mut_iterator>(mut.getID(), it));
    list<mut_iterator> aux;

    for(int i = 0; i < mut.getGenes().size(); i++){
      gen_map.insert(pair<IDgen, list< mut_iterator> >(mut.getGenes()[i], aux));
      gen_map[mut.getGenes()[i]].push_back(it);
    }

    for(int i = 0; i < mut.getEnfermedades().size(); i++){
      enfDB.insert(pair<IDenf, enfermedad>(mut.getEnfermedades()[i].getID(), mut.getEnfermedades()[i]));
      IDenf_map.insert(pair <IDenf, mut_iterator>(mut.getEnfermedades()[i].getID(), it));
    }
  }


  /**
  * @brief Elimina una mutacion de todas las estructuras de clinvar
  * @param ID ID de la mutacion a ser borrada
  * @return true si tiene exito borrando, false en caso contrario
  *
  */
  bool ClinVar::erase( IDmut ID){


    mutacion una;
    bool enc = false;
    mut_iterator it;
    it.setit(mutDB.begin());
    for(it; it.getit() != mutDB.end() && !enc; it++){
      if(it.getID() == ID){
        una = *it;
        enc = true;
      }
    }
    if(enc){
      mutDB.erase(una);

      IDm_map.erase(ID);

      for(int i = 0; i < una.getGenes().size(); i++){
        gen_map.erase(una.getGenes()[i]);
      }

      for(int i = 0; i < una.getEnfermedades().size(); i++){
        enfDB.erase(una.getEnfermedades()[i].getID());
        IDenf_map.erase(una.getEnfermedades()[i].getID());
      }

    }
    return enc;
  }


  /**
  * @brief Busca una mutacion en la clase clinvar
  * @param ID ID de la mutacion a buscar
  * @return Iterador a la mutacion si la encuentra
  *
  */
  ClinVar::mut_iterator ClinVar::find_mut(IDmut ID){
    return IDm_map[ID];
  }


  /**
  * @brief Busca una enfermedad en la clase clinvar
  * @param ID ID de la enfermedad a buscar
  * @return Iterador a la enfermedad si la encuentra
  *
  */
  enfermedad_iterator ClinVar::find_Enf(IDenf ID){
    enfermedad_iterator uno;
    uno = enfDB.find(ID);
    return uno;
  }



  /**
  * @brief Devuelve las enfermedades de una mutacion
  * @param mut mutacion sobre la que buscar las enfermedades
  * @return vector de enfermedades de la mutacion
  *
  */
  vector<enfermedad> ClinVar::getEnfermedades(mutacion &mut){
    vector<enfermedad> res;
    for(enfermedad_iterator it = enfDB.begin(); it != enfDB.end(); it++){
      for(int i = 0; i < mut.getEnfermedades().size(); i++){
        if(it->second == mut.getEnfermedades()[i]){
          res.push_back(it->second);
        }
      }
    }
    return res;
  }

  /**
  * @brief Devuelve las enfermedades que contienen una palabra clave en el nombre
  * @param keyword Palabra clave a buscar en el nombre de las enfermedades
  * @return lista de ID de enfermedades que contienen la palabra clave
  *
  */
  list<IDenf> ClinVar::getEnfermedades(string keyword){
    list<IDenf> una;
    for(enfermedad_iterator it = enfDB.begin(); it != enfDB.end(); it++){
      if(it->second.nameContains(keyword)){
        una.push_back(it->second.getID());
      }
    }
  return una;
  }


  /**
  * @brief Busca las mutaciones que tienen un determinado ID en sus enfermedades
  * @param ID ID de las enfermedades a buscar en el conjunto de mutaciones
  * @return set con el conjunto de ID de las mutaciones que tienen enfermedades con el ID pasado como parametro
  *
  */
  set<IDmut> ClinVar::getMutacionesEnf (IDenf ID){
    set<IDmut> res;
    mut_iterator uno;
    uno.setit(mutDB.begin());
    for(uno; uno.getit() != mutDB.end(); uno++){
      int tam = (*uno).getEnfermedades().size();
      for(int i = 0; i < tam; i++)
      if(uno.getEnfID()[i] == ID){
        res.insert((*uno).getID());
      }
    }
  return res;
  }


  /**
  * @brief Busca las mutaciones que tienen un determinado ID en sus genes
  * @param ID ID de los genes a buscar en el conjunto de mutaciones
  * @return set con el conjunto de ID de las mutaciones que tienen genes con el ID pasado como parametro
  *
  */
  set<IDmut> ClinVar::getMutacionesGen (IDgen ID){
    set<IDmut> uno;
    list<mut_iterator> una;
    una = gen_map[ID];
    for(list<mut_iterator>::iterator i = una.end(); i != una.begin(); i--){
      uno.insert(una.back().getID());
      una.pop_back();
    }
    return uno;
  }


  /**
  * @brief Reinserta una mutacion en la priority_queue
  * @param mutacion mutacion a reinsertar
  * @param cola priority_queue donde reinsertar la mutacion
  * Reinserta todas las mutaciones menos la que estaba ultima, de forma que la sustituye por la mutacion nueva
  *
  */

  void ClinVar::Reinsertar(mutacion una, priority_queue<mutacion, vector<mutacion>, ClinVar::ProbMutaciones> &cola){
    cola.push(una);
    int veces = cola.size();
    while(veces > 1){ // Reinserta todas menos la que estaba al final
      mutacion m = cola.top();
      cola.push(m);
      cola.pop();
      veces--;
    }
  }




  /**
  * @brief Busca las mutaciones que tienen una palabra clave en el nombre y devuelve las k más probables
  * @param keyword palabra clave en el nombre de las mutaciones
  * @param k numero de mutaciones máximo de las más probables para devolver
  * @return set con el conjunto de mutaciones más probables con la determinada palabra clave en el nombre
  *
  */
  set<mutacion, ClinVar::ProbMutaciones> ClinVar::topKMutaciones(int k, string keyword){
    set<mutacion, ClinVar::ProbMutaciones> topk;
    priority_queue<mutacion, vector<mutacion>, ClinVar::ProbMutaciones> cola;


    list<IDenf> una;
    una = getEnfermedades(keyword);
    int cont = 0;
    while(una.size() > 0){
      enfermedad_iterator enfit = find_Enf(una.back());
      set<IDmut> uno = getMutacionesEnf(enfit->second.getID());

      for(set<IDmut>::iterator i = uno.begin(); i != uno.end(); i++){
        mut_iterator unno = find_mut(*i);
        if(unno.getit() != mutDB.end()){ // Comprobamos que exista
          if(cont < k){ // Insertamos las k primeras antes
            cola.push(*unno);
            cont++;
          }else{ // Insertamos el resto comparando con el tope
            if(*unno < cola.top()){ // Si tiene más prioridad
              Reinsertar(*unno, cola); // Insertamos la nueva
            }
          }
        }
      }
      una.pop_back();
    }

    // Pasar de la cola al topk
    while(!cola.empty()){
      topk.insert(cola.top());
      cola.pop();
    }

    return topk;
  }



  /**
  * @brief Tamaño del conjunto clinvar
  * @return int con el valor de mutaciones cargadas en clinvar
  *
  */
  int ClinVar::size(){
    return IDm_map.size();
  }



  /**
  * @brief Imprime el tamaño de todos los conjuntos que hay en clinvar
  * Para comprobar la correcta lectura del fichero
  *
  */
  void ClinVar::LecturaFichero(){
    cout<< "Tamaños de las lecturas:"                                                      << endl;
    cout<< "set<mutacion>                              mutDB: "     <<  mutDB.size()       << endl;
    cout<< "unordered_map<IDmut, mut_iterator>       IDm_map: "     <<  IDm_map.size()     << endl;
    cout<< "map<IDgen, list< mut_iterator> >         gen_map: "     <<  gen_map.size()     << endl;
    cout<< "map<IDenf, enfermedad>                     enfDB: "     <<  enfDB.size()       << endl;
    cout<< "multimap<IDenf, mut_iterator >         IDenf_map: "     <<  IDenf_map.size()   << endl;
  }

  /* Metodos relacionados con los iteradores */


  /**
  * @brief Busca una mutacion con chr mayor o igual que cromosoma y pos mayor o igual que posicion
  * @param cromosoma cromosoma de la mutacion a buscar
  * @param posicion posicion de la mutacion a buscar
  * @return mut_iterator iterador apuntando a la mutacion encontrada
  *
  */
  ClinVar::mut_iterator ClinVar::lower_bound(string cromosoma, unsigned int posicion){

    mut_iterator it;
    it.setit(mutDB.begin());
    for(it; it.getit() != mutDB.end(); it++){
      if(((*it).getChr() >= cromosoma) && ((*it).getPos() >= posicion)){
        return it;
      }
    }
    it.setit(mutDB.end());
    return it;
  }


  /**
  * @brief Busca una mutacion con chr mayor que cromosoma y pos mayor que posicion
  * @param cromosoma cromosoma de la mutacion a buscar
  * @param posicion posicion de la mutacion a buscar
  * @return mut_iterator iterador apuntando a la mutacion encontrada
  *
  */
  ClinVar::mut_iterator ClinVar::upper_bound(string cromosoma, unsigned int posicion){
    mut_iterator it;
    it.setit(mutDB.begin());
    for(it; it.getit() != mutDB.end(); it++){
      if(((*it).getChr() > cromosoma) && ((*it).getPos() > posicion)){
        return it;
      }
    }
    it.setit(mutDB.end());
    return it;
  }


  /**
  * @brief Devuelve un objeto mut_iterator apuntando al principio de las mutaciones de clinvar
  * @return mut_iterator apuntando al principio de las mutaciones de clinvar
  *
  */
  ClinVar::mut_iterator ClinVar::begin(){
    mut_iterator it;
    it.setit(mutDB.begin());
    return it;

  }

  /**
  * @brief Devuelve un objeto mut_iterator apuntando al final de las mutaciones de clinvar
  * @return mut_iterator apuntando al final de las mutaciones de clinvar
  *
  */
  ClinVar::mut_iterator ClinVar::end(){
    mut_iterator it;
    it.setit(mutDB.end());
    return it;

  }

  /**
  * @brief Devuelve un enfermedad_iterator apuntando al principio de las enfermedades de clinvar
  * @return enfermedad_iterator apuntando al principio de las enfermedades de clinvar
  *
  */
  enfermedad_iterator ClinVar::ebegin(){
    enfermedad_iterator it = enfDB.begin();
    return it;
  }


  /**
  * @brief Devuelve un enfermedad_iterator apuntando al final de las enfermedades de clinvar
  * @return enfermedad_iterator apuntando al final de las enfermedades de clinvar
  *
  */
  enfermedad_iterator ClinVar::eend(){
    enfermedad_iterator it = enfDB.end();
    return it;

  }



  /**
  * @brief Devuelve un objeto gen_iterator apuntando al principio de los genes de clinvar
  * @return enfermedad_iterator apuntando al principio de los genes de clinvar
  *
  */
  ClinVar::gen_iterator ClinVar::gbegin(){
    gen_iterator it;
    it.setitmap(gen_map.begin());
    return it;

  }

  /**
  * @brief Devuelve un objeto gen_iterator apuntando al final de los genes de clinvar
  * @return enfermedad_iterator apuntando al final de los genes de clinvar
  *
  */
  ClinVar::gen_iterator ClinVar::gend(){
    gen_iterator it;
    it.setitmap(gen_map.end());
    return it;

  }
