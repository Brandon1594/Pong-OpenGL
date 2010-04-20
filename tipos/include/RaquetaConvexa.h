/* Tipo RaquetaConvexa */
/*
 * RaquetaConvexa implementa un rebote basado en
 * la reflexión de un espejo convéxo.
 * 
 * Hereda de RaquetaConvexa y sobrecarga el método
 * "getRebote".
 */

#include <RaquetaNormal.h>

#ifndef _RAQUETA_CONVEXA
#define _RAQUETA_CONVEXA

class RaquetaConvexa : public RaquetaNormal {
	private:
		const int distFocal;	//Distancia del foco al centro de la raqueta en píxeles
	
	public:
		RaquetaConvexa(int pos_x, int tam, int an, int vel, Espacio*& esp, int distFocal);
	
		Vector getRebote(Vector posicion, Vector velocidad) const;

};

#endif
