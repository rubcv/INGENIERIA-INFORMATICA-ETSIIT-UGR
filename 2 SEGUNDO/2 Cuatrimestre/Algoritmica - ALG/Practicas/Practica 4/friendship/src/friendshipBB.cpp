#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <limits>
#include "Apermutacion.cpp"

using namespace std;
/**
	Sobrecargas para la salida de la matriz de datos
*/
template <class T>
ostream & operator<<(ostream &os, const vector<T> & d){
   for (int i=0;i<d.size();i++)
      os<<d[i]<<" ";
   
   return os;
}

template <class T>
ostream & operator<<(ostream &os, const vector<vector<T> > & mtrx){
	for (int i=0;i<mtrx.size();i++)
		os<<mtrx[i]<<endl;

	return os;
}

/**
	Sobrecarga de entrada de los datos en matriz
*/
template <class T>
istream & operator>>(istream &is, vector<vector<T> > & mtrx){

	for (int i=0;i<mtrx.size();i++)
		for(int j=0;j<mtrx[i].size();j++)
			is >> mtrx[i][j];				


	return is;
}

template <class T>
void InitializerMtrx(vector<vector<T> > & mtrx, int fil=100, int col=100 ){

	vector<T> containAux;	


	for (int i=0;i<col;i++)
		containAux.push_back(0);		

	for(int j=0;j<fil;j++)
		mtrx.push_back(containAux);				


}

void MuestraSecuencia(const Apermutacion & P){
  Apermutacion::const_iterator it;
  
  for (it=P.begin();it!=P.end();++it)
      cout<<*it<<" ";
  cout<<endl;    
}

///////////////////////////////////VORACES////////////////////////////////////////////////


//************** SIN REPETIDOS **************



bool Factible(const vector<bool> & uno,const int i, const int j){
    return ((uno[i] == false) && (uno[j] == false));
}

vector<pair<int, int> > Seleccionar(int &pos, vector<vector<int> > & discrepancias, vector<bool> & usados, int & discrepancia, vector<bool> & asignados){
    vector<pair<int, int> > parejas;
    

    int menor = discrepancias[0][0];
    int pareja1 = 0, pareja2 = 0;

    for(unsigned int j = 0; j < discrepancias[0].size(); j++){
        if(discrepancias[pos][j] <  menor && Factible(usados, pos, j) && Factible(asignados, pos, j)){
            menor = discrepancias[pos][j];
            pareja2 = j;
        }
    }
    
    pareja1 = pos;
    usados[pareja1] = true;
    usados[pareja2] = true;
    if(menor != discrepancias[0][0])
    	discrepancia += menor;
   
    parejas.push_back(make_pair(pareja1, pareja2));
    parejas.push_back(make_pair(pareja2, pareja1));


    return parejas;
}



vector<pair<int, int> > Greedy_CS(vector<vector<int> > & discrepancias, int personas, int & discrepancia, vector<bool> & asignados){
    vector<pair<int, int> > res;
    vector<bool> usados(discrepancias[0].size(), false);
   
    int pos = 0;
    while(res.size() != personas){
        while(asignados[pos] == true && pos < discrepancias[0].size())
            pos++;

        vector<pair<int, int> > una = Seleccionar(pos, discrepancias, usados, discrepancia, asignados); // Comprobamos si es factible en Seleccionar
        res.push_back(una[0]); // La pareja a con b
        res.push_back(una[1]); // La pareja b con a
    }

    return res;
}



//************** CON REPETIDOS **************



int Seleccionar(int &pos, vector<vector<int> > & discrepancias, int personas, int & discrepancia, vector<bool> & asignados){


    int menor = discrepancias[0][0];
    int pareja2  = 0;
    for(unsigned int j = 0; j < personas; j++){
        if(discrepancias[pos][j] <  menor && Factible(asignados, pos, j)){ // No este en asignados
    
            menor = discrepancias[pos][j];
            pareja2 = j;
        }
    }
    pos++;
    if(menor != discrepancias[0][0])
        discrepancia += menor;

    return pareja2;
}



vector<int> Greedy_CI(vector<vector<int> > & discrepancias, int personas, int & discrepancia, vector<bool> & asignados){
    vector<int> res;
    
    int pos = 0;
    while(res.size() != personas){

        int una = Seleccionar(pos, discrepancias, personas, discrepancia, asignados); // Comprobamos si es factible en Seleccionar
        res.push_back(una);
    }

    return res;
}



float V_CI(vector<vector<int> > uno, vector<bool> & asignados){
    int discrepancia = 0;
    Greedy_CI(uno, uno[0].size(), discrepancia, asignados);

    return discrepancia;
}


float V_CS(vector<vector<int> > uno, vector<bool> & asignados){
    int discrepancias = 0, cont = 0;
    for(int i = 0; i < asignados.size(); i++){
        if(asignados[i] == false)
            cont++;
    }
    Greedy_CS(uno, cont/2, discrepancias, asignados);

    discrepancias *= 2;
    return discrepancias;
}

// ----------------------------------- B & B -----------------------------------
//
//  CI = Greedy repitiendo
//  CS = Greedy sin repetir (a con b -> b con a)
//  BE = (CI + CS) / 2
//
//  C = min{(CS(j)), (Valor(s))}
//  
//  PODA: CI(i) >= C
//
//



struct nodo{
    Apermutacion V;
    int bact;
    float CI;
    float BE;
    float CS;

    nodo(Apermutacion uno, int b, int ci, int be, int cs){
        V = uno;
        bact = b;
        CI = ci;
        BE = be;
        CS = cs;
    }
};

bool operator<(const nodo &n1, const nodo &n2){ // Minimizando
    return (n1.BE < n2.BE);
}


int Suma_Discrepancias(const Apermutacion & A, const vector<vector <int> > & discrepancias){
    vector<int> datos = A.GetSecuencia();
    int res = 0;
    for(int i = 0; i <= A.GetLevel(); i++){
        if(i + 1 < datos[i]){
            res += discrepancias[i][datos[i] - 1];
        }
    }
    return res*2;
}

int BB(const vector<vector<int> > &discrepancias, Apermutacion &ab){
    int n = discrepancias[0].size();
    Apermutacion P(n);
    int bact = 0, best_beneficio = numeric_limits<int>::max();
    unsigned int nodos_recorridos = 0;
    vector<int> aux(n, -1);
    vector<bool> asignados(n, false);
    
    float CS = V_CS(discrepancias, asignados);
    float CI = V_CI(discrepancias, asignados);
    float BE = (CI + CS) / 2;
    float C = CS;

    priority_queue<nodo> LNV;

    nodo a(P, bact, CI, BE, CS);
    LNV.push(a);
 cout<< "CI: " << CI << " CS: " << CS << " BE: " << BE << " bact: " << bact << " C: " << C << endl;
    do{
        nodos_recorridos++;
        a = LNV.top();
        LNV.pop();

        if(a.CI <= C){
            vector<vector<int> > hijos = a.V.GeneraHijos();
            for(int i = 0; i < hijos.size(); i++){
                for(int k = 0; k < n; k++){
                    asignados[k] = false;
                }
                Apermutacion H(hijos[i], a.V.GetLevel() + 1);
                for(int j = 0; j <= H.GetLevel(); j++){
                    if(H[j] != 0){
                        asignados[j] = true;
                        asignados[H[j] - 1] = true;
                    }
                }
                bact = Suma_Discrepancias(H, discrepancias);
                CS = bact + V_CS(discrepancias, asignados);
                CI = bact + V_CI(discrepancias, asignados);
                BE = (CI + CS) / 2;
                cout<< "CI: " << CI << " CS: " << CS << " BE: " << BE << " bact: " << bact << " C: " << C << endl;
                cout << H << endl;
                if(H.GetLevel() == n - 1 && bact < best_beneficio){
                    ab = H;
                    best_beneficio = bact;
                    C = (C < bact)? C : bact;
                }else{
                    if(CI <= C){
                        nodo anew(H, bact, CI, BE, CS);
                        LNV.push(anew);
                        C = (C < CS)? C : CS;
                    }
                }
            }
        }
    }while(!LNV.empty());

    return best_beneficio;
}



// -------------------------------------------------------------------------------------

vector<vector<int> > DoDiscrepancia(vector<vector<int> > &mtrx){
	vector<vector<int> > discrepancia;
	int sumaDife = 0;

	InitializerMtrx(discrepancia,mtrx.size(), mtrx.size());

	for(int i=0;i<mtrx.size();i++)
		discrepancia[i][i]=numeric_limits<int>::max();

	for(int i=0;i<mtrx.size();i++)
		for(int j=0;j<mtrx.size();j++)
			if(i != j){
				sumaDife = 0;
				for(int k=0;k<mtrx[i].size();k++)
					sumaDife += abs(mtrx[i][k] - mtrx[j][k]);

				discrepancia[i][j] = sumaDife;

			}

	return discrepancia;
	

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


	vector<	vector<int> > mtrx, discrMtrx;
	int person, question;
	string line;
	Apermutacion ab(5);
		
	getline(input, line);
		
	input >> person; input >> question;

	InitializerMtrx(mtrx,person,question);
	InitializerMtrx(discrMtrx,person,person);

	input >> mtrx;
	discrMtrx = DoDiscrepancia(mtrx);


    
    int res = BB(discrMtrx, ab);

    cout<< "Discrepancia optima: " << res << endl;
/*
    cout << "Greedy sin repetir:" << endl;
    int discrepancia = 0;
	vector<pair<int, int> > res1 = Greedy_CS(discrMtrx, person, discrepancia);

    for(int i = 0; i < res1.size(); i++){
        cout<< res1[i].first + 1 << " esta con " << res1[i].second + 1 << endl;
    }
    cout<< endl;

    cout << "Greedy repitiendo:" << endl;
    vector<int> res2 = Greedy_CI(discrMtrx, person);
    for(int i = 0; i < res2.size(); i++){
        cout << i + 1 << " esta con " << res2[i] + 1 << endl;
    }
*/

	return 0;

}
