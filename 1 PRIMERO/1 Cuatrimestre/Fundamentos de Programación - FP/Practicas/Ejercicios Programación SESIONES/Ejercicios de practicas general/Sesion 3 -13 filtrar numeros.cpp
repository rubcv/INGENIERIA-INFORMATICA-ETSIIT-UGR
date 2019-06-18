#include <iostream>
#include <cmath>
using namespace std;
int main (){
int cifra=0,num2,potencia,suma,digitos,numero;


cout<<"Introduce un numero entero para ver si es feliz:  ";
cin>>numero;

numero=num2;

do {
	num2 = num2/10;

cifra++;
}while(num2>9);

do {
	potencia= pow(10,cifra);
	digitos=numero/potencia;
	numero= numero%potencia;
	
	cifra--;
	
	suma = suma +(digitos*digitos);
	
}while(numero>9);

suma=suma+(numero*numero);

if(suma==1){
cout<<"Es feliz."<<endl;
}else{
cout<<"No es feliz"<<endl;
}

system("pause");
return 0;

}










