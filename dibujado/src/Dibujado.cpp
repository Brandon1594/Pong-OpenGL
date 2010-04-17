/* Implementación de los métodos de dibujado */

#include <Dibujado.h>

#include <EspacioNormal.h>
#include <PelotaNormal.h>
#include <RaquetaNormal.h>

#include <cstdio>
#include <cmath>

void inicializaTiposNormales(Espacio*& espacio, Pelota*& pelota, Raqueta*& raquetaI, Raqueta*& raquetaD){
	
	espacio = new EspacioNormal(1000,500);
	raquetaI = new RaquetaNormal(30, 60, 15, 1, espacio);
	raquetaD = new RaquetaNormal(970, 60, 15, 1, espacio);
	pelota = new PelotaNormal(6, 10, raquetaI, raquetaD, espacio);
	
}

void liberaTiposNormales(Espacio*& espacio, Pelota*& pelota, Raqueta*& raquetaI, Raqueta*& raquetaD){
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
	const int radio = pelota->getRadio();
	const int x0 = pelota->getPos().x;
	const int y0 = pelota->getPos().y;
	
	glPointSize(7);
	glBegin(GL_POINTS);
		glVertex2i(x0,y0);
	glEnd();
	//printf("\n( %i, %i )",x0,y0);
	
	glBegin(GL_POLYGON);
		for(int i = 0 ; i < NUM_LDS ; i++){
			glVertex2i(
				radio * cos(2*M_PI*NUM_LDS*i) + x0,
				radio * sin(2*M_PI*NUM_LDS*i) + y0
			);
			//printf("\n( %i, %i )",radio * cos(2*M_PI*NUM_LDS*i) + x0,radio * sin(2*M_PI*NUM_LDS*i) + y0);
		}
	glEnd();
}

void dibuja(Raqueta* raqueta){
	
	glBegin(GL_POLYGON);
		glVertex2i(
			raqueta->getPosX() - raqueta->getAncho(),
			raqueta->getPosY() - raqueta->getTamanio()
		);
		glVertex2i(
			raqueta->getPosX() - raqueta->getAncho(),
			raqueta->getPosY() + raqueta->getTamanio()
		);
		glVertex2i(
			raqueta->getPosX() + raqueta->getAncho(),
			raqueta->getPosY() + raqueta->getTamanio()
		);
		glVertex2i(
			raqueta->getPosX() + raqueta->getAncho(),
			raqueta->getPosY() - raqueta->getTamanio()
		);
	glEnd();
	
}
