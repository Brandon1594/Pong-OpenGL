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

PelotaNormal::PelotaNormal(int modVel, int rad, Raqueta*& raqI, Raqueta*& raqD, Espacio*& esp) : 
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

	printf("\nE:%i RI:%i RD:%i",colisionEsp,colisionRaqI,colisionRaqD);
	printf("\n( %i, %i )",velocidad.x,velocidad.y);

	if(colisionEsp){
		velocidad += espacio->getRebote(velocidad);
	
		if(colisionEsp == GOL_IZQ){
			raquetaD->incrPuntos();
			resetGol();
			
		}
		if(colisionEsp == GOL_DER){
			raquetaI->incrPuntos();
			resetGol();
		}
		
	}
	if(colisionRaqI)
		velocidad += raquetaI->getRebote(posicion,velocidad);
	
	else if(colisionRaqD)
		velocidad += raquetaD->getRebote(posicion,velocidad);
}

Vector PelotaNormal::getPos() const{ return posicion; }
int PelotaNormal::getRadio() const{ return radio; }

void PelotaNormal::reset(int modVel){
	//Reseteamos la posición
	posicion.x = espacio->getAncho()/2;
	posicion.y = espacio->getAlto()/2;
	
	//Ponemos a la velocidad una dirección aleatoria
	velocidad.x = rand()%(modVel+1) - modVel;
	velocidad.y = rand()% (int)( tan( ANG_MAX_SAL )/velocidad.x +1  - modVel);
	//Aseguramos el módulo del vector
	velocidad.x = (int) sqrt( pow(modVel,2) - pow(velocidad.y,2));
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
