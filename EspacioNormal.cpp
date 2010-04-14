/* Implementación de un Espacio simple. 
 * Este espacio solo dispone de dimensiones, un espacio más complejo
 * podría disponer también de fuerzas, cambios de tamaño, etc.
 */

#include<Espacio.h>

class EspacioNormal : public Espacio {
	private:
		int ancho;
		int alto;

	public:
		EspacioSimple(int an, int al) : ancho(an),alto(al) {
			if(ancho <= 0 || alto <= 0)
				throw PongException("No se admite una dimensión negativa o nula");

		//Comprobación de colisiones con la pelota.
		TipoColision hayColision(Vector posicion) const{
			
			TipoColision tColision;
			
			if(posicion.x == ancho)
				tColision = GOL_DER;
			
			else if(posicion.x == 0)
				tColision = GOL_IZQ;
			
			if(posicion.y == alto || posicion.y == 0)
				tColision = COLISION;

			else
				tColision = NO_COLISION;
			

			return tColision;
		}
		
		//Devuelve la aceleración normal que genera el rebote
		Vector getRebote(Vector velocidad) const{
			Vector aceleracion = 
				{aceleracion.x = 2 * pelota->velocidad.x , aceleracion.y = 2 * pelota->velocidad.y}	

			return aceleracion;	
		}

		//Consultores
		int getAncho() const{
			return ancho;
		}

		int getAlto() const{
			return alto;
		}
};
