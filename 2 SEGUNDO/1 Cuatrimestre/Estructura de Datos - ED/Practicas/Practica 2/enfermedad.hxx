/** @brief fichero de implementacion de la clase enfermedad
*
*/

#include <string>
#include <cstring>
#include <algorithm> // Para usar tolower y pasar a minuscula nombre y cadena a bucar


// CONSTRUCTORES
enfermedad:: enfermedad(){
  // @todo implementar esta funcion
  name = "";
  ID = "";
  database = "";
}


enfermedad:: enfermedad(const string & name, const string & ID, const string & database){
 // @todo implementar esta funcion
 this->name = name;
 this->ID = ID;
 this->database = database;
}


// SET

void enfermedad:: setName(const string & name){
  this->name = name;
}

void enfermedad:: setID(const string & ID){
  this->ID = ID;
}

void enfermedad:: setDatabase(const string & database){
  this->database = database;
}


// GET
string enfermedad:: getName() const{
  return name;
}

string enfermedad:: getID() const{
  return ID;
}

string enfermedad:: getDatabase() const{
  return database;
}


// OPERATOR

enfermedad & enfermedad:: operator=(const enfermedad & e){
  if(this != &e){
    name = e.name;
    ID = e.ID;
    database = e.database;
  }
  return *this;
}

bool enfermedad:: operator==(const enfermedad & e) const{
  return ((name == e.name) && (ID == e.ID) && (database == e.database));
}

bool enfermedad:: operator!=(const enfermedad & e) const{
    return (!((name == e.name) && (ID == e.ID) && (database == e.database)));
}

bool enfermedad:: operator<(const enfermedad & e) const{
  return (name < e.name);
}

bool enfermedad:: nameContains(const string &str) const{
  string nom = name;
  string bus = str;

  std::transform(nom.begin(), nom.end(), nom.begin(), ::tolower);
  std::transform(bus.begin(), bus.end(), bus.begin(), ::tolower);

    return (nom.find(bus) != std::string::npos);
  }


 // @todo implementar esta funcion

 string enfermedad:: toString() const{
    string res = getName() + " " + getID() + " " + getDatabase();
    return res;
 }





// @todo implementar el resto de métodos especificados en enfermedad.h

ostream& operator<<(ostream& os, const enfermedad & e){
  // @todo implementa esta funcion
  os<< "\nEnfermedad name = " << e.name << endl;
  os<< "\nEnfermedad ID = " << e.ID << endl;
  os<< "\nEnfermedad database = " << e.database << endl;
  //...
  return os;
}
