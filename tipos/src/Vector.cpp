/* Implementación de los operadores de Vector */

#include <Vector.h>
#include <cmath>

const Vector operator+(const Vector v1, const Vector v2){
	Vector suma = {v1.x + v2.x, v1.y + v2.y};
	return suma;
}

const Vector operator-(const Vector v1, const Vector v2){
	Vector resta = {v1.x - v2.x, v1.y - v2.y};
	return resta;
}

const Vector operator*(const int esc, const Vector v){
	Vector escalado= {esc * v.x , esc * v.y};
	return escalado;
}

const Vector operator*(const Vector v, const int esc){
	Vector escalado= {esc * v.x , esc * v.y};
	return escalado;
}

const double operator*(const Vector v1, const Vector v2){
	return v1.x * v2.x  +  v1.y * v2.y;
}

const Vector operator/(const Vector v, const int esc){
	Vector escalado= {v.x/esc , v.y/esc};
	return escalado;
}

const Vector operator+=(Vector& v1, const Vector v2){
	return (v1 = v1 + v2);
}
const Vector operator-=(Vector& v1, const Vector v2){
	return (v1 = v1 - v2);
}

const Vector operator*=(Vector& v, const int esc){
	return (v = esc*v);
}

const Vector operator/=(Vector& v, const int esc){
	return (v = v/esc);
}

const double mod(const Vector v){
	return sqrt( pow(v.x,2) + pow(v.y,2) );
}
