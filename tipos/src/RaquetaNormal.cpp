/* Tipo RaquetaNormal */
/*
 * RaquetaNormal implementa un rebote basado en la posición
 * donde la pelota colisiona con la raqueta
 */

#include<Raqueta.h>
#include<TipoColision.h>

// Determina la convexidad(positivo) concavidad(negativo) de la raqueta, siendo 0 un espejo.
const int CONVEXIDAD = 2;

class RaquetaNormal : public Raqueta {
	private:
		const int posX;
		int posY;
		int velocidad;
		int puntuacion;
		int tamanio;

		const Espacio* espacio;

	public:
		//Constructor
		RaquetaNormal(int pos_x, int vel, int tam, Espacio* esp) :
			posX(pos_x),
			velocidad(vel),
			tamanio(tam),
			espacio(esp),
			puntuacion(0)
		{
			if(tamanio > espacio->getAlto()/2)
				throw PongException("El tamaño de la raqueta no puede ser mayor que el alto del espacio.");

			posY = espacio->getAlto()/2;
			puntuacion = 0;
		}
		
		TipoColision hayColision(Vector posicion, int radio){
			
			TipoColision tColision;
		
			if( (posicion.x - radio == posX || posicion.x + radio == posX) && 
			   posicion.y <= posY + tamanio &&
			   posicion.y >= posY - tamanio)
			{
				tColision = NORMAL;
			}
			else
				tColision = NO_COLISION;

			return tColision;
		}
		
		Vector getRebote(Vector posicion, Vector velocidad){
			//'variacion' es un numero entre -1 y 1 que se usará para escalar las componentes
			//de la aceleracion en función del punto de colisión de la pelota
			int variacion;
			int distAlCentro = posicion.x - posY;
			//Contemplamos el signo de la distancia
			if(distAlCentro > 0)
				variacion = tamanio/(tamanio + distAlCentro);
			else
				variacion = -tamanio/(tamanio - distAlCentro); 
				
			//Calculamos la aceleración del rebote
			Vector aceleracion = {
				aceleracion.x = 2 * velocidad.x,
				aceleracion.y = CONVEXIDAD * velocidad.y * variacion
			};
				
			return aceleracion;	
		}
		
		void mueveteArriba(){
			posY += velocidad;
			if(posY + tamanio > espacio->getAlto()) posY = espacio->getAlto();
		}

		void mueveteAbajo(){
			posY -= velocidad;
			if(posY - tamanio < 0) posY = 0; 
		}

		void incrPunt(){	puntuacion++;	 }
		
		int getPosX(){	return posX;	}
		int getPosY(){	return posY;	}
		int getPuntos(){	return puntuacion;	}

		void reset(){
			posY = espacio->getAlto()/2;
			puntuacion = 0;
		}
};
