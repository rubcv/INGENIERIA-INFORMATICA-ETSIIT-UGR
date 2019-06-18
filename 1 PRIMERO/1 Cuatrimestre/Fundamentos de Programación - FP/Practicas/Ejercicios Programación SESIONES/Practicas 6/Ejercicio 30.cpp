#include <iostream>
using namespace std;
int main (){
int nsuc, unid;
char cod;

cout<<"Introduce 1 2 o 3 (Numero de la sucursal), a b o c (Codigo del producto) "
" y numero de unidades vendidas"<<endl;
cout<<"-1 para salir."<<endl<<endl;


	do{
	cin>>nsuc;
	while(nsuc > 3 || nsuc < 1){
		cout<<"Del 1 al 3 "<<endl;
		cin>>nsuc;
	}
	
	cin>>cod;
	while (cod != 'a' && cod != 'b' && cod != 'c'){
		cout<<"Solo a b o c "<<endl;
		cin>>cod;
	}
	cin>>unid;
	while(unid<0){
	cout<<"Unidades positivas "<<endl;
	cin>>unid;
	}
	
	}while(nsuc!=-1 || cod !=-1 || unid != -1);
	

system ("pause");
return 0;
}
