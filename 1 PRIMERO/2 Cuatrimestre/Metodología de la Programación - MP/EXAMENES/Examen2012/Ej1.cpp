#include <iostream>
#include <fstream>

using namespace std;

class Matriz{
  private:
    int nfilas;
    int *ncolumnas;
    double** datos;

  public:
    Matriz();
    ~Matriz();
    Matriz(const Matriz &orig);
    Matriz& operator=(const Matriz &orig);
    friend istream& operator>>(istream &is, Matriz &orig);
    //friend ifstream& operator>>(ifstream& is, Matriz &orig);
    friend ostream& operator<<(ostream &os, const Matriz &orig);
    friend ofstream& operator<<(ofstream &os, const Matriz &orig);
    void Escribir(string nombre, bool comentario);
    double Get(int fil, int col) const;
    void Set(int fil, int col, double dato);
    Matriz Intercambiar() const;
    Matriz Leer(string nombre);
    void ValorMayor(int &fils, int &cols);


} ;

Matriz::Matriz(){
  nfilas = 0;
  ncolumnas = 0;
  datos = 0;
}

Matriz::~Matriz(){
  if(ncolumnas){
    delete[] ncolumnas;
  }

  if(datos){
    for (int i = 0; i < nfilas; i++) {
      delete[] datos[i];
    }
    delete[] datos;
  }
}


Matriz::Matriz(const Matriz &orig){
  nfilas = orig.nfilas;
  if(orig.datos){
    datos  = new double* [nfilas];
    ncolumnas = new int [nfilas];

    for(int i = 0; i < nfilas; i++){
      ncolumnas[i] = orig.ncolumnas[i];
      datos[i] = new double [ncolumnas[i]];

      for(int j = 0; j < ncolumnas[i]; j++){
        datos[i][j] = orig.datos[i][j];
      }
    }
  }else{
    datos = 0;
    ncolumnas = 0;
    nfilas = 0;
  }
}

double Matriz::Get(int fil, int col) const{
  return datos[fil][col];
}

void Matriz::Set(int fil, int col, double dato){
  datos[fil][col] = dato;
}

Matriz& Matriz::operator=(const Matriz &orig){
  if(this != &orig){
    if(ncolumnas){
      delete[] ncolumnas;
    }

    if(datos){
      for (int i = 0; i < nfilas; i++) {
        delete[] datos[i];
      }
      delete[] datos;
    }

    nfilas = orig.nfilas;
    if(orig.datos){
      datos  = new double* [nfilas];
      ncolumnas = new int [nfilas];

      for(int i = 0; i < nfilas; i++){
        ncolumnas[i] = orig.ncolumnas[i];
        datos[i] = new double [ncolumnas[i]];

        for(int j = 0; j < ncolumnas[i]; j++){
          datos[i][j] = orig.datos[i][j];
        }
      }
    }else{
      datos = 0;
      ncolumnas = 0;
      nfilas = 0;
    }

  }
  return *this;
}



ostream& operator<<(ostream &os, const Matriz &orig){
  os<< "Nº filas:"<< endl;
  os<< orig.nfilas << endl;

  os<< "Nº columnas de cada fila:"<< endl;
  for(int i = 0; i < orig.nfilas; i++){
    os<< orig.ncolumnas[i] << " ";
  }
  os<< endl;

  os<< "Matriz:"<< endl;
  for(int i = 0; i < orig.nfilas; i++){
    for(int j = 0; j < orig.ncolumnas[i]; j++){
      os<< orig.datos[i][j] << " ";
    }
    os<< endl;
  }
  return os;
}

istream& operator>>(istream &is, Matriz &orig){
  for(int i = 0; i < orig.nfilas; i++){
    delete[] orig.datos[i];
  }
  delete[] orig.datos;
  delete[] orig.ncolumnas;

  is>> orig.nfilas;
  orig.ncolumnas = new int [orig.nfilas];
  orig.datos = new double* [orig.nfilas];

  for(int i = 0; i < orig.nfilas; i++){
    is>> orig.ncolumnas[i];
    orig.datos[i] = new double [orig.ncolumnas[i]];
    for(int j = 0; j < orig.ncolumnas[i]; j++){
      is>> orig.datos[i][j];
    }
  }
  return is;
}
/*
ifstream& operator>>(ifstream& is, Matriz &orig){
  for(int i = 0; i < orig.nfilas; i++){
    delete[] orig.datos[i];
  }
  delete[] orig.datos;
  delete[] orig.ncolumnas;


  int cols;
  double dato;

  is>> orig.nfilas;
  orig.ncolumnas = new int [orig.nfilas];
  orig.datos = new double* [orig.nfilas];

  for(int i = 0; i < orig.nfilas; i++){
    is.read(reinterpret_cast<char*>(&cols), sizeof(int));
    orig.ncolumnas[i] = cols;
    orig.datos[i] = new double[orig.ncolumnas[i]];
    for(int j = 0; j < orig.ncolumnas[i]; j++){
      is.read(reinterpret_cast<char*>(&dato), sizeof(double));
      orig.datos[i][j] = dato;
    }
  }
  return is;
}
*/
/*

OPERATOR << Y >> SOLO PARA FORMATO, NO PARA BINARIO
ofstream& operator<<(ofstream &os, const Matriz &orig){
  os<< orig.nfilas << endl;
  int columnas;
  double dato;

  for(int i = 0; i < orig.nfilas; i++){
    columnas = orig.ncolumnas[i];

    // for(int j = 0; j < orig.ncolumnas[i]; i++){
    //   dato = orig.datos[i][j];
    //   os.write(reinterpret_cast<char*>(&dato), sizeof(double));
    // }
  }
  return os;
}

*/

/*
  PUNTO H

  Class Matriz{


}

*/
void Matriz::Escribir(string nombre, bool comentario) const{
  ofstream fout(nombre, ios::binary | ios::out);
  if(fout){
    fout<< "MP" << endl;

    if(comentario){
      fout<< "# Ejemplo de una matriz irregular para el examen" << endl;
    }

    fout<< nfilas <<endl;

    for(int i = 0; i < nfilas; i++){
      fout.write(reinterpret_cast<char*>(&ncolumnas[i]), sizeof(int));
      fout.write(reinterpret_cast<char*>(datos[i]), sizeof(double)*ncolumnas[i]); //Multiplicas por ncolumnas porque quieres escribir n datos de la fila
                                        //datos[i] ya es un puntero, luego no hace falta ponerle el &
    }

    fout.close();
  }else{
    cerr<< "Error en la lectura" << endl;
  }
}


/*
void Matriz::Escribir(const char* nombre, const char* comentario) const {
  ofstream fichero(nombre, ios::binary | ios:out);
  if(fichero) {
    fichero << "MP" << endl;
    if(comentario) {
      fichero << "# " << comentario << endl;
    }
    fichero << nfils << endl;
    for(int i = 0; i < nfils; i++) {
      fichero.write(reinterpret_cast<char*>(&ncolumnas[i]), sizeof(int));
      fichero.write(reinterpret_cast<char*>(datos[i]), ncolumnas[i]*sizeof(double));
    }
    fichero.close();
  }
}

*/

bool Matriz::Leer(string nombre){
  ifstream is(nombre);
  if(!is){
    return false;
  }

  is.ignore('\n');
  if(is.peek() == '#'){
    is.ignore('\n');
  }

  if(datos){
    for(int i = 0; i < nfilas; i++){
      delete[] datos[i];
    }
    delete[] datos;
    delete[] ncolumnas;
  }

  int cols;
  double dato;

  is>> nfilas;
  fichero.ignore(); //el >> te deja un '\n' al final
  ncolumnas = new int [nfilas];
  datos = new double* [nfilas];

  for(int i = 0; i < nfilas; i++){
    fout.read(reinterpret_cast<char*>(&ncolumnas[i]), sizeof(int));
    fout.read(reinterpret_cast<char*>(datos[i]), sizeof(double)*ncolumnas[i]);
    }

    fout.close();
}

/*
bool Matriz::Lectura(const char* nombre) {
  ifstream fichero(nombre);
  if(!fichero) {
    return false;
  }
  // Forma 1
  if(fichero.peek() != 'M') return false;
  fichero.ignore();
  if(fichero.peek() != 'P') return false;
  fichero.ignore(2);
  // Forma 2
  string cadenaMagica;
  fichero >> cadenaMagica;
  if(cadenaMagica != "MP") return false;
  fichero.ignore();
  // Forma 3
  string cadenaMagica;
  getline(fichero, cadenaMagica);
  if(cadenaMagica != "MP") return false;
  // Forma 4
  if(fichero.get() != 'M' || fichero.get() != 'P') return false;
  fichero.ignore();

  // Gregory (como a mi me salga): continue
  if(fichero.peek() == '#') {
    // Forma 1
    while(fichero.peek() != '\n') {
      fichero.ignore();
    }
    fichero.ignore();
    // Forma 2
    string comentario;
    getline(fichero, comentario);
  }

  if(datos) {
    for (int i = 0; i < nfils; i++) {
      delete[] datos[i];
    }
    delete[] datos;
    delete[] ncolumnas;
  }
  fichero >> nfils;
  fichero.ignore(); // VUESTRA CAGADA
  datos = new double[nfils];
  ncolumnas = new int[nfils];
  for (int i = 0; i < nfils; i++) {
    fichero.read(reinterpret_cast<char*>(&ncolumnas[i]), sizeof(int));
    fichero.read(reinterpret_cast<char*>(datos[i]), ncolumnas[i]*sizeof(double));
  }

  fichero.close();
}


*/
Matriz Matriz::Intercambiar() const{
  Matriz nueva(*this);
  if(nueva.datos){
    double* aux;
    int dato;

    for(int i = 0; i < nueva.nfilas/2; i++){
      aux = nueva.datos[i];
      nueva.datos[i] = nueva.datos[(nueva.nfilas - 1) - i];
      nueva.datos[(nueva.nfilas - 1) - i] = aux;

      dato = nueva.ncolumnas[i];
      nueva.ncolumnas[i] = nueva.ncolumnas[(nueva.nfilas - 1) - i];
      nueva.ncolumnas[(nueva.nfilas - 1) - i] = dato;
    }
  }
  return nueva;
}


void Matriz::ValorMayor(int &fils, int &cols){
  int num = datos[0][0];
  fils = 0; cols =0;

  for(int i = 0; i < nfilas; i++){
    for(int j = 0; j < ncolumnas[i]; j++){
      if(num < datos[i][j]){
        fils = i;
        cols = j;
        num = datos[i][j];
      }
    }
  }
}









int main(){
  string nombre;
  bool comentario;
  char si;

  cout<< "Introduce la matriz: "<< endl;
  cout<<"1º: nfilas(Ej 3), 2º numero de columnas de cada fila(Ej 3 3 3), 3º datos de cada fila:" << endl;

  Matriz matriz;
  cin>> matriz;
  cout<< endl << endl << endl;

  cout<< "Get: "<< matriz.Get(0,0) << endl << endl;
  matriz.Set(0,0,20);
  cout<<"Matriz 1:______________________"<< endl;
  cout<< matriz.Intercambiar() << endl << endl;

  cout<<"Matriz 2:______________________"<< endl;

  cout<< matriz;
  cout<< endl << endl;
  cout<< "Introduce nombre de fichero para escritura:" << endl;
  cin>> nombre;
  cout<< "¿Comentario? (s/n)" << endl;
  cin>> si;
  if(si == 's'){
    comentario = true;
    matriz.Escribir(nombre, comentario);
  }else if(si == 'n'){
    comentario = false;
    matriz.Escribir(nombre, comentario);
  }else{
    cout<<"Valor incorrecto" << endl;
  }


  cout<<"Lectura de fichero: "<< endl;
  matriz.Leer(nombre);

  cout<< matriz;
}
