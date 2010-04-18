/* Tipo PelotaNormal */

#include <PelotaNormal.h>
#include <cstdio>
/* CONSTANTES
 * 	const int ANG_MAX_SAL = M_PI/3;	//En radianes (60º)
 */

/* ATRIBUTOS
 * 	private:
 * 		Vector posicion;
 * 		Vector velocidad;
 * 		int radio;
 * 		
 * 		Raqueta* raquetaI;
 * 		Raqueta* raquetaD;
 * 		Espacio* espacio;
 */

PelotaNormal::PelotaNormal(double modVel, int rad, Raqueta*& raqI, Raqueta*& raqD, Espacio*& esp) : 
	radio(rad),
	raquetaI(raqI),
	raquetaD(raqD),
	espacio(esp)
{	
	srand(time(NULL));	//Ponemos la semilla del random con la hora actual
	reset(modVel);	//Ponemos la posicion inicial y la velocidad aleatoria
}

void PelotaNormal::muevete(){
	posicion += velocidad;

	TipoColision colisionEsp = espacio->hayColision(posicion,radio);
	TipoColision colisionRaqI = raquetaI->hayColision(posicion,radio);
	TipoColision colisionRaqD = raquetaD->hayColision(posicion,radio);

	//printf("\nE:%i RI:%i RD:%i",colisionEsp,colisionRaqI,colisionRaqD);
	//printf("\n( %i, %i )",velocidad.x,velocidad.y);

	switch(colisionEsp){
		case NORMAL:
			velocidad += espacio->getRebote(velocidad);
		break;
		
		case  GOL_IZQ:
			raquetaD->incrPuntos();
			resetGol();
		break;
	
		case GOL_DER:
			raquetaI->incrPuntos();
			resetGol();
		break;
		
	}
	
	if(colisionRaqI)
		velocidad += raquetaI->getRebote(posicion,velocidad);
		
	else if(colisionRaqD)
		velocidad += raquetaD->getRebote(posicion,velocidad);
}

Vector PelotaNormal::getPos() const{ return posicion; }
int PelotaNormal::getRadio() const{ return radio; }

void PelotaNormal::reset(double modVel){
	//Centramos la pelota en el campo
	posicion.x = espacio->getAncho()/2;
	posicion.y = espacio->getAlto()/2;
	
	//Calculamos un ángulo aleatorio positivo
	double angulo = fmod(rand(),ANG_MAX_SAL);
	
	//Calculamos las componentes de la velocidad
	//TODO: Con ceil el módulo de la velocidad es cada vez mayor y con floor al revés
	velocidad.x = (int)( ceil( modVel * cos(angulo) ) );
	velocidad.y = (int)( ceil( modVel * sin(angulo) ) );
	
	//Ponemos aleatoriamente el ángulo de salida negativo o hacia la izquierda
	if(rand()%2)	velocidad.y = -velocidad.y;
	if(rand()%2)	velocidad.x = -velocidad.x;
}

void PelotaNormal::reset(){
	reset( sqrt( pow(velocidad.x,2) + pow(velocidad.y,2) ) );
}

void PelotaNormal::resetGol(){
	//Reseteamos la posición
	posicion.x = espacio->getAncho()/2;
	posicion.y = espacio->getAlto()/2;
	
	//Ponemos a la velocidad una dirección horizontal del mismo sentido anterior.
	if(velocidad.x < 0)
		velocidad.x = -(int) sqrt( pow(velocidad.x,2) + pow(velocidad.y,2) );
	else
		velocidad.x = (int) sqrt( pow(velocidad.x,2) + pow(velocidad.y,2) );
		
	velocidad.y = 0;
}
