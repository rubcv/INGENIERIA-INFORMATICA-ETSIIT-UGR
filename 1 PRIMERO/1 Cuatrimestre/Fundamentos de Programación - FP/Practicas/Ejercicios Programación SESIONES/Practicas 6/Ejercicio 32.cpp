#include <iostream>
#include <cmath>
using namespace std;

int main(){
   int numero, numero_copia,resultado;
   double suma;
   printf ("Introduce un numero para ver si es narcisista: ");
   scanf ("%s", &numero);

  
numero_copia=numero;
do{
     suma= pow (numero_copia,"%s");
  
   }
   	while ( numero_copia > 0 );

   if (suma == numero){
      cout << "\n\nEs narcisista.";
   }else{
      cout << "\n\nNo es narcisista.";
}
   system("pause");
}
