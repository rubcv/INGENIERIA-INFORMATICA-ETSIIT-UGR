#include <iostream> 
using namespace std; 
int x, n, potencia; 
main(){ 
cout<<"escriba la base"<<endl; 
cin>>x; 
cout<<"Escriba el exponente"<<endl; 
cin>>n; 
potencia=x; 
for (int i =1; i<n; i++){ 
potencia*=x; 
} 
cout<<x<<" elevado a "<<n<<" = "<<potencia<<endl; 

system ("pause");
return 0; 
}
