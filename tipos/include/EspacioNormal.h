/* Implementación de un Espacio simple. 
 * Este espacio solo dispone de dimensiones, un espacio más complejo
 * podría disponer también de fuerzas, cambios de tamaño, etc.
 */
#ifndef _ESPACIO_NORMAL
#define _ESPACIO_NORMAL

#include <Espacio.h>
#include <PongException.h>
#include <cmath>

class EspacioNormal : public Espacio {
	private:
		const int ancho;
		const int alto;

	public:
		EspacioNormal(int an, int al);
		
		TipoColision hayColision(Vector posicion, int radio) const;
		Vector getRebote(Vector velocidad) const;
		Vector getPosicionColision(Vector posicion, Vector postPosicion, int radio) const;
		int getAncho() const;
		int getAlto() const;
};

#endif
