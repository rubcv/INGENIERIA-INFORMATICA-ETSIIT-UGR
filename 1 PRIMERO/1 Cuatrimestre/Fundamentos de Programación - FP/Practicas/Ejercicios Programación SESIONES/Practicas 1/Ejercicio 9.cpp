#include <iostream>
 using namespace std;
  int main () {
  	double edadPedro, edadJuan, aux;
  cout<< "Este programa intercambia las edades de Pedro y Juan.\n";
  cout << "\n Para ello introduzca la edad de Pedro: ";
  cin>> edadPedro;
  cout<< "\n Introduzca la edad de Juan: ";
  cin>> edadJuan;
  aux=edadPedro;
   edadPedro=edadJuan;
   edadJuan=aux;
  
  cout<< "\n Las correspondientes edades son: \n";
  cout<<"\n Edad de Pedro: "<<edadPedro;
   cout<<"\n Edad de Juan: "<<edadJuan; 
  	
  	return 0;
  }
