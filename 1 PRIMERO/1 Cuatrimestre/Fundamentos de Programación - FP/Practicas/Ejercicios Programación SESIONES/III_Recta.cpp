////////////////////////////////////////////////////////////////////////////
//
// Fundamentos de Programación
// ETS Informática y Telecomunicaciones
// Universidad de Granada
// Departamento de Ciencias de la Computación e Inteligencia Artificial
// Autor: Juan Carlos Cubero
//
////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;


//////////////////////////////////////////////////////////////////////
// Datos miembros públicos :-(
   
class Recta_vs1{
// Ax + By + C = 0
public:
	double A = 0.0;
	double B = 0.0;
	double C = 0.0;   
};


//////////////////////////////////////////////////////////////////////
// Datos miembros públicos :-(
// Métodos públicos :-)
  
class Recta_vs2{
// Ax + By + C = 0
public:
	double A = 0.0;
	double B = 0.0;
	double C = 0.0;  
	
   double Ordenada_en(double x){
		return (-C - x*A ) / B;
	}
	
	double Abscisa_en (double y){
		return (-C - y*B ) / A;
	}
	
	double Pendiente(){
		return -A/B;
	}
};



//////////////////////////////////////////////////////////////////////
// Datos miembros privados :-)
// Métodos públicos :-)
// Un método para asignar el valor de cada dato miembro :-)
   
class Recta_vs3{
// Ax + By + C = 0
private:
	double A = 0.0;
	double B = 0.0;
	double C = 0.0;  
public:	
	double Coef_X(){
		return A;
	}

	double Coef_Y(){
		return B;
	}
	
	double Coef_indep(){
		return C;
	}
	
	void SetCoefX(double coef_x){
	   A = coef_x;
	}

	void SetCoefY(double coef_y){
	   B = coef_y;
	}
	
	void SetCoefIndep(double coef_indep){
	   C = coef_indep;
	}

   double Ordenada_en(double x){
		return (-C - x*A ) / B;
	}
	
	double Abscisa_en (double y){
		return (-C - y*B ) / A;
	}
	
	double Pendiente(){
		return -A/B;
	}
};


//////////////////////////////////////////////////////////////////////
// Datos miembros privados :-)
// Métodos públicos :-)
// Un único método para asignar valores a todos 
// los datos miembro a la misma vez :-) 

class Recta_vs4{
// Ax + By + C = 0
private:
	double A = 0.0;
	double B = 0.0;
	double C = 0.0;  	
public:
	void SetCoeficientes(double coef_x, double coef_y, double coef_indep){
      A = coef_x;
      B = coef_y;
      C = coef_indep;
	}

	double Coef_X(){
		return A;
	}

	double Coef_Y(){
		return B;
	}
	
	double Coef_indep(){
		return C;
	}
	
	double Ordenada_en(double x){
		return (-C - x*A ) / B;
	}
	
	double Abscisa_en (double y){
		return (-C - y*B ) / A;
	}
	
	double Pendiente(){
		return -A/B;
	}
};

//////////////////////////////////////////////////////////////////////
// Datos miembros privados :-)
// Métodos públicos :-)
// Un único método para asignar valores a todos los datos miembro a la misma vez :-) 
// Constructor :-)
   
class Recta_vs5{
// Ax + By + C = 0
private:
	double A = 0.0;
	double B = 0.0;
	double C = 0.0;  
	
public:
   Recta_vs5(double coef_x, double coef_y, double coef_indep){      
      // O bien hacemos las asignaciones una a una:
      // A = coef_x;
      // B = coef_y;
      // C = coef_indep;
      
      // O bien usamos el mismo método SetCoeficientes:
      SetCoeficientes(coef_x, coef_y, coef_indep);
   }

	void SetCoeficientes(double coef_x, double coef_y, double coef_indep){
      A = coef_x;
      B = coef_y;
      C = coef_indep;
	}

	double Coef_X(){
		return A;
	}

	double Coef_Y(){
		return B;
	}
	
	double Coef_indep(){
		return C;
	}
	
	double Ordenada_en(double x){
		return (-C - x*A ) / B;
	}
	
	double Abscisa_en (double y){
		return (-C - y*B ) / A;
	}
	
	double Pendiente(){
		return -A/B;
	}
};


//////////////////////////////////////////////////////////////////////
// Datos miembros privados :-)
// Métodos públicos :-)
// Un único método para asignar valores a todos los datos miembro a la misma vez :-) 
// Constructor :-)
// Método privado para comprobar la validez de los datos a asignar a los datos miembro :-)

class Recta{
// Ax + By + C = 0
private:
	double A = 0.0;
	double B = 0.0;
	double C = 0.0;  
	
   bool SonCorrectos (double coef_x, double coef_y){
      return !(coef_x == 0 && coef_y == 0);
   }
   
public:
   Recta(double coef_x, double coef_y, double coef_indep){
      SetCoeficientes(coef_x, coef_y, coef_indep);
   }

   // Si los datos no son correctos, no hace ninguna modificación   
	void SetCoeficientes(double coef_x, double coef_y, double coef_indep){
      if (SonCorrectos(coef_x, coef_y)){
         A = coef_x;
         B = coef_y;
         C = coef_indep;
      }
	}

	double Coef_X(){
		return A;
	}

	double Coef_Y(){
		return B;
	}
	
	double Coef_indep(){
		return C;
	}
	
	double Ordenada_en(double x){
		return (-C - x*A ) / B;
	}
	
	double Abscisa_en (double y){
		return (-C - y*B ) / A;
	}
	
	double Pendiente(){
		return -A/B;
	}
};

int main(){
   double coef_x_primera_recta, coef_y_primera_recta, coef_indep_primera_recta, 
          coef_x_segunda_recta, coef_y_segunda_recta, coef_indep_segunda_recta;
   double pendiente_primera_recta, pendiente_segunda_recta;
   double x, ordenada_de_x, y, abscisa_de_y;
   
   //////////////////////////////////////////////////////////////////////
   // vs_1
   
   /*
   Recta_vs1 primera_recta;
   Recta_vs1 segunda_recta;
   
 
   cout << "Introduzca los coeficientes de la recta Ax + By + C = 0\n";
   cin >> coef_x_primera_recta;
   cin >> coef_y_primera_recta;
   cin >> coef_indep_primera_recta;
   cout << "\nIntroduzca los coeficientes de la recta Ax + By + C = 0\n";
   cin >> coef_x_segunda_recta;
   cin >> coef_y_segunda_recta;
   cin >> coef_indep_segunda_recta;
   
   primera_recta.A = coef_x_primera_recta;
   primera_recta.B = coef_y_primera_recta;
   primera_recta.C = coef_indep_primera_recta;
   
   segunda_recta.A = coef_x_segunda_recta;
   segunda_recta.B = coef_y_segunda_recta;
   segunda_recta.C = coef_indep_segunda_recta;
      
   pendiente_primera_recta = - primera_recta.B / primera_recta.A;
   pendiente_segunda_recta = - segunda_recta.B / segunda.recta.A;      
   */
   
   
   //////////////////////////////////////////////////////////////////////
   // vs_2
   
   /*
   Recta_vs2 primera_recta;
   Recta_vs2 segunda_recta;
   
   cout << "Introduzca los coeficientes de la recta Ax + By + C = 0\n";
   cin >> coef_x_primera_recta;
   cin >> coef_y_primera_recta;
   cin >> coef_indep_primera_recta;
   cout << "\nIntroduzca los coeficientes de la recta Ax + By + C = 0\n";
   cin >> coef_x_segunda_recta;
   cin >> coef_y_segunda_recta;
   cin >> coef_indep_segunda_recta;
   cout << "\nIntroduzca un valor de abscisa\n";
   cin >> x;
   cout << "\nIntroduzca un valor de ordenada\n";
   cin >> y;
   
   primera_recta.A = coef_x_primera_recta;
   primera_recta.B = coef_y_primera_recta;
   primera_recta.C = coef_indep_primera_recta;
   
   segunda_recta.A = coef_x_segunda_recta;
   segunda_recta.B = coef_y_segunda_recta;
   segunda_recta.C = coef_indep_segunda_recta;
      
   pendiente_primera_recta = primera_recta.Pendiente();
   pendiente_segunda_recta = segunda_recta.Pendiente();      
   
   ordenada_de_x = primera_recta.Ordenada_en(x);
   abscisa_de_y  = primera_recta.Abscisa_en(y);
   */
   
   
   //////////////////////////////////////////////////////////////////////
   // vs_3
   
   /*   
   Recta_vs3 primera_recta;
   Recta_vs3 segunda_recta;
   
   cout << "Introduzca los coeficientes de la recta Ax + By + C = 0\n";
   cin >> coef_x_primera_recta;
   cin >> coef_y_primera_recta;
   cin >> coef_indep_primera_recta;
   cout << "\nIntroduzca los coeficientes de la recta Ax + By + C = 0\n";
   cin >> coef_x_segunda_recta;
   cin >> coef_y_segunda_recta;
   cin >> coef_indep_segunda_recta;
   cout << "\nIntroduzca un valor de abscisa\n";
   cin >> x;
   cout << "\nIntroduzca un valor de ordenada\n";
   cin >> y;
   
   primera_recta.SetCoefX(coef_x_primera_recta);
   primera_recta.SetCoefY(coef_y_primera_recta);
   primera_recta.SetCoefIndep(coef_indep_primera_recta);
   
   segunda_recta.SetCoefX(coef_x_segunda_recta);
   segunda_recta.SetCoefY(coef_y_segunda_recta);
   segunda_recta.SetCoefIndep(coef_indep_segunda_recta);
      
   pendiente_primera_recta = primera_recta.Pendiente();
   pendiente_segunda_recta = segunda_recta.Pendiente();      
   
   ordenada_de_x = primera_recta.Ordenada_en(x);
   abscisa_de_y  = primera_recta.Abscisa_en(y);
   */
   
   //////////////////////////////////////////////////////////////////////
   // vs_4
   
   /*
   Recta_vs4 primera_recta;
   Recta_vs4 segunda_recta;
   
   cout << "Introduzca los coeficientes de la recta Ax + By + C = 0\n";
   cin >> coef_x_primera_recta;
   cin >> coef_y_primera_recta;
   cin >> coef_indep_primera_recta;
   cout << "\nIntroduzca los coeficientes de la recta Ax + By + C = 0\n";
   cin >> coef_x_segunda_recta;
   cin >> coef_y_segunda_recta;
   cin >> coef_indep_segunda_recta;
   cout << "\nIntroduzca un valor de abscisa\n";
   cin >> x;
   cout << "\nIntroduzca un valor de ordenada\n";
   cin >> y;
   
   primera_recta.SetCoeficientes(coef_x_primera_recta, coef_y_primera_recta, coef_indep_primera_recta);   
   segunda_recta.SetCoeficientes(coef_x_segunda_recta, coef_y_segunda_recta, coef_indep_segunda_recta);
      
   pendiente_primera_recta = primera_recta.Pendiente();
   pendiente_segunda_recta = segunda_recta.Pendiente();      
   
   ordenada_de_x = primera_recta.Ordenada_en(x);
   abscisa_de_y  = primera_recta.Abscisa_en(y);
   */
   
   
   //////////////////////////////////////////////////////////////////////
   // vs_5

   /*
   cout << "Introduzca los coeficientes de la recta Ax + By + C = 0\n";
   cin >> coef_x_primera_recta;
   cin >> coef_y_primera_recta;
   cin >> coef_indep_primera_recta;
   cout << "\nIntroduzca los coeficientes de la recta Ax + By + C = 0\n";
   cin >> coef_x_segunda_recta;
   cin >> coef_y_segunda_recta;
   cin >> coef_indep_segunda_recta;
   
   // Debemos crear los objetos DESPUÉS de leer los datos
   
   Recta_vs5 primera_recta(coef_x_primera_recta, coef_y_primera_recta, coef_indep_primera_recta);
   Recta_vs5 segunda_recta(coef_x_segunda_recta, coef_y_segunda_recta, coef_indep_segunda_recta);   
   
   cout << "\nIntroduzca un valor de abscisa\n";
   cin >> x;
   cout << "\nIntroduzca un valor de ordenada\n";
   cin >> y;
   
   // Podríamos modificar posteriormente los datos miembro llamando al método SetCoeficientes
   // primera_recta.SetCoeficientes(coef_x_primera_recta, coef_y_primera_recta, coef_indep_primera_recta);   
   // segunda_recta.SetCoeficientes(coef_x_segunda_recta, coef_y_segunda_recta, coef_indep_segunda_recta);
      
   pendiente_primera_recta = primera_recta.Pendiente();
   pendiente_segunda_recta = segunda_recta.Pendiente();      
   
   ordenada_de_x = primera_recta.Ordenada_en(x);
   abscisa_de_y  = primera_recta.Abscisa_en(y);
   */
   
   
   //////////////////////////////////////////////////////////////////////
   // vs_definitiva

   cout << "Introduzca los coeficientes de la recta Ax + By + C = 0\n";
   cin >> coef_x_primera_recta;
   cin >> coef_y_primera_recta;
   cin >> coef_indep_primera_recta;
   cout << "\nIntroduzca los coeficientes de la recta Ax + By + C = 0\n";
   cin >> coef_x_segunda_recta;
   cin >> coef_y_segunda_recta;
   cin >> coef_indep_segunda_recta;
   
   // Debemos crear los objetos DESPUÉS de leer los datos
   
   Recta primera_recta(coef_x_primera_recta, coef_y_primera_recta, coef_indep_primera_recta);
   Recta segunda_recta(coef_x_segunda_recta, coef_y_segunda_recta, coef_indep_segunda_recta);   
   
   cout << "\nIntroduzca un valor de abscisa\n";
   cin >> x;
   cout << "\nIntroduzca un valor de ordenada\n";
   cin >> y;
   
   // Podríamos modificar posteriormente los datos miembro llamando al método SetCoeficientes
   // primera_recta.SetCoeficientes(coef_x_primera_recta, coef_y_primera_recta, coef_indep_primera_recta);   
   // segunda_recta.SetCoeficientes(coef_x_segunda_recta, coef_y_segunda_recta, coef_indep_segunda_recta);
      
   pendiente_primera_recta = primera_recta.Pendiente();
   pendiente_segunda_recta = segunda_recta.Pendiente();      
   
   ordenada_de_x = primera_recta.Ordenada_en(x);
   abscisa_de_y  = primera_recta.Abscisa_en(y);
   

   cout << "\n\nPendiente de la recta 1: " << pendiente_primera_recta;
   cout << "\n\nPendiente de la recta 2: " << pendiente_segunda_recta;
   cout << "\n\nOrdenada de la recta 1 en " << x << " = " << ordenada_de_x;
   cout << "\n\nAbscisa  de la recta 1 en " << y << " = " << abscisa_de_y;
   
   cout << "\n\n";
   system ("pause");
}

