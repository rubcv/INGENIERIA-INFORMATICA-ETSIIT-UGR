/*  Se está diseñando un sistema web que recolecta datos
personales de un usuario y, en un momento dado, debe sugerirle un nombre de
usuario (login). Dicho login estará basado en el nombre y los apellidos; en concreto estará formado por los N primeros caracteres de cada nombre y apellido
(en minúsculas, unidos y sin espacios en blanco). Por ejemplo, si el nombre es
"Antonio Francisco Molina Ortega" y N=2, el nombre de usuario sugerido
será "anfrmoor".
Debe tener en cuenta que el número de palabras que forman el nombre y los apellidos puede ser cualquiera. Además, si N es mayor que alguna de las palabras que
aparecen en el nombre, se incluirá la palabra completa. Por ejemplo, si el nombre es "Ana CAMPOS de la Blanca" y N=4, entonces la sugerencia será
Guión de Prácticas. Fundamentos de Programación RP-IV.11
RELACIÓN DE PROBLEMAS IV. Vectores
"anacampdelabl an" (observe que se pueden utilizar varios espacios en blanco
para separar palabras).
Implemente la clase Login que tendrá como único dato miembro el tamaño N. Hay
que definir el método Codifica que recibirá una cadena de caracteres (tipo string)
formada por el nombre y apellidos (separados por uno o más espacios en blanco) y
devuelva otra cadena con la sugerencia de login.
class Login{
private:
int num_caracteres_a_coger;
public:
Login (int numero_caracteres_a_coger)
:num_caracteres_a_coger(numero_caracteres_a_coger)
{ }
string Codifica(string nombre_completo){
......
}
};
Los únicos métodos que necesita usar de la clase string son size y push_back.
Para probar el programa lea los caracteres de la cadena uno a uno con cin.get() ,
hasta que el usuario introduzca el carácter # */




#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Login{
	private:
		int precision;
	public:
		
		Login(int numero_caracteres_a_coger){
			precision = numero_caracteres_a_coger;
		};
		
		string Codifica( vector<string> nombre_completo)
		{
		
			string resultado;
	
			//Imprimimos los N caracteres de cada palabra
			for(int i = 0; i < nombre_completo.size(); i++)
			{
				for( int j = 0; j < precision+1; j++)
				{
					if( j != 0 && nombre_completo[i][j] != '#')
					resultado += nombre_completo[i][j]; //Concatenamos los caracteres
				}
			}
			
			return resultado;
			
		}


};

int main(){
	int precision;
	string nombre;
	vector<string> nombre_aux;
	int contador_espacios = 0;
	char caracter_leido = 0;
	
	cout<<"Este programa recolecta datos de usuario"<<endl<<endl;
	cout<<"Escriba la precision para guardar los nombres:"<<endl;
	cin>>precision;
	
	cout << "Introduzca nombre y apellidos " << endl;

	nombre_aux.push_back(" ");
	nombre_aux[0].pop_back();
	
	while(caracter_leido != '#')
	{
		
	 	caracter_leido = cin.get();
	 	
	 	if(caracter_leido == ' ')
	 	{
	 		contador_espacios++;
	 		nombre_aux.push_back(" ");
	 		nombre_aux[contador_espacios].pop_back();
	 	}
	 	
		nombre_aux[contador_espacios].push_back(caracter_leido);
		
	}
	
	Login l(precision);

	cout << "El nombre sugerido es: " ;
  cout <<l.Codifica(nombre_aux) << endl;
	





system("pause");
return 0;
}
