#include <iostream>
using namespace std;

char parejas(char, char, char, char);
int main(){

	char min_izda, max_izda, min_dcha, max_dcha;
	

cout << "Escribe una primera letra minuscula: ";
cin >> min_izda;
	while(min_izda <'a' || min_izda >'z'){
		cout << "La letra no era minuscula, vuelve a escribirla: ";
		cin >> min_izda;
	}
	
					
cout << "Escribe una segunda letra mayor alfabeticamente que la anterior: ";
cin >> max_izda;
	while(max_izda <'a' || max_izda >='z' || min_izda > max_izda){
		cout << "La letra no era minuscula o era menor que la anterior, vuelve a introducirla: ";
		cin >> max_izda;
	}
	
cout << "Escribe la primera letra de la pareja: ";
cin >> min_dcha;
	while(min_dcha <'a' || min_dcha >='z'){
		cout << "La letra no era minuscula, vuelve a escribirla: ";
		cin >> min_dcha;
	}
	
					
	cout << "Escribe la segunda letra de la pareja, mayor alfabeticamente que la anterior: ";
	cin >> max_dcha;
	while(max_dcha <'a' || max_dcha >='z' || min_dcha > max_dcha){
		cout << "La letra no era minuscula o era menor que la anterior, vuelve a introducirla: ";
		cin >> max_dcha;
	}
	

	
	parejas(min_izda, max_izda, min_dcha, max_dcha);

	return 0;
	
}

char parejas(char min_izda, char max_izda, char min_dcha, char max_dcha){

	char letra1, letra2;
	int dist1=max_izda - min_izda;
	int dist2=max_dcha - min_dcha;
	
	for(int i=0; i <= dist1; i++){
		letra1= min_izda+i;
	
		
		for(int j=0; j <= dist2; j++){
			cout << letra1;
			letra2=min_dcha+j;
			cout << letra2 << " ";
		}
		cout << "\n";
	}

system ("pause");
}


