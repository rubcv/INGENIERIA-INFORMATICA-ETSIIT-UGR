/* Queremos modificar el ejercicio 7 para leer un car�cter letra_original desde teclado
y hacer lo siguiente:
 Si es una letra may�scula, almacenaremos en la variable letra_convertida
la correspondiente letra min�scula.
 Si es una letra min�scula, almacenaremos en la variable letra_convertida
la correspondiente letra may�scula.
 Si es un car�cter no alfab�tico, almacenaremos el mismo car�cter en la variable
letra_convertida
El programa debe imprimir en pantalla el valor de letra_convertida e indicar si la
letra introducida era una min�scula, may�scula o no era una car�cter alfab�tico. */


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
