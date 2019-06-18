#include <iostream>
using namespace std;
int main () {
int x,y,z,a;
cout<< "introduca el valor x ";
cin>> x;
cout<< "introduzca el valor y ";
cin>> y;
cout<< "introduzca el valor z ";
cin>> z;
a=z;
z=y;
y=x;
x=a;
cout<< " x = "<< x << " y = "<< y << " z = "<< z ; 
return 0;
}
