#include <iostream>
#include <cmath>
using namespace std;

int LeeEnteroPositivo(int x, int n, int potencia){

potencia=pow(x,n);


return potencia;
}

int main(){
	int x,n,potencia;
	do{

cout<<"Escribe la base: ";
cin>>x;
cout<<"Escribe el exponente: ";
cin>>n;

potencia=pow(x,n);
potencia=LeeEnteroPositivo(x,n,potencia);



}while(0>=x && 0>=n);
cout<<"\n\n"<< x <<" elevado a "<<n<<" es "<<potencia<<endl;

system ("pause");



}








