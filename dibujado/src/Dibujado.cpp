/* Implementación de los métodos de dibujado */

#include <Dibujado.h>

#include <EspacioNormal.h>
#include <PelotaNormal.h>
#include <RaquetaNormal.h>
#include <RaquetaConvexa.h>

#include <cstdio>
#include <cmath>

void inicializaTipos(Espacio*& espacio, Pelota*& pelota, Raqueta*& raquetaI, Raqueta*& raquetaD){
	
	espacio = new EspacioNormal(1000,500);
	//~ raquetaI = new RaquetaConvexa(40, 10, 60, 3, espacio,-70);
	raquetaI = new RaquetaNormal(40, 10, 60, 5, espacio);
	raquetaD = new RaquetaNormal(960, 10, 60, 5, espacio);
	pelota = new PelotaNormal(1.0, 8, raquetaI, raquetaD, espacio);
	
}

void liberaTipos(Espacio*& espacio, Pelota*& pelota, Raqueta*& raquetaI, Raqueta*& raquetaD){
	delete espacio;
	delete pelota;
	delete raquetaI;
	delete raquetaD;
}

void inicializaOGL(int ventanaAncho, int ventanaAlto){
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
		
	glutInitWindowSize(ventanaAncho, ventanaAlto);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("-* PONG *-");

	gluOrtho2D(0.0, ventanaAncho, 0.0, ventanaAlto);
	glEnable (GL_LINE_SMOOTH);	// Activar lineas con Antialiasing
	glEnable (GL_LINE_STIPPLE);	// Activar lineas rayadass
	
	glClearColor(0,0,0,0);
}

void dibuja(Espacio* espacio){
	glBegin(GL_LINE_LOOP);
		glVertex2i(1, 1);
		glVertex2i(1, espacio->getAlto());
		glVertex2i(espacio->getAncho(),espacio->getAlto());
		glVertex2i(espacio->getAncho(), 1);
	glEnd();
	
	glPushAttrib (GL_LINE_BIT);
	glLineWidth (8);
	glLineStipple (3, 0x1F1F);
	
	glBegin(GL_LINE_LOOP);
		glVertex2i(espacio->getAncho()/2, espacio->getAlto());
		glVertex2i(espacio->getAncho()/2, 0);
	glEnd();
	glPopAttrib ();
}

void dibuja(Pelota* pelota){
	const double radio = pelota->getRadio();
	const double x0 = pelota->getPos().x;
	const double y0 = pelota->getPos().y;
		
	glBegin(GL_POLYGON);
		for(int i = 0 ; i < NUM_LDS ; i++){
			glVertex2i(
				radio * cos(2.0*M_PI*i/NUM_LDS) + x0,
				radio * sin(2.0*M_PI*i/NUM_LDS) + y0
			);
		}
	glEnd();
}

void dibuja(Raqueta* raqueta){
	
	glBegin(GL_POLYGON);
		glVertex2i(
			raqueta->getPosX() - raqueta->getAncho(),
			raqueta->getPosY() - raqueta->getAlto()
		);
		glVertex2i(
			raqueta->getPosX() - raqueta->getAncho(),
			raqueta->getPosY() + raqueta->getAlto()
		);
		glVertex2i(
			raqueta->getPosX() + raqueta->getAncho(),
			raqueta->getPosY() + raqueta->getAlto()
		);
		glVertex2i(
			raqueta->getPosX() + raqueta->getAncho(),
			raqueta->getPosY() - raqueta->getAlto()
		);
	glEnd();
	
}
