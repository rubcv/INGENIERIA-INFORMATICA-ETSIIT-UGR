#include <iostream>
#include <cmath>

using namespace std;

int main () {
	int suc1codA = 0, suc1codB = 0, suc1codC = 0 ;
	int suc2codA = 0, suc2codB = 0, suc2codC = 0 ;
	int suc3codA = 0, suc3codB = 0, suc3codC = 0 ;
	
	int num_suc, cantidad;
	char cod_prod;
	
	bool salir = false;
	
	do {
		cout << "Introduca numero se sucursal 1, 2 ó 3: ";
		cin >> num_suc ;
		
		if(num_suc == -1) {salir = true;}
		
		if(!salir) {
			cout << "Introduca codigo producto A, B ó C: " ; 
			cin >> cod_prod;
			
			cout << "Introduca cantidad ";
			cin >> cantidad;
			
			if (num_suc == 1) {
				if(cod_prod == 'a') {
					suc1codA += cantidad;
				} else if(cod_prod == 'b') {
					suc1codB += cantidad;
				} else if(cod_prod == 'c') {
					suc1codC += cantidad;
				} else { 
					cout << "Codigo producto erroneo ";
				}
			} else if (num_suc == 2) {
				if(cod_prod == 'a') { 
					suc2codA += cantidad;	
				} else if(cod_prod == 'b') {
					suc2codB += cantidad;
				} else if(cod_prod == 'c') {
					suc2codC += cantidad;
				} else {
					cout << "Codigo producto erroneo ";
				}
				
			} else if (num_suc == 3) {
				if(cod_prod == 'a') {
					suc3codA += cantidad;
					
				} else if(cod_prod == 'b') {
					suc3codB += cantidad;
				} else if(cod_prod == 'c') {
					suc3codC += cantidad;
				} else {
					cout << "Codogo producto erroneo ";
				}	
			}
		} 
	} while(!salir);
	
	int total_suc_1 = suc1codA + suc1codB + suc1codC; 
	int total_suc_2 = suc2codA + suc2codB + suc2codC; 
	int total_suc_3 = suc3codA + suc3codB + suc3codC;
	
	cout << "total_suc_1:" << total_suc_1 << endl;
	cout << "total_suc_2:" << total_suc_2 << endl;
	cout << "total_suc_3:" << total_suc_3 << endl;
	
	if ( total_suc_1 > total_suc_2 ){
		if(total_suc_1 > total_suc_3) {
			cout << "sucursal 1 es la que mas productos ha vendido ";
		}
	} else if ( total_suc_2 > total_suc_3) {
		cout << "sucursal 2 es la que mas productos ha vendido ";
	} else {                                                                            // en el caso de que todos sean menor que 3
		cout << "sucursal 3 es la que mas productos ha vendido ";
	}
	
	
	system("pause");
	
	
	}
	
