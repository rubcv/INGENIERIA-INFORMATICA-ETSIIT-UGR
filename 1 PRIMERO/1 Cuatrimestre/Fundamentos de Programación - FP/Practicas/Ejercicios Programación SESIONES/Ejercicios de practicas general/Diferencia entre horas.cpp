#include <iostream>
#include <cmath>
using namespace std;
int main (){

int hora=0,min=0,seg=0,dia=1,dia2=1;
int hora2, min2, seg2;

cout<<"Introduce la primera hora: ";
cin>>hora;
cout<<"Introduce los primeros minutos: ";
cin>>min;
cout<<"Introduce los primeros segundos: ";
cin>>seg;

		if (seg>59){
		min=min+1;
		}
	
		if (min>59){
		hora=hora+1;
		}

		if (hora>23){
		dia=dia+1;
		}
	cout<<"Introduce la segunda hora: ";
	cin>>hora2;
	cout<<"Introduce los segundos minutos: ";
	cin>>min2;
	cout<<"Introduce los segundos segundos: ";
	cin>>seg2;
	
	if (seg2>59){
	min2=min2+1;
	}
	
	if (min>59){
	hora2=hora2+1;
	}
	
	if (hora>23){
	dia2=dia2+1;
	}
	
int	diaf=abs (dia2-dia);
int	horaf=abs (hora2-hora);
int	minf=abs (min2-min);
int	segf=abs (seg2-seg);

cout<<"Dias: "<<diaf<<endl;
cout<<"Horas: "<<horaf<<endl;
cout<<"Minutos: "<<minf<<endl;
cout<<"Segundos: "<<segf;






system("pause");
return 0;
}
