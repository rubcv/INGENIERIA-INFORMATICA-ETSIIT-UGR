#include <iostream>
using namespace std;

int funcion(int a, int b){

a=2;
b=3;

return a,b;
}

int main (){

int a=2,b=3;

a= funcion(a,b);
b= funcion(a,b);
cout<<a<<" "<<b<<endl;

system ("pause");
return 0;

}
