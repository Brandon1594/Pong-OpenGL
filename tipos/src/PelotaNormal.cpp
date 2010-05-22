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

	//Comprobamos las colisiones
	TipoColision colisionEsp = espacio->hayColision(postPosicion, radio);
	TipoColision colisionRaqI = raquetaI->hayColision(postPosicion, radio);
	TipoColision colisionRaqD = raquetaD->hayColision(postPosicion, radio);
	
	//Según la colisión y su tipo, calcularemos dónde colisiona la pelota y
	//tarda en hacerlo
	Vector posicionColision;
	double tiempoColision;

	switch(colisionEsp){
		case NORMAL:
			posicionColision = espacio->getPosicionColision(posicion,postPosicion,radio);
			tiempoColision = mod(posicionColision-posicion)/mod(velocidad);
			
			//Restamos al tiempo total de iteración el tiempo que ha consumido
			//mover la pelota hasta la posición de colisión
			tiempo -= tiempoColision;
			
			//Actualizamos la posición y la velocidad
			posicion = posicionColision;
			velocidad += espacio->getRebote(velocidad);
			
			//LLamada recursiva con el nuevo tiempo
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
				posicionColision = raquetaI->getPosicionColision(posicion,postPosicion,radio);
				tiempoColision = mod(posicionColision-posicion)/mod(velocidad);
				
				//Restamos al tiempo total de iteración el tiempo que ha consumido
				//mover la pelota hasta la posición de colisión
				tiempo -= tiempoColision;
							
				//Actualizamos la posición y la velocidad
				posicion = posicionColision;
				velocidad += raquetaI->getRebote(this);
				
				//LLamada recursiva con el nuevo tiempo
				muevete(tiempo);
			}

			else if(colisionRaqD){
				posicionColision = raquetaD->getPosicionColision(posicion,postPosicion,radio);
				tiempoColision = mod(posicionColision-posicion)/mod(velocidad);
				
				//Restamos al tiempo total de iteración el tiempo que ha consumido
				//mover la pelota hasta la posición de colisión
				tiempo -= tiempoColision;
				
				//Actualizamos la posición y la velocidad
				posicion = posicionColision;			
				velocidad += raquetaD->getRebote(this);
				
				//LLamada recursiva con el nuevo tiempo
				muevete(tiempo);
			}
			else
				//Si no ha colisionado llegamos al caso base, dónde avanzamos la
				//pelota el tiempo restante
				posicion += velocidad*tiempo;
				
		break;
	}
		
}

Vector PelotaNormal::getPos() const{ return posicion; }
int PelotaNormal::getRadio() const{ return radio; }
Vector PelotaNormal::getVel() const{ return velocidad; }

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
