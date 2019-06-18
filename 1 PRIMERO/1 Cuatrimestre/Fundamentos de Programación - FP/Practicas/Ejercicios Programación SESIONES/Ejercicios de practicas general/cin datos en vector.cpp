#include <iostream>
using namespace std;

int main (){

const int TAM = 10;
int datos;
int vector[TAM]={0};



cout<<"Introduce datos: "<<endl;

for(int i = 0; i < TAM; i++){
		cin>> datos;
		vector[i]=datos;	
}

cout<<endl;
cout<<"Vector: "<<endl;
	for(int j = 0; j < TAM; j++){
		cout << vector[j];
		
	}
	return 0;

}
