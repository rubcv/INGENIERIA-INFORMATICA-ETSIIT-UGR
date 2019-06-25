/* SumaVectoresCpp.cpp  
 Suma de dos vectores: v3 = v1 + v2
 
 Para compilar usar (-lrt: real time library):  
		g++  -O2 SumaVectoresCpp.cpp -o SumaVectoresCpp -lrt

 Para ejecutar use: SumaVectoresCpp longitud
*/ 

#include <cstdlib>	 // biblioteca con atoi()
#include <iostream>	// biblioteca donde se encuentra la función cout
using namespace std;
#include <time.h>	  // biblioteca donde se encuentra la función clock_gettime() 

//#define COUT_ALL	// comentar para quitar el cout ...
			                 // que imprime todos los componentes

//Sólo puede estar definida una de las tres constantes VECTOR_ (sólo uno de los ... 
//tres defines siguientes puede estar descomentado):
//#define VECTOR_LOCAL	// descomentar para que los vectores sean variables ...
			                     // locales (si se supera el tamaño de la pila se ...
			                     	// generará el error "Violación de Segmento")
//#define VECTOR_GLOBAL// descomentar para que los vectores sean variables ...
			                     // globales (su longitud no estará limitada por el ...
			                     // tamaño de la pila del programa)
#define VECTOR_DYNAMIC	// descomentar para que los vectores sean variables ...
						                   // dinámicas (memoria reutilizable durante la ejecución)
#ifdef VECTOR_GLOBAL
#define MAX 33554432	//=2^25
double v1[MAX], v2[MAX], v3[MAX]; 
#endif
  
int main(int argc, char** argv){ 
  
  struct timespec cgt1,cgt2;   //para tiempo de ejecución

  //Leer argumento de entrada (nº de componentes del vector)
  if (argc<2){
    cout << "Faltan nº componentes del vector\n" << endl ;
    exit(-1);
  } 

  unsigned int N = atoi(argv[1]);
  #ifdef VECTOR_LOCAL
  double v1[N], v2[N], v3[N];   
  #endif
  #ifdef VECTOR_GLOBAL
  if (N>MAX) N=MAX;
  #endif
  #ifdef VECTOR_DYNAMIC
  double *v1, *v2, *v3;
  v1 = new double [N];    //si no hay espacio suficiente new genera una excepción
  v2 = new double [N];
  v3 = new double [N];
  #endif

  //Inicializar vectores 
  for(int i=0; i<N; i++){ 
    v1[i] = N*0.1+i*0.1; v2[i] = N*0.1-i*0.1; //los valores dependen de N
  } 
 
  clock_gettime(CLOCK_REALTIME,&cgt1);
  //Calcular suma de vectores 
  for(int i=0; i<N; i++) 
    v3[i] = v1[i] + v2[i]; 
 
  clock_gettime(CLOCK_REALTIME,&cgt2);
  double ncgt=(double) (cgt2.tv_sec-cgt1.tv_sec)+
       (double) ((cgt2.tv_nsec-cgt1.tv_nsec)/(1.e+9));

  //Imprimir resultado de la suma y el tiempo de ejecución
  #ifdef COUT_ALL
  cout << "Tiempo(seg.):" << ncgt << "\t/ Tamaño Vectores:" << N << endl;
  for(int i=0; i<N; i++) 
      cout << "/ V1[" << i << "]+V2[" << i << "]=V3" << i << "](" << v1[i] << "+" << v2[i] << "=" 
      << v3[i] << ") /\t" << endl; 
  cout <<"\n"<< endl;
  #else
      cout << "Tiempo(seg.):" << ncgt << "\t/ Tamaño Vectores:" << N << "\t/ V1[0]+V2[0]=V3[0](" 
      << v1[0] << "+" << v2[0] << "=" << v3[0] << ") / / V1[" << N-1 << "]+V2[" << N-1 << "]=V3[" 
      << N-1 << "](" << v1[N-1] << "+" << v2[N-1] << "=" << v3[N-1] << ")/\n" << endl;
  #endif

  #ifdef VECTOR_DYNAMIC
  delete [] v1; // libera el espacio reservado para v1
  delete [] v2; // libera el espacio reservado para v2
  delete [] v3; // libera el espacio reservado para v3
  #endif
  return 0; 
}
