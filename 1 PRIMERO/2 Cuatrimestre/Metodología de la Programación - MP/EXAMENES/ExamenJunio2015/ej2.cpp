#include <iostream>

using namespace std;


Frecuencias& Frecuencias::operator+=(int num){
  Add(num);
  return *this;
}

void Frecuencias::Add(int num){
  bool esta = false;

  for(int i = 0; i < npares && !esta; i++){
    if(parejas[i].dato == num){
      esta = true;
      parejas[i].nveces++;
    }
  }
  if(!esta){
    Pareja* aux = new Pareja[npares + 1];
    for(int i = 0; i < npares; i++){
      aux[i] = parejas[i];
    }
    delete[] parejas;
    parejas = aux;
    parejas[npares].dato = num;
    parejas[npares].nveces++;
    npares++;
  }
}


Frecuencias Leer(istream &is){
  Frecuencias freq;
  int num;
  while(is >> num){
    freq.Add(num);
  }
  return freq;
}

int main(){
  Frecuencias freq;
  if(argc == 1){
    freq = Leer(cin);
  }else if(argc == 2){
    ifstream fich(...);
    if(fich){
      freq = Leer(fich);
    }
  }

  cout<< freq << endl;

}
