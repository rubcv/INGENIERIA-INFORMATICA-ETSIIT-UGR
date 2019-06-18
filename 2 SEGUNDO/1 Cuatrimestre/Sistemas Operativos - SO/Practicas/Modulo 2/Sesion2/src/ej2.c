/*
	Ejercicio 2
	Rubén Calvo Villazán - 76065313

*/


#include <unistd.h>  /* POSIX Standard: 2.10 Symbolic Constants <unistd.h>		                    */
#include <stdlib.h>
#include <sys/types.h>  /* Primitive system data types for abstraction of implementation-dependent data types.     \
		                      POSIX Standard: 2.6 Primitive System Data Types     <sys/types.h>  */
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>
#include <dirent.h>



int main(int argc, char* argv[]){

	if(argc < 3){ // Comprobacion de los argumentos
		printf("%s\n", "Escribe ./ej2 [nombre dir (ej /home/user/Desktop)] [permisos (ej 0777)]\n");
		exit(-1);
	}
	long int permisos = strtol(argv[2], NULL, 8);
	long int permisosAntes;
	char* dir = argv[1];
	char* perm = argv[2];
	DIR *pDir;
	struct dirent *pDirent;
	struct stat atributos;
	int fd;

	if((pDir = opendir(dir)) == NULL){ // Se abre el directorio pasado como argumento
		printf("%s\n", "Error en la apertura del directorio\n");
		exit(-1);
	}

	chdir(dir); // Entramos al directorio
	pDirent = readdir(pDir); // Leemos el directorio

	while(pDirent != NULL){
		printf("\nNombre del archivo: %s\n", pDirent->d_name); // Mostramos por pantalla el nombre del archivo

		if(stat(pDirent->d_name, &atributos) < 0) { // Guardamos los atributos
			printf("\nError al guardar los atributos\n");
			exit(-1);
		}


		if(chmod(pDirent->d_name, permisos) < 0){ // Hacemos chmod para cambiar los permisos de cada archivo
			printf("\nError al cambiar permisos\n");
			printf("\nPermisos antiguos: %o\n", atributos.st_mode); // %o de octal
		}else{
			printf("\nPermisos antiguos: %o Permisos nuevos: %lu\n", atributos.st_mode, permisos); // Permisos nuevos y antiguos
		}

		close(fd); // Cerramos el archivo

		pDirent = readdir(pDir); // Abrimos el siguiente

	}

	if(closedir(pDir) < 0){ // Cerramos el directorio
		printf("\nFallo al cerrar el directorio\n");
		exit(-1);
	}
}
