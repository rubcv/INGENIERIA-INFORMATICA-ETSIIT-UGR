/* Ejercicio de prueba con el menú  */

/* Prueba de char y string */ 
#include <iostream>
#include <string>
using namespace std;
int main () {
		int a;
		
		string opcion[a];
		opcion[1]= "1: Cafe solo";
		opcion[2]= "2: Cafe con leche";
		opcion[3]= "3: Cola Cao";
		opcion[4]= "4: Chocolate";
		
		cout<<opcion[1]<<endl<<opcion[2]<<endl<<opcion[3]<<endl<<opcion[4]<<endl<<endl;
		
		cout << "\n\nElige tu opcion: "<<endl;
		cin>> a;
		
for (  ; a<=4; )
			{
		
		cout<<"Su opcion es: "<<opcion[a];
		
		cout<<endl<<endl;
		break;
}
if (a>4 || a<1){
	cout<< "Dentro del menu "<<endl;

}
system ("pause");
return 0;
}
