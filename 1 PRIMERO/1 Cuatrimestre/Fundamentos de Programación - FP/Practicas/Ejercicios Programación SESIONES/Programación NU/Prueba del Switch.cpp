#include <iostream>
using namespace std;
int main (){
char c; //Car�cter que va cambiando
cout<<"Escribe una letra: "<<endl;
cin>> c;
switch (c)//Variable que va cambiando
{

/* Casos */

		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		
		cout << "Es una vocal ";
		break; //Si no se cumple la primera condici�n 
		default: // Otros casos
			cout<<"Es una consonante ";

}



system("pause");

return 0;
}
