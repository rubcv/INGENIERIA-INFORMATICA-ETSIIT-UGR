#include <iostream>
using namespace std;

void NumerodeVeces(long long numero){
	
	int digito;
	int contador =0, contadorf=0;
	long long temp;
	
	for (int i=0; i<=9;i++){
		temp = numero;
		contadorf=0;
		while(temp>0){
			digito=temp%10;
			temp=temp/10;	
			if(i==digito)
				contadorf=contadorf+1;
		}
		if (contadorf>0)
			cout<<"El numero "<<i<<" aparece "<<contadorf<<" veces "<<endl;
	}
}

int VecesRepetida(long long numero,int digito, int aux ){
		int mayor;
		while(numero>0){
			digito=numero%10;
			numero=numero/10;
			
			aux=digito;
		
		}
			if(digito>aux){
				mayor=digito;
			}else{
				mayor=aux;
			}
return mayor;
}
		
int main (){
	long long numero;

	cout<<"Introduce un numero positivo de cualquier longitud: "<<endl;
	cin>>numero;
		while(numero<0){
			cout<<"El numero debe ser positivo: "<<endl;
			cin>>numero;
		}

	NumerodeVeces(numero);
	//mayor=VecesRepetida(numero,digito,aux);
		
	//cout<<endl<<"La cifra mas repetida de forma consecutiva es: "<<mayor<<endl<<endl;
			
system ("pause");
}
