#include <iostream>
using namespace std;

bool Ordenado(char v[], int util){
	bool ordenado = true;
	
	for(int i = 1; i < util && ordenado == true; i++){
		if(v[i - 1] < v[i]){
			
			ordenado = true;
		}else{
			ordenado = false;
		}
	}
	return ordenado;
}


int main(){




}
