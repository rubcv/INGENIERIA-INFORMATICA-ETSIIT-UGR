//
// Ejercicio 6 - Relacion Pilas_Colas
//
//
// 6. Dada una matriz que representa un laberinto,
// construye una función que determine si se puede
// llegar desde la entrada hasta la salida. Esta matriz
// tendrá una ’E’ en la entrada, una ’S’ en la salida,
// un ’0’ en las casillas por las que se pueda pasar
// y un ’1’ en las que no. No se puede ir en diagonal.
//

#include <iostream>
#include <stack>


using namespace std;

void Rellenar(char** &matriz, int fil, int cols){ // Funcion para rellenar el laberinto

  char no = '1'; // Distintos valores que puede haber en el laberinto
  char si = '0';
  char ini = 'E';
  char fin = 'S';

  matriz = new char*[fil + 1]; // Creamos la matriz con los datos

  for(int i = 0; i <= fil; i++){ // La matriz tiene los bordes a '1'
    matriz[i] = new char[cols];
    for(int j = 0; j <= cols; j++){
      matriz[i][j] = no;
    }
  }

//----- INICIALIZAR -----

  // Posicion de inicio y fin
  matriz[1][1] = ini;
  matriz[fil-1][cols - 1] = fin;

// Rellenar laberinto a mano para tam = 5
/* Rellenado a mano hasta 5 para probar el algoritmo de recorrer,
Cambiar cualquier valor a 'no' o añadir nuevas posiciones para hacer pruebas */
  matriz[1][2] = si;
  matriz[1][2] = si;
  matriz[2][2] = si;
  matriz[2][3] = si;
  matriz[3][2] = si;
  matriz[4][2] = si;
  matriz[4][3] = si;

//--------------------------

// MOSTRAR EL LABERINTO INICIALIZADO
  for(int i = 1; i < fil; i++){
    for(int j = 1; j < cols; j++){
      cout<< matriz[i][j] << " ";
    }
    cout<< endl;
  }
}



bool Laberinto(char** matriz, int fils, int cols){ // Funcion para recorrer el laberinto
  stack<int> pi; // Creamos dos pilas, para guardar la posicion de la i
  stack<int> pj; // Para guardar la posicion de la j

  // Distintos valores que puede haber en el laberinto
  char no = '1';
  char si = '0';
  char ini = 'E';
  char fin = 'S';
  char visi = 'V';
  int conVisi = 0;

// Recorremos el laberinto
  for(int i = 1; i < fils ; i++){
    for(int j = 1; j < cols ; j++){
      // Para evitar que se encuentre en una posicion sola rodeada de '1', al inicio por ejemplo
      char pos1 = matriz[i][j - 1];
      char pos4 = matriz[i][j + 1];
      char pos2 = matriz[i - 1][j];
      char pos3 = matriz[i + 1][j];
      if(pos1 == no && pos2 == no && pos3 == no && pos4 == no){
        return false;
      }

      if(matriz[i][j] != visi){ // Si es una casilla sin visitar
        if(matriz[i][j] != fin){ // Si no hemos llegado al final
          if(matriz[i][j] == si){ // Si es = '0', se puede avanzar
            pi.push(i); // Se guarda la posicion en la pila
            pj.push(j);
            conVisi = 0; // Contador de visitadas = 0
          }else{
            matriz[i][j] = visi; // Si no es '0' se pone a visitada
            if(conVisi == fils - 2){ // Si toda la fila ha sido visitada, es decir no conectan los '0' con la salida
              return  false;
            }
            conVisi++; // Contador de visitadas++

            if(!pi.empty() && !pj.empty()){ // Si hay datos de un '0' previo en la pila
              i = pi.top(); // Se vuelve a su posicion
              j = pj.top();
            }
          }
        }else{
          return true; // Si la casilla es  = Salida, se puede llegar
        }
      }
    }
  }
  return false; // Si no se llega, = false
}

int main(){

  char** matriz;
  const int TAM = 5;
  int fil = TAM;
  int cols = TAM;

  Rellenar(matriz, fil, cols);

  if(Laberinto(matriz, fil, cols)){
    cout<< "\nSe puede ir de inicio a fin" << endl;
  }else{
    cout<< "\nNo se puede ir de inicio a fin" << endl;
  }
}
