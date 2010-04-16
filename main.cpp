#include <Espacio.h>
#include <Pelota.h>
#include <Raqueta.h>

#include <Dibujado.h>

//Tipos
	Espacio* espacio;
	Pelota* pelota;
	Raqueta* raquetaIzq;
	Raqueta* raquetaDer;

	int resolucionX = 600;
	int resoluciónY = 200;

	int velocidadPelota = 20;	// Píxeles/Iteración
	int velocidadRaquetas = 30;	// Píxeles/Iteración

void main(){
	
	inicializaTiposNormales(espacio, pelota, raquetaIzq, raquetaDer);
	inicializaOGL(espacio->getAncho()+4, espacio->getAlto()+4);

	glutDisplayFunc(dibuja);
	glutKeyboardFunc(teclas);
	glutMouseFunc(raton);
	glutReshapeFunc(ventanaEscalada);
	glutIdleFunc(itera);
	
	glutMainLoop();
	
}

void inicializaTipos(Espacio*, Pelota*, Raqueta* raquetaIzq, Raqueta* raquetaDer){
	
}
