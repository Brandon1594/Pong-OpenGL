/* Tipo RaquetaConvexa */
/*
 * RaquetaConvexa implementa un rebote basado en
 * la reflexión de un espejo convéxo.
 * 
 * Hereda de RaquetaConvexa y sobrecarga el método
 * "getRebote".
 */

 /* ATRIBUTOS
 * 	RaquetaNormal:
 * 		const int posX;
 * 		int posY;
 * 		int velocidad;
 * 		int puntuacion;
 * 		int tamanio;	//Es la mitad del largo de la raqueta
 * 		int ancho;
 * 
 * 		const Espacio* espacio;
 * 
 *  RaquetaConvexa:
 * 		const int distFocal;
 */

#include <RaquetaConvexa.h>
#include <PongException.h>

RaquetaConvexa::RaquetaConvexa(int pos_x, int tam, int an, int vel, Espacio*& esp,int distF) :
	RaquetaNormal(pos_x,tam,an,vel,esp),
	distFocal(distF)
{
		if(distFocal == 0)
			throw PongException("La distancia focal no puede ser nula");
}

Vector RaquetaConvexa::getRebote(Vector posicion, Vector velocidad) const{
	
	Vector direccion = {-distFocal , posicion.y - posY};
	
	//Falla debido a los casting de double a int
	Vector nuevaVelocidad = direccion/(mod(direccion) * velocidad.x);
	nuevaVelocidad.y += velocidad.y;
	
	Vector aceleracion = nuevaVelocidad - velocidad;
	
	return aceleracion;
	
}
