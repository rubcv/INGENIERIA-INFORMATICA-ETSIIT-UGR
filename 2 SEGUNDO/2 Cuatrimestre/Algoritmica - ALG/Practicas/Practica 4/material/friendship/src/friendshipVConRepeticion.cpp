#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include <utility>

using namespace std;



int Seleccionar(int &pos, vector<vector<int> > discrepancias, int personas){


    int menor = discrepancias[0][0];
    int pareja2  = 0;
    for(unsigned int j = 0; j < personas; j++){
        if(discrepancias[pos][j] <  menor){
    
            menor = discrepancias[pos][j];
            pareja2 = j;
        }
    }
    pos++;

    return pareja2;
}



vector<int> Greedy(vector<vector<int> > discrepancias, int personas){
    vector<int> res;
    
    int pos = 0;
    while(res.size() != personas){

        int una = Seleccionar(pos, discrepancias, personas); // Comprobamos si es factible en Seleccionar
        res.push_back(una);
    }

    return res;
}



int main(int argc, char** argv){

    if(argc != 2){
        cerr<< "Escribe " << argv[0] << " <nombre-fichero>" << endl;
        exit(1);
    }

    fstream input;
    
    try{
        input.open(argv[1], fstream::in);
    }catch(exception &e){
        cerr<< "Error abriendo el fichero" << endl;
        exit(1);
    }



    // ----- LEEMOS LOS DATOS Y CREAMOS LA MATRIZ DE DISCREPANCIAS ------
    unsigned int personas = 0 , preguntas = 0;
    int dato;
    string comentario;

    getline(input, comentario);        
    input>> dato; // Personas
    personas = dato;
    input>> dato;
    preguntas = dato; // Preguntas

    vector<vector<int> > matriz(personas, vector<int>(preguntas, 0));

    for(unsigned int i = 0; i < personas; i ++){
        for(unsigned int j = 0; j < preguntas; j++){
            input>> dato;
            matriz[i][j] = dato;
        }
    }
    

    vector<vector<int> > discrepancias(personas, vector<int>(personas, 0));
    int inf = numeric_limits<int>::max();
    for(unsigned int i = 0; i < personas; i ++){
        for(unsigned int j = 0; j < personas; j++){
            if(i == j)
                discrepancias[i][j] = inf;
        }
    }
    /*
    for(unsigned int i = 0; i < personas; i++){
        for(unsigned int j = 0; j < personas; j++){
            cout<< discrepancias[i][j] << " ";
        }
        cout << endl;
    }
    */
    
    int fil = 0, fil_pareja = 1;

    while(fil_pareja < personas){
       int suma = 0;
       for( int k = 0; k < preguntas; k++){
                suma += abs(matriz[fil][k] - matriz[fil_pareja][k]);
        }

        discrepancias[fil][fil_pareja] = suma;
        fil_pareja++;
        if(fil_pareja == personas){
            fil++;  
            fil_pareja = fil + 1;
        }
    }

    for(unsigned int i = 1; i < personas; i++){
        for(unsigned int j = 0; j <= i; j++){
            discrepancias[i][j] = discrepancias[j][i];
        }
    }


    // --------------------------------------------------------


    /*
    cout << endl;
    for(unsigned int i = 0; i < personas; i++){
        for(unsigned int j = 0; j < personas; j++){
            cout<< discrepancias[i][j] << "   ";
        }
        cout << endl;
    }
    */


    vector<int> res = Greedy(discrepancias, personas);


    for(unsigned int i = 0; i < res.size(); i++){
        cout<< i + 1 << " esta con " << res[i] + 1 << endl;
    }


}   