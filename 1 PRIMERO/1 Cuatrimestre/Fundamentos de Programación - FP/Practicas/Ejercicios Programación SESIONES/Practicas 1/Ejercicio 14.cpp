#include <iostream>
using namespace std;

int main()
{
	int num1;  
	
	cout << "Escriba un numero entero: ";
	cin >> num1;
	
	cout << "\n " << num1 % 1000 / 100 << "   " << num1 % 100 / 10 << "   "
		 << num1 % 10 << endl;
	
	system ("pause");
	return 0; 
	
} 
