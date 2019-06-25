#include <iostream>
#include <chrono>
#include <vector>
#include <fstream>
#include <utility>
#include <algorithm>

using namespace std;
using namespace std::chrono;

// Obtener M con el subconjunto S y las operaciones
//  1º- Candidatos a seleccionar: Conjunto de números y operaciones
//  2º- Candidatos seleccionados: Subconjunto de números y operaciones
//  3º- Función solución: El subconjunto seleccionado en combinacion con las operaciones da M
//  4º- Función factible: La división no es entre 0 y no da distinto de 0
//  5º- Función selección: Siguiente número y operación

// Eficiencia de O(n²)


void QuickSort(vector<int> &A,int izq, int der )
{ 
int i, j, x , aux; 
i = izq; 
j = der; 
x = A[ (izq + der) /2 ]; 
    do{ 
        while( (A[i] > x) && (j <= der) )
        { 
            i++;
        } 
 
        while( (x > A[j]) && (j > izq) )
        { 
            j--;
        } 
 
        if( i <= j )
        { 
            aux = A[i]; A[i] = A[j]; A[j] = aux; 
            i++;  j--; 
        }
         
    }while( i <= j ); 
 
    if( izq < j ) 
        QuickSort( A, izq, j ); 
    if( i < der ) 
        QuickSort( A, i, der ); 
}

bool Factible(int ele, int M, int ele2){
    return (abs(M - ele) > abs(M - ele2));
}


int Operacion(int res, int ele, char op){
    if(op == '+'){
        return res + ele;
    }
    if(op == '-'){
        return res - ele;
    }
    if(op == '*'){
       if(ele != 0){
          return res * ele;
       }
    }
    if(op == '/'){
        if(ele != 0 && res/ele == 0){
            return res / ele;
        }
    }
    return res;
}

pair<vector<int>::iterator, char> Seleccionar(const int res_operacion, vector<int>& uno, vector<char> op, int M){
    vector<pair<pair<int, int>, char> > operaciones;

    for(unsigned int i = 0; i < op.size(); i++){
        for(unsigned int j = 0; j < uno.size(); j++){
            int res = Operacion(res_operacion, uno[j], op[i]);
            operaciones.push_back(make_pair(make_pair(uno[j], res), op[i]));
        }
    }
    int elem = operaciones[0].first.first;
    int mas_cercano = operaciones[0].first.second; char operacion = operaciones[0].second;
    for(unsigned int i = 1; i < operaciones.size(); i++){
        if(Factible( mas_cercano,  M , operaciones[i].first.second)){    
             mas_cercano = operaciones[i].first.second;
             operacion = operaciones[i].second;
             elem = operaciones[i].first.first;
        }
    }
    
    pair<vector<int>::iterator, char>  p;
    vector<int>::iterator itt = find(uno.begin(), uno.end(), elem);  
    p.first = itt;
    p.second = operacion;
    return p;
}


bool HacerOperacion(int& res, int& ele, char op){
    if(op == '+'){
        res += ele;
        return true;
    }
    if(op == '-'){
        res -= ele;
        return true;
    }
    if(op == '*'){
        if(ele != 0){
          res *= ele;
          return true;
       }
    }
    if(op == '/'){
        if(ele != 0 && res/ele == 0){
            res /= ele;
            return true;
        }
    }
    return false;
}

vector<pair<int, char> > cifrasV(vector<int> & uno, const vector<char> & operaciones, int M){
     vector<pair<int, char> > res;
     QuickSort(uno, 0, uno.size()-1);

     int res_operacion = 0;
     int res_previo = 0;
     while(uno.size() && res_operacion != M){
         pair<vector<int>::iterator, char> x = Seleccionar(res_operacion, uno, operaciones, M);
         
         vector<int>::iterator it = x.first;
         res_previo = res_operacion;
         if(it != uno.end() && HacerOperacion(res_operacion, *it, x.second)){
            if(Factible(res_previo, M, res_operacion)){
                res.push_back(make_pair(*it, x.second));
            }else{
                res_operacion = res_previo;
            }
         }
         it = uno.erase(it);
         
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

  
    vector<char> operaciones;
    operaciones.push_back('+');
    operaciones.push_back('-');
    operaciones.push_back('*');
    operaciones.push_back('/');

    high_resolution_clock::time_point start, end;
    duration<double> tiempo_transcurrido;
    
    start = high_resolution_clock::now();

    vector<pair<int, char> > res = cifrasV(uno, operaciones, M);

    end =  high_resolution_clock::now();
        
    //el tiempo transcurrido es
    tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

    // Mostramos resultados
    cout << M << "\t" << tiempo_transcurrido.count() << endl;

    cout<< endl;
    cout << 0;
    for(unsigned int i = 0; i < res.size(); i++){         // Imprime la operación y el número
        cout<< res[i].second << res[i].first;             
    }                                                     
    cout<< endl;


}