// ORDENACIÓN POR INSERCIÓN

/*
El vector se divide en dos subvectores: el de la izquierda ordenado, y el de la derecha desordenado.
Cogemos el primer elemento del subvector desordenado y lo insertamos
de forma ordenada en el subvector de la izquierda (el ordenado)

Nota. La componente de la posición(primer elemento del subvector
desordenado) será reemplazada por la anterior (después de desplazar)


Ir fijando el inicio del subvector derecho con un índice
izda (desde 1 hasta total_utilizados-1)
	Seleccionar el valor v[izda]
	Insertar dicho valor de forma ordenada en el subvector izquierdo
	
	*/
	
	class SecuenciaCaracteres{
		private:
			const int TAMANIO = 50;
			char vector_privado[TAMANIO];
			int total_utilizados;
		public:
			........
			
			void Ordena_por_Insercion(){
				int izda, i;
				char a_desplazar;
				
				for ( izda = 1; izda < total_utilizados; izda++){
					a_desplazar = vector_privado[izda];
					
					
					for ( i = izda; i > 0 && a_desplazar < vector_privado[i-1]; i--){
						vector_privado[i] = vector_privado[i-1];
					}
					
					vector_privado[i] = a_desplazar;
				}
			}
	
	};
