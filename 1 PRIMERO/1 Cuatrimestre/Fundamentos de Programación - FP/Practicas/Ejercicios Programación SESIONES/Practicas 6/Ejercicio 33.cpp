#include <iostream>

using namespace std;
int main (){

int x, n, potencia;

//Elevar x a n
cout<<"Escribe la base "; 
cin>>x; 
cout<<"Escribe el exponente "; 
cin>>n; 
potencia=x; 
for (int i =1; i<n; i++){ 
potencia*=x; 
} 
cout<<x<<" elevado a "<<n<<" = "<<potencia<<endl;

// Sacar factorial
int fac=0; 
printf("Escribe numero para calcular el factorial "); 
scanf("%d",&fac); 
int valor=fac-1; 
int num=fac; 
while (valor>=1) 
{ 
num=num*valor; 
valor--; 
} 

printf("El factorial de %d es: %d ", fac,num); 
cout<<endl<<endl;
system ("pause");
return 0;
}
