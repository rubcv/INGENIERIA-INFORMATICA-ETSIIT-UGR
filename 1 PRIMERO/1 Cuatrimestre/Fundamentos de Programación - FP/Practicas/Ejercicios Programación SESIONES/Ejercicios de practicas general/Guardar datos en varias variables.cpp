#include <iostream>
using namespace std;

int ValorMayor(int a, int b){
	int mayor;
	if (a>b){
	mayor=a;
	}
	if (b<a){
	mayor=b;
	}
return mayor;
}

int main (){

	int contador=-1,dorsales=0,dorsal,mayor;
	
	cout<<"Introduce dorsales: (0 para salir): "<<endl;
		
		do{
			cin>>dorsal;
			dorsales+=dorsal;
			contador++;
			
		}while (dorsal!=0);
		cout<<"Suma dorsales: "<<dorsales<<endl;
		cout<<"Dorsales: "<<contador<<endl;
	int media=dorsales/contador;		
			cout<<"Media: "<<media;
	mayor=ValorMayor(dorsales,dorsales);
	
	cout<<"El valor mayor es: "<<mayor;

system("pause");
return 0;
}
