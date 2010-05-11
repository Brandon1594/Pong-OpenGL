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
	raquetaI = new RaquetaConvexa(30, 15, 60, 10, espacio,-70);
	raquetaD = new RaquetaNormal(970, 15, 60, 10, espacio);
	pelota = new PelotaNormal(4.0, 5, raquetaI, raquetaD, espacio);
	
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
	
	glClearColor(0,0,0,0);
}

void dibuja(Espacio* espacio){
	glBegin(GL_LINE_LOOP);
		glVertex2i(1, 1);
		glVertex2i(1, espacio->getAlto());
		glVertex2i(espacio->getAncho(),espacio->getAlto());
		glVertex2i(espacio->getAncho(), 1);
	glEnd();
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
