#include <iostream>
using namespace std;

class Nomina(int horas, int sueldo){

	private:
		double horas,sueldo;

	public:
		double	porcentaje_extra,horas_fijas;





}

int main () {
	
	double sueldo,sueldof,sueldoff,horas;

cout<<"Este programa calcula el salario de un trabajador: "<<endl<<endl;

cout<<"Introduce la cantidad de horas trabajadas: "<<endl;
cin>>horas;
cout<<"Introduce el sueldo por horas: "<<endl;
cin>>sueldo;


if (horas>=40)
{
	
sueldof=sueldo+(sueldo*0.5);
sueldoff=sueldof*horas;


cout<<"Al ser mas de 40 horas, el salario se incrementa un 50% "<<endl;
cout<<" Salario final: "<<sueldoff<<" euros "<<endl;


}else{

sueldof=sueldo*horas;
cout<<"El sueldo final es: "<<sueldof<<" euros "<<endl; 

}

system ("pause");
return 0;

}
