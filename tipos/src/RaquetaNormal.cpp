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
 * 		int ancho;	//Es la mitad del ancho de la raqueta
 *		int alto;	//Es la mitad del largo de la raqueta
 * 
 * 		const Espacio* espacio;
 */

RaquetaNormal::RaquetaNormal(int pos_x, int an, int al, int vel, Espacio*& esp) :
	posX(pos_x),
	velocidad(vel),
	ancho(an),
	alto(al),
	puntuacion(0),
	espacio(esp)
{
	if(alto > espacio->getAlto()/2)
		throw PongException("El alto de la raqueta no puede ser mayor que el alto del espacio.");

	posY = espacio->getAlto()/2;
	puntuacion = 0;
}

void RaquetaNormal::mueveteArriba(){
	posY += velocidad;
	if((posY + alto) > espacio->getAlto()) posY = espacio->getAlto() - alto;
}

void RaquetaNormal::mueveteAbajo(){
	posY -= velocidad;
	if((posY - alto) < 0) posY = alto; 
}

void RaquetaNormal::incrPuntos(){ puntuacion++; }

TipoColision RaquetaNormal::hayColision(Vector posicion, int radio) const {
	
	TipoColision tColision;
	double x = posicion.x;
	double y = posicion.y;

	if(
		(
			(x - radio < posX + ancho && x + radio > posX - ancho) ||	//Raqueta Izq
			(x - radio > posX + ancho && x + radio < posX - ancho) 		//Raqueta Der
		) && 
		y < posY + alto &&
		y > posY - alto)
	{
		tColision = NORMAL;
	}
	else
		tColision = NO_COLISION;

	return tColision;
}

Vector RaquetaNormal::getRebote(Pelota* pelota) const{
	
	//Calculamos la aceleración del rebote
	Vector aceleracion = {
		aceleracion.x = -2 * pelota->getVel().x,
		aceleracion.y = 0
	};
	
	return aceleracion;	
}

Vector RaquetaNormal::getPosicionColision(Vector posicion, Vector postPosicion, int radio) const{
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
    
    double Y,y,X,x;
    Vector posicionColision;
    
    if((X = posicion.x - postPosicion.x) > 0){	//Raqueta Izq
		x = posicion.x - posX - ancho - radio;
		Y = posicion.y - postPosicion.y;
		y = Y*x/X;
		posicionColision.x = posicion.x - x;
		posicionColision.y = posicion.y + y;
	}
	else{										//Raqueta Der
		x = posX - posicion.x - ancho - radio;
		Y = posicion.y - postPosicion.y;
		y = Y*x/X;
		posicionColision.x = posicion.x + x;
		posicionColision.y = posicion.y + y;
	}	 
	
	return posicionColision;
	
}

int RaquetaNormal::getPosX() const { return posX; }
int RaquetaNormal::getPosY() const { return posY; }
int RaquetaNormal::getAncho() const { return ancho; }
int RaquetaNormal::getAlto() const { return alto; }
int RaquetaNormal::getPuntos() const { return puntuacion; }

void RaquetaNormal::reset(){
	posY = espacio->getAlto()/2;
	puntuacion = 0;
}
