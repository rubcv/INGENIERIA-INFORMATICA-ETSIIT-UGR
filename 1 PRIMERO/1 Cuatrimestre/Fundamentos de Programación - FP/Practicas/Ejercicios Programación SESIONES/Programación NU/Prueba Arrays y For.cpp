#include <iostream>
using namespace std;
int main () {

char c [5]; // Se declara una variable y el número de valores que puede tomar
 c[0]= 'H';  /* Los distintos valores que va tomando */
 c[1]= 'o';
 c[2]= 'l';
 c[3]= 'a';
 c[4]= '!';

for (int a=0; // Nueva variable que tomaría el sitio de [])
     a<5; // Condición de que sea menor al nº de valores que puede tomar
     a++ // Le vaya sumando 1 para que se cumplan todos
     )
     
     cout << c[a]; /* cout con la variable original y la variable que determina
     los valores que toma */
     cout<< endl;
     
system ("pause");
return 0;
}
