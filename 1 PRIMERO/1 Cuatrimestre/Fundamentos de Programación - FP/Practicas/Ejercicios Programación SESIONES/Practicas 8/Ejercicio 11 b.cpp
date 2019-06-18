#include <iostream>
using namespace std;
int main () {

int num,rad,suma=1,t,num2;
double mod; 

cout<<"Introduce un numero para ver si tiene numeros amigos: "<<endl;
cin>>num;
cout<<"Introduce un radio para ver si cerca del numero anterior hay numeros amigos: "<<endl;
cin>>rad;

for(t=num;t<=rad;t++){
	t=num2;
	for(int i=2;i<num2;i++){
		mod=num2%i;
		if(mod==0){	
			suma=suma+i;
		}
	}
	
}

if (suma==t){
			cout<<t<<"Es un numero amigo de "<<num<<endl;
		}else{
			cout<<"No hay numeros amigos en el radio "<<rad<<endl;
		}
system("pause");
return 0;
}
