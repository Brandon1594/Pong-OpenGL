/* Funciones para dibujar los tipos de Pong en OpenGL */

#include <Espacio.h>
#include <Pelota.h>
#include <Raqueta.h>

#include <glut.h>

void inicializaTiposNormales(Espacio*, Pelota*, Raqueta* raquetaIzq, Raqueta* raquetaDer);
void inicializaOGL(int ventanaAncho, int ventanaAlto);

void dibujaEspacio(Espacio*);
void dibujaPelota(Pelota*);
void dibujaRaqueta(Rauqeta*);

void teclas(unsigned char tecla, int x, int y);
void raton(int boton, int estado, int x, int y);
void escalarVentana(int x, int y);
