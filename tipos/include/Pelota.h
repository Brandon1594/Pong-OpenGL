/* Interfaz Pelota */

#ifndef _PELOTA
#define _PELOTA

#include<Raqueta.h>
#include<Espacio.h>
#include<Vector.h>
#include<TipoColision.h>
#include<PongException.h>

class Pelota {
	public:
		virtual void muevete() = 0;
		virtual Vector getPos() const = 0;
		virtual int getRadio() const = 0;
		virtual void reset(int modVel) = 0;
};

#endif
