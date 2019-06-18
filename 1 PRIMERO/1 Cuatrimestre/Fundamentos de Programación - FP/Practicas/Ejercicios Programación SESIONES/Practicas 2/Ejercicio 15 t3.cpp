#include <iostream>	
using namespace std;
int main () {
	int hora, min, seg, suma;
cout <<"Introduzca los: \n";
cout<< "segundos ";
cin>> seg;
cout<<"minutos ";
cin>> min;
cout<<"horas ";
cin>> hora;

suma=seg/60;
seg=seg%60;
min=min+suma;


suma=min/60;
min=min%60;
hora=hora+suma;

suma=hora/60;
hora=hora%60;
hora=hora+suma;

cout<< hora<< " horas "<< min<< " minutos "<< seg<< " segundos ";	
	
	return 0;
}

