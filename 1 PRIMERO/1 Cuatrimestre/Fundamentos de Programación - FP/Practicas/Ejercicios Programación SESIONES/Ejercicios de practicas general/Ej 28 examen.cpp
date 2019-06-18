#include <iostream>
using namespace std;
int main (){
	
int num1,num2;
char operacion;

	cout<<"Introduce dos numeros enteros separados por espacio: "<<endl;
	cin>>num1,num2;

cout<<"I. Introducir numeros"<<endl;
cout<<"S. Suma"<<endl;
cout<<"P. Producto"<<endl;
cout<<"M. Maximo"<<endl;
cout<<"R. Salir"<<endl;
cin>>operacion;

while(operacion != 'I' && 'S' && 'P'&& 'M' ){
cout<<"Dentro de las instrucciones: "<<endl;
cin>> operacion;
}

while(operacion != 'R'){

	

	if(operacion='S'){
		cout<<"La suma es: "<<num1+num2<<endl;
	}
	if(operacion='P'){
	cout<<"El producto es: "<<num1*num2<<endl;
	}
	if(operacion='M'){
		if(num1>num2){
		cout<< num1<<" Es mayor que "<<num2<<endl;
		}
		else if(num1<num2){
		cout<<num1<<"Es menor que "<<num2<<endl;
		}else{
			cout<<"Son iguales"<<endl;
		}
	}
}

system("pause");
return 0;
}
