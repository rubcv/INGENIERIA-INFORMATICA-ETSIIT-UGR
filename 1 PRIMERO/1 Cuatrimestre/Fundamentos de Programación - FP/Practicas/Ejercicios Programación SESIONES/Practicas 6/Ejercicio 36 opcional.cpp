#include <iostream>
#include <cmath>
using namespace std;
int main () {



double a1,r,k,potencia,siguiente;

cout<<"Este programa realiza la serie numerica ai=a1*r^i-1";
cout<<"\nIntroduce r ";
cin>> r;
cout<<"\nIntroduce el primer elemento a1 ";
cin>>a1;
cout<<"\nIntroduce el valor maximo de ai (k) ";
cin>> k;

do{
		for (int a1=1;a1<=k;a1++)
			{

			potencia=a1*pow(r,potencia-1);

			siguiente=a1*potencia;

			cout<<"\nLa serie numerica es: "<<siguiente<<endl<<endl;
		}
} 
while(siguiente<=k);


system ("pause");
return 0;
}
