#include "Nmer.h"
#include "ktree.h"
#include <fstream>
#include <cstring>
#include <string>
#include <queue>
#include <map>


  // template<typename T, int K>
  // extern void recorrido_preorden(typename ktree<T,K>::const_node n);

  /** @brief Constructor primitivo .
      Crea un Nmer de longitud maxima 0, con el valor ('-',0) en la raíz
  */
  Nmer::Nmer() {
    max_long = 0;
    el_Nmer = ktree<pair<char,int>,4>(pair<char,int>('-',0));

  }


  /** @brief Constructor de copia
  */
  Nmer::Nmer(const Nmer &orig){
    max_long  = orig.max_long;
    el_Nmer  = orig.el_Nmer;
  }


  /** @brief Recorre un Nmer en preorden
  *   @param n Nodo de partida, se muestra primero la raiz, luego hijo izquierda y luego hijo derecha
  */
  void Nmer::recorrido_preorden(cnode n) const{
    if (!n.null()){
      for(int i = 0; i < (*n).second; i++){
        cout << "( " << (*n).first <<  "," << (*n).second << "); ";
      }
      cout<< endl;

      typename ktree<pair<char, int>, 4>::const_node::child_iterator ini = n.begin();
      typename ktree<pair<char, int>, 4>::const_node::child_iterator fin = n.end();

      while (ini != fin){
        recorrido_preorden(*ini);
        ++ini;
      }
    }
  }


  /** @brief Imprime los Nmers
  * @todo Debemos de implementar este método de forma que nos garantizemos que se imprimen todos los Nmers.
  */
  void Nmer::list_Nmer() const {

    recorrido_preorden(el_Nmer.root());

    cout << endl;

  }


  /** @brief Máxima longitud de los Nmers almacenados
  */
  unsigned int Nmer::length() const {
    return max_long;
  }


  /** @brief Número de Nmers almacenados
  */
  Nmer::size_type Nmer::size() const{
    return el_Nmer.size()-1;
  }


  /** @brief Asigna un Nmer a otro
  *   @orig Nmer para hacer la asignacion
  */
  Nmer & Nmer::operator=(const Nmer &orig){
    if(this != &orig){
      el_Nmer  = orig.el_Nmer;
     max_long  = orig.max_long;
    }
    return *this;
  }


  /** @brief Convierte el Nmer en un string
      @param aux Nodo a partir del cual se va creando el string
  */
  string Nmer::tree_toString(const ktree<pair<char, int>, 4>::const_node n, string & cadena) const{
    cadena = "";
    if (!n.null()){
  		cadena += (*n).first;
      	for (auto hijo : n){
    			cadena += tree_toString(hijo, cadena);
    		}
    }
  	return cadena;
  }


  /** @brief Devuelve el Nmer (subarbol) asociado a un prefijo.
  */
  Nmer Nmer::Prefix(string adn){
    // Creo el Nmer resultado
    // Paso el arbol a string
    // busco el substring adn en el arbol
    // a partir del substring hasta el final del arbol (substring como prefijo)
    // creo un nuevo Nmer con la cadena resultante

    Nmer res;
    string cadena = "";
    string arbol = tree_toString(el_Nmer.root(), cadena);
    int pos = arbol.find(adn);
    for(int i = pos; i < arbol.size() && pos != string::npos; i++){
      res.insertar_cadena(to_string(arbol[i]));
    }
    return res;
  }


  /** @brief Se devuelve un Nmer donde para cada nodo (representa una
  *    secuencia) se computa la suma de las frecuencias en *this y en referencia,
  *   @param reference Nmer de referencia para unir
  */
  Nmer Nmer::Union(const Nmer reference) const{
    // Creamos Nmer copia de this
    // Llamamos a recorrido_preorden_crear para que sume this con reference
    // las frecuencias de res deben ser la suma de *this y reference
    Nmer res(*this);
    // el_Nmer += reference.el_Nmer;


    return res;
  }


  /** @brief Comprueba que el Nmer contiene la cadena dada por adn
  *   @param adn cadena a buscar
  */
  bool Nmer::containString(const string adn) const{
    string cadena = "";
    const char* arbol = (tree_toString(root(), cadena)).c_str();
    const char* _adn = adn.c_str();
    return strstr(arbol, _adn);

  }


  /** @brief Comprueba que el Nmer de referencia está incluido en el actual
  *   @param reference Nmer de referencia para ver si esta incluido en el Nmer actual
  */
  bool Nmer::included(const Nmer reference) const{
    Nmer aux = reference;
    string cadena = "";
    const char* arbol = (tree_toString(el_Nmer.root(), cadena)).c_str();
    const char* arbol_aux =  (tree_toString(aux.root(), cadena)).c_str();
    return strstr(arbol, arbol_aux);
  }


  /** @brief inserta una cadena en el Nmer
  *   @param cadena Cadena que se inserta
  */
  void Nmer::insertar_cadena(const string & cadena){
    node n_act = el_Nmer.root();

    for(int i = 0; i < cadena.size(); i++){
        if(!n_act[i].null()){
          (*n_act[i]).second++;
        }else{
          el_Nmer.insert_k_child(n_act, i, pair<char, int>(cadena[i], 1));
        }
        n_act = n_act[i]; // = siguiente
      }
  }


  /** @brief Inserta la secuencia de ADN en el Nmer actual
  *   @param l tamaño de las subsecuencias a insertar
  *   @param adn secuencias para ir insertando
  */
  void Nmer::sequenceADN(unsigned int l, const string &adn){
      el_Nmer = ktree<pair<char,int>,4>(pair<char,int>('-',0));
      max_long = adn.size();

      string subcadena = "";
      for(int i = 0; i < adn.size() - l; i++){
        for(int j = i; j < l; j++){
          subcadena += adn[j];
        }
        insertar_cadena(subcadena);
        subcadena = "";
      }

  }


  /** @brief lectura fichero serializado
   * @param nombre_fichero fichero serializado con extension .srl
   *
   * Genera a partir del fichero el ktree que contiene todos los kmers asociados a una cadena de ADN
   *
   * La cadena original viene descrita en el fichero serializado
   */
  bool Nmer::loadSerialized(const string & fichero) {
   string cadena;
   ifstream fe;
   pair<char,int> nulo('x',-1);
   Nmer::String2Base stb;

   fe.open(fichero.c_str(), ifstream::in);
   if (fe.fail()){
      cerr << "Error al abrir el fichero " << fichero << endl;
   }
   else {
      //leo la cabecera del fichero (líneas que comienzan con #)
      do{
        getline(fe,cadena,'\n');
      } while (cadena.find("#")==0 && !fe.eof());
      // leemos Nmer_length
       max_long = std::stoi(cadena);
       // leemos cadena serializada
      getline(fe,cadena,'\n');
      el_Nmer.deserialize(cadena,nulo,';',stb);
      fe.close();
      return true;
   } // else
   fe.close();
   return false;
  }


  /** @brief Calcula la distancia entre 2 Nmer
  *   @param x Nmer origen para calcular la distancia
  */
  float Distance(const Nmer &x){
    
  }


  /** @brief Functor para comparar strings por tamaño
  *   @param a,b strings para comparar
  */
  struct mayorCad{
    bool operator()(string a, string b){
      return (a.size() < b.size());
    }
  };


  /** @brief Encuentra el Nmer de mayor longitud posible
  *   que aparezca un numero menor o igual que threshold
  *   @param threshold
  */
  set<pair<string, int>,  Nmer::ordenCrec > Nmer::rareNmer(int threshold){
    // paso el arbol a string
    // me creo un mapa para ordenar los string por tamaño con el functor
    // recorro el arbol string, con un subbucle hasta threshold
    // guardo en una cadena, las subcadenas que voy creando
    // busco en el arbol todas las subcadenas iguales a la subcadena creada
    // con el while cuento las veces que aparece la subcadena buscada
    // guardo en el map la cadena y incremento las veces que aparece cada vez
    // que la encuentra
    // despues paso el mapa al set


    set<pair<string, int>,  Nmer::ordenCrec > res;
    map<string, int, mayorCad> mapa;

    string cadena = "";
    string arbol = tree_toString(el_Nmer.root(), cadena);
    string cad = "";

    for(int i = 0; i < arbol.size(); i++){
      for(int j = 0; j < threshold; j++){
        cad += arbol[j];
        size_t nPos = arbol.find(cad, 0); // primera aparicion
        while(nPos != string::npos){
          mapa[cad]++;
          nPos = arbol.find(cad, nPos+1);
        }
      }
      cad = "";
    }

      map<string, int, mayorCad>::iterator it = mapa.begin();

      for(it; it != mapa.end(); it++){
        res.insert(make_pair((*it).first, (*it).second));
      }

      return res;
  }


  /** @brief Encuentra el Nmer de mayor longitud posible
  *   que aparezca un numero mayor que threshold
  *   @param threshold
  */
  set<pair<string,int>, Nmer::ordenDecre > Nmer::commonNmer(int threshold){

      set<pair<string, int>,  Nmer::ordenDecre > res;
      map<string, int, mayorCad> mapa;

      string cadena = "";
      string arbol = tree_toString(el_Nmer.root(), cadena);
      string cad = "";

      for(int i = 0; i < arbol.size(); i++){
          cad += arbol[i];
          size_t nPos = arbol.find(cad, 0); // primera aparicion
          while(nPos != string::npos){
            mapa[cad]++;
            nPos = arbol.find(cad, nPos+1);
          }
        cad = "";
      }
        map<string, int, mayorCad>::iterator it = mapa.begin();
        for(it; it != mapa.end(); it++){
          res.insert(make_pair((*it).first, (*it).second));
        }

    return res;
  }


  /** @brief devuelve los Nmers de longitud l, ordenados en orden creciente de frecuencia.
  *   @param l entero longitud del Nmer
  */
  set<pair<string,int>, Nmer::ordenCrec > Nmer::level(int l){
    // Para cada nodo de hijo de la raiz, le asigno el iterador
    // Recorro cada hijo de la raiz mientras que no sea nulo hasta llegar al nivel l
    // Voy guardando las etiquetas en un string para quedarme con el Nmer
    // Guardo como frecuencia el entero de la ultima etiqueta
    // Los guardo en el set que ya de por si se ordena de forma creciente,
    // gracias al functor

    set<pair<string,int>, Nmer::ordenCrec > res;
    string cad = "";
    ktree<pair<char,int>, 4>::node::child_iterator it;
    for(int i = 0; i < 4 && !(((el_Nmer.root()).k_child(i)).null()); i++){
       it = (el_Nmer.root()).k_child(i).begin();
      for(int j = 0; j < l && !(*it).null(); j++){
        cad += ((*(*it)).first);
        it++;
      }
      res.insert(make_pair(cad, 1));
      cad = "";
    }
    return res;
  }
