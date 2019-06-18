#include <iostream>
using namespace std;

// MEDIA DE UN VECTOR

float Media(float v[], int util){
	float suma = 0;
	
	for( int i = 0; i < util; i++){
		suma += v[i];
	}
	
	return suma/util;
}



int main(){

}
