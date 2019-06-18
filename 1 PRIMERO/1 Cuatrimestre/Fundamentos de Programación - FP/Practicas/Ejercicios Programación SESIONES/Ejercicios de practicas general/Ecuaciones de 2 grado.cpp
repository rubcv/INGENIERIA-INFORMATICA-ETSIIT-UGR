// Calcular ecuacion de segundo grado


#include <iostream>
#include <cmath>
using namespace std;

double Adistintode0(double a){
	while(a==0){
	cout<<"La ecuacion no es de segundo grado meapilas: ";
	cin>>a;
	}
return 0;
}

double Solucionessiexiste(double a,double b,double c){
 double x1=0;
 double b2=b*b;
 double ac4=a*c*4;
 
	if(b2>ac4){
		x1=(sqrt(b*b-4*a*c)-b)/(2*a);
		
	}else{
		cout<<"No tiene solucion "<<endl;
	}
return x1;
}

double Segundasolucion(double a, double b, double c){
	double x2=0;
	
	if(b*b>4*a*c){
		x2=(-b-sqrt(b*b-4*a*c))/(2*a);
	
	}else{
		cout<<"No tiene solucion "<<endl;
	}
return x2;
}


int main (){


double a,b,c,x1,x2;


cout<<"Este programa calcula ecuaciones de segundo grado \n"
"de la forma ax^2+bx+c: "<<endl<<endl;
cout<<"Introduce a: ";
cin>>a;
a=Adistintode0(a);

cout<<endl;
cout<<"Introduce b: ";
cin>>b;
cout<<endl;
cout<<"Introduce c: ";
cin>>c;
cout<<endl<<endl;

x1=Solucionessiexiste(a,b,c);
	cout<<"Primera solucion: "<<x1<<endl;
	
x2=Segundasolucion(a,b,c);	
	cout<<"Segunda solucion: "<<x2<<endl;

system("pause");

}
