#include <iostream>
#include <cmath>

using namespace std;

//Prec: numero_introducido >= 0
string DigitosSinCalculos(int numero_introducido){
	string numero = to_string(numero_introducido), digitos = "";
	for(int i = 0; i < numero.length(); i++){
		digitos += " " + numero.substr(i, 1);
	}
	return digitos;
}

//Prec: numero_introducido >= 0
string Digitos(int numero_introducido){
	string digitos = "";
	const long long var_control = 10;
	long long aux_calculo = 10, var_calculo = 1, contador = 0;
	
	for(var_calculo = 1; var_calculo <= numero_introducido; var_calculo *= var_control){
		aux_calculo = (numero_introducido / var_calculo);
		contador++;
	}
	
	digitos += to_string(aux_calculo);
	
	for(contador=contador-2; contador>=0; contador--){
		var_calculo = pow(var_control, contador);
		aux_calculo =(numero_introducido/var_calculo)-(aux_calculo*var_control);
		digitos += " "+to_string(aux_calculo);
		aux_calculo = numero_introducido/var_calculo;
	}
	return digitos;
}

int main(){
	int numero;
	
	do{
		cout << "\nIntroduce un Numero: ";
		cin >> numero;
	}while(numero < 0);
	
	cout << endl << Digitos(numero) << endl;
	
	system("pause");
	return 0;
}
