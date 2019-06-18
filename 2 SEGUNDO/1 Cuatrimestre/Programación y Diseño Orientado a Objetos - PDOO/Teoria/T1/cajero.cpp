#include <iostream>

using namespace std;

const long TOTAL = 1000000;
const long SALDO = 2836;

int main(){
  long cantidad, totfinal;
  int b10 = 100,
  b20 = 100,
  b50 = 100,
  b100 = 100,
  b200 = 100,
  b500 = 100;
  cout<< "Dispones de " << SALDO << " $" << endl;
  cout<< "Cuanto quieres sacar? "<< endl;
  cout<< "10" << " " << "20" << endl;
  cout<< "50" << " " << "100" << endl;
  cout<< "200" << " " << "500" << endl;

  cin>> cantidad;
  while(cantidad > SALDO && cantidad != 0){
    cout<< "Introduce cantidad valida, 0 para salir" << endl;
    cin>> cantidad;
  }

  if(cantidad < SALDO){
    long totfinal = TOTAL - cantidad;
    saldFin = SALDO - cantidad;
  }


  /*
  Comprobar si la cantidad se puede dividir en billetes grandes, si no es asi ir bajando para sacar el menor numero \
  de billetes posible */


}
