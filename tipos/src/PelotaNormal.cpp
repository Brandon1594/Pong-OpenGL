/* Tipo PelotaNormal */

#include <PelotaNormal.h>

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

	muevete(1.0);
	
}

void PelotaNormal::muevete(double tiempo){
	
	/* Primero se comprueba si la pelota va ha estar en el interior de la
	 * raqueta o del espacio(hayColision), si es así la pelota "se ha pasado", 
	 * hay que calcular dónde tendría que haber chocado y la porción de
	 * iteración (tiempo) que tardará en hacerlo. Con estos datos se vuelve ha
	 * repetir recursivamente el proceso hasta completar la iteración.
	 */
    
    Vector postPosicion = posicion + velocidad*tiempo;

	TipoColision colisionEsp = espacio->hayColision(this);
	TipoColision colisionRaqI = raquetaI->hayColision(this);
	TipoColision colisionRaqD = raquetaD->hayColision(this);

	switch(colisionEsp){
		case NORMAL:
			Vector posicionColision = espacio->getPosicionColision(posicion,postPosicion,radio);
			double tiempoColision = mod(posicionColision)/mod(velocidad);
			tiempo -= tiempoColision;
			
			posicion = posicionColision;		
			velocidad += espacio->getRebote(velocidad);
			
			muevete(tiempo);
		break;

		case GOL_IZQ:
			raquetaD->incrPuntos();
			resetGol();
		break;
	
		case GOL_DER:
			raquetaI->incrPuntos();
			resetGol();
		break;
		
		default:
		
			if(colisionRaqI){
				Vector posicionColision = raquetaI->getPosicionColision(posicion,postPosicion,radio);
				double tiempoColision = mod(posicionColision)/mod(velocidad);
				tiempo -= tiempoColision;
							
				posicion = posicionColision;
				velocidad += raquetaI->getRebote(posicion,velocidad);
				
				muevete(tiempo);
			}

			else if(colisionRaqD){
				Vector posicionColision = raquetaD->getPosicionColision(posicion,postPosicion,radio);
				double tiempoColision = mod(posicionColision)/mod(velocidad);
				tiempo -= tiempoColision;
							
				posicion += velocidad*tiempoColision;
							
				posicion = posicionColision;			
				velocidad += raquetaD->getRebote(posicion,velocidad);
				
				muevete(tiempo);
			}
			else
				posicion += velocidad*tiempo;
				
		break;
	}
		
}

Vector PelotaNormal::getPos() const{ return posicion; }
int PelotaNormal::getRadio() const{ return radio; }
Vector getVel() const{ return velocidad; }

void PelotaNormal::reset(double modVel){
	//Centramos la pelota en el campo
	posicion.x = espacio->getAncho()/2;
	posicion.y = espacio->getAlto()/2;
	
	//Calculamos un ángulo aleatorio positivo
	double angulo = fmod(rand(),ANG_MAX_SAL);
	
	//Calculamos las componentes de la velocidad
	//TODO: Con ceil el módulo de la velocidad es cada vez mayor y con floor al revés
	velocidad.x = modVel * cos(angulo);
	velocidad.y = modVel * sin(angulo);
	
	//Ponemos aleatoriamente el ángulo de salida negativo o hacia la izquierda
	if(rand()%2)	velocidad.y = -velocidad.y;
	if(rand()%2)	velocidad.x = -velocidad.x;
}

void PelotaNormal::reset(){
	reset( mod(velocidad) );
}

void PelotaNormal::resetGol(){
	//Reseteamos la posición
	posicion.x = espacio->getAncho()/2;
	posicion.y = espacio->getAlto()/2;
	
	//Ponemos a la velocidad una dirección horizontal del mismo sentido anterior.
	if(velocidad.x < 0)
		velocidad.x = -mod(velocidad);
	else
		velocidad.x = mod(velocidad);
		
	velocidad.y = 0;
}
