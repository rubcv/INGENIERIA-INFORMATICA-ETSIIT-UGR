/*  Escribir todas las posibles parejas (i,j) */

//					BUCLES ANIDADOS	

#include <iostream>
using namespace std;
int main () {
	
	int i,j;
	
	for (i=1;i<=5;i++)
		for (j=1;j<=5;j++)
			cout<<i<<","<<j<<endl;
	
	cout<< "\n\nParte 2\n"<<endl;
	
	// Bucle anterior( for de dentro depende del de fuera
	//					(i,j)	 pero j>=i
	
	for (i=1;i<=5;i++)
		for (j=i;j<=5;j++)
			cout<< i <<','<<j<<endl;
						
						
						
						
	
	system ("pause");
	return 0;
}
	
