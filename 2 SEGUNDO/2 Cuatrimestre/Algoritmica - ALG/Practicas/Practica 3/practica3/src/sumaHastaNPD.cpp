#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>


using namespace std;
using namespace std::chrono;

// Subconjunto S de números que sume menor o igual que N




// Eficiencia de O(n²) ya que recorres la matriz para ir rellenandola


int Min(int n, int m){
    return (n < m)? n:m;
}


vector<int> sumaHastaNPD(const vector<int> & uno, int M){
    vector< vector <int> > tabla(uno.size() + 1, vector<int>(M + 1, 0));
    vector<int> res;


    for( int i = 0; i <= M; i++)
          tabla[0][i] = i;

 for( unsigned int i = 0; i <= uno.size(); i++)
        tabla[i][0] = 0;

    for(unsigned int i = 1; i <= uno.size(); i++){
        for( int j = 1; j <= M; j++){
            int elem = uno[i - 1];
            if(j - elem < 0){
                tabla[i][j] = tabla[i - 1][j];
            }else{
                tabla[i][j] = Min( tabla[i - 1][j - elem], // Incluye el valor
                                   tabla[i - 1][j]        // No lo incluye
                                 );
            }
        }
    }

    int m = M;
    for(int i = uno.size(); i > 0; i--){
        if(tabla[i][m] != tabla[i-1][m]){
            res.push_back(i - 1);
            m -= uno[i - 1];
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

    vector<int> res = sumaHastaNPD(uno, M);

    end =  high_resolution_clock::now();
        
    //el tiempo transcurrido es
    tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

    // Mostramos resultados
    cout << M << "\t" <<tiempo_transcurrido.count() << endl;

    // cout<< endl;
    
   // for(int i = 0; i < res.size(); i++){
   //     cout<< uno[res[i]] << "+";
   // }


  //  cout<< endl;

}