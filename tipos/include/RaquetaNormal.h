/* Tipo RaquetaNormal */
/*
 * RaquetaNormal implementa un rebote normal, es decir,
 * la pelota sale rebotada con el mismo ángugo con el que entra
 * a colisionar.
 */

#ifndef _RAQUETA_NORMAL
#define _RAQUETA_NORMAL

#include <Raqueta.h>
#include <PongException.h>

class RaquetaNormal : public Raqueta {
	protected:
		const int posX;
		int posY;
		int velocidad;
		int puntuacion;
		int ancho;	//Es la mitad del ancho de la raqueta
		int alto;	//Es la mitad del largo de la raqueta

		const Espacio* espacio;

	public:
		RaquetaNormal(int pos_x, int an, int al, int vel, Espacio*& esp);
		
		void mueveteArriba();
		void mueveteAbajo();
		void incrPuntos();
		TipoColision hayColision(Pelota*) const;		
		Vector getRebote(Pelota*) const;	
		int getPosX() const;
		int getPosY() const;
		int getAncho() const;
		int getAlto() const;
		int getPuntos() const;
		void reset();
};

#endif
