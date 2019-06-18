#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;



class BigInt{
  private:
    int* datos;
    int longitud;
  public:
    BigInt();
    ~BigInt();
    BigInt(const char cadena[]);
    BigInt(unsigned int numero);
    BigInt(const BigInt &orig);
    BigInt& operator=(const BigInt &orig);
    BigInt  operator+(const BigInt &ent) const;
    friend ostream& operator<< (ostream &os, const BigInt &orig);
    friend istream& operator>>(istream &is, BigInt &orig);

};

BigInt::BigInt(){
  longitud = 1;
  datos = new int;
  datos[0] = 0;
}

BigInt::~BigInt(){
  if(datos){
    delete[] datos;
  }
}


BigInt::BigInt(const char cadena[]){
  longitud = strlen(cadena);
  datos = new int [longitud];

  for(int i = 0; i < longitud; i++){ //Copiarla al reves
    datos[i] = cadena[longitud - 1 - i] - '0'; //Le quitas '0' porque el char te guarda la equivalencia en la tabla ascii
  }
}


BigInt::BigInt(unsigned int numero){
  unsigned int copia = numero;
  int n = 1;
  while(copia > 9){ //Va dividiendo y contando los datos para hacer la reserva
    n++;
    copia /= 10;
  }
  datos = new int[n];
  for(int i = 0; i < n; i++){
    datos[i] = numero % 10; //Te quedas con la izquierda para que se guarde al reves
    numero /= 10; //Lo vas haciendo mas pequeño
  }
}




BigInt::BigInt(const BigInt &orig){
  longitud = orig.longitud;
  if(orig.datos){
    datos = new int [longitud];
    for(int i = 0; i < longitud; i++){
      datos[i] = orig.datos[i];
    }
  }else{
    datos = 0;
    longitud = 0;
  }
}


BigInt& BigInt::operator=(const BigInt &orig){
  if(this != &orig){
    if(datos){
      delete[] datos;
    }

    longitud = orig.longitud;
    if(orig.datos){
      datos = new int [longitud];
      for(int i = 0; i < longitud; i++){
        datos[i] = orig.datos[i];
      }
    }else{
      datos = 0;
      longitud = 0;
    }
  }
return *this;
}



ostream& operator<< (ostream &os, const BigInt &orig){
  os<< orig.longitud << endl;

   for(int i = orig.longitud - 1; i >= 0; i--){
     os<< orig.datos[i];
   }
  return os;
}

istream& operator>>(istream &is, BigInt &orig){

    delete[] orig.datos;

  string dato;
  is>> dato;
  //orig = BigInt(dato.c_str()); // Usando el constructor del char[]
  int longi = dato.size();
  orig.longitud = longi;
  orig.datos = new int[longi];

  for(int i = 0; i < orig.longitud; i++){
    orig.datos[i] = dato[orig.longitud - 1 - i] - '0'; // -'0' porque el char te guarda el valor de la tabla ascii, si le quitas el '0' te lo pasa a numero normal
  }
  return is;
}

/*
BigInt BigInt::operator+(const BigInt &orig) const{
  int tope;
    if(longitud <= orig.longitud){
      tope = longitud;
    }else{
      tope = orig.longitud;
    }

    BigInt res;
    res.longitud = tope + 1;
    res.datos = new int [res.longitud];

    for(int i = 0; i < res.longitud; i++){
      res.datos[i] = 0;
    }

      int num, numSig;
    for(int i = 0; i < res.longitud - 1; i++){
      for(int j = 0; j < longitud; j++){
        for(int k = 0; k < orig.longitud; k++){
          if(datos[j] + orig.datos[k] + res.datos[i] > 9){
            num = (datos[j] + orig.datos[k] + res.datos[i]) % 10;
            numSig = (datos[j] + orig.datos[k] + res.datos[i]) / 10;
            res.datos[i + 1] += numSig;
          }else{
            num = datos[j] + orig.datos[k] + res.datos[i];
          }
          j++;
          res.datos[i] += num;

        }
      }

    }
    return res;
}
*/

BigInt BigInt::operator+(const BigInt &ent) const{
  BigInt suma;
  int acarreo = 0;

  suma.longitud = (longitud > ent.longitud)? longitud : ent.longitud;
  suma.datos = new int [suma.longitud];

  for(int i = 0; i < suma.longitud; i++){
    if(i > longitud){
      suma.datos[i] = ent.datos[i] + acarreo;
    }else if(i > ent.longitud){
      suma.datos[i] = datos[i] + acarreo;
    }else{
      suma.datos[i] = datos[i] + ent.datos[i] + acarreo;
    }
    if(suma.datos[i] > 9){
      suma.datos[i] = suma.datos[i] % 10;
      acarreo = 1;
    }else{
      acarreo = 0;
    }
  }
  if(acarreo){
    int* aux = new int [suma.longitud + 1];
    for(int i = 0; i < suma.longitud; i++){
      aux[i] = suma.datos[i];
    }
    aux[suma.longitud] += acarreo;
    delete[] suma.datos;
    suma.datos = aux;
    suma.longitud++;
  }
  return suma;
}

BigInt  Suma(const char* nombre){
  BigInt dato, suma;
  ifstream fin(nombre);
    if(fin){
      while(fin>> dato){
        suma = suma + dato;
      }
      fin.close();
    }
  return suma;
}

int main(){

  BigInt uno, dos, tres;
  cout<< "Introduce 3 BigInt's: " << endl;
  cout<< "1º : ";
  cin>> uno;
  cout<< endl;
  cout<< "2º : ";
  cin>> dos;
  cout<< endl;
  cout<< "3º : ";
  cin>> tres;
  cout<< endl << endl;
  cout<< "uno: ";
  cout<< uno;
  cout<< endl;
  cout<< "dos: ";
  cout<< dos;
  cout<< endl;
  cout<< "tres: ";
  cout<< tres;
  cout<< endl;
  cout<< endl;

  tres = uno + dos;

  cout<<" tres = uno + dos: "<< endl;
  cout<< tres;

  cout<< endl<< endl;

cout<<"De fichero: [test.txt contiene 536 y 721] Suma = 1257:" << endl;
cout<< Suma("test.txt") << endl;


}
