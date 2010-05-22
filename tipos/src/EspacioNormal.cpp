/* Implementación de un Espacio simple. 
 * Este espacio solo dispone de dimensiones, un espacio más complejo
 * podría disponer también de fuerzas, cambios de tamaño, etc.
 */

#include <EspacioNormal.h>

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
	
	if(posicion.y + radio > alto || posicion.y - radio < 0)
		tColision = NORMAL;

	else
		tColision = NO_COLISION;
	
	if(posicion.x + radio > ancho)
		tColision = GOL_DER;
	
	else if(posicion.x - radio < 0)
		tColision = GOL_IZQ;	

	return tColision;
}

Vector EspacioNormal::getPosicionColision(Vector posicion, Vector postPosicion, int radio) const{
	/* Para calcular el punto de colisión con el campo y la pelota y el
	 * espacio que queda hasta que colisione usamos la proporcionalidad
	 * entre triángulos tal y como se muestra en el esquema: 
                                O  _  _ 
                             | /|   |  |
                             |/ |   |x |          X/x = Y/y
                             *__|  _|  |X
                            /|  |      |          x = Xy/Y
                           /_|__|     _|
                          O  '    
                             |__|
                              y
                          |_____|
                             Y
    */
    
    
    double Y,y,X,x;
    Vector posicionColision;
    
	if( (Y = posicion.y - postPosicion.y) <= 0 ){	//Choca arriba
		Y = -Y;
		y = alto - posicion.y - radio;
		X = posicion.x - postPosicion.x;
		x = X*y/Y;
		
		posicionColision.x = posicion.x - x;
		posicionColision.y = posicion.y + y;
	}
	else{													//Choca abajo
		y = posicion.y - radio;
		X = posicion.x - postPosicion.x;
		X = posicion.x - postPosicion.x;
		x = X*y/Y;
		
		posicionColision.x = posicion.x - x;
		posicionColision.y = posicion.y - y;
	}	 
	
	return posicionColision;
    
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
