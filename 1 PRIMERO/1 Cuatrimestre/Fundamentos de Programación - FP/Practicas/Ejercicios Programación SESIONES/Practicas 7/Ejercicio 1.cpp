
//Funcion 1

int ValorAbsoluto (int entero){ //Está mal ya que le falta el return en caso de que se cumpla el if
		if (entero < 0)
			entero = -entero;
		else
			return entero; 
}

//Funcion 2

void Cuadrado (int entero)	{
	
		return entero*entero; //Como tiene return el valor retornado no puede ser un dato tipo void
		
}

//Funcion 3

void Imprime (double valor) { //Se declara dos veces la variable
		double valor;
		
			cout << valor;
	}
	
	//Funcion 4
	
	bool Espositivo(int valor)	{
		if (valor > 0)
			return true; //Faltaría la opcion false de la variable en caso de no cumplirse el if
			
}
