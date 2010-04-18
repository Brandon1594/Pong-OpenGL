/* Tipo PelotaNormal */

#ifndef _PELOTA_NORMAL
#define _PELOTA_NORMAL

#include <Pelota.h>
#include <cstdlib>
#include <cmath>
#include <ctime>

//Ángulo máximo de salida para el reset(int modVel)
const double ANG_MAX_SAL = M_PI/3;	//En radianes (60º)

class PelotaNormal : public Pelota {
	private:
		Vector posicion;
		Vector velocidad;
		int radio;
		
		Raqueta* raquetaI;
		Raqueta* raquetaD;
		Espacio* espacio;

	public:
		PelotaNormal(double modVel, int radio, Raqueta*& raqI, Raqueta*& raqD, Espacio*& esp);

		void muevete();		
		Vector getPos() const;
		int getRadio() const;
		void reset(double modVel);
		void reset();
		
	private:
		void resetGol();
};

#endif
