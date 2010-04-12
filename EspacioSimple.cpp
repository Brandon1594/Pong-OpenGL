/* Implementación de un Espacio simple. 
 * Este espacio solo dispone de dimensiones, un espacio más complejo
 * podría disponer también de fuerzas, cambios de tamaño, etc.
 */

#include<Espacio.h>

class EspacioSimple : public Espacio {
	private:
		int ancho;
		int alto;

	public:
		EspacioSimple(int an, int al) : ancho(an),alto(al) {}

		int getAncho() const{
			return ancho;
		}

		int getAlto() const{
			return alto;
		}
};
