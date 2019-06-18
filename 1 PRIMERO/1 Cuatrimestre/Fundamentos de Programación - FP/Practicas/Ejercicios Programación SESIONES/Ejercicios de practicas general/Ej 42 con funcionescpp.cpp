#include<iostream>
using namespace std;
int main (){

int num,min,max,aparicion=0,div,mod,aparicion2=0;

cout<<"Este programa calcula cuantas veces aparece el numero en un intervalo. "<<endl<<endl;

cout<<"Introduce el numero entre 0 y 9: "<<endl;
cin>>num;
while(num<0 || num>9){
cout<<"Debe estar entre 0 y 9: "<<endl;
cin>>num;
}

cout<<"Valor inicial del intervalo: "<<endl;
cin>>min;
cout<<"Valor maximo del intervalo: "<<endl;
cin>>max;

while(max<min){
cout<<"El valor maximo es menor que minimo, introduce otro valor: "<<endl;
cin>>max;
}


for(int i=min;i<=max;i++){
	do{div=i/10;
	}
	while(div>0);
		if(div==num){
			aparicion=aparicion+1;
		}
	
	do{mod=i%10;
	}
	while(mod>0);
		if(mod==num){
			aparicion2=aparicion2+1;
		}
}

cout<<"El total de veces que aparece "<<num<< " es "<<aparicion+aparicion2<<endl;









system ("pause");
return 0;
}
