/* Interfaz Raqueta */

#ifndef _RAQUETA
#define _RAQUETA

#include <Espacio.h>
#include <Vector.h>
#include <TipoColision.h>

class Raqueta {
	public:
		virtual void mueveteArriba() = 0;
		virtual void mueveteAbajo() = 0;
		virtual void incrPuntos() = 0;
		virtual TipoColision hayColision(Pelota*) const = 0;
		virtual Vector getRebote(Pelota*) const = 0;
		virtual int getPosX() const = 0;
		virtual int getPosY() const = 0;
		virtual int getAncho() const = 0;
		virtual int getAlto() const = 0;
		virtual int getPuntos() const = 0;
		virtual void reset() = 0;
};

#endif
