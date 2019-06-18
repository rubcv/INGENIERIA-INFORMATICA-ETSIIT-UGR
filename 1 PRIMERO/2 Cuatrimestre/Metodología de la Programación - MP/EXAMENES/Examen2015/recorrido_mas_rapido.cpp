#include "Recorrido.h"

using namespace std;

int main(int argc, char *argv[]) {

    if(argc < 2) {
        cerr << "Sintaxis: " << argv[0] << " <fichero1> <fichero2> ... <ficheroN>" << endl;
        return -1;
    } else {
        int n_ficheros = argc-1;
        double *velocidad_media = new double[n_ficheros];   // Array con velocidad media de los recorridos
        int max = 0;

        // Para cada fichero:
        // 1) leer recorrido
        // 2) calcular velocidad media
        // 3) actualizar velocidad media maxima
        for(int i=0; i<n_ficheros; i++) {
            Recorrido r(false);
            bool lecturaOK = r.lectura(argv[i+1]); cout << " t: " << r.TiempoRecorrido() << " d: " << r.DistanciaRecorrido() << endl;

            if(lecturaOK) {
                velocidad_media[i] = r.VelocidadMedia();
                if (velocidad_media[i] >= velocidad_media[max])
                    max = i;
            } else {
                velocidad_media[i] = -1;
            }

        }

        if(velocidad_media[max] > 0) {
            cout << "Velocidad media maxima: ";
            cout << argv[max+1] << " (" << velocidad_media[max] << ")\n" ;
        } else
            cout << "Ningun fichero contiene datos validos";
    }

    return 0;
}