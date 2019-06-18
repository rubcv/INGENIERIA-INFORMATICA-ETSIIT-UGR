/* En este ejercicio, no hay que construir ninguna clase ni función. Es un ejercicio sobre
recorridos de una matriz declarada directamente en el main.
Leed desde teclado dos variables util_filas y util_columnas y leed los datos
de una matriz de enteros de tamaño util_filas x util_columnas. Sobre dicha
matriz, se pide lo siguiente:
a) Calcular la traspuesta de la matriz, almacenando el resultado en otra matriz.
d) Leer los datos de otra matriz y multiplicar ambas matrices (las dimensiones de la
segunda matriz han de ser compatibles con las de la primera para poder hacer la
multiplicación)
*/



#include	<iostream>
using namespace std;
int main(){
	
	int util_filas,util_columnas,i=0,j=0;
	
	cout<<"Introduce el numero de filas: ";
	cin>>util_filas;
	cout<<"\nIntroduce el numero de columnas: ";
	cin>>util_columnas;
	cout<<endl<<endl;
int matriz[util_filas][util_columnas];

for(int f=0;f<util_filas;f++){ /* Inicializar matriz */
	for(int c=0;c<util_columnas; c++){
		matriz[f][c]=0;
	}
}
	
for (i=0; i<util_filas;i++){
	for( j=0; j<util_columnas;j++){
		cout<<"Introduce el valor: "<<i+1<<","<<j+1<<" de la matriz"<<endl;
		cin>>matriz[i][j];
	
	
	}
	cout<<endl;
	
}


int traspuesta[i][j];



cout<<"Matriz traspuesta: "<<endl;

	for (int i=0; i<util_filas; i++){
		for (int j=0; j<util_columnas; j++){
			
			if(util_filas == 1)
			{
				traspuesta[i][j]=matriz[0][j];
					cout<<traspuesta[i][j]; // Traspuesta guardada en otra matriz
			}
			else
			{
				traspuesta[i][j]=matriz[j][i];
				cout<<traspuesta[i][j]; // Traspuesta guardada en otra matriz
			}
		
		}
		cout<<endl; // Cuando completa una fila añade un salto de linea  
	}



/* _____ Multiplicacion de matrices ________ */


cout<<"Introduzca los valores de la matriz"<<endl;
	for(int i = 0; i < utilfilas_otra; i++){
		for(int j = 0; j < utilcolumnas_res; j++){
			resultado[i][j]=0;
			for(int h = 0; h < utilcolumnas; h++){ 
				resultado[i][j] += matriz [i][h] * otra[h][j]; 
			} 
		}
	}
 



system("pause");
return 0;
}
