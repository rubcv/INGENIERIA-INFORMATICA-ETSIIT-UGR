#include <iostream>

using namespace std;

char LeeOpcion2Alternativas(char val)
{
	do{cout<< "La letra era incorrecta, vuelve a introducirla: ";
cin>>val;
}
while (val!='N' && val!='n' && val!='s' && val!='S');


return val;

}



int main () {
char val;




cout<<"Introduce la letra S o N maysucula o minuscula: ";

cin>>val;

val=LeeOpcion2Alternativas(val);



cout<<"La letra era "<<val<<endl;




system ("pause");
}
