/* Tipo PelotaNormal */

#include<Pelota.h>
#include<cmath>

//Ángulo máximo de salida para el reset(int modVel)
const ANG_MAX_SAL = M_PI/3;	//En radianes (60º)

class PelotaNormal : public Pelota {
	private:
		Vector posicion;
		Vector velocidad;
		int radio;
		
		Raqueta* raquetaI;
		Raqueta* raquetaD;
		Espacio* espacio;

	public:
		PelotaNormal(int modVel, Raqueta* raqI, Raqueta* raqD, Espacio* esp) :
			raquetaI(raqI),
			raquetaD(raqD),
			espacio(esp)
		{
			srand(time(NULL));	//Ponemos la semilla del random con la hora actual
			reset(modVel);	//Ponemos la posicion inicial y la velocidad aleatoria
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
					resetGol();
					
				}
				if(colisionEsp == GOL_DER){
					raquetaI->incrPuntos();
					resetGol();
				}
				
			}
			else if(colisionRaqI)
				velocidad += raquetaI->getRebote(posicion,velocidad);
			
			else if(colisionRaqI)
				velocidad += raquetaD->getRebote(posicion,velocidad);
		}
		
		Vector getPos(){	return posicion;	}

		void reset(int modVel){
			//Reseteamos la posición
			posicion.x = espacio->getAncho()/2;
			posicion.y = espacio->getAlto()/2;
			
			//Ponemos a la velocidad una dirección aleatoria
			velocidad.x = rand()%(modVel+1) - modVel;
			velocidad.y = rand()% (int)( tan( ANG_MAX_SAL )/velocidad.x +1 ) - modVel;
			//Aseguramos el módulo del vector
			velocidad.x = (int) sqrt( pow(modVel,2) - pow(velocidad.y,2));
		}

	private:
		void resetGol(){
			//Reseteamos la posición
			posicion.x = espacio->getAncho()/2;
			posicion.y = espacio->getAlto()/2;
			
			//Ponemos a la velocidad una dirección horizontal del mismo sentido anterior.
			if(velocidad.x < 0)
				velocidad.x = (int) -sqrt( pow(modVel,2) - pow(velocidad.y,2));
			else
				velocidad.x = (int) sqrt( pow(modVel,2) - pow(velocidad.y,2));
				
			velocidad.y = 0;
		}
}
