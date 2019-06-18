#include <iostream>
using namespace std;
int main () {

float total,capital,interes,n;

cout<<"Introduce un capital: "<<endl;
cin>>capital;

cout<<"Introduce un interes: "<<endl;
cin>>interes;

cout<<"Introduce numero de anhos: "<<endl;
cin>>n;

do
{
total=capital+capital*interes/100;

cout<<"El total es: " <<total<<endl;
n--;
}
while (n!=0);

system ("pause");
return 0;
}
