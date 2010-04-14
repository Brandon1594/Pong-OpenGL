/* Tipo RauquetaSimple */
/*
 * RaquetaSimple implementa un rebote basado en la posición
 * donde la pelota colisiona con la raqueta
 */

#include<Raqueta.h>
#include<Espacio.h>
#include<Pelota.h>
#include<PongException.h>
#include<Vector.h>
#inclide<TipoColision.h>

// Determina la convexidad(positivo) concavidad(negativo) de la raqueta, siendo 0 un espejo.
const int CONVEXIDAD = 2;

class RaquetaSimple : public Raqueta {
	private:
		const int posX;
		int posY;
		int velocidad;
		int puntuacion;
		int tamanio;

		const Espacio* espacio;
		const Pelota* pelota;

	public:
	
		//Constructor
		RaquetaSimple(int pos_x, int vel, int tam) : velocidad(vel), posX(pos_x){
			if(tam > espacio)	throw PongException("El tamaño de la raqueta no puede ser mayor que el ancho del espacio.");
			tamanio = tam;
			posY = espacio->getAlto()/2;
			puntuacion = 0;
		}
		
		
		TipoColision hayColision(int x, int y){
			
			TipoColision tColision;
		
			if(pelota->getX() == posX &&
			   pelota->getY() <= posY + tamanio &&
			   pelota->getY() >= posY - tamanio){
			   
			   tColision = COLISION;			
			}
			else{
			tColision = NO_COLISION;
			}
			return tColision;
		}
		
		Vector getRebote(Vector velocidad){
			Vector aceleracion;
			//'variacion' es un numero entre -1 y 1 que se usará para escalar las componentes
			//de la aceleracion en función del punto de colisión de la pelota
			int variacion = tamanio/(tamanio + pelota->getY() - posY);
				
			aceleracion.x = 2 * pelota->velocidad.x;
			aceleracion.y = 2 * pelota->velocidad.y * variacion;
				
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
		void decrPunt(){	puntuacion--;	 }
		
		int getPosX(){	return posX;	}
		int getPosY(){	return posY;	}
		int getPuntos(){	return puntuacion;	}
		
		
};
