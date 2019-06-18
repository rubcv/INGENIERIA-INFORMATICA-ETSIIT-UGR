#include <iostream>
#include <fstream>
using namespace std;



class VectorDinamico{
  private:
    int NumMaxElems;
    int NumOcupados;
    int * v;
  public:

    VectorDinamico(){
      v = 0;
      NumOcupados = 0;
      NumMaxElems = 0;
    }

  friend ostream& operator<<(ostream& os, const VectorDinamico &orig);


    void push_back(int ele){
      if(!v){
        v = new int;
        v[0] = ele;
        NumMaxElems++;
        NumOcupados++;

      }else{
        int* aux = new int [NumOcupados + 1];

        for(int i = 0; i < NumOcupados; i++){
          aux[i] = v[i];
        }
        aux[NumOcupados] = ele;

        NumMaxElems++;
        NumOcupados++;
        delete[] v;
        v = aux;
      }
    }


    bool redimensionar(int nuevotam){
      int* aux;
      bool todos;
      aux = new int[nuevotam];
      if(nuevotam >= NumOcupados){
        for (int i = 0; i < NumOcupados; i++) {
            aux[i] = v[i];
        }
        todos = true;
        NumMaxElems = nuevotam;
      }else{
        for(int i = 0; i < nuevotam; i++){
          aux[i] = v[i];
        }
        todos = false;
        NumMaxElems = NumOcupados = nuevotam;
      }
      delete[] v;
      v = aux;

      return todos;
    }
};

ostream& operator<<(ostream& os, const VectorDinamico &orig){
  os<< "NumMaxElems: "<< orig.NumMaxElems << endl;
  os<< "NumOcupados: "<< orig.NumOcupados << endl;

  for(int i = 0; i < orig.NumOcupados; i++){
    os<< "V[" << i << "] : " << orig.v[i] << endl;
  }
  return os;
}

int main(){


  VectorDinamico uno;

  uno.push_back(1);
  uno.push_back(2);
  uno.push_back(3);
  uno.push_back(4);
  uno.push_back(5);
  uno.push_back(6);

uno.redimensionar(9);
  cout<< uno;

  ofstream fout("res.txt");
  fout<< uno;

  fout.close();


}
