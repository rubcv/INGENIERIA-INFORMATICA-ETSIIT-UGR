 #include <iostream>
  using namespace std;
  int main () {
  	double distancia, litros_consumidos, litros_deposito,consumo, km_auto, litros;
 
 cout<< "Introduzca la distancia recorrida en km: ";
 cin>> distancia;
 cout<< "Introduzca los litros de gasolina consumidos: ";
 cin>>  litros_consumidos;
 cout<< "Introduzca los litros de gasolina restantes en el depósito: "; 
  cin>> litros_deposito;
  
  consumo=distancia/(litros_deposito-litros_consumidos);
  km_auto= (litros_deposito-litros_consumidos)*distancia/litros_consumidos;
  litros= (litros_deposito-litros_consumidos)/100;
  
  cout<< "\n El consumo de su vehículo es de: "<<consumo <<"Km/L";
  cout<< "\n Su vehículo dispone de: "<<km_auto  <<"Km de autonomía";
  cout<< "\n Su vehículo consume: "<<litros  <<"Litros por cada 100 Km";
  return 0;
  }
