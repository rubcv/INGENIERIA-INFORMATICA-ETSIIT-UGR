#include <iostream>
#include <fstream>

using namespace std;

class Polilinea; // Defines la clase Polilinea porque Punto la utiliza

class Punto{
  private:
    int x;
    int y;
  public:
    friend class Polilinea;
    bool operator!=(const Punto &orig) const;
    Polilinea operator+(const Polilinea &orig) const;
    friend ostream& operator<<(ostream &os, const Punto &orig);
    friend istream& operator>>(istream &is, Punto &orig);
};

class Polilinea{
  private:
    Punto* p;
    int num;
  public:
    friend class Punto; // Hacer los operator+ fuera de las clases y ponerlo como friend en las dos clases
    Polilinea();
    ~Polilinea();
    Polilinea(const Polilinea &orig);
    Polilinea& operator=(const Polilinea &orig);
    Punto& operator[](int pos);
    const Punto& operator[](int pos) const
    bool operator==(const Polilinea &orig) const;
    bool operator!=(const Polilinea &orig) const;
    Polilinea operator+(const Punto &orig) const;
    bool LeerPolilinea(const char* nombre);
    void EscribirPolilinea(const char* nombre, const char* comentario);

    friend ostream& operator<<(ostream &os, const Polilinea &orig);

};

Polilinea::Polilinea(){
  p = 0;
  num = 0;
}

Polilinea::~Polilinea(){
  if(p){
    delete[] p;
  }
}

Polilinea::Polilinea(const Polilinea &orig){
  num = orig.num;
  if(orig.p){
    p = new Punto [num];
    for(int i = 0; i < num; i++){
      p[i] = orig.p[i];
    }
  }else{
    p = 0;
    num = 0;
  }
}


Polilinea& Polilinea::operator=(const Polilinea &orig){
  if(this != &orig){
    if(p){
      delete[] p;
    }

    num = orig.num;
    if(orig.p){
      p = new Punto [num];
      for(int i = 0; i < num; i++){
        p[i] = orig.p[i];
      }
    }else{
      p = 0;
      num = 0;
    }
  }
    return *this;
}


Punto& Polilinea::operator[](int pos){
  return p[pos];
}

const Punto& Polilinea::operator[](int pos) const{
  return p[pos];
}


bool Polilinea::operator==(const Polilinea &orig) const{
  bool iguales = true;

  if(this != &orig){
    if(num != orig.num){
      iguales = false;
    }else{
      for(int i = 0; i < num && iguales; i++){
        if(p[i] != orig.p[i]){
          iguales = false;
        }

        for(int i = 0; i < num && iguales; i++){
          if(p[i] != orig.p[num - 1 - i]){
            iguales = false;
          }
      }
    }
  }
  return iguales;
}


bool Punto::operator!=(const Punto &orig) const{
  bool distinto = false;
  if(this != &orig){
    if(x != orig.x && y != orig.y){
      distinto = true;
    }
  }
  return distinto;
}

bool Polilinea::operator!=(const Polilinea &orig) const{ // Si tienes el operator== :  return !(*this == orig);
/*
  bool distinto = false;
  if(this != &orig){
    if(num == orig.num){
      for(int i = 0; i < num && !distinto; i++){
        if(p[i] != orig.p[i]){
          distinto = true;
        }
      }
    }else{
      distinto = true;
    }
  }
  return distinto;
*/

  return !(*this == orig);
}

Polilinea Polilinea::operator+(const Punto &orig) const{
  Polilinea nueva(*this);


  Punto* aux = new Punto[nueva.num + 1];

  for(int i = 0; i < nueva.num; i++){
    aux[i] = nueva.p[i];
  }
  nueva.num++;
  aux[nueva.num] = orig;

  delete[] nueva.p;
  nueva.p = aux;

  return nueva;
}

Polilinea Punto::operator+(const Polilinea &orig) const{
  Polilinea nueva(orig);

  Punto* aux = new Punto [nueva.num + 1];

  aux[0] = *this;

  for(int i = 0; i < nueva.num; i++){
    aux[i + 1] = orig.p[i];
  }

  nueva.num++;

  delete[] nueva.p;
  nueva.p = aux;

  return nueva;
}


bool Polilinea::LeerPolilinea(const char* nombre){
  bool lectura = false;
  ifstream fin(nombre);
  if(fin){
    lectura = true;
    string cad;
    fin>> cad;
    fin.ignore();
    if(cad != "POLILINEA"){
      lectura = false;
    }
      if(fin.peek() == '#'){
        while(fin.peek() != '\n'){
          fin.ignore();
        }
        fin.ignore();
      }
      fin>> num;
      delete[] p;
      p = new Punto[num];

      for(int i = 0; i < num && lectura; i++){
        fin>> p[i];
      }

    fin.close();
  }
  return lectura;
}


void Polilinea::EscribirPolilinea(const char* nombre, const char* comentario){
  ofstream fout(nombre);
  if(fout){
    fout<< "POLILINEA" << endl;
    if(comentario){
      fout<< "#" << comentario << endl;
    }
    fout<< num << endl;

    for(int i = 0; i < num; i++){
      fout<< p[i];
    }
    fout.close();
  }
}


istream& operator>>(istream &is, Punto &orig){
  is>> orig.x >> orig.y;

  return is;
}
ostream& operator<<(ostream &os, const Punto &orig){
  os<< orig.x << " " << orig.y << endl;
  return os;
}

ostream& operator<<(ostream &os, const Polilinea &orig){
  os<< orig.num << endl;

  for(int i = 0; i < orig.num; i++){
    os<< orig.p[i]; //Necesita operator<< de Punto
  }
  return os;
}
int main(){
  Polilinea p1, p2, p3;
  Punto p;
  p3 = p1 + p;
  p2 = p + p1;
  if(p3 == p2){
    cout<< "Iguales" << endl;
  }

  if(p1.LeerPolilinea("test.txt")){
    cout<<"Exito en la lectura" << endl;
    cout<< p1;
  }

  p1.EscribirPolilinea("p1.txt", "ElComentario");

}
