#include "mutacion.h"
#include "enfermedad.h"
#include "clinvar.h"
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

int main(int argc, char *argv[]){

    ClinVar clinvar;
    string busqueda;


    const char* nombreArchivo = "datos/clinvar_20160831.vcf"; // El archivo se guarda en datos (En el mismo directorio que el programa)

    // cout<< "Abriendo el archivo " << nombreArchivo << endl << endl;
    // //Cargar las mutaciones en clinvar
    // mutacion una;
    // una = clinvar.load(nombreArchivo); // Para poder hacer pruebas
    //
    //
    // // //Imprimir número de elementos almacenados en clinvar (130867 mutaciones totales)
    // cout << "Lectura del fichero finalizada. Mutaciones cargadas: " << clinvar.size() << endl;
    // clinvar.LecturaFichero();
    // cout<< endl;
    //
    // cout<< una;
    //
    // cout<< "---------------------------------------" << endl;
    // cout<< "Prueba - Insert" << endl;
    // clinvar.insert(una);
    // cout << "Lectura del fichero finalizada. Mutaciones cargadas: " << clinvar.size() << endl;
    // clinvar.LecturaFichero();
    // cout<< endl;
    //
    // cout<< "---------------------------------------" << endl;
    // cout<< "Get-Enfermedades:" << endl;
    //
    // vector<enfermedad> uno = clinvar.getEnfermedades(una);
    // for(int i = 0; i < uno.size(); i++){
    //   cout<< uno[i] << endl;
    // }
    // cout<< "---------------------------------------" << endl;
    // cout<< "Prueba - find_mut" << endl;
    //
    // ClinVar::mut_iterator unoit;
    // cout<< una.getID() << endl;
    // unoit = clinvar.find_mut(una.getID());
    // cout<< *unoit << endl;
    // cout<< endl;
    //
    // cout<< "---------------------------------------" << endl;
    // cout<< "Prueba - find_Enf" << endl;
    //
    // enfermedad_iterator unit;
    // unit = clinvar.find_Enf(una.getEnfermedades()[0].getID());
    // cout<< unit->second << endl;
    // cout<< endl;
    //
    // cout<< "---------------------------------------" << endl;
    // cout<< "Prueba - getEnfermedades -keyword" << endl;
    // list<IDenf> res;
    // res =  clinvar.getEnfermedades("basal");
    // for(list<IDenf>::iterator it = res.begin(); it != res.end(); it++){
    //   cout<< *it << endl;
    // }
    // cout<< "---------------------------------------" << endl;
    // cout<< "Prueba- getMutacionesEnf" << endl;
    //
    // set<IDmut> rres;
    // rres = clinvar.getMutacionesEnf(una.getEnfermedades()[0].getID());
    // for(set<IDmut>::iterator un = rres.begin(); un != rres.end(); un++){
    //   cout<< *un << endl;
    // }
    // cout<< "---------------------------------------" << endl;
    // cout<< "Prueba - getMutacionesGen" << endl;
    // set<IDmut> setres;
    // setres = clinvar.getMutacionesGen("XPR1:9213");
    // for(set<IDmut>::iterator uno = setres.begin(); uno != setres.end(); uno++){
    //   cout<< *uno << endl;
    // }
    // cout<< "---------------------------------------" << endl;
    // cout<< "Prueba - topKMutaciones" << endl;
    //
    // set<mutacion, ClinVar::ProbMutaciones> foo;
    // foo = clinvar.topKMutaciones(5, "cancer");
    //
    // for(set<mutacion, ClinVar::ProbMutaciones>::iterator u = foo.begin(); u != foo.end(); u++){
    //   cout<< *u << endl;
    // }
    //
    // cout<< "---------------------------------------" << endl;
    // cout<< "Prueba de lower_bound" << endl;
    // ClinVar::mut_iterator lb;
    // lb = clinvar.lower_bound(una.getChr(), una.getPos());
    // cout<< *lb << endl;
    // cout<< "---------------------------------------" << endl;
    // cout<< "Prueba de upper_bound" << endl;
    // ClinVar::mut_iterator ub;
    // ub = clinvar.upper_bound(una.getChr(), una.getPos());
    // if(ub != clinvar.end())
    //   cout<< *ub << endl;
    // cout<< "---------------------------------------" << endl;
    //
    // cout << endl;
    // cout<< "Prueba - Erase" << endl;
    // clinvar.erase(una.getID());
    // cout << "Lectura del fichero finalizada. Mutaciones cargadas: " << clinvar.size() << endl;
    // clinvar.LecturaFichero();
    // cout<< endl;
    // cout<< "---------------------------------------" << endl;

}
