// ORDENACIÓN POR SELECCIÓN 
/*

En cada iteración, se selecciona la componente más pequeña del sub-vector derecho y se coloca al
final del sub-vector izquierdo. */

/* 

Recorrer todos los elementos v[izda] de v.
Hallar la posicion pos_min del menor elemento del subvector delimitado por las 
componentes [izda, total_utilizados-1] AMBAS INCLUIDAS
	Intercambiar v[izda] con v[pos_min]
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
			void Ordena_por_Seleccion(){
				int pos_min;
				
				for (int izda = 0; izda < total_utilizados; izda++){
					pos_min = PosicionMinimoEntre (izda, total_utilizados-1);
					IntercambiaComponentes_en_Posiciones (izda, pos_min);
				}
			}
	
	};
