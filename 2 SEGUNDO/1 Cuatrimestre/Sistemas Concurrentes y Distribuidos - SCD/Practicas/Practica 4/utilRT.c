/*******************************************************************************
*
*   UtilRT.c Utilidades de conversion y gestion de tiempo en POSIX
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
*   Nota: En linux es necesario enlazar la libreria RTOS al final añadiendo -lrt
*
*
*******************************************************************************/

#include "utilRT.h"

////////////////////////////////////////////////////////////////////////
// Funcion restaTiempos: Diferencia dos timespec, t1-t2
// Param1: (IN) Instante de tiempo t1
// Param2: (IN) Instante de tiempo t2
// Return: timespec diferencia
////////////////////////////////////////////////////////////////////////
struct timespec restaTiempos(struct timespec *t1, struct timespec *t2)
{
      struct timespec tres;

      tres.tv_sec = t1->tv_sec - t2->tv_sec;
      tres.tv_nsec = t1->tv_nsec - t2->tv_nsec;
      if (tres.tv_nsec<0){
        tres.tv_nsec=NANO_PER_SECOND + t1->tv_nsec - t2->tv_nsec;
        tres.tv_sec--;
      }
      return tres;
}

/////////////////////////////////////////////////////////////////////////
// Funcion sumaTiempos: Suma dos timespec t1 + t2
// Param1: (IN) Instante de tiempo t1
// Param2: (IN) Instante de tiempo t2
// Return: timespec suma
////////////////////////////////////////////////////////////////////////
struct timespec sumaTiempos(struct timespec *t1, struct timespec *t2)
{
      struct timespec tres;

      tres.tv_sec = t1->tv_sec + t2->tv_sec;
      tres.tv_nsec = t1->tv_nsec + t2->tv_nsec;
      if (tres.tv_nsec>=NANO_PER_SECOND){
		  tres.tv_nsec -= NANO_PER_SECOND;
        tres.tv_sec++;
      }
      return tres;
}

/////////////////////////////////////////////////////////////////////////
// Funcion getSegundos: Obtiene segundos a partir de timespec
// Param1: (IN) Tiempo en timespec
// Return: Segundos asociados al intervalo de tiempo
////////////////////////////////////////////////////////////////////////
double getSeconds(struct timespec *t1)
{
	double delta;
	delta = (double) t1->tv_sec ;
	delta += (double) t1->tv_nsec *(double) SECOND_PER_NANO;
	return delta;
}

/////////////////////////////////////////////////////////////////////////
// Funcion getMillis: Obtiene milisegundos a partir de timespec
// Param1: (IN) Tiempo en timespec
// Return: Millisegundos asociados al intervalo de tiempo
////////////////////////////////////////////////////////////////////////
double getMillis(struct timespec *t1)
{
	double delta;
	delta = (double) t1->tv_sec * (double) MILI_PER_SECOND;
	delta += (double) t1->tv_nsec *(double) MILI_PER_NANO;
	return delta;
}


/////////////////////////////////////////////////////////////////////////
// Funcion getMillis: Obtiene timespec a partir de segundos
// Param1: (IN) Tiempo en segundo
// Return: timespec
////////////////////////////////////////////////////////////////////////
struct timespec getTimespec(double seconds)
{
	struct timespec time;

	time.tv_sec = (int) seconds;
	time.tv_nsec = (int) ((seconds - time.tv_sec) * NANO_PER_SECOND);
	return time;
}


