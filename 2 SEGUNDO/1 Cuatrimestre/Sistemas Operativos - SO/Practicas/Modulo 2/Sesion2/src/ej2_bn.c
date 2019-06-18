/* (C) Programmed by:
   Antonio Jimenez Martínez
   Andrés Ortiz Corrales
   Mariano Palomo Villafranca
Practica Sistemas Operativos: Modulo 2 - Sesion 2
Version:0.1
EJERCICIO 2:
Realiza un programa en C utilizando las llamadas al sistema necesarias que
acepte como entrada:
	-Un argumento que representa el 'pathname' de un directorio.
	-Otro argumento que es un número octal de 4 dígitos (similar al que se puede utilizar
	para cambiar los permisos en la llamada al sistema chmod). Para convertir este
	argumento tipo cadena a un tipo numérico puedes utilizar la función strtol. Consulta
	el manual en línea para conocer sus argumentos.
El programa tiene que usar el número octal indicado en el segundo argumento para cambiar
los permisos de todos los archivos que se encuentren en el directorio indicado en el primer
argumento.
El programa debe proporcionar en la salida estándar una línea para cada archivo del
directorio que esté formada por:
<nombre_de_archivo> : <permisos_antiguos> <permisos_nuevos>
Si no se pueden cambiar los permisos de un determinado archivo se debe especificar la
siguiente información en la línea de salida:
<nombre_de_archivo> : <errno> <permisos_antiguos>
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <dirent.h>


int main(int argc, char *argv[]){

	DIR *directorio;
	struct dirent *file;//estructura directorio
	int fd;//descriptor de archivo
	long int permisos,permisosa;//permisos nuevos y antiguos
	struct stat atributos;//estructura de los atributos de un archivo

	if(argc<3) {// si el numero de argumentos es menor que tres, salimos de la ejecucion.
		printf("\nSintaxis de ejecucion: tarea4 [<pathname>]+ [<4digit_octal_number>]+ \n\n");
		exit(-1);
	}

	directorio = opendir(argv[1]);//abrimos el direcctorio con pathname el primer argumento
	file = readdir(directorio);
	permisos=strtol(argv[2],NULL,8);//almacenamos permisos nuevos del segundo argumento
	chdir(argv[1]);//abrimos el directorio.
	while(file != NULL && strcmp(file->d_name,".")==1 && strcmp(file->d_name,"..")==1){
	//mientras que el archivo no sea nulo o no el nombre del archivo no esa "." o ".."
			printf("\nFile Name: %s\n",file->d_name);//mostramos por pantalla el nombre del archivo

			if(stat(file->d_name,&atributos) < 0) {//almacenamos sus atributos
				printf("\nError al intentar acceder a los atributos");
				perror("\nstat Fail");
				exit(-1);
			}


			if(chmod(file->d_name,permisos)<0){//cambiamos los atributos del archivo
			printf("\nError en chmod\n");
			printf("\npermisos antiguos:%o\n",atributos.st_mode);
			}
			else//mostramos los permisos antiguos y nuevos
			printf("\npermisos antiguos:%o permisos nuevos:%lu\n",atributos.st_mode,permisos);//%o de octal
			close(fd);//cerramos el archivo

			file = readdir(directorio);//abrimos el proximo archivo
	}

	if(closedir(directorio)<0) {//cerramos el directorio
		printf("\nclosedir Fail \n\n");
		exit(-1);
	}
	return 0;
}
