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
		void muevete() const = 0;
		Vector getPos() const = 0;
		void reset() const = 0;
}

#endif
