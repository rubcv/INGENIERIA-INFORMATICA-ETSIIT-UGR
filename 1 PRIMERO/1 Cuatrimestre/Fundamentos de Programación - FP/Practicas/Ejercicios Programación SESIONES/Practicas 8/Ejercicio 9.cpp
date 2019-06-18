#include <iostream>
#include<cctype>
using namespace std;

char Convierte_a_Mayuscula(char valor){
char valor2;
valor2=toupper(valor);

return valor2;


}

char Convierte_a_Minuscula(char valor){
	char valor3;
valor3=tolower(valor);
	
	return valor3;



}



void Capitalizacion(char valor) {
	
	char valor2,valor3;
	
if (valor>='a' && valor <='z'){
 cout<<endl<<"Es una letra minuscula"<<endl;
 
 valor2=Convierte_a_Mayuscula(valor);
 cout<<endl<<"La letra mayuscula es: "<<valor2<<endl;
 
}

if (valor>='A' && valor <= 'Z'){
	cout<<endl<<"Es una letra mayuscula"<<endl;
	
	valor3=Convierte_a_Minuscula(valor);
	cout<<endl<<"La letra minuscula es: "<<valor3<<endl;
}

if ((valor <'A' || valor>'Z')&& (valor<'a'|| valor>'z')){

	cout<<endl<<"Es un caracter"<<endl;
}



}

	




int main () {
	char valor;

	
cout<<"Introduce un valor: "<<endl;

cin>>valor;

Capitalizacion(valor);



system ("pause");

}
