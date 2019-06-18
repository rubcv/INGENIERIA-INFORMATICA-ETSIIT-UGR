 #include <iostream>
 #include <ctype.h>
 using namespace std;
 int main () {
 	double letra, edad;
 	
 cout<< "Escriba una letra: ";
 cin>> letra;
 if (letra=tolower){ 
printf("True"); 
}else { 
printf("False"); 
} ;
   cout<<"Introduzca edad: ";
 cin>> edad;
 if (edad<18, edad>65)
 printf ("True");
 
 return 0;
 }
