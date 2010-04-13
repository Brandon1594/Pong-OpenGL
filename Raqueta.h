/* Interfaz Raqueta */
class Raqueta {
	public:
		void itera(); const = 0;
		void mueveteArriba() const = 0;
		void mueveteAbajo() const = 0;
		void incrPunt() const = 0;
		void decrPunt() const = 0;
		int getPosX() const = 0;
		int getPosY() const = 0;
		int getPuntos() const = 0;
};
