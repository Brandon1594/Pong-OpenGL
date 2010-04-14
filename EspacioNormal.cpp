/* Implementación de un Espacio simple. 
 * Este espacio solo dispone de dimensiones, un espacio más complejo
 * podría disponer también de fuerzas, cambios de tamaño, etc.
 */

#include<Espacio.h>
#include<TipoColision.h>

class EspacioSimple : public Espacio {
	private:
		int ancho;
		int alto;
		Pelota* pelota;

	public:
		//Constructor.
		EspacioSimple(int an, int al) : ancho(an),alto(al) {}

		//Comprobación de colisiones de la pelota.
		TipoColision hayColision(int x, int y){
			
			TipoColision tColision;
		
			
			
			if(x == ancho){
			tColision = GOL_DER;
			}
			else if(x == 0){
			tColision = GOL_IZQ;
			}
			else if(y == alto){
			tColision = COLISION;
			}
			else if(y == 0){
			tColision = COLISION;
			}
			else{
			tColision = NO_COLISION;
			}
			return tColision;
		}
		
		//Envía a la pelota el nuevo vector velocidad.
		Vector getRebote(Vector velocidad){
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
