/* Queremos modificar el ejercicio 7 para leer un carácter letra_original desde teclado
y hacer lo siguiente:
 Si es una letra mayúscula, almacenaremos en la variable letra_convertida
la correspondiente letra minúscula.
 Si es una letra minúscula, almacenaremos en la variable letra_convertida
la correspondiente letra mayúscula.
 Si es un carácter no alfabético, almacenaremos el mismo carácter en la variable
letra_convertida
El programa debe imprimir en pantalla el valor de letra_convertida e indicar si la
letra introducida era una minúscula, mayúscula o no era una carácter alfabético. */


#include <iostream>
using namespace std;
int main () {
	
const int SALTO = 'a'-'A';
char letra_original, letra_convertida;
cout<<"Introduce una letra: ";
cin>>letra_original;

if(letra_original>='a'&&letra_original<='z'){
letra_convertida=letra_original-SALTO;

cout<<letra_convertida<<"\nEra minuscula.";
}
if (letra_original>='A'&&letra_original<='Z'){
	letra_convertida=letra_original+SALTO;
	
	cout<<letra_convertida<<"\nEra mayuscula.";
}
if (!letra_original >='A'&&!letra_original <='Z'&&!letra_original>='a'&&!letra_original<='z')
{
cout<<"\nEra un caracter";

}

system ("pause");
return 0;
}
