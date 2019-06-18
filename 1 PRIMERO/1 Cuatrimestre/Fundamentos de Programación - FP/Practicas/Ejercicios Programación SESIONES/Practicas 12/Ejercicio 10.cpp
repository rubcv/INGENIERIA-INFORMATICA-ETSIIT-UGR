#include <iostream>
using namespace std;

int main(){
	char letra;
	int caracteres['Z'-'A'+1];
	
	// Inicializar vector
	for(int i=0; i< ('Z'-'A'+1); i++){
		caracteres[i]=0;
	}
		
	cout<<"Introduce caracteres ('.' para terminar): "<<endl;
	cin>>letra;
	
	while(letra!='.'){
		caracteres[letra-'A']++;
		cout<< "Introduce caracteres ('.' para terminar): "<<endl;
		cin>>letra;
	}
	
	for(int i=0; i<('Z'-'A'+1); i++){	
		letra='A'+i;
		cout<<letra<<" aparece "<<caracteres[i]<<" veces"<<endl;
	}
	
system("pause");
return 0;
}
