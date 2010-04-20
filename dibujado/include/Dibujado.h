/* Funciones para dibujar los tipos de Pong en OpenGL */

#ifndef _DIBUJADO
#define _DIBUJADO

#include <Espacio.h>
#include <Pelota.h>
#include <Raqueta.h>

#include <GL/glut.h>
#include <cmath>

//Ángulo interno del polígono regular que representa la pelota (ángulo de resolución)
const double ANG_RES = M_PI - 0.07;

//Cálculo del número de lados del polígono
const int NUM_LDS = 2*M_PI/(M_PI - ANG_RES);

void inicializaTipos(Espacio*&, Pelota*&, Raqueta*& raquetaIzq, Raqueta*& raquetaDer);
void liberaTipos(Espacio*&, Pelota*&, Raqueta*& raquetaIzq, Raqueta*& raquetaDer);
void inicializaOGL(int ventanaAncho, int ventanaAlto);

void dibuja(Espacio*);
void dibuja(Pelota*);
void dibuja(Raqueta*);

#endif
