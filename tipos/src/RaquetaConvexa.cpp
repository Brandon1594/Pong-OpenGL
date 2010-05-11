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
 * 		int ancho;	//Es la mitad del ancho de la raqueta
 * 		int alto;	//Es la mitad del largo de la raqueta
 * 
 * 		const Espacio* espacio;
 * 
 *  RaquetaConvexa:
 * 		const int distFocal;	//Distancia del foco al centro de la raqueta
 */

#include <RaquetaConvexa.h>

RaquetaConvexa::RaquetaConvexa(int pos_x, int an, int al, int vel, Espacio*& esp,int distF) :
	RaquetaNormal(pos_x,an,al,vel,esp),
	distFocal(distF)
{
		if(distFocal == 0)
			throw PongException("La distancia focal no puede ser nula");
}

Vector RaquetaConvexa::getRebote(Pelota* pelota) const{
	
	Vector direccion = { -distFocal , pelota.getPos().y - posY };
	
	Vector nuevaVelocidad = (direccion/mod(direccion)) * fabs(pelota.getVel().x);
	nuevaVelocidad.y += pelota.getVel().y;
	
	Vector aceleracion = nuevaVelocidad - pelota.getVel();
	
	return aceleracion;
	
}
