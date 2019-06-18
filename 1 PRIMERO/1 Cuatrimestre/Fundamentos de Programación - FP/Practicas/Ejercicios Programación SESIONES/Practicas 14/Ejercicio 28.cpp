
// En construcción


#include <iostream>
using namespace std;
int main (){
	
	
	const int FILAS = 50;
	const int COLUMNAS = 30;
	
	int numfilas, i, j, k,suma;
	
	cout<<" MATRIZ SIMETRICA: Introduzca el numero de filas: "<<endl;
	cin>> numfilas;

	cout<<" Introduce los datos de la matriz: "<<endl;
	float original[FILAS][COLUMNAS];
	float suavizada[FILAS][COLUMNAS];
	
	if (numfilas<FILAS){
		for (int i=0; i< numfilas; i++){
			for (int j=0;j<numfilas; j++)
			
		
			cin>>original[i][j];
		}
		
		for (j = i+1; j<numfilas; j++){
			 if(i==j)
			 	suavizada[i][j]=original[i][j];
			else if (j>i) {
				int suma = 0;
				
				for (k = j; k < numfilas; k++){
					suma += original[i][k];
					
					suma=suma/(numfilas-j);
				
					suavizada[i][j]=suma;
				}
			} else {
				suavizada[i][j]=suavizada[j][i];
			} 
		}
	}
	
	cout<<endl;
for (i = 0; i < numfilas; i ++){
	for (j=0; j < numfilas; j++){	
		
		cout << original[i][j];

	}
	cout<< endl;
}



return 0;
}
