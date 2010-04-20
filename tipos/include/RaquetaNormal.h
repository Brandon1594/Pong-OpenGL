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
		int tamanio;	//Es la mitad del largo de la raqueta
		int ancho;

		const Espacio* espacio;

	public:
		RaquetaNormal(int pos_x, int tam, int an, int vel, Espacio*& esp);
		
		void mueveteArriba();
		void mueveteAbajo();
		void incrPuntos();
		TipoColision hayColision(Vector posicion, int radio) const;		
		Vector getRebote(Vector posicion, Vector velocidad) const;	
		int getPosX() const;
		int getPosY() const;
		int getTamanio() const;
		int getAncho() const;
		int getPuntos() const;
		void reset();
};

#endif
