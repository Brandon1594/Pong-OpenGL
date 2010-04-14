/* Interfaz Espacio  */

#ifndef _ESPACIO
#define _ESPACIO

#include<Vector.h>
#include<TipoColision.h>
#include<PongException.h>

class Espacio {
	public:
		virtual int getAncho() const = 0;
		virtual int getAlto() const = 0;
		virtual hayColision(Vector posicion) const = 0;
		virtual getRebote(Vector velocidad) const = 0;
};

#endif
