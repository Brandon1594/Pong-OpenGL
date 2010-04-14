/* Tipo PelotaNormal */

#include<Pelota.h>

class PelotaNormal : public Pelota {
	private:
		Vector posicion;
		Vector velocidad;
		int radio;
		
		Raqueta* raquetaI;
		Raqueta* raquetaD;
		Espacio* espacio;

	public:
		PelotaNormal(Vector vel, Raueta* raqI, Raqueta* raqD, Espacio* esp) :
			velocidad(vel),
			raquetaI(raqI),
			raquetaD(raqD),
			espacio(esp)
		{
			srand(time(NULL));	//Ponemos la semilla del random con la hora actual
		}

		void muevete(){
			Posicion += velocidad;

			TipoColision colisionEsp = espacio->hayColision(posicion,radio);
			TipoColision colisionRaqI = raquetaI->hayColision(posicion,radio);
			TipoColision colisionRaqD = raquetaD->hayColision(posicion,radio);

			if(colisionEsp){
				velocidad += espacio->getRebote(posicion);
			
				if(colisionEsp == GOL_IZQ){
					raquetaD->incrPuntos();
					//Reseteamos la posición
					posicion.x = espacio->getAncho()/2;
					posicion.y = espacio->getAlto()/2;
					
				}
				if(colisionEsp == GOL_DER){
					raquetaI->incrPuntos();
					//Reseteamos la posición
					posicion.x = espacio->getAncho()/2;
					posicion.y = espacio->getAlto()/2;
				}
				
			}
			else if(colisionRaqI)
				velocidad += raquetaI->getRebote(posicion,velocidad);
			
			else if(colisionRaqI)
				velocidad += raquetaD->getRebote(posicion,velocidad);
		}
		
		Vector getPos(){	return posicion;	}
		
		void reset(){
			//Reseteamos la posición
			posicion.x = espacio->getAncho()/2;
			posicion.y = espacio->getAlto()/2;
			
			//Ponemos una dirección aleatoria a la velocidad
			//Creamos un vector aleatorio
			//TODO
		}
}
