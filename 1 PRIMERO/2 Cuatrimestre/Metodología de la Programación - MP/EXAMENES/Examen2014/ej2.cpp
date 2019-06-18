#include <iostream>
#include <fstream>
using namespace std;

class Barquitos{
 private:
   int** datos;
   int filas;
   int cols;
 public:
  Barquitos();
  bool CasillaPosible(int i, int j)const;
  bool comprobar(char f, int c, char dir, int tam) const;
   Barquitos(int filas, int cols);
   ~Barquitos();
   Barquitos(const Barquitos& orig);
   int Aleatorio(int x, int y);
   Barquitos& operator=(const Barquitos& orig);
   void Insertar(int tam);
   bool Leer(string nombre);
   bool Escribir(string nombre);
};

Barquitos::Barquitos(){
  datos = 0;
  filas = 0;
  cols = 0;
}

Barquitos::Barquitos(int filas, int cols){
  this->filas = filas;
  this->cols = cols;

  if(filas*cols > 0){
    datos = new int* [filas];

    for(int i = 0; i < filas; i++){
      datos[i] = new int [cols];
      for(int j = 0; j < cols; j++){
        datos[i][j] = 9;
      }
    }
  }
}


Barquitos::~Barquitos(){
  if(datos){
    for(int i = 0; i < filas; i++){
      delete[] datos[i];
    }
    delete[] datos;
  }
}


Barquitos::Barquitos(const Barquitos& orig){
  filas = orig.filas;
  cols = orig.cols;

  if(orig.datos){
    datos = new int* [filas];
    for(int i = 0; i < filas; i++){
      datos[i] = new int [cols];
      for(int j = 0; j < cols; j++){
        datos[i][j] = orig.datos[i][j];
      }
    }
  }else{
    datos = 0;
    filas = 0;
    cols = 0;
  }
}


Barquitos& Barquitos::operator=(const Barquitos& orig){
  if(this != &orig){
    if(datos){
      for(int i = 0; i < filas; i++){
        delete[] datos[i];
      }
      delete[] datos;
    }


    filas = orig.filas;
    cols = orig.cols;

    if(orig.datos){
      datos = new int* [filas];
      for(int i = 0; i < filas; i++){
        datos[i] = new int [cols];
        for(int j = 0; j < cols; j++){
          datos[i][j] = orig.datos[i][j];
        }
      }
    }else{
      datos = 0;
      filas = 0;
      cols = 0;
    }
  }
  return *this;
}

bool Barquitos::CasillaPosible(int i, int j)const{
  return (i < 0 || i >= filas || j < 0 || j>= cols || datos[i][j] == 9); //Si te sales del tablero o hay agua te devuelve true
}

bool Barquitos::comprobar(char f, int c, char dir, int tam) const{
  bool posible = true;
  int fil = f - 'A';
  int col = c - 1;
  if(dir == 'H'){
    for(int i = fil - 1; i <= fil + 1 && posible; i++){
      for(int j = col - 1; j < col + tam + 1 && posible; j++){
        posible = CasillaPosible(i, j);
      }
    }
  }else if(dir == 'V'){
    for(int i = fil - 1; i <= fil + tam + 1 && posible; i++){
      for(int j = col - 1; j < col + 1 && posible; j++){
        posible = CasillaPosible(i, j);
      }
    }
  }

}

int Barquitos::Aleatorio(int x, int y){
  return random(x,y);
}

void Barquitos::Insertar(int tam){
  int fil, col;
  char pos;

  while(!comprobar(fil, col, tam, pos)){
    fil = Aleatorio(1,filas);
    col = Aleatorio(1,cols);

    if(Aleatorio(1,2) == 1){
      pos = 'H';
    }else{
      pos = 'V';
    }
  }

  if(pos == 'H'){
    for(int i = 0; i < tam; i++){
      datos[fil][i] = tam;
    }
  }else{
    for(int i = 0; i < tam; i++){
      datos[i][col] = tam;
    }
  }
}

bool Barquitos::Leer(string nombre){
  bool res = true;

  ifstream fin(nombre);

  if(!fin){
    res = false;
  }

  if(res){
    string cadenaMagica;

    fin>> cadenaMagica;

    if(cadenaMagica != "MP-BARQ-V1.0"){
      res = false;
    }

    fin>> filas >> cols;
    fin.ignore(); // '\n'

    datos = new int* [filas];

    for(int i = 0; i < filas; i++){
      datos[i] = new int [cols];
      fin.read(reinterpret_cast<char*>(datos[i]), sizeof(int)*cols);
      }
    fin.close();
    }

  return res;
}

bool Barquitos::Escribir(string nombre){
  bool res = true;
  ofstream fout(nombre);
  if(!fout){
    res = false;
  }

  if(res){
    fout<< "MP-BARQ-V1.0" << endl;

    fout<< filas << " ";
    fout<< cols << endl;

    for(int i = 0; i < filas; i++){
        fout.write(reinterpret_cast<char*>(datos[i]), sizeof(int)*cols);
    }
    fout.close();
  }
  return res;
}


int main(){

  Barquitos barco(6,6);

  barco.Escribir("barco.txt");

  Barquitos barco2;

  if(barco2.Leer("barco.txt")){
    cout<<"Leida con exito" << endl;
  }


}
