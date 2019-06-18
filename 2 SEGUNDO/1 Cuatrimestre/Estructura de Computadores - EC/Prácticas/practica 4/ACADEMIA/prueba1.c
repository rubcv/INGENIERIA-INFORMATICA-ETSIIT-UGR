#include <librerias.h>

char clave[] = {65, 66, 67, 68, 0x09}; // ABCD

int comprobar(char* pass){
  int res = 1, i = 0;

  while(clave[i] != '\0' && pass[i] != '\0' && (clave[i] + 1) == pass[i]){
    i++;
  }

  if(clave[i] != '\0' && (clave[i] + 1) != pass[i]){ // Con el +1 le sumas 1 a los char luego es BCDE
    res = 0;
  }
  return res;
}


int main(){
  char pass[100];
  fgets(pass, 100, stdin);
  printf("Leido %s", pass);

  if(!comprobar(pass)){
    printf("Boom!\n");
  }
}
