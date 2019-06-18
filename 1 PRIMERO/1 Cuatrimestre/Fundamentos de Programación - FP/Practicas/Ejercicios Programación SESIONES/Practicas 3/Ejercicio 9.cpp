#include <iostream>
using namespace std;
int main () {
	double ventas, preciof,ventadesc;
cout<<"Introduzca cantidad vendida: ";
cin>> ventas;
if (ventas >=100){
	preciof = ventas-(ventas*0.03);
	cout<< "\nPrecio final: "<< preciof;
}
if (preciof>= 700){
 ventadesc=preciof-(preciof*0.02);
cout<< "\nPrecio final tras el segundo descuento: "<< ventadesc;
}else{
	cout<<"\nPrecio final tras el segundo descuento: "<<preciof;
}


return 0;
}	
