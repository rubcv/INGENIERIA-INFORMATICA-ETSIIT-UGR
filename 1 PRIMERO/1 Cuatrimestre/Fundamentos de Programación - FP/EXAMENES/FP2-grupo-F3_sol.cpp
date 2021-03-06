/***************************************************************************/

// FUNDAMENTOS DE PROGRAMACI�N
// GRADO EN INGENIER�A INFORM�TICA
//
// CURSO 2015-2016
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACI�N E INTELIGENCIA ARTIFICIAL
//
// EXAMEN PR�CTICO - ENERO 2016
// soluci�n al problema : conjunto
//
/***************************************************************************/

// Trata de leer una secuencia de enteros y crear un m�todo Simplifica()
// para que dado una secuencia lo convierta en un conjunto
// Se ha de hacer de forma eficiente
// Se pide el m�todo Buscar()

#include <iostream>

// EXAMEN: conjunto

using namespace std;

// class SecuenciaEnteros
// Datos miembro:
// 	CAPACIDAD: tama�o m�ximo que puede tener el conjunto
// 	conjunto: vector que alberga los elementos del conjunto
// 	utilizados: cantidad de elementos del conjunto en un momento dado
class SecuenciaEnteros{
	
	static const int CAPACIDAD = 100;
	int conjunto[CAPACIDAD];
	int utilizados;
	static const int NO_PRESENTE = -1;

	public:
		// Constructor sin parametros
		// Inicializa utilizados a 0
		SecuenciaEnteros(){
			utilizados = 0;
		}
		
		// Devuelve la cantidad de elementos del conjunto
		int TotalUtilizados(){
			return utilizados;
		}
		

		// Devuelve el tama�o m�ximo que puede tener el conjunto
		int Capacidad(){
			return CAPACIDAD;
		}	

		// Devuelve el elemento existente en la posici�n especificada,
		// habr�a que comprobar rangos v�lidos y lanzar una excepci�n...
		int Elemento( int posicion ){
			
			return conjunto[posicion];
			
		}
		
		// A�ade un elemento nuevo al final del conjunto, si cabe 
		// y NO ESTA ya presente, es la forma de controlar que 
		// SecuenciaEnteros se comporta como un conjunto
		void Aniade( int nuevo ){
			
			if ( utilizados < CAPACIDAD ){
				conjunto[utilizados] = nuevo;
				utilizados++;
			}
		}
	
		
		// Comprueba la presencia de un elemento en el conjunto.
		// Devuelve -1 de no estar presente, y, en caso contrario,
		// el n�mero correspondiente a la posici�n donde se encuentra
		int Buscar( int numero ){
			
			int posicion = NO_PRESENTE;
			int i;
			
			for ( i = 0; i < utilizados && conjunto[i] != numero; i++ ); // solo avanza
			
			if ( i < utilizados )
				posicion = i;
			
			return posicion;
		}
		
		// Calcula y devuelve el conjunto diferencia del objeto 
		// invocado atrav�s del m�todo menos sustraendo
		SecuenciaEnteros Simplifica(){
			
			SecuenciaEnteros local;
			int i;
			
			for ( i = 0; i < utilizados; i++ ){
				
				if ( local.Buscar(conjunto[i]) == NO_PRESENTE )
					local.Aniade(conjunto[i]);  // se busca entre los ya metidos en local (vector <= size)
			}		// o bien se hac un nuevo m�todo para que busque de 0 a la posicion i, no despu�s
			
			return local;
		}
		
};// Hasta aqu�, la definici�n de la clase.
// OJO: No hay ni cin, ni cout dentro de la clase
//se pod�a definir un m�todo SecuenciaToString que devuelva
// una cadena

/*---------------- Parte realizada por un programador que utiliza la clase */

// Funcion que recibe una secuencia y muestra su contenido en la
// forma deseada por el programador
void Mostrar (SecuenciaEnteros elconjunto){
  
     cout << "{ "; 
     for(int i=0; i < elconjunto.TotalUtilizados(); i++){
        cout << elconjunto.Elemento(i);
	if (i < elconjunto.TotalUtilizados() -1)
	    cout << ", ";
     }
     cout << " }"; 
     cout << endl;
       
}

SecuenciaEnteros  CargarSecuencia (string textoInicial, int sentinela){
  
        int nuevo;
	SecuenciaEnteros local;
  	// Introducci�n de los elementos del primer conjunto
	cout << endl<< textoInicial << sentinela << " para terminar): ";
	cin >> nuevo;
	
	while ( nuevo != sentinela ){
		
		local.Aniade(nuevo);
		cout << sentinela << " para terminar): ";
		cin >> nuevo;
	}
        return local;
       
}

int main(){
		
       const int TERMINADOR = 0; // constante utilizada en este programa

	SecuenciaEnteros original = CargarSecuencia ("Componentes del primer conjunto ", TERMINADOR); 	
	SecuenciaEnteros simplificada (original.Simplifica()); // uso del constructor por copia
	
	cout << "Secuencia original : ";
	Mostrar(primera);
	cout << "Conjunto resultante: " ;
	Mostrar( simplificada);

}

 
