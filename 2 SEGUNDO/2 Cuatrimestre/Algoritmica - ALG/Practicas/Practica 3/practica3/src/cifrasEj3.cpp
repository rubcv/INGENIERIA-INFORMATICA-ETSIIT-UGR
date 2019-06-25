#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>
#include <utility>
#include <fstream>
#include <chrono>


using namespace std;
using namespace std::chrono;


// Eficiencia de porque rellenas la tabla O(n²)

void Busca_conjunto(const vector<int> &S, const int &M, vector<vector<pair<int, char> > > &tabla, vector<pair<int, char> > &solution, const int maximo){
	int i, j;

    int ncol=M*maximo;
    int nfil=S.size();

	for(i = 0; i <=nfil; i++){
		tabla[i][0] = make_pair(0, '?');

	}

	for(j= 1; j <=ncol; j++){
			tabla[0][j] = make_pair(j, '?');
		
	}
	
	for (i = 1; i <= nfil; i++){
		for(j = 1; j <= ncol; j++){
            tabla[i][j].first=tabla[i-1][j].first;//no echarlo
			tabla[i][j].second = '?' ; 

            if (j-S[i-1]>=0)//sumando
               if (tabla[i][j].first > tabla[i-1][j-S[i-1]].first){
                    tabla[i][j].first = tabla[i-1][j-S[i-1]].first;
					tabla[i][j].second = '+';
				}
            if (j+S[i-1]<=ncol)//restando
               if (tabla[i][j].first > tabla[i-1][j+S[i-1]].first){
                    tabla[i][j].first = tabla[i-1][j+S[i-1]].first;
					tabla[i][j].second = '-';	
				}
			if (j%S[i-1] == 0)//multiplicando
				if (tabla[i][j].first > tabla[i-1][j/S[i-1]].first){
					tabla[i][j].first = tabla[i-1][j/S[i-1]].first;
					tabla[i][j].second = '*';
				}
			if (j*S[i-1] <= ncol)//dividiendo
				if (tabla[i][j].first > tabla[i-1][j*S[i-1]].first){
					tabla[i][j].first = tabla[i-1][j*S[i-1]].first;
					tabla[i][j].second = '/';		
				}

		}//endFOR
	}//endFOR

/*
	cout << "\tTABLA\t\n";
    for (int i=0;i<=nfil;i++){
         for (int j=0;j<=ncol;j++)
               cout<<tabla[i][j].first<<"\t";
         cout<<endl;
    }
*/
//-------SOLUTION--------------

	j = M;
	
	for(i = S.size(); i > 0; i--){

		if (tabla[i][j].first != tabla[i - 1][j].first){
			solution.push_back(make_pair(S[i-1], tabla[i][j].second));

			if(tabla[i][j].second == '-')
				j = j + S[i-1];
			if(tabla[i][j].second == '+')
				j = j - S[i-1];
			if(tabla[i][j].second == '/')
				j = j *S[i-1];
			if(tabla[i][j].second == '*')
				j = j /S[i-1];
		}

	}

	solution.push_back(make_pair(0,'?'));//Metemos el 0 para sumarle el resultado	


}

int Pivote(vector<int> &v, int inicio, int fin){
	int intercambia;
	int pivote = v[inicio];

	int i = inicio + 1;
	int d = fin;

	while(i <= d)
	{

		while(i <= d && v[i] >= pivote)
			i++;

		while(i <= d && v[d] < pivote)
			d--;

		if (i < d)
		{
			intercambia = v[i];
			v[i] = v[d];
			v[d] = intercambia;
			d--;
			i++;
		}

	}

	intercambia = v[inicio];
	v[inicio] = v[d];
	v[d] = intercambia;

	return d;
}



void Ordena ( vector<int> & S, int inicio, int fin){

	if(fin > inicio){
	
		int l = Pivote(S, inicio, fin);
		
		Ordena(S, inicio, l-1);
		Ordena(S, l+1, fin);
	}
}


int main(int argc,char** argv){


    if(argc != 3){
        cerr<< "Escribe " << argv[0] << " <fichero-datos> <M>" << endl;
        exit(1);
    }
    

	vector<int> S;
    fstream file;
    int dato, M = atoi(argv[2]);

    file.open(argv[1], fstream::in);

    while(file >> dato){
        S.push_back(dato);
    }
	
	


  //  int valores[3] = {3, 2, 1};
   // vector<int> S(valores, valores + 3);
	Ordena(S, 0, S.size()-1);
	int maximo = S[0];


    vector< vector<pair<int,char> > > tabla(S.size()+1, vector<pair<int,char> >(M * maximo+1, make_pair(numeric_limits<int>::max(),'?')));
    vector<pair<int, char> > solucion;



    high_resolution_clock::time_point start, end;
    duration<double> tiempo_transcurrido;
    
    start = high_resolution_clock::now();

    Busca_conjunto(S, M, tabla, solucion, maximo);

	end =  high_resolution_clock::now();



	  //el tiempo transcurrido es
    tiempo_transcurrido  = duration_cast<duration<double> >(end - start);

    // Mostramos resultados
    cout << M << "\t" << tiempo_transcurrido.count() << endl;
	
	vector<pair<int,char> >::iterator it;
	for(it = solucion.begin(); it != solucion.end(); ++it){

		if((*it).second != '?')
			cout << (*it).second << " " ;
		
		cout << (*it).first << " ";

	}

	cout << endl;
	
    return 0;
}
