/* Interfaz Pelota */

class Pelota {
	public:
		void itera() const = 0;
		void rebota(Vector aceleracion) const = 0;
		int getX() const = 0;
		int getY() const = 0;
		void getVelocidad() const = 0;
}
