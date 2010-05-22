/* Interfaz Pelota */

#ifndef _PELOTA
#define _PELOTA


#include <Vector.h>
#include <TipoColision.h>

class Pelota {
	public:
		virtual void muevete() = 0;
		virtual Vector getPos() const = 0;
		virtual int getRadio() const = 0;
		virtual Vector getVel() const = 0;
		virtual void reset(double modVel) = 0;
		virtual void reset() = 0;
};

#include <Raqueta.h>
#include <Espacio.h>

#endif
