#include <iostream>
using namespace std;
int main (){
	
	int min, max;
	
	cout<<"Introduce un valor minimo 1: ";
	cin>> min;
	cout<<"Introduce un valor maximo 6: ";
	cin>> max;
	
	for(min=1;min<=6;min++) {
		for(int i=min;i<=6;i++){
			cout<<i<<" ";
		}
		cout << endl;
	}
	
	system ("pause");
return 0;	
}
