#include <iostream>
using namespace std;

//ELEMENTOS DE UN VECTOR INCLUIDOS EN OTRO


bool ElementosContenidos(int v1[], int util1, int v2[], int util2){
	
		bool todoscontenidos = true;
		
		for(int i = 0; i < util1 && todoscontenidos == true; i++){
			todoscontenidos = false;
			
			for(int j = 0; j < util2; j++){
				if(v1[i] == v2[j]){
					todoscontenidos = true;
				}
			}
		}
		return todoscontenidos;

}



int main(){

}
