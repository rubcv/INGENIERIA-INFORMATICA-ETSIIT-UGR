#include<iostream>
using namespace std;
int main (){

int num,min,max,aparicion=0,aparicion2=0,aparicion3=0,num2,num3,num4,div,mod,total,m1,m2,m;

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


for (int i=m;i<=max;i++){
		i=num2;
			if(num2=num){
				aparicion=aparicion+1;
			}	
}
min=m1;
for(int j=m1;j<=max;j++){
			j=num3;
			div=num3/10;
				if(div=num){
					aparicion2=aparicion2+1;
				}	
}
min=m2;
for(int k=m2;k<=max;k++){
		k=num4;
		mod=num4%10;
			if(mod=num){
				aparicion3=aparicion3+1;
			}
}

total=aparicion+aparicion2+aparicion3;
cout<<"El total de veces que aparece "<<num<< " es "<<total<<endl;









system ("pause");
return 0;
}
