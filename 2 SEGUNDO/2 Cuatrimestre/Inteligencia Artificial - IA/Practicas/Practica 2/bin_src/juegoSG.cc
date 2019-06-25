#include "motorlib.hpp"
#include <fstream>

MonitorJuego monitor;

int main(int argc, char ** argv){
  list<pair<int,int>> listo;

  if (argc < 8){
    cout << "Faltan parametros..." << endl;
    cout << "Se necesita indicar: " << endl;
    cout << "1) Mapa" << endl << "2) Semilla" << endl << "3) Nivel (1, 2 o 3)" << endl;
    cout << "4) Origen (F)" << endl << "5) Origen (C)" << endl;
    cout << "6) Destino (F)" << endl << "7) Destino (C)" << endl;
    cout << "...) Destino (F)" << endl << "...) Destino (C)" << endl;
  }
  else {
    // 1 -> mapa
    // 2 -> semilla
    // 3 -> nivel
    // 4,5 -> origen
    // 6,7 -> destino1
    // 8,9 -> destino2
    // ...
    srand(atoi(argv[2]));
    monitor.setMapa(argv[1]);
    monitor.startGame(atoi(argv[3]));

    ifstream ifile;
    ifile.open(argv[1], ios::in);

    unsigned int colSize, filSize;
    ifile >> colSize;
    ifile >> filSize;

    vector<vector<unsigned char> > mapAux;
    vector<unsigned char> colAux(colSize);

    for (unsigned int i = 0; i < filSize; i++) {
      mapAux.push_back(colAux);
    }

    for (unsigned int i = 0; i < filSize; i++) {
      for (unsigned int j = 0; j < colSize; j++) {
        ifile >> mapAux[i][j];
      }
    }
    ifile.close();
    // Reviso si es una posicion valida
    if (mapAux[atoi(argv[4])][atoi(argv[5])] != 'T')
	cout << "Posicion (" << argv[4] << "," << argv[5] << ") no es de tipo T" << endl;

    monitor.inicializar(atoi(argv[4]), atoi(argv[5]));
    monitor.setPasos(50);
    monitor.setRetardo(0);
    
    // Reviso si es una posicion valida
    if (mapAux[atoi(argv[6])][atoi(argv[7])] != 'T')
	cout << "Posicion (" << argv[6] << "," << argv[7] << ") no es de tipo T" << endl;

    monitor.setObjX(atoi(argv[6]));
    monitor.setObjY(atoi(argv[7]));

    listo.push_back(pair<int,int>(atoi(argv[6]),atoi(argv[7])));

    int i = 8;

    if (argc > i+1) {
	// Reviso si es una posicion valida
    	if (mapAux[atoi(argv[i])][atoi(argv[i+1])] != 'T')
		cout << "Posicion (" << argv[i] << "," << argv[i+1] << ") no es de tipo T" << endl;
	listo.push_back(pair<int,int>(atoi(argv[i]),atoi(argv[i+1])));
	i += 2;
    }

    monitor.setListObj(listo);
	
    monitor.juegoInicializado();

    lanzar_motor_juego2(monitor);
  }
  exit(EXIT_SUCCESS);
}
