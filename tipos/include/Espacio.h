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
		virtual TipoColision hayColision(Vector posicion, int radio) const = 0;
		virtual Vector getRebote(Vector velocidad) const = 0;
		virtual Vector getPosicionColision(Vector posicion, Vector postPosicion, int radio) const = 0;
};

#endif
