#include "mutacion.h"
#include "enfermedad.h"
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

/** @brief Carga un vector de mutaciones con mutaciones leidas desde un fichero
*  @param vm vector de mutaciones a cargar por referencia
*  @param s cadena con el nombre del fichero
*  @return resultado de la lectura
*/

bool load(vector<mutacion> &  vm, const string & s) {
 ifstream fe;
 string cadena;

 cout << "Abrimos "<< s << endl;
 fe.open(s.c_str(), ifstream::in);
 if (fe.fail()){
   cerr << "Error al abrir el fichero " << s << endl;
 }
 else {
    //leo la cabecera del fichero (líneas que comienzan con #)
    do{
      getline(fe,cadena,'\n');
    }while (cadena.find("#")==0 && !fe.eof());
    
    //leo la tabla de mutaciones, una línea cada vez
    while ( !fe.eof() ){

        mutacion mut = mutacion(cadena);      // Invoco el constructor de mutación que recibe una cadena completa, la parsea y crea la mutación.
        vm.push_back(mut);                   // Insertar mutación en el vector

        getline(fe,cadena,'\n');            // Se lee la siguiente cadena
    }
    fe.close();
    return true;
  }
  fe.close();
  return false;
 }

 /** @brief Cuenta el numero de veces que aparece la mutacion
 *  @param vm vector de mutaciones
 *  @param s cadena con la mutacion a buscar
 *  @return numero de apariciones
 */


int cuentaMutacionesEnfermedad(vector<mutacion> &  vm, const string & s) {

  vector <enfermedad> enfermedades; //para almacenar las enfermedades asociadas a cada mutación
  int cont_mutaciones = 0;          //para almacenar el número de mutaciones asociadas a enfermedades que contienen s
  bool esta;

  for (int i = 0; i < vm.size(); i++){    //recorrer vector de mutaciones vm
    esta = false;
    // para cada mutación, obtener sus enfermedades asociadas:
    enfermedades = vm[i].getEnfermedades();
    // recorrer el vector de enfermedades para ver si hay alguna cuyo nombre esta s
    int contador = 0;
    while (contador < enfermedades.size()){
      //utilizar el método enfermedades[j].nameContains(s)
      if(enfermedades[contador].nameContains(s)){
        esta = true;
      }
      contador++;
    }
    // si alguna enfermedad de enfermedades estaba asociada a s, incrementar contador.
    if(esta)
      cont_mutaciones++;
  }

  return cont_mutaciones;
}


/** @brief Lee un fichero con mutaciones
*  @param query_str mutacion a buscar, por defecto "cancer"
*
*  @return resultado de la lectura y numero de apariciones
*/

int main(int argc, char *argv[]){

    vector<mutacion> vectorSNPs;
    string query_str;

    if (argc>1){
      query_str = argv[1];      //Término de búsqueda indicado por el usuario
    }else{
      query_str = "cancer";     //Default query: "cancer"
    }

    //Cargar las mutaciones en vectorSNPs
    load(vectorSNPs, "clinvar_20160831.vcf");

    //Imprimir número de elementos almacenados en vectorSNPs (130867 mutaciones totales)
    cout << "Lectura del fichero finalizada. Mutaciones cargadas: "<<vectorSNPs.size()<<endl;

    //Imprimir cuántas mutaciones están asociadas a la enfermedad indicada en query_str
    cout << "Mutaciones asociadas a " <<query_str <<": "<< cuentaMutacionesEnfermedad(vectorSNPs, query_str)<< endl;

   return 0;
}
