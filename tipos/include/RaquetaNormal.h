/* Tipo RaquetaNormal */
/*
 * RaquetaNormal implementa un rebote basado en la posición
 * donde la pelota colisiona con la raqueta
 */

#ifndef _RAQUETA_NORMAL
#define _RAQUETA_NORMAL

#include <Raqueta.h>

// Determina la convexidad(positivo) concavidad(negativo) de la raqueta, siendo 0 un espejo.
const int CONVEXIDAD = 2;

class RaquetaNormal : public Raqueta {
	private:
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
