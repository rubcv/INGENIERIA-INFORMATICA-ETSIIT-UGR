#include "mutacion.h"
#include "enfermedad.h"
#include "conjunto.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;


  /* -------------------- FUNCTORES ------------------------ */


  // /* Conjunto de mutacion por cromosoma/posicion creciente */
  // class CrecienteChrPos{
  //   public:
  //     bool operator()(const mutacion &a, const mutacion &b){
  //        return !(( a.getChr() < b.getChr() ) && ( a.getPos() < b.getPos() ));
  //     }
  // };
  //
  //
  // /* Conjunto de mutaciones por cromosoma/posicion decreciente */
  // class DecrecienteChrPos{
  //   public:
  //     bool operator()( const mutacion &a, const mutacion &b){
  //    		   return ( ( a.getChr() < b.getChr() ) && ( a.getPos() < b.getPos() ) );
  //   	}
  //   };
  //
  //   /* Conjunto de mutacion por ID creciente */
  //   class CrecienteID{
  //     public:
  //     	bool operator()(const mutacion &a, const mutacion &b){
  //     		return (a.getID() < b.getID());
  //     	}
  //   };
  //
  //   /* Conjunto de mutacion por ID decreciente */
  //   class DecrecienteID{
  //     public:
  //     	bool operator()(const mutacion &a, const mutacion &b){
  //     		return !(a.getID() < b.getID());
  //     	}
  //   };
  //
  //   /* Conjunto de mutacion por enfermedad creciente */
  //   class CrecienteEnfermedad{
  //     public:
  //     	bool operator()(const mutacion &a, const mutacion &b){
  //     		return (a.getEnfermedades() < b.getEnfermedades());
  //     	}
  //   };
  //
  //   /* Conjunto de mutacion por ID decreciente */
  //   class DecrecienteEnfermedad{
  //     public:
  //     	bool operator()(const mutacion &a, const mutacion &b){
  //     		return !(a.getEnfermedades() < b.getEnfermedades());
  //     	}
  //   };

	/** @brief lee un fichero de mutaciones, linea a linea
	@param[in] s nombre del fichero
  @param[in,out] cm objeto tipo conjunto sobre el que se almacenan las mutaciones
	@return true si la lectura ha sido correcta, false en caso contrario
	*/

const int TOPE = 1000; // Modificar segun del tamaño del que se quiera hacer la lectura
int con = 0; // PARA EVALUAR SIN TENER QUE HACER UNA LECTURA COMPLETA

template<class CMP>
bool load(conjunto<mutacion,CMP> &  cm, const string & s) {
 ifstream fe;
 string cadena;

 cout << "\nAbrimos "<< s << endl; // << ---- COMENTAR Para las pruebas de eficiencia, que no se escriba en el *.dat
 fe.open(s.c_str(), ifstream::in);
 if (fe.fail()){
   cerr << "\nError al abrir el fichero " << s << endl;
 }
 else {
    //leo la cabecera del fichero (líneas que comienzan con #)
    do{
      getline(fe,cadena,'\n');
    }while (cadena.find("#")==0 && !fe.eof());


    //leo la tabla de mutaciones, una línea cada vez
    while ( !fe.eof() && con < TOPE ){
        //cout << "leo:: "<< cadena << endl;
        // Invoco el constructor de mutación que recibe una cadena completa, la parsea y crea la mutación.
        mutacion mut = mutacion(cadena);
        // Insertar mutación en el conjunto
        cm.insert(mut);
        getline(fe,cadena,'\n');
        //con++; // Incremento en cada lectura << ----- DESCOMENTAR PARA LECTURA CONTROLADA
    }
    fe.close();
    return true;
  } // else
  fe.close();
  return false;
 }

 template <typename T>
int distanciaIntervalo( T iterA, T iterB){
 int cont = 0;
  while(iterA != iterB){
    cont++;
    iterA++;
  }
  return cont;
}

int main(int argc, char *argv[]){

  conjunto<mutacion, less<mutacion> > cm;

  cout<< "Cargamos el fichero: " << endl;
  load(cm,"clinvar_20160831.vcf");
  cout << "Lectura del fichero finalizada. Mutaciones cargadas: " << cm.size() <<endl;

  mutacion una, otra;

  auto it = cm.find(*cm.begin());

  if (it == cm.end()){
    cout<< "No esta " <<endl;
  }else{
    cout<< (*it).getID() << " "  << (*it).getPos() << endl;
  }


  una.setPos(0);
  una.setChr("3");

  otra.setPos(0);
  otra.setChr("4");

  cout << "En rango "<< distanciaIntervalo(cm.lower_bound(una),cm.lower_bound(otra)) << endl;
  it = cm.end();
  for(int i=0;i<7;i++){
    --it;
  }
  cm.erase(it);

  cout << cm.size()<< endl;
  cout << cm.erase(una) << endl;
  int i=0;
  for (mutacion m :cm){
      //if (i%10==0)
      cout << m <<endl;
    i++;
}

// ----------------------------------------


	conjunto<mutacion,greater<mutacion> > cmg;

	cout << "Lectura decreciente: " <<endl;
    load(cmg,"clinvar_20160831.vcf");
   i = 0;
   cout << cmg.size() << endl;

  cout << cmg << endl;

    cout << "Posiciones Impares" <<endl;
   for (auto iti = cmg.ibegin();iti != cmg.iend(); ++iti)
        cout << *iti <<endl;

   conjunto<mutacion,greater<mutacion> >::secure_iterator sit = cmg.send();
   --sit;
 // Borro 10 elementos;
   for(int i=0;i<10;i++){
       cmg.erase(cmg.end()--);
    }

   cout << *sit << endl; // Iterador no valido, debe abortar
    cin >> i;


//
//   // Distintos conjuntos con su determinado orden (Cambiar)
//
//   conjunto < mutacion, CrecienteChrPos >  conjuntoMutaciones;
//   // conjunto < mutacion, DecrecienteChrPos >  conjuntoMutaciones;
//   // conjunto < mutacion, CrecienteID >  conjuntoMutaciones;
//   // conjunto < mutacion, DecrecienteID >  conjuntoMutaciones;
//   // conjunto < mutacion, CrecienteEnfermedad >  conjuntoMutaciones;
//   // conjunto < mutacion, DecrecienteEnfermedad > conjuntoMutaciones;
//
//
//   string query_str;
//
//
//     high_resolution_clock::time_point tantes, tdespues; // Para ver la eficiencia
//     duration<double> tiempo_transcurrido;
//
// /* ------------ Carga del conjunto mutaciones por orden determinado ---------------- */
//
//     //Cargar las mutaciones en vectorSNPs
//     load(conjuntoMutaciones, "clinvar_20160831.vcf"); // Cargado en el conjunto con orden determinado greater de mutacion
//
//
//
//
//   /* Cada ejercicio separado */
//   cout<< endl << endl;
//
//
//                       // ---- INICIO DE SALIDA ----
//
//   //Imprimir número de elementos almacenados en conjuntoMutaciones
//   cout << "\nLectura del fichero finalizada. Mutaciones cargadas: "<<conjuntoMutaciones.size()<<endl;
//
// // -------------------------------------------------------------------------------------------------------------
//     cout<< endl << endl;
//     //Imprimir cuántas mutaciones están asociadas al cromosoma 1:
//     cout << "\n----Mutaciones asociadas a Chr 1: ----"<< endl;
//
//     // Se usa lower_bound, devuelve iterador a ele >= que chr
//     // desde begin() hasta el iterador devuelto se imprimen todas las mutaciones o se cuentan las que
//     // hay
//     //
//     int total = conjuntoMutaciones.getMutaciones(conjuntoMutaciones.lower_bound("1", 1), true);
//     cout<< "\nHay: " << total << " mutaciones" << endl;
//
// // -------------------------------------------------------------------------------------------------------------
//     cout<< endl << endl;
//     // /**@todo ¿Existe la mutación con ID "rs147165522"? Imprimir la mutación y las enfermedades asociadas */
//     //
//     cout<< "\n---- Mutaciones con el ID: rs147165522 ----" << endl;
//
//     pair<conjunto::value_type, bool> id = conjuntoMutaciones.find("rs147165522");
//
//     if(id.second){ // Si true, first inicializado luego se imprime
//      cout<< id.first << endl;
//    }else{
//      cout<< "\nNo exite la mutacion" << endl;
//    }
//
// // -------------------------------------------------------------------------------------------------------------
//     cout<< endl << endl;
//     //
//     // /**@todo ¿Existe la mutación en chr/pos "14"/67769578? Imprimir la mutación y las enfermedades asociadas */
//     //
//     cout<< "\n---- Mutacion con chr/pos 14/67769578: ----" << endl;
//
//     pair<conjunto::value_type, bool> chrpos = conjuntoMutaciones.find("14", 67769578);
//
//     if(chrpos.second){ // Si true, first inicializado luego se imprime
//       cout<< chrpos.first << endl;
//     }else{
//       cout<< "\nNo existe la mutacion" << endl;
//     }
//
//
// // -------------------------------------------------------------------------------------------------------------
//
//     cout<< endl << endl;
//     /**@todo ¿Cómo podríamos calcular el número de mutaciones del cromosoma 3? (utiliza lower_bound / upper_bound) */
//     /*Buscar las que estan por encima de 3 y restar las que estan por debajo*/
//
//     int parte1 = conjuntoMutaciones.getMutaciones(conjuntoMutaciones.lower_bound("2",1), true); // Contamos mutaciones de [1-2]
//     int parte2 = conjuntoMutaciones.getMutaciones(conjuntoMutaciones.upper_bound("3",1), false); // Contamos mutaciones de [4-total]
//     int resultado = conjuntoMutaciones.size() - (parte1 + parte2); // Mut de 3 = Total - ([1-2] + [4-Total])
//
//     cout<< "\n---- Mutacion con chr 3: ----" << endl;
//     cout<< "\nHay: " << resultado << " mutaciones del cromosoma 3" << endl;
//     cout<< endl;
//     cout<< endl << endl;

// -------------------------------------------------------------------------------------------------------------

  // ---- FIN DE SALIDA ----

    /**@todo Analiza la eficiencia teórica y empírica de las operaciones find, insert y erase */

    /* Pruebas de eficiencia:
      - Descomentar la que se quiera hacer
      - Comprobar que se hace el incremento-> "con"
      - Comprobar que la linea de "Leido correctamente" no se imprime(comentar) en *.dat para dibujar con gnuplot
      - Ver si se leen todos los datos o solo una parte
    */

    //
    // con = 0;
    //
    // while(con < TOPE){ // Para evaluar cada operacion varias veces
    //
    //   /* ---- FIND --- */
    //   tantes = high_resolution_clock::now(); // Tiempo antes
    //   conjuntoMutaciones.find("rs147165522");
    //   tdespues = high_resolution_clock::now(); // Tiempo despues
    //
    //   tiempo_transcurrido  = duration_cast<duration<double> >(tdespues - tantes);
    //   cout << con << " " << tiempo_transcurrido.count() << endl;
    //
    //   /* ---- INSERT ---- */
    //   // tantes = high_resolution_clock::now(); // Tiempo antes
    //   // conjunto::value_type una; // Mutacion a insertar
    //   // conjuntoMutaciones.insert(una);
    //   // tdespues = high_resolution_clock::now(); // Tiempo despues
    //   //
    //   // tiempo_transcurrido  = duration_cast<duration<double> >(tdespues - tantes);
    //   // cout << con << " " << tiempo_transcurrido.count() << endl;
    //
    //   /* ---- ERASE ---- */
    //   // tantes = high_resolution_clock::now(); // Tiempo antes
    //   // conjuntoMutaciones.eraseChr("1"); // Borramos mutaciones con chr = 1 (Para poder hacer varias eliminaciones)
    //   // tdespues = high_resolution_clock::now(); // Tiempo despues
    //   //
    //   // tiempo_transcurrido  = duration_cast<duration<double> >(tdespues - tantes);
    //   // cout << con << " " << tiempo_transcurrido.count() << endl;
    //
    //   con+= 50; // Incremento
    // }

}
