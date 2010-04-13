/* Interfaz Espacio  */
class Espacio {
	public:
		virtual void itera();
		virtual int getAncho() const = 0;
		virtual int getAlto() const = 0;
};
