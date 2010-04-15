/* Interfaz Raqueta */

#ifndef _RAQUETA
#define _RAQUETA

#include<Espacio.h>
#include<PongException.h>
#include<Vector.h>
#include<TipoRebote.h>

class Raqueta {
	public:
		void mueveteArriba() const = 0;
		void mueveteAbajo() const = 0;
		void incrPuntos() const = 0;
		int getPosX() const = 0;
		int getPosY() const = 0;
		int getPuntos() const = 0;
		void reset() const = 0;
};

#endif
