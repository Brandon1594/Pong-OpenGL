/* Implementación de un Espacio simple. 
 * Este espacio solo dispone de dimensiones, un espacio más complejo
 * podría disponer también de fuerzas, cambios de tamaño, etc.
 */

#include<EspacioNormal.h>

/* ATRIBUTOS
 * 	private:
 * 		const int ancho;
 * 		const int alto;
 */

EspacioNormal::EspacioNormal(int an, int al) : ancho(an),alto(al) {
	if(ancho <= 0 || alto <= 0)
		throw PongException("No se admite una dimensión negativa o nula");
}

//Comprobación de colisiones con la pelota.
TipoColision EspacioNormal::hayColision(Vector posicion, int radio) const{
	
	TipoColision tColision;
	
	if(posicion.x + radio >= ancho)
		tColision = GOL_DER;
	
	else if(posicion.x - radio <= 0)
		tColision = GOL_IZQ;
	
	if(posicion.y + radio >= alto || posicion.y - radio <= 0)
		tColision = NORMAL;

	else
		tColision = NO_COLISION;
	

	return tColision;
}

//Devuelve la aceleración normal que genera el rebote
Vector EspacioNormal::getRebote(Vector velocidad) const{
	Vector aceleracion = 
		{0, -2 * velocidad.y};

	return aceleracion;
}

//Consultores
int EspacioNormal::getAncho() const{
	return ancho;
}

int EspacioNormal::getAlto() const{
	return alto;
}
