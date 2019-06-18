#include <iostream>
using namespace std;
int main () {
int num1, num2, num3;
cout<<"Introduzca un numero: ";
cin>> num1;
cout<<"\nIntroduzca un numero: ";
cin>> num2;
cout<< "\nIntroduzca un numero: ";
cin>> num3;


if (num1<num2<num3) {
	cout<< "Estan ordenados de forma ascendente" <<endl;
}else if  (num1>num2>num3)
	{
	
	cout<< "Estan ordenados de forma descendente"<<endl;
} else {
cout<< "No estan ordenados"<<endl;

}
system ("pause");
return 0;
}
