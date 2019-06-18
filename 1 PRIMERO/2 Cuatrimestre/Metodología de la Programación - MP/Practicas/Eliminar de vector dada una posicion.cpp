#include <iostream>
using namespace std;

void Elimina(int v[], int &util, int pos){
	for(int i = pos - 1; i < util - 1; i++){
		v[i] = v[i + 1];
	}
	util--;
}

int main(){
	
int util, pos;

	cout<<"Introduce util: "<<endl;
	cin>> util;
	
	int v[util];

	cout<<"Introduce el vector: "<< endl;
		for (int i = 0; i < util; i++){
			cin>> v[i];
		}
	cout<<"Introduce posicion a eliminar: "<< endl;	
	cin>> pos;
	
	Elimina(v, util, pos);
	
	for(int i = 0; i < util; i++){
		cout<< v[i]<<" ";
	}

}
