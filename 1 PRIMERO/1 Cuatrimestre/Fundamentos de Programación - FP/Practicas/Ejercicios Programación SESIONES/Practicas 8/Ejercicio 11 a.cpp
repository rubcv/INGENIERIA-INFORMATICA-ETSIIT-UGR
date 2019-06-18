 #include <iostream>
using namespace std;
int main () {


int x,y,suma=1,suma2=1,mod,mod2;

cout<<"Este programa calcula si dos numeros son amigos. "<<endl;

cout<<endl<< "Introduce un numero: ";
cin>>x;

cout<<endl<<"Introduce otro numero: ";
cin>>y;


for(int i=2;i<y;i++){
	mod=y%i;
	if(mod==0){	
		suma=suma+i;
	}
}


for (int j=2;j<x;j++){
	mod2=x%j;
	if(mod2==0){
		suma2=suma2+j;				
	}	
}

if(suma==x && suma2==y){
	cout<<endl<<x<< " Es un numero amigo de "<<y<<endl;
}else{
	cout<<x<<" No es un numero amigo de "<<y<<endl;
}	

								
								
system ("pause");
return 0;

}
