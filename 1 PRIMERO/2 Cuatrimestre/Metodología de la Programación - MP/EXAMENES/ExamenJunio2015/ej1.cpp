#include <iostream>
using namespace std;


struct Celda{
  double dato;
  Celda* sig;
};


void Insertar(Celda* &lista, double dato){
    Celda* nueva = new Celda;
    nueva->dato = dato;
    nueva->sig = NULL;

    if(!lista.sig){
      lista.sig = nueva;
    }else{
      Celda* aux = lista.sig;
      while(aux->sig != NULL){
        aux = aux->sig;
      }
      aux->sig = nueva;
    }

}

void InsertarPrincipio(Celda* &lista, double dato){
  Celda* nueva = new Celda;
  nueva->dato = dato;
  nueva->sig = lista;
  lista = nueva;
}

void BorrarPrimero(Celda* &lista){
  Celda* borra = lista;
  lista = lista->sig;
  delete borra;
}

void ImprimirLista(Celda* &orig){ //Para mostrar al reves, hacer funcion que inserte al principio  y mostrar la primera
  Celda* aux, *listaaux = NULL;
  aux = orig;
  while(aux){
    InsertarPrincipio(listaaux, aux->dato);
    aux = aux->sig;
  }
  while(listaaux){
    cout<< listaaux->dato << " ";
    BorrarPrimero(listaaux);
  }
}





int main(){

  Celda* una;

  Insertar(una, 1);
  Insertar(una, 2);
  Insertar(una, 3);
  Insertar(una, 4);
  Insertar(una, 5);

  ImprimirLista(una);

}
