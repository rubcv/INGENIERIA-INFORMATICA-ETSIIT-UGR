

// En construcción



/*

C-----D
|		|
|		|
A-----B

*/



#include <iostream>
#include <cmath>
using namespace std;

static const double PI = 3.1416;


class Punto2D{
	private:
		double abscisa;
		double ordenada;
	public:
		//......
		
	double getX (){
		return abscisa;
	}
	
	double getY(){
		return ordenada;
	}
};

class SegmentoDirigido{
	private:
		double x_1, y_1, x_2, y_2;
	
	public:
		//......
		
		double Longitud(){
			double modulo = sqrt((x_2-x_1)*(x_2-x_1)+(y_2-y_1)*(y_2-y_1));
		
		return modulo;
		}
		
};

class Circunferencia{
	private:
		double centro_x;
		double centro_y;
		double radio;
	public:
		//......
		
		
};

class Cuadrado{
	private:
		double esquina_abscisa;
		double esquina_ordenada;
		double longitud;
		
		
	public:
		//......
		
		double Area(){
			return longitud*longitud;
		}
		
		double Perimetro(){
				return longitud*4;
		}
		
		Punto2D Centro (){
			double abscisa = esquina_abscisa+longitud/2;
			double ordenada = esquina_ordenada+longitud/2;

				Punto2D centro(abscisa,ordenada);
				
				return centro;
		}

	

		Circunferencia CircunferenciaInscrita(){
				radio= esquina_abscisa + esquina_ordenada/2;
			
				
				
				
				Circunferencia inscrita(x,y,radio);
				
				return inscrita;
		
			
		
		}

		Circunferencia CircunferenciaCircunscrita(){
				
				radio=sqrt((longitud/2)*(longitud/2)+(longitud/2)*(longitud/2))
				
			Circunferencia circunscrita(x,y,radio)
		
		}
		
		
		
};


int main(){


Cuadrado cuadrado1;
Cuadrado cuadrado2;



if(cuadrado1.Area() > cuadrado2.Area())
	cout<<"El cuadrado 1 tiene mayor area"<<endl;
else
	cout<<"El cuadrado 2 tiene mayor area"<<endl;








return 0;
}
