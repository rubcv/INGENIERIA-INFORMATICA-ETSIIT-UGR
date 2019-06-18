#include <iostream>
using namespace std;

class SecuenciaReal{
	
	private:
		static const int MAX = 100;
		float vector_privado[MAX];
		int util;
		
	public:
		
		float Suma(){
			double resultado = 0;
			int i;
			
			for(i = 0; i < util; i++){
				resultado += vector_privado[i];
			}
		
			return resultado;
		}
			
		void Aniade(float nuevo){
			if (util < MAX){
				vector_privado[util] = nuevo;
				util++;
			}
		}
		

		SecuenciaReal simetrica(){
		
			SecuenciaReal local;
			
			int i;
			
			for (i = util -1; i >= 0; i--){
				local.Aniade(vector_privado[i]);
				return local;
			}
		}
};


int main(){
	
SecuenciaReal una;

	una.Aniade(3.1);
	una.Aniade(5.2);
	una.Aniade(9.7);


	cout<< una.Suma();











return 0;
}

