/*******************************************************************************
*
*   Ejemplo #1: Mide el tiempo de la ejecucion de una seccion de codigo
*
*   Autor: J.A. Holgado
*   Ultima modificacion: 04/01/2015
*   Plataforma: POSIX
*   Asignatura: Sistemas Concurrente y Distribuido
*   Departamento: Lenguaje y Sistemas Informatico
*   Universidad de Granada
*
*   compilacion: gcc medidatiempo.c  -o medidatiempo
*
*   ejecucion: pasar como parametro el nombre del comando o programa a medir
*
*   Nota: En algunos sistemas Linux es necesario enlazar la libreria RTOS al final añadiendo -lrt
*
*
*******************************************************************************/

#include <time.h>			//clock_gettime()
#include <stdio.h>			// printf()
#include <stdlib.h>  // para "system"
#include "utilRT.h"


//Inicio del programa principal
int main(int argc,char *argv[])
{
	//Almacena marcas de tiempo
	struct timespec times0,times1;

	//Almacena la resolucion del reloj
	struct timespec clock_res;

	//Define variables auxiliares para la estadistica
	double total;
	struct timespec timeInterval;

	//Obtiene la resolucion del reloj POSIX por defecto
	if ( clock_getres(CLOCK_MONOTONIC, &clock_res) == -1 ) {
	      perror( "clock get resolution" );
	      return -1;
    	}

	//Mide el tiempo de una seccion de codigo
	clock_gettime(CLOCK_MONOTONIC, &times0); //marcamos tiempo inicial
	// Codigo a ejecutar-------
	system(argv[1]);
	////
	clock_gettime(CLOCK_MONOTONIC, &times1); //marcamos tiempo final

	//Se calcula el tiempo transcurrido
	timeInterval = restaTiempos(&times1,&times0);
	total = getMillis(&timeInterval);

	//Se muestran los resultados
    	printf( "\n\t\tResultados \n\t\t----------\n");
	printf( "Resolucion del reloj CLOCK_MONOTONIC: %ld segundos y %ld nanosegundos\n",clock_res.tv_sec,clock_res.tv_nsec);
    	printf( "Tiempo total en ejecutar %s: %.6f  (ms)\n", argv[1],total);

}
