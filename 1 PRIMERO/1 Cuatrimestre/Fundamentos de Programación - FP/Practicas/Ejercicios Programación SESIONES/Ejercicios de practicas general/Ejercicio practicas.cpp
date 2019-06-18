/*{En atletismo se expresa la rapidez de un atleta en términos de ritmo (minutos y segundos
ipor kilómetro) más que en unidades de velocidad (kilómetros por hora).
Escribid dos programas para convertir entre estas dos medidas:
a) El primero leerá el ritmo (minutos y segundos, por separado) y mostrará la velocidad
(kilómetros por hora).
b) El segundo leerá la velocidad (kilómetros por hora) y mostrará el ritmo (minutos
y segundos).
*/

#include <iostream>
using namespace std;
int main () {
cout<<"Este programa convierte el ritmo de un atleta en velocidad y viceversa.";

double velo,velof,met1,met2,min1,min2,rit,ritf,ritmo,velocidad; 

cout<<"Escriba la magnitud a convertir: ";
if (cin>>ritmo){
cout<< "\nIntroduce el ritmo en: minutos y metros; separados por un espacio: ";
cin>> min1;
cin>> met1;
velo=(min1*60)/(met1/100);
velof=1/velo;
cout<<"\nLa velocidad es de: "<<velof<<"km/h";
}
if(cin>>velocidad){
cout<< "\n\nIntroduce la velocidad en: metros y minutos; separados por un espacio: ";
cin>> met2;
cin>>min2;
rit=(min2*60)/(met2/100);
ritf=1/rit;
cout<<"\nEl ritmo es de: "<<ritf<<"horas/km";
}
return 0;
}
