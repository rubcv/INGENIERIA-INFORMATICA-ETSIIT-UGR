#include <iostream>

using namespace std;

struct Celda{
  Celda* sig;
  int dato;
};

class Lista{
  private:
    Celda* inicio;

  public:

    Celda* getInicio(){
      return inicio;
    }

    Lista(){
      inicio = NULL;
    }


    void Insertar(int dato){
      Celda* nueva = new Celda;
      nueva->dato = dato;
      nueva->sig = NULL;
      if(!inicio){
        inicio = nueva;
      }else{
        Celda* aux = inicio;

        while(aux->sig != NULL){
          aux = aux->sig;
        }
        aux = nueva;
      }
    }

};


Celda** Dividir(Lista &orig, int t){
  Celda** res;
  Celda* aux, *aux2;
  int tam = 0, tamRes = 0;

  aux = orig.getInicio();

  while(aux != NULL){
    aux = aux->sig;
    tam++;
  }

  if(tam % t == 0){
    res = new Celda* [tam/t];
    tamRes = tam/t;
  }else{
    res = new Celda* [tam/t + 1];
    tamRes = tam/t + 1;
  }

  aux2 = orig.getInicio();
  res[0] = orig.getInicio();

  for(int i = 1; i < tamRes; i++){
    res[i] = res[i - 1] + t;

    while(aux2->sig != (res[i])->sig){
      aux2 = aux2->sig;
    }
    aux2->sig = NULL;
    aux2 = (res[i])->sig;
  }

return res;
}


int main(){
  Lista orig;
  orig.Insertar(1);
  orig.Insertar(1);
  orig.Insertar(1);
  orig.Insertar(1);
  orig.Insertar(1);

Celda** Resultado = Dividir(orig, 2);

  if(Resultado){
    cout<< "Division realizada con exito" << endl;
  }

}
