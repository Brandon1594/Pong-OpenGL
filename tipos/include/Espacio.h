/* Interfaz Espacio  */

#ifndef _ESPACIO
#define _ESPACIO

#include <Vector.h>
#include <Pelota.h>
#include <TipoColision.h>

class Espacio {
	public:
		virtual int getAncho() const = 0;
		virtual int getAlto() const = 0;
		virtual TipoColision hayColision(Pelota*) const = 0;
		virtual Vector getRebote(Vector velocidad) const = 0;
};

#endif
