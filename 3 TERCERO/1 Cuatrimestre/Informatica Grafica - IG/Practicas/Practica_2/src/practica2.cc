/*
* Practicas de IG
* Domingo Martin Perandres© 2014-2018
* dmartin@ugr.es
*
* GPL 3
*/

#include <GL/gl.h>
#include <GL/glut.h>
#include "stdlib.h"
#include "stdio.h"
#include <ctype.h>

#include "colors.h"
#include "axis.h"
#include "tetrahedron.h"
#include "cubo.h"
#include "cilindro.h"
#include "cono.h"

using namespace _colors_ne;

const float X_MIN=-.1;
const float X_MAX=.1;
const float Y_MIN=-.1;
const float Y_MAX=.1;
const float FRONT_PLANE_PERSPECTIVE=(X_MAX-X_MIN)/2;
const float BACK_PLANE_PERSPECTIVE=1000;
const float DEFAULT_DISTANCE=2;
const float ANGLE_STEP=1;

typedef enum {MODE_DRAW_POINT,MODE_DRAW_LINE,MODE_DRAW_FILL,MODE_DRAW_CHESS} _mode_draw;
typedef enum {OBJECT_TETRAHEDRON,OBJECT_CUBE} _object;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_angle_x=0;
GLfloat Observer_angle_y=0;
GLfloat Observer_distance=DEFAULT_DISTANCE;

// variables que controlan la ventana y la transformacion de perspectiva
//GLfloat Window_width,Window_height,Front_plane,Back_plane;
// variables que determninan la posicion y tamaño de la ventana X
int UI_window_pos_x=50,UI_window_pos_y=50,UI_window_width=800,UI_window_height=800;

_axis Axis;

/****************************FUNCIONES MIAS*******************************************************************/
//VARIABLE GESTION TECLAS
int modo = 0;
bool draw_cubo = false;
bool draw_ajedrez = false;
bool draw_lineas = false;
bool draw_puntos = false;
bool draw_solido = false;

// // VARIABLES QUE VOY A PINTAR
Cubo miCubo;
_tetrahedron miTetraedro;
Cilindro miCilindro;
Cono miCono;

int objeto=-100;


//**************************************************************************
// Limpiar ventana
//***************************************************************************

void clear_window()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************
/*
*@param
*@returns
*/
void change_projection()
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
//  formato(x_minimo,x_maximo, y_minimo, y_maximo,Front_plane, plano_traser)
//  Front_plane>0  Back_plane>PlanoDelantero)
  glFrustum(X_MIN,X_MAX,Y_MIN,Y_MAX,FRONT_PLANE_PERSPECTIVE,BACK_PLANE_PERSPECTIVE);
}


//**************************************************************************
// Funcion para definir la transformación de vista (posicionar la camara)
//***************************************************************************


void change_observer()
{
  // posicion del observador
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(0,0,-Observer_distance);
  glRotatef(Observer_angle_x,1,0,0);
  glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion que dibuja los objetos
//***************************************************************************
void draw_objects()
{
	Axis.draw_line();// son los ejes x y pintados
	switch(objeto)
	{
		case 1://cubo
		{
			if(draw_puntos)
			miCubo.draw_point();

			if(draw_lineas)
				miCubo.draw_line();

			if(draw_solido)
				miCubo.draw_fill(draw_ajedrez);
		}break;

		case 2: //tetraedro
		{
			if(draw_puntos)
			miTetraedro.draw_point();

			if(draw_lineas)
				miTetraedro.draw_line();

			if(draw_solido)
				miTetraedro.draw_fill(draw_ajedrez);
		}break;

		case 3: //cilindro
		{
			if(draw_puntos)
			miCilindro.draw_point();

			if(draw_lineas)
				miCilindro.draw_line();

			if(draw_solido)
				miCilindro.draw_fill(draw_ajedrez);
		}break;

		case 4: //cono
		{
			if(draw_puntos)
			miCono.draw_point();

			if(draw_lineas)
				miCono.draw_line();

			if(draw_solido)
				miCono.draw_fill(draw_ajedrez);
		}break;
	
	}

}



void draw_scene(void)
{
	clear_window();
	change_observer();
	draw_objects();
	glutSwapBuffers();
   
}


/**
* Evento de cambio de tamaño de la ventana
*@param
*@returns
*/

void resize(int Ancho1,int Alto1)
{
// 	change_projection();
	glViewport(0,0,Ancho1,Alto1);
	glutPostRedisplay();
}


//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//************************************OTRAS TECLAS PERO IGUAL***************************************

// void normal_keys(unsigned char Tecla1,int x,int y)
// {
// 	switch (toupper(Tecla1)){
// 		case '1':Object=OBJECT_TETRAHEDRON;break;
// 		case '2':Object=OBJECT_CUBE;break;
		
// 		//puntos
// 		case 'P':Draw_point=!Draw_point;break;
// 		//lineas
// 		case 'L':Draw_line=!Draw_line;break;
// 		//pintar caras(solido)
// 		case 'F':Draw_fill=!Draw_fill;break;
// 		//ajedrez
// 		case 'C':Draw_chess=!Draw_chess;break;		
		
// 		case 'Q':exit(0);
// 	}
// 	glutPostRedisplay();
// }

//															MODIFICADO
void normal_keys(unsigned char Tecla1,int x,int y)
{

if (toupper(Tecla1)=='Q') exit(0);
if (toupper(Tecla1)=='C'){ //ajedrez
	if(draw_ajedrez)
	 	draw_ajedrez=false;
	else
	 	draw_ajedrez = true;
	}
if (toupper(Tecla1)=='L'){
	if(draw_lineas)
		draw_lineas=false;
	else
		draw_lineas=true;
}//Lineas
if (toupper(Tecla1)=='F'){
	if(draw_solido)
		draw_solido=false;
	else
		draw_solido=true;
}//Relleno
if (toupper(Tecla1)=='P'){
	 if(draw_puntos)
	 	draw_puntos=false;
	 else
	 	draw_puntos=true;

 } //Puntos

 if (toupper(Tecla1)=='1') objeto = 1; //Cubo
 if (toupper(Tecla1)=='2') objeto = 2; //tetaedro
 if (toupper(Tecla1)=='3') objeto = 3; //cilindo
 if (toupper(Tecla1)=='4') objeto = 4; //cono


glutPostRedisplay();
}

//***************************************************************************
// Funcion llamada cuando se produce aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//*********************************IGUAL******************************************

void special_keys(int Tecla1,int x,int y)
{
	switch (Tecla1){
		case GLUT_KEY_LEFT:Observer_angle_y--;break;
		case GLUT_KEY_RIGHT:Observer_angle_y++;break;
		case GLUT_KEY_UP:Observer_angle_x--;break;
		case GLUT_KEY_DOWN:Observer_angle_x++;break;
		case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
		case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
		}
	glutPostRedisplay();
}



//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void)   //HAY COSAS AÑADIR
{
	//-------------------NUEVO----------------------------
		// se inicalizan la ventana y los planos de corte
		// Window_width=5;
		// Window_height=5;
		// Front_plane=10;
		// Back_plane=1000;

		// // se inicia la posicion del observador, en el eje z
		// Observer_distance=2*Front_plane;
		// Observer_angle_x=0;
		// Observer_angle_y=0;
	//-----------------Nuevo------------------------------
	// se indica cual sera el color para limpiar la ventana	(r,v,a,al)
	glClearColor(1,1,1,1);

	// se habilita el z-bufer
	glEnable(GL_DEPTH_TEST);
	//
	change_projection();
	//
	glViewport(0,0,UI_window_width,UI_window_height);
}


//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************

int main(int argc, char **argv)
{
	// se llama a la inicialización de glut
	glutInit(&argc, argv);

	// se indica las caracteristicas que se desean para la visualización con OpenGL
	// Las posibilidades son:
	// GLUT_SIMPLE -> memoria de imagen simple
	// GLUT_DOUBLE -> memoria de imagen doble
	// GLUT_INDEX -> memoria de imagen con color indizado
	// GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para cada pixel
	// GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa para cada pixel
	// GLUT_DEPTH -> memoria de profundidad o z-bufer
	// GLUT_STENCIL -> memoria de estarcido
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	// posicion de la esquina inferior izquierdad de la ventana
	glutInitWindowPosition(UI_window_pos_x,UI_window_pos_y);

	// tamaño de la ventana (ancho y alto)
	glutInitWindowSize(UI_window_width,UI_window_height);

	// llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
	// al bucle de eventos)
	glutCreateWindow("Practica 2");

	// asignación de la funcion llamada "dibujar" al evento de dibujo
	glutDisplayFunc(draw_scene);
	// asignación de la funcion llamada "cambiar_tamanio_ventana" al evento correspondiente
	glutReshapeFunc(resize);
	// asignación de la funcion llamada "tecla_normal" al evento correspondiente
	glutKeyboardFunc(normal_keys);
	// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
	glutSpecialFunc(special_keys);

	// funcion de inicialización
	initialize();

	// inicio del bucle de eventos
	glutMainLoop();
	return 0;
}
