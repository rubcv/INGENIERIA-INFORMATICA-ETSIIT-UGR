#include "motorlib.hpp"

int main(int argc, char ** argv) {
  if (argc < 2){
    srand(1);
    lanzar_motor_grafico(argc, argv);
  }
  else {
    srand(atoi(argv[1]));
    lanzar_motor_grafico(argc, argv);
  }

  exit(EXIT_SUCCESS);
}
