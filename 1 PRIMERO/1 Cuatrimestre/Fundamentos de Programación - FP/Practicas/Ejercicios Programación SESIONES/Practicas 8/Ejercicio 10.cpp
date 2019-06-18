#include <iostream>
#include <cmath>
using namespace std;
int main() {


double des, esp, x, gaus;
const double pi=3.141592654;
const double e=2.718281828;
const double b0 = 0.2316419, b1 = 0.319381530 ,b2 = 0.356563782,
b3 = 1.781477937, b4 = 1.821255978, b5 = 1.330274429;

double t0,t1,t2,t3,t4,t5;
double cdf;

cout<<"Este programa calcula la gaussiana"<<endl<<endl;
cout<<"Introduce un valor de desviacion: ";
cin>>des;
cout<<endl<<"Introduce un valor de esperanza: ";
cin>>esp;
cout<<endl<<"Introduce un valor del eje x: ";
cin>>x;

for (int i=0; i<=x;i++){

gaus=(1/des*sqrt(2*pi))*(pow(e,(-1/2)*pow((i-esp/des),2)));


t0=1/1+b0*i;
t1=1/(1+b1*i);
t2=1/(1+b2*i);
t3=1/(1+b3*i);
t4=1/(1+b4*i);
t5=1/(1+b5*i);

cdf=1-gaus*(b0*t0+b1*t1+b2*t2+b3*t3+b4*t4+b5*t5);

cout<<"El area en "<< i <<" es: "<<cdf<<endl;
}
system ("pause");
return 0;
}
