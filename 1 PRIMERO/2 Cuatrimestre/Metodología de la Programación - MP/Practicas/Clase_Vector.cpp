#include <iostream>
using namespace std;

class Vector{
	private:
		float* v;
		int util;
	
	public:
		
	// CONSTRUCTOR POR DEFECTO
		Vector(){ 
			v = NULL;
			util = 0;			
		}

	// CONSTRUCTOR DE COPIA
		Vector(const Vector &vector){ // Si util > 0 crea vector y copia el vector del original m√°s el util
//Si util <= 0, no hay vector asi que simplemente lo asigna a NULL, te da igual asignarle otro util
			if(util > 0){
				util = vector.util;
		
				v = new float[vector.util];

				for(int i = 0; i < vector.util; i++){
					v[i] = vector.v[i];
				}	
			}else{
				v = NULL;
			}
		}

// DEVOLVER TAMA—O
		int Size()const{
			return util;
		}
		
// GET ELEMENTO DEL VECTOR

float getEle(int pos){
	return v[pos];
}

// COLOCAR ELEMENTO EN EL VECTOR

void setEle(float Ele, int pos){
	v[pos] = Ele;
}

		void push_back(float elemento){ //Se copia todo el vector en otro, ultimo elemento el que se quiera a√±adir, luego se borra el original, se aumenta util y se copia el auxiliar en un nuevo original
			float* aux;			
			aux = new float[util + 1];
			for(int i = 0; i < util; i++){
				aux[i] = v[i];
			}

			aux[util] = elemento;
		
			delete[] v;
			util++;
			v = aux;
		}

		void pop_back(){ //Si util > 1 (que al menos haya 2 elementos) copia v en el auxiliar quitando el ultimo elemento
//Si hay 1 o menos elementos, destruye el vector y util = 0
			if(util > 1){
				float* aux = new float[util - 1];
				
				for(int i = 0; i  < util; i++){
					aux[i] = v[i];
				}
				
				delete[] v;
				util--;
				v = aux;
			}else{
				delete[] v;
				v = NULL;
				util = 0;
			}	
		}

		//INSERTAR ELEMENTO DADA UNA POS

		void Insertar(float elemento, int pos){ //Copia hasta la posicion, pos = ele, copia el resto desde pos + 1 hasta util + 1 pero con j - 1, uno por detras para que no se salte un elemento
			float* aux = new float[util + 1];
		
			for(int i = 0; i < pos; i++){
				aux[i] = v[i];
			}
	
			v[pos] = elemento;

			for(int j = pos + 1; j < util + 1; j++ ){
					aux[j] = v[j - 1];
			}
				util++;
				delete[] v;
				v = aux;
		}
		
		// OBTENER NUM PARES DE UN VECTOR EN OTRO
		
		// 1∫ Forma
		Vector Vector::ObtenerPares1()const{
			Vector pares;
			
			for(int i = 0; i < util; i++){
				if(datos[i] % 2 == 0){
					pares.util++;
				}
			}
			
			pares.v = new float[pares.util];
			
			for(int i = 0; i < util; i++){
				if(datos[i] % 2 == 0){
					pares.v[pos] = datos[i];
					pos++;
				}
			}
			return pares;
		}
		
		// 2∫ Forma
		Vector Vector::ObtenerPares2(){ //Cada vez que encuentra un elemento, lo copia, lo redimensiona y elimina la versiÛn anterior
			Vecctor pares;
			
			for(int i = 0; i < util; i++){
				if(datos[i] % 2 == 0){
					float* aux;
					
					aux = new float[pares.util + 1];
					
					for(int k = 0; k < pares.util; k++){ // Este for copia los elementos que ya tienes
						aux[k] = pares.datos[k];						
					}
					
					delete[] pares.datos;
					pares.datos = aux;
					pares.util++;
				}
			}
			return pares;
		}

		// 3∫ Forma
		
		Vector Vector::ObtenerPares3(){ // Igual que la anterior pero al copiarlo usa push_back // La anterior hace lo mismo que push_back pero sin usarlo
			Vector pares;
			
			for(int i = 0; i < util; i++){
				if(datos[i] % 2 == 0){
					pares.push_back(datos[i]);
				}
			}
			return pares;
		}
};
