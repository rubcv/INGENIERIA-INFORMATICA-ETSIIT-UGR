//
// Ejercicio 9 - Relacion Pilas_Colas
//
//
// 9. Un tipo ventana es un tipo de dato que permite insertar un elemento,
// mover derecha, mover izquierda, borrar elemento y que se implementa usando dos pilas.
// Implementa ese tipo de dato con las operaciones comentadas.
//

#include <stack>
#include <iostream>

using namespace std;


class Ventana{
  private:
    stack<int> izq;
    stack<int> dch;

    void volcar(stack<int> &pOrig, stack<int> &pDest);
    int PosDeDato(int ele);
    void vaciar(stack<int> &pila);
  public:

    void InstertarI(int ele);
    void InstertarD(int ele);
    void Borrar(int ele);
    void MoverIzquierda(int pos);
    void MoverDerecha(int dato);
    void Monstrar();

};

void Ventana::vaciar(stack<int> &pila){
  while(!pila.empty()){
    pila.pop();
  }
}

int Ventana::PosDeDato(int ele){
  int contIzq = 0;
  int contDch = 0;
  bool estaI = false;

  stack<int> copiaI = izq;
  stack<int> copiaD = dch;

  while(!copiaI.empty() && !estaI){
    int dato = copiaI.top();
    if(dato == ele){
      estaI = true;
      return contIzq;
    }
    contIzq++;
    copiaI.pop();
  }
  bool estaD = false;
  while(!copiaD.empty() && !estaD){
    int dato = copiaD.top();
    if(dato == ele){
      estaD = true;
      return -contDch;
    }
    contDch++;
    copiaD.pop();
  }

}

void Ventana::volcar(stack<int> &pOrig, stack<int> &pDest){ // Vuelca el origen en el destino borrando destino antes
  stack<int> copia = pOrig;


  while(!copia.empty()){
    int dato = copia.top();
    pDest.push(dato);
    copia.pop();
  }
}


void Ventana::InstertarI(int ele){
  izq.push(ele);
}

void Ventana::InstertarD(int ele){
  dch.push(ele);
}

void Ventana::MoverIzquierda(int dat){
  int pos = PosDeDato(dat);

  if(pos > 0){
    pos += 1; // Se le suma 1 por el desfase de la funcion PosDeDato()
    stack<int> aux;
    int cont = 1;

    while(cont < pos){ // Se vacia la pila hasta la posicion del dato
      aux.push(izq.top()); // Se guarda en aux
      izq.pop();
      cont++;
    }
    int dato = izq.top(); // Se guarda el dato
    izq.pop(); // Se saca el dato de 'izq'
    izq.push(aux.top()); // Se guarda el dato de su izq en 'izq' \
                          (Se avanza a la derecha el anterior)
    aux.pop(); // Se saca el anterior de 'aux'
    izq.push(dato); // Se guarda el dato (a la izq de donde estaba)

    volcar(aux, izq); // Se vuelca el resto de la pila
  }else if(pos == 0){
          int aux = dch.top();
          dch.pop();
          int dato = dch.top();
          dch.pop();
          dch.push(aux);
          dch.push(dato);

    }else if(pos < 0){
          int res = (pos * -1);
          int cont = 0;
          stack<int> aux;

          while(cont < res - 1){
            aux.push(dch.top());
            dch.pop();
            cont++;
          }

          int anterior = dch.top();
          dch.pop();
          int dato = dch.top();
          dch.pop();

          dch.push(anterior);
          dch.push(dato);

          volcar(aux, dch);
      }

}

void Ventana::MoverDerecha(int ele){
  int pos = PosDeDato(ele);

    if(pos > 0){
      pos += 1; // Se le suma 1 por el desfase de la funcion PosDeDato()
      stack<int> aux;
      int cont = 1;

      while(cont < pos){ // Se vacia la pila hasta la posicion del dato
        aux.push(izq.top()); // Se guarda en aux
        izq.pop();
        cont++;
      }
      int dato = izq.top(); // Se guarda el dato
      izq.pop(); // Se saca el dato de 'izq'
      int auxd = izq.top();
      izq.pop();
      izq.push(dato); // Se guarda el dato de su izq en 'izq' \
                            (Se avanza a la derecha el anterior)
      //aux.pop(); // Se saca el anterior de 'aux'
      izq.push(auxd); // Se guarda el dato (a la izq de donde estaba)

      volcar(aux, izq); // Se vuelca el resto de la pila

    }else if(pos == 0){
        stack<int> aux = dch;
        vaciar(dch);
        int dato = aux.top();
        aux.pop();
        int auxd = aux.top();
        aux.pop();
        volcar(aux, dch);
        dch.push(dato);
        dch.push(auxd);

      }else if(pos < 0){
            int res = (pos * -1);
            int cont = 0;
            stack<int> aux;

            while(cont < res - 1){
              aux.push(dch.top());
              dch.pop();
              cont++;
            }
            aux.push(dch.top());
            dch.pop();

            int dato = dch.top();
            dch.pop();
            int post = dch.top();
            dch.pop();

            dch.push(dato);
            dch.push(post);

            volcar(aux, dch);
        }
}

void Ventana::Borrar(int ele){
  int pos = PosDeDato(ele);
  stack<int> aux;
  if(pos > 0){
    int cont = 0;
      while(cont < pos){ // Se vacia la pila hasta la posicion del dato
        aux.push(izq.top()); // Se guarda en aux
        izq.pop();
        cont++;
      }
      izq.pop(); // Se saca el dato de 'izq'
      volcar(aux, izq); // Se vuelca el resto de la pila
  }else{
    int res = (pos * -1);
    int cont = 0;

    while(cont < res ){
      aux.push(dch.top());
      dch.pop();
      cont++;
    }
    dch.pop(); // Se saca el dato de 'dch'
    volcar(aux, dch);
  }
}


void Ventana::Monstrar(){
  stack<int> izqAux = izq;
  stack<int> dchAux = dch;
  while(!izqAux.empty()){
    int dato = izqAux.top();
    cout<< dato << " ";
    izqAux.pop();
  }

  cout<< "|";


  while(!dchAux.empty()){
    int dato = dchAux.top();
    cout<< dato << " ";
    dchAux.pop();
  }
}

int main(){

  Ventana una;

  una.InstertarI(5);
  una.InstertarI(4);
  una.InstertarI(4); // Dos '4' para borrar
  una.InstertarI(3);
  una.InstertarI(2);
  una.InstertarI(1);
  una.InstertarI(0);

  una.InstertarD(10);
  una.InstertarD(9);
  una.InstertarD(8);
  una.InstertarD(7);
  una.InstertarD(6);


  una.Borrar(4); // Borra un 4 (Cambiar)

  cout<< "\nAntes (Mover izq):" << endl;
  una.Monstrar();
  una.MoverIzquierda(5); // Mueve un 5 a la izquierda
  cout<< endl;
  cout<< "Despues (Mover izq:" << endl;
  una.Monstrar();
  cout<< endl;
  cout<< "\n-------------------------------------------------" << endl;
  cout<< "\nAntes (Mover dch):" << endl;
  una.Monstrar();
  una.MoverDerecha(2); // Mueve el 2 a la dcha
  cout<< endl;
  cout<< "Despues (Mover dch):" << endl;
  una.Monstrar();
  cout<< endl;
  cout<< "\n-------------------------------------------------" << endl;

  cout<< endl << endl;
}
