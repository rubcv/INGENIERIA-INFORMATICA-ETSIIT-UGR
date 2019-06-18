#include <iostream>


using namespace std;

struct dato{
  float elem;
  int siguiente;
};

class Lista{
  private:
    dato* elementos;
    int primero;
    int nelems;

  public:
    Lista(const Lista &orig){
      primero = orig.primero;
      nelems = orig.nelems;

      if(orig.elementos){
        elementos = new dato[nelems];

        for(int i = 0; i < nelems; i++){
          elementos[i] = orig.elementos[i];
        }
      }else{
        elementos = 0;
        primero = 0;
        nelems = 0;
      }
    }

    Lista& operator=(const Lista &orig){
      if(this != &orig){
        if(elementos){
          delete[] elementos;
        }

        primero = orig.primero;
        nelems = orig.nelems;

        if(orig.elementos){
          elementos = new dato[nelems];

          for(int i = 0; i < nelems; i++){
            elementos[i] = orig.elementos[i];
          }
        }else{
          elementos = 0;
          primero = 0;
          nelems = 0;
        }
      }
      return *this;
    }


    bool operator==(const Lista &orig) const{
      bool iguales = true;

      if(this != &orig){
        if(primero == orig.primero && nelems == orig.nelems){
          bool vectorIgual = true;

          for (int i = 0; i < nelems && vectorIgual; i++) {
            if(elementos[i] != orig.elementos[i]){
              vectorIgual = false;
            }
          }
          if(vectorIgual == false){
            iguales = false;
          }
        }else{
          iguales =false;
        }
      }
      return iguales;
    }
};

int main(){

}
