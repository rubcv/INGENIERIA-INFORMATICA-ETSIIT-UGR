
// En construcción


#include <iostream>
#include <cmath>
using namespace std;

class TableroBuscaMinas{
	private:
	static	const int FILAS = 50;
	static	const int COLUMNAS = 30;
	
	int matriz[FILAS][COLUMNAS] = {0};
	
	public:

	int getFilas(){
		
		return FILAS;
	}
	
	int getColumnas(){
		
		return COLUMNAS;
	}
	
	
	
	void ImprimirMatriz(){
		
		for(int i=0;i<FILAS;i++){
			for(int j=0;j<COLUMNAS;j++){
				cout<<matriz[i][j];
			}
			cout<<endl;
		}	
	}
	
	bool incluirmina(int i,int j){
		
		matriz[i][j]==true;
	}
	
	
	bool haymina(int i, int j){
		bool mina = false;
		
		
		if(matriz[i][j] == true){
			
			return mina;	
		}else{
			for (int f=0;f<FILAS;f++){
				for (int c=0;f<COLUMNAS;c++){
					if(matriz[i][j] == 1){
						cout<<matriz[max(0,f-1)][c-1]<<endl; // COMPARAR MAXIMO
					}			
				}
			}	
		}
	}
};



	
	

int main(){
	
	char orden;
	int i;
	int j;
	
	cout<<"Dispone de un buscaminas de: 50 filas y 30 columnas"<<endl<<endl;
	
	TableroBuscaMinas tablero;
	
	
	
	do{
	cout<<"Escribe dos coordenadas i j donde quieres colocar una mina, '-1' en ambas coordenadas para salir "<<endl;

	cin>>i;
	cin>>j;

	tablero.incluirmina(i,j);
	
	}while(i != -1 && j != -1 );
	
	cout<<endl<<endl;
	
	do{
	cout<<"Introduce coordenadas i j para ver si hay una mina, '-1' en ambas coordenadas para salir: "<<endl;
	cin>>i;
	cin>>j;
	
	
	if(tablero.haymina(i,j) == true){
		cout<<"Explosion"<<endl;
	}else{
	
		tablero.haymina(i,j);
	}
	
	}while(i != -1 && j != -1 );
	
	
	
	
	
	
	do{
	cout<<"Introduce # para ver el tablero "<<endl;
	
		cin>>orden;
		
	}while(orden != '#' );
	tablero.ImprimirMatriz();



return 0;
}







