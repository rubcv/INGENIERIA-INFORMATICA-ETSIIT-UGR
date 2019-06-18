// EXAMEN FEBRERO 2015 

/* Un intervalo es un espacio metrico comprendido entre dos cotas, a las cotas las llamamos a y b, siendo a la cota inferior y b la superior.
Cada extremo puede ser abierto o cerraso y se denota por () o []. Para la cota inferior solo se usa ( o [ y para la superior ) o ].
Ejemplos: (a,b]={x perteneciente a R tq a <=x <=b

Se quiere implementar la clase intervalo.
*/

// a) Datos miembros y constructores

class Intervalo{
	private:
		double a;
		double b;
		bool a_abierto;
		bool b_abiero;
		
		bool IntervaloCorrecto(double inf, double sup){
			if (inf<=sup)
				return true;
			return false;
		}
		
	public:
		Intervalo(double inf, double sup, bool inf_abierto, bool sup_abierto){
			if (IntervaloCorrecto(inf, sup)){
				a=inf;
				b=sup;
				a_abierto=inf_abierto;
				b_abierto=sup_abierto;
			}else{
				a!=0;
				b!=0;
				a_abierto=true;
				b_abierto=true;
				}
		 :Intervalo(inf,sup,false,false);
		
		}
		Intervalo (double inf, double sup)
		Intervalo()
			:Intervalo(0,0,true,true);
			
			
			
		
