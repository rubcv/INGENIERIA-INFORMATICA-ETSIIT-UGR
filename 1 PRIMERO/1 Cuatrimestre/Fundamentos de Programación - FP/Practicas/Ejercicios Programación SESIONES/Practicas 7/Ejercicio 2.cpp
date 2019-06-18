#include <iostream>

using namespace std;

double Max(double un_valor, double otro_valor, double el_tercero, double maximo)
{
if (un_valor>otro_valor && un_valor>el_tercero){
		maximo=un_valor;
}
if (un_valor<otro_valor && otro_valor>el_tercero){
		maximo=otro_valor;
}
if (un_valor<otro_valor && otro_valor<el_tercero){
		maximo=el_tercero;
}
return maximo;


}


int main (){
 double un_valor, otro_valor, el_tercero, maximo;

cout<<"Introduce tres valores separados de un espacio: ";
cin>>un_valor;
cin>>otro_valor;
cin>>el_tercero;

maximo=Max(un_valor,otro_valor,el_tercero,maximo);

cout<<"El valor maximo es: "<<maximo<<endl;


system ("pause");

}




