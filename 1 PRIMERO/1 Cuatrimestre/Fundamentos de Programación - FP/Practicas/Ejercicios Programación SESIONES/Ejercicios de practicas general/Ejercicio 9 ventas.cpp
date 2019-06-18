#include <iostream>
using namespace std;
int main(){

	double ventas,precio;
	cout<<"Introduce cantidad de ventas: ";
	cin>>ventas;
	cout<<endl;
		if (ventas>100){
		ventas=ventas*0.7;
		}
	cout<<"Precio de ventas: ";
	cin>>precio;
	cout<<endl;
	
	precio=precio*ventas;
		if(precio>700 && ventas>100){
		precio=precio*0.8;
		}

cout<<"Ventas final: "<<ventas<<endl;
cout<<"Precio final: "<<precio<<endl;

system("pause");
return 0;
}
