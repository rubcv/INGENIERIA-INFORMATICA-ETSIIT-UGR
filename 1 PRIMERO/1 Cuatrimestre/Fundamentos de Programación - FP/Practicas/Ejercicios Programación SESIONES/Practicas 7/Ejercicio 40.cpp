#include <iostream>
using namespace std;
int main (){
double capital,operacion;
double anhos, interes;
double total;

cout<<"Introduce el valor del capital: "<<endl;
cin>>capital;
cout<<"Introduce el valor del interes: "<<endl;
cin>>interes;
cout<<"Introduce el numero de anhos: "<<endl;
cin>>anhos;



for (double i=1;interes>=i;i++){
		
	cout<<"Calculos realizados al "<<i<<"%"<<endl<<endl;
	for(double incremento=1;incremento<=anhos;incremento++){
		operacion=(incremento*(i/100));
		total=capital+capital*operacion;
	
		cout<<"Total en el anho numero "<<incremento<<"="<<total<<endl;
		
		
	}
	cout<<endl<<endl;
}



system ("pause");
return 0;
}
