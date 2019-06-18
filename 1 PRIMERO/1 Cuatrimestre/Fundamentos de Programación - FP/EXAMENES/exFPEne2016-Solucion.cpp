/***************************************************************************/
// FUNDAMENTOS DE PROGRAMACIÓN
// GRADO EN INGENIERÍA INFORMÁTICA
// GRUPO F-1
//
// CURSO 2015-2016
// DEPARTAMENTO DE CIENCIAS DE LA COMPUTACIÓN E INTELIGENCIA ARTIFICIAL
//
// EXAMEN PRÁCTICO - ENERO 2016
//
// Solución al problema 
//
/***************************************************************************/

#include <iostream>
#include <iomanip>
using namespace std;


// NO EMPLEAR VARIABLES GLOBALES

/////////////////////////////////////////////////////////////////////////////

class SecuenciaEnteros  
{

private:

	static const int TAMANIO = 100; // Número de casillas disponibles
	int vector_privado[TAMANIO];
	
	//PRE: 0 <= total_utilizados <= TAMANIO
	int total_utilizados;	// Número de casillas ocupadas

public:
	
	/***********************************************************************/
	// Constructor sin argumentos

	SecuenciaEnteros (void) 
	{
		total_utilizados = 0;
	}

	/***********************************************************************/
	// Métodos de lectura (Get) de los datos individuales 

	// Devuelve el número de casillas ocupadas
	int TotalUtilizados (void)
	{
		return (total_utilizados);
	}

	// Devuelve el número de casillas disponibles
	int Capacidad (void)
	{
		return (TAMANIO);
	}

	/***********************************************************************/
	// Añade un elemento al vector.
	// Recibe: nuevo, el elemento que se va a añadir.
	//
	// PRE: total_utilizados < TAMANIO
	// 		La adición se realiza si hay espacio para el nuevo elemento. 
	// 		El nuevo elemento se coloca al final del vector. 
	// 		Si no hay espacio, no se hace nada.	

	void Aniade (int nuevo)
	{
		if (total_utilizados < TAMANIO) {
			vector_privado[total_utilizados] = nuevo;
			total_utilizados++;
		}
	}

	/***********************************************************************/
	// Devuelve el elemento de la casilla "indice" 
	//
	// PRE: 0 <= indice < total_utilizados 

	int Elemento (int indice)
	{
		return vector_privado[indice];
	}
	
	/***********************************************************************/
	// "Vacía" una secuencia
		
	void EliminaTodos (void) 
	{
		total_utilizados = 0;
	}
	
	/***********************************************************************/
	//Ordena una secuencia de enteros

	void OrdenarSecuencia()
	{
		int aux;
		
		for(int i = 0; i < total_utilizados;i++)
		{
			for(int j = total_utilizados-1; j > i; j--)
			{
				if(vector_privado[i] > vector_privado[j])
				{
					aux = vector_privado[i];
					vector_privado[i] = vector_privado[j];
					vector_privado[j] = aux;
				}
			}
		}
	}
	
	/***********************************************************************/
	//Devuelve un subconjunto de enteros cuya selección viene nada por el orden n-ésimo de la secuencia recibida
	// PRE: secuencia con enteros positivos mayores que 0
	
	SecuenciaEnteros ObtenerSubconjunto(SecuenciaEnteros selector)
	{
		SecuenciaEnteros copia_original;
		SecuenciaEnteros resultado;
		
		for (int i = 0; i < total_utilizados; i++) 
		{
			copia_original.Aniade(vector_privado[i]);
		} 
		
		copia_original.OrdenarSecuencia();
		
		for(int i = 0; i < selector.TotalUtilizados(); i++)
		{
			if (selector.Elemento(i) > 0 && selector.Elemento(i) <= total_utilizados)
			{
				resultado.Aniade(copia_original.Elemento(selector.Elemento(i)-1));
			}
		}
		
		return resultado;
	}
};

 /////////////////////////////////////////////////////////////////////////////
 

/*************************************************************************/

int main (void)
{
	cout.setf(ios::fixed);		// Notación de punto fijo para los reales
	cout.setf(ios::showpoint);	// Mostrar siempre decimales

	int valor1,valor2;
	SecuenciaEnteros original, selector, resultado;
	
	cout << "Introduce un entero positivo para la secuencia original (0 para terminar): ";
	cin >> valor1;
	
	while(valor1 != 0)
	{
		if(valor1 > 0)
			original.Aniade(valor1);
		else
			cout << "Valor negativo, no se ha introducido." << endl;
		cout << "Introduce un entero positivo para la secuencia original (0 para terminar): ";
		cin >> valor1;
	}
	
	cout << "Introduce un entero positivo para la secuencia selectora (0 para terminar):";
	cin >> valor2;
	
	while(valor2 != 0)
	{
		if(valor2 > 0)
			selector.Aniade(valor2);
		else
			cout << "Valor negativo, no se ha introducido." << endl;
		cout << "Introduce un entero positivo para la secuencia selectora (0 para terminar): ";
		cin >> valor2;
	}

	cout << "La secuencia original es:" << endl;	
	for(int i = 0; i < original.TotalUtilizados(); i++)
		cout << original.Elemento(i) << " ";
	cout << endl;

	cout << "La secuencia selectora es:" << endl;	
	for(int i = 0; i < selector.TotalUtilizados(); i++)
		cout << selector.Elemento(i) << " ";
	cout << endl;
	
	resultado = original.ObtenerSubconjunto(selector);

	cout << "La secuencia resultado es:" << endl;	
	for(int i = 0; i < resultado.TotalUtilizados(); i++)
		cout << resultado.Elemento(i) << " ";
	cout << endl;

	return (0);
}

 
 
