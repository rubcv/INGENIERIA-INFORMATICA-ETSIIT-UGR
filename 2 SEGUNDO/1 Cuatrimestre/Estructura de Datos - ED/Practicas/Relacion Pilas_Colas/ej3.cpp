//
// Ejercicio 3 - Relacion Pilas_Colas
//
// 3. Implementa un TDA cola usando como representación dos pilas.
//

#include <stack>
#include <iostream>

using namespace std;

/*  Class Cola:
      Operaciones:
        - push
        - pop
        - front
        - back
        - empty
        - size
        - operator <
        - operator ==
*/

class Cola{
  private:
    stack<int> una;
    stack<int> dos;

    void volcar(stack<int> &pOrig, stack<int> &pDest);

  public:

    void push(int dato);
    void pop();
    int front() const;
    int back() const;
    bool empty() const;
    int size() const;
    bool operator<(const Cola &orig) const;
    bool operator==(const Cola &orig) const;
    Cola & operator=(const Cola &orig);

};

void Cola::volcar(stack<int> &pOrig, stack<int> &pDest){ // Vuelca el origen en el destino borrando destino antes
  stack<int> copia = pOrig;

  while(!pDest.empty()){
    pDest.pop();
  }

  while(!copia.empty()){
    int dato = copia.top();
    pDest.push(dato);
    copia.pop();
  }
}


void Cola::push(int dato){
  una.push(dato);

  // Actualizar la otra
  volcar(una, dos);
}

void Cola::pop(){
  if(!dos.empty()){
    dos.pop();

    // Quitarlo tambien de "una"
    volcar(dos, una);
  }
}

int Cola::front() const{
  return dos.top();
}

int Cola::back() const{
  return una.top();
}

bool Cola::empty() const{
  return una.empty();
}

int Cola::size() const{
  return una.size();
}

bool Cola::operator<(const Cola &orig) const{
  return (dos < orig.dos); // La 2º pila es con la que comparas
}


bool Cola::operator==(const Cola &orig) const{
  return (dos == orig.dos);
}


Cola & Cola::operator=(const Cola &orig){
  if(this != &orig){
    una = orig.una;
    dos = orig.dos;
  }
  return *this;
}

int main(){

cout<< "\nCola con dos pilas: " << endl;
  Cola una, dos;

  una.push(1);
  una.push(2);
  una.push(3);
  una.push(4);
  una.push(5);
  una.push(6);

  dos  = una;

  int back = dos.back();
  cout<< "Back: " << back << endl;

  while(!dos.empty()){
    int front = dos.front();
    cout<< "Front: " << front << endl;

    dos.pop();
  }

}
