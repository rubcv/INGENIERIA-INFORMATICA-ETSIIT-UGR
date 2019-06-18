#include <iostream>
using namespace std;

int LeeEnteroPositivo(int fac,int num,int total_fac){
	
	for(fac=0;fac<num;fac++){
total_fac=num*fac;
	}

return total_fac;
}

int main (){
	int fac,num,total_fac;
	
	
	

cout<<"Introduce un numero para sacar su factorial: "<<endl;
cin>>num;


total_fac=LeeEnteroPositivo(fac,num,total_fac);

cout<<"Su factorial es: "<<total_fac<<endl<<endl;




system("pause");


}
