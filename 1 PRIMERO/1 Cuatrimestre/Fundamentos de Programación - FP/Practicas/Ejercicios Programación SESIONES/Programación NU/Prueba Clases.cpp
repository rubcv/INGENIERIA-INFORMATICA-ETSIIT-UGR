#include <iostream>
using namespace std;

class Caballo {
	public:
		int ObtenerEdad();
		void ConfigurarEdad(int edad);
		void Relinchar();
		
	private:
		int suEdad;
};


int Caballo::ObtenerEdad(){
	return suEdad;
}


void Caballo::ConfigurarEdad(int edad){
	suEdad=edad;
	}
	
	
void Caballo::Relinchar(){
	cout<<"Relincha"<<endl;
}

//___________________________________________________________


int main(){

	Caballo Janto;
	Janto.ConfigurarEdad(5);
	Janto.Relinchar();
	cout<<"Tiene: "<< Janto.ObtenerEdad() << " años "<<endl;
	Janto.Relinchar();
system("pause");	
return 0;
} 
