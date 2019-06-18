#include <iostream>
using namespace std;
int main (){

double renta_bruta,renta_neta,retencion_final,retencion_inicial;
string estado_civil;
bool autonomo,pensionista;
const double baja_autonomos =3,sube_pensionistas =1, demas_trabajadores =2;


cout<< "Es un autonomo o no (0 o 1): "<<endl;
cin>>autonomo;
cout<< "Es pensionista o no (0 o 1): "<<endl;
cin>>pensionista;
cout<<"Introduce el estado civil de la persona: "<<endl;
cin>> estado_civil;
cout<<"Introduce el total de ingresos obtenidos (renta bruta): "<<endl;
cin>>renta_bruta;
cout<<"Introduce la retencion inicial a aplicar (entre 0 y 100): "<<endl;
cin>>retencion_inicial;


if (autonomo)
{
retencion_final = retencion_inicial - baja_autonomos;


}else{
	if(pensionista){
	retencion_final = retencion_inicial + sube_pensionistas;
	}else{
		
		retencion_inicial = retencion_inicial + demas_trabajadores;
		
		if (renta_bruta< 20000){
			
			retencion_final = retencion_inicial + 2;
		}else{
			if (estado_civil=="casado"  && renta_bruta> 20000)
			{
				retencion_final = retencion_inicial + 2.5;
			}else{
				if(estado_civil=="soltero" && renta_bruta> 20000)
						retencion_final = retencion_inicial +3;
					}
			}
		}
	}
	
	renta_neta = renta_bruta - renta_bruta*(retencion_final/100);
	
	
	cout<< "La renta neta final es: "<< renta_neta<< endl;
				


system ("pause");
return 0;
}
