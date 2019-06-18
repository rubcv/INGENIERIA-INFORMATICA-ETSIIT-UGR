#include <iostream>
using namespace std;
int main () {
cout.precision(9999999);

//a) 
int chico, chico1, chico2;
chico1 = 123456789;
chico2 = 123456780;
chico = chico1 * chico2;
cout<< "a) "<< chico <<"\n\n";
//b) 
long grande;
int chico3, chico4;
chico1 = 123456789;
chico2 = 123456780;
grande = chico3 * chico4;
cout <<"b) " <<grande <<"\n\n";
//c)
 double resultado, real1, real2;
real1 = 123.1;
real2 = 124.2;
resultado = real1 * real2;
cout << "c) "<<resultado << "\n\n";
//d)
 double resultado2, real3, real4;
real1 = 123456789.1;
real2 = 123456789.2;
resultado = real3 * real4;
cout << "d) "<< resultado <<"\n\n";
//e)
 double real5, otro_real, real;
real = 2e34;
otro_real = real5 + 1;
otro_real = otro_real - real5;
cout << "e) "<<otro_real << "\n\n";
//f ) 
double real6, otro_real2;
real6 = 1e+300;
otro_real2 = 1e+200;
otro_real2= otro_real2 * real6;
cout <<"f) "<< otro_real2 <<"\n\n";

return 0;
}
