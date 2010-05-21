/* Tipo RaquetaNormal */
/*
 * RaquetaNormal implementa un rebote normal, es decir,
 * la pelota sale rebotada con el mismo ángugo con el que entra
 * a colisionar.
 */

#include <RaquetaNormal.h>

/* ATRIBUTOS
 * 	protected:
 * 		const int posX;
 * 		int posY;
 * 		int velocidad;
 * 		int puntuacion;
 * 		int tamanio;	//Es la mitad del largo de la raqueta
 * 		int ancho;
 * 
 * 		const Espacio* espacio;
 */

RaquetaNormal::RaquetaNormal(int pos_x, int tam, int an, int vel, Espacio*& esp) :
	posX(pos_x),
	velocidad(vel),
	tamanio(tam),
	ancho(an),
	puntuacion(0),
	espacio(esp)
{
	if(tamanio > espacio->getAlto()/2)
		throw PongException("El tamaño de la raqueta no puede ser mayor que el alto del espacio.");

	posY = espacio->getAlto()/2;
	puntuacion = 0;
}

void RaquetaNormal::mueveteArriba(){
	posY += velocidad;
	if((posY + tamanio) > espacio->getAlto()) posY = espacio->getAlto() - tamanio;
}

void RaquetaNormal::mueveteAbajo(){
	posY -= velocidad;
	if((posY - tamanio) < 0) posY = tamanio; 
}

void RaquetaNormal::incrPuntos(){ puntuacion++; }

TipoColision RaquetaNormal::hayColision(Vector posicion, int radio) const {
	
	TipoColision tColision;
	double x = posicion.x;
	double y = posicion.y;

	if(
		(
			(x - radio <= posX + ancho && x + radio >= posX - ancho) ||
			(x - radio <= posX + ancho && x + radio >= posX - ancho) 
		) && 
		y <= posY + tamanio &&
		y >= posY - tamanio)
	{
		tColision = NORMAL;
	}
	else
		tColision = NO_COLISION;

	return tColision;
}

Vector RaquetaNormal::getPosicionColision(Vector posicion, Vector postPosicion, int radio){
	/* Para calcular el punto de colisión con la raqueta y la pelota y el
	 * espacio que queda hasta que colisione usamos la proporcionalidad
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
    
    double X = fabs(posicion.x - postPosicion.x);
	double x = X - (fabs( posX - postPosicion.x ) + ancho + radio );
	double Y = posicion.y - posicion.y;
		
	double y = Y*x/X;
	
	Vector posicionColision = {0,y};
	
	if(posX < posicion.x)	//Raqueta Izquierda
		posicionColision.x = posicion.x - x;
	else	//Raqueta Derecha
		posicionColision.x = posicion.x + x;
	 
	
	return posicionColision;
	
}

Vector RaquetaNormal::getRebote(Vector posicion, Vector velocidad) const{
	
	//Calculamos la aceleración del rebote
	Vector aceleracion = {
		aceleracion.x = -2 * velocidad.x,
		aceleracion.y = 0
	};
	
	return aceleracion;	
}

int RaquetaNormal::getPosX() const { return posX; }
int RaquetaNormal::getPosY() const { return posY; }
int RaquetaNormal::getTamanio() const { return tamanio; }
int RaquetaNormal::getAncho() const { return ancho; }
int RaquetaNormal::getPuntos() const { return puntuacion; }

void RaquetaNormal::reset(){
	posY = espacio->getAlto()/2;
	puntuacion = 0;
}
