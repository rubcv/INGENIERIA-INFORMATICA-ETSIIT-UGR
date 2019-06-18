
// CONSTRUCTORES

/**
* @brief Constructor por defecto
*/

mutacion::mutacion(){
  chr = "";
  pos = -1;
  ID = "";
  ref_alt = vector<string>();
  genes = vector<string>();
  common = 0;
  clnsig = vector<int>();
  caf = vector<float>();
  enfermedades = vector<enfermedad>();
}

/**
* @brief Constructor de copia
*/

mutacion::mutacion(const mutacion& m){
 chr = m.getChr();
 pos = m.getPos();
 ID = m.getID();
 ref_alt = m.getRef_alt();
 genes = m.getGenes();
 common = m.getCommon();
 clnsig = m.getClnsig();
 caf = m.getCaf();
 enfermedades = m.getEnfermedades();
}


/**
* @brief Constructor por un string
* @param str string con la informacion para inicializar
*/

mutacion::mutacion(const string& str){

   char p;
   int inicio=0, fin=0, aux_int=0, i=0;
   string aux_str, aux_str2;
   float fl;

   // CHR
   fin= str.find('\t');

   aux_str= str.substr(0, fin);
   this->chr= aux_str;

   // POS
   inicio= fin+1;
   fin= str.find('\t', inicio);
   aux_int= atoi(str.substr(inicio, fin-inicio).c_str());
   this->pos=aux_int;

   // ID
   inicio= fin+1;
   fin= str.find('\t', inicio);
   aux_str= str.substr(inicio, fin-inicio);
   this->ID= aux_str;

   // REF_ALT: REF
   inicio= fin+1;
   fin= str.find('\t', inicio);
   aux_str= str.substr(inicio, fin-inicio);
   ref_alt.push_back(aux_str);

   // REF_ALT: ALT
   inicio= fin+1;
   fin= str.find('\t', inicio);
   aux_str= str.substr(inicio, fin-inicio);

      fin= aux_str.find(',', 0);
      if(fin != -1){
         inicio= 0;
         do{
            aux_str2= aux_str.substr(inicio, fin-inicio);
            inicio= fin+1;
            this->ref_alt.push_back(aux_str2);
            fin= aux_str.find(',', inicio);
         }while(fin != -1);

         aux_str2= aux_str.substr(inicio, aux_str.size()-inicio);
         this->ref_alt.push_back(aux_str2);
      }else{
         aux_str2= aux_str.substr(0, aux_str.size());
         this->ref_alt.push_back(aux_str2);
      }



   // GENES
   inicio= fin+1;
   inicio= str.find("GENEINFO=");
   if(inicio!=-1){
      inicio+=9;
      fin= str.find(';', inicio);
      aux_str= str.substr(inicio, fin-inicio);
   }else{
      aux_str= "";
    }
      genes.push_back(aux_str);

   // CAF
   string copia = str;
   int indice = 0;
   string aux2;
   aux2 = "";
   string dato = "CAF=";
  float dat = 0;
  if(copia.find(dato) == std::string::npos){
    caf.push_back(dat);
  }else{
    indice = copia.find(dato);
    indice += 4;
    while(copia[indice] != ';'){
      if(copia[indice] == '|' || copia[indice] == ','){
        dat = atof(aux2.c_str());
        caf.push_back(dat);
        aux2 = "";

      }else{
        aux2 += copia[indice];
      }
      indice++;
    }
    dat = atof(aux2.c_str());
    caf.push_back(dat);
    aux2 = "";
  }


   // COMMON
inicio= str.find("COMMON=");
   if(inicio!=-1){
      inicio+=7;
      aux_str= str.substr(inicio, 1);
      common=aux_str.c_str();
   }else{
      common= false;
    }

   // CLNSIG
   inicio= str.find("CLNSIG=")+7;
   fin= str.find(';', inicio);
   aux_str= str.substr(inicio, fin-inicio);


   fin= aux_str.find('|', 0);
   if(fin == -1)
      fin= aux_str.find(',', 0);
   if(fin != -1){
      inicio=0;
      do{
         aux_str2= aux_str.substr(inicio, fin);
         inicio= fin+1;
         aux_int=atoi(aux_str2.c_str());
         this->clnsig.push_back(aux_int);
         fin= aux_str.find('|', inicio);
         if(fin == -1)
            fin= aux_str.find(',', inicio);
      }while(fin != -1);

      aux_str2= aux_str.substr(inicio, aux_str.size());
      aux_int=atoi(aux_str2.c_str());
      this->clnsig.push_back(aux_int);
   }
   else{
      aux_int=atoi(aux_str.c_str());
      this->clnsig.push_back(aux_int);
   }


   // ENFERMEDAD
   enfermedad nueva;

   inicio= str.find("CLNDBN=")+7;
   fin= str.find(';', inicio);
   aux_str= str.substr(inicio, fin-inicio);

   fin= aux_str.find('|', 0);
   if(fin == -1)
      fin= aux_str.find(',', 0);
   if(fin != -1){
      inicio=0;
      do{
         aux_str2= aux_str.substr(inicio, fin-inicio);
         inicio= fin+1;
         nueva.setName(aux_str2);
         this->enfermedades.push_back(nueva);
         fin= aux_str.find('|', inicio);
         if(fin == -1)
            fin= aux_str.find(',', inicio);
      }while(fin != -1);

      aux_str2= aux_str.substr(inicio, aux_str.size());
      nueva.setName(aux_str2);
      this->enfermedades.push_back(nueva);
   }
   else{
      nueva.setName(aux_str);
      this->enfermedades.push_back(nueva);
   }

   inicio= str.find("CLNDSDBID=")+10;
   fin= str.find(';', inicio);
   aux_str= str.substr(inicio, fin-inicio);

   fin= aux_str.find('|', 0);
   if(fin == -1)
      fin= aux_str.find(',', 0);
   if(fin != -1){
      inicio=0;
      for(i=0; i<this->enfermedades.size()-1 && fin != -1; i++){
         aux_str2= aux_str.substr(inicio, fin-inicio);
         inicio= fin+1;
         enfermedades[i].setID(aux_str2);
         fin= aux_str.find('|', inicio);
         if(fin == -1)
            fin= aux_str.find(',', inicio);
      }
      aux_str2= aux_str.substr(inicio, aux_str.size());
      enfermedades[i].setID(aux_str2);
   }
   else
      enfermedades[0].setID(aux_str);


   inicio= str.find("CLNDSDB=")+8;
   fin= str.find(';', inicio);
   aux_str= str.substr(inicio, fin-inicio);

   fin= aux_str.find('|', 0);
   if(fin == -1)
      fin= aux_str.find(',', 0);
   if(fin != -1){
      inicio=0;
      for(i=0; i<this->enfermedades.size()-1 && fin != -1; i++){
         aux_str2= aux_str.substr(inicio, fin-inicio);
         inicio= fin+1;
         enfermedades[i].setDatabase(aux_str2);
         fin= aux_str.find('|', inicio);
         if(fin == -1)
            fin= aux_str.find(',', inicio);
      }
      aux_str2= aux_str.substr(inicio, aux_str.size());
      enfermedades[i].setDatabase(aux_str2);
   }
   else
      enfermedades[0].setDatabase(aux_str);
}


void mutacion::setID(const string & ID){
  this->ID = ID;
}

void mutacion::setChr(const string & chr){
  this->chr = chr;
}

void mutacion::setPos(const unsigned int & pos){
  this->pos = pos;
}

void mutacion::setRef_alt(const std::vector<string> & ref_alt){
  this->ref_alt = ref_alt;
}

void mutacion::setGenes(const std::vector<string> & genes){
  this->genes = genes;
}

void mutacion::setCommon(const bool & common){
  this->common = common;
}

void mutacion::setCaf(const std::vector<float> & caf){
  this->caf = caf;
}

void mutacion::setEnfermedades(const std::vector<enfermedad> & enfermedades){
  this->enfermedades = enfermedades;
}

void mutacion::setClnsig(const std::vector<int> & clnsig){
  this->clnsig = clnsig;
}

string mutacion::getID( ) const{
  return ID;
}

string mutacion::getChr( ) const{
  return chr;
}

unsigned int mutacion::getPos( ) const{
  return pos;
}

const std::vector<string> & mutacion::getRef_alt () const{
  return ref_alt;
}

const std::vector<string> & mutacion::getGenes () const{
  return genes;
}

bool mutacion::getCommon () const{
  return common;
}

const std::vector<float> & mutacion::getCaf () const{
  return caf;
}

const std::vector<enfermedad> & mutacion::getEnfermedades () const{
  return enfermedades;
}

const std::vector<int> & mutacion::getClnsig () const{
  return clnsig;
}

mutacion & mutacion:: operator=(const mutacion & m){
  if(this != &m){
    ID = m.ID;
    chr = m.chr;
    pos = m.pos;
    common = m.common;
    ref_alt = m.ref_alt;
    genes = m.genes;
    caf = m.caf;
    enfermedades = m.enfermedades;
    clnsig = m.clnsig;
  }
  return *this;
}

bool mutacion:: operator==(const mutacion & m) const{
  return   ((ID == m.ID) &&
           (chr == m.chr) &&
           (pos == m.pos) &&
           (common == m.common) &&
           (ref_alt == m.ref_alt) &&
           (genes == m.genes) &&
           (caf == m.caf) &&
           (enfermedades == m.enfermedades) &&
           (clnsig == m.clnsig));
}

bool mutacion::operator<(const mutacion & m) const{
  if(chr == m.chr){
    return (pos < pos);
  }else{
    if(chr != "MT" && m.chr != "MT"){
        return (chr < m.chr);
    }else if(chr == "MT"){
        return false;
    }else if(m.chr == "MT"){
      return true;
    }
  }
}     //El orden viene determinado por Chr y pos. El primer criterio es el número de cromosoma. El orden para el número de cromosoma se rige por "1"<"2"<"3"<->->-><"22"<"X"<"Y"<"MT". Dos mutaciones del mismo cromosoma deben ordenarse según su posición, de menor posición a mayor (orden natural de enteros)->


ostream& operator<< ( ostream& os, const mutacion& m){

  os << "\nCHR = " << m.chr << endl;
  os << "POSICION = " << m.pos << endl;
  os << "\nID = " << m.ID << endl;

  os << "\nREF_ALT: afectada = " << m.ref_alt[0] << endl;
  os << "REF_ALT: cambiante = " << m.ref_alt[1] << endl;

  os << "\nGENES = " << m.genes[0] << endl;
  for(int i = 1; i < m.genes.size(); i++){
    os << ", " <<m.genes[i];
  }

  os << "\nCOMMON: " << m.common << endl;

  os<< "\nCLNSIG: " << endl;
  for(int i = 0; i < m.clnsig.size(); i++){
    os << m.clnsig[i] << " ";
  }
  os << endl;

  os << "\nCAF: " << endl;
  for(int i = 0; i < m.caf.size(); i++){
    os<< m.caf[i] << " ";
  }
  os << endl;


  os<< "\nENFERMEDAD: " << endl;
  for(int i = 0; i < m.enfermedades.size(); i++){
    os<< m.enfermedades[i] << " ";
  }
  os << endl;

  return os;
}
