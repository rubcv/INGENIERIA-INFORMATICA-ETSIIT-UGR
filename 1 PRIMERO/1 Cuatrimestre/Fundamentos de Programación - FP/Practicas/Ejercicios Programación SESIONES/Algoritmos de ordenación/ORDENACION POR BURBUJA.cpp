// ORDENACION POR INTERCAMBIO DIRECTO 
// METODO DE LA BURBUJA


/* Al igual que
antes, a la izquierda se va dejando un subvector ordenado. Desde el final
y hacia atrás, se van comparando elementos dos a dos y se deja a la
izquierda el más pequeño (intercambiándolos)

Ir fijando el inicio del subvector derecho con un contador izda desde 0 hasta total_utilizados-1
	Recorrer el subvector de la derecha desde el final hasta el principio (izda) con un contador i
	
	Si v[i] < v[i-1], intercambiarlos
	*/ 
	
	
class SecuenciaCaracteres{
	private:
		const int TAMANIO = 50;
		char vector_privado[TAMANIO];
		int total_utilizados;
		
		
		void IntercambiaComponentes_en_Posiciones(int pos_izda, int pos_dcha){
			char intercambia;
			
			intercambia = vector_privado[pos_izda];
			vector_privado[pos_izda] = vector_privado[pos_dcha];
			vector_privado[pos_dcha] = intercambia;
		}
		
	public:
		.........
		void Ordena_por_Burbuja(){
			int izda, i;
			bool cambio;
			
			cambio=true;
			
			
				for ( izda = 0; izda < total_utilizados && cambio; izda++){
					for ( i = total_utilizados-1 ; i > izda; i--){
						if (vector_privado[i] < vector_privado[i-1]){
							IntercambiaComponentes_en_Posiciones(i, i-1);
						}
						
					}
				}
		}
};
