# include <iostream>

using namespace std;

int main (){

int numero,numero_desglosado=0,min,max,auxnumero,contador=0;

cout << "Introduce un numero a buscar: "<<endl;
cin >> numero;

cout <<"Introduce el numero maximo: "<< endl;
cin >> max;

cout <<"Introduce el numero minimo: "<< endl;
cin >> min;

for (int i=min;i<max;i++){

	//log(i)+1; //Para obtener el numero de cifras . NOTA: Hace falta la biblioteca cmath

	auxnumero=i;
	numero_desglosado=0;
	
	while(auxnumero!=0){
		numero_desglosado=auxnumero%10;//sacamos el resto
		auxnumero/=10;//divimos entre 10 y añadimos a la variable, para ir quitando la ultima cifra de la serie de numeros
		
		if(numero_desglosado==numero){
			contador++;//Lo usaremos mas abajo para sacar el exponente segun la cantidad de numeros.
		}
	}
}


cout << "Veces que se repite el numero "<<numero<<" : "<<contador<<endl;

system("pause");
}




