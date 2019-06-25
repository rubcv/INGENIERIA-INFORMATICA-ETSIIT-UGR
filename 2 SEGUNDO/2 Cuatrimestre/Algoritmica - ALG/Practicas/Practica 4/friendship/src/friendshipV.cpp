#include <iostream>
#include <fstream>
#include <limits>
#include <vector>
#include <utility>

using namespace std;



bool Factible(const vector<bool> & uno,const int i, const int j){
    return ((uno[i] == false) && (uno[j] == false));
}

vector<pair<int, int> > Seleccionar(int &pos, vector<vector<int> > discrepancias, vector<bool> & usados, int personas, int & discrepancia){
    vector<pair<int, int> > parejas;
    

    int menor = discrepancias[0][0];
    int pareja1 = 0, pareja2 = 0;

    for(unsigned int j = 0; j < personas; j++){
        if(discrepancias[pos][j] <  menor && Factible(usados, pos, j)){
    
            menor = discrepancias[pos][j];
            pareja2 = j;
        }
    }
    
    pareja1 = pos;
    pos++;
    usados[pareja1] = true;
    usados[pareja2] = true;
    if(menor != discrepancias[0][0])
    	discrepancia += menor;
   
    parejas.push_back(make_pair(pareja1, pareja2));
    parejas.push_back(make_pair(pareja2, pareja1));


    return parejas;
}



vector<pair<int, int> > Greedy(vector<vector<int> > discrepancias, int personas, int & discrepancia){
    vector<pair<int, int> > res;
    vector<bool> usados(personas, false);
    
    int pos = 0;
    while(res.size() != personas){

        vector<pair<int, int> > una = Seleccionar(pos, discrepancias, usados, personas, discrepancia); // Comprobamos si es factible en Seleccionar
        res.push_back(una[0]); // La pareja a con b
        res.push_back(una[1]); // La pareja b con a
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


/*      COMPROBAR DISCREPANCIAS

    cout << endl;
    for(unsigned int i = 0; i < personas; i++){
        for(unsigned int j = 0; j < personas; j++){
            cout<< discrepancias[i][j] << "   ";
        }
        cout << endl;
    }
*/

    int discrepancia = 0;
    vector<pair<int, int> > res = Greedy(discrepancias, personas, discrepancia);


    cout<< "Discrepancia total: " << discrepancia*2 << endl; // *2 Para contar los ya pareados (a con b y b con a 2 parejas)
    for(unsigned int i = 0; i < res.size(); i++){
        cout<< res[i].first + 1 << " esta con " << res[i].second + 1 << endl;
    }


}   