#include <iostream>
#include <time.h>
 using namespace std; 
  int main () 
  {
  	long int cogesegs(void);
 	double horas, minutos, diferencia, segundos1, segundos2;
 	cout << "Este programa calcula la diferencia de segundos entre dos instantes del d�a: \n";
 	cout<<"Introduzca instante 1� en (formato X:XX:XX): \n";
 	cin>> segundos1= cogesegs();
 	
 	cout<<"Introduzca instante 2�(Posterior): \n";
 	cin >>segundos2 = cogesegs();
 	
 	diferencia = segundos2 - segundos1;
    horas = (int)(diferencia/3600);
    diferencia = diferencia%3600;
    minutos = (int)(diferencia/60);
    diferencia = diferencia%60;
 	
 	cout<< "La diferencia en segundos es: "<< horas, minutos, diferencia);
 	return 0;
 }
