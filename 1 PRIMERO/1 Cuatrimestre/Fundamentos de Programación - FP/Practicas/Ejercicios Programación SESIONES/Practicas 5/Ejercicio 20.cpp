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

while (n>=0);
{
total=capital+capital*interes/100;

cout<<"El total es: " <<total<<endl;
n++;
}
if (capital=capital*2){
	cout<<"En "<<n<<" anhos se doblara el capital";

}
system ("pause");
return 0;
} 
