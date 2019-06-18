
//En construcción


#include <iostream>
using namespace std;


class SecuenciaCaracteres{
	private:
	
	int contador;
	
	const int TAM = 100;
	static const char secuencia[TAM]={0};
	static const char procesadas[TAM]={0};

	public:	

void setContador(){
	contador=0;

}


void Comparar(SecuenciaCaracteres , SecuenciaCaracteres)
{
	
	int i = 0;
	int j = 0;
	secuencia[i]=secuencia[j];
	
	
	
	/*
	   secuencia[i]-secuencia[i]+1 == secuencia[j]-secuencia[j]+1
		Equivale a la primera cifra de cada cadena
	*/
	
	if(secuencia[i]-secuencia[i]+1 == secuencia[j]-secuencia[j]+1 && secuencia[i]-1 == secuencia[j]-1)
 	{	
	
	
	for( i = 1; i < secuencia[i]-1; i++){
		for( j = 1; j < secuencia[j]-1; j++ ){
			if(i != j){
									
				i=procesadas[TAM];				
			}else{
			
				contador++;
			
			}
			
		}
	}



cout<< "A";
}

}




};



int main(){


SecuenciaCaracteres caracteres1, caracteres2;



caracteres1.Comparar(caracteres2);












return 0;
}
