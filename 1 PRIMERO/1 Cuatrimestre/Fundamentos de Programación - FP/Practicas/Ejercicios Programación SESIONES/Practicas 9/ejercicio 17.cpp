#include <iostream>
using namespace std;

class Recta{
	public:
		
void pendiente(double A,double B){
	double pendiente=-A/B;
	
cout<<"La pendiente es: "<<pendiente<<endl;
}




};


int main (){
	double A,B,C,D,E,F;
Recta recta1=Recta();
Recta recta2=Recta();


cout<<"Introduce 6 numeros; 3 de la primera recta y 3 de la segunda para calcular la pendiente"<<endl<<endl;
cin>>A;
cin>>B;
cin>>C;
recta1.pendiente(A,B);
cout<<"Segunda recta: "<<endl;
cin>>D;
cin>>E;
cin>>F;
recta2.pendiente(D,E);


system("pause");
return 0;




}
