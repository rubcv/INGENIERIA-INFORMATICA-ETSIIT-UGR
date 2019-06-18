#include <iostream>
using namespace std;
int main () {

const int SALTO = 'a'-'A';
char a,af;
do{
cout<<"Introduzca una letra mayuscula: ";
cin>>a;

	
	af=a+SALTO;


}
while (a>='a'&&a<='z');


cout<< "Letra convertida es: "<<af<<endl<<endl;





system ("pause");
return 0;
}
