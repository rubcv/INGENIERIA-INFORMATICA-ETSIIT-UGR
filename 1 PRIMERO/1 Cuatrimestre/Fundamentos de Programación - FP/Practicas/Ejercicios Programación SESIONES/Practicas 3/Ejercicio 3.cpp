#include <iostream>

using namespace std;
int main () {
int edad;
double salario, salariof;
cout<<"Introduzca una edad: ";
cin>>edad;
cout<<"\nIntroduzca un salario: ";
cin>>salario;

if (edad>= 65) {
salariof=(salario*0.05)+salario;
cout<<"\n\nEl sueldo es: "<<salariof;
}else{
cout<<"\n\nNo es aplicable la suma.";	
}

return 0;
}
