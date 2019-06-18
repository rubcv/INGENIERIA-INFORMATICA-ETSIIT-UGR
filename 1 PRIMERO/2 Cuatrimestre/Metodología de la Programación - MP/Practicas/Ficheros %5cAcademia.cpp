#include <fstream>
#include <iostream>
#include <cstdlib> // #include <stdlib.h>

using namespace std;

int main(int argc, char* argv[]) {
  int inicio, repeticiones;

  if(argc != 3) {
    cerr << "Parametros incorrectos" << endl;
    return 10;
  }

  inicio = atoi(argv[2]);
  repeticiones = atoi(argv[1]);

  ofstream fichero("datos.txt");
  // Comentaricos :)
  if(fichero) {
    for (int i = inicio; i < inicio + repeticiones; i++) {
      fichero << i << " ";
    }
    fichero << endl;
  }
  else {
    cerr << "No se pudo abrir el fichero" << endl;
  }
}



// ________________________________________________________________________________
#include <fstream>
#include <iostream>
#include <cstdlib> // #include <stdlib.h>

using namespace std;

struct Punto {
  int x, y;
};

ostream & operator<<(ostream & os, const Punto &p) {
  os << p.x << " " << p.y;
  return os;
}

int main(int argc, char* argv[]) {
  int inicio, repeticiones;

  if(argc != 3) {
    cerr << "Parametros incorrectos" << endl;
    return 10;
  }

  inicio = atoi(argv[2]);
  repeticiones = atoi(argv[1]);

  Punto p;
  p.x = 2;
  p.y = 3;

  cout << p << endl; // operator<<(cout, p);

  ofstream fichero("datos.txt");
  // Comentaricos :)
  if(fichero) {
    for (int i = inicio; i < inicio + repeticiones; i++) {
      fichero << i << " ";
    }
    fichero << endl;
  }
  else {
    cerr << "No se pudo abrir el fichero" << endl;
  }
}