#include <iostream>

using namespace std;

class Ventas{
	private:
		int unds[100], empresas[100];
		int contEmpr = 0;
	public:
		//Prec: unidades >= 0 && 100 >= Sucursal > 0
		void SetUnidades(int sucursal, int unidades){ 
			if(contEmpr != 0){
				bool flag = true;
				int tamanho = contEmpr;
				for(int i = 0; i <= tamanho; i++){
					if(empresas[i] == sucursal){
						unds[sucursal] += unidades;
						flag = false;
					}
				}
				if(flag){
					empresas[contEmpr] = sucursal;
					unds[sucursal] = unidades;
					contEmpr++;
				}
			}else{
				empresas[contEmpr] = sucursal;
				unds[sucursal] = unidades;
				contEmpr++;
			}
		}
		int GetVentasMax(){
			int aux = -1;
			for(int i = 0; i < contEmpr; i++){
				int posicion = empresas[i];
				if(unds[posicion] > aux){
					aux = unds[posicion];
				}
			}
			return aux;
		}
		int GetSucursalMax(){
			int auxVentas = -1, auxSucursal = -1;
			for(int i = 0; i < contEmpr; i++){
				int posicion = empresas[i];
				if(unds[posicion] > auxVentas){
					auxVentas = unds[posicion];
					auxSucursal = posicion;
				}
			}
			return auxSucursal;
		}
};

int main() {
  	int sucursal, unidades;
  	char producto;
  	Ventas ventas_empresa;
  	do{
  		do{
			cout << "Introduce la sucursal(-1 para salir): ";
	  		cin >> sucursal;
		}while(sucursal < -1);
	  	if(sucursal!=-1){
			do{
				cout << "Introduce el codigo del producto (a, b, c): ";
				cin >> producto;
			}while(producto!='a' && producto!='b' && producto!='c');
			do{
				cout << "Introduce el numero de unidades: ";
				cin >> unidades;
			}while(unidades < 0);
			ventas_empresa.SetUnidades(sucursal, unidades);
		}
	}while(sucursal!=-1);
	
	cout << "\nLa sucursal es " << ventas_empresa.GetSucursalMax() << " con " << ventas_empresa.GetVentasMax() << " unidades" << endl;
		
  	system("pause");
   return 0;
}
