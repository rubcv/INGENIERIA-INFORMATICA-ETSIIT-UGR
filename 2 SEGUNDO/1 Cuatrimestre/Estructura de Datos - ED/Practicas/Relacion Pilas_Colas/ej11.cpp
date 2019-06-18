//
// Ejercicio 11 - Relacion Pilas_Colas
//
// 11. Implementa una cola con prioridad de un tipo struct
// con (apellidos, nombre, prioridad)
// de forma que los datos salgan de acuerdo a ese tercer campo prioridad.
//

#include <queue>
#include <iostream>
#include <vector>

using namespace std;

struct campo{
  string apellidos;
  string nombre;
  int prioridad;


  bool operator<(const campo& b){ // Hay que implementar el operator< para que la priority_queue tenga con que comparar
    return (this->prioridad < b.prioridad);
  }

}a,b,c; // Objetos del struct


struct comp{ // Struct para usar el functor, implementar en el el operator()
  bool operator()(campo a, campo b){ // Orden que sigue la priority_queue, debe estar implementado el operator< \
                                      ya que los datos son de tipo struct campo
    return (a < b);
  }
};

int main(){

priority_queue<campo, vector<campo>, comp> pq; // Creacion de la priority_queue con el orden comp

  a.prioridad = 10234;
  b.prioridad = 11;
  c.prioridad = 64;

pq.push(a);
pq.push(b);
pq.push(c);

cout<< "Cola: " << endl;

while(!pq.empty()){
  cout<< (pq.top()).prioridad << " ";
  pq.pop();
}

}
