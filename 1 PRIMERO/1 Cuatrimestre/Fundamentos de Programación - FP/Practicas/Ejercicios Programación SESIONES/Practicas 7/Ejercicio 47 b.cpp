#include <iostream>
using namespace std;
int main (){
	
	int min,max,m,n;
	
	cout<<"Introduce un valor inicial: ";
	cin>> n;
	cout<<"Introduce un numero de filas: ";
	cin>> m;
	
	for( int i=0;i<m;i++) {
		for(int o=0;o<m;o++){
			cout<<o+i+n<<" ";
		}
		cout << endl;
	}
	
	system ("pause");
return 0;	
}
