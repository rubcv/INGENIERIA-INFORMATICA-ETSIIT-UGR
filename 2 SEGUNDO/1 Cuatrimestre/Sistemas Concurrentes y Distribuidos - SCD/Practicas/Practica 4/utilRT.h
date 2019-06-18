/*******************************************************************************
*
*   utilRT.h Definicion del archivo utilRT.h
*        Utilidades de conversion y gestion de tiempo en POSIX
*
*   Autor: J.A. Holgado
*   Ultima modificacion: 04/01/2015
*   Plataforma: POSIX
*   Asignatura: Sistemas Concurrentes y Distribuidos
*   Departamento: Lenguaje y Sistemas Informatico
*   Universidad de Granada
*
*   incluir utilRT.h al compilar con gcc
*
*******************************************************************************/
#ifndef UTILRT_H_
#define UTILRT_H_

#include <time.h>			

//Define las constantes de tiempo
#define NANO_PER_SECOND		1000000000L
#define MICRO_PER_SECOND	1000000L
#define MILI_PER_SECOND		1000L

#define MICRO_PER_NANO		1e-3
#define MILI_PER_NANO		1e-6
#define SECOND_PER_NANO		1e-9


// Funcion restaTiempos: Diferencia dos timespec, t1-t2
struct timespec restaTiempos(struct timespec *t1, struct timespec *t2);

// Funcion sumaTiempos: Suma dos timespec t1 + t2
struct timespec sumaTiempos(struct timespec *t1, struct timespec *t2);

// Funcion getSegundos: Obtiene segundos a partir de timespec
double getSeconds(struct timespec *t1);

// Funcion getMillis: Obtiene milisegundos a partir de timespec
double getMillis(struct timespec *t1);

// Funcion getMillis: Obtiene timespec a partir de segundos
struct timespec getTimespec(double seconds);



#endif //UTIRT_H_
