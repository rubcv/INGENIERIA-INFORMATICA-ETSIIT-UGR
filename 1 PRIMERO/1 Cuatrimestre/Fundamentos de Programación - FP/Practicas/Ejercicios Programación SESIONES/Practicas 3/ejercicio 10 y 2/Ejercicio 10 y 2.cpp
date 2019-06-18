#include <iostream>
#include <cmath>
using namespace std;
int main (){
	int altura1, altura2, altura3,media,desviacion;
cout<<"Introduzca las tres alturas separadas por un espacio: ";	
cin>> altura1; 
cin>> altura2;
cin>> altura3;
media=(altura1+altura2+altura3)/3;
cout<<"La media es: \n"<<media;

desviacion=sqrt((1/3)*(pow(altura1-media,2)+pow(altura2-media,2)+pow(altura3-media,2)));
cout<<"\n La desviacion es: \n" <<desviacion;

if (altura1<media){
cout<<"\n altura<=media\n";
}else{
cout<< "\n media<=altura \n";
}
system ("pause");
return 0;
}
