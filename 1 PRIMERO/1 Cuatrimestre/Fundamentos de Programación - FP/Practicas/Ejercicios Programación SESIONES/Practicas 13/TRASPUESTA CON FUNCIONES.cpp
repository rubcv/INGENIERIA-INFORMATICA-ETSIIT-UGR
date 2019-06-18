#include	<iostream>
#include <string>

#define ENTER '\n'
using namespace std;

void leermatriz(int m[3][3]){
	
		for (int i=0; i<=2; i++){
			for (int j=0; j<=2; j++){
				
				cout<<"Escribe el elemento "<<i<<","<<j<<" de la matriz "<<endl;
				cin>>m[i][j];
				//cout<<m[i][j]<<" ";
				
			
			
			}
		cout<<ENTER; /* Cuando completa una fila añade un salto de linea */ 
	}
	



}



void imprimirmatriz(int m[3][3]) /* Funcion que imprime la matriz */
{
	for (int i=0; i<=2; i++){
		for (int j=0; j<=2; j++){
			cout<<m[i][j]<<" ";
			
		
		
		}
	cout<<ENTER; /* Cuando completa una fila añade un salto de linea */ 
	}
	
	
}

void imprimirtraspuesta(int m[3][3]) /* Funcion que imprime la matriz traspuesta */
{
	for (int i=0; i<=2; i++){
		for (int j=0; j<=2; j++){
			cout<<m[j][i]<<" "; /* Hace traspuesta solo cambiando i por j */
			
		
		
		}
	cout<<ENTER; /* Cuando completa una fila añade un salto de linea */ 
	}
	
	
}
void traspuesta(int m[3][3], int t[3][3]) /* Funcion que imprime la matriz traspuesta */
{
	for (int i=0; i<=2; i++){
		for (int j=0; j<=2; j++){
			//cout<<m[j][i]<<" "; /* Hace traspuesta solo cambiando i por j */
			
		t[i][j]=m[j][i]; /* Traspuesta guardada en otra matriz */
		
		}
		cout<<ENTER; /* Cuando completa una fila añade un salto de linea */ 
	}
	
	
}

int main(){

//	int matriz[3][3]={{1,2,3},{4,5,6},{7,8,9}}; /* Matriz declarada 3x3 */
	int matriz[3][3];
	int t[3][3]; // Matriz donde se guarda la traspuesta
	
	
	leermatriz(matriz);
	imprimirmatriz(matriz);
	cout<<endl;
	//imprimirtraspuesta(matriz);
	traspuesta(matriz,t);
	cout<<endl;
	imprimirmatriz(t);


system("pause");
return 0;
}
