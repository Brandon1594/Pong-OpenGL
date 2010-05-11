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
	 * raqueta, si es así la pelota "se ha pasado", hay que calcular dónde
	 * tendría que haber chocado y la porción de iteración (tiempo) que tardará
	 * en hacerlo.Con estos datos se vuelve ha repetir recursivamente el proceso
	 * hasta completar la iteración.
	 * 
	 * Para calcular el punto de colisión con la raqueta y el espacio y el
	 * tiempo que queda hasta que colisione usamos la proporcionalidad
	 * entre triángulos tal y como se muestra en el esquema: 
                                O  _  _ 
                             | /|   |  |
                             |/ |   |y |          Y/y = X/x
                             *__|  _|  |Y
                            /|  |      |          y = Yx/X
                           /_|__|     _|
                          O  '    
                             |__|
                              x
                          |_____|
                             X
    */
    
    Vector postPosicion = posicion + velocidad*tiempo;

	TipoColision colisionEsp = espacio->hayColision(postPosicion,radio);
	TipoColision colisionRaqI = raquetaI->hayColision(postPosicion,radio);
	TipoColision colisionRaqD = raquetaD->hayColision(postPosicion,radio);

	switch(colisionEsp){
		case NORMAL:
			//TODO: Calcular tiempo ¿espacio->getTiempoColision(posicion,postPosicion,radio)?
			
			posicion += velocidad*tiempo;
		
			velocidad += espacio->getRebote(velocidad);
		break;

		case GOL_IZQ:
			raquetaD->incrPuntos();
			resetGol();
		break;
	
		case GOL_DER:
			raquetaI->incrPuntos();
			resetGol();
		break;
	}
	
	if(colisionRaqI){
		//TODO: Calcular tiempo	¿raquetaI->getTiempoColision(posicion,postPosicion,radio)?
		
		posicion += velocidad*tiempo;
		
		velocidad += raquetaI->getRebote(posicion,velocidad);
	}

	else if(colisionRaqD){
		//TODO: Calcular tiempo	¿raquetaD->getTiempoColision(posicion,postPosicion,radio)?
		
		posicion += velocidad*tiempo;
		
		velocidad += raquetaD->getRebote(posicion,velocidad);
	}
	
	
	if(!colisionEsp && !colisionRaqI && !colisionRaqD){
		posicion += velocidad*tiempo;
		//tiempo = 0.0;
	}
	else	muevete(tiempo);
	
       
       /*double X = posicion.x - postPosicion.x;
		double x = X - ( (posX + ancho) - postPosicion.x );
		double Y = postPosicion.y - posicion;
			
		double y = Y*x/X;
			
		double X = postPosicion.x - posicion.x;
		double x = X - ( postPosicion.x - (posX - ancho) );
		double Y = postPosicion.y - posicion;
		
		double y = Y*x/X;
		*/
	
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
