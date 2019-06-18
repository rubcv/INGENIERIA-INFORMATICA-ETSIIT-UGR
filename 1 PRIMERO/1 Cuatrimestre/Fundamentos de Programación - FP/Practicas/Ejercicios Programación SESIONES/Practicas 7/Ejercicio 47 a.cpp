#include <iostream>
using namespace std;
int main (){
	
	int min,max,m,n;
	
	cout<<"Introduce un valor minimo: ";
	cin>> n;
	cout<<"Introduce un valor maximo: ";
	cin>> m;
	
	for( min=n;min<=m;min++) {
		for(int i=min;i<=m;i++){
			cout<<i<<" ";
		}
		cout << endl;
	}
	
	system ("pause");
return 0;	
}
