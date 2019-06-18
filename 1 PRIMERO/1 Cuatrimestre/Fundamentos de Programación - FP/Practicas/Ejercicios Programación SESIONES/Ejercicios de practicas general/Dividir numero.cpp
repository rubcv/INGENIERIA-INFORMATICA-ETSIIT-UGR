#include <iostream>
#include <cmath>
using namespace std;

int main (){
	int numero,digito,cifras=0,cifra,digito2;
	
	cout<<"Introduce un numero: ";
	cin>>numero;
	
	while(numero>0){
		digito=numero%10;
		numero=numero/10;
	//	cifras+=1;
	
		cout<<digito;
		
	
		
		
	}
		int variable=digito;
	while(variable>0){
			digito2=variable%10;
			variable=variable/10;
			
			cout<<digito2;
		}
	cout<<endl;

		
		//cout<<endl<<cifras<<endl;

system("pause");
return 0;
}
