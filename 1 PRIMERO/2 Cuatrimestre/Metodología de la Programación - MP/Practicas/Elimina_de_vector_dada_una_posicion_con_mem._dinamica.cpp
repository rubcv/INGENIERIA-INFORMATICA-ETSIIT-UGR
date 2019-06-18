#include <iostream>
using namespace std;


void Elimina(int* v, int &util, int pos){
	int* aux;
	aux = new int[util - 1];
	
	for(int i = 0; i < util - 1; i++){
		if(i < pos){
			aux[i] = v[i];
		}else{
			v[i + 1] = aux[i];
		}
	}
	delete[] v;
	util--;




}



int main(){
	
	int util, pos;
	int* v;
	cout<<"Introduce util: "<<endl;
	cin>> util;
	v = new int [util];
	
	
	cout<<"Rellenar vector: "<< endl;
	
	for (int i = 0; i < util; i++){
		cin>> v[i];
	}
	 cout<<"Vector: ";
	 for(int i = 0; i < util; i++)
		cout<< v[i]<< " ";
	cout<<endl;
	
	cout<<"Introduce posicion a eliminar: "<<endl;
	cin>> pos;
	
	Elimina(v,util,pos);
	
	cout<<"Util: "<<util<<endl;
	
	for(int i = 0; i < util; i++)
		cout<< v[i]<< " ";
}
