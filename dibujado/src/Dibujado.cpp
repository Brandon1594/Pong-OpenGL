/* Implementación de los métodos de dibujado */


void inicializaTiposNormales(Espacio* espacio, Pelota* pelota, Raqueta* raquetaIzq, Raqueta* raquetaDer){
	
	espacio = new EspacioNormal(600,200);
	pelota = new PelotaNormal(20, raquetaIzq, raquetaDer, espacio);
	raquetaIzq = new RaquetaNormal(10, 30, 25, espacio);
	raquetaDer = new RaquetaNormal(590, 30, 25, espacio);
	
}

void inicializaOGL(int ventanaAncho, int ventanaAlto){
	
}

void dibujaEspacio(Espacio*){
	
}

void dibujaPelota(Pelota*){
	
}

void dibujaRaqueta(Rauqeta*){
	
}

void teclas(unsigned char tecla, int x, int y){
	
}

void raton(int boton, int estado, int x, int y){
	
}

void escalarVentana(int x, int y){
	
}
