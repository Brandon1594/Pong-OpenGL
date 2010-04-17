/* Tipo RaquetaNormal */
/*
 * RaquetaNormal implementa un rebote basado en la posición
 * donde la pelota colisiona con la raqueta
 */

#include <RaquetaNormal.h>

/* CONSTANTES
 * 	const int CONVEXIDAD = 2;
 */

/* ATRIBUTOS
 * 	private:
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
	int x = posicion.x;
	int y = posicion.y;

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

Vector RaquetaNormal::getRebote(Vector posicion, Vector velocidad) const{
	//'variacion' es un numero entre -1 y 1 que se usará para escalar las componentes
	//de la aceleracion en función del punto de colisión de la pelota
	int variacion;
	int distAlCentro = posicion.x - posY;
	//Contemplamos el signo de la distancia
	if(distAlCentro > 0)
		variacion = tamanio/(tamanio + distAlCentro);
	else
		variacion = -tamanio/(tamanio - distAlCentro); 
		
	//Calculamos la aceleración del rebote
	Vector aceleracion = {
		aceleracion.x = -2 * velocidad.x,
		aceleracion.y = CONVEXIDAD * velocidad.y * variacion
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
