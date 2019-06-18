#include <iostream>
using namespace std;
int main (){
float capital,interes,operacion,capital_mod;
cout<<"Introduce el valor del capital: "<<endl;
cin>>capital;
cout<<"Introduce el valor del interes: "<<endl;
cin>>interes;

int anhos,incremento=1,total;
cout<<"Introduce el numero de anhos: "<<endl;
cin>>anhos;
capital_mod=capital;

while(anhos>=incremento){
	operacion=(capital*(interes/100));
	total=capital_mod+operacion;
	
	cout<<"Total en el anho numero "<<incremento<<"="<<total<<endl;
	incremento=incremento+1;
	capital_mod=total;
}




system ("pause");
return 0;
}
