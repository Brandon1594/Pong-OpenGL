/* Interfaz Raqueta */

#ifndef _RAQUETA
#define _RAQUETA

#include <Espacio.h>
#include <PongException.h>
#include <Vector.h>
#include <TipoColision.h>

class Raqueta {
	public:
		virtual void mueveteArriba() const = 0;
		virtual void mueveteAbajo() const = 0;
		virtual void incrPuntos() const = 0;
		virtual TipoColision hayColision(Vector posicion, int radio) const = 0;
		virtual Vector getRebote(Vector posicion, Vector velocidad) const = 0;
		virtual int getPosX() const = 0;
		virtual int getPosY() const = 0;
		virtual int getPuntos() const = 0;
		virtual void reset() const = 0;
};

#endif
