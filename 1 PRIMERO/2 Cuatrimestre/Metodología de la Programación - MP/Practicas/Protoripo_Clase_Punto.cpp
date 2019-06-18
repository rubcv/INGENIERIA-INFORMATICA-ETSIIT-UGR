#include <iostream>
using namespace std;

class Punto{
	private:
		int x, y;
	public:
		int getX(){
			return x;
		}

		int setX(int nuevox){
			x = nuevox;
		}

		//CONSTRUCTORES

		//CONSTRUCTOR POR DEFECTO
	Punto(){
		x = 0;
		y = 0;
	}
	
		//CONSTRUCTOR DE COPIA
	Punto(Punto original){
		x = original.x;
		y = original.y;
	}
	
	
	//CONSTRUCTOR POR PARAMETROS
	
	Punto( int x_alguna, int y_alguna){
		(this->)x = x_alguna;
		(this->)y = y_alguna;
	}
	
	
};


int main{

	Punto p1; // Se llama automaticamente al constructor por defecto
	
	Punto p2(p1); //Se llama al constructor de copia, p1 se copia en p2
	
	Punto p3(5,7); //Se llama al constructor por parámetros y se asignan los valores


}
