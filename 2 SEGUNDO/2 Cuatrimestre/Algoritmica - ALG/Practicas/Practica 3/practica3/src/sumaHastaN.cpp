#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>


using namespace std;
using namespace std::chrono;

// Subconjunto S de números que sume menor o igual que N
//  1º- Candidatos a seleccionar: Conjunto de números
//  2º- Candidatos seleccionados: Subconjunto de números
//  3º- Función solución: Suma <= N
//  4º- Función factible: El valor no se pasa de N
//  5º- Función selección: Siguiente número

// Eficiencia de O(n) ya que recorres el vector para ir haciendo la suma


vector<int> sumaHastaN(const vector<int> & uno, int M){
    vector<int> res;
    int suma = 0;
    unsigned int pos = 0;

    while(pos < uno.size() && suma <= M){
        int elem = uno[pos];
        pos++;

        if((suma + elem) <= M){
            suma += elem;
            res.push_back(elem);
        }
    }
    return res;
}




int main(int argc, char** argv){

    if(argc != 3){
        cerr<< "Escribe " << argv[0] << " <fichero-datos> <M>" << endl;
        exit(1);
    }

    vector<int> uno;
    fstream file;
    int dato, M = atoi(argv[2]);

    file.open(argv[1], fstream::in);

    while(file >> dato){
        uno.push_back(dato);
    }

    high_resolution_clock::time_point start, end;
    duration<double> tiempo_transcurrido;
    
    start = high_resolution_clock::now();

    vector<int> res = sumaHastaN(uno, M);

    end =  high_resolution_clock::now();
        
    //el tiempo transcurrido es
    tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

    // Mostramos resultados
    cout << M << "\t" <<tiempo_transcurrido.count() << endl;


}