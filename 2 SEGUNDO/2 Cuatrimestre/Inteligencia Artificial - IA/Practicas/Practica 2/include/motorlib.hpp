#ifndef MOTORLIB
#define MOTORLIB

#include "motorlib/monitor.hpp"
#include <glui/glui.h>

extern MonitorJuego monitor;

bool lanzar_motor_juego(int &colisiones, int acc = -1, GLUI_EditText * editPosX = NULL, GLUI_EditText * editPosY = NULL);
void lanzar_motor_juego2(MonitorJuego &monitor);
void nucleo_motor_juego(MonitorJuego & monitor, int acc);
void lanzar_motor_grafico(int argc, char ** argv);

#endif
