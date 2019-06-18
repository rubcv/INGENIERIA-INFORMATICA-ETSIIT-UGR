//
// Ejercicio 4 - Relacion Pilas_Colas
//
//
// 4. Implementa el TDA pila usando dos colas.
// ¿Qué orden de eficiencia tienen las operaciones push y pop?
//


#include <queue>
#include <iostream>

using namespace std;

/* Class pila:
      operaciones:
        - push
        - pop
        - top
        - empty
        - size
        - operator <
        - operator ==
*/

class Pila{
  private:
    queue<int> una; // Con una cola es suficiente

  public:
    void push(int ele);
    void pop();
    int top() const;
    bool empty() const;
    int size() const;
    bool operator<(const Pila &orig) const;
    bool operator==(const Pila &orig) const;
    Pila& operator=(const Pila &orig);


};

void Pila::push(int ele){
  una.push(ele); // Orden de eficiencia del push de la libreria queue
}

void Pila::pop(){ // Orden de eficiencia O(log n) (del while) * O(push) * O(pop) de libreria queue
  queue<int> aux;

  int cont = 0;
  int tam = una.size() - 1;

  while(cont < tam){
    int dato = una.front();
    aux.push(dato);
    una.pop();

    cont++;
  }
  una = aux;
}

int Pila::top() const{
  return una.back();
}

bool Pila::empty() const{
  return una.empty();
}

int Pila::size() const{
  return una.size();
}

bool Pila::operator<(const Pila &orig) const{
  return (una < orig.una);
}

bool Pila::operator==(const Pila &orig) const{
  return (una == orig.una);
}

Pila & Pila::operator=(const Pila &orig){
  if(this != &orig){
    una = orig.una;
  }
  return *this;
}





int main(){

cout<< "\nPila usando una cola" << endl;

Pila una, dos;

    una.push(1);
    una.push(2);
    una.push(3);
    una.push(4);
    una.push(5);
    una.push(6);

    dos = una;

    bool iguales = una == dos;
    cout<< "Iguales: " << iguales << endl;
    while(!dos.empty()){
      int dato = dos.top();
      cout<< "\nTop: " << dato << endl;
      dos.pop();
    }
}
