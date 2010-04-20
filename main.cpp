#include <iostream>
#include <cstdlib>

#include <Espacio.h>
#include <Pelota.h>
#include <Raqueta.h>

#include <Dibujado.h>

//Tipos
Espacio* espacio;
Pelota* pelota;
Raqueta* raquetaIzq;
Raqueta* raquetaDer;

//Función Idle
void itera(int nada);
void dibujaTodo();
void teclas(unsigned char tecla, int x, int y);
void raton(int boton, int estado, int x, int y);
void escalarVentana(int x, int y);

int main(int argc, char **argv){
	glutInit(&argc, argv);
	
	inicializaTipos(espacio, pelota, raquetaIzq, raquetaDer);
	inicializaOGL(espacio->getAncho(), espacio->getAlto());

	glutDisplayFunc(dibujaTodo);
	glutKeyboardFunc(teclas);
	glutMouseFunc(raton);
	glutReshapeFunc(escalarVentana);
	//glutIdleFunc(itera);
	itera(0);
	glutMainLoop();
	
	return 0;
}

void itera(int nada){
	pelota->muevete();
	glutPostRedisplay();
	
	glutTimerFunc(50, itera, nada);
}

void dibujaTodo(){
	glClear(GL_COLOR_BUFFER_BIT);
	
	dibuja(espacio);
	dibuja(raquetaIzq);
	dibuja(raquetaDer);
	dibuja(pelota);
	
	glutSwapBuffers();
}

void teclas(unsigned char tecla, int x, int y){
	switch (tecla) {
		case 27:	//<ESC>
			liberaTipos(espacio, pelota, raquetaIzq, raquetaDer);
			std::cout << "Memoria liberada." << std::endl;
			exit(0);
		break;
		
		case 119:	//w
			raquetaIzq->mueveteArriba();
		break;
		
		case 115:	//s
			raquetaIzq->mueveteAbajo();
		break;
		
		case 114:	//r
			pelota->reset();
		break;
	}
}

void raton(int boton, int estado, int x, int y){
	
}
	
void escalarVentana(int x, int y){
	
}
